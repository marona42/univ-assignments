
#ifndef true
	#define true 1
#endif
#ifndef false
	#define false 0
#endif
#define BUFSIZE 256
#ifndef PATH_MAX
    #define PATH_MAX 1024
#endif
#define ARGNUM 6
#define SNUMBER 20162447
#define MNTRDIR "watching"
#define TIMEFORMAT "%Y-%m-%d %H:%M:%S"
#define INFOSZLIMIT 2048

extern char programpath[PATH_MAX],monitorpath[PATH_MAX];

int dotfilter(const struct dirent *ent);
int rename_all(const char *srcpath,const char *destpath);
int remove_all(const char *path);

void ssu_mntr(int argc, char *argv[]);
int do_prmpt(int pargc, char *pargv[]);
int do_delete(int pargc, char *pargv[ARGNUM]);
int do_size(int pargc, char *pargv[ARGNUM]);
int do_recover(int pargc, char *pargv[ARGNUM]);
int do_tree(int pargc, char *pargv[ARGNUM]);
int do_exit(int pargc, char *pargv[ARGNUM]);
int do_help(int pargc, char *pargv[ARGNUM]);
