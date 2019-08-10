// Dung 2 stack ( int , char element[] )
// pop => push (can chuyen doi so nguyen -> luu vao stack S3 -> luu lai vao string)
// Sua trong stackList.h ve typedef int elementtype
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stackList.h"
#define max 100

int menu(void);

typedef char elementtype_t;

typedef struct node_t{
	elementtype_t element[max];
	struct node_t *next;
}node_t;

typedef node_t stackList;

void initalizeList(stackList **head){
	*head = NULL;
}

stackList *makeNewNode_t(elementtype_t e[]){
	stackList *p = (stackList*)malloc(sizeof(stackList));
	// p->element = e;
	strcpy(p->element, e);
	p->next = NULL;
	return p;
}

int emptyList(stackList **head){
	if(*head == NULL) return 1;
	return 0;
}

void pushList(stackList **head, elementtype_t e[]){
	stackList *p = makeNewNode_t(e);
	if(*head == NULL){
		*head = p;
	}else{
		p->next = *head;
		*head = p;
	}
}

void popList(stackList **head){
	// elementtype_t *e;
	stackList *temp;
   	if(emptyList(head)){
      	printf("The stack is empty, can not pop, error\n");
     	exit(0);
   	}
   	// strcpy(e, (*head)->element);
   	temp = *head;
   	*head = (*head)->next;
   	free(temp);
   	// return e;
}

elementtype_t *peekList(stackList **head){
	if(emptyList(head)){
		printf("The stack is empty, can not seek, error\n");
		exit(0);
	}
	return (*head)->element;
}

int main(){

	int selec;
	int case1;
	int case3;
	int case11;
	char tmp[] = "pop";
	char a[max];
	int i =0;

	stackType *S1;
	initalize(&S1);
	stackList *S2;
	initalizeList(&S2);
	stackType *S3;
	initalize(&S3);

	do{
		selec = menu();
		switch(selec){
			case 1:
				printf("Nhap so can push: ");
				scanf("%d", &case1);
				push(&S1, case1);
				pushList(&S2, tmp);
				case11 = 1;
				// puts(peekList(&S2));
				break;
			case 2:
				if(case11 == 0){
					printf("Don't run case 1\nRun case 1!\n");
					break;
				}
				printf("Top is: %d\n", peek(&S1));
				break;
			case 3:
				// a = (char*)malloc(5*sizeof(char));
				// char a[5];
				if(case11 == 0){
					printf("Don't run case 1\nRun case 1!\n");
					break;
				}
				case3 = pop(&S1);
				while(case3 != 0){
					push(&S3, case3%10);
					case3 = case3/10;
				}
				while(!empty(&S3)){
					a[i++] = pop(&S3) + '0';
					// a++;
				}
				a[i] = '\0';
				i =0;
				pushList(&S2, a);
				printf("Pick complete, check case 2!\n");
				// puts(peekList(&S2));
				break;
			case 4:
				if(case11 == 0){
					printf("Don't run case 1\nRun case 1!\n");
					break;
				}
				if(strcmp(peekList(&S2), tmp) == 0){
					popList(&S2);
					pop(&S1);
					// puts(peekList(&S2));
				}else{
					push(&S1, atoi(peekList(&S2)));
					popList(&S2);
					// puts(peekList(&S2));
				}
				printf("Undo complete, check case 2!\n");
				break;
			case 5:
				while(!empty(&S1)){
					pop(&S1);
				}
				while(!emptyList(&S2)){
					popList(&S2);
				}
				while(!empty(&S3)){
					pop(&S3);
				}
				puts("Exit!!!");
				break;
			default:
				printf("Enter error!!!\n");
				break;
		}
	}while(selec != 5);

}

int menu(){
	puts("=============MENU============");
	puts("1.Add 1 integer to stack");
	puts("2.See top");
	puts("3.Pick 1 element from stack");
	puts("4.Undo");
	puts("5.Exit!!!");
	int n;
	printf("Enter selection: ");
	scanf("%d", &n);
	puts("============================");
	return n;
}



