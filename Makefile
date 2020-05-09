ssu_mntr : main.o ssu_mntr.o logger.o
	gcc main.o ssu_mntr.o logger.o -o ssu_mntr

main.o : main.c ssu_mntr.h
	gcc -c main.c

ssu_mntr.o : ssu_mntr.c ssu_mntr.h logger.h
	gcc -c ssu_mntr.c

logger.o : logger.c logger.h
	gcc -c logger.c

clean :
	rm *.o
	rm ssu_mntr

