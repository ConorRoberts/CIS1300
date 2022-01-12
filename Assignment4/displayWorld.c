#include <stdio.h>
#include <stdlib.h>

void displayWorld(unsigned int rowSize, unsigned int colSize, int world[rowSize][colSize], unsigned int tick){
  int row,col;
  char prnt;

  for (col=0;col<colSize;col++){
    printf("-");
  }printf("\n");

  for (row=0;row<rowSize;row++){
    printf("|");
    for (col=0;col<colSize;col++){
      if (world[row][col]==1){
        prnt='X';
      }else if(world[row][col]==0){
        prnt=' ';
      }
      printf("%c",prnt);
    }
    printf("|\n");
  }

  for (col=0;col<colSize;col++){
    printf("-");
  }printf("%d\n",tick);
}
