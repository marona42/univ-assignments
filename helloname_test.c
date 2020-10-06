#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc,char *argv[])
{
    if(argc<2) printf(1,"Usage : %s <name>\n",argv[0]);
    else hello_name(argv[1]);
    exit();
}
