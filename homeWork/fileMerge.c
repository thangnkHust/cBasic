#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

typedef struct{
	char name[20];
	char tel[11];
}phoneName;

void fileMerge(FILE *fin1, FILE *fin2, FILE *fout){

	int irc1, irc2;
	phoneName phone1[max], phone2[max];
	irc1 = fread(phone1, sizeof(phoneName), max, fin1);
	irc2 = fread(phone2, sizeof(phoneName), max, fin2);
	fwrite(phone1, sizeof(phoneName), irc1, fout);
	fwrite(phone2, sizeof(phoneName), irc2, fout);

}

int main(int argc, char *argv[]){

	if(argc != 4){
		printf("Sai cu phap\nCu phap dung la: %s <fin1> <fin2> <fout> \n", argv[0]);
		return 0;
	}
	FILE *f1, *f2;
	FILE *fout;
	char *fileName1, *fileName2;
	char *fileNameOut;

	fileName1 = (char*)malloc(strlen(argv[1])*sizeof(char));
	fileName2 = (char*)malloc(strlen(argv[2])*sizeof(char));
	fileNameOut = (char*)malloc(strlen(argv[3])*sizeof(char));
	strcpy(fileName1, argv[1]);
	strcpy(fileName2, argv[2]);
	strcpy(fileNameOut, argv[3]);

	if((f1 = fopen(fileName1, "rb")) == NULL){
		printf("Can not open file %s\n", fileName1);
		return 0;
	}
	if((f2 = fopen(fileName2, "rb")) == NULL){
		printf("Can not opne file %s\n", fileName2);
		return 0;
	}
	if((fout = fopen(fileNameOut, "wb")) == NULL){
		printf("Can not open file %s\n", fileNameOut);
		return 0;
	}

	fileMerge(f1, f2, fout);

	fclose(f1);
	fclose(f2);
	fclose(fout);
	free(fileName1);
	free(fileName2);
	free(fileNameOut);

}























