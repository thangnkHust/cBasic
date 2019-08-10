#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

typedef struct{
	char name[20];
	char tel[11];
	char mail[30];
}phoneName;

phoneName *phone;

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Sai cu phap\nDung la: %s <file.dat>\n", argv[0]);
		return 0;
	}

	char *fileName;
	FILE *fptr;
	int irc;

	fileName = (char*)malloc(strlen(argv[1])*sizeof(char));
	phone = (phoneName*)malloc(max*sizeof(phoneName));
	strcpy(fileName, argv[1]);
	if((fptr = fopen(fileName, "rb")) == NULL){
		printf("Can not open file %s\n", fileName);
	}

	irc = fread(phone, sizeof(phoneName), max, fptr);
	printf("file %s co %d phan tu\n", fileName, irc);

	for(int i =0; i< irc; i++){

		printf("%d.%s-", i+1,phone[i].name);
		printf("%s-%s\n", phone[i].tel, phone[i].mail);
	}

	fclose(fptr);
	free(phone);
	free(fileName);

}