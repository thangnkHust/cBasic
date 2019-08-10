#include <stdio.h>
#include <string.h>
#define max 100


void readWrite(FILE *fin, FILE *fout){

  char str[max];
  int count = 0;
  while(fgets(str, max, fin) != NULL){
    fprintf(fout, "%lu %s", strlen(str), str);
    printf("%lu %s", strlen(str), str);
    count++;
  }
  fprintf(fout, "\nSo dong trong file la: %d", count);

}


int main(int argc, char *argv[]){

  FILE *fptr1, *fptr2;
  char str1[max];
  char str2[max];

  strcpy(str1, argv[1]);
  strcpy(str2, argv[2]);

  if((fptr1 = fopen(str1, "r")) == NULL){
    printf("can not open file %s", str1);
  }else{
    if((fptr2 = fopen(str2, "w")) == NULL){
      printf("can not open file %s", str2);
    }else{
      readWrite(fptr1, fptr2);
      fclose(fptr1);
      fclose(fptr2);
    }
  }


}
