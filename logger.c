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
#include "logger.h"

const char *action[]={NULL,"create","delete","modify"};

pid_t dpid;
FILE *mlog;
char path[PATH_MAX];
statdata *filetable[BUCKETSIZE];
int logger_daemon_init(const char *ppath)
{
	int fd, maxfd;
	char logpath[PATH_MAX];

	if ((dpid = fork()) < 0)
	{ fprintf(stderr,"fork error\n");	exit(1); }
	else if(dpid != 0)
		exit(0);

	dpid = getpid();
	printf("process %d running as daemon\n",dpid);
	setsid();
	signal(SIGTTIN,SIG_IGN);
	signal(SIGTTOU,SIG_IGN);
	signal(SIGTSTP,SIG_IGN);
	maxfd = getdtablesize();

	for (fd = 0;fd < maxfd;fd++)
		close(fd);
	umask(0);
	chdir("/");
	fd = open("/dev/null", O_RDWR);
	dup(0);
	dup(0);
	strcpy(path,ppath);
	strcat(path,"/");	strcat(path,MNTRDIR);
	strcpy(logpath,path);
	strcat(logpath,"/");	strcat(logpath,LOGNAME);
	mlog=fopen(logpath,"a");
	setvbuf(mlog,NULL,_IOLBF,0);
	return 0;
}
int dotfilter(const struct dirent *ent) //scandir시 ., .. 제외
{ return strcmp(ent->d_name,".") && strcmp(ent->d_name,".."); }
int inspect_file(statdata *sd,const struct stat *st,const char *fname)
{
																				//테이블에 없는데 디렉토리에 있음=created[1]
	if(sd==NULL) {table_add(st,fname); return 1;} 									//테이블에 있는데 디렉토리에 없음=deleted[2]
	if(st->st_mtime!=sd->mtime)	{sd->mtime=st->st_mtime; return 3;}				//둘 다 있고 		mtime이 바뀜 =modified[3]
	else return 0;	//nothing happened
}
void table_add(const struct stat *st,const char *name)
{
	statdata *cur=filetable[st->st_ino%BUCKETSIZE], *pre;
	pre=cur;
	while(cur!=NULL)
	{
		pre=cur;
		cur=cur->next;
	}
	if(cur == pre) //첫 요소인 경우
		cur->prev=NULL;
	else
		cur->prev=pre;

	cur = malloc(sizeof(statdata));
	cur->next=NULL;
	cur->inode=st->st_ino;
	cur->mtime=st->st_mtime;
	cur->fname=malloc(sizeof(char)*strlen(name));
	strcpy(cur->fname,name);
}
void table_del(statdata *sd)
{
	if(sd->next && sd->prev)	//중간에 낀 경우
	{
		sd->next->prev = sd->prev;
		sd->prev->next = sd->next;
	}
	else if(sd->next == NULL)	//마지막인 경우
	{
		sd->prev->next=NULL;
	}
	else						//처음인 경우
	{
		sd->next->prev=NULL;
	}

	free(sd->fname);
	free(sd);
}
void table_chk(time_t now)
{
	int i;
	statdata *cur;
	char timememo[BUFSIZE];
	strftime(timememo,BUFSIZE,TIMEFORMAT,localtime(&now));

	for(i=0;i<BUCKETSIZE;i++)
	{
		cur=filetable[i];
		while(cur!=NULL)
		{
			if(cur->refresh != now)
			{
				fprintf(mlog,"[%s][%s_%s]\n",timememo,action[2],cur->fname);
				statdata *tmp = cur;
				cur=cur->next;
				table_del(tmp);
			}
			else
				cur=cur->next;
		}
	}
}
statdata *table_if(ino_t ino,time_t now)
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
void init_monitoring(const char *mpath)
{
	struct stat statbuf;
    struct dirent **items;
    int itemnum,i;
    char itempath[PATH_MAX];

    itemnum = scandir(mpath,&items,dotfilter,NULL);
    for(i=0;i<itemnum;i++)
    {
        sprintf(itempath,"%s/%s",mpath,items[i]->d_name);
        lstat(itempath,&statbuf);
        table_add(&statbuf,items[i]->d_name);

		if(S_ISDIR(statbuf.st_mode))
			init_monitoring(itempath);
        free(items[i]);
    }
    free(items);
}
void do_monitor(const char *path)
{
	time_t timenow;
	time(&timenow);
	do_monitoring(path,timenow);
	table_chk(timenow);
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
        if(mstatus=inspect_file(table_if(statbuf.st_ino,timenow),&statbuf,items[i]->d_name))
			fprintf(mlog,"[%s][%s_%s]\n",timememo,action[mstatus],items[i]->d_name);

		if(S_ISDIR(statbuf.st_mode))
			do_monitoring(itempath,timenow);
        free(items[i]);
    }
    free(items);
}