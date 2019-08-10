//Bai toan xep quan hau tren ban co NxN 
#include <stdio.h>
// Thuat toan: mc[] dung danh dau cot
// 				m1[], m2[] dung danh dau duong cheo
// 					m1[] danh dau duong chieu tong(v+k) 2, 4, 6, 8....
// 					m2[] danh dau duong cheo hieu(k-v) ...-2, -1, 0, 1, 2...
// 				x[][] dung de danh dau xem moi hang thi con hau de o cot nao 
int mc[50], m1[100], m2[100];
int x[50][50];
int n =4;

void solution(){
	for(int i = 1; i<= n; i++){
		for(int j = 1; j<= n; j++){
			printf("%d ",x[i][j]);
		}
		printf("\n");
	}
	puts("===========================");
}

void TRY(int k){
	for(int v= 1; v<= n; v++){
		if(mc[v] == 0 && m1[v+k] == 0 && m2[k -v] == 0){
			mc[v] = 1;
			m1[v+k] = 1;
			m2[k-v] = 1;
			x[k][v] = 1;
			if(k == n) {
				solution();
				// break;
			}
			TRY(k+1);
			mc[v] = 0;
			m1[v+k] = 0;
			m2[k-v] = 0;
			x[k][v] = 0;
		}
	}
}

int main(){

	for(int i =1; i<= n; i++){
		for(int j = 1; j<= n; j++){
			x[i][j] = 0;
		}
	}
	for(int i = 1; i<= n; i++){
		mc[i] = 0;
	}
	for(int i = 2; i<= 2*n; i++){
		m1[i] = 0;
	}
	for(int i = 1-n; i<= n-1; i++){
		m2[i] = 0;
	}
	TRY(1);


}