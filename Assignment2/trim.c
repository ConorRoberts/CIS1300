#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trim ( char *line ){
  int i;

  /*for (i=0;line[i]==' ';i++);*/

  if(line[strlen(line)-1]!=' ' && line[0]!=' ') return -1;

  while (line[0]==' '){
    for (i=0;i<strlen(line)-1;i++){
      line[i]=line[i+1];
    }
  }

  printf("%s\n",line);

  while (line[strlen(line)-2]==' '){
    line[strlen(line)-2]='\0';
  }

  /*start=i;

  for (i=start;line[i]!='\0';i++) if (line[i]==' ' && line[i]!='\0') end=i;

  if (start==0 && end==(strlen(line)-1)) return (-1);

  for (i=0;i<=(end-start);i++) line[i]=line[i+start];

  line[i]='\0';*/

  return (0);
}

/*int main(){
  char str[]="  hello stinky  ";
  trim(str);
  printf("-%s-\n",str);
}*/
