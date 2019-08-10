#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu(void);
void insertionSort(int a[], int n);
void selectionSort(int a[], int n);
void bubbleSort(int a[], int n);

void swap(int *a, int *b);
void heapify(int a[], int i, int n);
void buildHeap(int a[], int n);
void heapSort(int a[], int n);

int main(){

	int *a = (int*)malloc(sizeof(int)*2000000);
	srand(time(NULL));

	int selec, case1 = 0;
	clock_t begin1, end1, begin2, end2, begin3, end3, begin4, end4;
	int n;

	do{
		selec = menu();
		switch(selec){
			case 1:
				printf("Nhap so luong: ");
				scanf("%d", &n);
				for(int i = 1; i<= n; i++){
					a[i] = rand()%n+1;
				}
				puts("Build array success");
				case1 = 1;
				break;
			case 2:
				if(case1 == 0){
					printf("Don't run case 1, run again\n");
					break;
				}
				begin1 = clock();
				insertionSort(a, n);
				end1 = clock();
				printf("Time run insertionSort: %lf secs\n", (double)(end1 - begin1)/CLOCKS_PER_SEC);
				break;
			case 3:
				if(case1 == 0){
					printf("Don't run case 1, run again\n");
					break;
				}
				begin2 = clock();
				selectionSort(a, n);
				end2 = clock();
				printf("Time run selectionSort: %lf secs\n", (double)(end2 - begin2)/CLOCKS_PER_SEC);
				break;
			case 4:
				if(case1 == 0){
					printf("Don't run case 1, run again\n");
					break;
				}
				begin4 = clock();
				bubbleSort(a, n);
				end4 = clock();
				printf("Time run bubbleSort: %lf secs\n", (double)(end4 - begin4)/CLOCKS_PER_SEC);
				break;
			case 5:
				if(case1 == 0){
					printf("Don't run case 1, run again\n");
					break;
				}
				begin3 = clock();
				heapSort(a, n);
				end3 = clock();
				printf("Time run heapSort: %lf secs\n", (double)(end3 - begin3)/CLOCKS_PER_SEC);
				break;
			case 6:
				puts("Exit!!!");
				break;
		}
	}while(selec != 6);

}

int menu(){
	puts("=========MENU========");
	puts("1.Tao du lieu");
	puts("2.Insertion sort");
	puts("3.Selection sort");
	puts("4.Bubble sort");
	puts("5.Heap sort");
	puts("6.Exit!!!");
	int n;
	printf("Enter selection: ");
	scanf("%d", &n);
	puts("=====================");
	return n;
}

void insertionSort(int a[], int n){
	int tmp;
	for(int i =2; i<=n; i++){
		tmp = a[i];
		for(int j = i-1; j >= 1; j--){
			if(tmp < a[j]){
				a[j+1] = a[j];
				a[j] = tmp;
			}
		}
	}
}

void selectionSort(int a[], int n){
	int tmp, min;
	for(int i =1; i < n; i++){
		min = i;
		for(int j = i+1; j <= n; j++){
			if(a[j] < a[min]){
				min = j;
			}
		}
		tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
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

void bubbleSort(int a[], int n){
	for(int i = 1; i< n; i++){
		for(int j = 1; j< n-i; j++){
			if(a[j] > a[j+1]){
				swap(&a[j], &a[j+1]);
			}
		}
	}
}









