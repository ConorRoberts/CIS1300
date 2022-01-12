#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
If live item is surrounded by <2 other live items, it dies
If live item is surrounded by 2-3 live items, it remains
If live item is surrounded by >3 live items, it dies
If dead item is surrounded by 3 live items, it lives
*/

int updateCell(unsigned int cellRow, unsigned int cellCol, unsigned int rowSize, unsigned int colSize, int world[rowSize][colSize]){
  int n=0; /*Number of live items surrounding a cell*/
  int i,j;
  int colUpper=1,colLower=-1,rowUpper=1,rowLower=-1;

  if (cellRow==0){
    rowLower=0;
  }else if (cellRow==rowSize-1){
    rowUpper=0;
  }

  if (cellCol==0){
    colLower=0;
  }else if (cellCol==colSize-1){
    colUpper=0;
  }

  for(i=rowLower;i<=rowUpper;i++){
    for(j=colLower;j<=colUpper;j++){
      if ((i || j) && world[cellRow+i][cellCol+j]){
          n++;
      }
    }
  }

  if (n<2 || n>3 || (n==2 && world[cellRow][cellCol]==0)){
    return 0;
  }else if((n==2 && world[cellRow][cellCol]==1) || n==3){
    return 1;
  }else{
    return -1;
  }
}
