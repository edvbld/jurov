all:
	flex --header-file=lex.yy.h jurov.l
	bison -d jurov.y
	gcc -Wall -c lex.yy.c
	gcc -Wall -c jurov.tab.c
	g++ -Wall -c tests/lex_single_token.cpp
	g++ -Wall -c tests/lex_multiple_tokens.cpp
	g++ -lgtest -lpthread lex.yy.o jurov.tab.o lex_single_token.o lex_multiple_tokens.o run_all.cpp -o run_all

clean:
	rm -f lex.yy.h lex.yy.c jurov.tab.h jurov.tab.c *.o run_all
