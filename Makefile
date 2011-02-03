all:
	flex --header-file=lex.yy.h src/jurov.l
	bison -d src/jurov.y
	gcc -Wall -c lex.yy.c
	gcc -Wall -c jurov.tab.c
	g++ -Wall -c tests/lex_single_token.cpp -I .
	g++ -Wall -c tests/lex_multiple_tokens.cpp -I .
	g++ -lgtest -lpthread lex.yy.o jurov.tab.o lex_single_token.o lex_multiple_tokens.o tests/run_all.cpp -o run_all

clean:
	rm -f lex.yy.h lex.yy.c jurov.tab.h jurov.tab.c *.o run_all
