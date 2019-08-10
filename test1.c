#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

int main(){

	treeType T;
	initalize(&T);
	insertMostLeft(&T, 1);
	insertMostRight(&T, 2);
	insertMostRight(&T, 3);
	insertMostLeft(&T, 4);
	insertMostRight(&(T->leftChild), 5);
	insertMostLeft(&(T->rightChild->rightChild), 6);
	insertMostLeft(&(T->rightChild->rightChild->leftChild), 7);
	inOder(T);
	printf("height: %d\n", height(T));
	
}