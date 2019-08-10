#include <stdio.h>
#include <stdlib.h>
#include "../stackList.h"

int main(){

	node *root = NULL;
	for(int i =0; i< 5; i++){
		push(&root, i);
	}
	printf("%g\n", pop(&root));
	printf("%g\n", pop(&root));
	printf("%g\n", pop(&root));

}




