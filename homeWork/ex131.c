// Heap Sort key: name
// fin: test.dat
#include <stdio.h>
#include <string.h>
#include "../heapSort.h"
#define max 100

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
	elementtype element[max];
	irc = fread(element, sizeof(elementtype), max, fin);
	printf("file co %d phan tu\n", irc);

	for(int i =irc; i>= 1; i--){
		element[i] = element[i-1];
	}
	for(int i = 1; i<= irc; i++){
		printf("%-20s%-15s%-20s\n", element[i].name, element[i].tel, element[i].email);
	}



	heapSort(element, irc);
	puts("===============================");
	for(int i = 1; i<= irc; i++){
		printf("%-20s%-15s%-20s\n", element[i].name, element[i].tel, element[i].email);
	}

}










