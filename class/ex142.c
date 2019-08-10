// fin: student.txt
#include <stdio.h>
#include <string.h>
#include "ex142.h"
#define max 20

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Error argument\n");
		return 0;
	}

	FILE *fin;
	if((fin = fopen(argv[1], "r")) == NULL){
		printf("Can't open file %s\n", argv[1]);
		return 0;
	}

	elementtype e[max];
	int i =0;
	while(!feof(fin)){
		fscanf(fin, "%s%s%d", e[i].id, e[i].name, &e[i].grade);
		i++;
	}
	for(int k =0; k< i-1; k++){
		printf("%-10s%-40s%-5d\n", e[k].id, e[k].name, e[k].grade);
	}
	quickSort(e, 0, i-2);
	puts("================================");
	for(int k =0; k< i-1; k++){
		printf("%-10s%-40s%-5d\n", e[k].id, e[k].name, e[k].grade);
	}

}