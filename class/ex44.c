#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

char *my_strcat(char str1[], char str2[]){
 
  char *p;
  p = (char*)malloc((strlen(str1) + strlen(str2) + 1)*sizeof(char));
  if(p == NULL){
    printf("Cap phat bo nho dong fail\n");
  }
  strcpy(p, str1);
  strcpy(p + strlen(str1), str2);
  return p;
}

int main(){

  char str1[max];
  char str2[max];
  char *cat_str;

  printf("nhap 2 string: \n");
  scanf("%s", str1);
  scanf("%s", str2);
  cat_str = my_strcat(str1, str2);
  if(cat_str == NULL){
    printf("xay ra loi cap phat bo nho\n");
    return 1;
  }
  printf("str1 = %s, str2 = %s, cat_str = %s\n", str1, str2, cat_str);

  free(cat_str);

}
