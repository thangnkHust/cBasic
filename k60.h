typedef struct process{
	char name[30];
	char phone[15];
	int sp1, sp2, sp3;
}khachHang;

typedef khachHang elementtype;

typedef struct node{
	elementtype element;
	struct node *prev;
	struct node *next;
}node;

typedef struct queueType{
	node *root;
	node *tail;
}queueType;

// typedef queueType queueType;

void initalize(queueType *Q){
	Q->root = NULL;
	Q->tail = NULL;
}

node *makeNewNode(elementtype e){
	node *new = (node*)malloc(sizeof(node));
	new->element = e;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

int empty(queueType *Q){
	if(Q->root == NULL) return 1;
	return 0;
}

void enQueue(queueType *Q, elementtype e){
	node *new = makeNewNode(e);
	if(empty(Q)){
		Q->root = new;
		Q->tail = new;
	}else{
		Q->tail->next = new;
		new->prev = Q->tail;
		Q->tail = new;
	}
}

elementtype deQueue(queueType *Q){
	elementtype e;
	if(empty(Q)){
		printf("Queue is empty\n");
		exit(0);
	}
	node *tmp = Q->root;
	e = tmp->element;
	Q->root = Q->root->next;
	free(tmp);
	return e;
}

elementtype peekQueue(queueType *Q){
	elementtype e;
	if(empty(Q)){
		printf("Queue is empty\n");
		exit(0);
	}
	return Q->root->element;	
}

void deleteFirst(queueType *Q){
	node *tmp = (*Q).root;
	(*Q).root = tmp->next;
	free(tmp);
}

void deleteCurrent(queueType *Q, node *cur){
	// node *tmp = cur;
	if(cur == NULL){
		puts("Khong co model current");
		return;
	} 
	if(cur == (*Q).root) deleteFirst(Q);
	else{
		node *prev = (*Q).root;
		while(prev->next != cur) prev = prev->next;
		prev->next = cur->next;
		free(cur);
	}
}


