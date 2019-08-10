#define max 10000

typedef int elementtype;

typedef struct queue{
	elementtype element[max];
	int front, rear;
}queue;

typedef queue queueType;

void initalize(queueType *Q){
	Q->front = -1;
	Q->rear = -1;
}

int empty(queueType *Q){
	if(Q->front == -1) return 1;
	return 0;
}

int full(queueType *Q){
	if((Q->rear - Q->front + 1)%max == 0) return 1;
	return 0;
}

void enQueue(queueType *Q, elementtype e){
	if(full(Q)){
		printf("Queue is full!\n");
		exit(0);
	}
	if(empty(Q)) Q->front = 0;
	Q->rear = (Q->rear + 1)%max;
	Q->element[Q->rear] = e;
}

elementtype deQueue(queueType *Q){
	elementtype e;
	if(empty(Q)){
		printf("Queue is empty!\n");
		exit(0);
	}
	if(Q->front == Q->rear){
		initalize(Q);
	}else{
		e = Q->element[Q->front];
		Q->front = (Q->front + 1)%max;
	}
	return e;
}

elementtype peekQueue(queueType *Q){
	if(empty(Q)){
		printf("Queue is empty!\n");
		exit(0);
	}
	return Q->element[Q->front];
}








