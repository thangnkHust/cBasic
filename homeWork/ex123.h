typedef struct{
	char model[15];
	char memory[10];
	char screen[10];
	char price[20];
}telephone;

typedef telephone keyType;

typedef struct node{
	keyType key;
	struct node *leftChild;
	struct node *rightChild;
}node;

typedef node *treeType;

void initalize(treeType *T){
	*T = NULL;
}

int emptyTree(treeType T){
	return T == NULL;
}

treeType leftChild(treeType T){
	if(T != NULL) return T->leftChild;
	return NULL;
}

treeType rightChild(treeType T){
	if(T != NULL) return T->rightChild;
	return NULL;
}

treeType makeNewNode(keyType e){
	treeType new = (node*)malloc(sizeof(node));
	new->key = e;
	new->leftChild = NULL;
	new->rightChild = NULL;
	return new;
}

int leaf(treeType T){
	if(T != NULL){
		return (leftChild(T) == NULL && rightChild(T) == NULL);
	}
	return 0;
}

void printTree(treeType T){
	if(emptyTree(T)){
		return;
	}
	printf("%-15s%-10s%-10s%-20s\n", T->key.model, T->key.memory, T->key.screen, T->key.price);
	if(T->leftChild != NULL){
		printf("%-15s%-10s%-10s%-20s\n", T->leftChild->key.model, T->leftChild->key.memory, T->leftChild->key.screen, T->leftChild->key.price);
	}
	if(T->rightChild != NULL){
		printf("%-15s%-10s%-10s%-20s\n", T->rightChild->key.model, T->rightChild->key.memory, T->rightChild->key.screen, T->rightChild->key.price);
	}
	printf("\n");
	printTree(T->leftChild);
	printTree(T->rightChild);

}

int countTree(treeType T){
	if(emptyTree(T)) return 0;
	return 1 + countTree(leftChild(T)) + countTree(rightChild(T));
}

treeType creatFrom2Tree(treeType left, treeType right, keyType e){
	treeType new = makeNewNode(e);
	new->leftChild = left;
	new->rightChild = right;
	return new;
}

// void preOder(treeType T){
// 	if(T != NULL){
// 		printf("%d ", T->key);
// 		preOder(T->leftChild);
// 		preOder(T->rightChild);
// 	}
// }

void inOder(treeType T){
	if(T != NULL){
		inOder(T->leftChild);
		printf("%-15s%-10s%-10s%-20s\n", T->key.model, T->key.memory, T->key.screen, T->key.price);
		inOder(T->rightChild);
	}
}

// void postOder(treeType T){
// 	if(T != NULL){
// 		postOder(T->leftChild);
// 		postOder(T->rightChild);
// 		printf("%d ", T->key);
// 	}
// }

void insertNode(treeType *T, keyType k){
	if(*T == NULL){
		*T = (node*)malloc(sizeof(node));
		(*T)->key = k;
		(*T)->rightChild = NULL;
		(*T)->leftChild = NULL;
	}else{
		if(strcasecmp(k.model, (*T)->key.model) <= 0) insertNode(&((*T)->leftChild), k);
		else if( strcasecmp(k.model, (*T)->key.model) > 0) insertNode(&((*T)->rightChild), k);
	}
}

treeType search(treeType T, keyType k){
	if(T == NULL) return NULL;
	if(strcasecmp(T->key.model, k.model) == 0) return T;
	if(strcasecmp(k.model, (T)->key.model) > 0) return search(T->rightChild, k);
	return search(T->leftChild, k);
}

keyType deleteMin(treeType *T){
	keyType k;
	if((*T)->leftChild == NULL){
		k = (*T)->key;
		*T = (*T)->rightChild;
		return k;
	}
	return deleteMin(&(*T)->leftChild);
}

void deleteNode(treeType *T, keyType x){
	if(*T != NULL){
		if(strcasecmp(x.model, (*T)->key.model) < 0) deleteNode(&(*T)->leftChild, x);
		else
			if(strcasecmp(x.model, (*T)->key.model) > 0) deleteNode(&(*T)->rightChild, x);
			else if((*T)->rightChild == NULL && (*T)->leftChild == NULL) (*T) = NULL;
			else if((*T)->rightChild == NULL) *T = (*T)->leftChild;
			else if((*T)->leftChild == NULL) *T = (*T)->rightChild;
			else (*T)->key = deleteMin(&(*T)->rightChild);
	}
}





