// Bai tap tong hop chuc nang
// Trong cac function insert can phai node **cur de thay doi gia tri cua cur sau moi lan insert
// VD: iphone x => 1 => 2 hoac 2 => 1 => iphone x
// Su dung library doubleLinkedList.h ( tong hop cac chuc nang )
//Su dung case 2 de in cac truong hop cua case khac
//case 4 case 5 check position
//case 6 find current, khong co thi return NULL
//case 11 neu n2>(list con lai) thi chia list1 la tu n1->end
//fin = phoneDB.dat fout = phoneDBout.dat
//Muon xoa tat ca model 1 lan thi can co model[] lam trung gian luu tru element.model
//Bo sung case 9 (search move to top) va case 10 (search transpose)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../doubleLinkedList.h"
#define max 100

int menu(void);
void readDatToList(FILE *fin, node **root, node **tail);
void printList(node *root, node *tail);
node *findCur(node **root, node **tail);
elementtype readNode(void);
void updateCur(node **root, node **tail, node *cur);
void saveToFile(FILE *fout, node **root, node **tail);
void updateTranspose(node **root, node **tail, node	*cur);
void updateMoveToTop(node **root, node **tail, node *cur);

int main(int argc, char *argv[]){

	int selec, case3, case1 = 0, case11 = 0;
	FILE *fin, *fout;
	node *root = NULL, *tail = NULL, *cur = NULL;
	int count;
	node *root1 = NULL, *root2 = NULL;
	node *tail1 = NULL, *tail2 = NULL;
	int n1, n2;
	char model[max];

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
					readDatToList(fin, &root, &tail);
					case1 = 1;
				}else{
					freeList(&root, &tail);
					readDatToList(fin, &root, &tail);
				}
				break;
			case 2:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				printList(root, tail);
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
							cur = findCur(&root, &tail);
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
								insertBeforeCurrent(&root, &tail, &cur, readNode());
							}
							puts("\t*Insert before current perfect");
							puts("========================================");
							// printList(root);
							break;
						case 2:
							cur = findCur(&root, &tail);
							if(cur == NULL){
								printf("Khong xac dinh duoc current\n");
								break;
							}
							printf("Nhap so luong: ");
							scanf("%d", &count);
							getchar();
							for(int i =0; i< count; i++){
								printf("***Nhap phone %d: \n", i+1);
								insertAfterCurrent(&root, &tail, &cur, readNode());
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
				getchar();
				puts("Press phone: ");
				insertAtPosition(&root, &tail, readNode(), count);
				
				break;
			case 5:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				printf("Press position: ");
				scanf("%d", &count);
				getchar();
				deleteAtPosition(&root, &tail, count);
				break;
			case 6:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				cur = findCur(&root, &tail);
				if(cur == NULL){
					puts("Khong xac dinh current");
					break;
				}
				strcpy(model, cur->element.model);		//them model de luu element.model cua cur, neu khong thi delete khong triet de
				while(cur != NULL){
					if(strcasecmp(cur->element.model, model) == 0){
						deleteCurrent(&root, &tail, cur);
					}
					cur = cur->next;
				}
				puts("Delete current perfect!");
				break;
			case 7:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				deleteFirst(&root, &tail);
				puts("Delete first perfect!");
				// printList(root);
				break;
			case 8:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				cur = findCur(&root, &tail);
				if(cur == NULL){
					printf("Khong co model phu hop\n");
					break;
				}
				updateCur(&root, &tail, cur);
				break;
			case 9:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				cur = findCur(&root, &tail);
				if(cur == NULL){
					printf("Khong co model phu hop\n");
					break;
				}
				updateMoveToTop(&root, &tail, cur);
				// printList(root, tail);
				break;
			case 10:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				cur = findCur(&root, &tail);
				if(cur == NULL){
					printf("Khong co model phu hop\n");
					break;
				}
				updateTranspose(&root, &tail, cur);
				// printList(root, tail);
				break;
			case 11:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				if(case11 == 0){
					printf("Enter position: ");
					scanf("%d", &n1);
					printf("Enter number: ");
					scanf("%d", &n2);
					splitList(root, tail, &root1, &tail1, &root2, &tail2, n1, n2);
					puts("***Sub-List 1: ");
					printList(root1, tail2);
					puts("***Sub-List 2: ");
					printList(root2, tail2);
					printf("***List source: \n");
					printList(root, tail);
					case11 = 1;
				}else{
					freeList(&root1, &tail1);
					freeList(&root2, &tail2);
					printf("Enter position: ");
					scanf("%d", &n1);
					printf("Enter number: ");
					scanf("%d", &n2);
					splitList(root, tail, &root1, &tail1, &root2, &tail2, n1, n2);
					puts("***Sub-List 1: ");
					printList(root1, tail1);
					puts("***Sub-List 2: ");
					printList(root2, tail2);
					printf("***List source: \n");
					printList(root, tail);	
				}
				break;
			case 12:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				reverseList(&root, &tail);
				printList(root, tail);
				break;
			case 13:
				if(case1 == 0){
					printf("Don't run case 1!\nRun again!\n");
					break;
				}
				saveToFile(fout, &root, &tail);
				break;
			case 14:
				puts("Quit!!!");
				break;
			default:
				puts("Enter error, enter again");
				break;
		}
	}while(selec != 14);

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
	puts("9.Search move to top");
	puts("10.Search transpose");
	puts("11.Divide and Extract");
	puts("12.Reverse list");
	puts("13.Save to file");
	puts("14.Quit");
	int n;
	printf("Enter selection: ");
	scanf("%d", &n);
	puts("=============================");
	return n;
}

