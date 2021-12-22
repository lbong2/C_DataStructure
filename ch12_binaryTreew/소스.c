#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable : 4996)


typedef struct _node {
	int key;
	struct _node* left;
	struct _node* right;
}node;
node* base;
node* bti_search(int key, node* base, int* num)
{
	node* s;
	s = base->left; // root node
	while (key != s->key && s != NULL)
	{
		if (key < s->key)
			s = s->left;
		else
			s = s->right;
	}
	if (s == NULL) return NULL;
	else return s;
}
node* bti_insert(int key, node* base, int* num)
{
	node* p, * s;
	p = base;
	s = base->left;
	while (s != NULL) {
		p = s;
		if (key < s->key) s = s->left;
		else s = s->right;
	}
	s = (node*)malloc(sizeof(node));
	s->key = key;
	s->left = NULL;
	s->right = NULL;
	if (key < p->key || p == base) p->left = s;
	else p->right = s;
	(*num)++;
	return s;
}
node* bti_delete1(int key, node* base, int* num)
{
	node* parent, * son, * del, * nexth;
	parent = base;
	del = base->left;
	while (key != del->key && del != NULL) {
		parent = del;
		if (del->key > key) del = del->left;
		else del = del->right;
	}
	if (del == NULL) return NULL;
	if (del->left == NULL && del->right == NULL)
		son = NULL;
	else if (del->left != NULL && del->right != NULL)
	{
		nexth = del->right;
		if (nexth->left != NULL) {
			while (nexth->left->left != NULL) nexth = nexth->left;
			son = nexth->left;
			nexth->left = son->right;
			son->left = del->left;
			son->right = del->right;
		}
		else
		{
			son = nexth;
			son->left = del->left;
		}
	}
	else
	{
		if (del->left != NULL) son = del->left;
		else son = del->right;
	}
	if (key < parent->key || parent == base)
		parent->left = son;
	else
		parent->right = son;
	free(del);
	(*num)--;
	return parent;
}
node* bti_delete(int key, node* base, int* num)
{
	node* parent, * son, * del, * nexth;
	parent = base;
	del = base->left;
	while (key != del->key && del != NULL) {
		parent = del;
		if (del->key > key) del = del->left;
		else del = del->right;
	}
	if (del == NULL) return NULL;
	/* same with bti_delete1() for finding del node */
	if (del->right == NULL) son = del->left;
	else if (del->right->left == NULL) {
		son = del->right;
		son->left = del->left;
	}
	else {
		nexth = del->right;
		while (nexth->left->left != NULL) nexth = nexth->left;
		son = nexth->left;
		nexth->left = son->right;
		son->left = del->left;
		son->right = del->right;
	}
	if (key < parent->key || parent == base)
		parent->left = son;
	else
		parent->right = son;
	free(del);
	(*num)--;
	return parent;
	/* same with bti_delete1() for making connections with new parent */
}
node* _balance(int N, int* a, int* index)
{
	int nl, nr;
	node* p;
	if (N > 0) {
		nl = (N - 1) / 2;
		nr = N - nl - 1;
		p = (node*)malloc(sizeof(node));
		p->left = _balance(nl, a, index);
		p->key = a[(*index)++];
		p->right = _balance(nr, a, index);
		return p;
	}
	else return NULL;
}
void bti_sort(node* p, int* a, int* index)
{
	if (p != NULL)
	{
		bti_sort(p->left, a, index);
		a[(*index)++] = p->key;
		bti_sort(p->right, a, index);
	}
}
void main() {
	int num = 0;
	node* tmp;
	base = (node*)malloc(sizeof(node));
	base->left = NULL;
	base->right = NULL;
	bti_insert('A', base, &num);
	bti_insert('B', base, &num);
	bti_insert('C', base, &num);
	bti_insert('D', base, &num);
	bti_insert('F', base, &num);
	bti_insert('O', base, &num);
	bti_insert('L', base, &num);
	bti_insert('G', base, &num);
	bti_insert('H', base, &num);
	bti_insert('K', base, &num);
	bti_insert('M', base, &num);
	bti_insert('N', base, &num);
	int arr[13];
	int index = 0;
	bti_sort(base, arr, &index);
	index = 0;
	base->left = _balance(num, arr, &index);

	printf("%c\n", base->left->right->key);	// 'L'
	printf("%c\n", base->left->right->left->key);	// 'H'
	printf("%c\n", base->left->left->left->key);	// 'A'
}