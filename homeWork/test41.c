#include <stdio.h>
#include <string.h>

int main(){

	char str[100];
	FILE *fptr;
	fptr = fopen("../../file/lab1.txt", "r");
	char *token;
	while(fgets(str, 100, fptr) != NULL){
		token = strtok(str, " ");
		while(token != NULL){
			printf("%s\n", token);
			token = strtok(NULL, " ");
		}
	}
	// puts(strstr(str1, str2));
	// strcpy(TG, strstr(str1, str2));
	// puts(TG);
	fclose(fptr);
}