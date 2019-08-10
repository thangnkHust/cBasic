#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 80

void readWrite(FILE *fin, FILE *fout){

	int num;
	char buff[MAX_LEN + 1]; 
	while (!feof(fin)){
		num = fread(buff, sizeof(char),MAX_LEN, fin);
    // printf("%d\n", num);
		buff[num * sizeof(char)] = '\0';
		printf("%s", buff);
		fwrite(buff, sizeof(char), num, fout);
	}

}

int main(){

	FILE *file1, *file2;
	if((file1 = fopen("../../file/lab1.txt", "r")) == NULL){
		printf("Can not open source file\n");
	}else{
    if((file2 = fopen("../../file/lab1a.txt", "w")) == NULL)
      printf("Can not open file \n");
    else{
		readWrite(file1, file2);
		fclose(file1);
		fclose(file2);
    }
  }

}
