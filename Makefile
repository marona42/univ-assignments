#ssu_asdf : main.o ssu_mntr.o logger.o
#	gcc main.o ssu_mntr.o logger.o -o ssu_mntr

#main.o : main.c ssu_mntr.h
#	gcc -c main.c

#ssu_mntr.o : ssu_mntr.c ssu_mntr.h logger.h
#	gcc -c ssu_mntr.c
#	#gcc -c ssu_mntr.c -D DEBUG

#logger.o : logger.c logger.h
#	gcc -c logger.c

##ssu_crond: crond.c	cronc.o
##	gcc crond.c cronc.o -o ssu_crond

ssu_crontab: bootstrap_c.o cront.o cronc.o
	gcc bootstrap_c.o cront.o cronc.o -o ssu_crontab

bootstrap_c.o: cront.o cront.h cronc.o cronc.h
	gcc -c bootstrap_c.c

cront.o : cront.c cront.h cronc.h
	gcc -c cront.c

cronc.o : cronc.c cronc.h
	gcc -c cronc.c

##ssu_rsync: bootstrap_r.o
##	gcc bootstrap_r.c -o ssu_rsync
##
##bootstrap_r.o: rsync.o rsync.h
##	gcc -c bootstrap_r.o
##
##rsync.o : rsync.c rsync.h
##	gcc -c rync.c -lpthread

clean :
	rm *.o
	rm ssu_rsync
	rm ssu_crontab
	rm ssu_crond