#include <stdio.h>

int giaiThua(int n){
	if(n == 1 || n == 0) return 1;
	return n*giaiThua(n-1);
}
int fibo(int n){
	if(n == 1 || n == 2) return 1;
	return fibo(n-1) + fibo(n-2);
}
int outFibo(int n, int i){
	if(i == n) return fibo(n);
	printf("%d\n",fibo(i));
	return outFibo(n, i+1);
}

int main(){

	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("%d! = %d\n",n, giaiThua(n));
	printf("fibo(%d) = %d\n", n, fibo(n));
	printf("%d\n", outFibo(n, 1));
}