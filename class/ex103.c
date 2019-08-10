// Test queue
// Library queueCircular.h, queueArray.h, queueList.h
#include <stdio.h>
#include <stdlib.h>
#include "../queueCircular.h"

int main(){

	queueType Q;
	initalize(&Q);
	for(int i =0; i< 5; i++){
		enQueue(&Q, i);
	}
	// enQueue(&Q, 1);
	printf("%d\n", deQueue(&Q));
	printf("%d\n", deQueue(&Q));
	enQueue(&Q, 5);
	enQueue(&Q, 6);
	printf("%d\n", peekQueue(&Q));
	printf("%d\n", peekQueue(&Q));

}