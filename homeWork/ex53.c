 // thong tin dien thoai: model memory screen price
// menu: 1.Import dDB from text: Dung malloc phoneDB.txt -> phoneDB.dat
// 		2.Import from DB: Doc tu file .dat (doc toan phan va 1 phan ho tro doc tu dau va cuoi) 
// 		3.Print All DB: In ra man hinh tu phoneDB.dat, phan trang
// 		4.Search phone: Theo model

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

typedef struct{
	char model[15];
	char memory[10];
	char screen[10];
	char price[20];
}phone;


int menu(void);
void textToBinary(FILE *fin, FILE *fout);
void readAll(FILE *fin, FILE *fout);
void readPart(FILE *fin, FILE *fout);
void printAll(FILE *fin);
void searchModel(FILE *fin);

char fileName1[max] , fileName2[max];

void getMobilephone(FILE *fout, int n);

int main(){

	FILE *fptr;
	FILE *fptrOut;
	FILE *fout;
	int n;
	int find;
	int check = 0;
	printf("Nhap ten file text: ");
	gets(fileName1);
	printf("Nhap ten file binary can chuyen doi: ");
	gets(fileName2);
	
	if((fptr = fopen(fileName1, "r+")) == NULL){
		printf("Can not open file\n");
		return 0;
	}
	if((fptrOut = fopen(fileName2, "w+b")) == NULL){
		puts("Can not open file");
		return 0;
	}
	if((fout = fopen("../../file/phoneOut.dat", "wb")) == NULL){
		printf("Can not open file ../../file/phoneOut.dat");
		return 0;
	}
	// int irc;
	// phone phoneSorce[max];	//luu du lieu khi doc file .dat


	do{
		n = menu();
		switch(n){
			case 1:
				textToBinary(fptr, fptrOut);
				check = 1;
				break;
			case 2:
				if(check == 0){
					puts("***Don't run case 1***");
					puts("***Run programing again***");
					break;
				}
				// fseek(fptrOut, 0*sizeof(phone), SEEK_SET);	//di chuyen con tro len dau file
				// irc = fread(phoneSorce, sizeof(phone), max, fptrOut);	//doc va dem so phan tu cua file .dat
				printf("Doc toan phan chon 1? Doc mot phan chon 2? \nChon: ");
				scanf("%d", &find);
				if(!(find == 1 || find == 2)){
					printf("Ban nhap sai lua chon, nhap lai: ");
					scanf("%d", &find);
				}
				if(find == 1){
					readAll(fptrOut, fout);
				}else{
					readPart(fptrOut, fout);
				}
				break;
			case 3:
				if(check == 0){
					puts("***Don't run case 1***");
					puts("***Run programing again***");
					break;
				}
				printAll(fptrOut);
				break;
			case 4:
				if(check == 0){
					puts("***Don't run case 1***");
					puts("***Run programing again***");
					break;
				}
				searchModel(fptrOut);
				break;
			case 5:
				getMobilephone(fptr, 2);
				puts("Thoat chuong trinh");
				break;
		}


	}while(n != 6);

	fclose(fptr);
	fclose(fptrOut);
	// int n;
	// printf("Nhap so luong mobile: ");
	// scanf("%d", &n);
	// getchar();
	// getMobilephone(fptr, n);

}

int menu(){
	int n;
	puts("=============MENU=============");
	printf("1.Import DB from text\n2.Import from DB\n3.Print all DB\n4.Tim kiem dien thoai\n5.Exit\n");
	puts("==============================");
	printf("Nhap lua chon: ");
	scanf("%d", &n);
	return n;
}

void textToBinary(FILE *fin, FILE *fout){
	phone *phoneDB;
	phoneDB = (phone*)malloc(max*sizeof(phone));
	fseek(fin, 0*sizeof(phone), SEEK_SET);
	int irc1, irc2;

	puts("***Bat dau chuyen doi file");
	irc1 = fread(phoneDB, sizeof(phone), max, fin);
	printf("file %s co %d phan tu\n", fileName1, irc1);
	irc2 = fwrite(phoneDB, sizeof(phone), irc1, fout);
	printf("file %s ghi thanh cong %d phan tu\n", fileName2, irc2);
	puts("***Chuyen doi thanh cong");

	free(phoneDB);
}

