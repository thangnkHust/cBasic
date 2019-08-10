#include <stdio.h>
#include <stdlib.h>

int print1to50(int n){
	if(n == 1){
		return 1;
	}
	printf("%d ", n);
	return print1to50(n-1);
}

void a(int n){
	if(n > 1) a(n-1);
	printf("%d ", n);
}

int main(){
	printf("%d \n", print1to50(50));
	a(50);
	printf("\n");
}