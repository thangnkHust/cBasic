#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

typedef struct{
	char model[15];
	char memory[10];
	char screen[10];
	char price[20];
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
		printf("%d.%-15s", i+1,phone[i].model);
		printf("%-10s", phone[i].memory);
		printf("%-10s", phone[i].screen);
		printf("%-20s\n", phone[i].price);
	}

	fclose(fptr);
	free(phone);
	free(fileName);

}