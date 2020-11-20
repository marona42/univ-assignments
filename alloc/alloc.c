#include "alloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

struct memmanger_s{
    void *prologue;
    void *bookmark;
} mmanager_static;
int init_alloc()
{
    //mmap(void *addr, size_t len, int prot, int flag,int fd, off_t off): 시작주소(0-운영체제선택)/파일영역의 크기/보호방식/매핑영역특성/매핑할 파일(오픈 필요)/시작위치 파일오프셋
    if((mmanager_static.prologue=mmap(0,PAGESIZE,(PROT_WRITE|PROT_READ),(MAP_ANONYMOUS|MAP_PRIVATE),-1,0))==MAP_FAILED) return errno;
    return 0;
}
int cleanup()
{

}
char *alloc(int size)
{
    size=size<MINALLOC?MINALLOC:size;   //assure size >= minalloc(8)
    if(size%MINALLOC == 0) return NULL;   //is not multiple of 8.
}
void dealloc(char *target)
{

}
