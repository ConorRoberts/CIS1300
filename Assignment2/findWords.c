#include <stdio.h>
#include <string.h>
#include "textProc.h"

#define MAXSIZE  500    /* maximum size of input line */
#define MAXWORDS 1000   /* maximum number of unique words */
/* 
 * Program Name:findWords.c
 * Author(s): Deb Stacey
 * Purpose: find words in text (STDIN)
 */ 

int main ( int argc, char *argv[] ) {
   char line[MAXSIZE];
   int i,j;
   int length;
   int numWords;
   int words[MAXWORDS];

   while ( fgets ( line, MAXSIZE, stdin ) != NULL ) {
      chop ( line );
      convertLowerCase ( line );
      replaceDigits ( line );
      replacePunc ( line );
      reduceSpace ( line );
      trim ( line );

      length = strlen(line) + 1;
      j = 0;
      numWords = 0;
      words[j++] = 0;
      for ( i=1; i<length; i++ ) {
         if ( line[i] == ' ' || line[i] == '\0' ) {
	    line[i] = '\0';
	    numWords++;
	    words[j++] = i+1;
	 }
      }
      for ( i=0; i<numWords; i++ ) {
	 if ( strlen(&line[words[i]]) > 5 ) {
	    printf ( "%s\n",&line[words[i]] );
	 }
      }

   } 


   return ( 0 );
}
