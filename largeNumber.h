// Library tinh toan voi large number

stackType sumLargeNumber(char str1[], char str2[], stackType stack1, stackType stack2, stackType stack3);
int compare(char str1[], char str2[]);
stackType subtractionLargeNumber(char str1[], char str2[], stackType stack1, stackType stack2, stackType stack3);

stackType sumLargeNumber(char str1[], char str2[], stackType stack1, stackType stack2, stackType stack3){	//tinh tong
	int mark = 0;
	int tmp = 0;
	for(int i =0; i < strlen(str1); i++){
		if(str1[0] != '-')
			push(&stack1, str1[i]-48);
	}
	for(int i =0; i < strlen(str2); i++){
		if(str2[0] != '-')
			push(&stack2, str2[i]-48);
	}
	if(str1[0] != '-' && str2[0] != '-'){		//Tong 2 so duong
		// int mark = 0;
		// int tmp;

		while(!empty(&stack1) && !empty(&stack2)){
			tmp = pop(&stack1) + pop(&stack2);
			tmp += mark;
			mark = 0;
			if(tmp >= 10){
				tmp = tmp%10;
				mark = 1;
				push(&stack3, tmp);
			}else{
				tmp = tmp%10;
				push(&stack3, tmp);
			}
		}
		while(!empty(&stack1)){
			tmp = pop(&stack1);
			tmp += mark;
			mark = 0;
			if(tmp >= 10){
				tmp = tmp%10;
				mark = 1;
				push(&stack3, tmp);
			}else{
				tmp = tmp%10;
				push(&stack3, tmp);
			}
		}
		// if(mark == 1)
		// 	push(1,&stack3);
		while(!empty(&stack2)){
			tmp = pop(&stack2);
			tmp += mark;
			mark = 0;
			if(tmp >= 10){
				tmp = tmp%10;
				mark = 1;
				push(&stack3, tmp);
			}else{
				tmp = tmp%10;
				push(&stack3, tmp);
			}
		}
		if(mark == 1) push(&stack3, mark);
	}
	if(str1[0] == '-' && str2[0] != '-'){		//Tong so am va so duong
		char tmp[max];
		strcpy(tmp, str1);
		for(int i =0; i<strlen(tmp); i++){
			tmp[i] = tmp[i+1];
		}
		// puts(tmp);
		stack3 = subtractionLargeNumber(tmp, str2, stack1, stack2, stack3);
	}
	if(str2[0] == '-' && str1[0] != '-'){		//Tong so duong va am (error khi so am lon hon so duong)
		char temp[max];
		strcpy(temp, str2);
		for(int i =0; i<strlen(temp); i++){
			temp[i] = temp[i+1];
		}
		puts(temp);
		stack3 = subtractionLargeNumber(str1, temp, stack1, stack2, stack3);
	}
	if(str1[0] == '-' && str2[0] == '-'){		//Tong so am va so am (error)
		while(!empty(&stack1) && !empty(&stack2)){
			tmp = pop(&stack1) + pop(&stack2);
			tmp += mark;
			mark = 0;
			if(tmp >= 10){
				tmp = tmp%10;
				mark = 1;
				push(&stack3, tmp);
			}else{
				tmp = tmp%10;
				push(&stack3, tmp);
			}
		}
		while(!empty(&stack1)){
			tmp = pop(&stack1);
			tmp += mark;
			mark = 0;
			if(tmp >= 10){
				tmp = tmp%10;
				mark = 1;
				push(&stack3, tmp);
			}else{
				tmp = tmp%10;
				push(&stack3, tmp);
			}
		}
		while(!empty(&stack2)){
			tmp = pop(&stack2);
			tmp += mark;
			mark = 0;
			if(tmp >= 10){
				tmp = tmp%10;
				mark = 1;
				push(&stack3, tmp);
			}else{
				tmp = tmp%10;
				push(&stack3, tmp);
			}
		}
		if(mark == 1) push(&stack3, 1);
		int b = pop(&stack3);
		push(&stack3, -b);
	}

	return stack3;
}

// function so sanh 2 so dung de tinh so nho tru so to
int compare(char str1[], char str2[]){
	if(strlen(str1) > strlen(str2)) return 1;
	if(strlen(str1) < strlen(str2)) return -1;
	if(strlen(str1) == strlen(str2)){
		for(int i =0; i<strlen(str1); i++){
			if(str1[i] < str2[i]) return -1;
			if(str1[i] > str2[i]) return 1;
		}
	}
	return 0;
}

// tinh hieu
stackType subtractionLargeNumber(char str1[], char str2[], stackType stack1, stackType stack2, stackType stack3){
	int mark = 0;
	int count1 = 0, count2 = 0;
	//init from string to stack
	for(int i =0; i < strlen(str1); i++){
		if(str1[i] != '-'){
			push(&stack1, str1[i]-48);
			// count1++;
		}

	}
	for(int i =0; i < strlen(str2); i++){
		if(str2[i] != '-'){
			push(&stack2, str2[i]-48);
			// count2++;
		}
	}

	int tmp;

	if(compare(str1, str2) >= 0){
		while(!empty(&stack1) && !empty(&stack2)){
			tmp = pop(&stack1) - pop(&stack2) + mark;
			mark = 0;
			if(tmp < 0){
				tmp += 10;
				mark = -1;
				push(&stack3, tmp);
			}else{
				push(&stack3, tmp);
			}
		}

		while(!empty(&stack1)){
			tmp = pop(&stack1)%10 + mark;
			mark = 0;
			push(&stack3, tmp);
		}
	}else{
		initalize(&stack1);
		initalize(&stack2);
		stack3 = subtractionLargeNumber(str2, str1, stack1, stack2, stack3);
		int a = pop(&stack3);
		push(&stack3, -a);
	}

	return stack3;
}

