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
#ifdef DEBUG
    #include <errno.h>
    extern int errno;
#endif

pid_t pid;
char *pargv[ARGNUM], prmptinput[BUFSIZE], programpath[PATH_MAX],monitorpath[PATH_MAX];

void ssu_mntr(int argc, char *argv[])
{
    getcwd(programpath,PATH_MAX);                           //프로그램 경로를 저장
    sprintf(monitorpath,"%s/%s",programpath,MNTRDIR);    //모니터링 디렉토리 경로를 저장
    if ((pid = fork()) < 0)
        { fprintf(stderr,"Error : Fork failed\n");  exit(1); }
    else if (pid == 0)
        if (logger_daemon_init(programpath) < 0)         //모니터링 디몬 만들기
            { fprintf(stderr,"Error : daemon init failed\n");   exit(1); }
        else
        {
            init_monitoring(monitorpath);
            while(1)
                do_monitor(monitorpath);
        }
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
    if (strcmp("delete",pargv[0]) == 0) do_delete(pargc,pargv);
    else if (strcmp("size",pargv[0]) == 0) do_size(pargc,pargv);
    else if (strcmp("recover",pargv[0]) == 0) do_recover(pargc,pargv);
    else if (strcmp("tree",pargv[0]) == 0) do_tree(pargc,pargv);
    else if (strcmp("exit",pargv[0]) == 0)
    {
        printf("Prompt exited!\nplease kill daemon : ps -efj | grep []\n");
        //kill(dpid,SIGTERM);   //명세 변경
        return -1;
    }
    else do_help(pargc,pargv);                                      //이외 다른 입력에 대해 전부 help 실행.
    return 0;
}

