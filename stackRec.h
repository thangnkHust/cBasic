#define max 10000

typedef char elementtype;

typedef struct stackRec{
	elementtype element[max];
	int top;
}stackRec;

typedef struct stackRec stackType;

void initalize(stackType *stack){
	stack->top = 0;
}

int empty(stackType *stack){
	if(stack->top == 0) return 1;
	return 0;
}

int full(stackType *stack){
	if(stack->top == max) return 1;
	return 0;
}

void push(stackType *stack, elementtype e){
	if(full(stack))
		printf("stack overflow\n");
	else stack->element[stack->top++] = e;
}

elementtype pop(stackType *stack){
	if(empty(stack)){
		printf("stack underflow\n");
		return 0;
	}
	return stack->element[--stack->top];
}

elementtype peek(stackType *stack){
	if(empty(stack)){
		printf("stack underflow\n");
		return 0;
	}
	return stack->element[stack->top-1];
}



