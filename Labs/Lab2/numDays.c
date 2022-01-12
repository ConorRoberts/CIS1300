#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 *   Program name: numDays.c
 *   Author: Conor Roberts
 *   Date Created: September 29, 2019
 *   Function: Returns date that is a specificed number of days away
 *   Compilation: gcc -ansi -o numDays numDays.c
 *   Execution: ./numDays 15-01-2019 60
 */

/*Function to determine if a year is a leap year*/
bool leap(int y){
    if ((y%4==0 && (y%100)>0) || y%400==0){
        return (true);
    }else{
        return (false);
    }
}

/*Checks if a given date is valid and prints errors accordingly*/
bool dateValid(int d, int m, int y){
    int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (leap(y)){
        months[1]=29;
    }

    if(y<1582){
        printf("Error - Year less than 1582.\n");
        return (false);
    }
    if(m<1 || m>12){
        printf("Error - Month out of range.\n");
        return (false);
    }
    if (d<1 || d>months[m-1]){
        printf("Error - Day out of range.\n");
        return (false);
    }

    return (true);
}

/*Calculates the day/365(366) of a given date*/
int dayNum(int d,int m, int y){
    int dayYear[12]={1,32,60,91,121,152,182,213,244,274,305,335};
    int i=0;
    if (leap(y)){
        for (i=2;i<12;i++){
            dayYear[i]+=1;
        }
    }

    return (dayYear[m-1]+d-1);
}

/*Main program code*/
int main ( int argc, char *argv[] ) {

    int monthLength[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    int minArg=5;
    int maxArg=5;
    
    /*Checking number of arguments*/
    if (argc<minArg || argc>maxArg) {
      printf ("Usage: ./numDays dd1 mm1 yyyy1 <int>\n");
      exit(1);
   }

    /*Formatting arguments into usable variables*/
    int day=atoi(argv[1]);
    int month=atoi(argv[2]);
    int year=atoi(argv[3]);

    int shift=atoi(argv[4]);

    if (shift>300){
        printf("Invalid number of days\n");
        exit(2);
    }

    if (dateValid(day,month,year)==false){
        exit(3);
    }

    if (leap(year)){
        monthLength[1]=29;
    }

    int i,m,d=0;
    int y=year;

    /*
    Explanation for the lab
    i, m, d, y are counters
    i - Count the total amount of time the loop runs so that it can match the inputted date
    m - Counts how many months the loop counts through so that it can match the inputted date
    d - Counts the current day of the month. This is primarily used so that 'm' can count properly
    y - Is either equal to year or year+1 if the loop has to go into a new year
    
    The first if statement checks if the end of the year has been reached and resets 'd' & 'm'
    The second if statement checks if the end of the month has been reached and resets the day counter.
    */
    while(i!=dayNum(day,month,year)+shift){
        d+=1;
        if (m==11 && d==monthLength[11]){
            d=0;
            m=0;
            y+=1;
            if (leap(y)){
                monthLength[1]=29;
            }else{
                monthLength[1]=28;
            }
        }
        if (d==monthLength[m]){
            d-=monthLength[m];
            m+=1;
        }
        i+=1;
    }

    printf("%.2d %.2d %d\n",d,m+1,y);
    
    return 0;
}
