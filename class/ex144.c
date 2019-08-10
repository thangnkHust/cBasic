#include <stdio.h>
#include <string.h>
// #include "ex144.h"

int i = -1, j = -1;
void cut(char str[], char tmp[]){
	i = j;
	for(int k = i+1; k < strlen(str); k++){
		if(str[k] == ' ' || str[k] == '\n'){
			j = k;
			break;
		}
	}
	int x = 0;
	for(int k = i+1; k < j; k++){
		tmp[x++] = str[k];
	}
	tmp[x] = '\0';
}

int main(){

	char str[] = "Nguyen Khac Thang\n";
	char tmp[10];
	while(j != strlen(str) - 1){
		cut(str, tmp);
		puts(tmp);
	}

}