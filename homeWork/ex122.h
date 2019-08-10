typedef struct{
	char name[50];
}fullname;

typedef fullname keyType;

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
	printf("Nut %s: ", T->key.name);
	if(T->leftChild != NULL){
		printf("%s ", T->leftChild->key.name);
	}
	if(T->rightChild != NULL){
		printf("%s ", T->rightChild->key.name);
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

void preOder(treeType T){
	if(T != NULL){
		printf("%s", T->key.name);
		preOder(T->leftChild);
		preOder(T->rightChild);
	}
}

void inOder(treeType T){
	if(T != NULL){
		inOder(T->leftChild);
		printf("\t%s\n", T->key.name);
		inOder(T->rightChild);
	}
}

void postOder(treeType T){
	if(T != NULL){
		postOder(T->leftChild);
		postOder(T->rightChild);
		printf("%s", T->key.name);
	}
}



keyType deleteMin(treeType *T){
	keyType k;
	if((*T)->leftChild == NULL){
		strcpy(k.name ,(*T)->key.name);
		*T = (*T)->rightChild;
		return k;
	}
	return deleteMin(&(*T)->leftChild);
}

// void deleteNode(treeType *T, keyType x){
// 	if(*T != NULL){
// 		if(x < (*T)->key->name) deleteNode(&(*T)->leftChild, x);
// 		else
// 			if(x > (*T)->key->name) deleteNode(&(*T)->rightChild, x);
// 			else if((*T)->rightChild == NULL && (*T)->leftChild == NULL) (*T) = NULL;
// 			else if((*T)->rightChild == NULL) *T = (*T)->leftChild;
// 			else if((*T)->leftChild == NULL) *T = (*T)->rightChild;
// 			else (*T)->key->name = deleteMin(&(*T)->rightChild);
// 	}
// }