time_t getdtime(const char *fname)
{
    FILE *ap;
    char abuf[PATH_MAX];
    struct tm at;
    ap = fopen(fname,"r");
    fgets(abuf,PATH_MAX,ap);
    fgets(abuf,PATH_MAX,ap);
    fgets(abuf,PATH_MAX,ap);
    strptime(abuf,TIMEFORMAT,&at);
    fclose(ap);
    return mktime(&at);
}
time_t getmtime(const char *fname)
{
    FILE *ap;
    char abuf[PATH_MAX];
    struct tm at;
    ap = fopen(fname,"r");
    fgets(abuf,PATH_MAX,ap);
    fgets(abuf,PATH_MAX,ap);
    fgets(abuf,PATH_MAX,ap);
    fgets(abuf,PATH_MAX,ap);
    strptime(abuf,TIMEFORMAT,&at);
    fclose(ap);
    return mktime(&at);
}
int olddtimesort(const struct dirent **a, const struct dirent **b)      //scandir compare: 삭제시간 오름차순 정렬
{ return getdtime((*a)->d_name)>getdtime((*b)->d_name); }
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
int isnumber(const char *str)   //주어진 문자열이 숫자로만 있는지: 정수인가?
{
    int i,len=strlen(str);
    for(int i=0;i<len;i++)
        if(!isdigit(str[i])) return false;
    return true;
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
    //printf("%s size : %d\n",dirpath,size);
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

    ///[END_TIME] 처리
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
            case '?': fprintf(stderr,"Error : check options\n");  return -1;
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
            { fprintf(stderr,"failed to make 'trash' directory\n"); return -2;}
            if(mkdir("trash/files",0777) < 0)     //생성
            { fprintf(stderr,"failed to make 'trash/files' directory\n"); return -2;}
            if(mkdir("trash/info",0777) < 0)     //생성
            { fprintf(stderr,"failed to make 'trash/info' directory\n"); return -2;}
            
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
void do_size_d(const char *papath, const char *prpath, const char *fname,int depth)
{
    struct stat stbuf;
    struct dirent **items;
    char oldpath[PATH_MAX],newpath[PATH_MAX],itempath[PATH_MAX],*filename,*pch;
    int i,fsize=-1,itemnum;

    sprintf(oldpath,"%s/%s",papath,fname);
    sprintf(newpath,"%s/%s",prpath,fname);
    ///대상 크기 출력
    lstat(oldpath,&stbuf);
    if(S_ISDIR(stbuf.st_mode))
        fsize=getdirsize(oldpath);
    else
        fsize=stbuf.st_size;
    printf("%d\t\t%s/%s\n",fsize,prpath,fname); //크기와 상대주소 출력

    if(S_ISDIR(stbuf.st_mode) && depth>1) //하위 디렉토리 출력
    {
        itemnum = scandir(oldpath,&items,dotfilter,alphasort);  //알파벳 순 출력
        for(i=0;i<itemnum;i++)
        {
            sprintf(itempath,"%s/%s",oldpath,items[i]->d_name);
            lstat(itempath,&stbuf);
            if(S_ISDIR(stbuf.st_mode))
                do_size_d(oldpath,newpath,items[i]->d_name,depth-1);
            else    //파일의 경우 바로 출력하기
                printf("%ld\t\t%s/%s\n",stbuf.st_size,newpath,items[i]->d_name);
            free(items[i]);
        }
        free(items);
    }
}
int do_size(int pargc, char *pargv[ARGNUM])
{
    struct stat stbuf;
    struct dirent **items;
    char newpath[PATH_MAX],oldpath[PATH_MAX],itempath[PATH_MAX],*pch;
    int i,dOption=1,fsize=-1,itemnum,c;
    
    if(pargc < 2)
    { fprintf(stderr,"need arguments\n");   return -1;}
    chdir(programpath);
    if(access(pargv[1],F_OK))
    { fprintf(stderr,"%s is not exist!\n",pargv[1]);    return -1;}

    realpath(pargv[1],oldpath);
    ///-d옵션 입력받기 :하위 디렉토리 깊이
    while((c = getopt(pargc,pargv,"d:"))!= -1)  //getopt가 pargv의 순서를 바꿔놓으므로, 다른 인자들 처리를 먼저 해야한다.
    {
        switch(c)
        {
            case 'd':
            #ifdef DEBUG
                printf("dOption enabled:");
            #endif
                if(isnumber(optarg))
                {
                    dOption = atoi(optarg);
                    #ifdef DEBUG
                        printf("%d\n",dOption);
                    #endif
                    if(dOption < 1)
                        {fprintf(stderr,"must be a number > 1 after -d option\n");   return -1;}
                }
                else
                    {fprintf(stderr,"must be a number after -d option\n");   return -1;}
                break;
            case '?': fprintf(stderr,"Error : check options\n");  return -1;
        }
    }optind=0;  //인자처리 초기화

    ///newpath에 oldpath에 해당하는 상대경로 만들기
    if((pch=strstr(oldpath,programpath)) != NULL )  //포함하는 경우
    {
        strcpy(newpath,"./");
        i=strlen(programpath)+1;
        strcat(newpath,&oldpath[i]);
    }
    else    //..이 포함되어야 하는 경우
    {
        for(i=0;oldpath[i]==programpath[i];i++);    //공통주소의 끝까지 간다
        strcat(newpath,"../");
        pch=&programpath[i];
        while((pch=strchr(pch+1,'/'))!=NULL) strcat(newpath,"../");
        strcat(newpath,&oldpath[i]);
    }

    ///대상 크기 출력
    lstat(oldpath,&stbuf);
    if(S_ISDIR(stbuf.st_mode))
        fsize=getdirsize(oldpath);
    else
        fsize=stbuf.st_size;
    printf("%d\t\t%s\n",fsize,newpath); //크기와 상대주소 출력

    if(S_ISDIR(stbuf.st_mode) && dOption>1) //하위 디렉토리 출력
    {
        itemnum = scandir(oldpath,&items,dotfilter,alphasort);  //알파벳 순 출력
        for(i=0;i<itemnum;i++)
        {
            sprintf(itempath,"%s/%s",oldpath,items[i]->d_name);
            lstat(itempath,&stbuf);
            if(S_ISDIR(stbuf.st_mode))
                do_size_d(oldpath,newpath,items[i]->d_name,dOption-1);
            else    //파일의 경우 바로 출력하기
                printf("%ld\t\t%s/%s\n",stbuf.st_size,newpath,items[i]->d_name);
            free(items[i]);
        }
        free(items);
    }
    memset(newpath,0,sizeof(newpath));
}
int getname(const char *path, char *name)   //^ 뒤를 떼서 파일 이름만 가져오기
{
    char *end;
    end=strchr(path,'^');
    strncpy(name,path,end-path);
    name[end-path]='\0';
}
void getpath(const char *path, char *name)   //path의 파일에서 path 가져오기
{
    FILE *ap;
    ap = fopen(path,"r");
    fgets(name,PATH_MAX,ap);
    fgets(name,PATH_MAX,ap);
    name[strlen(name)-1]=0; //마지막 \n지우기
    fclose(ap);
}
int do_recover(int pargc, char *pargv[ARGNUM])
{
    struct stat stbuf;
    struct tm tmbuf;
    struct dirent **items;
    time_t dtime,mtime;
    char newpath[PATH_MAX],oldpath[PATH_MAX],filename[PATH_MAX],infopath[PATH_MAX],npath[PATH_MAX],timememo[BUFSIZE];
    FILE *infop;
    int i,li,c,lOption=false,itemnum, *fmap;

    if (pargc < 2)
    { fprintf(stderr,"need arguments\n");   return -1;}

    ///trash, info,files 디렉토리 확인
    if(lstat("trash",&stbuf) < 0)
    { fprintf(stderr,"There is no 'trash' directory!\n"); return -2;}
    else if (!S_ISDIR(stbuf.st_mode))   //있긴한데 디렉토리가 아니라면?
    { fprintf(stderr,"'trash' is not a directory!\n"); return -2;}

    sprintf(npath,"%s/trash/files",programpath);    //npath 임시로 씀
    if(lstat(npath,&stbuf) < 0)
    { fprintf(stderr,"There is no 'trash/files' directory!\n"); return -2;}
    else if (!S_ISDIR(stbuf.st_mode))
    { fprintf(stderr,"'trash/files' is not a directory!\n"); return -2;}    memset(npath,0,sizeof(npath));

    sprintf(infopath, "%s/trash/info", programpath);
    if(lstat(infopath,&stbuf) < 0)
    { fprintf(stderr,"There is no 'trash/info' directory!\n"); return -2;}
    else if (!S_ISDIR(stbuf.st_mode))
    { fprintf(stderr,"'trash/info' is not a directory!\n"); return -2;}

    strcpy(filename,pargv[1]);  //[FILENAME] 복사만 해두고 나중에 처리

    while((c = getopt(pargc,pargv,"l"))!= -1)  //getopt가 pargv의 순서를 바꿔놓으므로, [FILENAME]처리를 먼저 해야한다.
    {
        switch(c)
        {
            case 'l': lOption = true; break;
            case '?': fprintf(stderr,"Error : check options\n");  return -1;
        }
    }optind=0;  //인자처리 초기화
    ///-l 옵션 : 삭제시간 오래된 순으로 출력후 진행
    if(lOption)
    {
        chdir(infopath);
        if((itemnum=scandir(infopath,&items,dotfilter,olddtimesort))<0)
        {
            fprintf(stderr,"scandir(info) failed!\n");
            #ifdef DEBUG
                switch(errno)
                {
                    case ENOENT:
                        fprintf(stderr,"dirp isn't exist\n");
                        break;
                    case ENOMEM:
                        fprintf(stderr,"not enough memory\n");
                        break;
                    case ENOTDIR:
                        fprintf(stderr,"is not dir\n");
                        break;
                }
            #endif
            return -2;
        }
        printf("List of trash files:-------\n[N] [FILENAME]\t[DELETEDTIME]\n");
        for (i=0;i<itemnum;i++)
        {
            getname(items[i]->d_name,newpath);  //변수돌려쓰기
            dtime = getdtime(items[i]->d_name);
            strftime(timememo,BUFSIZE,TIMEFORMAT,localtime(&dtime));
            printf("%d. %s \t\t%s\n",i+1,newpath,timememo);
            free(items[i]);
        }memset(newpath,0,sizeof(newpath));
        free(items);
        printf("--------------------------\n");
        chdir(programpath);
    }

    ///TODO: [FILENAME] 처리
    chdir(infopath);
    if((itemnum=scandir(infopath,&items,dotfilter,olddtimesort))<0)
    {
        fprintf(stderr,"scandir(info) failed!\n");
        #ifdef DEBUG
            switch(errno)
            {
                case ENOENT:
                    fprintf(stderr,"dirp isn't exist\n");
                    break;
                case ENOMEM:
                    fprintf(stderr,"not enough memory\n");
                    break;
                case ENOTDIR:
                    fprintf(stderr,"is not dir\n");
                    break;
            }
        #endif
        return -2;
    }

    c=0;
    for (i=0;i<itemnum;i++) //파일 세기
    {
        getname(items[i]->d_name,newpath);  //변수돌려쓰기
        if(!strcmp(newpath,filename))   {c++; li=i;}
        #ifdef DEBUG
        //    printf("%s : %d\n",newpath,c);
        #endif
    }memset(newpath,0,sizeof(newpath));
    if(!c)
    { fprintf(stderr,"there is no '%s' in 'trash' directory\n",filename);   return -2; }
    else if(c > 1)    //여러 개 있는 경우
    {
        fmap=malloc(sizeof(int)*(c+1));
        c=0;
        for (i=0;i<itemnum;i++)
        {
            getname(items[i]->d_name,newpath);  //변수돌려쓰기
            if(!strcmp(newpath,filename))
            {
                dtime = getdtime(items[i]->d_name);
                mtime = getmtime(items[i]->d_name);
                strftime(timememo,BUFSIZE,TIMEFORMAT,localtime(&dtime));
                printf("[%d] %s \tDeleted : %s\t",++c,newpath,timememo);    fmap[c]=i;
                strftime(timememo,BUFSIZE,TIMEFORMAT,localtime(&mtime));
                printf("Modified : %s\n",timememo);
            }
        }
        printf("Choose : ");
        fgets(timememo,BUFSIZE,stdin);  timememo[strlen(timememo)-1]='\0';
        while((li=atoi(timememo)) > c || !isnumber(timememo))   //잘못된 입력인 경우
        {
            printf("Please input [1-%d]\nChoose : ",c); fgets(timememo,BUFSIZE,stdin);
        }
        li=fmap[li];
        free(fmap);
    }
    //하나인 경우 이미 li에 저장됨

    sprintf(oldpath,"%s/trash/files/%s",programpath,items[li]->d_name);
    getpath(items[li]->d_name,newpath);
    strncpy(npath,newpath,strlen(newpath)-strlen(filename)-1);
    sprintf(infopath,"%s/trash/info/%s",programpath,items[li]->d_name);

    for(i=0;i<itemnum;i++) free(items[i]);
    free(items);

    i=0;
    while(!access(newpath,F_OK)) {sprintf(newpath,"%s/%d_%s",npath,++i,filename);}   //같은 이름 있는지 보고 넘긴다

    ///복구 액션
    remove(infopath);
    rename_all(oldpath,newpath);   //move from trash
    chdir(programpath);
}
void print_tree(const char *curpath,const char *fname,int curdepth,int peod,int eod)
{
    struct stat stbuf;
    struct dirent **items;
    char itempath[PATH_MAX];
    int i,itemnum;
    for(i=0;i<curdepth-1;i++)   printf(" %s\t ",i==curdepth-2&&peod&&eod?" ":"│");
    if(eod) printf(" └────────");
    else printf(" ├────────");
    printf("%s\n",fname);
    
    lstat(curpath,&stbuf);
    if(S_ISDIR(stbuf.st_mode))
    {
        itemnum = scandir(curpath,&items,dotfilter,alphasort);  //알파벳 순 출력
        for(i=0;i<itemnum-1;i++)
        {
            sprintf(itempath,"%s/%s",curpath,items[i]->d_name);
            lstat(itempath,&stbuf);
            print_tree(itempath,items[i]->d_name,curdepth+1,eod,0);
            free(items[i]);
        }
        if(itemnum)
        {
            sprintf(itempath,"%s/%s",curpath,items[i]->d_name);
            lstat(itempath,&stbuf);
            print_tree(itempath,items[i]->d_name,curdepth+1,eod,1);        //디렉토리 마지막 처리
            free(items[i]);
            free(items);
        }
    }
}
int do_tree(int pargc, char *pargv[ARGNUM])
{
    //TODO: 기본동작 : 디렉토리 구조 보여주기
    struct stat stbuf;
    struct dirent **items;
    char curpath[PATH_MAX],itempath[PATH_MAX];
    int i,itemnum;
    
    if(pargc > 1)
    { fprintf(stderr,"too many arguments\n");   return -1;}
    chdir(monitorpath);
    if(access(programpath,F_OK))
    { fprintf(stderr,"%s is not exist!\n",MNTRDIR);    return -1;}

    strcpy(curpath,monitorpath);

    printf("%s\n",MNTRDIR); //depth : 0

    //하위 디렉토리 출력
    itemnum = scandir(curpath,&items,dotfilter,alphasort);  //알파벳 순 출력
    for(i=0;i<itemnum-1;i++)
    {
        sprintf(itempath,"%s/%s",curpath,items[i]->d_name);
        lstat(itempath,&stbuf);
        print_tree(itempath,items[i]->d_name,1,0,0);
        free(items[i]);
    }
    if(itemnum)
    {
        sprintf(itempath,"%s/%s",curpath,items[i]->d_name);
        lstat(itempath,&stbuf);
        print_tree(itempath,items[i]->d_name,1,0,1);        //디렉토리 마지막 처리
        free(items[i]);
        free(items);
    }

    chdir(programpath);
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
