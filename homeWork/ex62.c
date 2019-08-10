#include <stdio.h>
#include <string.h>
#include <ctype.h>

void fisrtCapital(char str[], int i){
	// if(i != (strlen(str)-1)){
	// 	upper(str, i+1);
	// }
	// if(isupper(str[i])){
	// 	printf("%c ",str[i]);
	// }
	if(isupper(str[i])){
		printf("The first capital character in string \"%s\" is: ", str);
		printf("%c\n", str[i]);
	}else{
		if(i != (strlen(str) - 1)){
			fisrtCapital(str, i+1);
		}else{
			printf("Haven't capital character!!!\n");
		}
	}
}

int main(){

	char str[100];
	printf("Nhap string: ");
	gets(str);
	// upper(str, 0);
	// if(count == 0){
	// 	printf("Khong co ky tu hoa\n");
	// }
	fisrtCapital(str, 0);
	
}