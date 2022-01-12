#include <stdio.h>
#include <string.h>

#define MAXSIZE 500

void getStr(char in[], char prompt[]){
  printf("%s",prompt);
  fgets(in,MAXSIZE,stdin);
  if ((strlen(in) > 0) && (in[strlen (in) - 1] == '\n'))
        in[strlen (in) - 1] = '\0';
}
