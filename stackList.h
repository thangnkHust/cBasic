typedef struct ngoac{
	int line;
	char c;
}ngoac;

typedef	ngoac elementtype;

typedef struct node{
	elementtype element;
	struct node *next;
}node;

typedef node stackType;

void initalize(stackType **root){
	*root = NULL;
}

stackType *makeNewNode(elementtype e){
	stackType *new = (stackType*)malloc(sizeof(stackType));
	new->element = e;
	new->next = NULL;
	return new;
}

int empty(stackType **root){
	if(*root == NULL) return 1;
	return 0;
}

void push(stackType **root, elementtype e){
	stackType *new = makeNewNode(e);
	if(*root == NULL){
		*root = new;
	}else{
		new->next = *root;
		*root = new;
	}
}

elementtype pop(stackType **root){
	elementtype e;
	stackType *temp;
   	if(empty(root)){
      	printf("Stack is empty!\n");
     	exit(0);
   	}
   	e = (*root)->element;
   	temp = *root;
   	*root = (*root)->next;
   	free(temp);
   	return e;
}

elementtype peek(stackType **root){
	if(empty(root)){
		printf("Stack is empty!\n");
		exit(0);
	}
	return (*root)->element;
}










