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
	/*1 TODO: filename으로 파일 생성, inode 할당-반환, 초기화 필요. 동일이름의 파일이 시스템에 존재하지 않아야 함*/

	struct superblock_t *superblock = (struct superblock_t *) malloc(sizeof(struct superblock_t));
	struct inode_t *tmp = (struct inode_t *) malloc(sizeof(struct inode_t));
	int ninode;

	///전처리
	if (strlen(filename) > MAX_NAME_STRLEN) {
		return -1;
	}
	ssufs_readSuperBlock(superblock);

	for (int i = 0; i < NUM_INODES; i++)
		if (superblock->inode_freelist[i] == INODE_IN_USE)
		{
			ssufs_readInode(i, tmp);
			if (strcmp(tmp->name, filename) == 0)
			{
				free(tmp);
				return -1;		//이미 있는 filename인 경우 실패
			}
		}
	ninode = -1;
	for(int i=0; i<NUM_INODES; i++)
		if(superblock->inode_freelist[i] == INODE_FREE)
		{
			superblock->inode_freelist[i] = INODE_IN_USE;
			ssufs_writeSuperBlock(superblock);
			free(superblock);
			ninode=i;
			break;
		}
	if(ninode < 0) return -1;	//비어있는 inode 블럭이 없음!

	///액션: inode 초기화
	ssufs_readInode(ninode,tmp);

	strncpy(tmp->name,filename,strlen(filename));
	tmp->status=0;
	tmp->file_size=0;
	for(int i=0;i<MAX_FILE_SIZE;i++)
		tmp->direct_blocks[i]=NULL;

	///뒷처리
	free(superblock);
	return ninode;
}

void ssufs_delete(char *filename){
	/*2 TODO: filname 삭제, inode와 같은 관련 리소스 해제. close 안해도 삭제 가능 */
	//THINK: 데이터블록 freelist를 지우긴 함
	int inode=open_namei(filename);
	if(inode<0) return -1;	//filename인 파일이 없음

	struct superblock_t *superblock = (struct superblock_t *) malloc(sizeof(struct superblock_t));
	struct inode_t *tmp = (struct inode_t *) malloc(sizeof(struct inode_t));
	ssufs_readSuperBlock(superblock);
	ssufs_readInode(inode, tmp);
	for (int i=0;i<MAX_FILE_SIZE;i++)
		if(tmp->direct_blocks[i]) ssufs_freeDataBlock(tmp->direct_blocks[i]);
	ssufs_freeInode(inode);
	ssufs_writeSuperBlock(superblock);
}

int ssufs_open(char *filename){
	/*3 TODO: create한 파일의 경우만 성공! file handle에서 할당, 초기화. */
	int inode = open_namei(filename);
	if(inode<0) return -1;	//filename의 파일이 없음

	int nfd=ssufs_allocFileHandle();
	if(nfd<0) return -1;	//fd가 전부 참

	file_handle_array[nfd].inode_number=inode;
	file_handle_array[nfd].offset=0;
}

void ssufs_close(int file_handle){
	file_handle_array[file_handle].inode_number = -1;
	file_handle_array[file_handle].offset = 0;
}

int ssufs_read(int file_handle, char *buf, int nbytes){
	/*4 FIXME: 4 
		! open() buf nb 된 파일의 현재 오프셋에서 요청된 로 요청된 수를 읽음 ytes
	! 요청된 수는 디스크 상에서 연 nbytes -> 속되지 않을 수도 있음 여러 블록에 걸쳐 있을 수 있음
	! 성공 시 리턴 : 0
	! 에러 시 리턴 : -1
	! 주의할 점
	- 파일의 일부 읽기는 지원 하지 않음 요청된 수를 모두 버퍼로 읽 . nbytes , 거나 전혀 읽지 않아야
	함
	- 요청된 수를 읽으 nbytes 면 파일 끝을 넘어 가게 되는 경우 아무 것도 읽지 않아야하며 에러를
	리턴해야 함
	- 읽기가 블록 경계에서 정렬되지 않고 블록 중간에서 시작하거나 끝날 수 있는 경우 반드시 처리
	해야 함
	- 읽기가 성공하면 fd의 오프셋 값도 갱신해야 함
	*/
}

int ssufs_write(int file_handle, char *buf, int nbytes){
	/*5 FIXME: 5 
	! open() buf nb 된 파일의 현재 오프셋에서 요청된 에서 요청된 수를 디스크에 ytes 씀
	! 요청된 수는 디스크 상에서 연 nbytes -> 속되지 않을 수도 있음 여러 블록에 걸쳐있을 수 있음
	! 성공 시 리턴 : 0
	! 에러 시 리턴 : -1
	! 주의할 점
	- 파일의 일부 쓰기는 지원 하지 않음 요청된 모든 수를 파일에 쓰 . nbytes 거나 전혀 쓰지 않아야
	함
	- 요청된 수를 nbytes ( : 쓸 수없는 경우 예 요청 된 바이트 수를 쓰면 최대 파일 크기 제한을 초과
	하거나 쓰기를 완료하는 데 사용할 수 있는 디스크 블록이 없는 경우 free ) 아무것도 쓰지 않고
	에러 리턴해야 함.
	- 쓰기가 실퍠한 경우 실패가 발생하기 전에 할당 된 모든 데이터 블록을 해제하고 해당 블록은
	파일시스템에 반환해야 함. -> 실패한 쓰기는 파일시스템이 시작된 상태와 동일한 상태를 유지
	- 쓰기가 블록 경계에서 정렬되지 않고 블록 중간에서 시작하거나 끝날 수 있는 경우 반드시 처리
	- 쓰기가 성공하면 fd의 오프셋 값도 갱신해야 함
	*/
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
