#include "ssufs-ops.h"

extern struct filehandle_t file_handle_array[MAX_OPEN_FILES];

int ssufs_allocFileHandle() {
	for(int i = 0; i < MAX_OPEN_FILES; i++) {
		if (file_handle_array[i].inode_number == -1) {
			return i;
		}
	}
	return -1;
}

int ssufs_create(char *filename){
	/*1 MEMO: filename으로 파일 생성, inode 할당-반환, 초기화 필요. 동일이름의 파일이 시스템에 존재하지 않아야 함*/

	struct inode_t *tmp = (struct inode_t *) malloc(sizeof(struct inode_t));
	int ninode;

	///전처리
	if (strlen(filename) > MAX_NAME_STRLEN) {
		return -1;
	}
	if(open_namei(filename)>=0) return -1;	//이미 같은이름의 파일이 존재함
	ninode = ssufs_allocInode();
	if(ninode < 0) return -1;	//비어있는 inode 블럭이 없음!

	///액션: inode 초기화
	ssufs_readInode(ninode,tmp);

	strncpy(tmp->name,filename,strlen(filename));
	tmp->status=INODE_IN_USE;
	tmp->file_size=0;
	for(int i=0;i<MAX_FILE_SIZE;i++)
		tmp->direct_blocks[i]=-1;
	ssufs_writeInode(ninode,tmp);
	return ninode;
}

void ssufs_delete(char *filename){
	/*2 MEMO: filname 삭제, inode와 같은 관련 리소스 해제. close 안해도 삭제 가능 */
	//THINK: 데이터블록 freelist를 지우긴 함
	int inode=open_namei(filename);
	if(inode<0) return;	//filename인 파일이 없음

	struct inode_t *tmp = (struct inode_t *) malloc(sizeof(struct inode_t));
	ssufs_readInode(inode, tmp);
	//for (int i=0;i<MAX_FILE_SIZE;i++)
	//	if(tmp->direct_blocks[i]>=0) ssufs_freeDataBlock(tmp->direct_blocks[i]);
	ssufs_freeInode(inode);
	free(tmp);
}

int ssufs_open(char *filename){
	/*3 MEMO: create한 파일의 경우만 성공! file handle에서 할당, 초기화. */
	int inode = open_namei(filename);
	if(inode<0) return -1;	//filename의 파일이 없음

	int nfd=ssufs_allocFileHandle();
	if(nfd<0) return -1;	//fd가 전부 참

	file_handle_array[nfd].inode_number=inode;
	file_handle_array[nfd].offset=0;
	return nfd;
}

void ssufs_close(int file_handle){
	file_handle_array[file_handle].inode_number = -1;
	file_handle_array[file_handle].offset = 0;
}

int ssufs_read(int file_handle, char *buf, int nbytes){
	/*4 MEMO: 4 
	! open()된 파일의 현재 오프셋에서 요청된 buf로 요청된 nbytes수를 읽음
	! 요청된 수는 디스크 상에서 연속되지 않을 수도 있음 ->여러 블록에 걸쳐 있을 수 있음
	! 성공 시 리턴 : 0
	! 에러 시 리턴 : -1
	! 주의할 점
	- 파일의 일부 읽기는 지원 하지 않음 요청된 수를 모두 버퍼로 읽거나 전혀 읽지 않아야 함
	- 요청된 nbyte수를 읽으면 파일 끝을 넘어 가게 되는 경우 아무 것도 읽지 않아야하며 에러를 리턴해야 함
	- 읽기가 블록 경계에서 정렬되지 않고 블록 중간에서 시작하거나 끝날 수 있는 경우 반드시 처리 해야 함
	- 읽기가 성공하면 fd의 오프셋 값도 갱신해야 함
	*/
	struct inode_t *tmp = (struct inode_t *) malloc(sizeof(struct inode_t));
	char bbuf[BLOCKSIZE];
	ssufs_readInode(file_handle_array[file_handle].inode_number, tmp);
	int soffset=file_handle_array[file_handle].offset,eoffset=soffset+nbytes,coffset=soffset;
	int blkoffset,byteoffset,bufoffset;
	while(coffset<eoffset)
	{
		blkoffset=coffset/BLOCKSIZE;
		ssufs_readDataBlock(blkoffset,bbuf);
		for(byteoffset=coffset%BLOCKSIZE;byteoffset<BLOCKSIZE;byteoffset++)
		{
			if(coffset>=eoffset) {free(tmp);	file_handle_array[file_handle].offset=coffset;	return 0;}
			else if(blkoffset*BLOCKSIZE+byteoffset>=tmp->file_size) { free(tmp);	file_handle_array[file_handle].offset=coffset;	return -1;}	//파일 끝을 넘음
			buf[bufoffset++]=bbuf[byteoffset];
			coffset++;
		}
	}
	return -1;
}

