// Setting stack by array
// 1 struct luu top va array
#include <stdio.h>
#include <stdlib.h>
#include "../stackRec.h"

int main(){
	stackType stack;
	initalize(&stack);
	push(1, &stack);
	push(2, &stack);
	push(10, &stack);
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	// for(int i =0 ; i< stack.top; i++){
	// 	printf("%d\n", stack.element[i]);
	// }
}