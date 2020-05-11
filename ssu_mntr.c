#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
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
        while(ptok != NULL && pargc < ARGNUM-1) //pargv를 공백으로 나누기
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
int dotfilter(const struct dirent *ent) //scandir시 ., .. 제외
{ return strcmp(ent->d_name,".") && strcmp(ent->d_name,".."); }
int olddtimesort(const struct dirent **a, const struct dirent **b)      //scandir시 오래된 순 정렬
{
    FILE *ap, *bp;
    char abuf[BUFSIZE], bbuf[BUFSIZE];
    struct tm at, bt;
    ap = fopen((*a)->d_name,"r");   bp = fopen((*b)->d_name,"r");
    fgets(abuf,BUFSIZE,ap);     fgets(bbuf,BUFSIZE,bp);
    fgets(abuf,BUFSIZE,ap);     fgets(bbuf,BUFSIZE,bp);
    fgets(abuf,BUFSIZE,ap);     fgets(bbuf,BUFSIZE,bp);
    #ifdef DEBUG
    //printf("%s %s:: %s vs %s\n",(*a)->d_name,(*b)->d_name,abuf,bbuf);
    #endif
    strptime(abuf,TIMEFORMAT,&at); strptime(bbuf,TIMEFORMAT,&bt);

    return mktime(&at)>mktime(&bt);
}
int rename_all(const char *srcpath,const char *destpath)    //재귀적으로 remove
{
    #ifdef DEBUG
    printf("rename %s -> %s\n",srcpath,destpath);
    #endif
    struct stat statbuf;
    struct dirent **items;
    int itemnum,i;
    char itempath[PATH_MAX],nitempath[PATH_MAX];
    lstat(srcpath,&statbuf);
    if(S_ISDIR(statbuf.st_mode))
    {
        mkdir(destpath,0777);
        itemnum = scandir(srcpath,&items,dotfilter,NULL);
        for(i=0;i<itemnum;i++)
        {
            sprintf(itempath,"%s/%s",srcpath,items[i]->d_name);
            sprintf(nitempath,"%s/%s",destpath,items[i]->d_name);
            rename_all(itempath,nitempath);
            free(items[i]);
        }
        free(items);
        rmdir(srcpath);
    }
    else
        return rename(srcpath,destpath);
}
int remove_all(const char *path)    //재귀적으로 remove
{
    #ifdef DEBUG
    printf("remove %s\n",path);
    #endif
    struct stat statbuf;
    struct dirent **items;
    int itemnum,i;
    char itempath[PATH_MAX];
    lstat(path,&statbuf);
    if(S_ISDIR(statbuf.st_mode))
    {
        itemnum = scandir(path,&items,dotfilter,NULL);
        for(i=0;i<itemnum;i++)
        {
            sprintf(itempath,"%s/%s",path,items[i]->d_name);
            remove_all(itempath);
            free(items[i]);
        }
        free(items);
    }
    return remove(path);
}
int getdirsize(const char *dirpath)
{
    struct stat statbuf;
    struct dirent **items;
    int itemnum,i,size=0;
    char itempath[PATH_MAX];
    itemnum = scandir(dirpath,&items,dotfilter,NULL);
    for(i=0;i<itemnum;i++)
    {
        sprintf(itempath,"%s/%s",dirpath,items[i]->d_name);
        lstat(itempath,&statbuf);
        if(S_ISDIR(statbuf.st_mode))
            size+=getdirsize(itempath);
        else
            size+=statbuf.st_size;
        
        free(items[i]);
    }
    free(items);
    #ifdef DEBUG
    printf("%s size : %d\n",dirpath,size);
    #endif
    return size;
}
int do_delete(int pargc, char *pargv[ARGNUM])
{
    struct stat stbuf;
    char newpath[PATH_MAX],oldpath[PATH_MAX],*filename,infopath[PATH_MAX],timememo[BUFSIZE];
    FILE *infop;
    struct tm tmbuf;
    time_t timenow,timetogo;
    int i,c,iOption=false,rOption=false;
    struct dirent **items;

    if (pargc < 2)
    { fprintf(stderr,"need arguments\n");   return -1;}
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
    if(strcmp(oldpath,monitorpath) == 0)
    { fprintf(stderr, "%s is monitored directory!\n",pargv[1]); return -3; }
    if(strstr(oldpath,monitorpath) == NULL) //모니터링 디렉토리를 벗어난 경로의 경우 에러처리
    { fprintf(stderr,"%s is not in %s!\n",pargv[1],monitorpath); return -3; }

    ///TODO:[END_TIME] 처리
    if (pargc > 3 && pargv[2][0]!='-' && pargv[3][0]!='-')
    {
        strcat(pargv[2],pargv[3]);
        strptime(pargv[2],"%Y-%m-%d %H:%M",&tmbuf);
        timetogo=mktime(&tmbuf);
        time(&timenow);
        if(timetogo < timenow)  //주어진 시간이 지나간 시간인 경우
        { fprintf(stderr,"[END_TIME] is invalid\n");    return -3; }
    }
    else
        timetogo=0;
    

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
    if(iOption)
    {
        if(fork() == 0)
        {
            time(&timenow);
            #ifdef DEBUG
            printf("go remove after %ld seconds\n",timetogo?timetogo-timenow:0);
            #endif
            sleep(timetogo?timetogo-timenow:0);    //시간 예약
            if(rOption) //한번 더 확인
            {
                printf("Delete? [y/n]:");
                scanf("%s\n",timememo);
                if(!strcmp(timememo,"n") || !strcmp(timememo,"N") || !strcmp(timememo,"0")) return -9;
            }
            if(remove_all(oldpath)<0)
            { fprintf(stderr, "remove failed\n");   return -4; }
            else
            { printf("removed successfully\n");    return 0;}
        }
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

        i = 0;
        sprintf(newpath,"%s/trash/files/%s^%d.deleted",programpath,filename,i);
        while(!access(newpath,F_OK)) {sprintf(newpath,"%s/trash/files/%s^%d.deleted",programpath,filename,++i);}   //같은 이름 있는지 보고 넘긴다

        sprintf(newpath,"%s/trash/files/%s^%d.deleted",programpath,filename,i);    //newpath에 trash/files 디렉토리 경로를 넣는다. + 삭제태그로 .deleted를 붙여준다.
        sprintf(infopath,"%s/trash/info/%s^%d.deleted",programpath,filename,i);    //infopath에 trash/info 디렉토리 경로를 넣는다. + 삭제태그로 .deleted를 붙여준다.

        if(fork() == 0)
        {
            time(&timenow);
            #ifdef DEBUG
            printf("go delete after %ld seconds\n",timetogo?timetogo-timenow:0);
            #endif
            sleep(timetogo?timetogo-timenow:0);    //시간 예약
            if(rOption) //한번 더 확인
            {
                printf("Delete? [y/n]:");
                scanf("%s\n",timememo);
                if(!strcmp(timememo,"n") || !strcmp(timememo,"N") || !strcmp(timememo,"0")) return -9;
            }
            ///삭제 액션
            infop = fopen(infopath,"w");
            time(&timenow);
            strftime(timememo,BUFSIZE,TIMEFORMAT,localtime(&timenow));
            fprintf(infop,"[Trash info]\n%s\n%s\n",oldpath,timememo);   //예전 절대경로/삭제 시간/
            strftime(timememo,BUFSIZE,TIMEFORMAT,localtime(&stbuf.st_mtime));
            fprintf(infop,"%s\n",timememo);   //변경시간(mtime)
            fclose(infop);
            rename_all(oldpath,newpath);   //move into trash


            ///INFO크기 제한
            sprintf(infopath,"%s/trash/info",programpath);
            chdir(infopath);
            while(getdirsize(infopath) > INFOSZLIMIT)
            {
                c = scandir(infopath,&items,dotfilter,olddtimesort);    //오래된 순으로 정렬한다.

                #ifdef DEBUG
                for(int i=0;i<c;i++)
                {
                    printf("%s\n",items[i]->d_name);
                }
                #endif
                for(int i=1;i<c;i++)    //필요한건 가장 위의 값, 나머지는 필요없다.
                    free(items[i]);
                sprintf(newpath,"%s/trash/info/%s",programpath,items[0]->d_name); //info의 파일 경로
                remove_all(newpath);
                sprintf(newpath,"%s/trash/files/%s",programpath,items[0]->d_name); //files의 파일 경로
                remove_all(newpath);
                free(items[0]);
                free(items);
            }
            chdir(programpath);
        }
    }
}
int do_size(int pargc, char *pargv[ARGNUM])
{
    //TODO: 기본동작 :  상대경로(programpath), 크기
    //TODO: -d옵션  :하위 디렉토리 깊이
}
int do_recover(int pargc, char *pargv[ARGNUM])
{
    //TODO: 기본동작 : 파일 복구
        //TODO: 동일한 이름 파일 선택
        //TODO: 동일한 이름 파일 복구시 숫자_ 추가
    //TODO: -l 옵션 : 삭제시간 오래된 순으로 출력후 진행

}
int do_tree(int pargc, char *pargv[ARGNUM])
{
    //TODO: 기본동작 : 디렉토리 구조 보여주기
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
