#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100

typedef struct{
	char model[15];
	char memory[10];
	char screen[10];
	char price[20];
}telephone;

typedef struct node{
	telephone phone;
	struct node *next;
}node;

int menu(void);
node * makeNewNode(telephone phone);
node *insertFisrt(node *root, telephone phone);
node *insertLast(node *root, telephone phone);
node *insertAfterCur(node *root, telephone phone);
void printList(node *root);
node *readTextToList(FILE *fin, node *root);
node *readDatToList(FILE *fin, node *root);
node *freeList(node *root);
void searchModel(node *root);
void searchPriceUnder(node *root);
void exportToDat(node *root, FILE *fout);


int main(int argc, char *argv[]){

	if(argc != 3){
		printf("Nhap sai argument\nCu phap dung la: %s <fileText> <fileDat>\n", argv[0]);
		return 0;
	}

	FILE *fin1, *fin2, *fout;

	if((fin1 = fopen(argv[1], "r")) == NULL){
		printf("Can not open file %s\n", argv[1]);
		return 0;
	}
	if((fin2 = fopen(argv[2], "r+b")) == NULL){
		printf("Can not open file %s\n", argv[2]);
		return 0;
	}

	if((fout = fopen("../../file/phoneDBout.dat", "wb")) == NULL){
		printf("Can not open file\n");
		return 0;
	}

	int n;
	node *root1 = NULL;
	node *root2 = NULL;
	int case1 = 0, case2 = 0, case3, case4;
	int count;
	telephone phoneCase4[max];
	do{
		n = menu();
		switch(n){
			case 1:
				if(case1 == 0){
					root1 = readTextToList(fin1, root1);
					case1 = 1;
				}else{
					root1 = freeList(root1);
					root1 = readTextToList(fin1, root1);
				}
				break;
			case 2:
				if(case2 == 0){
					root2 = readDatToList(fin2, root2);
					case2 = 1;
				}else{
					root2 = freeList(root2);
					root2 = readDatToList(fin2, root2);
				}
				break;
			case 4:
				if(case1 == 0 || case2 == 0){
					printf("***Don't run case 1 and case 2\n");
					break;
				}
				do{
					printf("\t1.Insert at head\n\t2.Insert at end\n\t3.Exit case 4\n\tPress: ");
					scanf("%d", &case4);
					switch(case4){
						case 1:
							printf("***Nhap so luong insert: ");
							scanf("%d", &count);
							getchar();
							for(int i =0; i< count; i++){
								printf("***Nhap telephone %d\n", i+1);
								printf("\tNhap model: ");
								gets(phoneCase4[i].model);
								printf("\tNhap memory: ");
								gets(phoneCase4[i].memory);
								printf("\tNhap screen: ");
								gets(phoneCase4[i].screen);
								printf("\tNhap price: ");
								gets(phoneCase4[i].price);
								root2 = insertFisrt(root2, phoneCase4[i]);
								root1 = insertLast(root1, phoneCase4[i]);
							}
							break;
						case 2:
							printf("***Nhap so luong insert: ");
							scanf("%d", &count);
							getchar();
							for(int i =0; i< count; i++){
								printf("***Nhap telephone %d\n", i+1);
								printf("\tNhap model: ");
								gets(phoneCase4[i].model);
								printf("\tNhap memory: ");
								gets(phoneCase4[i].memory);
								printf("\tNhap screen: ");
								gets(phoneCase4[i].screen);
								printf("\tNhap price: ");
								gets(phoneCase4[i].price);
								root2 = insertLast(root2, phoneCase4[i]);
								root1 = insertFisrt(root1, phoneCase4[i]);
							}
							break;
						case 3:
							break;
						default:
							printf("Press erros, press again\n");
							break;
					}
				}while(case4 != 3);
				break;
			case 3:
				if(case1 == 0 || case2 == 0){
					printf("***Don't run case 1 and case 2\n");
					break;
				}
				do{
					printf("\t1.Display list from text\n\t2.Display list from dat\n\t3.Exit case 3\n\tPress: ");
					scanf("%d", &case3);
					switch(case3){
						case 1:
							printList(root1);
							break;
						case 2:
							printList(root2);
							break;
						case 3:
							break; 
						default: 
							printf("Press erros, press again\n");
							break;
					}

				}while(case3 != 3);
				break;
			case 5:
				// printList(root2);
				if(case1 == 0 || case2 == 0){
					printf("***Don't run case 1 and case 2\n");
					break;
				}else{
					searchModel(root2);
				}
				
				break;
			case 6:
				if(case1 == 0 || case2 == 0){
					printf("***Don't run case 1 and case 2\n");
					break;
				}
				searchPriceUnder(root2);
				break;
			case 7:
				if(case1 == 0 || case2 == 0){
					printf("***Don't run case 1 and case 2\n");
					break;
				}
				exportToDat(root2, fout);
				break;
			case 8:
				puts("Exit!!!");
				break;
			default: 
				puts("Enter erros, enter again!");
				break;
		}
	}while(n != 8);

}

