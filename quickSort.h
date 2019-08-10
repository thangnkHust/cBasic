typedef int elementtype;

void swap(elementtype *a, elementtype *b){
	elementtype tmp = *a;
	*a = *b;
	*b = tmp;
}

void quickSort(elementtype element[], int L, int R){
	int pivot, i, j;
	elementtype tmp;
	if(L < R){
		i = L;
		j = R+1;
		pivot = element[L];
		do {
			do i++; while (element[i] < pivot);
			do j--; while (element[j] > pivot);
	     	if (i < j) swap(&element[i], &element[j]);
	    }while (i < j);
	    swap(&element[L], &element[j]);
	    quickSort(element, L, j-1);
	    quickSort(element, j+1, R);
	}
}