#include <stdio.h>

int linearSentinelSearch(int a[], int n, int x){  //tim kiem tuyen tinh co linh gac 
	int k = 0;
	a[n] = x;
	while(a[k] != x){
		k++;
	}
	return k;
}

int main(){

	int n;
	printf("Nhap so phan tu: ");
	scanf("%d", &n);
	int a[n+1];
	for(int i =0; i< n; i++){
		printf("Nhap so thu %d: ", i+1);
		scanf("%d", &a[i]);
	}

	int x;
	printf("Nhap x: ");
	scanf("%d", &x);

	if(n == linearSentinelSearch(a, n, x)){
		printf("Khong co so can tim!\n");
	}else{
		printf("So can tim o vi tri: %d\n", linearSentinelSearch(a, n, x) );
	}

}