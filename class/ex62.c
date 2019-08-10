#include <stdio.h>

int  multiply(int a, int b){
	if(a >= 1){
		return b+ multiply(a-1, b); 
	}
	return 0;
}

int main(){
	
	printf("%d\n", multiply(2, 6));

}