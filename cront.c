#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctype.h>
#include "cront.h"
#include "cronc.h"
#ifdef DEBUG
    #include <errno.h>
    extern int errno;
#endif

pid_t pid;
char *pargv[ARGNUM], prmptinput[BUFSIZE], programpath[PATH_MAX],monitorpath[PATH_MAX];

void ssu_crontab(int argc, char *argv[])
{
    int pargc;
    int i,spacechk;
    char *ptok;
    while(1)
    {
        //TODO: "ssu_crontab_file"에 저장된 모든 명령어 출력 및 개행
        //
        printf("%d>",SNUMBER);
        fgets(prmptinput,BUFSIZE,stdin);
        fflush(stdin);
        prmptinput[strlen(prmptinput)-1]=0; //마지막 개행문자를 없앰
        ptok=strtok(prmptinput," ");    pargc=0;
        while(ptok != NULL && pargc < ARGNUM-1) //pargv를 공백으로 나누기
        {
            pargv[pargc++]=ptok;
            ptok=strtok(NULL," ");
        }
        if(pargc)                   //엔터만 눌렀을 땐 프롬프트 재출력
            if(do_prmpt(pargc,pargv)<0) break;
    }
}

int do_prmpt(int pargc,char *pargv[ARGNUM])
{
    chdir(programpath); //오류시 변경안하고 나오므로 확실히 해둠.
    for(int i=0;pargv[0][i];i++)    pargv[0][i]=tolower(pargv[0][i]);   //pargv[0] 소문자 변환
    #ifdef DEBUG 
    printf("pargc : %d\n",pargc);
    for(int i=0;i<pargc;i++)
        printf(">%d: \"%s\"\n",i,pargv[i]);
    #endif
    if (strcmp("add",pargv[0]) == 0) do_add(pargc,pargv);
    else if (strcmp("remove",pargv[0]) == 0) do_remove(pargc,pargv);
    else if (strcmp("exit",pargv[0]) == 0) { return -1; }
    else    //다른 입력의 경우
    { fprintf(stderr,"Error: Invalid command input\n");  return 1; }
    return 0;
}

int do_add(int pargc,char *pargv[ARGNUM])
{
    char combuf[BUFSIZE];
    //커맨드 문법 검증
    if(pargc < 6)
    { fprintf(stderr,"Error: Not enough parameter!\n");       return 1; }
    int i;
    for(i=1;i<6;i++)
    {
        if(are_valid(pargv[i]))
        {
            fprintf(stderr,"Error: Invalid parameter!\n");       return 1;
        }
    }
    strcpy(combuf,pargv[1]);
    for(i=2;i<pargc;i++)    { strcat(combuf," "); strcat(combuf,pargv[i]); }    //뒤의 pargv를 하나로 붙임
    add_tab(combuf); //ssu_crontab_file 추가
    add_log(combuf,A_ADD);   //ssu_crontab_log 로깅
    show_tab();
    return 0;
}

int do_remove(int pargc,char *pargv[ARGNUM])
{
    int line = line_tab(),tline;
    //커맨드 검증
    if(pargc != 2)
    { fprintf(stderr,"Error: syntax: remove <line number:[1-%d]>",line); return 1;}
    if(!isnumber(pargv[1]))
    { fprintf(stderr,"Error: syntax: remove <line number:[1-%d]>",line); return 1;}
    tline = atoi(pargv[1]);
    if(tline > line || tline < 1)
    { fprintf(stderr,"Error: syntax: remove <line number:[1-%d]>",line); return 1;}
    //TODO: ssu_crontab_file 삭제
    add_log(pargv[1],A_REMOVE);    //ssu_crontab_log 로깅
    show_tab();
    return 0;
}