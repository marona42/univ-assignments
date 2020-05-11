#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "ssu_mntr.h"
#include "logger.h"

pid_t pid;
char *pargv[ARGNUM], prmptinput[BUFSIZE], programpath[PATH_MAX],monitorpath[PATH_MAX];

void ssu_mntr(int argc, char *argv[])
{
    getcwd(programpath,PATH_MAX);                           //프로그램 경로를 저장
    sprintf(monitorpath,"%s/%s",programpath,MNTRDIR);    //모니터링 디렉토리 경로를 저장
//    if ((pid = fork()) < 0)
//        { fprintf(stderr,"Error : Fork failed\n");  exit(1); }
//    else if (pid == 0)
//        if (logger_daemon_init() < 0)         //모니터링 디몬 만들기
//            { fprintf(stderr,"Error : daemon init failed\n");   exit(1); }

    int pargc;
    int i,spacechk;
    char *ptok;
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
    printf("pargc : %d\n",pargc);
    for(int i=0;i<pargc;i++)
        printf(">%d: \"%s\"\n",i,pargv[i]);
#endif
    if (strcmp("delete",pargv[0]) == 0) do_delete(pargc,pargv);
    else if (strcmp("size",pargv[0]) == 0) do_size(pargc,pargv);
    else if (strcmp("recover",pargv[0]) == 0) do_recover(pargc,pargv);
    else if (strcmp("tree",pargv[0]) == 0) do_tree(pargc,pargv);
    else if (strcmp("exit",pargv[0]) == 0) do_exit(pargc,pargv);
    else do_help(pargc,pargv);                                      //이외 다른 입력에 대해 전부 help 실행.
    return 0;
}
int do_delete(int pargc, char *pargv[ARGNUM])
{
    //TODO: END_TIME
    struct stat stbuf;
    char newpath[PATH_MAX],oldpath[PATH_MAX],*filename,infopath[PATH_MAX],timememo[BUFSIZE];
    FILE *infop;
    time_t timenow;
    int i,c,iOption=false,rOption=false;

    ///[FILENAME] 처리
    chdir(monitorpath);
    if(pargv[1][0]!='/')   //주어진 경로가 절대경로가 아닌 경우 
            realpath(pargv[1],oldpath); //상대경로를 절대경로
        else
            strcpy(oldpath,pargv[1]);   //절대경로인 경우 복사만
    filename=strrchr(oldpath,'/')+1;    //파일이름 시작지점 포인터
    chdir(programpath);

    if(lstat(oldpath,&stbuf) < 0)  //[FILENAME] 확인
    { fprintf(stderr, "%s is not exist!\n",pargv[1]); return -3; }
    if(strstr(oldpath,monitorpath) == NULL) //모니터링 디렉토리를 벗어난 경로의 경우 에러처리
    { fprintf(stderr,"%s is not in %s!\n",pargv[1],monitorpath); return -3; }

    ///[END_TIME] 처리

    while((c = getopt(pargc,pargv,"ir"))!= -1)  //getopt가 pargv의 순서를 바꿔놓으므로, [FILENAME]과 [END_TIME]처리를 먼저 해야한다.
    {
        switch(c)
        {
            case 'i': iOption = true; break;
            case 'r': rOption = true; break;
            case '?': fprintf(stderr,"Error : check options");  return -1;
        }
    }optind=0;  //인자처리 초기화

    ///삭제액션
    //FIXME: 디렉토리 삭제시...?
    //FIXME: 모니터 디렉토리 자체를 삭제?!
    if(iOption)
    {
        
        if(remove(oldpath)<0)
        { fprintf(stderr, "Error : remove failed\n");   return -4; }
        else
        { printf("removed successfully\n");    return 0;}
    }
    else
    {
        if(lstat("trash",&stbuf) < 0)       //trash가 없다면
        {
            if(mkdir("trash",0777) < 0)     //생성
            { fprintf(stderr,"failed to make 'trash' directory\n"); return -1;}
            if(mkdir("trash/files",0777) < 0)     //생성
            { fprintf(stderr,"failed to make 'trash/files' directory\n"); return -1;}
            if(mkdir("trash/info",0777) < 0)     //생성
            { fprintf(stderr,"failed to make 'trash/info' directory\n"); return -1;}
            
        }
        else if (!S_ISDIR(stbuf.st_mode))   //있는데 디렉토리가 아니라면?
        { fprintf(stderr,"'trash' is not a directory!\n"); return -2;}

        sprintf(newpath,"%s/trash/files/%s^%lu.deleted",programpath,filename,stbuf.st_ino);    //newpath에 trash/files 디렉토리 경로를 넣는다. + 삭제태그로 ino값과 .deleted를 붙여준다.
        sprintf(infopath,"%s/trash/info/%s^%lu.deleted",programpath,filename,stbuf.st_ino);    //infopath에 trash/info 디렉토리 경로를 넣는다. + 삭제태그로 ino값과 .deleted를 붙여준다.
        
        infop = fopen(infopath,"w");
        time(&timenow);
        strftime(timememo,BUFSIZE,"%Y-%m-%d %H:%M:%S",localtime(&timenow));
        fprintf(infop,"[Trash info]\n%s\n%s\n",oldpath,timememo);   //예전 절대경로/삭제 시간/
        strftime(timememo,BUFSIZE,"%Y-%m-%d %H:%M:%S",localtime(&stbuf.st_mtime));
        fprintf(infop,"%s\n",timememo);   //변경시간(mtime)
        fclose(infop);
        rename(oldpath,newpath);   //move into trash
    }
}
int do_size(int pargc, char *pargv[ARGNUM])
{

}
int do_recover(int pargc, char *pargv[ARGNUM])
{

}
int do_tree(int pargc, char *pargv[ARGNUM])
{

}
int do_exit(int pargc, char *pargv[ARGNUM])
{
    printf("Prompt exited!\nplease kill daemon : ps -efj | grep [THISNAME]\n");
    //kill(dpid,SIGTERM);   //명세 변경
    exit(0);
}
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
