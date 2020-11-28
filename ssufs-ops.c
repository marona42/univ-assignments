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
	//MEMO: data 블럭이 없는(크기가 0)인 파일도 가능하도록 일단은 짜자. 질문해야 할까? 아무래도 강의를 정주행해봐야 할 것 같은데...
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
	int inode=open_namei(filename);
	if(inode<0) return -1;	//filename인 파일이 없음
	ssufs_freeInode(inode);
	
}

int ssufs_open(char *filename){
	/*3 TODO: create한 파일의 경우만 성공! file handle에서 할당, 초기화. */
}

void ssufs_close(int file_handle){
	file_handle_array[file_handle].inode_number = -1;
	file_handle_array[file_handle].offset = 0;
}

int ssufs_read(int file_handle, char *buf, int nbytes){
	/*4 TODO: 4 */
}

int ssufs_write(int file_handle, char *buf, int nbytes){
	/*5 TODO: 5 */
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