void readAll(FILE *fin, FILE *fout){
	
	// int selec;
	int irc;
	phone *phoneAll;	//struct luu tru de in ra tat ca file .dat
	phoneAll = (phone*)malloc(max*sizeof(phone));

	fseek(fin, 0*sizeof(phone), SEEK_SET);	//dua con tro len dau file .dat
	irc = fread(phoneAll, sizeof(phone), max, fin);
	fwrite(phoneAll, sizeof(phone), irc, fout);
	// printf("***Doc tu dau chon 1? Tu cuoi chon 2?\n***Chon: ");
	// scanf("%d", &selec);
	// if(!(selec == 1 || selec == 2)){
		// printf("Ban nhap sai nhap lai: ");
		// scanf("%d", &selec);
	// }
	// if(selec == 1){
	for(int i =0; i< irc; i++){
		printf("%d.%-15s", i+1,phoneAll[i].model);
		printf("%-10s", phoneAll[i].memory);
		printf("%-10s", phoneAll[i].screen);
		printf("%-20s\n", phoneAll[i].price);
	}
	// }else{
	// 	for(int i =irc-1; i>= 0; i--){
	// 		printf("%d.%-15s", i+1,phoneAll[i].model);
	// 		printf("%-10s", phoneAll[i].memory);
	// 		printf("%-10s", phoneAll[i].screen);
	// 		printf("%-20s\n", phoneAll[i].price);
	// 	}
	// }

	free(phoneAll);
}

void readPart(FILE *fin, FILE *fout){

	int selec;
	int irc;
	int count;
	phone *phonePart;
	printf("***Doc tu dau chon 1? Tu cuoi chon 2?\n***Chon: ");
	scanf("%d", &selec);
	if(!(selec == 1 || selec == 2)){
		printf("Ban nhap sai nhap lai: ");
		scanf("%d", &selec);
	}
	if(selec == 1){
		fseek(fin, 0*sizeof(phone), SEEK_SET);
		printf("Nhap so luong phan tu: ");
		scanf("%d", &count);
		phonePart = (phone*)malloc(count*sizeof(phone));
		irc = fread(phonePart, sizeof(phone), count, fin);
		fwrite(phonePart, sizeof(phone), count, fout);
		for(int i =0; i< irc; i++){
			printf("%d.%-15s", i+1,phonePart[i].model);
			printf("%-10s", phonePart[i].memory);
			printf("%-10s", phonePart[i].screen);
			printf("%-20s\n", phonePart[i].price);
		}
	}else{
		printf("Nhap so luong phan tu: ");
		scanf("%d", &count);
		fseek(fin, (-count)*sizeof(phone), SEEK_END);
		phonePart = (phone*)malloc(count*sizeof(phone));
		irc = fread(phonePart, sizeof(phone), count, fin);
		fwrite(phonePart, sizeof(phone), count, fout);
		for(int i =0; i< irc; i++){
			printf("%d.%-15s", i+1,phonePart[i].model);
			printf("%-10s", phonePart[i].memory);
			printf("%-10s", phonePart[i].screen);
			printf("%-20s\n", phonePart[i].price);
		}
	}
	free(phonePart);	

}

void printAll(FILE *fin){

	int irc;
	phone *printAll;
	printAll = (phone*)malloc(max*sizeof(phone));

	fseek(fin, 0*sizeof(phone), SEEK_SET);	//dua con tro len dau file .dat
	irc = fread(printAll, sizeof(phone), max, fin);

	int i = 0;
	char c;
	getchar();
	while(i < irc){
		printf("%d.%-15s", i+1,printAll[i].model);
		printf("%-10s", printAll[i].memory);
		printf("%-10s", printAll[i].screen);
		printf("%-20s\n", printAll[i].price);
		i++;
		if(i%4 == 0) scanf("%c", &c);
	}

	free(printAll);

}

void searchModel(FILE *fin){

	int irc;
	phone *search;
	search = (phone*)malloc(max*sizeof(phone));

	fseek(fin, 0*sizeof(phone), SEEK_SET);	//dua con tro len dau file .dat
	irc = fread(search, sizeof(phone), max, fin);
	char model[max];
	getchar();
	printf("Nhap model can tim: ");
	gets(model);
	int dem = 0;
	for(int i =0; i < irc; i++){
		if(strcasestr(search[i].model, model) != NULL){
			printf("%d.%-15s", i+1,search[i].model);
			printf("%-10s", search[i].memory);
			printf("%-10s", search[i].screen);
			printf("%-20s\n", search[i].price);	
			dem++;
		}
	}
	if(dem == 0){
		printf("Khong co model search\n");
	}

	free(search);
}

void getMobilephone(FILE *fout, int n){

	int irc;
	phone *phoneDB;
	phoneDB = (phone*)malloc(sizeof(phone)*n);
	getchar();
	for(int i =0; i< n; i++){
		printf("Nhap mobile %d: \n", i+1);
		printf("\tModel: ");
		gets(phoneDB[i].model);
		printf("\tMemory: ");
		gets(phoneDB[i].memory);
		printf("\tScreen: ");
		gets(phoneDB[i].screen);
		printf("\tPrice: ");
		gets(phoneDB[i].price);
	}

	irc = fwrite(phoneDB, sizeof(phone), n, fout);
	printf("Ghi duoc %d struct\n", irc);

	free(phoneDB);

}


























