#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc,char *argv[])
{
    if(argc<2) printf("Usage : %s <name>\n",argv[0]);
    else helloname(argv[1]);
    exit();
}
