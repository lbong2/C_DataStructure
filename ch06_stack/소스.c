#include<stdio.h>
#pragma warning (disable : 4996)
#define MAX 10

int stack[MAX];
int top;

void init_stack() {
	top = -1;
}

int push(int t) {
	if (top >= MAX - 1)
	{
		printf("Stack overflow !!!\n");
		return -1;
	}
	stack[++top] = t;
	return t;
}
int pop() {
	if (top < 0) {
		printf("Stack underflow !!!\n");
		return -1;
	}
	return stack[top--];
}void main() {
	int k;
	init_stack();
	push(3);
	push(6);
	push(9);
	push(1);
	push(6);
	push(3);
	for (int i = top; i > -1; i--) {
		printf("%d\n", stack[i]);
	}
	push(4);
	push(8);
	push(7);
	push(2);
	push(0);
	init_stack();
	pop();
}