#include "alloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

typedef struct mementry_s{
    mementry *prev;
    mementry *next;
    int chapter; //페이지에서 엔트리의 시작점
    int size;    //이 엔트리가 점유하는 페이지 공간은 [chapter,chapter+size)
} mementry;
struct memmanger_s{
    void *prologue;
    mementry *bookmark; //마지막으로 페이지에 할당한 엔트리
} mmanager_static;
mementry *searchentry(char *target) //주어진 주소로 해당하는 엔트리를 찾아 반환
{

}
mementry *delentry(mementry *target)
{

}
mementry *newentry(int size)
{

}
int init_alloc()
{
    //mmap(void *addr, size_t len, int prot, int flag,int fd, off_t off): 시작주소(0-운영체제선택)/파일영역의 크기/보호방식/매핑영역특성/매핑할 파일(오픈 필요)/시작위치 파일오프셋
    if((mmanager_static.prologue=mmap(0,PAGESIZE,(PROT_WRITE|PROT_READ),(MAP_ANONYMOUS|MAP_PRIVATE),-1,0))==MAP_FAILED) return errno;
    mmanager_static.bookmark=NULL;
    return 0;
}
int cleanup()
{
    while(mmanager_static.bookmark != NULL) delentry(mmanager_static.bookmark);
    if (mmanager_static.bookmark != NULL ) return 1;
    return 0;
}
char *alloc(int size)
{
    size=size<MINALLOC?MINALLOC:size;   //assure size >= minalloc(8)
    if(size%MINALLOC == 0) return NULL;   //is not multiple of 8.
}
void dealloc(char *target)
{

}
