#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "crond.h"

const char *action[]={NULL,"create","delete","modify"};

pid_t dpid;
FILE *mlog;
//statdata *filetable[BUCKETSIZE]={0};
int logger_daemon_init(const char *ppath)
{
	int fd, maxfd;
	char logpath[PATH_MAX];

	if ((dpid = fork()) < 0)
	{ fprintf(stderr,"fork error\n");	exit(1); }
	else if(dpid != 0)
		exit(0);

	dpid = getpid();
	#ifdef DEBUG
		printf("process %d running as daemon\n",dpid);
	#endif
	setsid();
	signal(SIGTTIN,SIG_IGN);
	signal(SIGTTOU,SIG_IGN);
	signal(SIGTSTP,SIG_IGN);
	maxfd = getdtablesize();

	umask(0);
	chdir("/");
	for (fd = 0;fd < maxfd;fd++)
		close(fd);
	fd = open("/dev/null", O_RDWR);
	dup(0);
	dup(0);

	strcpy(logpath,ppath);
	strcat(logpath,"/");	strcat(logpath,LOGNAME);	//logpath에 로그파일의 절대경로를 기록한다.
	mlog=fopen(logpath,"a");
	setvbuf(mlog,NULL,_IOLBF,0);	//라인버퍼로 출력이 이루어지게끔 변경
	return 0;
}
int dotfilter(const struct dirent *ent) //scandir시 ., .. 제외
{ return strcmp(ent->d_name,".") && strcmp(ent->d_name,".."); }
int inspect_file(statdata *sd,const struct stat *st,const char *fname,time_t now)	//테이블을 참조해 상태를 반환한다
{
																				//테이블에 없는데 디렉토리에 있음=created[1]
	if(sd==NULL) {table_add(st,fname,now); return 1;} 									//테이블에 있는데 디렉토리에 없음=deleted[2]
	if(st->st_mtime!=sd->mtime)	{sd->mtime=st->st_mtime; return 3;}				//둘 다 있고 		mtime이 바뀜 =modified[3]
	else return 0;	//nothing happened
}
void table_add(const struct stat *st,const char *name,time_t now)	//테이블 요소 추가
{
	statdata *cur=filetable[(st->st_ino)%BUCKETSIZE], *pre=NULL;
	while(cur!=NULL)
	{
		pre=cur;
		cur=cur->next;
	}
	if(cur == pre) //첫 요소인 경우
	{
		cur = malloc(sizeof(statdata));
		cur->prev=NULL;
		filetable[(st->st_ino)%BUCKETSIZE]=cur;
	}
	else
	{
		cur = malloc(sizeof(statdata));
		cur->prev=pre;
		pre->next=cur;
	}
	cur->next=NULL;
	cur->inode=st->st_ino;
	cur->mtime=st->st_mtime;
	cur->refresh=now;
	cur->fname=malloc(sizeof(char)*strlen(name));
	strcpy(cur->fname,name);
}
void table_del(statdata *sd)	//테이블 요소 삭제
{
	if(sd->next && sd->prev)	//중간에 낀 경우
	{
		sd->next->prev = sd->prev;
		sd->prev->next = sd->next;
	}
	else if(!sd->next && !sd->prev)	//혼자인 경우
	{
		filetable[sd->inode%BUCKETSIZE]=NULL;
	}
	else if(sd->next == NULL)	//마지막인 경우
	{
		sd->prev->next=NULL;
	}
	else						//처음인 경우
	{
		sd->next->prev=NULL;
	}
	fflush(stdout);
	free(sd->fname);
	fflush(stdout);
	free(sd);
}
void table_chk(time_t now)	//테이블을 순회히 디렉토리에서 삭제된 파일이 있는지 찾고 출력한다.
{
	int i;
	statdata *cur;
	char timememo[BUFSIZE];
	strftime(timememo,BUFSIZE,TIMEFORMAT,localtime(&now));

	for(i=0;i<BUCKETSIZE;i++)	//모든 filetable요소를 순회
	{
		cur=filetable[i];
		while(cur!=NULL)
		{
			if(cur->refresh != now)	//파일테이블이 참조되지 않았다면
			{
				fprintf(mlog,"[%s][%s_%s]\n",timememo,action[2],cur->fname);	//삭제된것이므로 로그
				statdata *tmp;
				tmp = cur;
				cur=cur->next;
				fflush(stdout);
				table_del(tmp);	//테이블에서도 삭제한다
			}
			else
				cur=cur->next;
		}
	}
}
statdata *table_if(ino_t ino,time_t now)	//ino를 가진 statdata가 있는지 체크한다
{
	statdata *cur=filetable[ino%BUCKETSIZE];
	while(cur!=NULL)
	{
		if(cur->inode==ino)
		{
			cur->refresh=now;
			return cur;
		}
		else cur=cur->next;
	}
	return NULL;
}
void init_monitoring(const char *mpath)		//디렉토리를 보고 filetable을 생성한다
{
	struct stat statbuf;
    struct dirent **items;
    int itemnum,i;
    char itempath[PATH_MAX];
	time_t now;
	time(&now);

    itemnum = scandir(mpath,&items,dotfilter,NULL);
    for(i=0;i<itemnum;i++)
    {
        sprintf(itempath,"%s/%s",mpath,items[i]->d_name);
        lstat(itempath,&statbuf);
        table_add(&statbuf,items[i]->d_name,now);	//filetable 추가

		if(S_ISDIR(statbuf.st_mode))	//디렉토리인 경우
			init_monitoring(itempath);	//재귀호출로 내부 파일도 생성한다
        free(items[i]);
    }
    free(items);
}
void do_monitor(const char *path)
{
	time_t timenow;
	time(&timenow);					//현재 시간을 기준으로
	do_monitoring(path,timenow);	//생성, 변경한 경우를 찾는다
	table_chk(timenow);				//삭제한 파일을 찾는다
}
void do_monitoring(const char *path,time_t timenow)
{
	struct stat statbuf;
    struct dirent **items;
    int itemnum,i,mstatus;
    char itempath[PATH_MAX],timememo[BUFSIZE];

	strftime(timememo,BUFSIZE,TIMEFORMAT,localtime(&timenow));
    itemnum = scandir(path,&items,dotfilter,NULL);
    for(i=0;i<itemnum;i++)
    {
        sprintf(itempath,"%s/%s",path,items[i]->d_name);
        lstat(itempath,&statbuf);
        if(mstatus=inspect_file(table_if(statbuf.st_ino,timenow),&statbuf,items[i]->d_name,timenow))	//변경,생성된 경우
		{
			fprintf(mlog,"[%s][%s_%s]\n",timememo,action[mstatus],items[i]->d_name);	//그 내용을 로그에 출력한다
		}
		if(S_ISDIR(statbuf.st_mode))		//디렉토리인 경우
			do_monitoring(itempath,timenow);	//내부의 파일도 확인
        free(items[i]);
    }
    free(items);
}