#include<stdio.h>
#include<ctype.h>

void readWrite(FILE *fin, FILE *fout){
  int c;
  while((c = fgetc(fin)) != EOF){
    if(islower(c)){
      c = toupper(c);
    }else{
      if(isupper(c)){
        c = tolower(c);
      }
    }
    
    fputc(c, fout);
    putchar(c);
  }
}


int main(){

  FILE *fptr1, *fptr2;

  if((fptr1 = fopen("../../file/lab1.txt", "r")) == NULL){
    printf("can not open file 1");
  }else{
    if((fptr2 = fopen("../../file/lab31.txt", "w")) == NULL){
      printf("can not open file 2");
    }else{
      readWrite(fptr1, fptr2);
      fclose(fptr1);
      fclose(fptr2);
    }
  }

}
