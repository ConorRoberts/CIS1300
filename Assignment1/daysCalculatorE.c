#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/*
 *   Program name: daysCalculatorE.c
 *   Author: Conor Roberts
 *   Last Update: September 24, 2019
 *   Function: Calculate difference between two dates
 *   Compilation: gcc -ansi -o daysCalculatorE daysCalculatorE.c
 *   Execution: ./daysCalculatorE 15-01-2019 20-01-2019 include
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
    if (leap(y)){ /*I'm a fucking retard*/
        total+=1;
    }
    total+=dayYear[m-1]+d;

    return (total);
}

/*Main program code*/
int main (int argc, char *argv[]) {

    int monthLength[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    char *startDateA[3];
    char *endDateA[3];

    int startDate[3];
    int endDate[3];

    int minArg=3;
    int maxArg=4;

    time_t t=time(NULL);
    struct tm tm =*localtime(&t);

    /*Checking number of arguments*/
    if ( argc<minArg || argc>maxArg ) {
      printf ("Usage: ./dateCalculatorE dd1-mm1-yyyy1 dd2-mm2-yyyy2 <include> \n");
      exit (1);
   }

   /*Formatting arguments into usable variables*/
    if (strcmp(argv[1],"today")==0){
        startDate[0]=tm.tm_mday;
        startDate[1]=tm.tm_mon+1;
        startDate[2]=tm.tm_year+1900;
    }else{
        char *p=strtok(argv[1],"-");
        int j=0;

        while(p !=NULL){
            startDateA[j++]=p;
            p=strtok(NULL,"-");
        }
        startDate[0]=atoi(startDateA[0]);
        startDate[1]=atoi(startDateA[1]);
        startDate[2]=atoi(startDateA[2]);
    }
    if (strcmp(argv[2],"today")==0){
        endDate[0]=tm.tm_mday;
        endDate[1]=tm.tm_mon+1;
        endDate[2]=tm.tm_year+1900;
    }else{
        char *p=strtok(argv[2],"-");
        int j=0;

        while(p !=NULL){
            endDateA[j++]=p;
            p=strtok(NULL,"-");
        }
        endDate[0]=atoi(endDateA[0]);
        endDate[1]=atoi(endDateA[1]);
        endDate[2]=atoi(endDateA[2]);
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

    /*Checking if day #2 should be included*/
   if(argc==maxArg){
       if ((strcmp(argv[3],"include")==0)){
           endDateN+=1;
       }else{
           printf("Error - Proper syntax is 'include' or no arguement.\n");
           exit(5);
       }
   }

    /*Checking if startDateN is before endDateN*/
   if(endDateN<startDateN){
       printf("Error - Day #1 must occur before day #2.\n ");
       exit(3);
   }

    printf("%d\n",endDateN-startDateN);

    return 0;
}
