#include <stdio.h>
#include <stdlib.h>
#include "../doubleLinkedList.h"

elementtype readNode(){
	elementtype tmp;
	printf("\tpress model: ");
	gets(tmp.model);
	printf("\tpress memory: ");
	gets(tmp.memory);
	printf("\tpress screen: ");
	gets(tmp.screen);
	printf("\tpress price: ");
	gets(tmp.price);
	return tmp;
}

void printList(node *root){
	node *cur = root;
	int i =0;
	if(cur == NULL){
		printf("Loi con tro NULL\n");
		return;
	}
	while(cur != NULL){
		printf("%-3d%-15s%-10s%-10s%-20s\n", i, cur->element.model, cur->element.memory, cur->element.screen, cur->element.price);
		cur = cur->next;
		i++;
	}
}


int main(){

	node *root = NULL;
	node *tail = NULL;
	elementtype e;
	// e = readNode();
	insertAtHead(&root, &tail, readNode());
	insertAtHead(&root, &tail, readNode());
	insertAtEnd(&root, &tail, readNode());
	printList(root);
	deleteFirst(&root, &tail);
	printList(root);
}






