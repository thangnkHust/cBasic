#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 100

char *subString(char *str, int offset, int number){
	char *p;
	char strC[max];

	p = (char*)malloc((strlen(str) - offset + 1)*sizeof(char));
	if(p == NULL){
		printf("Cap phat bo nho fail\n");
		exit(1);
	}
	int count = 0;
	if((offset + number) > strlen(str)){
		for(int i = offset - 1; i< strlen(str); i++){
			strC[count] = str[i];
			count++;
		}
		strC[count] = '\0';
	}else{
		for(int i = offset - 1; i< (offset+number); i++){
			strC[count] = str[i];
			count++;
		}
		strC[count] = '\0';

	}
	strcpy(p, strC);

	return p;
}

int main(){

	char str[max];
	char *strOut;
	int offset, number;

	printf("nhap xau dau vao\n");
	fgets(str, max, stdin);
	printf("nhap ky tu bat dau: ");
	scanf("%d", &offset);
	printf("nhap so ky tu can cat: ");
	scanf("%d", &number);

	strOut = subString(str, offset, number);

	if(strOut == NULL){
		printf("Cap phat bo nho gap van de\n");
		return 0;
	}

	printf("%s\n",strOut);

	free(strOut);

}