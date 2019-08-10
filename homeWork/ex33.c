#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 100

typedef struct{
	int STT;
	char MSSV[max];
	char fullName[max];
	char phone[max];
	float mark;
}SV;


int main(){

	SV student[max];
	FILE *fptr, *fptrOut;
	char str[max];
	char fileName[max] = "../../file/dS.txt";
	if((fptr = fopen(fileName, "r")) == NULL){
		printf("Can not open file %s\n", fileName);
	}else{
		if((fptrOut = fopen("../../file/bangDiem.txt", "w")) == NULL){
			printf("Can not open file ../../file/bangDiem.txt\n");
		}else{
			int count = 0;
			while(fgets(str, max, fptr)!= NULL){
				count++;
			}
			fseek(fptr, 0*sizeof(SV), SEEK_SET);
			for(int i = 0; i< count; i++){
				fscanf(fptr, "%d%s%s%s", &student[i].STT, student[i].MSSV, student[i].fullName, student[i].phone);
			}
			for(int i =0; i< count; i++){
				printf("nhap diem MSSV %s : ", student[i].MSSV);
				scanf("%f", &student[i].mark);
			}
			for(int i =0; i< count; i++){
				fprintf(fptrOut,"%-5d%-10s%-20s%-20s%-5g\n", i+1, student[i].MSSV, student[i].fullName, student[i].phone, student[i].mark);
			}
		}
		
		
	}
	fclose(fptr);

}