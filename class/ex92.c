//Setting stack by array
//top la doc lap 
#include <stdio.h>	
#include "../stackArray.h"

int main(){
	stackType stack;
	push(1,stack);
	push(2, stack);
	push(10, stack);
	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));
	// for(int i =0 ; i< top; i++){
	// 	printf("%d ", stack[i]);
	// }
}






