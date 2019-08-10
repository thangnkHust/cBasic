#include<stdio.h>
#include<stdlib.h>

int main(){

	int i, n, *p;

	printf("how many numbers do you want to enter?\n");
	scanf("%d", &n);

	p = (int *)malloc(n * sizeof(int));
	if(p == NULL){
		printf("bo nho cap phat failed\n");
		return 1;
	}

	/* Nhận các số từ bàn phím */ 
	printf("Please enter numbers now:\n"); 
	for (i = 0; i < n; i++)
		scanf("%d", &p[i]);
	/* Đưa ra theo thứ tự ngược lại*/
	printf("The numbers in reverse order are \n"); 
	for (i = n - 1; i >= 0; --i)
		printf("%d ",p[i]);
	printf("\n");
	/* Giải phóng bộ nhớ */ 
	free(p);
	return 0;

}