#include <stdio.h>
#include <string.h>
#include "textProc.h"

#define MAXSIZE  500    /* maximum size of input line */

int main ( int argc, char *argv[] ) {
   char line[MAXSIZE];
   int ret;

   while ( fgets ( line, MAXSIZE, stdin ) != NULL ) {
      chop ( line );
      convertLowerCase ( line );
      replaceDigits ( line );
      replacePunc ( line );
      reduceSpace ( line );
      ret = trim ( line );
      printf ( "%d - %s\n", ret, line );
   } 

   return ( 0 );
}
