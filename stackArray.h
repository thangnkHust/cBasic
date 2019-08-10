#define max 10000
typedef int elementtype;
typedef elementtype stackType[max];
int top;

void initalize(stackType stack){
	top = 0;
}

int empty(stackType stack){
	if(top == 0) return 1;
	return 0;
}

int full(stackType stack){
	if(top == max) return 1;
	return 0;
}

void push(stackType stack, elementtype e){
	if(full(stack))
		printf("stack overflow\n");
	else stack[top++] = e;
}

elementtype pop(stackType stack){
	if(empty(stack)){
		printf("stack underflow\n");
		return -99999;
	}
	return stack[--top];
}

elementtype peek(stackType stack){
	if(empty(stack)){
		printf("stack underflow\n");
		return -999999;
	}
	return stack[top-1];
}