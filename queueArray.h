#define max 10000

typedef int elementtype;

typedef struct queue{
	elementtype element[max];
	int front, rear;
}queue;

typedef queue queueType;

void initalize(queueType *Q){
	Q->front = 0;
	Q->rear = 0;
}

int empty(queueType *Q){
	if(Q->front == -1) return 1;
	return 0;
}

int full(queueType *Q){
	if((Q->rear - Q->front + 1) == max) return 1;
	return 0;
}

void enQueue(queueType *Q, elementtype e){
	if(!full(Q)){
		// if(empty(Q)) Q->front = 0;
		Q->rear = (Q->rear +1)%max;
		Q->element[Q->rear] = e;
	}else{
		printf("Queue full!\n");
	}
}

elementtype deQueue(queueType *Q){
	elementtype e;
	if(empty(Q)){
		printf("Queue is empty!\n");
		exit(0);
	}
	e = Q->element[Q->front++];
	if(Q->front > Q->rear) initalize(Q);
	return e;
}

elementtype peekQueue(queueType *Q){
	if(empty(Q)){
		printf("Queue is empty!\n");
		exit(0);
	}
	return Q->front;
}











