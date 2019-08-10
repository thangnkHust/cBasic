//Dung file bangDiem.txt 
//*Ghi thanh grade.dat
//*In bang diem tu grade.dat ra man hinh
//*Tim kiem 1 sinh vien theo ma so, sua diem, ghi lai vao file, readFile de kiem tra 
//Nen dung menu(1. Text to binary 2.display dat file 3.Search and update 4.end)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

typedef struct{
	int STT;
	char MSSV[max];
	char fullName[max];
	char phone[max];
	float mark;
}student;

int menu(void);
void textToDat(FILE *fin, FILE *fout);
void printFile(FILE *fin);
void searchStudent(FILE *fin);


int main(int argc, char *argv[]){

	int selec;
	FILE *fin, *fout;
	int check = 0;

	if(argc != 3){
		printf("Sai cu phap\nCu phap dung la: %s <file in> <file out>\n", argv[0]);
		return 0;
	}
	if((fin = fopen(argv[1], "r")) == NULL){
		printf("Can not open file %s\n", argv[1]);
		return 0;
	}
	if((fout = fopen(argv[2], "w+b")) == NULL){
		printf("Can not open file %s\n", argv[2]);
		return 0;
	}


	do{
		selec = menu();
		switch(selec){
			case 1:
				textToDat(fin, fout);
				check = 1;
				break;
			case 2:
				if(check == 0){
					puts("***Chua chay case 1\n***Run again");
					break;
				}
				printFile(fout);
				break;
			case 3:
				if(check == 0){
					puts("***Chua chay case 1\n***Run again");
					break;
				}
				searchStudent(fout);
				break;
			case 4:
				puts("Thoat chuong trinh");
				break;
			default:
				puts("Ban nhap sai cu phap");
				break;
		}

	}while(selec != 4);

	fclose(fin);
	fclose(fout);

}

int menu(){
	int selec;
	puts("============MENU============");
	printf("1.Text to binary\n2.Display dat file\n3.Search and update\n4.End\n");
	puts("============================");
	printf("Hay chon: ");
	scanf("%d", &selec);
	return selec;
}

void textToDat(FILE *fin, FILE *fout){

	int count = 0;
	student *SV;
	int irc;
	char str[max];
	SV = (student*)malloc(max*sizeof(student));
	puts("***Bat dau chuyen doi file");
	while(fgets(str, max, fin)!= NULL){	
		count++;
	}
	printf("%d\n", count);
	fseek(fin, 0*sizeof(student), SEEK_SET);
	for(int i = 0; i< count; i++){
		fscanf(fin, "%d%s%s%s%f", &SV[i].STT, SV[i].MSSV, SV[i].fullName, SV[i].phone, &SV[i].mark);
	}
	irc = fwrite(SV, sizeof(student), count, fout);
	puts("***Chuyen doi file thanh cong");
	printf("File grade.dat ghi thanh cong %d phan tu\n", irc);
	
	free(SV);

}

void printFile(FILE *fin){

	student *SV;
	int irc;
	SV = (student*)malloc(sizeof(student)*max);

	puts("Noi dung file la: ");
	fseek(fin, 0*sizeof(student), SEEK_SET);
	irc =fread(SV, sizeof(student), max, fin);
	for(int i =0; i< irc; i++){
		printf("%-5d%-10s%-20s%-20s%-5g\n", SV[i].STT, SV[i].MSSV, SV[i].fullName, SV[i].phone, SV[i].mark);
	}	

	free(SV);

}

void searchStudent(FILE *fin){

	char MSSV[max];
	student *SV;
	int mark = 0;
	int diem;
	int irc;
	printf("Nhap MSSV muon sua diem: ");
	getchar();
	gets(MSSV);

	SV = (student*)malloc(max*sizeof(student));

	fseek(fin, 0*sizeof(student), SEEK_SET);
	irc = fread(SV, sizeof(student), max, fin);
	for(int i =0; i< irc; i++){
		if(strcmp(SV[i].MSSV, MSSV) == 0){
			mark++;
			puts("SV tim duoc la: ");
			printf("%-5d%-10s%-20s%-20s%-5g\n", SV[i].STT, SV[i].MSSV, SV[i].fullName, SV[i].phone, SV[i].mark);
			printf("Nhap diem sua: ");
			scanf("%d", &diem);
			SV[i].mark = diem;
			puts("SV sau khi sua la: ");
			printf("%-5d%-10s%-20s%-20s%-5g\n", SV[i].STT, SV[i].MSSV, SV[i].fullName, SV[i].phone, SV[i].mark);
		}
	}

	if(mark == 0){
		printf("Khong co sinh vien voi MSSV la %s\n", MSSV);
	}else{
		fseek(fin, 0*sizeof(student), SEEK_SET);
		fwrite(SV, sizeof(student), irc, fin);
	}

	free(SV);

}





















