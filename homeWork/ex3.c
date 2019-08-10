#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define max 100

typedef struct{
    char article[max];
    char noun[max];
    char verb[max];
    char preposition[max];
//    char sentence[max];
} burnSent;

burnSent *getBurnSent(burnSent burnSent[], int n);

int main(){
    
    int n, m;
    
    printf("nhap so luong moi cau truc: ");
    scanf("%d", &n);
    getchar();
    
    burnSent burnSent[n];
    
    getBurnSent(burnSent, n);
    
//    for (int i = 0; i< n; i++) {
//        printf("%s ", burnSent[i].article);
//    }
    printf("nhap so luong cau can tao: ");
    scanf("%d", &m);
    char sentence[m][max];
    
    srand(time(NULL));
    
    for (int i = 0 ; i < m; i++) {
        
        sentence[i][0] = '\0';
        strcat(sentence[i], burnSent[rand()%n].article);
        
        strcat(sentence[i], burnSent[rand()%n].noun);
        strcat(sentence[i], burnSent[rand()%n].verb);
        strcat(sentence[i], burnSent[rand()%n].preposition);
        strcat(sentence[i], burnSent[rand()%n].article);
        strcat(sentence[i], burnSent[rand()%n].noun);
    }
    
    printf("KET QUA \n");
    for (int i = 0; i< m; i++) {
        printf("%s\n", sentence[i]);
    }
    
}

burnSent *getBurnSent(burnSent burnSent[], int n){
    printf("nhap article: ");
    for (int i = 0 ; i< n; i++) {
        printf("nhap article thu %d: ", i+1);
        gets(burnSent[i].article);
    }
    printf("nhap noun: ");
    for (int i = 0 ; i< n; i++) {
        printf("nhap noun thu %d: ", i+1 );
        gets(burnSent[i].noun);
    }
    printf("nhap verb: ");
    for (int i = 0 ; i< n; i++) {
        printf("nhap verb thu %d: ", i+1 );
        gets(burnSent[i].verb);
    }
    printf("nhap preposition: ");
    for (int i = 0 ; i< n; i++) {
        printf("nhap preposition thu %d: ", i+1 );
        gets(burnSent[i].preposition);
    }
    return burnSent;
}




