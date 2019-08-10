//Tinh gia tri bieu thuc hau to ( tinh cho ca cac so nhieu chu so )
//Check khi init error
//Dung stackList.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../stackList.h"
#define max 100

float conversion(char *str, stackType *S){
	float a, b;

	for(int i =0; i< strlen(str); i++){
		if(str[i] == ' '){
			i++;
		}
		if(isdigit(str[i])){
			int num = 0;
			while(isdigit(str[i])){
				num = num*10 + str[i]-48;
				i++;
			}
			push(&S, num);
		}
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
			if(empty(&S)){
				printf("Init error!!!\n");
				exit(0);
			}
			a = pop(&S);
			if(empty(&S)){
				printf("Init error!!!\n");
				exit(0);
			}
			b = pop(&S);
			switch(str[i]){
				case '+':
					push(&S, b + a);
					break;
				case '-': 
					push(&S, b - a);
					break;
				case '*': 
					push(&S, b * a);
					break;
				case '/': 
					push(&S, b / a);
					break;
			}
		}
	}
	int result = pop(&S);;
	if(!empty(&S)){
		printf("Init error!!!\n");
		exit(0);
	}
	return result;
}

int main(){

	char str[max];
	stackType *S;
	initalize(&S);
	gets(str);
	printf("%g\n", conversion(str, S));

}