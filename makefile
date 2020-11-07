FNAME = mid

$(FNAME) : lex.yy.c y.tab.c y.tab.h builder.c
	gcc -o $(FNAME) lex.yy.c y.tab.c y.tab.h builder.c print.c

lex.yy.c: yyparse.l 	y.tab.c
	lex yyparse.l

builder.o: builder.c type.h y.tab.c
	gcc -c builder.c

print.o: print.c type.h
	gcc -c print.c

y.tab.c: grammar.y type.h
	yacc -d grammar.y


clean:
	rm -f lex.yy.c y.tab.c y.tab.h build.o $(FNAME)