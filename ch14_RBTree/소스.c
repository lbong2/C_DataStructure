#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable : 4996)
typedef struct _node {
	char key[10];
	int red;
	struct _node* left;
	struct _node* right;
}node;
node* head;

node* rotate(char* key, node* pivot, int* base)
{
	node* child, * gchild;
	if (strcmp(key, pivot->key) == -1 || pivot == head)
		child = pivot->left;
	else
		child = pivot->right;
	if (strcmp(key, child->key) == -1) {
		gchild = child->left;
		child->left = gchild->right;
		gchild->right = child;
	}
	else {
		gchild = child->right;
		child->right = gchild->left;
		gchild->left = child;
	}
	if (strcmp(key, pivot->key) == -1 || pivot
		== base)
		pivot->left = gchild;
	else
		pivot->right = gchild;
	return gchild;
}
node* rbti_insert(char* key, node* base, int* num)
{
	node* t, * parent, * gparent, * ggparent;
	ggparent = gparent = parent = base;
	t = base->left;
	while (t != NULL) {
		if (strcmp(key, t->key) == 0) return NULL;
		if (t->left && t->right && t->left->red && t->right->red) {
			t->red = 1;
			t->left->red = t->right->red = 0;
			if (parent->red) {
				gparent->red = 1;
				if (strcmp(key, gparent->key) == -1 != strcmp(key, parent->key) == -1)
					parent = rotate(key, gparent, base);
				t = rotate(key, ggparent, base);
				t->red = 0;
			}
			base->left->red = 0;
		}
		ggparent = gparent;
		gparent = parent;
		parent = t;
		if (strcmp(key, t->key) == -1) t = t->left;
		else t = t->right;
	}
	t = (node*)malloc(sizeof(node));

	strcpy(t->key, key);
	t->left = NULL;
	t->right = NULL;
	if (strcmp(key, parent->key) == -1 || parent == base) parent->left = t;
	else parent->right = t;
	(*num)++;
	t->red = 1;
	if (parent->red)
	{
		gparent->red = 1;
		if (strcmp(key, gparent->key) == -1 != strcmp(key, parent->key) == -1)
			parent = rotate(key, gparent, base);
		t = rotate(key, ggparent, base);
		t->red = 0;
	}
	base->left->red = 0;
	return t;
}

void main() {
	char s[] = "You did a good job";
	int size = 0;
	char delim[] = ", .:";
	char* token;
	token = strtok(s, delim);
	head = (node*)malloc(sizeof(node));
	head->right = NULL;
	head->left = NULL;
	head->red = 0;
	rbti_insert(token, head, &size);
	printf("%s\n", token);
	while (token != NULL) {
		token = strtok(NULL, delim);
		if (token == NULL)
			break;
		rbti_insert(token, head, &size);
		printf("%s\n", token);
	}
	printf("%s ", head->left->key);
	printf("%s ", head->left->left->key);
	printf("%s ", head->left->left->right->key);
	printf("%s ", head->left->right->key);
	printf("%s ", head->left->right->right->key);
}