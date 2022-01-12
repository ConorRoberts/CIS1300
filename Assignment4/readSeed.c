#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int readSeed(char fName[100], int *rowLimit, int *colLimit, unsigned int rowSize, unsigned int colSize, int world[rowSize][colSize]){
  int col;
  int i=0;
  int row=0;
  char line[500];

  FILE *f;

  if ((f=fopen(fName,"r"))==NULL){
    return 0;
  }

  while (fgets(line,500,f)!=NULL && row<rowSize){
    *colLimit=strlen(line)/2;
    for (col=0;col<colSize*2;col++){
      if (line[col]=='0'){
        world[row][i]=0;
        i++;
      }else if (line[col]=='1'){
        world[row][i]=1;
        i++;
      }
    }
    i=0;
    row++;
  }
  *rowLimit=row;
  fclose(f);

  return 1;
}
