all: dynCGOL cgol

dynCGOL: readSeed.o dynCGOL.o displayWorld.o updateCell.o
	gcc -ansi -Wall -o dynCGOL dynCGOL.o readSeed.o displayWorld.o updateCell.o

cgol: readSeed.o cgol.o displayWorld.o updateCell.o
	gcc -ansi -Wall -o cgol cgol.o readSeed.o displayWorld.o updateCell.o

cgol.o: cgol.c
	gcc -ansi -Wall -c cgol.c

dynCGOL.o: dynCGOL.c
	gcc -ansi -Wall -c dynCGOL.c

readSeed.o: readSeed.c
	gcc -ansi -Wall -c readSeed.c

displayWorld.o: displayWorld.c
	gcc -ansi -Wall -c displayWorld.c

updateCell.o: updateCell.c
	gcc -ansi -Wall -c updateCell.c

clean:
	rm dynCGOL cgol *o *seed
