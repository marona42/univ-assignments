FNAME = a5

$(FNAME) : lex.yy.c y.tab.c y.tab.h
	gcc -o $(FNAME) lex.yy.c y.tab.c y.tab.h

lex.yy.c: $(FNAME).l 	y.tab.c
	lex $(FNAME).l

y.tab.c: $(FNAME).y
	yacc -d $(FNAME).y

clean:
	rm -f lex.yy.c y.tab.c y.tab.h $(FNAME)