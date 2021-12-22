#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)
#define MAX 100
typedef struct _node {
	int key;
	struct _node* left;
	struct _node* right;
}node;
node* head, * tail;
node* stack[MAX];
int top;
void init_stack() {
	top = -1;
}
int is_stack_empty() {
	return (top == -1);
}
node* push(node* t) {
	stack[++top] = t;
	return t;
}
node* pop() {
	return stack[top--];
}
int is_operator(int k) {
	return (k == '+' || k == '-' || k == '*' || k == '/');
}

int calcPostFixEq(char* p) {
	node* t;
	int tmp;
	init_stack();
	while (*p) {
		while (*p == ' ') p++;
		t = (node*)calloc(1, sizeof(node));
		t->key = atoi(*p);
		t->left = tail;
		t->right = tail;
		if (is_operator(*p)) {
			t->left = pop();
			t->right = pop();
			switch (*p) {
			case '+':
				tmp = t->left->key + t->right->key ;
				break;
			case '-':
				tmp = t->left->key - t->right->key;
				break;
			case '*':
				tmp = t->left->key * t->right->key;
				break;
			case '/':
				tmp = t->left->key / t->right->key;
				break;
			}
			t->key = tmp;
		}
		push(t);
		p++;
	}
	return pop()->key;
}
void main() {
	char eqn[100] = "3 9 / 3 9 * – 5 –";
	int result;

	result = calcPostFixEq(eqn);
	printf("result = %d\n", result);

}