// Test ngoac dung stack
// check 1, tu dau da dong ngoac ->return 0
// 		 2,	thua dau dong ngoac ->return 0
// 		 3, thua dau mo ngoac ->check empty stack ->return 0
// 		 4, check init error ->exit(0)
// Sua trong stackList.h ve typedef ngoac elementtype 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../stackList.h"
#define max 1000

int match(char a, char b){
	if(a == '(' && b == ')') return 1;
	if(a == '[' && b == ']') return 1;
	if(a == '{' && b == '}') return 1;
	return 0;
}

void check(FILE *fin){
	stackType *S;
	initalize(&S);
	char str[max];
	int count = 0;
	char k;
	int line;
	elementtype e;

	while(fgets(str, max, fin) != NULL){
		count++;
		for(int i =0; i<strlen(str); i++){
			if(str[i] == '(' || str[i] == '[' || str[i] == '{'){	//neu ngoac mo thi push(char, line);
				e.line = count;
				e.c = str[i];
				push(&S, e);
				// printf("%c-%d\n", peek(&S).c, peek(&S).line);
			}else{
				if(str[i] == ')' || str[i] == ']' || str[i] == '}'){	//neu ngoac dong thi check with pop(&S)
					if(empty(&S)){										//co ngoac dong ma khong co mo
						printf("Error thua %c and line %d\n", str[i], count);
						return;
					}
					k = peek(&S).c;
					line = pop(&S).line;
					if(match(k, str[i]) == 0){					//ngoac dong va mo khong doi xung
						printf("Error %c <=> %c and line %d <=> %d\n", k, str[i], line, count);
						return;
					}
				}
				
			}
		}
	}
	if(empty(&S)){
		printf("Check OK\n");
	}else{
		while(!empty(&S)){		//thua ngoac mo
			printf("Error thua %c and line %d\n", peek(&S).c, pop(&S).line);
		}
	}
	
}

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Syntax error\n%s <file in>\n", argv[0]);
		return 0;
	}

	FILE *fin;

	if((fin = fopen(argv[1], "r")) == NULL){
		printf("Can not open file %s\n", argv[1]);
		return 0;
	}

	check(fin);

}










