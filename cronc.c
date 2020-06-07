/*
commons library of crontab, crondaemon

logging at logfile, read/write tabfile
parsing time period.
*/

/*
tabfile structure:
[period by 5 arguments] [command]
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "cronc.h"
FILE *tabf, *logf, *tmp;
char *actions[]={"","run","add","remove"};

int isnumber(const char *str)   //주어진 문자열이 숫자로만 있는지: 정수인가?
{
    int i,len=strlen(str);
    for(int i=0;i<len;i++)
        if(!isdigit(str[i])) return false;
    return true;
}
int is_valid(char t)  //주어진 문자가 주기로 유효한지 확인
{
    if(t == '*' || t == '/' || t == ',' || t == '-' || isdigit(t))
        return 1;
    else return 0;
}
int are_valid(char *ar) //주어진 문자열이 유효한지 본다
{
    int len=strlen(ar),i;
    for(i = 0;i<len;i++) if(!is_valid(ar[i])) return 0;
    return 1;
}

void add_tab(char *txt) //tabfile에 내용 추가
{
    if(access(TABNAME,R_OK))
    {
        fprintf(stderr,"Warning: %s doesn't exist. creating %s...\n",TABNAME,TABNAME);
    }
    tabf=fopen(TABNAME,"a");
    fprintf(tabf,"%s\n",txt);
    fclose(tabf);
}

void add_log(char *txt,int action)  //로그파일에 현재 시간과 동작종류를 붙여 내용 추가
{
    char timememo[BUFSIZE];
    time_t timenow;

    if(access(LOGNAME,R_OK))
    {
        fprintf(stderr,"Warning: %s doesn't exist. creating %s...\n",LOGNAME,LOGNAME);
    }
    if(action == A_REMOVE)  //remove를 로그로 쓸 경우, txt로 받아오는건 log의 줄번호다.
    {
        logf=fopen(LOGNAME,"w+");   //파일 생성을 위해 r+가 아닌 w+
        int line=atoi(txt),i;
        char *d;
        for(i=0;i<line;i++) scanf("%*s %*s %*s %*s %*s %[^\n]",txt);    //txt에 커맨드 저장
        fseek(logf,0,SEEK_END); //오프셋을 맨 뒤로
    }
    else logf=fopen(LOGNAME,"a");
    time(&timenow); //현재시간을 받아옴
    strftime(timememo,BUFSIZE,TIMEFORMAT,localtime(&timenow));   //포맷에 맞게 문자열 변환
    fprintf(logf,"[%s] %s %s\n",timememo,actions[action],txt);   //로그파일 끝에 내용 씀
    fclose(logf);
}

int line_tab()  //tabfile의 줄수 가져옴
{
    char tmp;
    int fd,cnt=0;
    if(open(TABNAME,O_RDONLY) < 0)
    { fprintf(stderr,"Warning: cannot open %s\n",TABNAME);  return -1; }
    while(1)
        if(read(fd,&tmp,1)>0) {if(tmp=='\n') cnt++;}    //개행문자만 셈
        else break;
    close(fd);
    return cnt;
}

int show_tab()  //tabfile을 표시하고 줄수를 리턴함
{
    char buf[BUFSIZE];
    int lcnt=0;
    tabf=fopen(TABNAME,"r");
    while(!feof(tabf))
    {
        fgets(buf,256,tabf);
        printf("%d. %s\n",++lcnt,buf);
    }
    return lcnt;
}