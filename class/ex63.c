#include <stdio.h>

int sumN(int n){
	if(n >= 1){
		return n + sumN(n-1);
	}
	return 0;
}

int a, b= 1;
int count = 1;
int soChuSo(int n){
	a = n/b;
	if(a  < 10){
		return count;
	}
	b = b*10;
	count ++;
	return soChuSo(n);
}
int demN(int n){
	int dem = 0;
	if(n/10 == 0) return 1;
	dem++;
	return dem + demN(n/10);
}

// int sum = 0;
int sumInN(int n){
	int sum = 0;
	if(n/10 == 0) return n;
	sum = n%10;
	return sum + sumInN(n/10);
}


int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Tong tu 1 den %d la: %d\n",n, sumN(n));
	printf("So chu so cua %d la:  %d\n",n, soChuSo(n));
	printf("So chu so cua %d la:  %d\n",n, demN(n));
	printf("Tong cac chu so: %d\n", sumInN(n));

}