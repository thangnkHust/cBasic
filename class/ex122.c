#include <stdio.h>
#include <stdlib.h>
#include "../binarySearchTree.h"
#define max 100

int main(){
	treeType T;
	initalize(&T);
	int a[max];
	int n;
	scanf("%d", &n);
	for(int i =0; i< n; i++){
		scanf("%d", &a[i]);
	}
	for(int i =0; i<n; i++){
		insertNode(&T, a[i]);
	}
	inOder(T);
	puts("");
	preOder(T);
	puts("");
	// treeType tmp = search(T, 3);
	// if(tmp != NULL){
		// printf("%d\n", tmp->key);
	// }
	// printf("Min: %d\n", deleteMin(&T));
	// deleteNode(&T, 7);
	// inOder(T);
	// puts("");
	// preOder(T);
}