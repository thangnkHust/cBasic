#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

	FILE *fin;
	char eng[30], vn[30];
	char c;
	fin = fopen("../file/test1.txt", "r");
	char str[100];
	int count = 0;
	while(fgets(str, 100, fin) != NULL){
		count++;
	}
	// printf("%d", count);
	rewind(fin);
	for(int i =0; i <count; i++){
		fscanf(fin, "%s", eng);
		for(int i =0; i<strlen(eng); i++){
			eng[i] = tolower(eng[i]);
		}
		c = fgetc(fin);
		fgets(vn, 30, fin);
		for(int i =0; i<strlen(vn); i++){
			vn[i] = tolower(vn[i]);
		}
		printf("%s-%s", eng, vn);
	}

}