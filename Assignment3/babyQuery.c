#include "babies.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 500
#define MAXLENGTH 20
#define ROWS 200

int main(int argc, char *argv[]){
  char fileRead1[MAXSIZE];
  char fileRead2[MAXSIZE];
  FILE *f1,*f2;
  char tmp[MAXSIZE];
  char line[MAXSIZE];
  int y1,y2,i,rank,gender;
  char action[MAXSIZE]="GetYears";
  char name[MAXSIZE];

  struct pNames n1;
  struct pNames n2;
  char maleSNumber[MAXLENGTH];
  char femaleSNumber[MAXLENGTH];

  while(1){ /*Primary while loop*/

    /*Getting and error checking initial inputs*/
    while(strcmp(action,"GetYears")==0){
      printf("Chose two decades to look at? [1880 to 2010]: ");
      scanf("%s %s",fileRead1, fileRead2);
      fgetc(stdin);

      strcat(fileRead1,"Names.txt");
      strcat(fileRead2,"Names.txt");

      y1=atoi(fileRead1);
      y2=atoi(fileRead2);

      if ((y1%10==0 && y1>=1880 && y1<=2010)&&(y2%10==0 && y2>=1880 && y2<=2010) && y1!=y2){
        if ((f1=fopen(fileRead1,"r"))==NULL || (f2=fopen(fileRead2,"r")) ==NULL){
          printf("Error - File name invalid. Try again. \n");
        }else{
          /*Loading files*/
          i=0;
          while(fgets(line, MAXSIZE, f1)!=NULL){
            sscanf (line, "%d %s %s %s %s", &n1.rank[i], n1.maleName[i], maleSNumber, n1.femaleName[i], femaleSNumber);
            removeCommas (maleSNumber);
            removeCommas (femaleSNumber);
            n1.maleNumber[i]=atoi(maleSNumber);
            n1.femaleNumber[i]=atoi(femaleSNumber);
            i++;
          }
          i=0;
          while(fgets(line, MAXSIZE, f2)!=NULL){
            sscanf (line, "%d %s %s %s %s", &n2.rank[i], n2.maleName[i], maleSNumber, n2.femaleName[i], femaleSNumber);
            removeCommas (maleSNumber);
            removeCommas (femaleSNumber);
            n2.maleNumber[i]=atoi(maleSNumber);
            n2.femaleNumber[i]=atoi(femaleSNumber);
            i++;
          }
          strcpy(action,"GetSearch");
          break;
        }
      }else{
        printf("Acceptable decades are 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, or 2010. No other numbers are acceptable. You must enter 2 acceptable decades separated by a least one space.\n");
      }
    }

    /*Deciding which stream to go down*/
    while (strcmp(action,"GetSearch")==0) {
      getStr(action,"What would you like to see? [rank, search, top]: ");
      if (strcmp(action,"rank")==0 || strcmp(action,"search")==0 || strcmp(action,"top")==0)
        break;
      printf("Please type in rank, search, or top exactly as requested.\n");
    }

    /*Rank*/
    if (strcmp(action,"rank")==0){
      rank=-1;
      while(1){
        getStr(tmp,"What rank do you wish to see [1-200]: ");
        rank=atoi(tmp);
        if (rank>0 && rank<201)
          break;
        printf("Only numbers between 1 and 200 are acceptable.\n");
      }

      gender=-1;
      while(1){
        getStr(tmp,"Do you wish to search male (0), female (1), or both (2) name? [0-2]: ");
        gender=atoi(tmp);
        if (gender>-1 && gender<3)
          break;
        printf("Only the numbers 0, 1, or 2 are acceptable.\n");
      }

      int r=rank-1;
      if (gender==0){
        printf("%d: Male: %s (%d)\n",y1,n1.maleName[r],n1.maleNumber[r]);
        printf("%d: Male: %s (%d)\n",y2,n2.maleName[r],n2.maleNumber[r]);
      }else if(gender==1){
        printf("%d: Female: %s (%d)\n",y1,n1.femaleName[r],n1.femaleNumber[r]);
        printf("%d: Female: %s (%d)\n",y2,n2.femaleName[r],n2.femaleNumber[r]);
      }else if(gender==2){
        printf("%d: Male: %s (%d) and Female: %s (%d)\n",y1,n1.maleName[r],n1.maleNumber[r],n1.femaleName[r],n1.femaleNumber[r]);
        printf("%d: Male: %s (%d) and Female: %s (%d)\n",y2,n2.maleName[r],n2.maleNumber[r],n2.femaleName[r],n2.femaleNumber[r]);
      }
    }

    /*Search*/
    if (strcmp(action,"search")==0){
      getStr(name,"What name do you want to search for? [case sensitive]: ");

      gender=-1;
      while (1){
        getStr(tmp,"Do you wish to search male (0), female (1), or both (2) name? [0-2]: ");
        gender=atoi(tmp);
        if (gender>-1 && gender<3)
          break;
        printf("Only the numbers 0, 1, or 2 are acceptable.\n");
      }

      searchResult(name,gender,y1,n1.maleName,n1.femaleName,n1.maleNumber,n1.femaleNumber);
      searchResult(name,gender,y2,n2.maleName,n2.femaleName,n2.maleNumber,n2.femaleNumber);
    }

    /*Top*/
    if (strcmp(action,"top")==0){
      printf("Top Male Names in Both %d and %d: ",y1,y2);
      showTop(n1.maleName,n2.maleName);
      printf("Top female Names in Both %d and %d: ",y1,y2);
      showTop(n1.femaleName,n2.femaleName);
    }

    strcpy(action,"None");
    while (strcmp(action,"None")==0){
      getStr(tmp,"Would you like to ask more about these years? ");
      if (strcmp(tmp,"y")==0 || strcmp(tmp,"Y")==0){
        strcpy(action,"GetSearch");
        break;
      }else if(strcmp(tmp,"n")==0 || strcmp(tmp,"N")==0){
          while (1){
            getStr(tmp,"Would you like to select new years? ");
            if (strcmp(tmp,"N")==0 || strcmp(tmp,"n")==0) {
              fclose(f1);
              fclose(f2);
              return 0;
            }else if (strcmp(tmp,"y")==0 || strcmp(tmp,"Y")==0){
              fclose(f1);
              fclose(f2);
              strcpy(action,"GetYears");
              break;
            }else{
                printf("Only the single characters Y or N are acceptable.\n");
            }
          }
        }else{
              printf("Only the single characters Y or N are acceptable.\n");
        }
      }
    }
}
