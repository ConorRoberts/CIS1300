#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 *   Program name: daysCalculatorA.c
 *   Author: Conor Roberts
 *   Last Update: September 24, 2019
 *   Function: Calculate difference between two dates
 *   Compilation: gcc -ansi -o daysCalculatorA daysCalculatorA.c
 *   Execution: ./daysCalculatorA 15-01-2019 20-01-2019
 */

/*Function to determine if a year is a leap year*/
bool leap(int y){
    if ((y%4==0 && (y%100)>0) || y%400==0){
        return (true);
    }else{
        return (false);
    }
}

/*Calculates the number of days between two dates*/
int dayNum(int d,int m, int y){
    int dayYear[12]={1,32,60,91,121,152,182,213,244,274,305,335};
    int k,total=0;
    for (k=1582;k<y;k++){
            if (leap(k)){
                total+=1;
            }
            total+=365;
        }
    total+=dayYear[m-1]+d;

    return (total);
}

/*Main program code*/
int main ( int argc, char *argv[] ) {

    int monthLength[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    int startDate[3];
    int endDate[3];

    int minArg=7;
    int maxArg=7;
    
    /*Checking number of arguments*/
    if ( argc<minArg || argc>maxArg ) {
      printf ("Usage: ./dateCalculatorA dd1 mm1 yyyy1 dd2 mm2 yyyy2\n");
      exit (1);
   }

    /*Formatting arguments into usable variables*/
    startDate[0]=atoi(argv[1]);
    startDate[1]=atoi(argv[2]);
    startDate[2]=atoi(argv[3]);

    endDate[0]=atoi(argv[4]);
    endDate[1]=atoi(argv[5]);
    endDate[2]=atoi(argv[6]);

    if (startDate[2]!=endDate[2]){
        printf("Error - Years must be the same.\n");
        exit(80085);
    }

    /*Checking if year of startDate is leap and adjusting February accordingly*/
    if (leap(startDate[2])){
        monthLength[1]=29;
    }else{
        monthLength[1]=28;
    }
    if (startDate[0]<1 || startDate[0]>monthLength[startDate[1]-1]){
        printf("Error - Date out of range.\n");
        exit(69);
    }
    if (leap(endDate[2])){
        monthLength[1]=29;
    }else{
        monthLength[1]=28;
    }
    if (endDate[0]<1 || endDate[0]>monthLength[endDate[1]-1]){
        printf("Error - Date out of range.\n");
        exit(69);
    }

    /*Checking month number and year number*/
    if (startDate[1]<1 || startDate[1]>12 || endDate[1]<1 || endDate[1]>12 || startDate[2]<1582 || endDate[2]<1582){
        printf("Error - Date out of range.\n");
        exit(69);
    }
    
    int startDateN=dayNum(startDate[0],startDate[1],startDate[2]);
    int endDateN=dayNum(endDate[0],endDate[1],endDate[2]);

    printf("%d\n",endDateN-startDateN);

    return 0;
}
