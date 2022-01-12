#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convertLowerCase ( char *line ){
    int i;
    int changed=0;
    char c;

    for (i=0;line[i]!='\0';i++){
        c=line[i];
        if (c>='A' && c<='Z'){
            line[i]=c+32;
            changed++;
        }
      }
    return changed;
}
