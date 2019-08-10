// kiem tra xem co phai day doi xung khong (dung de quy)
#include <stdio.h>
#include <string.h>

void checkPalindrome(char str[], int check){
	printf("%d\n", strlen(str));
	int len = strlen(str) - (check+1);
	if(str[check] == str[len]){
		if(check == len + 1 || check == len){
			printf("xau doi xung\n");
			return;
		}
		checkPalindrome(str, check +1);
	}else{
		printf("xau khong doi xung\n");
	}
}

int main(){

	char str[20] = "abcdeedcba";
	checkPalindrome(str, 0);

}