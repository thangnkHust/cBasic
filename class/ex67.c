// Ha Noi tower 
#include<stdio.h>

int count =0;
int max =0;

void move(int n, char A, char B, char C){
	
	if(n == 1){
		count++;
		printf("Buoc %d: %c -> %c\n",count, A, B);
		if(max < count) max = count;
	}else{
		move(n-1, A, C, B);
		move(1, A, B, C);
		move(n-1, C, B, A);
	}
}

int main(){

	int n;
	printf("nhap n: ");
	scanf("%d", &n);
	move(n, 'A', 'B', 'C');
	printf("Tong so buoc la: %d\n", max);

}