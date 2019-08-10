//fileSlip programing
//Tao file phoneName.dat chua 20 so lien lac
//fileSplip <phoneName.dat> <phone1.dat> <phone2.dat>
//Lien quan den: fileRead dung doc cac file, fileMerge dung de ghep 2 file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

typedef struct{
	char name[20];
	char tel[11];
	char mail[30];
}phoneName;

phoneName phone[max];

void writeFile(FILE *fout){
	int n;
	int count;
	printf("nhap so luong can nhap: ");
	scanf("%d", &n);
	getchar();
	for(int i =0; i< n; i++){
		printf("nhap person %d: \n", i+1);
		printf("\tnhap name: ");
		gets(phone[i].name);
		printf("\tnhap tel: ");
		gets(phone[i].tel);
		printf("\tnhap mail: ");
		gets(phone[i].mail);
	}
	count = fwrite(phone, sizeof(phoneName), n, fout);
	printf("so truong ghi duoc count = %d\n", count );
}

void cutPhone(FILE *fin, FILE *fout1, FILE *fout2, int n){
	int irc;

	phoneName *phoneSource;		//struct luu file nguon
	phoneSource = (phoneName*)malloc(sizeof(phoneName)*max);	//cap phat dong cho struct
	if(phoneSource == NULL){
		printf("Cap phat dong fail\n");
		exit(0);
	}

	irc = fread(phoneSource,sizeof(phoneName), max, fin);	//doc struct file nguon tra ve so luong file
	fseek(fin, 0*sizeof(phoneName), SEEK_SET );		//dua con tro ve dau file
	printf("fileSource co %d phan tu struct\n", irc);

	if(n > irc){	//kiem tra so luong can tach
		printf("khong the thao tac chia file\n");
		exit(0);
	}

	phoneName *phone1, *phone2;		//struct luu file can tach
	phone1 = (phoneName*)malloc(sizeof(phoneName)*n);
	phone2 = (phoneName*)malloc(sizeof(phoneName)*(irc-n));
	if(phone1 == NULL || phone2 == NULL){
		printf("Cap phat dong fail\n");
	}
	puts("Bat dau chia nho file\n");
	fread(phone1, sizeof(phoneName), n, fin);	//doc tu file nguon theo so luong va viet ra file can tach
	fwrite(phone1, sizeof(phoneName), n, fout1);
	fread(phone2, sizeof(phoneName), irc-n, fin);
	fwrite(phone2, sizeof(phoneName), irc-n, fout2);

	free(phoneSource);
	free(phone1);
	free(phone2);
}

int main(const int argc, const char *argv[]){

	// if(argc != 5){
	// 	printf("Sai cu phap\nCu phap dung: ./ex51 \"sourceFile\" \"soLuongLienLac\" \"file1\" \"file2\" \n");
	// 	return 0;
	// }

	int n;
	char *fileName;
	char *file1 , *file2;
	fileName = (char*)malloc(strlen(argv[1])*sizeof(char));
	file1 = (char*)malloc(strlen(argv[3])*sizeof(char));
	file2 = (char*)malloc(strlen(argv[4])*sizeof(char));

	if(fileName == NULL || file1 == NULL || file2 == NULL){
		printf("Cap phat dong fail\n");
		return 0;
	}

	strcpy(fileName, argv[1]);
	// strcpy(file1, argv[3]);
	// strcpy(file2, argv[4]);
	// n = atoi(argv[2]);
	

	FILE *fptr;
	FILE *f1, *f2;
	if((fptr = fopen(fileName, "w+b")) == NULL){
		printf("Can not open file %s\n", fileName);
		return 0;
	}
	// if((f1 = fopen(file1, "w+b")) == NULL){
	// 	printf("Can not open file %s\n", file1);
	// 	return 0;
	// }
	// if((f2 = fopen(file2, "w+b")) == NULL){
	// 	printf("Can not open file %s\n", file2);
	// 	return 0;
	// }


	// cutPhone(fptr, f1, f2, n);
	// printf("cut file complete\n");

	writeFile(fptr);
	fclose(fptr);
	fclose(f1);
	fclose(f2);
	free(fileName);
	free(file1);
	free(file2);

}
























