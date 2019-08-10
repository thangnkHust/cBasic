//Bai tong hop chuc nang, tong hop function from singleLinkedList.h
//Su dung case 2 de in cac truong hop cua case khac
//case 4 case 5 check position
//case 6 find current, khong co return NULL
//fin = phoneDB.dat fout = phoneDBout.dat
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../singleLinkedList.h"
#define max 100

// typedef struct telephone{
// 	char model[15];
// 	char memory[10];
// 	char screen[10];
// 	char price[20];
// }telephone;

// typedef telephone elementtype;

// typedef struct node node;

// typedef struct node{
// 	elementtype element;
// 	struct node *next;
// };


int menu(void);
node *readDatToList(FILE *fin, node *root);
void printList(node *root);
node *findCur(node *root);
elementtype readNode(void);
node *updateCur(node *root, node *cur);
void saveToFile(FILE *fout, node *root);

int main(int argc, char *argv[]){

	int selec, case3, case1 = 0, case9 = 0;
	FILE *fin, *fout;
	node *root = NULL, *cur = NULL;
	int count;
	node *root1 = NULL, *root2 = NULL;
	int n1, n2;

	if(argc != 3){
		printf("Error argument\nSyntax correct: %s <sourceFile> <fileOut>\n", argv[0]);
		return 0;
	}

	if((fin = fopen(argv[1], "rb")) == NULL){
		printf("Can not open file %s\n", argv[1]);
		return 0;
	}
	if((fout = fopen(argv[2], "wb")) == NULL){
		printf("Can not open file %s\n", argv[2]);
		return 0;	
	}

	do{
		selec = menu();
		switch(selec){
			case 1:
				if(case1 == 0){
					root = readDatToList(fin, root);	
					case1 = 1;
				}else{
					root = freeList(root);
					root = readDatToList(fin, root);
				}
				break;
			case 2:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				printList(root);
				break;
			case 3:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				do{
					puts("\t1.Insert before current");
					puts("\t2.Insert after current");
					puts("\t3.Exit case 3");
					printf("\tPress: ");
					scanf("%d", &case3);
					// getchar();
					switch(case3){
						case 1:
							cur = findCur(root);
							// printf("%s\n", cur->element.model);
							if(cur == NULL){
								printf("Khong xac dinh duoc current\n");
								break;
							}
							printf("Nhap so luong: ");
							scanf("%d", &count);
							getchar();
							for(int i =0; i< count; i++){
								printf("***Nhap phone %d: \n", i+1);
								// elementtype e = readNode();
								// printf("%s-%s-%s-%s", e.model, e.memory, e.screen, e.price);
								root = insertBeforeCurrent(root, cur, readNode());
							}
							puts("\t*Insert before current perfect");
							puts("========================================");
							// printList(root);
							break;
						case 2:
							cur = findCur(root);
							if(cur == NULL){
								printf("Khong xac dinh duoc current\n");
								break;
							}
							printf("Nhap so luong: ");
							scanf("%d", &count);
							getchar();
							for(int i =0; i< count; i++){
								printf("***Nhap phone %d: \n", i+1);
								root = insertAfterCurrent(root, cur, readNode());
							}
							puts("\t*Insert after current perfect");
							puts("========================================");
							break;
						case 3:
							break;
						default:
							puts("Press error!");
							break;
					}
				}while(case3 != 3);
				break;
			case 4:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				printf("Press position: ");
				scanf("%d", &count);
				if(count > countList(root)-1){
					puts("Don't have position!");
					break;
				}
				getchar();
				puts("Press phone: ");
				root = insertAtPosition(root, readNode(), count);
				break;
			case 5:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				printf("Press position: ");
				scanf("%d", &count);
				getchar();
				root = deleteAtPosition(root, count);
				break;
			case 6:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				cur = findCur(root);
				if(cur == NULL){
					puts("Khong xac dinh current");
					break;
				}
				root = deleteCurrent(root, cur);
				puts("Delete current perfect!");
				// while((cur = findCur(root)) != NULL){
				// 	root = deleteCurrent(root, cur);
				// 	printList(root);
				// }
				break;
			case 7:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				root = deleteFirst(root);
				puts("Delete first node perfect!");
				// printList(root);
				break;
			case 8:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				cur = findCur(root);
				if(cur == NULL){
					printf("Khong co model phu hop\n");
					break;
				}
				root = updateCur(root, cur);
				puts("Update perfect!");
				break;
			case 9:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				if(case9 == 0){
					printf("Enter position: ");
					scanf("%d", &n1);
					printf("Enter number: ");
					scanf("%d", &n2);
					splitList(root, &root1, &root2, n1, n2);
					puts("***Sub-List 1: ");
					printList(root1);
					puts("***Sub-List 2: ");
					printList(root2);
					printf("***List source: \n");
					printList(root);	
					case9 = 1;
				}else{
					root1 = freeList(root1);
					root2 = freeList(root2);
					printf("Enter position: ");
					scanf("%d", &n1);
					printf("Enter number: ");
					scanf("%d", &n2);
					splitList(root, &root1, &root2, n1, n2);
					puts("***Sub-List 1: ");
					printList(root1);
					puts("***Sub-List 2: ");
					printList(root2);
					printf("***List source: \n");
					printList(root);	
				}
				break;
			case 10:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				root = reverseList(root);
				printList(root);
				break;
			case 11:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				saveToFile(fout, root);
				break;
			case 12:
				puts("Quit!!!");
				break;
			default:
				puts("Enter error, enter again");
				break;
		}
	}while(selec != 12);

}

