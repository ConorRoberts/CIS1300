/*  Defines */
#define MAXLENGTH 20
#define ROWS 200

/* Struct definitions */
struct pNames {
   int  year;
   int  rank[ROWS];
   char maleName[ROWS][MAXLENGTH];
   int  maleNumber[ROWS];
   char femaleName[ROWS][MAXLENGTH];
   int  femaleNumber[ROWS];
};

/* Function definitions */
int removeCommas ( char * );
void getStr(char in[], char prompt[]);
void showTop(char arr1[ROWS][MAXLENGTH], char arr2[ROWS][MAXLENGTH]);
void searchResult(char name[],int gender,int year,char maleArr[ROWS][MAXLENGTH],char femaleArr[ROWS][MAXLENGTH],int maleArrN[ROWS],int femaleArrN[ROWS]);
