// Single linked list
// *khai bao cau truc struct
// *make node: toa 1 node 
// *display node: in ra danh sach
// *insert: cac ham dung de chen vao dau, cuoi day, truoc current, sau current
// *remove: xoa phan tu dau tien, xoa cac phan tu khac
// *free list: free list
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char name[20];
	char tel[11];
	char email[25];
}adress;

typedef adress elementtype;

typedef struct node node;

typedef struct node{ 
 	elementtype addr; 
  	node* next; 
}; 

node *root, *cur, *prev;		//root tro den dau list, cur tro den phan tu hien thoi, prev tro den phan tu truoc phan tu hien thoi

adress readNode(){
	elementtype tmp;
	printf("Nhap name: ");
	gets(tmp.name);
	printf("Nhap tel: ");
	gets(tmp.tel);
	printf("Nhap email: ");
	gets(tmp.email);
	return tmp;
}

node *makeNewNode(elementtype addr){
	node *new = (node*)malloc(sizeof(node));
	new->addr = addr;
	new->next = NULL; 
	return new;
}

void displayNode(node *p){
	if(p == NULL){
		printf("Loi con tro NULL\n");
		return;
	}
	while(p != NULL){
		elementtype tmp = p->addr;
		printf("%-20s\t%-15s\t%-30s\t%p\n", tmp.name, tmp.tel, tmp.email, p->next);
		p = p->next;
	}
}

node *insertFirst(node *f, elementtype addr){
	node *p = makeNewNode(addr);
	p->next = f;
	f = p;
	cur = f;
	return f;
}

void insertAfterCurrent(elementtype addr){
	node *new = makeNewNode(addr);
	if(root == NULL){
		root = new;
		cur = root;
	}
	if(cur == NULL){
		printf("do nothing\n");
	}
	new->next = cur->next;
	cur->next = new;
	cur = new;
}

void insertBeforeCurent(elementtype addr){
	node *tmp = root;
	node *new = makeNewNode(addr);
	while(tmp->next != cur && cur != NULL){
		tmp = tmp->next;
	}
	prev = tmp;
	if(root == NULL){
		root = new;
		cur = root;
		prev = NULL;
	}else{
		new->next = cur;
		prev->next = new;
		cur = new;
	}
	
}

node *insertLast(node *f, elementtype addr){
	node *p = makeNewNode(addr);
	if(f == NULL) return p;
	node *q = f;
	while(q->next != NULL){
		q = q->next;
	}
	q->next = p;
	return f;
}

void freeList(){
	node *to_free;
	to_free = root;
	while(to_free != NULL){
		root = root->next;
		free(to_free);
		to_free = root;
	}
}

node *removeFisrt(node *root){
	node *del = root;
	root = root->next;
	free(del);
	return root;
}

node *removeMiddle(node *root){
	char str[20];
	gets(str);
	cur = root;
	while(cur != NULL){
		if(strcmp(str, cur->addr.name) == 0){
			break;
		}
		cur = cur->next;
	}
	if(cur == NULL){
		puts("Khong tim thay");
	}
	prev = root;
	// cur = root->next;
	if(cur == NULL) return root;
	if(cur != root){
		while(prev->next != cur){
			prev = prev->next;
		}
	}
	if(cur == root){
		root = removeFisrt(root);
	}else{
		prev->next = cur->next;
		free(cur);
		cur = prev->next;
	}
	return root;
}

node *reverseList(node *root){
	node *a, *b;
	a = b = NULL;
	while(root != NULL){
		a = root;
		root = root->next;
		a->next = b;
		b = a;
	}
	return b;
}



int main(){
	// root = makeNewNode(readNode());
	cur = root;
	int n;
	printf("Nhap so luong: ");
	scanf("%d", &n);
	getchar();
	for(int i = 0; i< n; i++){
		root = insertFirst(root, readNode());
	}
	displayNode(root);
	printf("\n");

	// insertAfterCurrent(readNode());
	// displayNode(root);

	// insertBeforeCurent(readNode());
	// displayNode(root);

	// root = removeFisrt(root);
	// root = removeMiddle(root);
	root = reverseList(root);
	displayNode(root);

	freeList();
	// displayNode(root);
}

























