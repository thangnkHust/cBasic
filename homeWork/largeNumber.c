#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stackRec.h"
#include "../largeNumber.h"

int menu(void);

int main(){

	stackType stack1, stack2, stack3;
	initalize(&stack1);
	initalize(&stack2);
	initalize(&stack3);
	char str1[max];
	char str2[max];
	int n;

	do{
		n = menu();
		switch(n){
			case 1:
				printf("Nhap so thu 1: ");
				getchar();
				gets(str1);
				for(int i =0; i< strlen(str1); i++){
					if(!((str1[i] >= '0' && str1[i] <= '9') || str1[i] == ' ' || str1[0] == '-') ){
						printf("String %s error\n", str1);
						break;
					}
				}
				printf("Nhap so thu 2: ");
				gets(str2);
				for(int i =0; i< strlen(str2); i++){
					if(!((str2[i] >= '0' && str2[i] <= '9') || str2[i] == ' ' || str2[0] == '-') ){
						printf("String %s error\n", str2);
						break;
					}
				}
				stack3 = sumLargeNumber(str1, str2, stack1, stack2, stack3);
				printf("***The result of %s + %s = ", str1, str2);
				while(!empty(&stack3)){
					printf("%d", pop(&stack3));
				}
				puts("");
				
				break;
			case 2:
				printf("Nhap so thu 1: ");
				getchar();
				gets(str1);
				for(int i =0; i< strlen(str1); i++){
					if(!((str1[i] >= '0' && str1[i] <= '9') || str1[i] == ' ' || str1[0] == '-') ){
						printf("String %s error\n", str1);
						break;
					}
				}
				printf("Nhap so thu 2: ");
				gets(str2);
				for(int i =0; i< strlen(str2); i++){
					if(!((str2[i] >= '0' && str2[i] <= '9') || str2[i] == ' ' || str2[0] == '-') ){
						printf("String %s error\n", str2);
						break;
					}
				}
				stack3 = subtractionLargeNumber(str1, str2, stack1, stack2, stack3);
				printf("***The result of %s - %s = ", str1, str2);
				while(!empty(&stack3)){
					printf("%d", pop(&stack3));
				}
				puts("");
				break;
			case 3: 
				puts("Quit!!!");
				break;
		}
	}while(n != 3);

}

int menu(){
	puts("=============MENU===========");
	puts("1.Cong 2 so nguyen lon");
	puts("2.Tru 2 so nguyen lon");
	puts("3.Quit!!!");
	int n;
	printf("Enter selection: ");
	scanf("%d", &n);
	puts("=========================");
	return n;
}
