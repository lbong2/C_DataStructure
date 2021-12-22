#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable : 4996)
typedef struct _node { struct _node* next; } node;
typedef int (*FCMP)(const void*, const void*);
void init_list(node**);
void* llv_search(void* key, node* base, int* num, int width, FCMP fcmp);
node* llv_insert(void* key, node* base, int* num, int width, FCMP fcmp);
void* llv_delete(void* key, node* base, int* num, int width, FCMP fcmp);

int intcmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
#define LEN 5
void main() {
	void* p;
	node* t, * head;
	int size = 0, key = 9;
	int data[LEN] = { 3, 1, 9, 7, 5 };
	init_list(&t); // using the pointer t
	head = (node*)malloc(sizeof(node));
	head->next = t;
	for (int i = 0; i < LEN; i++) {
		p = llv_insert(data + i, t, &size, sizeof(int), intcmp);

		printf("%d is insert\n", *((node*)p + 1));
	}
	printf("\nPrint Linked-List\n");
	for (t = t->next; t != NULL; t = t->next) {
		printf("%d ", *(t + 1));
	}
	t = head->next;
	p = llv_search(&key, t, &size, sizeof(int), intcmp);
	printf("\nSearched key '%d' is in index %d\n", *((node*)p + 1), size);
	
}
void init_list(node** p) {
	*p = (node*)malloc(sizeof(node));
	(*p)->next = NULL;
}

node* llv_insert(void* key, node* base, int* num, int width, FCMP fcmp)
{
	node* t;
	t = (node*)malloc(sizeof(node) + width);
	memcpy(t+1, key, width);
	t->next = base->next;
	base->next = t;
	(*num)++;
	return t;
}
void* llv_search(void* key, node* base, int* num, int width, FCMP fcmp)
{
	node* t;
	t = base->next;
	*num = 0;
	while (fcmp(t + 1, key) != 0 && t != NULL) {
		t = t->next;
		(*num)++;
	}
	return (t == NULL ? NULL : t);
}
void* llv_delete(void* key, node* base, int* num, int width, FCMP fcmp) {
	node* t, *s;
	void* k;
	s = base;
	t = base->next;
	
	while (fcmp(t + 1, key) != 0 && t != NULL) {
		s = s->next;
		t = t->next;
	}
	if (t != NULL) {
		k = t + 1;
		s->next = t->next;
		free(t);
		return k;
	}
	else{
		return NULL;
	}

}
