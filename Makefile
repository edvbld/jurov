all:
	flex --header-file=lex.yy.h jurov.l
	bison -d jurov.y
	gcc -c lex.yy.c
	gcc -c jurov.tab.c
	g++ -c lexertest.cpp
	g++ -lgtest -lpthread lex.yy.o jurov.tab.o lexertest.o run_all.cpp -o run_all

clean:
	rm -f lex.yy.h lex.yy.c jurov.tab.h jurov.tab.c lex.yy.o jurov.tab.o lexertest.o run_all
