#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLENGTH 20
#define ROWS 200

void searchResult(char name[],int gender,int year,char maleArr[ROWS][MAXLENGTH],char femaleArr[ROWS][MAXLENGTH],int maleArrN[ROWS],int femaleArrN[ROWS]){
  int maleRank=0;
  int femaleRank=0;
  int i;
  for (i=0;i<200;i++){
    if (strcmp(name,maleArr[i])==0) maleRank=i+1;
    if (strcmp(name,femaleArr[i])==0) femaleRank=i+1;
  }

  if (gender==1 || gender==2){
    if (femaleRank>0){
        printf("%d: Female name '%s' is ranked %d with a count of (%d)\n",year,name,femaleRank,femaleArrN[i-1]);
      }else{
        printf("%d: Female name '%s' is not ranked.\n",year,name);
    }
  }
  if (gender==0 || gender==2){
    if (maleRank>0){
        printf("%d: Male name '%s' is ranked %d with a count of (%d)\n",year,name,maleRank,maleArrN[i-1]);
      }else{
        printf("%d: Male name '%s' is not ranked.\n",year,name);
    }
  }
}
