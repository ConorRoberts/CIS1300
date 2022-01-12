Cc=gcc
CFLAGS=-ansi -Wall
UTILLIB=libutil.a
UTILFLAG=-lutil
UTILDIR=.

all: wordBag findWords $(UTILLIB) testChop testConvert testReplaceDigits testReplacePunc testReduceSpace testTrim

wordBag: wordBag.o $(UTILLIB)
	$(CC) $(CFLAGS) -o wordBag wordBag.o -L$(UTILDIR) $(UTILFLAG)

findWords: findWords.o $(UTILLIB)
	$(CC) $(CFLAGS) -o findWords findWords.o -L$(UTILDIR) $(UTILFLAG)

$(UTILLIB): chop.o convertLowerCase.o replaceDigits.o replacePunc.o reduceSpace.o trim.o
	ar crs $@ $^ 

testChop: testChop.o chop.o
	$(CC) $(CFLAGS) -o testChop testChop.o chop.o

testConvert: testConvert.o convertLowerCase.o
	$(CC) $(CFLAGS) -o testConvert testConvert.o convertLowerCase.o

testReplaceDigits: testReplaceDigits.o replaceDigits.o
	$(CC) $(CFLAGS) -o testReplaceDigits testReplaceDigits.o replaceDigits.o

testReplacePunc: testReplacePunc.o replacePunc.o
	$(CC) $(CFLAGS) -o testReplacePunc testReplacePunc.o replacePunc.o

testReduceSpace: testReduceSpace.o $(UTILLIB)
	$(CC) $(CFLAGS) -o testReduceSpace testReduceSpace.o -L$(UTILDIR) $(UTILFLAG)

testTrim: testTrim.o $(UTILLIB)
	$(CC) $(CFLAGS) -o testTrim testTrim.o -L$(UTILDIR) $(UTILFLAG)

wordBag.o: wordBag.c textProc.h
	$(CC) $(CFLAGS) -c wordBag.c
findWords.o: findWords.c textProc.h
	$(CC) $(CFLAGS) -c findWords.c
testChop.o: testChop.c textProc.h
	$(CC) $(CFLAGS) -c testChop.c
testConvert.o: testConvert.c textProc.h
	$(CC) $(CFLAGS) -c testConvert.c
testReplaceDigits.o: testReplaceDigits.c textProc.h
	$(CC) $(CFLAGS) -c testReplaceDigits.c
testReplacePunc.o: testReplacePunc.c textProc.h
	$(CC) $(CFLAGS) -c testReplacePunc.c
testReduceSpace.o: testReduceSpace.c textProc.h
	$(CC) $(CFLAGS) -c testReduceSpace.c
testTrim.o: testTrim.c textProc.h
	$(CC) $(CFLAGS) -c testTrim.c
chop.o: chop.c
	$(CC) $(CFLAGS) -c chop.c
convertLowerCase.o: convertLowerCase.c
	$(CC) $(CFLAGS) -c convertLowerCase.c
replaceDigits.o: replaceDigits.c
	$(CC) $(CFLAGS) -c replaceDigits.c
replacePunc.o: replacePunc.c
	$(CC) $(CFLAGS) -c replacePunc.c
reduceSpace.o: reduceSpace.c
	$(CC) $(CFLAGS) -c reduceSpace.c
trim.o: trim.c
	$(CC) $(CFLAGS) -c trim.c

