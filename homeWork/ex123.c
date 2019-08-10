#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex123.h"
#define max 100

int menu(void);
void readDatToList(FILE *fin, treeType *T);
keyType readNode(void);

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Error argument\n%s <fin in>\n", argv[0]);
		return 0;
	}

	FILE *fin;
	int selec;
	treeType T;
	initalize(&T);
	keyType tmp;
	keyType temp;
	treeType m;

	if((fin = fopen(argv[1], "r")) == NULL){
		printf("Can't open file %s\n", argv[1]);
		return 0;
	}

	do{
		selec = menu();
		switch(selec){
			case 1:
				readDatToList(fin, &T);
				break;
			case 2:
				inOder(T);
				break;
			case 3:
				printf("Enter new phone: \n");
				getchar();
				tmp = readNode();
				insertNode(&T, tmp);
				break;
			case 4:
				printf("Nhap model: ");
				getchar();
				gets(temp.model);
				deleteNode(&T, temp);
				break;
			case 5:
				printf("Nhap model: ");
				getchar();
				gets(temp.model);
				m = search(T, temp);
				break;
			case 6:
				deleteNode(&T, temp);
				temp = readNode();
				insertNode(&T, temp);
				break;
			case 7:
				puts("Eixt!!!");
				break;
		}
	}while(selec != 7);

}

int menu(){
	puts("==========MENU=========");
	puts("1.Import from file");
	puts("2.Display List");
	puts("3.Insert 1 phone");
	puts("4.Delete phone");
	puts("5.Find phone");
	puts("6.Update phone");
	puts("7.Exit!!!");
	printf("Enter selection: ");
	int n;
	scanf("%d", &n);
	puts("======================");
	return n;
}

void readDatToList(FILE *fin, treeType *T){
	keyType phoneDB[max];
	int irc;
	fseek(fin, 0*sizeof(telephone), SEEK_SET);
	irc = fread(phoneDB, sizeof(telephone), max, fin);
	printf("File co %d phan tu\n", irc);
	int i =0;
	while(i < irc){
		insertNode(T, phoneDB[i]); 
		i++;
	}
}

keyType readNode(){
	keyType tmp;
	getchar();
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



