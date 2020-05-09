#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "ssu_mntr.h"

#define SECOND_TO_MICRO 1000000

void ssu_runtime(struct timeval *begin_t, struct timeval *end_t);

int main(int argc, char *argv[])
{
	struct timeval begin_t, end_t;	
	gettimeofday(&begin_t, NULL);	//시작시간을 저장, 뒤의 NULL은 사용하지 않는 timezone인자.

	ssu_mntr(argc, argv);			//채점 시작

	gettimeofday(&end_t, NULL);		//끝난 시간을 저장.
	ssu_runtime(&begin_t, &end_t);

	exit(0);
}

void ssu_runtime(struct timeval *begin_t, struct timeval *end_t)
{
	end_t->tv_sec -= begin_t->tv_sec;	//초단위로 끝난시간-시작시간 계산

	if(end_t->tv_usec < begin_t->tv_usec){	//마이크로초 받아내림을 위한 연산
		end_t->tv_sec--;					//1초를 초단위에서 빼고
		end_t->tv_usec += SECOND_TO_MICRO;	//1초를 마이크로초에 더한다
	}

	end_t->tv_usec -= begin_t->tv_usec;		//마이크로초 뺄셈 연산
	printf("%s exited.\nRuntime: %ld:%06ld(sec:usec)\n",argv[0], end_t->tv_sec, end_t->tv_usec);	//마이크로초의 경우, leading zero포함해 6자리 고정포맷.
}
