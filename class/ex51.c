#include <stdio.h>
#include <stdlib.h>
#define max 100
typedef struct{
	char name[20];
	char tel[11];
	char email[25];
}phoneAddress;

int main(){

	phoneAddress *phone;

	FILE *fptr;
	if((fptr = fopen("../../file/phone.dat", "w+b")) == NULL){
		printf("Can not open file");
		return 0;
	}
	int irc;
	int n;
	printf("Nhap so nguoi lien he: ");
	scanf("%d", &n);
	getchar();
	phone = (phoneAddress*)malloc(n*sizeof(phoneAddress));
	if(phone == NULL){
		printf("FAIL\n");
		return 0;
	}

	for(int i =0; i< n; i++){
		printf("nhap person %d: \n", i+1);
		printf("\tnhap name: ");
		gets(phone[i].name);
		printf("\tnhap tel: ");
		gets(phone[i].tel);
		printf("\tnhap email: ");
		gets(phone[i].email);
	}



	// for(int i =0; i< n; i++){
	// 	fprintf(fptr, "%20s%11s%25s", phone[i].name, phone[i].tel, phone[i].email);
	// 	fprintf(fptr, "\n");
		irc = fwrite(phone, sizeof(phoneAddress), n, fptr);
		printf("fwrite return code = %d\n", irc);
	// }
	fclose(fptr);

	if((fptr = fopen("../../file/phone.dat", "rb")) == NULL){
		printf("Can not open file");
		return 0;
	}
	irc = fread(phone, sizeof(phoneAddress), n, fptr);

	for(int i =0; i< n; i++){
		printf("%20s", phone[i].name);

		printf("%20s", phone[i].tel);

		printf("%25s",phone[i].email);
		printf("\n");
	}

	free(phone);




}