#include <stdio.h>
#include "../mergeSort.h"

int main(){

	elementtype a[] = {1, 9, 10, 2, 3};
	mergeSort(a, 0, 4);
	for(int i =0; i<5; i++){
		printf("%d ", a[i]);
	}

}