typedef struct{
	char name[50];
	char tel[15];
	char email[50];
}telephone;

typedef telephone elementtype;

void swap(elementtype *a, elementtype *b){
	elementtype tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(elementtype element[], int i, int n){
	int L = 2*i;
	int R = 2*i+1;
	int max = i;
	if(strcasecmp(element[L].name, element[max].name) > 0 && L <= n){
		max = L;
	}
	if(strcasecmp(element[R].name, element[max].name) > 0 && R <= n){
		max = R;
	}
	if(i != max){
		swap(&element[i], &element[max]);
		heapify(element, max, n);
	}
}

void buildHeap(elementtype element[], int n){
	for(int i = n/2; i>= 1; i--){
		heapify(element, i, n);
	}
}

void heapSort(elementtype element[], int n){
	buildHeap(element, n);
	for(int i = n; i > 1; i--){
		swap(&element[1], &element[i]);
		heapify(element, 1, i-1);
	}
}



