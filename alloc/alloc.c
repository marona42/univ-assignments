#include "alloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int init_alloc()
{

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
