#ifndef PATH_MAX
    #define PATH_MAX 512
#endif
#define SNUMBER 20162447
#define ARGNUM 8

void ssu_crontab(int argc, char *argv[]);
int do_prmpt(int pargc,char *pargv[ARGNUM]);
int do_add(int pargc,char *pargv[ARGNUM]);
int do_remove(int pargc,char *pargv[ARGNUM]);