int menu(){
	puts("====================MENU==================");
	puts("1.Import from text");
	puts("2.Import from dat");
	puts("3.Display list");
	puts("4.Manual insertion");
	puts("5.Search phone by model");
	puts("6.Search phone by price under value input");
	puts("7.Export to dat");
	puts("8.Quit");
	int n;
	printf("Enter selection: ");
	scanf("%d", &n);
	return n;
}

node *makeNewNode(telephone phone){
	node *new = (node*)malloc(sizeof(node));
	new->phone = phone;
	new->next = NULL;
	return new;
}

node *insertFisrt(node *root, telephone phone){
	node *new = makeNewNode(phone);
	new->next = root;
	root = new;
	return root;
}

// node *cur;
node *insertAfterCur(node *root, telephone phone){
	static node *cur;
	node *new = makeNewNode(phone);
	if(root == NULL){
		root = new;
		cur = root;
	}else{
		new->next = cur->next;
		cur->next = new;
		cur = new;
	}
	return root;
}

void printList(node *root){
	if(root == NULL){
		printf("Loi con tro NULL\n");
		return;
	}
	while(root != NULL){
		printf("%-15s%-10s%-10s%-20s\n", root->phone.model, root->phone.memory, root->phone.screen, root->phone.price);
		root = root->next;
	}
}

node *readTextToList(FILE *fin, node *root){
	telephone phoneDB[max];
	fseek(fin, 0*sizeof(telephone), SEEK_SET);
	int irc;
	irc = fread(phoneDB, sizeof(telephone), max, fin);
	printf("file co %d phan tu\n", irc);
	int i =0;
	while(i <irc){
		root = insertFisrt(root, phoneDB[i]);
		i++;
	}
	puts("Import from text perfect");
	return root;
}

node *readDatToList(FILE *fin, node *root){
	telephone phoneDB[max];
	fseek(fin, 0*sizeof(telephone), SEEK_SET);
	int irc;
	irc = fread(phoneDB, sizeof(telephone), max, fin);
	printf("file co %d phan tu\n", irc);
	int i =0;
	while(i <irc){
		// printf("%-15s%-10s%-10s%-20s\n", phoneDB[i].model, phoneDB[i].memory, phoneDB[i].screen, phoneDB[i].price);
		root = insertAfterCur(root, phoneDB[i]);
		i++;
	}
	// puts("================");
	// printList(root);
	puts("Import from dat perfect");
	return root;
}

node *freeList(node *root){
	node *to_free = root;
	while(to_free != NULL){
		root = root->next;
		free(to_free);
		to_free = root;
	}
	return root;
}

node *insertLast(node *root, telephone phone){
	node *new = makeNewNode(phone);
	if(root == NULL){
		return new;
	}
	node *tmp = root;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = new;
	return root;
}

void searchModel(node *root){
	char model[20];
	getchar();
	printf("Nhap model: ");
	gets(model);
	int mark = 0;
	// node *cur = root;
	while(root != NULL){
		if(strcasestr(root->phone.model, model) != NULL){
			printf("%-15s%-10s%-10s%-20s\n", root->phone.model, root->phone.memory, root->phone.screen, root->phone.price);
			mark = 1;
		}
		root = root->next;
	}
	if(mark == 0){
		puts("Khong co model phu hop!");
	}
}

void searchPriceUnder(node *root){
	int price;
	printf("Enter price search: ");
	scanf("%d", &price);
	int mark = 0;
	while(root != NULL){
		if(price > atoi(root->phone.price)){
			printf("%-15s%-10s%-10s%-20s\n", root->phone.model, root->phone.memory, root->phone.screen, root->phone.price);
			mark = 1;
		}
		root = root->next;
	}
	if(mark == 0){
		puts("Khong co model phu hop!");
	}
}

telephone copyPhone(telephone phoneWrite, node *cur){		//copy from list to phoneName array
	strcpy(phoneWrite.model, cur->phone.model);
	strcpy(phoneWrite.memory, cur->phone.memory);
	strcpy(phoneWrite.screen, cur->phone.screen);
	strcpy(phoneWrite.price, cur->phone.price);
	// printf("%s-%s\n", cur->phone.name, cur->phone.tel);
	return phoneWrite;		//return struct neu khong return thi du lieu khong duoc xuat ra tu function
}

void exportToDat(node *root, FILE *fout){
	telephone phoneWrite[max];
	int j =0;
	while(root != NULL){
		phoneWrite[j] = copyPhone(phoneWrite[j], root);
		j++;
		root = root->next;
	}
	// printNode(root);
	fseek(fout, 0*sizeof(telephone), SEEK_SET);
	int irc = fwrite(phoneWrite, sizeof(telephone), j, fout);
	printf("Ghi duoc %d du lieu vao file\n", irc);

}
























