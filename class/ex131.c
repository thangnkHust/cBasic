#include <stdio.h>

void insertionSort(int a[], int n){
	int tmp;
	for(int i =1; i<n; i++){
		tmp = a[i];
		for(int j = i-1; j >= 0; j--){
			if(tmp < a[j]){
				a[j+1] = a[j];
				a[j] = tmp;
			}
		}
		printf("Buoc %d: ", i);
		for(int k = 0; k < n; k++){
			printf("%d ", a[k]);
		}
		printf("\n");
	}
}

void selectionSort(int a[], int n){
	int tmp, min;
	for(int i =0; i < n-1; i++){
		min = i;
		for(int j = i+1; j <= n-1; j++){
			if(a[j] < a[min]){
				min = j;
			}
		}
		tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
		printf("Buoc %d: ", i+1);
		for(int k = 0; k < n; k++){
			printf("%d ", a[k]);
		}
		printf("\n");
	}
}


int main(){

	int a[] = {1, 5, 6, 3, 9, 4};
	insertionSort(a, 6);
	selectionSort(a, 6);
	// for(int i =0; i < 6; i++){
	// 	printf("%d\n", a[i]);
	// }

}