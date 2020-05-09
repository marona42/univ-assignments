#define BUFSIZE 256
#define ARGNUM 6
#define SNUMBER 20162447
void ssu_mntr(int argc, char *argv[]);
int do_prmpt(int pargc, char *pargv[]);
int do_delete(int pargc, char *pargv[ARGNUM]);
int do_size(int pargc, char *pargv[ARGNUM]);
int do_recover(int pargc, char *pargv[ARGNUM]);
int do_tree(int pargc, char *pargv[ARGNUM]);
int do_exit(int pargc, char *pargv[ARGNUM]);
int do_help(int pargc, char *pargv[ARGNUM]);