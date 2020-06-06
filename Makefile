#ssu_asdf : main.o ssu_mntr.o logger.o
#	gcc main.o ssu_mntr.o logger.o -o ssu_mntr

#main.o : main.c ssu_mntr.h
#	gcc -c main.c

#ssu_mntr.o : ssu_mntr.c ssu_mntr.h logger.h
#	gcc -c ssu_mntr.c
#	#gcc -c ssu_mntr.c -D DEBUG

#logger.o : logger.c logger.h
#	gcc -c logger.c

ssu_rsync: bootstrap_r.o
	gcc bootstrap_r.o -o ssu_rsync

ssu_crontab: bootstrap_c.o crond.o
	gcc bootstrap_c.o crond.o -o ssu_crontab

cront.o : cront.c cront.h
	gcc -c cront.c

clean :
	rm *.o
	rm ssu_rsync
	rm ssu_crontab
