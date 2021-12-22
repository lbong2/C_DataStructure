#include<stdio.h>
#pragma warning(disable : 4996)

typedef struct _node
{
	int key;
	struct _node* next;
}node;

node* head, * tail;

void init_list()
{
	head = (node*)calloc(1, sizeof(node));
	tail = (node*)calloc(1, sizeof(node));
	head->next = tail;
	tail->next = tail;
}
int delete_node(int k)
{
	node* s, * p;
	p = head;
	s = p->next;
	while (s->key != k && s != tail) {
		p = p->next;
		s = p->next;
	}
	if (s != tail) {
		p->next = s->next;
		free(s);
		return 1;
	}
	else return 0;
}
node* insert_node(int t, int k)
{
	node* s, * p, * r;
	p = head;
	s = p->next;
	while (s->key != k && s != tail) {
		p = p->next;
		s = p->next;
	}
	if (s != tail) {
		r = (node*)calloc(1, sizeof(node));
		r->key = t;
		r->next = s->next;
		s->next = r;
		printf("%d insert after list(key : %d)\n", t, k);
	}
	return p->next;
}
node* ordered_insert(int k)
{
	node* s, * p, * r;
	p = head;
	s = p->next;
	while (s->key <= k && s != tail) {
		p = p->next;
		s = p->next;
	}
	r = (node*)calloc(1, sizeof(node));
	r->key = k;
	p->next = r;
	r->next = s;
	return r;
}
void find_node(int k)
{
	node* temp;
	int list_cnt = 1;
	temp = head->next;
	while (temp->key != k && temp != tail)
	{
		temp = temp->next;
		list_cnt++;
	}
	if (temp == tail) {
		printf("List don't have %d\n", k);
	}
	else printf("%d is in list %d\n", k, list_cnt);
	
}
void print_list(node* t)
{
	while (t != tail) {
		printf("%-8d", t->key);
		t = t->next;
	}
	printf("\n");
}
node* delete_all()
{
	node* s;
	node* t;
	t = head->next;
	while (t != tail)
	{
		s = t;
		t = t->next;
		free(s);
	}
	head->next = tail;
	return head;
}
void main() {
	node* t;
	int input_key;
	init_list();
	ordered_insert(9);
	ordered_insert(3);
	ordered_insert(5);
	ordered_insert(1);
	ordered_insert(7);
	t = head->next;
	printf("========Initial list========\n");
	print_list(t);
	printf("Please input the key number that you want to find >> ");
	scanf("%d", &input_key);
	find_node(input_key);
	printf("\n");

	insert_node(6, 5);
	print_list(t);
	printf("\n");

	printf("Please input key that you want to delete >> ");
	scanf("%d", &input_key);
	if (delete_node(input_key))
		printf("Delete success\n");
	else printf("%d is not in list\n", input_key);
	print_list(t);

	delete_all();
}