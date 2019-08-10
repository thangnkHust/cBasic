#include <stdio.h>
#include <string.h>
#define MAX_LEN  80

void mycat(FILE *fin){
	int num;
	int count = 0;
	char n;
	char buff[MAX_LEN + 1]; 
	while (!feof(fin)){
		count++;
		num = fread(buff, sizeof(char),MAX_LEN, fin);
    // printf("%d\n", num);
		buff[num * sizeof(char)] = '\0';
		printf("%s\n", buff);
		if(count %24 == 0){
			scanf("%c", &n);
		}
		// fwrite(buff, sizeof(char), num, fout);
	}
	
}

int main(){

	FILE *file;

	if((file = fopen("../../file/lab1.txt", "r")) == NULL){
		printf("Can not open source file\n");
	}else{
		mycat(file);
	}
}