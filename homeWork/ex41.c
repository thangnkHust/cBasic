#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define max 1000
#define max_key 10


int main(int argc, char *argv[]){

    if(argc != 3){
        printf("Nhap sai cu phap arguments\n");
        printf("Cu phap dung la: ./ex41 \"sourceFile\" \"'character'\"\n");
    }else{
        
        FILE *fptr;
        if((fptr = fopen(argv[1], "r")) == NULL){
            printf("Can not open file %s", argv[1]);
        }else{
            int n;
            char str[max];
            char *key[max_key][max_key];
            printf("Nhap so ky tu can loc: ");
            scanf("%d", &n);

            for(int i =0; i < n; i++){
                printf("nhap key can loc thu %d: ", i+1);
                scanf("%s", key[i]);
            }
            char *token;    //bien cat tung word
            char strKey[max_key][max_key]; //mang char luu tru cac word muon loc
            for(int i =0; i< n; i++){
                for(int j =0; j< strlen(key[i]); j++){
                    strKey[i][j] = *argv[2];
                }
            }
            while(fgets(str, max, fptr) != NULL){
                for(int i =0; i<strlen(str); i++){  //bien hoa thanh thuong 
                    if(isupper(str[i])){
                        str[i] = tolower(str[i]);
                    }
                }
            
                token = strtok(str, " ");//cat token dau tien
                
                while(token != NULL){   //cat token tiep theo 
                    for(int i =0; i < n; i++){
                        if(strcmp(token, key[i]) == 0){     //so sanh token as key, giong nhau thi break dung token dang xet
                            strcpy(token, strKey[i]);
                            break;
                        } 
                    }
                    printf(" %s", token);
                    token = strtok(NULL, " ");
                }

            }
            printf("\n");
        }
    }
    
}
