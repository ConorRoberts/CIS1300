#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reduceSpace ( char *line ){
    int i=0;
    int j=0;
    int omitted=0;
    int k=0;
    char str[500];

    for (i=0;i<strlen(line);i++){
      k=i-1;
      if (i==0) k=0;
      if (line[i]==' ' && line[k]==' ' && i!=0){
        omitted++;
      }else{
        str[j]=line[i];
        j++;
      }
    }

    str[j]='\0';

    strcpy(line,str);
    return omitted;
}
