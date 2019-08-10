// Chuyen bieu thuc trung to ve hau to ( Ky phap Ba Lan )
// Dung library stackList.h thi error: 	 about trap: 6
// Dung stackRec.h thi chay binh thuong
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../stackRec.h"

int compare(char x){
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1 ;
	if (x == '*' || x == '/' || x == '%')
		return 2;
	return 3;
}

void infixToPostfix(stackType S, char infix[], char postfix[]){
	int j = 0;
	char x;
	for(int i =0; i< strlen(infix); i++){
		if(isalnum(infix[i])){
			postfix[j++] = infix[i];
		}else{
			if(infix[i] == '('){
				push(&S, '(');
			}else{
				if(infix[i] == ')'){
					while((x = pop(&S)) != '('){
						postfix[j++] = x;
					}
				}else{
					while(!empty(&S) && (compare(infix[i]) <= compare(peek(&S))) ){
						postfix[j++] = pop(&S);
					}
					push(&S, infix[i]);
				}
			}
		}
	}
	while(!empty(&S)){
		postfix[j++] = pop(&S);
	}
	postfix[j] = '\0';
}


int main(){

	stackType S;
	initalize(&S);
	char infix[10], postfix[10];
	gets(infix);
	infixToPostfix(S, infix, postfix);
	puts(postfix);

}















