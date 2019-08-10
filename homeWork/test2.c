// Mo phong undo dung 2 stack n( int and float )
// neu push => pop ( push(&S2, 0.5))
// neu pop => push ( push(&S2, pop(&S1)))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stackList.h"

typedef float tmp;

typedef struct node_t{
	tmp element;
	struct node_t *next_t;
}node_t;

typedef node_t stackList;

void initalizeList(stackList **head){
	*head = NULL;
}

stackList *makeNewNodeList(tmp e){
	stackList *p = (stackList*)malloc(sizeof(stackList));
	p->element = e;
	p->next_t = NULL;
	return p;
}

int emptyList(stackList **head){
	if(*head == NULL) return 1;
	return 0;
}

void pushList(stackList **head, tmp e){
	stackList *p = makeNewNodeList(e);
	if(*head == NULL){
		*head = p;
	}else{
		p->next_t = *head;
		*head = p;
	}
}

tmp popList(stackList **head){
	tmp e;
	stackList *temp;
   	if(emptyList(head)){
      	printf("The stack is empty, can not pop, error\n");
     	exit(0);
   	}
   	e = (*head)->element;
   	temp = *head;
   	*head = (*head)->next_t;
   	free(temp);
   	return e;
}

tmp peekList(stackList **head){
	if(emptyList(head)){
		printf("The stack is empty, can not seek, error\n");
		exit(0);
	}
	return (*head)->element;
}

int menu(void);

int main(){

	int selec;
	int case1;
	int case4;

	stackType *S1;
	initalize(&S1);
	stackList *S2;
	initalizeList(&S2);

	do{
		selec = menu();
		switch(selec){
			case 1:
				printf("Nhap so can push: ");
				scanf("%d", &case1);
				push(&S1, case1);
				pushList(&S2, 0.5);
				break;
			case 2:
				printf("%d\n", peek(&S1));
				break;
			case 3:
				case4 = pop(&S1);
				// printf("pop: %d", case4 );
				pushList(&S2, case4);
				// printf("S2: %g\n", peekList(&S2));
				break;
			case 4:
				// strcpy(a,peek(&S2));
				if(peekList(&S2) == 0.5){
					pop(&S1);
					// printf("%d\n",peek(&S1));
				}else{
					// printf("S2: %g\n", peekList(&S2));
					push(&S1, popList(&S2));
					// printf("%d\n",peek(&S1));
				}
				break;
			case 5:
				puts("Exit!!!");
				break;
		}
	}while(selec != 5);

}

int menu(){
	puts("=========MENU========");
	puts("1.Them 1 so nguyen vao stack");
	puts("2.Xem dinh");
	puts("3.Lay 1 phan tu khoi stack");
	puts("4.Undo");
	puts("5.Exit!!!");
	int n;
	printf("Enter selection: ");
	scanf("%d", &n);
	return n;
}
