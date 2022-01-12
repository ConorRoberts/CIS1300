#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replaceDigits ( char *line ){
    int i;
    int changed=0;

    for (i=0;line[i]!='\0';i++){
        if (line[i]>='0' && line[i]<='9'){
            line[i]=' ';
            changed++;
        }
    }
    return changed;
}
