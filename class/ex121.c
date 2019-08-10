#include <stdio.h>
#include <stdlib.h>
#include "../binaryTree.h"

int main(){

	treeType T;
	T = makeNewNode('+');
	insertMostLeft(&T, 'a');
	insertMostLeft(&T, '!');
	insertMostRight(&T, '/');
	insertMostRight(&T, 'd');
	insertMostLeft(&(T->rightChild), '-');
	insertMostLeft(&(T->rightChild), 'b');
	insertMostRight(&(T->rightChild->leftChild), 'd');

	// printTree(T);
	inOder(T);
	printf("\n");
	preOder(T);
	printf("\n");
	postOder(T);

}