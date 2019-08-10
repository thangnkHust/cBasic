#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100


void codeTG(FILE *fin, FILE *fout, int n){

  char str[max];
  while(fgets(str, max, fin) != NULL){
    for(int i = 0; i < strlen(str); i++){
      if (((str[i]+n) > 'z' && str[i] >= 'a' && str[i] <= 'z' ) || ((str[i] + n) > 'Z' && str[i] >= 'A' && str[i] <= 'Z'))
        {
          str[i] = str[i] + n-26*( n/26+1 );
        }else{
          if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
          {
            str[i] += n;
          }
      }
    }
    fputs(str, fout); 
  }

}

void code(FILE *fin, FILE *fout, int n){

  char strCpy[max];
  while(fgets(strCpy, max, fin) != NULL){ 
    fputs(strCpy, fout);
  }

}

void deCodeTG(FILE *fin, FILE *fout, int n){

  char strDeCodeTG[max];
  while(fgets(strDeCodeTG, max, fin) != NULL){
    for(int i =0; i< strlen(strDeCodeTG); i++){
      if( ((strDeCodeTG[i]-n) < 'a' &&  strDeCodeTG[i] >= 'a' && strDeCodeTG[i] <= 'z' ) || ((strDeCodeTG[i]-n) <'A' && strDeCodeTG[i] >= 'A' && strDeCodeTG[i] <= 'Z') ){
        strDeCodeTG[i] = strDeCodeTG[i] -n +26 *( n/26 + 1 );
      }else{
         if ((strDeCodeTG[i] >= 'a' && strDeCodeTG[i] <= 'z') || (strDeCodeTG[i] >= 'A' && strDeCodeTG[i] <= 'Z'))
          {
            strDeCodeTG[i] -= n;
          }
      }
    }
    fputs(strDeCodeTG, fout);
  }


}




int main(){

  int n;
  printf("nhap tham so ma hoa: ");
  scanf("%d", &n);
  FILE *fptr1, *fptr2;

  // ma hoa file nguon 
  fptr1 = fopen("../../file/lab1.txt", "r"); //mo file nguon va file trung gian
  fptr2 = fopen("../../file/lab31H.txt", "w");

  if(fptr1 == NULL){
    printf("can not open file ../../file/lab1.tx ");
    exit(1);
  }

  if(fptr2 == NULL){
    printf("Can not open file ../../file/lab31H.tx ");
    exit(1);
  }


  codeTG(fptr1, fptr2, n); //ma hoa file nguon vao file trung gian

  fclose(fptr1);
  fclose(fptr2);

  fptr1 = fopen("../../file/lab1.txt", "w");
  fptr2 = fopen("../../file/lab31H.txt", "r");

  code(fptr2, fptr1, n); //ma hoa file nguon tu file trung gian 
  printf("ma hoa file nguon hoan thanh\n");

  fclose(fptr1);
  fclose(fptr2);

  // giai ma file nguon
  int mark;
  printf("ban co muon giai ma file nguon khong?\n yes: 1 ? no: 0?\n hay lua chon: ");
  scanf("%d", &mark);
  if(mark ==0){
    exit(1);
  }else{
    fptr1 = fopen("../../file/lab1.txt", "r"); //mo file nguon va file trung gian
    fptr2 = fopen("../../file/lab31W.txt", "w");

    deCodeTG(fptr1, fptr2, n);

    fclose(fptr1);
    fclose(fptr2);

    fptr1 = fopen("../../file/lab1.txt", "w"); //mo file nguon va file trung gian
    fptr2 = fopen("../../file/lab31W.txt", "r");

    code(fptr2, fptr1, n);
    printf("giai ma file nguon hoan thanh\n");

    fclose(fptr1);
    fclose(fptr2);
  }

}
