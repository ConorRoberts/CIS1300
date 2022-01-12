countLeaps: countLeaps.o isLeap.o
	gcc -ansi -Wall countLeaps.o isLeap.o -o countLeaps 

isLeap.o: isLeap.c
	gcc -ansi -Wall -c isLeap.c

countLeaps.o: countLeaps.c 
	gcc -ansi -Wall -c countLeaps.c

clean:
	rm countLeaps countLeaps.o isLeap.o