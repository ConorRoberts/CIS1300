#include <stdio.h>
#include <stdlib.h>
#include "isLeap.h"

int main(int argc, char *argv[]){
    if (argc!=3) {
      printf("Error - Wrong number of arguments\n");
      exit(0);
    }

    /*TODO; check if these are integers*/
    int startYear=atoi(argv[1]);
    int numLeaps=atoi(argv[2]);
    int i=0;

    while(i!=numLeaps){
        if (isLeap(startYear)){
            i++;
            printf("%d\n",startYear);
        }
        startYear++;
    }

    return 0;
}
