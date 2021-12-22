#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

typedef struct _dnode
{
	int key;
	struct _dnode* prev;
	struct _dnode* next;
}dnode;

dnode* dhead, * dtail;
void init_queue()
{
	dhead = (dnode*)calloc(1, sizeof(dnode));
	dtail = (dnode*)calloc(1, sizeof(dnode));
	dhead->prev = dhead;
	dhead->next = dtail;
	dtail->prev = dhead;
	dtail->next = dtail;
}
int put(int k)
{
	dnode* t;
	if ((t = (dnode*)malloc
	(sizeof(dnode))) == NULL)
	{
		printf("Out of memory !\n");
		return -1;
	}
	t->key = k;
	dtail->prev->next = t;
	t->prev = dtail->prev;
	dtail->prev = t;
	t->next = dtail;
	return k;
}
int get()
{
	dnode* t;
	int k;
	t = dhead->next;
	if (t == dtail)
	{
		printf("Queue underflow\n");
		return -1;
	}
	k = t->key;
	dhead->next = t->next;
	t->next->prev = dhead;
	free(t);
	return k;
}
void clear_queue()
{
	dnode* t, * s;
	t = dhead->next;
	while (t != dtail)
	{
		s = t;
		t = t->next;
		free(s);
	}
	dhead->next = dtail;
	dtail->prev = dhead;
}
void print_queue()
{
	dnode* t;
	t = dhead->next;
	while (t != dtail) {
		printf("% -6d", t->key);
		t = t->next;
	}
}
void main() {
	int k;
	init_queue();

	put(3);
	put(6);
	put(9);
	put(1);
	put(6);
	put(3);
	print_queue();
	put(4);
	put(8);
	put(7);
	put(2);
	put(0);
	clear_queue();
	get();
}