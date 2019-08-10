#include <stdio.h>
#include <stdlib.h>
#include "../queueList.h"
#define max 100

int menu(void);

int main(){

	int selec;
	int memory, parallel;
	int count1 = 0, count2 = 0;
	elementtype e;
	queueType Q1, Q2;
	node *tmp1;
	node *tmp2;
	initalize(&Q1);
	initalize(&Q2);

	printf("Memory capacity(MB): ");
	scanf("%d", &memory);
	int temp = memory;
	printf("Number of parallel process: ");
	scanf("%d", &parallel);
	do{
		selec = menu();
		switch(selec){
			case 1:
				if(count1 >= parallel){
					puts("Full parallel process!");
				}
				printf("Size of memory? ");
				scanf("%d", &e.memory);
				if(e.memory > temp){
					printf("Enter memory error\n ( > %d)\n", temp);
					break;
				}
				printf("Program ID? ");
				scanf("%d", &e.id);
				if(e.memory <= memory && count1 < parallel){
					enQueue(&Q1, e);
					count1++;
					memory = memory - e.memory;
				}else{
					enQueue(&Q2, e);
					count2++;
				}
				break;
			case 2:
				if(!empty(&Q1)){
					e = deQueue(&Q1);
					memory += e.memory;
					count1--;
					if(!empty(&Q2)){
						if(peekQueue(&Q2).memory <= memory){
							enQueue(&Q1, peekQueue(&Q2));
							memory -= deQueue(&Q2).memory;
						}
					}
					puts("Kill program complete");
				}else{
					puts("Program is empty!");
					break;
				}
				break;
			case 3:
				tmp1 = Q1.root;
				tmp2 = Q2.root;
				if(tmp1 == NULL){
					printf("OS khong xu ly du lieu nao!\n");
					break;
				}
				printf("%-10s%-10s%-10s\n", "ID", "Memory", "Queue");
				while(tmp1 != NULL){
					printf("%-10d%-10d\n", tmp1->element.id, tmp1->element.memory);
					tmp1 = tmp1->next;
				}
				while(tmp2 != NULL){
					printf("%-10d%-10s%-10d\n", tmp2->element.id, " ", tmp2->element.memory);
					tmp2 = tmp2->next;
				}
				break;
			case 4:
				while(!empty(&Q1)){
					deQueue(&Q1);
				}
				while(!empty(&Q2)){
					deQueue(&Q2);
				}
				puts("Exit!!!");
				break;
			default:
				puts("Enter error!!!");
				break;
		}
	}while(selec != 4);

}

int menu(){
	puts("============MENU==========");
	puts("1.Creat a new program");
	puts("2.Kill a program");
	puts("3.Show the status");
	puts("4.Exit!!!");
	int n;
	printf("Enter selection: ");
	scanf("%d", &n);
	return n;
}