void readDatToList(FILE *fin, node **root, node **tail){
	elementtype phoneDB[max];
	int irc;
	fseek(fin, 0*sizeof(telephone), SEEK_SET);
	irc = fread(phoneDB, sizeof(telephone), max, fin);
	printf("File co %d phan tu\n", irc);
	int i =0;
	while(i < irc){
		insertAtEnd(root, tail, phoneDB[i]); 
		i++;
	}
}
node *findCur(node **root, node **tail){
	node *cur = *root;
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

void updateCur(node **root, node **tail, node *cur){
	node *new = makeNewNode(readNode());
	if(cur == *root){
		new->next = (*root)->next;
		(*root)->next->prev = new;
		free(*root);
		*root = new;
		puts("Update perfect!");
		return;
	}
	if(cur == *tail){
		(*tail)->prev->next = new;
		new->prev = (*tail)->prev;
		free(*tail);
		*tail = new;
		puts("Update perfect!");
		return;
	}
	new->next = cur->next;
	cur->next->prev = new;
	new->prev = cur->prev;
	cur->prev->next = new;
	free(cur);
	puts("Update perfect!");
}

void saveToFile(FILE *fout, node **root, node **tail){
	fseek(fout, 0*sizeof(elementtype), SEEK_SET);
	elementtype phoneDB[max];
	int i =0, irc;
	node *cur = *root;
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

void printList(node *root, node *tail){
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
	// printf("\n%-3d%-15s%-10s%-10s%-20s\n", i, tail->element.model, tail->element.memory, tail->element.screen, tail->element.price);

}

void updateTranspose(node **root, node **tail, node	*cur){  //tim kiem va doi len vi tri truoc ( doi value ) 
	node *new = makeNewNode(readNode());
	if(*root == NULL) return;
	// while(strcasecmp(tmp->element.model,cur->element.model) != 0 && tmp != NULL){
	// 	tmp = tmp->next;
	// }

	if(cur == *root){
		deleteFirst(root, tail);
		new->next = *root;
		(*root)->prev = new;
		*root = new;
		return;
	}
	if(cur == *tail){
		(*tail)->element = (*tail)->prev->element;
		(*tail)->prev->element = new->element;
		return;
	}
		// new->next = cur->next;
		// cur->next->prev = new;
		// new->prev = cur->prev;
		// cur->prev->next = new;
	cur->element = cur->prev->element;
	cur->prev->element = new->element;
}

void updateMoveToTop(node **root, node **tail, node *cur){	//tiem kiem va doi len vi tri dau 
	node *new = makeNewNode(readNode());
	if(*root == NULL) return;
	if(cur == *root){
		cur->element = new->element;
		return;
	}
	deleteCurrent(root, tail, cur);
	new->next = *root;
	(*root)->prev = new;
	*root = new;
}










