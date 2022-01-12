#include <stdio.h>
#include <string.h>

#define MAXLENGTH 20
#define ROWS 200

void showTop(char arr1[ROWS][MAXLENGTH], char arr2[ROWS][MAXLENGTH]){
  int i,j;
  int printed=0;
    for (i=0;i<10;i++){
      for (j=0;j<10;j++){
        if (strcmp(arr1[i],arr2[j])==0){
          if(printed>0) printf(", ");
          printf("%s",arr1[i]);
          printed++;
        }
      }
    }
  if (printed==0) printf("None");
  printf("\n");
}
