#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char *str;

	str = (char*)malloc(15);
	strcpy(str, "tutorialpoint");
	printf("string = %s, Adress = %u\n",str, str );

	//Reallocating memory 
	
	str = (char *)realloc(str, 15);
	strcat(str, ".com");

	printf("String = %s, Adress = %u\n", str, str);

	free(str);

}