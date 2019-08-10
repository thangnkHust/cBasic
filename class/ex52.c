#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

typedef struct{
	char name[20];
	char tel[11];
	char email[25];
}phoneName;

phoneName *phoneArr;

int main(){

	int irc;
	int begin, end;
	FILE *fptr;
	printf("nhap truong cat begin = ");
	scanf("%d", &begin);
	printf("nhap truong cat end = ");
	scanf("%d", &end);

	if((fptr = fopen("../../file/phone.dat", "r+b")) == NULL){
		printf("Can not open file\n");
		return 0;
	}

	printf("Doc tu %d den %d\n", begin, end);

	phoneArr = (phoneName*)malloc(sizeof(phoneName)*(end-begin+1));
	if(phoneArr == NULL){
		printf("cap phat bo nho dong fail\n");
		return 0;
	}

	if(fseek(fptr, (begin -1)*sizeof(phoneName), SEEK_SET) != 0){
		printf("fseek fail\n");
		return 0;
	}

	irc = fread(phoneArr,sizeof(phoneName), end-begin+1, fptr);

	for(int i = 0; i<(end-begin+1); i++){
		printf("%s-",phoneArr[i].name); 
		printf("%s-",phoneArr[i].tel); 
		printf("%s\n",phoneArr[i].email);
	}

	//thay doi du lieu
	strcpy(phoneArr[end-begin].name,"thang"); 
	strcpy(phoneArr[end-begin].tel,"0164469572"); 
	strcpy(phoneArr[end-1].email,"thannk.hust@gmail.com");
	fseek(fptr, (begin-1)*sizeof(phoneName), SEEK_SET);

	irc = fwrite(phoneArr,sizeof(phoneName), end-begin+1, fptr);
	for(int i = 0; i<(end-begin+1); i++){
		printf("%s-",phoneArr[i].name); 
		printf("%s-",phoneArr[i].tel); 
		printf("%s\n",phoneArr[i].email);
	}
	fclose(fptr);
	free(phoneArr);


}