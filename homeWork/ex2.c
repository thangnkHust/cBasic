#include <stdio.h>
#include <string.h>
#define max 100

typedef struct{
    char fullName[max];
    char name[max];
    int SL;
} student;

student getStudent(void);
char *cut(char fullName[], char name[]);
void swap( student *s1, student *s2);


int main(){
    
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    student student[n];
    getchar();
    
    for (int i = 0; i< n; i++) {
        printf("nhap ten thu %d : ", i+1);
        student[i] = getStudent();
    }
    
    for (int i = 0; i< n; i++) {
        cut(student[i].fullName, student[i].name);
    }
    
    //    for (int i = 0; i< n ; i++) {
    //        puts(student[i].name);
    //    }
    
    for (int i = 0 ; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (strcmp(student[i].name, student[j].name) > 0) {
                swap(&student[i], &student[j]);
            }
        }
    }
    
    printf("ket qua sau khi sap xep la: \n");
    
    for (int i =0;  i< n; i++) {
        puts(student[i].fullName);
    }
    
    // int dem = 0;
    int sum = 0;
    char str[max];
    
    for (int i = 0; i< n; i++) {
        for (int j = i; j < n;  j++) {
            if (strcmp(student[i].name, student[j].name) == 0) {
                student[i].SL++;
            }
        }
        if (student[i].SL > sum) {
            sum = student[i].SL;
            // strcpy(str, student[i].name);
            // dem = 0;
        }
    }
    
    // printf("xuat hien nhieu nhat %d lan, ten do la   %s   ", sum -1, str);
    for (int i = 0; i < strlen(student); ++i)
    {
        if (sum == student[i].SL)
        {
            printf("xuat hien nhieu nhat %d lan, ten do la   %s   \n", sum , student[i].name );
        }
    }
    
    
    
}

student getStudent(){
    student student;
    fgets(student.fullName, max, stdin);
    return student;
}

char *cut(char fullName[], char name[]){
    int mark = 0, count = 0;
    for (int i = strlen(fullName) ; i>0; i--) {
        if (fullName[i] == ' ' ) {
            mark = i+1;
            break;
        }
    }
    for (int i = mark; i < strlen(fullName); i++) {
        name[count] = fullName[i];
        count++;
    }
    name[count] = '\0';
    return name;
}

void swap( student *s1, student *s2){
    student s = *s1;
    *s1 = *s2;
    *s2 = s;
}












