#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)
#define MAX 100
typedef struct _node
{
	char key;
	struct _node* left;
	struct _node* right;
}node;
int front, rear;
node* head, * tail;
node* queue[MAX];
void init_queue() {
	front = rear = 0;
}
int is_queue_empty() {
	return (front == rear);
}
node* put(node* t) {
	queue[rear] = t;
	rear = ++rear % MAX;
	return t;
}
node* get() {
	node* t;
	t = queue[front];
	front = ++front % MAX;
	return t;
}
void init_tree()
{
	head = (node*)calloc(1, sizeof(node));
	tail = (node*)calloc(1, sizeof(node));
	head->left = tail;
	head->right = tail;
	tail->left = tail;
	tail->right = tail;
}
node* set_tree(node* t, int k)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp->key = k;
	if (t->left == tail)
	{
	t->left = tmp;
	tmp->left = tail;
	tmp->right = tail;
	}
	else if (t->right == tail) {
	t->right = tmp;
	tmp->left = tail;
	tmp->right = tail;
	}
	
	else
		printf("Node's children is full\n");
	return tmp;
}
void visit(node* t) {
	printf("%c is visited\n", t->key);
}
void preorder_traverse(node* t)
{
	if (t != tail)
	{
		visit(t);
		preorder_traverse(t->left);
		preorder_traverse(t->right);
	}
}
void inorder_traverse(node* t)
{
	if (t != tail)
	{
		inorder_traverse(t->left);
		visit(t);
		inorder_traverse(t->right);
	}
}

void postorder_traverse(node* t) {
	if (t != tail) {
		postorder_traverse(t->left);
		postorder_traverse(t->right);
		visit(t);
	}
}
void levelorder_traverse(node* t) {
	put(t);
	while (!is_queue_empty()) {
		t = get();
		visit(t);

		if (t->left != tail)
			put(t->left);
		if (t->right != tail)
			put(t->right);
	}
}
void main() {
	init_tree();
	node* t = (node*)malloc(sizeof(node));
	t->key = 'A';
	head->right = t;
	head->left = t;
	t->right = tail;
	t->left = tail;
	t = head->right;
	set_tree(t, 'B');
	set_tree(t, 'C');
	t = t->left;
	set_tree(t, 'D');
	set_tree(t, 'E');
	t = t->left;
	set_tree(t, 'G');
	set_tree(t, 'H');
	t = head->right->right;
	set_tree(t, 'F');
	t = t->left;
	t = set_tree(t, 'I');

	t = head->left;
	preorder_traverse(t);
	printf("\n");
	inorder_traverse(t);
	printf("\n");
	postorder_traverse(t);
	printf("\n");
	levelorder_traverse(t);
	printf("\n");
	free(t);

}