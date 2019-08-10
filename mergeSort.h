typedef int elementtype;

void merge(elementtype element[], int L, int M, int R){
	int tmp[R-L+1];
	int i = L;
	int j = M+1;
	int k = 0;
	for(int k = L; k <= R; k++){
		if(i > M){
			tmp[k] = element[j];
			j++;
		}else{
			if(j > R){
				tmp[k] = element[i];
				i++;
			}else{
				if(element[i] < element[j]){
					tmp[k] = element[i];
					i++;
				}else{
					tmp[k] = element[j];
					j++;
				}
			}
		}
	}
	for(int k = L ; k <= R; k++){
		element[k] = tmp[k];
	}
	// while(i < M+1 && j < R+1){
	// 	if(element[i] < element[j]){
	// 		tmp[k] = element[i];
	// 		k++;
	// 		i++;
	// 	}else{
	// 		tmp[k] = element[j];
	// 		k++;
	// 		j++;
	// 	}
	// }
	// while(i < M+1){
	// 	tmp[k] = element[i];
	// 	k++;
	// 	i++;
	// }
	// while(j < R+1){
	// 	tmp[k] = element[j];
	// 	k++;
	// 	j++;
	// }
	// i = L;
	// for(int m = 0; m < R-L+1; m++){
	// 	element[m] = tmp[i];
	// 	i++;
	// }
}

void mergeSort(elementtype element[], int L, int R){
	if(L < R){
		int M = (L+R)/2;
		mergeSort(element, L, M);
		mergeSort(element, M+1, R);
		merge(element, L, M, R);
	}
}