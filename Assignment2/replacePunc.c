#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replacePunc ( char *line ){
    int i;
    int changed=0;
    char c;

    for (i=0;line[i]!='\0';i++){
        c=line[i];
        if ((c>=33 && c<=47) || (c>=58 && c<=64) || (c>=91 && c<=96) || (c>=123 && c<=127)){
            line[i]=' ';
            changed++;
          }
    }
    return changed;
}
