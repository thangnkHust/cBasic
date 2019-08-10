#include <stdio.h>

int main(){

	int n;
	int a[100];
	scanf("%d", &n);
	for(int i =0; i< n; i++){
		a[i] = 2*i;
	}
	for(int i =0; i< n; i++){
		printf("%d ", a[i]);
	}
	puts("");

}