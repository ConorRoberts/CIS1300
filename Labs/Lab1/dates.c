#include <stdio.h>
#include <stdlib.h>

/*
 *   Program name: dates.c
 *   Author: Conor Roberts
 *   Last Update: September 11, 2019
 *   Function: to print out date given on command line
 *   Compilation: gcc -ansi -o dates dates.c
 *   Execution: ./dates 23 8 2019
 */

int main ( int argc, char *argv[] ) {

   /* Names of the months */
   char *monthName[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September",
                      "October", "November", "December" };

   /* The number of days in each month */
   int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   int dd = 0;
   int mm = 0;
   int yyyy = 0;

   if ( argc!=4 ) {
      printf ( "Usage: ./dates dd mm yyyy \n" );
      exit ( 1 );
   } else {
      dd = atoi ( argv[1] );
      mm = atoi ( argv[2]);
      yyyy = atoi ( argv[3] );
   }

   /*Checks if month is in range*/
   if (mm<1 || mm>12){
    printf("Error - the month entered (%d) is not in the proper range (1-12)\n",mm);
    exit (2);
   }

   /*Checks if it's a leap year*/
   if ((yyyy%4==0 && (yyyy%100)>0) || yyyy%400==0){
      monthLength[1]=29;
      printf("This is a leap year\n");
   }else{
      printf("This is not a leap year.");
   }

   /*Checks if day is in range*/
   if (dd<1 || dd>monthLength[mm-1]){
       printf("Error - you entered %d for the day and that is not in the range 1-%d\n",dd,monthLength[mm-1]);
       exit (3);
   }

   printf ( "In %s there are %d days\n", monthName[mm-1], monthLength[mm-1]);

   return (0);
}
