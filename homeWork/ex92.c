#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stackRec.h"
#include "../largeNumber.h"


int main(){

	stackType stack1, stack2, stack3;
	initalize(&stack1);
	initalize(&stack2);
	initalize(&stack3);
	char str1[max];
	char str2[max];
	printf("Nhap so thu 1: ");
	gets(str1);
	for(int i =0; i< strlen(str1); i++){
		if(!((str1[i] >= '0' && str1[i] <= '9') || str1[i] == '-') ){
			printf("String error\n");
			return 0;
		}
	}
	printf("Nhap so thu 2: ");
	gets(str2);
	for(int i =0; i< strlen(str2); i++){
		if(!((str2[i] >= '0' && str2[i] <= '9') || str2[i] == '-') ){
			printf("String error\n");
			return 0;
		}
	}
	stack3 = sumLargeNumber(str1, str2, stack1, stack2, stack3);
	printf("The result of %s + %s = ", str1, str2);
	while(!empty(&stack3)){
		printf("%d", pop(&stack3));
	}
	puts("");

}






