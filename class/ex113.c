#include <stdio.h>
#include <stdlib.h>
#include "../binaryTree.h"

int main(){

	treeType T1, T2, T3, T4, new1, new2, new;
	initalize(&T1);
	initalize(&T1);
	// printf("%d\n", emptyTree(T));
	T1 = makeNewNode(3);
	T2 = makeNewNode(4);
	// printf("%d\n", emptyTree(T));
	new1 = creatFrom2Tree(T1, T2, 2);

	T3 = makeNewNode(5);
	T4 = makeNewNode(6);
	new2 = creatFrom2Tree(T3, T4, 7);

	new = creatFrom2Tree(new1, new2, 9);
	printTree(new);
	// printf("So nut la: %d\n", countTree(new));
	// insertMostLeft(&new, 5);
	// printTree(new);
	// printf("So nut la: %d\n", countTree(new));
	insertLeft(&new, 4, 10);
	insertRight(&new, 4, 11);
	// printf("%d \n", find(new, 11)->element);
	printTree(new);

}