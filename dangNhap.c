#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dangNhap.h"
#define max 100

int menu(void);
int menu1(void);
int menu2(void);
void readFile(FILE *fin, treeType *T);
int checkUser(char user[]);
int checkPass(char pass[]);
void addStudent(treeType *T);

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Error argument\n %s <file in>\n", argv[0]);
		return 0;
	}

	int selec;
	FILE *fin;

	if((fin = fopen(argv[1], "r+")) == NULL){
		printf("Can't open file %s\n", argv[1]);
		return 0;
	}

	treeType T, tmp;
	initalize(&T);
	readFile(fin, &T);
	keyType k;
	int count = 0;
	int case1, case2;
	char str1[max], str2[max];

	do{
		selec = menu();
		switch(selec){
			case 1:
				getchar();
				printf("Nhap username: ");
				gets(k.user);
				printf("Nhap password: ");
				gets(k.pass);
				tmp = search(T, k);
				while(tmp == NULL){
					count++;
					printf("Sai!!!\n");
					if(count == 3){
						return 0;
					}
					printf("Nhap username: ");
					gets(k.user);
					printf("Nhap password: ");
					gets(k.pass);
					tmp = search(T, k);
				}
				while(strcmp(tmp->key.pass, k.pass) != 0){
					count++;
					printf("Sai!!!\n");
					if(count == 3){
						return 0;
					}
					printf("Nhap username: ");
					gets(k.user);
					printf("Nhap password: ");
					gets(k.pass);
					tmp = search(T, k);
				}
				count = 0;
				
				if(strcmp(tmp->key.user, "admin") == 0){
					do{
						case1 = menu2();
						switch(case1){
							case 1:
								getchar();
								addStudent(&T);
								break;
							case 2:
								inOderDisplay(T);
								break;
							case 3:
								getchar();
								printf("Nhap username: ");
								gets(k.user);
								tmp = search(T, k);
								if(tmp == NULL){
									puts("Khong tim thay username");
									break;
								}
								printf("%s\t%s\t%g\n", tmp->key.user, tmp->key.pass, tmp->key.grade);
								deleteNode(&T, tmp->key);
								break;
							case 4:
								fclose(fin);
								fin = fopen(argv[1], "w+");
								inOder(T, fin);
								break;
						}
					}while(case1 != 4);
				}else{
					do{
						case2 = menu1();
						switch(case2){
							case 1:
								printf("Diem: %g\n", tmp->key.grade);
								break;
							case 2:
								printf("Nhap mk cu: ");
								getchar();
								gets(str1);
								if(strcmp(str1, tmp->key.pass) != 0){
									printf("Nhap sai mk cu!\n");
									break;
								}
								printf("Nhap mk moi: ");
								gets(str1);
								printf("Nhap lai mk moi: ");
								gets(str2);
								while(strcmp(str1, str2) != 0 || checkPass(str1) == 0){
									puts("Xac nhan mk sai!");
									printf("Nhap mk moi: ");
									gets(str1);
									printf("Nhap lai mk moi: ");
									gets(str2);
								}
								deleteNode(&T, tmp->key);
								strcpy(tmp->key.pass, str1);
								insertNode(&T, tmp->key);
								break;
							case 3:
								rewind(fin);
								inOder(T, fin);
								fclose(fin);
								fin = fopen(argv[1], "r+");
								break;
						}
					}while(case2 != 3);
				}
				break;
			case 2:
				puts("Exit!!!");
				fclose(fin);
				break;
		}
	}while(selec != 2);

}

int menu(){
	int selec;
	puts("1.Dang nhap");
	puts("2.Thoat");
	printf("Enter selection: ");
	scanf("%d", &selec);
	puts("==================");
	return selec;
}

int menu1(){
	int selec;
	puts("1.Xem diem");
	puts("2.Thay doi mat khau");
	puts("3.Ghi thong tin ra file va thoat");
	printf("Press: ");
	scanf("%d", &selec);
	puts("=================================");
	return selec;
}

int menu2(){
	int selec;
	puts("1.Them sinh vien vao he thong");
	puts("2.In danh sach sinh vien");
	puts("3.Xoa sinh vien");
	puts("4.Ghi thong tin ra file va thoat");
	printf("Press: ");
	scanf("%d", &selec);
	puts("================================");
	return selec;
}

void readFile(FILE *fin, treeType *T){
	int count = 0;
	char str[max];
	keyType a[max];
	while(fgets(str, max, fin) != NULL){
		count++;
	}
	rewind(fin);
	for(int i =0; i <= count-1; i++){
		fscanf(fin, "%s%s%f", a[i].user, a[i].pass, &a[i].grade);
		insertNode(T, a[i]);
	}

}

int checkUser(char user[]){
	for(int i =0; i <strlen(user); i++){
		if(user[i] == ' ') return 0;
	}
	return 1;
}

int checkPass(char pass[]){
	for(int i =0; i <strlen(pass); i++){
		if(pass[i] == ' ') return 0;
	}
	if(strlen(pass) <= 6) return 0;
	return 1;
}

void addStudent(treeType *T){
	keyType k;
	printf("Nhap username: ");
	gets(k.user);
	printf("Nhap password: ");
	gets(k.pass);
	printf("Nhap grade: ");
	scanf("%f", &k.grade);
	insertNode(T, k);
}














