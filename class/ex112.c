// search binary ( vong lap va de quy )

#include <stdio.h>
#include <stdlib.h>
#include "../doubleLinkedList.h"

void printList(node *root){
	node *tmp = root;
	while(tmp!= NULL){
		printf("%d\n", tmp->element);
		tmp = tmp->next;
	}
}

int binarySearch(int a[], elementtype x, int n){
	int L = 0, R = n-1;
	int mid;
	while(L <= R){
		mid = (L+R)/2;
		if(a[mid] < x)
			L = mid + 1;
		else
			if( a[mid] > x)
				R = mid-1;
			else
				return mid;
	}
	return -1;
}

int binarySearchRecursive(int a[], elementtype x, int L, int R){
	if(L > R) return -1;
	int mid = (L+R)/2;
	if(a[mid] < x)  return binarySearchRecursive(a, x, mid+1, R);
	else{
		if(a[mid] > x){
			return binarySearchRecursive(a, x, L, mid-1);
		}else
			return mid;
	}
	return -1;
}

int main(){

	// node *root = NULL, *tail = NULL;
	int n;
	printf("Nhap so luong: ");
	scanf("%d", &n);
	int a[n];
	for(int i =0; i< n; i++){
		// insertAtEnd(&root, &tail, i);
		a[i] = i+1;
	}

	int x;
	printf("Nhap so can tim: ");
	scanf("%d", &x);

	printf("vi tri: %d\n", binarySearch(a, x, n));
	printf("vi tri: %d\n", binarySearchRecursive(a, x, 0, n-1));
	

	// searchTranspose(&root, &tail, 3);
	// printList(root);
	// puts("");

	// searchMoveToTop(&root, &tail, 3);
	// printList(root);

}