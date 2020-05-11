
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

extern char programpath[PATH_MAX],monitorpath[PATH_MAX];

void ssu_mntr(int argc, char *argv[]);
int do_prmpt(int pargc, char *pargv[]);
int do_delete(int pargc, char *pargv[ARGNUM]);
int do_size(int pargc, char *pargv[ARGNUM]);
int do_recover(int pargc, char *pargv[ARGNUM]);
int do_tree(int pargc, char *pargv[ARGNUM]);
int do_exit(int pargc, char *pargv[ARGNUM]);
int do_help(int pargc, char *pargv[ARGNUM]);