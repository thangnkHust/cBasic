// Lay du lieu tu file phoneName.dat da tao ex51.c load vao single linked list
// *Print list ( left to right and right to left)
// *Insert more contacts to list(before and after current) 
// Chuc nang bo sung check: *Write vao file goc
// 							*Dung case 1, 2 de check ket qua
// 							*Dung name xac dinh current
// 							*Check name bi trung lap, yeu cau nhap lai 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100

typedef struct{
	char name[20];
	char tel[11];
	char mail[30];
}phoneName;

typedef struct node{
	phoneName phone;
	struct node *next;
}node;

// phoneName phoneRead[max];

int menu(){
	puts("====================MENU====================");
	puts("1.Read from file and print left to right");
	puts("2.Read from file and print right to left");
	puts("3.Insert contact after current to list");
	puts("4.Insert contact before current to list");
	puts("5.Exit");
	int n;
	printf("Enter selection: ");
	scanf("%d", &n);
	puts("==========================");
	return n;
}

node *makeNewNode(phoneName phone){
	node *new = (node*)malloc(sizeof(node));
	new->phone = phone;
	new->next = NULL;
	return new;
}

node *insertLast(node *root, phoneName phone){
	node *new = makeNewNode(phone);
	if(root == NULL){
		root = new;
		return root;
	}
	node *cur = root;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = new;
	return root;
}


void printNode(node *root){
	node *cur = root;

	while(cur != NULL){
		printf("%-20s%-15s%-20s%p\n", cur->phone.name, cur->phone.tel, cur->phone.mail, cur->next);
		cur = cur->next;
	}
}

node *readFileToList(FILE *fin, node *root){	//doc tu file add vao list tra ve con tro root 
	int irc;
	int i =0;
	phoneName phoneRead[max];
	fseek(fin, 0*sizeof(phoneName), SEEK_SET);
	irc = fread(phoneRead, sizeof(phoneName), max, fin);	//Doc du lieu tu file.dat
	// printf("file co %d phan tu\n", irc);
	while(i < irc){
		root = insertLast(root, phoneRead[i]);		//add single linked list 
		i++;
	}
	return root;
}

void readFileToList1(FILE *fin, node *root){	//doc tu file add vao list khong tra ve con tro root, dung de print list
	int irc;
	int i =0;
	phoneName phoneRead[max];
	fseek(fin, 0*sizeof(phoneName), SEEK_SET);
	irc = fread(phoneRead, sizeof(phoneName), max, fin);
	printf("file co %d phan tu\n", irc);	
	while(i < irc){
		root = insertLast(root, phoneRead[i]);		
		i++;
	}
	printNode(root);	
}

void readFileToList2(FILE *fin, node *root){	//doc tu file add vao list nhung khong tra ve node, chi dung print list khong dung luu tru
	int irc;
	// node *root1 = NULL;
	phoneName phoneRead[max];
	fseek(fin, 0*sizeof(phoneName), SEEK_SET);
	irc = fread(phoneRead, sizeof(phoneName), max, fin);
	printf("file co %d phan tu\n", irc);
	while(irc){
		root = insertLast(root, phoneRead[irc-1]);
		irc--;
	}
	printNode(root);
}

phoneName copyPhone(phoneName phoneWrite, node *cur){		//copy from list to phoneName array
	strcpy(phoneWrite.name, cur->phone.name);
	strcpy(phoneWrite.tel, cur->phone.tel);
	strcpy(phoneWrite.mail, cur->phone.mail);
	// printf("%s-%s\n", cur->phone.name, cur->phone.tel);
	return phoneWrite;		//return struct neu khong return thi du lieu khong duoc xuat ra tu function
}

node *findCur(node *root, node *cur){
	char str[max];
	getchar();
	printf("Nhap ten xac dinh current: ");
	gets(str);
	cur = root;
	while(cur != NULL){
		if(strcmp(cur->phone.name, str) == 0) break;
		cur = cur->next;
	}
	return cur;
	// printf("%s-%s\n", cur->phone.name, cur->phone.tel);
}

int checkName(node *new, node *root){
	node *cur = root;
	while(cur != NULL){
		if(strcmp(new->phone.name, cur->phone.name) == 0){
			return 0;
		}
		cur = cur->next;
	}
	return 1;
}

