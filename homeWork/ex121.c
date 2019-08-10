// Lich thi dau soccer
// Tao 1 khung cay 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "ex121.h"
#define max 100

void try(treeType T, int n, elementtype list[], int mark){
	int m;
	elementtype e;
	static int i =0;
	if(n == mark){
		strcpy(T->element.country, list[i].country);
		T->leftChild = NULL;
		T->rightChild = NULL;
		i++;
	}else{
		strcpy(e.country, " ");
		T->leftChild = makeNewNode(e);
		T->rightChild = makeNewNode(e);
		try(T->leftChild, n+1, list, mark);
		try(T->rightChild, n+1, list, mark);
		// srand(time(NULL));
		// m = rand()%2;
		// printf("%d\n", m);
		printf("Team %s vs", T->leftChild->element.country);
		printf(" Team %s\n", T->rightChild->element.country);
		printf("***Team win(1 is %s, 2 is %s): ", T->leftChild->element.country, T->rightChild->element.country);
		scanf("%d", &m);
		if(m ==  1){
			strcpy(T->element.country, T->leftChild->element.country);
		}
		else{
			strcpy(T->element.country, T->rightChild->element.country);
		}
	}
}

int main(int argc, char *argv[]){

	if(argc != 3){
		printf("Wrong argument\n %s <file source> <file out>\n", argv[0]);
		return 0;
	}

	FILE *fin, *fout;
	elementtype list[max];
	char str[max];
	int count = 0, mark;
	treeType T;

	if((fin = fopen(argv[1], "r")) == NULL){
		printf("Can't open file %s\n", argv[1]);
		return 0;
	}
	if((fout = fopen(argv[2], "w")) == NULL){
		printf("Can't open file %s\n", argv[2]);
		return 0;
	}

	while(fgets(str, max, fin) != NULL){
		count++;
	}
	rewind(fin);
	for(int i =0; i< count; i++){
		fscanf(fin, "%d%s", &list[i].id, list[i].country);
	}
	int j = 1;
	while(1){
		if(pow(2, j) == count) break;
		j++;
		if(j >= 100){
			printf("So doi khong thoa man\n");
			return 0;
		}
	}

	printf("Danh sach cac doi la: \n");
	for(int i =0; i< count; i++){
		printf("%d\t%s\n", list[i].id, list[i].country);
		// puts("");
	}

	elementtype e;
	strcpy(e.country, " ");
	T = makeNewNode(e);

	try(T, 0, list, j);
	postOder(T);
	printf("\nTeam champion: %s!!!\n", T->element.country);

}














