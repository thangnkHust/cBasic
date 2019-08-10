// Time run of linearSearch, linearSentinelSearch, binarySearch
#include <stdio.h>
#include <time.h>

typedef int elementtype;

int menu(void);
int linearSearch(elementtype a[], int n, elementtype x);
int linearSentinelSearch(elementtype a[], int n, elementtype x);  //tim kiem tuyen tinh co linh gac 
int binarySearchRecursive(elementtype a[], elementtype x, int L, int R);

int main(){

	int selec;
	int n, result;
	clock_t begin1, end1;
	clock_t begin2, end2;
	clock_t begin3, end3;
	printf("Nhap so luong: ");
	scanf("%d", &n);
	int a[n+1];
	int x;
	// int count = 0;

	for(int i =0; i< n; i++){
		a[i] = 2*i + 3;
	}

	printf("Nhap so can tim: ");
	scanf("%d", &x);

	do{
		selec = menu();
		switch(selec){
			case 1:
				begin1 = clock();
				result = linearSearch(a, n, x);
				if(result == -1) printf("Khong co ket qua\n");
				else printf("vi tri cua %d la: %d\n", x, result);
				end1 = clock();
				printf("time search linear = %lf seconds\n", (double)(end1 - begin1)/CLOCKS_PER_SEC);
				// count++;
				break;
			case 2:
				begin2 = clock();
				result = linearSentinelSearch(a, n, x);
				if(result == n) printf("Khong co ket qua\n");
				else printf("vi tri cua %d la: %d\n", x, result);
				end2 = clock();
				printf("time search linear sentinel = %lf seconds\n", (double)(end2 - begin1)/CLOCKS_PER_SEC);
				// count++;
				break;
			case 3:
				begin3 = clock();
				result = binarySearchRecursive(a, x, 0, n-1);
				if(result == -1) printf("Khong co ket qua\n");
				else printf("vi tri cua %d la: %d\n", x, result);
				end3 = clock();
				printf("time search linear = %lf seconds\n", (double)(end3 - begin3)/CLOCKS_PER_SEC);
				// count++;
				break;
			case 4:
				puts("Exit!!!");
				break;
			default:
				puts("Enter error\nEnter again");
				break;
		}

	}while(selec != 4);

}

int menu(){
	int n;
	puts("=============MENU============");
	puts("1.Linear search");
	puts("2.Linear sentinel search");
	puts("3.Binary search by recursive");
	puts("4.Exit!!!");
	printf("Enter selction: ");
	scanf("%d", &n);
	puts("============================");
	return n;
}

int linearSearch(elementtype a[], int n, elementtype x){
	int k = 0;
	while(a[k] != x){
		k++;
	}

	if( k == n) return -1;
	return k;
}

int linearSentinelSearch(elementtype a[], int n, elementtype x){  //tim kiem tuyen tinh co linh gac 
	int k = 0;
	a[n] = x;
	while(a[k] != x){
		k++;
	}
	return k;
}

int binarySearchRecursive(elementtype a[], elementtype x, int L, int R){
	if(L > R) return -1;
	int mid = (L+R)/2;
	if(a[mid] < x)  return binarySearchRecursive(a, x, mid+1, R);
	else{
		if(a[mid] > x){
			return binarySearchRecursive(a, x, L, mid-1);
		}else
			return mid;
	}
	return -1;
}








