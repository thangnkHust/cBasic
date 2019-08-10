#include<stdio.h>

void doubleSpace(FILE *fin, FILE *fout){
  int c;
  while((c = fgetc(fin)) != EOF){
    //if (fin)
    //{
    //  char buf[BUFSZ];
    //  while (fgets(buf, BUFSZ, fin))
    //    {
    //      printf("%s", buf);
    //      if (strrchr(buf, '\n')) printf("\n");
    //    }
    //}
    fputc(c , fout);
    putchar(c);
    if(c == '\n'){
      fputc('\n', fout);
      putchar(c);
    }
  }

    fputc(c, fout);
    putchar(c);
  }

int main(){

  FILE *fptr1, *fptr2;

  if((fptr1 = fopen("../../file/lab1.txt", "r")) == NULL){
    printf("can not open file 1");
  }else{
    if((fptr2 = fopen("../../file/lab32.txt", "w")) == NULL){
      printf("can not open file 2");
    }else{
      doubleSpace(fptr1, fptr2);
      fclose(fptr1);
      fclose(fptr2);
    }
  }

}
