#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

void getStr(char in[], char prompt[]){
  printf("%s",prompt);
  fgets(in,500,stdin);
  if ((strlen(in)>0)&&(in[strlen(in)-1]=='\n'))
        in[strlen(in)-1]='\0';
}

int main(int argc, char *argv[]){
  char str[100];

  if (argc!=5){
    printf("Error - Usage: /dynCGOL <seed> <ticks> <row size> <col size>\n");
    return 0;
  }else if(!atoi(argv[2]) || !atoi(argv[3]) || !atoi(argv[4])){
    printf("Error - Argument must be integer greater than zero.\n");
    return 0;
  }

  int tickMax=atoi(argv[2]);
  int rowMax=atoi(argv[3]);
  int colMax=atoi(argv[4]);

  while(1){
    int row,col;
    int same=0;
    int tick=0;
    int rowLimit=0;
    int colLimit=0;

    if (rowMax<0 || colMax<0){
      printf("Error - Dimensions out of range.\n");
      return 0;
    }

    int currentWorld[rowMax][colMax];
    int futureWorld[rowMax][colMax];

    if (!readSeed(argv[1], &rowLimit, &colLimit, rowMax, colMax,currentWorld) && !readSeed(argv[1], &rowLimit, &colLimit, rowMax,colMax,futureWorld)){
      printf("Error - Couldn't read file.\n");
      return 0;
    }else if (tickMax<0){
      printf("Error - Invalid number of ticks\n");
      return 0;
    }else if (rowMax>rowLimit || colMax>colLimit){
      printf("Error - Dimensions too large. Must be within %d x %d.\n",rowLimit,colLimit);
      return 0;
    }

    displayWorld(rowMax,colMax,currentWorld,0);

    do{
      getStr(str,"Start? ");
      if (!strcmp(str,"n") || !strcmp(str,"N")){
        return 0;
      }
    }while(strcmp(str,"y") && strcmp(str,"Y"));

    while(tick<tickMax && !same){
      system("clear");

      for (row=0;row<rowMax;row++){
        for (col=0;col<colMax;col++){
          futureWorld[row][col]=updateCell(row,col,rowMax,colMax,currentWorld);
        }
      }

      if (!memcmp(currentWorld,futureWorld,sizeof(currentWorld))){
        same=1;
      }

      for (row=0;row<rowMax;row++){
        for (col=0;col<colMax;col++){
          currentWorld[row][col]=futureWorld[row][col];
        }
      }

      displayWorld(rowMax,colMax,currentWorld,tick+1);

      system("sleep 0.25");
      tick++;
    }
    do{
      getStr(str,"Run again? ");
      if (!strcmp(str,"n") || !strcmp(str,"N")){
        return 1;
      }
    }while(strcmp(str,"y") && strcmp(str,"Y"));
    do{
      getStr(str,"How many ticks? ");
    }while(!atoi(str));
    tickMax=atoi(str);
  }

  return 0;
}