int menu(){
	puts("============MENU===========");
	puts("1.Import from phoneDB.dat");
	puts("2.Display");
	puts("3.Add new phone");
	puts("4.Insert at position");
	puts("5.Delete at position");
	puts("6.Delete current");
	puts("7.Delete First");
	puts("8.Search and update");
	puts("9.Divide and Extract");
	puts("10.Reverse list");
	puts("11.Save to file");
	puts("12.Quit");
	int n;
	printf("Enter selection: ");
	scanf("%d", &n);
	puts("=============================");
	return n;
}

node *readDatToList(FILE *fin, node *root){
	elementtype phoneDB[max];
	int irc;
	fseek(fin, 0*sizeof(telephone), SEEK_SET);
	irc = fread(phoneDB, sizeof(telephone), max, fin);
	printf("File co %d phan tu\n", irc);
	int i =0;
	while(i < irc){
		root = insertAtEnd(root, phoneDB[i]); 
		i++;
	}
	return root;
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

node *findCur(node *root){
	node *cur = root;
	printf("Enter model current: ");
	char model[15];
	getchar();
	gets(model);
	while(cur != NULL){
		if(strcasecmp(cur->element.model, model) == 0) break;
		cur = cur->next;
	}
	return cur;
}

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

node *updateCur(node *root, node *cur){
	node *new = makeNewNode(readNode());
	if(cur == root){
		new->next = root->next;
		free(root);
		return new;
	}
	node *prev = root;
	while(prev->next != cur) prev = prev->next;
	new->next = cur->next;
	prev->next = new;
	free(cur);
	return root;
}

void saveToFile(FILE *fout, node *root){
	fseek(fout, 0*sizeof(elementtype), SEEK_SET);
	elementtype phoneDB[max];
	int i =0, irc;
	node *cur = root;
	while(cur != NULL){
		strcpy(phoneDB[i].model, cur->element.model);
		strcpy(phoneDB[i].memory, cur->element.memory);
		strcpy(phoneDB[i].screen, cur->element.screen);
		strcpy(phoneDB[i].price, cur->element.price);
		i++;
		cur = cur->next;
	}
	irc = fwrite(phoneDB, sizeof(elementtype), i, fout);
	printf("Ghi thanh cong vao file %d phan tu\n", irc);
}

















