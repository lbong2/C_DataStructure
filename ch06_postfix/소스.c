#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)

typedef struct _node
{
	int key;
	struct _node* next;
}node;

node* head, * tail;

void init_stack()
{
	head = (node*)calloc(1, sizeof(node));
	tail = (node*)calloc(1, sizeof(node));
	head->next = tail;
	tail->next = tail;
}
int push(int k)
{
	node* t;
	if ((t = (node*)malloc(sizeof(node))) == NULL)
	{
		printf("Out of memory !\n");
		return -1;
	}
	t->key = k;
	t->next = head->next;
	head->next = t;
	return k;
}
int pop()
{
	node* t;
	int k;
	if (head->next == tail) {
		printf("Stack underflow!\n");
		return -1;
	}
	t = head->next;
	k = t->key;
	head->next = t->next;
	free(t);
	return k;
}
void postfix(char* dst, char* src) {
	char c;
	init_stack();

	while (*src) {
		if (*src == ')')	// 오른쪽 괄호일때 
		{
			*dst++ = pop();	// dst에 pop
			*dst++ = ' ';	// 가독성을 위한 공백
			src++;	// 다음 문자열
		}
		else if (*src == '+' || *src == '-' ||
			*src == '*' || *src == '/')	// operation이라면 
		{
			push(*src);	// operation을 푸쉬
			src++;
		}
		else if (*src >= '0' && *src <= '9')	// 숫자라면
		{
			do {
				*dst++ = *src++;	// dst에 저장
			} while (*src >= '0' && *src <= '9');
			*dst++ = ' ';	// 
		}
		else
			src++;
	}
	*dst = 0;	// dst를 스트링으로 만들어줌
}
void main() {
	char exp[256];
	char src[256] = "(1+(2*3))";

	postfix(exp, src);
	printf("\nPostfix representation : %s\n", exp);
}