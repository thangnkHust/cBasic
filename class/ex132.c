// fin: test.dat

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex132.h"
#define max 100

node *readFileToList(FILE *fin, node *root){	//doc tu file add vao list tra ve con tro root 
	int irc;
	int i =0;
	elementtype phoneRead[max];
	fseek(fin, 0*sizeof(elementtype), SEEK_SET);
	irc = fread(phoneRead, sizeof(elementtype), max, fin);	//Doc du lieu tu file.dat
	// printf("file co %d phan tu\n", irc);
	while(i < irc){
		root = insertAtEnd(root, phoneRead[i]);		//add single linked list 
		i++;
	}
	return root;
}

void insertionSort(elementtype a[], int n){
	elementtype tmp;
	for(int i =1; i<n; i++){
		tmp =  a[i];
		for(int j = i-1; j >= 0; j--){
			if(strcasecmp(tmp.name, a[j].name) < 0){
				a[j+1] = a[j];
				a[j] = tmp;
			}
		}
	}
}

void selectionSort(elementtype a[], int n){
	elementtype tmp;
	int min;
	for(int i =0; i < n-1; i++){
		min = i;
		for(int j = i+1; j <= n-1; j++){
			if(strcasecmp(a[j].name, a[min].name) < 0){
				min = j;
			}
		}
		tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
	}
}

void printNode(node *root){
	node *cur = root;

	while(cur != NULL){
		printf("%-20s%-15s%-20s%p\n", cur->element.name, cur->element.tel, cur->element.email, cur->next);
		cur = cur->next;
	}
}

int menu(){
	int n;
	puts("==========MENU=========");
	puts("1.Sort array");
	puts("2.Sort single list");
	puts("3.Exit!!!");
	printf("Enter selection: ");
	scanf("%d", &n);
	puts("=======================");
	return n;
}

int menuCase1(){
	int n;
	puts("\t=======MENU CASE 1======");
	puts("\t1.Insert sort");
	puts("\t2.Selection sort");
	puts("\t3.Exit case 1");
	printf("\tPress: ");
	scanf("%d", &n);
	puts("\t========================");
	return n;
}

node *addStudent(node *root, node *to_add)		//add theo thu tu diem
{
    node *cur = NULL, *prev = NULL;

    if (root == NULL)
        return to_add;

    if (strcasecmp(to_add->element.name, root->element.name) < 0)
    {
        to_add->next = root;
        // root = to_add;
        return to_add;
    }

    cur = root;
    while (cur != NULL  &&  strcasecmp(to_add->element.name, cur->element.name) > 0)
    {
        prev = cur;
        cur = cur->next;
    }

    prev->next = to_add;
    to_add->next = cur;

    return root;
}


int main(int argc, char *argv[]){
	FILE *fin;
	if(argc != 2){
		printf("Nhap sai argument\n");
		printf("Cu phap dung: %s <fileSource>\n", argv[0]);
		return 0;
	}
	if((fin = fopen(argv[1], "r+b")) == NULL){
		printf("Can not open file %s\n", argv[1]);
		return 0;
	}

	int irc = 0;
	node *root = NULL;
	elementtype a[max];
	irc = fread(a, sizeof(elementtype), max, fin);
	printf("file co %d phan tu\n", irc);
	for(int i = 0; i< irc; i++){
		printf("%-20s%-15s%-20s\n", a[i].name, a[i].tel, a[i].email);
	}
	node *new;
	int selec;
	int case1;
	do{
		selec = menu();
		switch(selec){
			case 1:
				do{
					case1 = menuCase1();
					switch(case1){
						case 1:
							rewind(fin);
							irc = fread(a, sizeof(elementtype), max, fin);
							insertionSort(a , irc);
							for(int i = 0; i< irc; i++){
								printf("%-20s%-15s%-20s\n", a[i].name, a[i].tel, a[i].email);
							}
							break;
						case 2:
							rewind(fin);
							irc = fread(a, sizeof(elementtype), max, fin);
							selectionSort(a, irc);
							for(int i = 0; i< irc; i++){
								printf("%-20s%-15s%-20s\n", a[i].name, a[i].tel, a[i].email);
							}
							break;
						case 3:
							puts("Exit case 1");
							break;
					}
				}while(case1 != 3);
				break;
			case 2:
				rewind(fin);
				irc = fread(a, sizeof(elementtype), max, fin);
				for(int i =0; i< irc; i++){
					root = addStudent(root, makeNewNode(a[i]));
				}
				printNode(root);
				break;
			case 3:
				printf("Exit!!!\n");
				break;
		}
	}while(selec != 3);


}










