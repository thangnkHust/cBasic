// Time run insertSort, heapSort cua file random(int) 1000000 so
// fin: 1000000.txt
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu(void);
void insertionSort(int a[], int n);
void heapify(int a[], int i, int n);
void swap(int *a, int *b);
void buildHeap(int a[], int n);
void heapSort(int a[], int n);


int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Error argument\n%s <file in>\n", argv[0]);
		return 0;
	}

	FILE *fin;
	if( (fin = fopen("../../file/1000000.txt", "r")) == NULL ){
		printf("Can't open file %s\n", argv[1]);
		return 0;
	}
	// srand(time(NULL));
	// for(int i = 0; i< 1000000; i++){
	// 	fprintf(fin, "%d ", rand()%1000000 + 1);
	// }
	int a[1000000];
	int i =1;
	while(!feof(fin)){
		fscanf(fin, "%d", &a[i++]);
	}
	clock_t begin1, begin2, end1, end2;

	int selec;
	do{
		selec = menu();
		switch(selec){
			case 1:
				begin1 = clock();
				insertionSort(a, 500000);
				end1 = clock();
				printf("Time run Insert Sort: %lf secs\n", (double)(end1-begin1)/CLOCKS_PER_SEC);
				break;
			case 2:
				begin2 = clock();
				heapSort(a, 1000000);
				end2 = clock();
				printf("Time run Heap Sort: %lf secs\n", (double)(end2-begin2)/CLOCKS_PER_SEC);
				break;
			case 3:
				printf("Exit!!!\n");
				break;
		}
	}while(selec != 3);

}

int menu(){
	int n;
	puts("===========MENU==========");
	puts("1.Insert sort");
	puts("2.Heap sort");
	puts("3.Exit");
	printf("Enter selection: ");
	scanf("%d", &n);
	puts("=========================");
	return n;
}

void insertionSort(int a[], int n){
	int tmp;
	for(int i =2; i<= n; i++){
		tmp = a[i];
		for(int j = i-1; j >= 0; j--){
			if(tmp < a[j]){
				a[j+1] = a[j];
				a[j] = tmp;
			}
		}
	}
}


void swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(int a[], int i, int n){
	int L = 2*i;
	int R = 2*i + 1;
	int max = i;
	if( L <= n && a[L] > a[i]){
		max = L;
	}
	if( R <= n && a[R] > a[max]){
		max = R;
	}
	if(max != i){
		swap(&a[i], &a[max]);
		heapify(a, max, n);
	}
}

void buildHeap(int a[], int n){
	for(int i = n/2; i >= 1; i--){
		heapify(a, i, n);
	}
}

void heapSort(int a[], int n){
	buildHeap(a, n);
	for(int i = n; i > 1; i--){
		swap(&a[1], &a[i]);
		heapify(a, 1, i-1);
	}
}














