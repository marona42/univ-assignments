#ifndef true
	#define true 1
#endif
#ifndef false
	#define false 0
#endif
#define LOGNAME "ssu_crontab_log"
#define TABNAME "ssu_crontab_file"
#define TIMEFORMAT "%Y-%m-%d %H:%M:%S"
#define A_RUN 1
#define A_ADD 2
#define A_REMOVE 3

#define COMMAX 256
#define BUFSIZE 256
#include <time.h>

typedef struct tabcommand_s{

    struct tm peroid;
    char command[COMMAX];
} tabcom;

int isnumber(const char *str);
int is_valid(char t);
int are_valid(char *ar);
void add_log(char *txt,int action);
int line_tab();
int show_tab();