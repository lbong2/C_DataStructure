#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
typedef int(*FCMP)(const void*, const void*);
typedef struct _node {
	struct _node* left;
	struct _node* right;
}node;
typedef struct _wcount {
	int count;
	char word[20];
}wcount;
void init_tree(node** p) {
	
	*p = (node*)malloc(sizeof(node));
	(*p)->left = NULL;
	(*p)->right = NULL;
	
}
int wcount_cmp(const void* a, const void* b)
{
	return strcmp( ((wcount*)a)->word, ((wcount*)b)->word );
}
void* btv_search(void* key, node* base, int* num, int width, FCMP fcmp) {
	node* s;
	s = base->left; // root node
	while (s != NULL)
	{
		if (fcmp(s + 1, key) == 0) {
			return (s + 1);
		}
		if (fcmp(s + 1, key) == -1)
			s = s->right;
		else
			s = s->left;
	}
	if (s == NULL) return NULL;
	else return (s + 1);
}

void* btv_insert(void* key, node* base, int* num, int width, FCMP fcmp)
{
	node* p, *s;
	
	p = base;
	s = base->left;
	while (s != NULL && fcmp(s + 1, key) != 0)
	{
		p = s;
		if (fcmp(s + 1, key) == -1) {
			
			s = s->right;
		}
		else {
			
			s = s->left;
		}
	}
	s = (node*)malloc(sizeof(node) + width);
	memcpy(s + 1, key, width);
	s->left = NULL;
	s->right = NULL;
	if (fcmp(key, p + 1) == -1 || p == base) p->left = s;
	else p->right = s;
	(*num)++;
	return s + 1;
}

void btv_list(node* p, void(*fptr)(void*))
{
	int i;
	static int x = 0;
	if (p != NULL)
	{
		x += 2; // position for displaying a node
		// a kind of inorder traverse
		btv_list(p->right, fptr);
		for (i = 2; i < x; i++) printf("  ");
		fptr(p + 1); // print it in the monitor
		btv_list(p->left, fptr);
		x -= 2;
	}
}
int _index = 0;
void _deleteall(node* t)
{
	if (t != NULL) {
		_deleteall(t->left); _deleteall(t->right); free(t);
	}
}
void* btv_deleteall(node* base, int* num)
{
	node* t;
	t = base->left;
	_deleteall(t);
	base->left = NULL;
	base->right = NULL;
	*num = 0;
	return base;
}
node* _balance(int N, void* a, int width)
{
	int i = 0;
	int nl, nr;
	node* p;
	if (N > 0) {
		nl = (N - 1) / 2;
		nr = N - nl - 1;
		p = (node*)malloc(sizeof(node) + width);
		p->left = _balance(nl, a, width);
		memcpy(p + 1, (char*)a + _index++ * width,  width);
		p->right = _balance(nr, a, width);
		return p;
	}
	else return NULL;
}
void _sort(node* p, void* a, int width)
{
	
	if (p != NULL)
	{
		_sort(p->left, a, width);
		memcpy((char*)a + _index++ * width, p + 1, width);
		_sort(p->right, a, width);
	}
}
void btv_balance(node* base, int* num, int width)
{
	void* tmp;
	int ntmp = *num;
	tmp = malloc(width * ntmp);
	_index = 0;
	_sort(base->left, tmp, width);
	ntmp = *num;
	btv_deleteall(base, num);
	_index = 0;
	base->left = _balance(ntmp, tmp, width);
	*num = ntmp;
	free(tmp);
}
