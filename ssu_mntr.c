#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include "ssu_mntr.h"
#include "logger.h"

char *pargv[ARGNUM], prmptinput[BUFSIZE];

void ssu_mntr(int argc, char *argv[])
{
    int pargc;
    int i,spacechk;
    char *ptok;
//    if (logger_daemon_init() < 0)
//    { fprintf(stderr,"Error : daemon init failed\n");   exit(1); }

    while(1)
    {
        printf("%d>",SNUMBER);
        fgets(prmptinput,BUFSIZE,stdin);
        prmptinput[strlen(prmptinput)-1]=0; //마지막 개행문자를 없앰
        ptok=strtok(prmptinput," ");    pargc=0;
        while(ptok != NULL && pargc < ARGNUM-1)
        {
            pargv[pargc++]=ptok;
            ptok=strtok(NULL," ");
        }
        if(pargc)                   //엔터만 눌렀을 땐 프롬프트 재출력
            do_prmpt(pargc,pargv);
    }
}
int do_prmpt(int pargc,char *pargv[ARGNUM])
{
    for(int i=0;pargv[0][i];i++)    pargv[0][i]=tolower(pargv[0][i]);   //pargv[0] 소문자 변환
#ifdef DEBUG 
    printf("%d\n",pargc);
    for(int i=0;i<pargc;i++)
        printf("> \"%s\"\n",pargv[i]);
#endif
    if (strcmp("delete",pargv[0]) == 0) do_delete(pargc,pargv);
    else if (strcmp("size",pargv[0]) == 0) do_size(pargc,pargv);
    else if (strcmp("recover",pargv[0]) == 0) do_recover(pargc,pargv);
    else if (strcmp("tree",pargv[0]) == 0) do_tree(pargc,pargv);
    else if (strcmp("exit",pargv[0]) == 0) do_exit(pargc,pargv);
    else do_help(pargc,pargv);                                      //이외 다른 입력에 대해 전부 help 실행.
    return 0;
}
int do_delete(int pargc, char *pargv[ARGNUM]){}
int do_size(int pargc, char *pargv[ARGNUM]){}
int do_recover(int pargc, char *pargv[ARGNUM]){}
int do_tree(int pargc, char *pargv[ARGNUM]){}
int do_exit(int pargc, char *pargv[ARGNUM]){}
int do_help(int pargc, char *pargv[ARGNUM])
{
    printf("Prompt Usages :\t(lowercase commands are OK)\n");
    printf("DELETE <FILENAME> [END_TIME] [OPTION]: deletes <FILENAME> by moving into 'trash' directory.\n");
    printf("\tEND_TIME : reserve the time when <FILENAME> deleted.\n\tOPTION:\n\t\t-i : removes <FILENAME> without using 'trash' directory\n\t\t-r : confirm deleting action when [END_TIME] arrives\n");
    printf("SIZE <FILENAME> [OPTION]: prints <FILENAME>'s size with relative directory\n");
    printf("\tOPTION:\n\t\t-d NUMBER : print <FILENAME>'s subdirectory of depth NUMBER\n");
    printf("RECOVER <FILENAME> [OPTION]: recover <FILENAME> from 'trash' directory.\n");
    printf("\tOPTION:\n\t\t-l : list 'trash' directory sorted with deleted time\n");
    printf("TREE: prints 'check' directory by tree foam.\n");
    printf("EXIT: exits this program containing monitoring process.\n");
    printf("HELP: prints prompt usage.\n");
}
