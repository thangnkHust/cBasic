typedef struct{
	char id[10];
	char name[50];
	int grade;
}student;

typedef student elementtype;

void swap(elementtype *a, elementtype *b){
	elementtype tmp = *a;
	*a = *b;
	*b = tmp;
}

void quickSort(elementtype element[], int L, int R){
	int i, j;
	elementtype pivot;
	elementtype tmp;
	if(L < R){
		i = L;
		j = R+1;
		strcpy(pivot.id,element[L].id);
		do {
			do i++; while (strcasecmp(element[i].id, pivot.id) < 0);
			do j--; while (strcasecmp(element[j].id, pivot.id) > 0);
	     	if (i < j) swap(&element[i], &element[j]);
	    }while (i < j);
	    swap(&element[L], &element[j]);
	    quickSort(element, L, j-1);
	    quickSort(element, j+1, R);
	}
}