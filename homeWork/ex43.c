#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_LEN 50
#define max 1000
#define MAX_BLOCK 80

FILE *fptr1, *fptr2;

int menu(){
	int selec;
	printf("====================MENU=====================\n");
	printf("1.Sao chep theo ky tu\n2.Sao chep theo dong\n3.Sao chep theo block\n4.Thoat programing\n");
	printf("Hay nhap lua chon: ");
	scanf("%d", &selec);
	return selec;
}

void copyCharacter(FILE *fin, FILE *fout){
	
	clock_t begin1, end1;
	begin1 = clock();
	int c;
	while((c = fgetc(fin)) != EOF){
		fputc(c, fout);
	}
	end1 = clock();
	printf("time copy character = %lf seconds\n", (double)(end1 - begin1)/CLOCKS_PER_SEC);
	
}

void copyLine(FILE *fin, FILE *fout){
	
	clock_t begin2 = clock();
	char str[max];
	while(fgets(str, max, fin) != NULL){
		fputs(str, fout);
	}
	clock_t end2 = clock();
	printf("time copy line = %lf seconds\n", (double)(end2 - begin2)/CLOCKS_PER_SEC);
	
}

void copyCharacterBlock(FILE *fin, FILE *fout){
	int block;
	printf("Nhap block: ");
	scanf("%d", &block);
	clock_t begin3, end3;
	begin3 = clock();
	int num;
	char buff[block+1];
	while(!feof(fin)){
		num = fread(buff, sizeof(char), block, fin);
		buff[num*sizeof(char)] = '\0';
		fwrite(buff, sizeof(char), num, fout);
	}
	end3 = clock();
	printf("time copy character block = %lf seconds\n", (double)(end3 - begin3)/CLOCKS_PER_SEC);

}

int main(){

	int selec;
	char fileName[MAX_LEN];
	printf("Nhap source file: ");
	gets(fileName);
	
	do{

		selec = menu();

		switch(selec){

			case 1:
				if((fptr1 = fopen(fileName, "r")) == NULL){
					printf("Can not open file \n");
					exit(1);
				}
				if((fptr2 = fopen("../../file/lab43.txt", "w")) == NULL){
					printf("Can not open file ../../lab43.txt\n");
					exit(1);
				}

				copyCharacter(fptr1, fptr2);

				fclose(fptr1);
				fclose(fptr2);	
				break;

			case 2:
				if((fptr1 = fopen(fileName, "r")) == NULL){
					printf("Can not open file \n");
					exit(1);
				}
				if((fptr2 = fopen("../../file/lab43.txt", "w")) == NULL){
					printf("Can not open file ../../lab43.txt\n");
					exit(1);
				}
				
				copyLine(fptr1, fptr2);

				fclose(fptr1);
				fclose(fptr2);
				break;

			case 3:
				if((fptr1 = fopen(fileName, "r")) == NULL){
					printf("Can not open file \n");
					exit(1);
				}
				if((fptr2 = fopen("../../file/lab43.txt", "w")) == NULL){
					printf("Can not open file ../../lab43.txt\n");
					exit(1);
				}
				
				copyCharacterBlock(fptr1, fptr2);

				fclose(fptr1);
				fclose(fptr2);	
				break;
			case 4:
				puts("Thoat chuong trinh");
				break;
			default:
				printf("Nhap sai ky tu, nhap lai\n");
				break;

		}

	}while(selec != 4);

	

}