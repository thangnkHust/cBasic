#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct{
	int STT;
	char MSSV[max];
	char fullName[max];
	char phone[max];
	float mark; 
}student;

student *SV;

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Nhap sai cu phap\nCu phap dung: %s <file>\n", argv[0]);
		return 0;
	}
	FILE *fin;
	int irc;
	if((fin = fopen(argv[1], "rb")) == NULL){
		printf("Can not open file %s\n", argv[1]);
		return 0;
	}
	SV = (student*)malloc(sizeof(student)*max);

	irc = fread(SV, sizeof(student), max, fin);
	for(int i = 0; i< irc; i++){
		printf("%-5d%-10s%-20s%-20s%-5g\n", SV[i].STT, SV[i].MSSV, SV[i].fullName, SV[i].phone, SV[i].mark);
	}

	free(SV);
	fclose(fin);
}