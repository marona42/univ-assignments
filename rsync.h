
#ifndef true
	#define true 1
#endif
#ifndef false
	#define false 0
#endif
#define BUFSIZE 256
#ifndef PATH_MAX
    #define PATH_MAX 512
#endif
#define ARGNUM 6
#define SNUMBER 20162447
#define INFOSZLIMIT 2048

time_t getdtime(const char *fname);
time_t getmtime(const char *fname);
int olddtimesort(const struct dirent **a, const struct dirent **b);
int dotfilter(const struct dirent *ent);
int rename_all(const char *srcpath,const char *destpath);
int remove_all(const char *path);
int getdirsize(const char *dirpath);
int isnumber(const char *str);
void getpath(const char *path, char *name);
int getname(const char *path, char *name);

void ssu_mntr(int argc, char *argv[]);
int do_prmpt(int pargc, char *pargv[]);
int do_delete(int pargc, char *pargv[ARGNUM]);
void do_size_d(const char *papath, const char *prpath, const char *fname,int depth);
int do_size(int pargc, char *pargv[ARGNUM]);
int do_recover(int pargc, char *pargv[ARGNUM]);
void print_tree(const char *curpath,const char *fname,int curdepth,int peod,int eod);
int do_tree(int pargc, char *pargv[ARGNUM]);
int do_help(int pargc, char *pargv[ARGNUM]);
