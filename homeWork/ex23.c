#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

void mycp ( FILE *fin, FILE *fout){
	int c;
	while( (c = fgetc(fin)) != EOF){
		fputc(c, fout);
		putchar(c);
	}
}


int main(int argc, char *argv[])
{
	FILE *fptr1, *fptr2;
	if (argc != 3)
	{
		printf("nhap sai arguments\n");
		printf("cu phap dung la: ./ex23 \"sourceFile\" \"copyFile\" \n");
	}else{
		char fileName1[max];
		char fileName2[max];
		strcpy(fileName1, argv[1]);
    strcpy(fileName2, argv[2]);
		if ((fptr1 = fopen(fileName1, "r")) == NULL)
		{
			printf("can not file %s\n", fileName1 );
		}else{
			if ((fptr2 = fopen(fileName2, "w")) == NULL)
			{
				printf("can not file %s\n", fileName2);
			}else{
				mycp(fptr1, fptr2);
			}
		}
    fclose(fptr1);
    fclose(fptr2);

	}
	return 0;
  
}