int ssufs_write(int file_handle, char *buf, int nbytes){
	/*5 FIXME: 5 
	! open() 된 파일의 현재 오프셋에서 요청된 buf에서 요청된 nbytes수를 디스크에 씀
	! 요청된 수는 디스크 상에서 연속되지 않을 수도 있음 여러 블록에 걸쳐있을 수 있음
	! 성공 시 리턴 : 0
	! 에러 시 리턴 : -1
	! 주의할 점
	- 파일의 일부 쓰기는 지원 하지 않음 요청된 모든 수를 파일에 쓰거나 전혀 쓰지 않아야 함
	- 요청된 nbytes 수를 쓸 수없는 경우:
		(ex: 요청 된 바이트 수를 쓰면 최대 파일 크기 제한을 초과하거나 쓰기를 완료하는 데 사용할 수 있는 free 디스크 블록이 없는 경우 ) 아무것도 쓰지 않고 에러 리턴해야 함.
	- 쓰기가 실퍠한 경우 실패가 발생하기 전에 할당 된 모든 데이터 블록을 해제하고 해당 블록은 파일시스템에 반환해야 함. -> 실패한 쓰기는 파일시스템이 시작된 상태와 동일한 상태를 유지
	- 쓰기가 블록 경계에서 정렬되지 않고 블록 중간에서 시작하거나 끝날 수 있는 경우 반드시 처리
	- 쓰기가 성공하면 fd의 오프셋 값도 갱신해야 함
	*/
	struct inode_t *tmp = (struct inode_t *) malloc(sizeof(struct inode_t));
	char bbuf[BLOCKSIZE]="",obuf[BLOCKSIZE];
	int newblk[MAX_FILE_SIZE]={-1,-1,-1,-1},blkcnt=0;
	ssufs_readInode(file_handle_array[file_handle].inode_number, tmp);
	int soffset=file_handle_array[file_handle].offset,eoffset=soffset+nbytes,coffset=soffset;
	//TODO: 바이트 수 체크, 필요 블럭 체크.
	//		쓰기 실패시 모든 블럭 해제
	//		오프셋이 블럭 중간일 수도 있음.
	printf("write %d bytes at %d offset -> buf: %s\n",nbytes,soffset,buf);
	int blkoffset,byteoffset,bufoffset=0;
	if(eoffset>MAX_FILE_SIZE*BLOCKSIZE) {free(tmp);	return -1;}	//최대파일크기제한 초과
	//필요한 블럭 미리 ALLOC 시도하고 실패한 경우 해제후 RETURN
	blkcnt=(eoffset+BLOCKSIZE/2)/BLOCKSIZE-(tmp->file_size+BLOCKSIZE/2)/BLOCKSIZE;	//새 할당이 필요한 블럭	
	printf("allocating %d blocks\n",blkcnt);
	for(int i=0;i<blkcnt;i++)
		newblk[i]=ssufs_allocDataBlock();
	for(int i=0;i<blkcnt;i++)
		printf("allocated block #%d/%d : %d\n",i+1,blkcnt,newblk[i]);
	if(blkcnt && newblk[blkcnt-1]<0)	//필요한 블럭중 마지막으로 할당한 블럭
	{
		printf("FAILED\n");
		for(int i=0;i<blkcnt;i++)
			if(newblk[i]>=0)ssufs_freeDataBlock(newblk[i]);
		return -1;
	}
	else if(blkcnt) //새로 할당한 블럭을 inode에 연결
	{
		blkoffset=tmp->direct_blocks[soffset/BLOCKSIZE];	//오프셋이 있는 블럭
		for (int i=0;i<blkcnt;i++)
			tmp->direct_blocks[blkoffset+i+1]=newblk[i];
		if(blkoffset<0) //첫 블럭도 새 블럭이다면?
			blkoffset=tmp->direct_blocks[soffset/BLOCKSIZE];
	}
	
	ssufs_writeInode(file_handle_array[file_handle].inode_number, tmp);	//블럭 할당상황 갱신

	printf("start write offset [%d , %d)\n",soffset,eoffset);
	if(soffset%BLOCKSIZE)	//첫 블럭이 중간에서 쓰기를 시작하는 경우
	{
		ssufs_readDataBlock(blkoffset,obuf);
		for(byteoffset=0;byteoffset<soffset%BLOCKSIZE;byteoffset++)
			bbuf[byteoffset]=obuf[byteoffset];		//오프셋 전까지 원본 블럭 복사
		for(byteoffset=soffset%BLOCKSIZE;byteoffset<BLOCKSIZE && coffset<eoffset;byteoffset++)
			{bbuf[byteoffset]=buf[bufoffset++];	coffset++;}		//내용을 블럭에 복사
		ssufs_writeDataBlock(blkoffset,bbuf);
	}
	while(coffset<eoffset)
	{
		memset(bbuf,0,sizeof(bbuf));
		blkoffset=tmp->direct_blocks[coffset/BLOCKSIZE];	printf("now write at block %d (%d)\n",blkoffset,coffset);
		for(byteoffset=0;byteoffset<BLOCKSIZE && coffset<eoffset;byteoffset++)
			{bbuf[byteoffset]=buf[bufoffset++];	coffset++;}		//내용을 블럭에 복사
		ssufs_writeDataBlock(blkoffset,bbuf);
	}

	file_handle_array[file_handle].offset=coffset;
	tmp->file_size=eoffset>tmp->file_size?eoffset:tmp->file_size;		//파일 크기 갱신
	ssufs_writeInode(file_handle_array[file_handle].inode_number, tmp);
	free(tmp);
	return 0;
}

int ssufs_lseek(int file_handle, int nseek){
	int offset = file_handle_array[file_handle].offset;

	struct inode_t *tmp = (struct inode_t *) malloc(sizeof(struct inode_t));
	ssufs_readInode(file_handle_array[file_handle].inode_number, tmp);
	
	int fsize = tmp->file_size;
	
	offset += nseek;

	if ((fsize == -1) || (offset < 0) || (offset > fsize)) {
		free(tmp);
		return -1;
	}

	file_handle_array[file_handle].offset = offset;
	free(tmp);

	return 0;
}
