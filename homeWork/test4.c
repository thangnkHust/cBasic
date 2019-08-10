#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../binaryTree.h"

void insert(treeType *T, int n, int A[]){
	static int count = 0;
	if(count == 4) {
		printf("ket thuc\n");
		return;
	}
	else{
		int m;
		(*T)->leftChild = makeNewNode((*T)->element);
		srand(time(NULL));
		m = rand()%16+1;
		printf("%d\n", m);
		printf("%d\n", A[m]);
		while(A[m] == 1){
			printf("%d\n", m);
			printf("%d\n", A[m]);
			getchar();
			srand(time(NULL));
			m = rand()%16+1;
		}
		(*T)->rightChild = makeNewNode(m);
		insert(&((*T)->leftChild), n, A);
		insert(&((*T)->rightChild), n, A);
		A[m] = 1;
		count++;
		printf("%d\n", count);
		getchar();
	}
}

int main(){
	treeType T;
	initalize(&T);
	int A[16];
	for(int i =1; i<= 16;i++){
		A[i] = 0;
	}
	for(int i = 1; i<= 16; i++){
		printf(" %d ", A[i]);
	}
	srand(time(NULL));
	int m = rand()%16+1;
	T = makeNewNode(m);
	A[m] = 1;
	printf("%d\n", T->element);
	insert(&T, 16, A);
	preOder(T);
}