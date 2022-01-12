#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

void getStr(char in[], char prompt[]){
  printf("%s",prompt);
  fgets(in,500,stdin);
  if ((strlen(in) > 0) && (in[strlen (in) - 1] == '\n'))
        in[strlen (in) - 1] = '\0';
}

int main(int argc, char *argv[]){
  char str[100];
  int tickMax;

  if (argc==2){
    tickMax=50;
  }else if (argc!=3){
    printf("Error - Usage: ./cgol <seed> <ticks>\n");
    return 0;
  }else if(!atoi(argv[2])){
    printf("Error - Ticks must be integer greater than zero.\n");
    return 0;
  }else{
    tickMax=atoi(argv[2]);
  }

  while(1){
    int row,col;
    int tick=0;
    int colLimit=0;
    int rowLimit=0;
    int rowMax=20;
    int colMax=40;
    int same=0;

    int currentWorld[rowMax][colMax];
    int futureWorld[rowMax][colMax];

    if (!readSeed(argv[1], &rowLimit, &colLimit, rowMax, colMax,currentWorld) && !readSeed(argv[1], &rowLimit, &colLimit, rowMax,colMax,futureWorld)){
      printf("Error - Couldn't read file.\n");
      return 0;
    }else if (rowLimit!=20 || colLimit!=40){
      printf("Error - File size invalid. Only sizes of 20 x 40 are acceptable.\n");
      return 0;
    }else if (tickMax<0){
      printf("Error - Invalid number of ticks\n");
      return 0;
    }

    displayWorld(rowMax,colMax,currentWorld,0);

    do{
      getStr(str,"Start? ");
      if (!strcmp(str,"n") || !strcmp(str,"N")){
        return 1;
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
  return 1;
}
