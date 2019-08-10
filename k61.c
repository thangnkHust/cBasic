#include <stdio.h>
#include <stdlib.h>
#include "singleLinkedList.h"

int menu(void);
void readFile(FILE *fin, node **root, int *n);
void printList(node *root);


typedef struct{
	int count;
	int id1[10], id2[10];
}vongThiDau;

typedef vongThiDau vongThiDau;
vongThiDau v[10];

void thiDau(vongThiDau v[], FILE *fin, int n, node *root);
void capNhat(vongThiDau v[], FILE *fin, int n, node **root);
void deleteMinTeam(node **root);

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Error argument\n %s <file in>\n", argv[0]);
		return 0;
	}

	int selec;
	FILE *fin;
	node *root = NULL;
	int n;
	int i =1; int j = 1;
	int a = 0;
	int case3 = 0;
	int count = 1;

	if((fin = fopen(argv[1], "r")) == NULL){
		printf("Can't open file %s\n", argv[1]);
		return 0;
	}
	readFile(fin, &root, &n);

	do{
		selec = menu();
		switch(selec){
			case 1:
				printf("%-3s%-30s%-10s%-20s%-20s\n", "id", "tenDoiBong", "diem", "soBanThang", "soBanThua");
				printList(root);
				break;
			case 2:
				if(case3 != 1){
					thiDau(v, fin, n, root);
				}else{
					printf("Da cap nhat ti so\n");
				}
				break;
			case 3:
				if(count <= n-1){
					capNhat(v, fin, n, &root);
					count++;
				}else{
					printf("Da cap nhat het cac vong\n");
				}
				if(count == n-1)
					case3 = 1;
				break;
			case 4:
				if(root->next == NULL){
					printf("%-3s%-30s%-10s%-20s%-20s\n", "id", "tenDoiBong", "diem", "soBanThang", "soBanThua");
					printList(root);
					break;
				}
				deleteMinTeam(&root);
				printf("%-3s%-30s%-10s%-20s%-20s\n", "id", "tenDoiBong", "diem", "soBanThang", "soBanThua");
				printList(root);
				break;
			case 5:
				puts("Exit!!!");
				break;
		}
	}while(selec != 5);



}

int menu(){
	int selec;
	puts("=============MENU===========");
	puts("1.In thong tin cac doi bong");
	puts("2.In thong tin lich thi dau");
	puts("3.Cap nhat ket qua vong dau");
	puts("4.Thong ke");
	puts("5.Exit!!!");
	printf("Nhap lua chon: ");
	scanf("%d", &selec);
	puts("============================");
	return selec;
}

void readFile(FILE *fin, node **root, int *n){
	fscanf(fin, "%d", &(*n));
	elementtype e;
	int i = 1;
	while(i <= *n){
		fscanf(fin, "%d%s", &e.id, e.name);
		// printf("%d-%s\n",e.id, e.name);
		insertAtHead(root, e);
		i++;
	}
}

void printList(node *root){
	node *cur = root;
	while(cur != NULL){
		printf("%-3d%-30s%-10d%-20d%-20d\n", cur->element.id, cur->element.name, cur->element.diem, cur->element.banThang, cur->element.banThua);
		cur = cur->next;
	}
}

void thiDau(vongThiDau *v, FILE *fin, int n, node *root){
	int i =1;
	int j = 1;
	node *cur1, *cur2;
	while(i <= n-1){
		fscanf(fin, "%d", &v[i].count);
		printf("Vong %d: \n", v[i].count);
		while(j <= n/2){
			fscanf(fin, "%d%d", &v[i].id1[j], &v[i].id2[j]);
			// printf("%d-%d\n", v[i].id1[j], v[i].id2[j]);
			cur1 = root;
			cur2 = root;
			while(cur1 != NULL){
				if(cur1->element.id == v[i].id1[j]) break;
				cur1 = cur1->next;
			}
			while(cur2 != NULL){
				if(cur2->element.id == v[i].id2[j]) break;
				cur2 = cur2->next;
			}
			printf("\t%s-%s\n", cur1->element.name, cur2->element.name);
			j++;
		}
		j = 1;
		i++;
	}
}

void capNhat(vongThiDau v[], FILE *fin, int n, node **root){
	static int i =1;
	int j = 1;
	int a, b;
	node *cur1, *cur2;
	printf("Cap nhat Vong %d: \n", v[i].count);
	while(j <= n/2){
		cur1 = *root;
		cur2 = *root;
		while(cur1 != NULL){
			if(cur1->element.id == v[i].id1[j]) break;
			cur1 = cur1->next;
		}
		while(cur2 != NULL){
			if(cur2->element.id == v[i].id2[j]) break;
			cur2 = cur2->next;
		}
		printf("%s-%s: ", cur1->element.name, cur2->element.name);
		scanf("%d%d", &a, &b);
		cur1->element.banThang += a;
		cur1->element.banThua += b;
		cur2->element.banThang += b;
		cur2->element.banThua += a;
		if(a > b){
			cur1->element.diem += 3;
		}else{
			if(a < b){
				cur2->element.diem += 3;
			}else{
				cur1->element.diem += 1;
				cur2->element.diem += 1;
			}
		}
		j++;
	}
	i++;
}

void deleteMinTeam(node **root){
	node *cur = *root;
	node *tmp = *root;
	int min = (*root)->element.diem;
	while(cur != NULL){
		if(cur->element.diem < min){
			min = cur->element.diem;
			tmp = cur;
		}
		cur = cur->next;
	}
	deleteCurrent(root, tmp);
}












