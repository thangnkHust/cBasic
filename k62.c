#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "k62.h"

int n;

typedef struct{
	int id;
	char name[255];
	int soluong;
	double gia;
}mon;

int menu(void);
void readFile(FILE *fin, mon thucdon[]);
void datmon(node **root, mon thucdon[]);
void printList(node *root, mon thucdon[]);
void uachuong(node *root, mon thucdon[]);

int main(int argc, char *argv[]){

	FILE *fin;
	int selec;
	// mon thucdon[];
	mon *thucdon = (mon*)malloc(sizeof(mon)*8);
	int case1 = 0;
	node *root = NULL;

	if(argc != 2){
		printf("Error argument, %s <file in>\n", argv[0]);
		return 0;
	}
	if((fin = fopen(argv[1], "r")) == NULL){
		printf("Can't open file %s\n", argv[1]);
		return 0;
	}

	do{

		selec = menu();
		switch(selec){
			case 1:
				if(case1 == 0){
					printf("%-5s%-20s%-15s%-10s\n", "ID", "ten mon", "so luong ton", "gia tien");
					readFile(fin, thucdon);
					case1 = 1;
				}else{
					printf("%-5s%-20s%-15s%-10s\n", "ID", "ten mon", "so luong ton", "gia tien");
					for(int i =0; i<n; i++){
						printf("%-5d%-20s%-15d%-10g\n", thucdon[i].id, thucdon[i].name, thucdon[i].soluong, thucdon[i].gia);
					}
				}
				break;
			case 2:
				datmon(&root, thucdon);
				break;
			case 3:
				printList(root, thucdon);
				break;
			case 4:
				uachuong(root, thucdon);
				break;
			case 5:
				fclose(fin);
				root = freeList(root);
				free(thucdon);
				puts("Thoat!!!");
				break;
			default:
				puts("error selection");
				break;
		}

	}while(selec != 5);


}

int menu(){
	int selec;
	puts("=============MENU==========");
	puts("1. Danh sach mon an hom nay");
	puts("2. Nhan order");
	puts("3. Thong tin tat ca order");
	puts("4. Mon an ua chuong nhat");
	puts("5. Thoat");
	printf("Nhap lua chon: ");
	scanf("%d", &selec);
	puts("============================");
	return selec;
}

void readFile(FILE *fin, mon thucdon[]){
	fscanf(fin, "%d", &n);
	// printf("Co %d mon an\n", n);
	for(int i =0; i< n; i++){
		fscanf(fin, "%d%s%d%lf", &thucdon[i].id, thucdon[i].name, &thucdon[i].soluong, &thucdon[i].gia);
		printf("%-5d%-20s%-15d%-10g\n", thucdon[i].id, thucdon[i].name, thucdon[i].soluong, thucdon[i].gia);
	}
}

void datmon(node **root, mon thucdon[]){
	static int k = 1;
	elementtype e;
	e.id = k;
	k++;
	int m = 0;
	printf("Moi quy khach chon so luong cac mon an: \n");
	for(int i =0; i<8; i++){
		e.order[i] = -1;
	}
	for(int i =0; i< n; i++){
		printf("\tNhap so luong mon an id %d: ", i+1);
		scanf("%d", &e.order[i]);
		// while(e.order[i] < 0){
		// 	printf("\tNhap sai so luong, nhap lai: ");
		// 	scanf("%d", &e.order[i]);
		// }
	}
	for(int i =0; i<n; i++){
		if(e.order[i] < 0){
			m = 1;
			printf("so luong khong hop le\n");
			break;
		}
		if(e.order[i] > thucdon[i].soluong){
			printf("Xin loi nha hang chung toi khong du dap ung nhu cau!\n");
			m = 1;
			break;
		}
	}
	if(m == 0){
		e.total = 0;
		for(int i =0; i<n; i++){
			e.total += e.order[i]*thucdon[i].gia; 
		}
		insertAtHead(root, e);
		printf("***Tong so tien order: %ld\n", e.total);
		for(int i = 0; i< n; i++){
			thucdon[i].soluong -= e.order[i];
		}
	}
}

void printList(node *root, mon thucdon[]){
	node *cur = root;
	int count = 1;
	float sum = 0;
	while(cur != NULL){
		printf("Don hang so %d\n", count);
		printf("\t%-30s%-20s%-10s\n", "mon da chon", "so luong", "thanh tien");
		for(int i =0; i<n; i++){
			if(cur->element.order[i] > 0){
				printf("\t%-30s%-20d%-10g\n", thucdon[i].name, cur->element.order[i], cur->element.order[i]*thucdon[i].gia);
				sum += cur->element.order[i]*thucdon[i].gia;
			}
		}
		printf("Tong hoa don thanh toan: %g\n", sum);
		cur = cur->next;
		count++;
		sum = 0;
	}
}

void uachuong(node *root, mon thucdon[]){
	node *cur = root;
	int dem[8];
	for(int i =0; i<8; i++){
		dem[i] = 0;
	}
	while(cur != NULL){
		for(int i =0; i<n; i++){
			dem[i] += cur->element.order[i];
		}
		cur = cur->next;
	}
	int max = dem[0];
	int mark = 0;
	for(int i =0; i<n; i++){
		if(max < dem[i]){
			max = dem[i];
			mark = i;
		}
	}
	printf("Cac mon ua thich nhat la: ");
	for(int i =0; i<8; i++){
		if(max == dem[i]){
			printf("%s, ", thucdon[i].name);
		}
	}
	printf("voi so luong la %d\n", max);
}









