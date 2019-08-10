// Su dung file in: name.txt
// Cut name, compare -> insertNode vao cay BST thi chi can so sanh T->key
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ex122.h"
#define max 100

void cut(char str[], char first[], char mid[], char last[]){	//Cut cac str va tra ve first, mid, last
	int m1, m2;
	for(int i =0; i < strlen(str); i++){
		if(str[i] == ' '){
			m1 = i;
			break;
		}
	}
	for(int i =strlen(str)-1; i >= 0; i--){
		if(str[i] == ' '){
			m2 = i;
			break;
		}
	}
	int j = 0;
	for(int i =0; i<m1; i++){
		first[j] = str[i];
		j++;
	}
	first[j] = '\0';
	j = 0;
	for(int i = m1+1; i < m2; i++){
		mid[j++] = str[i];
	}
	mid[j] = '\0';
	j =0;
	for(int i = m2+1; i <strlen(str); i++){
		last[j++] = str[i];
	}
	last[j] = '\0';
	// puts(first);
	// puts(mid);
	// puts(last);
}

int compare(char str1[], char str2[]){		//2 string vao, cut string va so sanh last -> mid -> last
	char first1[10], mid1[20], last1[10];
	char first2[10], mid2[20], last2[10];
	cut(str1, first1, mid1, last1);
	cut(str2, first2, mid2, last2);
	if(strcasecmp(last1, last2) > 0) return 1;
	else{
		if(strcasecmp(last1, last2) == 0 && strcasecmp(mid1, mid2) > 0) return 1;
		else{
			if(strcasecmp(mid1, mid2) == 0 && strcasecmp(first1, first2) > 0) return 1;
		}
	}
	return -1;
}

void insertNode(treeType *T, char k[]){
	char tmp[100];
	strcpy(tmp, k);
	if(*T == NULL){
		*T = (node*)malloc(sizeof(node));
		strcpy((*T)->key.name, tmp);
		(*T)->rightChild = NULL;
		(*T)->leftChild = NULL;
	}else{
		if(compare(k, (*T)->key.name) < 0) insertNode(&((*T)->leftChild), k);
		else insertNode(&((*T)->rightChild), k);
	}
}

int menu(){
	int n;
	puts("============MENU=============");
	puts("1.In danh sach da sap xep");
	puts("2.Tim kiem");
	puts("3.Exit!!!");
	printf("Enter selection: ");
	scanf("%d", &n);
	puts("=============================");
	return n;
}

treeType find(treeType T, keyType x){
	if(T == NULL) return NULL;
	if(strcasecmp(T->key.name, x.name) == 0) return T;
	if(compare(x.name, T->key.name) < 0) return find(T->leftChild, x);
	return find(T->rightChild, x);
}

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Error argument\n%s <file in>\n", argv[0]);
		return 0;
	}

	treeType T;
	initalize(&T);
	FILE *fin;
	char str[max];
	int selec;
	keyType tmp;
	char str1[max];
	treeType temp;

	if((fin = fopen(argv[1], "r")) == NULL){
		printf("Can't open file %s\n", argv[1]);
		return 0;
	}

	printf("Danh sach: \n");
	int j = 0;
	while(fgets(str, max, fin) != NULL){
		for(int i =0; i< strlen(str)-1; i++){
			str1[j] = str[i];
			j++;
		}
		str1[j] = '\0';
		j = 0;
		printf("%s\n", str1);
		insertNode(&T, str1);
	}
	do{
		selec = menu();
		switch(selec){
			case 1:
				printf("***Danh sach da sap xep: \n");
				inOder(T);
				break;
			case 2:
				printf("Nhap ten can tim: ");
				getchar();
				gets(tmp.name);
				temp = find(T, tmp);
				if(temp == NULL) printf("Khong co ket qua\n");
				else
					printf("Result: %p\t%s\n", find(T, tmp), find(T, tmp)->key.name);
				break;
			case 3:
				puts("Exit!!!");
				break;
		}
	}while(selec != 3);

}







