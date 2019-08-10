//Chuyen doi he thap phan sang he nhi phan
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max 100

int a[max];
int ni;
double nf;

int thapToNhi(int n){	//Bi han che so luong lon do da chuyen qua so cua he thap phan
	static int a =1;
	a*= 10;
	if(n/2 == 0) return 1*(a/10);
	return (n%2)*(a/10)+thapToNhi(n/2);
}

void doiCoSo(int a){	//Chi ap dung duoc cho so nguyen khong dau
	if(a>=2){
		doiCoSo(a/2);
	}
	printf("%d", a%2);
}

int count = 0;
void doiCoSo2(int n, int a[]){
	if(n/2 != 0) doiCoSo2(n/2, a);
	// printf("%d", n%2);
	a[count] = n%2;
	count++;
}

void printBinary1(int a[], int tmp){		//kiem tra de in ra dung gia tri cua 8bit, 16bit, 32bit....(kiem tra cua so duong)
	if(count %4 != 0){
		printf("%d", 0);
		count++;
		printBinary1(a, tmp);
	}
	if(a[0] == 1 && tmp%4 == 0){
		printf("0000");
	}
}
void printBinary2(int a[]){		//kiem tra de in ra dung gia tri cua 8bit, 16bit, 32bit....(kiem tra cua so am)
	if(count %4 != 0){
		printf("%d", 1);
		count++;
		printBinary2(a);
	}
	// if(a[0] == 1 &&)
}
void printBinary(int a[], int i, int tmp){		//in ra cac so da duoc doi sang nhi phan 
	if(i < tmp){
		printf("%d", a[i]);
		printBinary(a, i+1, tmp);	
	}
}
void doiPhanThapPhan(double nf){
	// static int dem = 0;
	if(nf > 0E+8){
		nf *=2;
        // fbin[i] =(int)(nf);
        printf("%d", (int)nf);
        if(nf>=1)
            nf-=1;
        // dem++;
     	doiPhanThapPhan(nf);
	}
}


int main(){

	double n;
	printf("Nhap n: ");
	scanf("%lf", &n);
	ni = (long)n;
	if(n < 0){
		nf = ni -n;
	}else{
		nf = n - ni;
	}
	int n1 = ni;		//Lay du lieu de kiem tra nguyen duong hay am
	
	printf("Cach doi bi han che voi so qua lon: ");
	printf("%d\n",thapToNhi(ni));

	printf("Cach doi ap dung cho so nguyen duong: ");
	doiCoSo(ni);
	printf("\n");

	printf("Cach doi cho so nguyen co dau: ");
	if(ni < -128) ni = ni+512*(abs(ni)/128);	//quy doi so am ra vong lap tiep theo co bit tuong tu
	if(ni >= -128 && ni < 0) ni = ni+256;
	doiCoSo2(ni, a);		//dung dem so luong 
	int tmp = count;

	if(n1>=0){
		printBinary1(a, tmp);
		printBinary(a, 0, tmp);
	}else{
		printBinary2(a);
		printBinary(a, 0, tmp);
	}
	if(nf != 0){
		printf(".");
		doiPhanThapPhan(nf);
	}
	printf("\n");

}
