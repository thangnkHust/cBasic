#include<stdio.h>

#define default 5

void input(int *array, int n){
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &array[i]);
	}
}

int compare(int *arr1, int *arr2, int n){
	int dem = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr1[i] == arr2[i])
		{
			if (i == n-1)
			{
				return 1;
			}
		}
		if (arr1[i] == arr2[n-i-1])
		{
			dem++;
			if (dem == n)	
			{
				return -1;
			}
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	
	int arr1[default], arr2[default];

	input(arr1, default);
	input(arr2, default);

	if (compare(arr1, arr2, default) == 1)
	{
		printf("2 mang giong nhau\n");
	}else if (compare(arr1, arr2, default) == -1)
	{		
		printf("2 mang doi nhau\n");
	}else
		printf("2 mang khac nhau \n");

	return 0;
}
