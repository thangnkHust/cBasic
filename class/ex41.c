#include <stdio.h>
#define max 100000

void lineMerge(FILE *f1, FILE *f2, FILE *f3){

  char str1[max], str2[max];
  int count;
  while((fgets(str1, max, f1) != NULL) && (fgets(str2, max, f2)!= NULL)){
    fputs(str1, f3);
    fputs(str2, f3);
  }
  if(str1 != NULL){
    fputs(str1, f3);
  }

  while( fgets(str1, max, f1) != NULL){
    fputs(str1, f3);
  }

  while(fgets(str2, max, f2) != NULL){
    fputs(str2, f3);
  }

}

int main(int argc, char *argv[]){

  FILE *file1, *file2, *file3;
 
  int count1 = 0;

  if(argc != 4){
    printf("ban nhap sai arguments\n");
    printf("cu phap dung la: ./ex41 \"file1\" \"file2\" \"file3\"");
  }else{
    if((file1 = fopen(argv[1], "r")) == NULL){
      printf("Can not open file %s \n", argv[1] );
    }else{
      if((file2 =fopen(argv[2], "r")) == NULL){
        printf("Can not opne file %s", argv[2]);
      }else{
        if((file3 = fopen(argv[3], "w")) == NULL){
          printf("Can not open file %s", argv[3]);
        }else{
          lineMerge(file1, file2, file3);
        }
      }
    }
  }

}
