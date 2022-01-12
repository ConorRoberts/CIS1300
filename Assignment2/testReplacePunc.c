#include <stdio.h>
#include <string.h>
#include "textProc.h"

#define MAXSIZE  500    /* maximum size of input line */

int main ( int argc, char *argv[] ) {
   char line[MAXSIZE];
   int ret;

   while ( fgets ( line, MAXSIZE, stdin ) != NULL ) {
      ret = replacePunc ( line );
      printf ( "%d - %s", ret, line );
   } 

   return ( 0 );
}
