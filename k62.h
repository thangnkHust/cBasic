#define num 8
typedef struct{
	int id;
	int order[num];
	long total;
}request;

typedef request elementtype;

// typedef struct node node;
typedef struct node{
	elementtype element;
	struct node *next;
}node;

typedef node node;

node *makeNewNode(elementtype e){
	node *neww = (node*)malloc(sizeof(node));
	neww->element = e;
	neww->next = NULL;
	return neww;
}

void insertAtHead(node **root, elementtype e){
	node *new = makeNewNode(e);
	if(*root == NULL) *root = new;
	else{
		new->next = *root;
		*root = new;
	}
}

void insertAtEnd(node **root, elementtype e){
	node *p = makeNewNode(e);
	if(*root == NULL){
		*root = p;
		return;
	}
	node *cur = *root;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = p;
}

void insertBeforeCurrent(node **root, node **cur, elementtype e){
	node *new = makeNewNode(e);
	if(*cur == *root){
		new->next = *root;
		*root = new;
	}else{
		node *prev = *root;
		while(prev->next != *cur){
			prev = prev->next;
		}
		new->next = *cur;
		prev->next = new;
		*cur = new;
	}
}

void insertAfterCurrent(node **root, node **cur, elementtype e){
	node *new = makeNewNode(e);
	if(*cur == NULL){
		puts("Do nothing"); 
	}else{
		new->next = (*cur)->next;
		(*cur)->next = new;
		*cur = new;
	}
}

void insertAtPosition(node **root, elementtype e, int n){
	int i = 0;
	if(n == 0 || root == NULL){
		node *new = makeNewNode(e);
		new->next = *root;
		*root = new;
	}
	node *cur = *root;
	while((i< n) && (cur->next != NULL)){
		i++;
		cur = cur->next;
	}					
	insertAfterCurrent(root, &cur, e);
}

void deleteFirst(node **root){
	node *tmp = *root;
	*root = tmp->next;
	free(tmp);
}

void deleteCurrent(node **root, node *cur){
	// node *tmp = cur;
	if(cur == NULL){
		puts("Khong co model current");
		return;
	} 
	if(cur == *root) deleteFirst(root);
	else{
		node *prev = *root;
		while(prev->next != cur) prev = prev->next;
		prev->next = cur->next;
		free(cur);
	}
}

void deleteAtPosition(node **root, int n){
	int i =0;
	if(n == 0) deleteFirst(root);
	else{
		node *cur = *root;
		while((i < n) && (cur->next != NULL)){
			cur = cur->next;
			i++;
		}
		if(i == n){
			deleteCurrent(root, cur);	
			puts("Delete at position perfect!");
		}
		else{
			printf("Don't have position!\n");
			// return;
		}
	}
}

node *freeList(node *root){		//free list, can return root de truyen gia tri ra khoi function
	node *to_free;
	to_free = root;
	while(to_free != NULL){
		root = root->next;
		free(to_free);
		to_free = root;
	}
	return root;
}

node *reverseList(node *root){
	node *a, *b;
	a = b = NULL;
	// node *cur = root;
	while(root != NULL){
		a = root;
		root = root->next;
		a->next = b;
		b = a;
	}
	return b;
}

void splitList(node *root, node **root1, node **root2, int n1, int n2){
	int i = 0;

	if(n1 == 0){
		node *cur = root;
		while( (i < n2) && (cur != NULL) ){
			insertAtEnd(root1, cur->element);
			cur = cur->next;
			i++;
		}
		while(cur != NULL){
			insertAtEnd(root2, cur->element);
			cur = cur->next;
		}
	}else{
		node *cur = root;
		node *prev = root;
		while( (i < n1) && (cur->next != NULL) ){
			cur = cur->next;
			i++;
		}
		// printf("%d\n", i);
		// printf("%s\n", cur->element.model);
		if(i <  n1){
			printf("Khong ton tai position %d\n", n1);
			return;
		}
		i = 0;
		while(prev->next != cur) prev = prev->next;
		while( (i< n2) && (cur != NULL) ){
			insertAtEnd(root1, cur->element);
			cur = cur->next;
			i++;
		}
		node *p = root;
		while(p != prev->next){
			insertAtEnd(root2, p->element);
			p = p->next;
		}
		while(cur!= NULL){
			insertAtEnd(root2, cur->element);
			cur = cur->next;
		}
	}
	
}

int countList(node *root){
	node *cur = root;
	int count = 0;
	while(cur != NULL){
		count++;
		cur = cur->next;
	}
	return count;
}




// elementtype readNode(){
// 	elementtype tmp;
// 	printf("\tpress model: ");
// 	gets(tmp.model);
// 	printf("\tpress memory: ");
// 	gets(tmp.memory);
// 	printf("\tpress screen: ");
// 	gets(tmp.screen);
// 	printf("\tpress price: ");
// 	gets(tmp.price);
// 	return tmp;
// }

// node *findCur(node *root){
// 	node *cur = root;
// 	printf("Enter model current: ");
// 	char model[15];
// 	getchar();
// 	gets(model);
// 	while(strcasecmp(cur->element.model, model) != 0){
// 		cur = cur->next;
// 	}
// 	return cur;
// }


















