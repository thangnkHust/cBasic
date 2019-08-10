#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "k60.h"

int menu(void);
void readFile(FILE *fin, queueType *Q);
int checkName(char name[]);
void addNew(queueType *Q);
void thongKe(FILE *fout, elementtype e[]);
void uuTien(queueType *Q);

int main(int argc, char *argv[]){

	if(argc != 3){
		printf("Sai argument, %s <fin> <fout>\n", argv[0]);
		return 0;
	}

	int selec;
	FILE *fin, *fout;
	queueType Q;
	initalize(&Q);
	elementtype tmp;
	elementtype e[100];

	if((fin = fopen(argv[1], "r")) == NULL){
		printf("Can't open file %s\n", argv[1]);
		return 0;
	}
	if((fout = fopen(argv[2], "w")) == NULL){
		printf("Can't open file %s\n", argv[2]);
		return 0;
	}

	do{

		selec = menu();
		switch(selec){
			case 1:
				printf("%-30s%-15s\n", "Name", "Phone");
				readFile(fin, &Q);
				break;
			case 2:
				getchar();
				addNew(&Q);
				break;
			case 3:
				tmp = deQueue(&Q);
				do{
					printf("%-30s%-15s\n", "Name", "Phone");
					printf("%-30s%-15s\n", tmp.name, tmp.phone);
					printf("Nhap so luong A: ");
					scanf("%d", &tmp.sp1);
					printf("Nhap so luong B: ");
					scanf("%d", &tmp.sp2);
					printf("Nhap so luong C: ");
					scanf("%d", &tmp.sp3);
				}while(tmp.sp1 == 0 || tmp.sp2 == 0 || tmp.sp3 == 0);
				fprintf(fout, "%d\t%d\t%d\n", tmp.sp1, tmp.sp2, tmp.sp3);
				break;
			case 4:
				fprintf(fout, "%d\n", -1);
				fclose(fin);
				fin = fopen(argv[1], "w");
				while(!empty(&Q)){
					tmp = deQueue(&Q);
					fprintf(fin, "%s\t%s\n", tmp.name, tmp.phone);
				}
				fclose(fin);
				fin = fopen(argv[1], "r");
				break;
			case 5:
				fclose(fout);
				fout = fopen(argv[2], "r+");
				thongKe(fout, e);
				break;
			case 6:
				getchar();
				uuTien(&Q);
				break;
			case 7:
				break;
			default:
				printf("Nhap sai cu phap, nhap lai!\n");
				break;
		}

	}while(selec != 7);




}

int menu(){
	int selec;
	puts("=============MENU==========");
	puts("1. Doc file danhSach.txt");
	puts("2. Them nguoi mua vao hang doi");
	puts("3. Ban hang");
	puts("4. Ghi thong tin sau mot ngay");
	puts("5. Thong ke thong tin ban hang");
	puts("6. Yeu cau dac biet");
	puts("7. Exit!!!");
	printf("Enter selection: ");
	scanf("%d", &selec);
	return selec;
}

void readFile(FILE *fin, queueType *Q){
	elementtype e;
	rewind(fin);
	int count = 0;
	char str[100];
	while(fgets(str, 100, fin) != NULL){
		count++;
	}
	rewind(fin);
	for(int i = 0; i < count; i++){
		fscanf(fin, "%s%s", e.name, e.phone);
		enQueue(Q, e);
		printf("%-30s%-15s\n", e.name, e.phone);
	}
}

int checkName(char name[]){
	for(int i = 0; i<strlen(name); i++){
		if(name[i] == ' ') return 0;
	}
	return 1;
}

void addNew(queueType *Q){
	elementtype e;
	printf("Nhap thong tin: \n");
	printf("\tNhap ten: ");
	gets(e.name);
	while(checkName(e.name) == 0){
		printf("\tName error, ");
		printf("Nhap lai name: ");
		gets(e.name);
	}
	printf("\tNhap sdt: ");
	gets(e.phone);
	enQueue(Q, e);
}

void thongKe(FILE *fout, elementtype e[]){
	int a;
	int count = 1;
	int sp = 0;
	for(int i =1; i< 100; i++){
		e[i].sp1 = 0;
		e[i].sp2 = 0;
		e[i].sp3 = 0;
	}
	while(!feof(fout)){
		fscanf(fout, "%d", &a);
		if(a == -1){
			count++;
		}else{
			sp++;
			if(sp%3 == 1) e[count].sp1 += a;
			if(sp%3 == 2) e[count].sp2 += a;
			if(sp%3 == 0) e[count].sp3 += a;
		}
	}
	int sum = 0;
	for(int i =1; i< count-1; i++){
		printf("ngay %d: \n", i);
		printf("\tSan pham A: %d\n", e[i].sp1);
		printf("\tSan pham B: %d\n", e[i].sp2);
		printf("\tSan pham C: %d\n", e[i].sp3);
		sum = e[i].sp1*10 + e[i].sp2*50 + e[i].sp3*80;
		printf("\tTong tien: %d trieu dong\n", sum); 
	}
}

void uuTien(queueType *Q){
	elementtype e;
	printf("Nhap nguoi uu tien: \n");
	printf("\tNhap ten: ");
	gets(e.name);
	printf("\tNhap phone: ");
	gets(e.phone);
	node *cur = (*Q).root;
	while(cur != NULL){
		if(strcasecmp(cur->element.name, e.name) == 0 && strcasecmp(cur->element.phone, e.phone) == 0) break;
		cur = cur->next;
	}
	node *tmp;
	if(cur != NULL){
		tmp = makeNewNode(cur->element);
	}
	deleteCurrent(Q, cur);
	tmp->next = (*Q).root;
	(*Q).root = tmp;
	cur = (*Q).root;
	while(cur != NULL){
		printf("%s-%s\n", cur->element.name, cur->element.phone);
		cur = cur->next;
	}
}
















