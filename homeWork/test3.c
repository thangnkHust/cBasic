#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex121.h"

void try(treeType T, int n){
	int m;
	elementtype e;
	if(n == 4){
		printf("Nhap doi: ");
		gets(T->element.country);
		// scanf("%d", &T->element.id);
		T->leftChild = NULL;
		T->rightChild = NULL;
	}else{
		strcpy(e.country, " ");
		T->leftChild = makeNewNode(e);
		T->rightChild = makeNewNode(e);
		try(T->leftChild, n+1);
		try(T->rightChild, n+1);
		srand(time(NULL));
		m = rand()%2;
		// printf("%d\n", m);
		if(m == 0) strcpy(T->element.country, T->leftChild->element.country);
		else strcpy(T->element.country, T->rightChild->element.country);
	}
}

int main(){

	treeType T;
	initalize(&T);
	elementtype e;
	strcpy(e.country, " ");
	T = makeNewNode(e);
	try(T, 0);
	printTree(T);
	printf("%s\n", T->element.country);

}