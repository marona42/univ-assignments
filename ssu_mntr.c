#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "ssu_mntr.h"
#include "logger.h"


void ssu_mntr(int argc, char *argv[])
{
    if (logger_daemon_init() < 0)
    { fprintf(stderr,"Error : daemon init failed\n");   exit(1); }

    while(1)
    {
        printf("%d>",SNUMBER);
        
    }
}