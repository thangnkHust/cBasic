#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "luanVo.h"

void readFile(FILE *fin1, FILE *fin2, queueType *Q1, queueType *Q2);
void thiDau(elementtype *m1, elementtype *m2, queueType *Q1, queueType *Q2);
int mark = 0;

int main(){

	FILE *fin1 = fopen("../file/mp1.txt", "r");
	FILE *fin2 = fopen("../file/mp2.txt", "r");
	queueType Q1, Q2;
	elementtype m1, m2;
	readFile(fin1, fin2, &Q1, &Q2);
	m1 = deQueue(&Q1);
	m2 = deQueue(&Q2);
	while( !empty(&Q1) && !empty(&Q2)){
		printf("MP1 %s(%d-%d-%d-%d) vs MP2 %s(%d-%d-%d-%d):\n", m1.bietHieu, m1.mau, m1.tancong, m1.nhanhnhen, m1.phongthu, m2.bietHieu, m2.mau, m2.tancong, m2.nhanhnhen, m2.phongthu);
		if(m1.nhanhnhen > m2.nhanhnhen){
			thiDau(&m1, &m2, &Q1, &Q2);
		}else{
			thiDau(&m2, &m1, &Q2, &Q1);
		}
	}
	if(empty(&Q1)){
		printf("MP1 thua!!!\n");
	}else{
		printf("MP2 thua!!!\n");
	}

}
elementtype a1[30], a2[30];
void readFile(FILE *fin1, FILE *fin2, queueType *Q1, queueType *Q2){
	
	int i =0, j = 0;
	printf("Mon phai 1: \n");
	while(!feof(fin1)){
		fscanf(fin1, "%s%d%d%d%d", a1[i].bietHieu, &a1[i].mau, &a1[i].tancong, &a1[i].nhanhnhen, &a1[i].phongthu);
		enQueue(Q1, a1[i]);
		printf("%s-%d-%d-%d-%d\n", a1[i].bietHieu, a1[i].mau, a1[i].tancong, a1[i].nhanhnhen, a1[i].phongthu);
		i++;
	}
	printf("Mon phai 2: \n");
	while(!feof(fin2)){
		fscanf(fin2, "%s%d%d%d%d", a2[j].bietHieu, &a2[j].mau, &a2[j].tancong, &a2[j].nhanhnhen, &a2[j].phongthu);
		enQueue(Q2, a2[j]);
		printf("%s-%d-%d-%d-%d\n", a2[j].bietHieu, a2[j].mau, a2[j].tancong, a2[j].nhanhnhen, a2[j].phongthu);
		j++;
	}

}

int tmp = 0;

// void thiDau(elementtype m1, elementtype m2, queueType *Q1, queueType *Q2){
// 	static int count = 0;
// 	if(m1.nhanhnhen > m2.nhanhnhen){
// 		printf("%s(%d) tan cong %s(%d) mat %d mau\n", m1.bietHieu, m1.mau, m2.bietHieu, m2.mau, m1.tancong - m2.phongthu);
// 		m2.mau = m2.mau - (m1.tancong - m2.phongthu);
// 		count++;
// 		if(m2.mau > 0){
// 			m1.diem += 1;
// 			thiDau(m2, m1, Q2, Q1);
// 		}else{
// 			printf("%s thua\n", m2.bietHieu);
// 			if(count == 1){
// 				m1.diem += 3;

// 				count = 0;
// 			}
// 			m2 = deQueue(Q2);
// 			thiDau(m1, m2, Q1, Q2);
// 			// return;
// 		}
// 	}
// 	if(m1.nhanhnhen < m2.nhanhnhen){
// 		printf("%s(%d) tan cong %s(%d) mat %d mau\n", m1.bietHieu, m1.mau, m2.bietHieu, m2.mau, m1.tancong - m2.phongthu);
// 		m2.mau = m2.mau - (m1.tancong - m2.phongthu);
// 		count++;
// 		if(m2.mau > 0){
// 			m1.diem += 1;
// 			thiDau(m2, m1, Q2, Q1);
// 		}else{
// 			printf("%s thua\n", m2.bietHieu);
// 			if(count == 1){
// 				m1.diem += 3;
// 				count = 0;
// 			}
// 			m2 = deQueue(Q2);
// 			thiDau(m1, m2, Q1, Q2);
// 			// return;
// 		}
// 		// thiDau(m2, m1, Q1, Q2);
// 	}
// }

void thiDau(elementtype *m1, elementtype *m2, queueType *Q1, queueType *Q2, elementtype a1[], elementtype a2[]){
	static int count = 0;
	printf("%s(%d) tan cong %s(%d) mat %d mau\n", m1->bietHieu, m1->mau, m2->bietHieu, m2->mau, m1->tancong - m2->phongthu);
	m2->mau = m2->mau - (m1->tancong - m2->phongthu);
	count++;
	if(m2->mau > 0){
		m1->diem += 1;
		thiDau(m2, m1, Q2, Q1);
	}else{
		printf("%s thua\n", m2->bietHieu);
		if(count == 1){
			m1->diem += 3;
			count = 0;
		}
		if(!empty(Q2)) *m2 = deQueue(Q2);
	}
}









