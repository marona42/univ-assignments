#ifndef true
	#define true 1
#endif
#ifndef false
	#define false 0
#endif
#define LOGNAME "log.txt"
#define TIMEFORMAT "%Y-%m-%d %H:%M:%S"
#define MNTRDIR "watching"
#define BUFSIZE 256
#ifndef PATH_MAX
    #define PATH_MAX 1024
#endif
#define BUCKETSIZE 512
typedef struct stat_st{
    time_t mtime;
    time_t refresh;
    ino_t inode;
    char *fname;
    struct stat_st *next, *prev;
} statdata;

int dotfilter(const struct dirent *ent);
int logger_daemon_init(const char *ppath);
int inspect_file(statdata *sd,const struct stat *st,const char *fname);
void init_monitoring(const char *mpath);
void do_monitor(const char *path);
void do_monitoring(const char *path,time_t timenow);

void table_add(const struct stat *st,const char *name);
void table_del(statdata *sd);
void table_chk(time_t now);
statdata *table_if(ino_t ino,time_t now);