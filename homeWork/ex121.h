typedef struct{
	int id;
	char country[20];
}team;

typedef team elementtype;

typedef struct node{
	elementtype element;
	struct node *leftChild;
	struct node *rightChild;
}node;

typedef node *treeType;

void initalize(treeType *T){
	*T = NULL;
}

treeType makeNewNode(elementtype e){
	treeType new = (node*)malloc(sizeof(node));
	new->element = e;
	new->leftChild = NULL;
	new->rightChild = NULL;
	return new;
}

int leaf(treeType T){
	if(T != NULL){
		return (T->leftChild == NULL && T->rightChild == NULL);
	}
	return 0;
}

int countTree(treeType T){
	if(T == NULL) return 0;
	return 1 + countTree(T->leftChild) + countTree(T->rightChild);
}

treeType creatFrom2Tree(treeType left, treeType right, elementtype e){
	// creat 1 tree from 2 tree
	treeType new = makeNewNode(e);
	new->leftChild = left;
	new->rightChild = right;
	return new;
}

void insertMostLeft(treeType *T, elementtype e){
	// insert most left on tree T
	treeType new = makeNewNode(e);
	if(*T == NULL) *T= new;
	else{
		treeType tmp = *T;
		while(tmp->leftChild != NULL){
			tmp = tmp->leftChild;
		}
		tmp->leftChild = new;
	}
}

void insertMostRight(treeType *T, elementtype e){
	// insert most right on tree T
	treeType new = makeNewNode(e);
	if(*T == NULL) *T = new;
	else{
		treeType tmp = *T;
		while(tmp->rightChild != NULL){
			tmp = tmp->rightChild;
		}
		tmp->rightChild = new;
	}
}

treeType find(treeType T, elementtype x){
	// find and return node x
	if(T == NULL) return NULL;
	if(strcasecmp(T->element.country, x.country) == 0) return T;
	node *tmp;
	tmp = find(T->leftChild, x);
	if(tmp == NULL)
		tmp = find(T->rightChild, x);
	return tmp;
}

void insertLeft(treeType *T, elementtype x, elementtype e){
	// insert left node x 1 node e
	if(*T == NULL) return;
	node *tmp = find(*T, x);
	if(tmp == NULL) return;
	node *new = makeNewNode(e);
	tmp->leftChild = new;
}

void insertRight(treeType *T, elementtype x, elementtype e){
	// insert rigt node x 1 node e
	if(*T == NULL) return;
	node *tmp = find(*T, x);
	if(tmp == NULL) return;
	node *new = makeNewNode(e);
	tmp->rightChild = new;
}

void preOder(treeType T){
	if(T != NULL){
		printf("%s ", T->element.country);
		preOder(T->leftChild);
		preOder(T->rightChild);
	}
}

void inOder(treeType T){
	if(T != NULL){
		inOder(T->leftChild);
		printf("%s ", T->element.country);
		inOder(T->rightChild);
	}
}

int a = 0;

void postOder(treeType T){
	if(T != NULL){
		postOder(T->leftChild);
		postOder(T->rightChild);
		printf("%s ", T->element.country);
	}
}

void printTree(treeType T){
	if(T == NULL){
		return;
	}
	printf("Nut %s: ", T->element.country);
	if(T->leftChild != NULL){
		printf("%s ", T->leftChild->element.country);
	}
	if(T->rightChild != NULL){
		printf("%s ", T->rightChild->element.country);
	}
	printf("\n");
	printTree(T->leftChild);
	printTree(T->rightChild);
}




