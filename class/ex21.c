// #include <stdio.h>
// #include <ctype.h>

// void readWrite(FILE *fin, FILE *fout){
// 	int c;
// 	while((c = fgetc(fin)) != EOF){
// 		if (islower(c))
// 		{
// 			c = toupper(c);
// 		}
// 		if (isupper(c))		
// 		{
// 			c = tolower(c);
// 		}
// 		fputc(c, fout);
// 		putchar(c);
// 	}
// }

// int main(int argc, char const *argv[])
// {
// 	FILE *fptr1, *fptr2;

// 	fptr1 = fopen("lab1.txt", "r");
// 	fptr2 = fopen("lab1w.txt", "w");

// 	readWrite(fptr1, fptr2);
// 	fclose(fptr1);
// 	fclose(fptr2);

// 	return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
    int height, width;
    
    if (argc < 3) {
        printf("thieu 1 doi so trong arguments \n");
    }
    if (argc > 3) {
        printf("nhap thua 1 doi so trong arguments\n");
    }
    
    height = atof(argv[1]);
    width = atof(argv[2]);
    
    printf("Dien tich hcn la: %d \n", height*width);
    printf("chu vi hcn la: %d \n", 2*(height + width));
    
    
}
