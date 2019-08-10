#include <stdio.h>

void readWrite(FILE *fin, FILE *fout){
    int c;
    while ((c = fgetc(fin)) != EOF) {
        fputc(c, fout);
        putchar(c);
    }
}

int main (){
    
    FILE *fptr1;
    FILE *fptr2;
    
    int reval = 1;
    
    fptr1 = fopen("../../file/lab1.txt", "r");
    fptr2 = fopen("../../file/lab1w.txt", "w");
    
    if (fptr1 == NULL) {
        printf("khong the mo file\n");
        reval = 0;
    }else {
        if (fptr2 == NULL) {
            printf("khong the mo file");
            reval = 0;
        }else{
            readWrite(fptr1, fptr2);
            fclose(fptr1);
            fclose(fptr2);
        }
        
    }
    
    
    
    return reval;
    
}
