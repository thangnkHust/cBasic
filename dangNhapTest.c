#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dangNhap.h"

int menu(void);
int menu1(void);
int menu2(void);
void readFile(FILE *fin, treeType *T);
void addStudent(treeType *T);

int main(int argc, char *argv[]){

	int selec, selec1, selec2;
	FILE *fin;

	if(argc != 2){
		printf("Sai argument, %s <fin>", argv[0]);
		return 0;
	}

	if((fin = fopen(argv[1], "r")) == NULL){
		printf("Can't open file %s\n", argv[1]);
		return 0;
	}

	treeType T, tmp;
	initalize(&T);
	readFile(fin, &T);
	keyType k;
	int count = 0;
	char str1[30], str2[30];

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
				while(tmp == NULL || strcmp(tmp->key.pass, k.pass) != 0){
					count++;
					printf("Sai!!!\n");
					if(count == 3) return 0;
					printf("Nhap username: ");
					gets(k.user);
					printf("Nhap password: ");
					gets(k.pass);
					tmp = search(T, k);
				}
				count = 0;
				if(strcmp(tmp->key.user, "admin") == 0){
					do{
						selec2 = menu2();
						switch(selec2){
							case 1:
								getchar();
								addStudent(&T);
								break;
							case 2:
								printf("%-10s%-10s%-5s\n", "username", "password", "grade");
								inOderDisplay(T);
								break;
							case 3:
								getchar();
								printf("Nhap username: ");
								gets(k.user);
								if(strcmp(k.user, "admin") == 0){
									printf("Khong the xoa admin\n");
									break;
								}
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
								puts("Thoat menu2!");
								break;
							default:
								printf("Sai selec\n");
								break;
						}
					}while(selec2 != 4);
				}else{
					do{
						selec1 = menu1();
						switch(selec1){
							case 1:
								printf("Diem: %g\n", tmp->key.grade);
								break;
							case 2:
								printf("Nhap mk cu: ");
								getchar();
								gets(str1);
								if(strcmp(str1, tmp->key.pass) != 0){
									printf("Nhap sai mk cu\n");
									break;
								}
								printf("Nhap mk moi: ");
								gets(str1);
								printf("Nhap lai mk moi: ");
								gets(str2);
								while(strcmp(str1, str2) != 0){
									printf("Nhap sai, nhap lai\n");
									printf("Nhap mk moi: ");
									gets(str1);
									printf("Nhap lai mk moi: ");
									gets(str2);
								}
								deleteNode(&T, tmp->key);
								strcpy(tmp->key.pass, str1);
								insertNode(&T, tmp->key);
								// inOderDisplay(T);
								break;
							case 3:
								rewind(fin);
								inOder(T, fin);
								printf("Thoat menu1\n");
								break;
							default:
								printf("Error selec\n");
							 	break;
						}
					}while(selec1 != 3);
				}

				break;
			case 2:
				fclose(fin);
				puts("Thoat!!!");
				break;
			default:
				printf("Error selec\n");
				break;
		}

	}while(selec != 2);

}

int menu(){
	int selec;
	puts("1. Dang nhap");
	puts("2. Thoat");
	printf("Nhap: ");
	scanf("%d", &selec);
	return selec;
}

int menu1(){
	int selec1;
	puts("1. Xem diem sinh vien do");
	puts("2. Thay doi mat khau");
	puts("3. Thoat menu1");
	printf("Press: ");
	scanf("%d", &selec1);
	return selec1;
}

int menu2(){
	int selec2;
	puts("1. Them mot sinh vien vao he thong");
	puts("2. In ra danh sach sinh vien");
	puts("3. Xoa sinh vien");
	puts("4. Thoat menu2");
	printf("Press: ");
	scanf("%d", &selec2);
	return selec2;
}

void readFile(FILE *fin, treeType *T){
	keyType a;
	int count = 0;
	char str[100];
	while(fgets(str, 100, fin) != NULL){
		count++;
	}
	rewind(fin);
	for(int i =0; i < count; i++){
		fscanf(fin, "%s%s%f", a.user, a.pass, &a.grade);
		insertNode(T, a);
		// printf("%-10s%-10s%-5g\n", a.user, a.pass, a.grade);
	}
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













