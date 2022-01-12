all: babyQuery

babyQuery: removeCommas.o babyQuery.o showTop.o searchResult.o getStr.o
	gcc -ansi -Wall -o babyQuery babyQuery.o removeCommas.o showTop.o searchResult.o getStr.o

babyQuery.o: babyQuery.c
	gcc -ansi -Wall -c babyQuery.c

getStr.o: getStr.c
	gcc -ansi -Wall -c getStr.c

showTop.o: showTop.c
	gcc -ansi -Wall -c showTop.c

searchResult.o: searchResult.c
	gcc -ansi -Wall -c searchResult.c

clean:
	rm babyQuery showTop.o searchResult.o getStr.o babyQuery.o
