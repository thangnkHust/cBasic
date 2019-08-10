#include <stdio.h>
#include <string.h>
#include "../quickSort.h"

int main(){
	int a[] = {4, 6, 3, 2, 19, 57, 5, 44, 7};
	quickSort(a, 0, 8);
	for(int i =0; i<9; i++){
		printf("%d ", a[i]);
	}
}

// typedef struct{
// 	char id[10];
// 	char name[50];
// 	int grade;
// }student;

// typedef student elementtype;

// int main(){
// 	FILE *fin;
// 	fin = fopen("../../file/student.txt", "w");
// 	elementtype e[20];

// 	for(int i =0; i<15; i++){
// 		printf("Nhap %d: \n", i+1);
// 		printf("Nhap id: ");
// 		gets(e[i].id);
// 		printf("Nhap name: ");
// 		gets(e[i].name);
// 		printf("Nhap grade: ");
// 		scanf("%d", &e[i].grade);
// 		getchar();
// 		fprintf(fin, "%-10s%-40s%-5d\n", e[i].id, e[i].name, e[i].grade);
// 	}

// }