#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stackRec.h"

stackType sumLargeNumber(char str1[], char str2[], stackType stack1, stackType stack2, stackType stack3){
	int mark = 0;
	for(int i =0; i < strlen(str1); i++){
		if(str1[i] != ' ')
			push(str1[i]-48, &stack1);
	}
	for(int i =0; i < strlen(str2); i++){
		if(str2[i] != ' ')
			push(str2[i]-48, &stack2);
	}

	int tmp;

	while(!empty(&stack1) && !empty(&stack2)){
		tmp = pop(&stack1) + pop(&stack2);
		tmp += mark;
		mark = 0;
		if(tmp >= 10){
			tmp = tmp%10;
			mark = 1;
			push(tmp, &stack3);
		}else{
			tmp = tmp%10;
			push(tmp, &stack3);
		}
	}
	// if(!empty(&stack1)){
	while(!empty(&stack1)){
		tmp = pop(&stack1);
		tmp += mark;
		mark = 0;
		if(tmp >= 10){
			tmp = tmp%10;
			mark = 1;
			push(tmp, &stack3);
		}else{
			tmp = tmp%10;
			push(tmp, &stack3);
		}
		if(mark == 1)
			push(1,&stack3);
	}
	while(!empty(&stack2)){
		tmp = pop(&stack2);
		tmp += mark;
		mark = 0;
		if(tmp >= 10){
			tmp = tmp%10;
			mark = 1;
			push(tmp, &stack3);
		}else{
			tmp = tmp%10;
			push(tmp, &stack3);
		}
	}
	if(mark == 1) push(1, &stack3);
	return stack3;
}

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
		if(!((str1[i] >= '0' && str1[i] <= '9') || str1[i] == ' ') ){
			printf("String error\n");
			return 0;
		}
	}
	printf("Nhap so thu 2: ");
	gets(str2);
	for(int i =0; i< strlen(str2); i++){
		if(!((str2[i] >= '0' && str2[i] <= '9') || str2[i] == ' ') ){
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








