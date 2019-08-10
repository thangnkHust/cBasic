#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 100

void charCount(FILE *fin, FILE *fout){
	char str[max];
	int ascii[95];

	for(int i =0; i < 95; i++){
		ascii[i] = 0;
	}

	while(fgets(str, max, fin) != NULL){
		for(int i =0; i< strlen(str); i++){
			if(isupper(str[i])){
				str[i] = tolower(str[i]);
			}
		}
		for( int i =0; i< strlen(str); i++){
			if( str[i] >= ' ' && i <= '~'){
				ascii[str[i] - ' ']++;
			}
		}
	}
	fprintf(fout, "charecter  count\n" );
	for(int i =0; i< 95; i++){
		if(ascii[i] > 0){
			printf("ky tu %c xuat hien %d lan\n",i+' ', ascii[i] );
			fprintf(fout, "%3c\t%5d\n",i+' ', ascii[i]);
		}
	}
	
	
}

int main(int argc, char*argv[]){

	if(argc != 2){
		printf("nhap sai cu phap arguments\n");
		printf("cu phap dung la: ./ex31 \"sourceFile\" \n");
	}else{
		char fileName[max];
		strcpy(fileName, argv[1]);
		FILE *fptr;
		FILE *fptrS;
		if((fptr = fopen(fileName, "r" )) == NULL){
			printf("Can not open file %s\n",fileName);
		}else{
			if((fptrS = fopen("../../file/sourceStats.txt", "w")) == NULL){
				printf("Can not open file sourceStats\n");
			}else{
				charCount(fptr, fptrS);
			}
		}
		fclose(fptr);
		fclose(fptrS);
		
	}


}