// uoc chung lon nhat va boi chung nho nhat	
#include <stdio.h>

int GCD(int a, int b){
	
	if(a > b)
		return GCD(a-b, b);
	else
		if(a < b)
			return GCD(a, b-a);
	return a;
}

int LCM(int a, int b){
	static int mark = 1;
	if(mark%a == 0 && mark%b == 0){
		return mark;
	}
	mark++;
	return LCM(a, b);
}

int main(){
	printf("%d\n", GCD(3,5));
	printf("%d\n", LCM(3,5));
}