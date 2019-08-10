// Nhap so luong string
// Nhap cac string
// puts string sorted
#include <stdio.h>
#include <string.h>
#define max 100

void insertionSort(char a[], int n){
	char tmp;
	for(int i =1; i<n; i++){
		tmp = a[i];
		for(int j = i-1; j >= 0; j--){
			if(tmp < a[j]){
				a[j+1] = a[j];
				a[j] = tmp;
			}
		}
	}
}


int main(){

	int n;
	printf("Nhap so luong tu: ");
	scanf("%d", &n);

	char a[n][max];
	char arr[3*max];

	getchar();
	for(int i =0; i< n; i++){
		gets(a[i]);
	}
	for(int i =0; i< n; i++){
		strcat(arr, a[i]);
	}
	printf("Input array character: \n\t");
	puts(arr);
	insertionSort(arr, strlen(arr));
	printf("Sorted array: \n\t");
	puts(arr);

}	