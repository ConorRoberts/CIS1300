#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 500
#define MAXWORDS 1000

int main(int argc, char *argv[]){
  char line[MAXSIZE];
  char arrWords[MAXWORDS][MAXSIZE];
  int i=0;
  int j=0;
  int found;
  int len;

  while (fgets(line, MAXSIZE, stdin)!= NULL){
    strcpy(arrWords[i],line);
    arrWords[i][strlen(arrWords[i])]='\0';
    i++;
  }
  len=i;
  for (i=0;i<len;i++){
    found=0;
    for (j=0;j<len;j++){
      if (strcmp(arrWords[i],arrWords[j])==0) found++;
    }
    if (strcmp(arrWords[i+1],arrWords[i])!=0) printf("%.03d %s",found,arrWords[i]);
  }

  return 0;
}