void insertContactAfterCur(FILE *fin, node *root){
	node *cur;
	cur = findCur(root, cur);
	if(cur == NULL){
		printf("***Khong tim thay ten phu hop\n");
		return;
	}
	int count;
	printf("Ban muon them bao nhieu lien lac: ");
	scanf("%d", &count);
	getchar();
	phoneName phoneInsert;
	for(int i =0; i< count; i++){
		printf("Nhap name %d: ", i+1);
		gets(phoneInsert.name);
		printf("\tNhap tel: ");
		gets(phoneInsert.tel);
		printf("\tNhap mail: ");
		gets(phoneInsert.mail);
		node *new = makeNewNode(phoneInsert);
		while(checkName(new, root) == 0){
			printf("*Ban nhap trung ten, Hay nhap lai\n");
			printf("Nhap name %d: ", i+1);
			gets(phoneInsert.name);
			printf("\tNhap tel: ");
			gets(phoneInsert.tel);
			printf("\tNhap mail: ");
			gets(phoneInsert.mail);
			new = makeNewNode(phoneInsert);
		}
		new->next = cur->next;
		cur->next = new;
		cur = new;
	}
	// printf("%s-%s\n", cur->next->phone.name, cur->next->phone.tel);

	phoneName phoneWrite[max];
	cur = root;
	int j =0;
	while(cur != NULL){
		phoneWrite[j] = copyPhone(phoneWrite[j], cur);
		j++;
		cur = cur->next;
	}
	// printNode(root);
	fseek(fin, 0*sizeof(phoneName), SEEK_SET);
	int irc = fwrite(phoneWrite, sizeof(phoneName), j, fin);
	printf("Ghi duoc %d du lieu vao file\n", irc);
}

void insertContactBeforeCur(FILE *fin, node *root){
	node *cur;
	cur = findCur(root, cur);
	if(cur == NULL){
		printf("***Khong tim thay ten phu hop\n");
		return;
	}
	
	phoneName phoneInsert;
	int count;
	if(cur == root){
		printf("Ban muon them bao nhieu lien lac: ");
		scanf("%d", &count);
		getchar();
		for(int i =0; i< count; i++){
			printf("Nhap name %d: ", i+1);
			gets(phoneInsert.name);
			printf("\tNhap tel: ");
			gets(phoneInsert.tel);
			printf("\tNhap mail: ");
			gets(phoneInsert.mail);
			node *new = makeNewNode(phoneInsert);
			while(checkName(new, root) == 0){
				printf("*Ban nhap trung ten, Hay nhap lai\n");
				printf("Nhap name %d: ", i+1);
				gets(phoneInsert.name);
				printf("\tNhap tel: ");
				gets(phoneInsert.tel);
				printf("\tNhap mail: ");
				gets(phoneInsert.mail);
				new = makeNewNode(phoneInsert);
			}
			new->next = root;
			root = new;
		}
	}else{
		node *prev = root;
		while(prev->next != cur){
			prev = prev->next;
		}
		printf("Ban muon them bao nhieu lien lac: ");
		scanf("%d", &count);
		getchar();
	
		for(int i =0; i< count; i++){
			printf("Nhap name %d: ", i+1);
			gets(phoneInsert.name);
			printf("\tNhap tel: ");
			gets(phoneInsert.tel);
			printf("\tNhap mail: ");
			gets(phoneInsert.mail);
			node *new = makeNewNode(phoneInsert);
			while(checkName(new, root) == 0){
				printf("*Ban nhap trung ten, Hay nhap lai\n");
				printf("Nhap name %d: ", i+1);
				gets(phoneInsert.name);
				printf("\tNhap tel: ");
				gets(phoneInsert.tel);
				printf("\tNhap mail: ");
				gets(phoneInsert.mail);
				new = makeNewNode(phoneInsert);
			}
			new->next = cur;
			prev->next = new;
			cur = new;
		}
	}
	
	phoneName phoneWrite[max];
	cur = root;
	int j =0;
	while(cur != NULL){
		phoneWrite[j] = copyPhone(phoneWrite[j], cur);
		j++;
		cur = cur->next;
	}
	fseek(fin, 0*sizeof(phoneName), SEEK_SET);
	int irc = fwrite(phoneWrite, sizeof(phoneName), j, fin);
	printf("Ghi duoc %d du lieu vao file\n", irc);
}

node *freeList(node *root){		//free list, can return root de truyen gia tri ra khoi function
	node *to_free;
	to_free = root;
	while(to_free != NULL){
		root = root->next;
		free(to_free);
		to_free = root;
	}
	return root;
}



int main(int argc, char *argv[]){	

	FILE *fin, *fout;
	int n;
	
	// int i = 0;
	node *root = NULL;
	node *root1 = NULL;
	if(argc != 2){
		printf("Nhap sai argument\n");
		printf("Cu phap dung: %s <fileSource>\n", argv[0]);
		return 0;
	}
	if((fin = fopen(argv[1], "r+b")) == NULL){
		printf("Can not open file %s\n", argv[1]);
		return 0;
	}
	root = readFileToList(fin, root);
	
	do{
		n = menu();
		switch(n){
			case 1:
				readFileToList1(fin, root1);
				printNode(root1);
				break;
			case 2:
				readFileToList2(fin, root1);
				break;
			case 3:
				insertContactAfterCur(fin, root);
				break;
			case 4:
				insertContactBeforeCur(fin, root);
				break;
			case 5:
				puts("Exit!!!");
				break;
			default: 
				printf("Enter erros, enter again!\n");
				break;
		}
	}while(n != 5);

	root = freeList(root);

}

















