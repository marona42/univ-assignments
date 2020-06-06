#ssu_asdf : main.o ssu_mntr.o logger.o
#	gcc main.o ssu_mntr.o logger.o -o ssu_mntr

#main.o : main.c ssu_mntr.h
#	gcc -c main.c

#ssu_mntr.o : ssu_mntr.c ssu_mntr.h logger.h
#	gcc -c ssu_mntr.c
#	#gcc -c ssu_mntr.c -D DEBUG

#logger.o : logger.c logger.h
#	gcc -c logger.c

ssu_crond: ssu_crond.c
	gcc ssu_crond.c -o ssu_crond

ssu_crontab: bootstrap_c.o cront.o
	gcc bootstrap_c.o cront.o -o ssu_crontab

bootstrap_c: cront.o cront.h
	gcc -c bootstrap_c.o 

cront.o : cront.c cront.h
	gcc -c cront.c

ssu_rsync: bootstrap_r.o
	gcc bootstrap_r.o -o ssu_rsync

bootstrap_r: rsync.o rsync.h
	gcc -c bootstrap_r.o

rsync.o : rsync.c rsync.h
	gcc -c rync.c -lpthread

clean :
	rm *.o
	rm ssu_rsync
	rm ssu_crontab
	rm ssu_crond