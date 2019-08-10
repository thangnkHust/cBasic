typedef struct{
	char model[15];
	char memory[10];
	char screen[10];
	char price[20];
}telephone;

typedef telephone elementtype;

typedef struct node{
	elementtype element;
	struct node *prev;
	struct node *next;
}node;

node *makeNewNode(elementtype e){
	node *new = (node*)malloc(sizeof(node));
	new->element = e;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

void insertAtHead(node **root, node **tail, elementtype e){
	node *new = makeNewNode(e);
	if(*root == NULL){
		*root = new;
		*tail = new;
	} 
	else{
		new->next = *root;
		(*root)->prev = new;
		*root = new;
	}
}

void insertAtEnd(node **root, node **tail, elementtype e){
	node *new = makeNewNode(e);
	if(*root == NULL){
		*root = new;
		*tail = new;
	}else{
		(*tail)->next = new;
		new->prev = *tail;
		*tail = new;
	}
}

void insertBeforeCurrent(node **root, node **tail, node **cur, elementtype e){
	node *new = makeNewNode(e);
	if(*cur == *root){
		(*cur)->prev = new;
		new->next = *cur;
		*cur = new;
		*root = new;
	}else{
		(*cur)->prev->next = new;
		new->prev = (*cur)->prev;
		new->next = *cur;
		(*cur)->prev = new;
		*cur = new;
	}
}

void insertAfterCurrent(node **root, node **tail, node **cur, elementtype e ){
	node *new = makeNewNode(e);
	if((*cur) == *tail){
		(*tail)->next = new;
		new->prev = *tail;
		*tail = new;
		(*cur) = new;
	}else{
		new->next = (*cur)->next;
		(*cur)->next->prev = new;
		(*cur)->next = new;
		new->prev = (*cur);
		(*cur) = new;
	}
}

void insertAtPosition(node **root, node **tail, elementtype e, int n){
	int i = 0;
	if(n < 0){
		printf("Don't have position %d\n", n);
		return;
	}
	if(n == 0 || root == NULL){
		insertAtHead(root, tail, e);
		puts("Insert at position perfect!");
	}else{
		node *cur = *root;
		while((i< n-1) && (cur->next != NULL)){
			i++;
			cur = cur->next;
		}
		if(i < n-1){
			printf("Don't have position %d\n", n);
			return;
		}	
		insertAfterCurrent(root, tail, &cur, e);
		puts("Insert at position perfect!");
	}
}

void deleteFirst(node **root, node **tail){
	node *tmp = *root;
	*root = (*root)->next;
	free(tmp);
}

void deleteEnd(node **root, node **tail){
	node *tmp = *tail;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	free(tmp);
}

void deleteCurrent(node **root, node **tail, node *cur){
	if(*root == NULL){
		printf("List empty\n");
		return;
	}
	if(cur == *root){
		deleteFirst(root, tail);
	}else{
		if(cur == *tail)
			deleteEnd(root, tail);
		else{
			cur->next->prev = cur->prev;
			cur->prev->next = cur->next;
			free(cur);
		}
	}
}

void deleteAtPosition(node **root, node **tail, int n){
	int i =0;
	if(n < 0){
		printf("Don't have position %d\n", n);
		return;
	}
	if(n == 0){
		deleteFirst(root, tail);
	}
	node *cur = *root;
	while((i < n) && (cur->next != NULL)){
		cur = cur->next;
		i++;
	}
	if(i == n){
		deleteCurrent(root, tail, cur);
		puts("Delete at position perfect!");
		return;
	}
	printf("Don't have position!\n");
}

void freeList(node **root, node **tail){		//free list, can return root de truyen gia tri ra khoi function
	node *to_free;
	to_free = *root;
	while(to_free != NULL){
		*root = (*root)->next;
		free(to_free);
		to_free = *root;
	}
}

void reverseList(node **root, node **tail){
	node *cur = NULL, *curtail = NULL;
	node *a = *root;
	curtail = a;
	cur = a;
	*root = (*root)->next;
	(cur)->prev = NULL;
	(curtail)->next = NULL;
	while(*root != NULL){
		node *tmp = *root;
		*root = (*root)->next;
		tmp->next = cur;
		(cur)->prev = tmp;
		cur = tmp;
	}
	*root = cur;
	*tail = curtail;
}

void reverseListTest(node *root, node *tail, node **cur, node **curtail){
	while(root != NULL){
		node *tmp = root;
		insertAtHead(cur, curtail, tmp->element);
		root = root->next;
	}
}

void splitList(node *root, node *tail, node **root1, node **tail1, node **root2, node **tail2, int n1, int n2){
	int i = 0;
	if(n1 < 0 || n2 < 0){
		printf("Press position error!\n");
		return;
	}
	if(n1 == 0){
		node *cur = root;
		while( (i < n2) && (cur != NULL) ){
			insertAtEnd(root1, tail1, cur->element);
			cur = cur->next;
			i++;
		}
		while(cur != NULL){
			insertAtEnd(root2, tail2, cur->element);
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
			insertAtEnd(root1, tail1, cur->element);
			cur = cur->next;
			i++;
		}
		node *p = root;
		while(p != prev->next){
			insertAtEnd(root2, tail2, p->element);
			p = p->next;
		}
		while(cur!= NULL){
			insertAtEnd(root2, tail2, cur->element);
			cur = cur->next;
		}
	}
	
}







// void printList(node *root){
// 	node *cur = root;
// 	int i =0;
// 	if(cur == NULL){
// 		printf("Loi con tro NULL\n");
// 		return;
// 	}
// 	while(cur != NULL){
// 		printf("%-3d%-15s%-10s%-10s%-20s\n", i, cur->element.model, cur->element.memory, cur->element.screen, cur->element.price);
// 		cur = cur->next;
// 		i++;
// 	}
// }

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
