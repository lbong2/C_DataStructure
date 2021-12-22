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
		if (*src == ')')	// ������ ��ȣ�϶� 
		{
			*dst++ = pop();	// dst�� pop
			*dst++ = ' ';	// �������� ���� ����
			src++;	// ���� ���ڿ�
		}
		else if (*src == '+' || *src == '-' ||
			*src == '*' || *src == '/')	// operation�̶�� 
		{
			push(*src);	// operation�� Ǫ��
			src++;
		}
		else if (*src >= '0' && *src <= '9')	// ���ڶ��
		{
			do {
				*dst++ = *src++;	// dst�� ����
			} while (*src >= '0' && *src <= '9');
			*dst++ = ' ';	// 
		}
		else
			src++;
	}
	*dst = 0;	// dst�� ��Ʈ������ �������
}
void main() {
	char exp[256];
	char src[256] = "(1+(2*3))";

	postfix(exp, src);
	printf("\nPostfix representation : %s\n", exp);
}