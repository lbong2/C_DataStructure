#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning (disable : 4996)
#define MAX 100

typedef int(*FCMP)(const void*, const void*);
int stack[MAX];
int top;
#define BASE(i) (char*)base + width * i

int intcmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}



void init_stack() {
	top = -1;
}

int push(int t) {
	if (top >= MAX - 1)
	{
		printf("Stack overflow !!!\n");
		return -1;
	}
	stack[++top] = t;
	return t;
}
int pop() {
	if (top < 0) {
		printf("Stack underflow !!!\n");
		return -1;
	}
	return stack[top--];
}
int is_empty() {
	return (top == -1);
}
void insert_sort(int* a, int N)
{
	int i, j, t;
	for (i = 1; i < N; i++)
	{
		t = a[i];
		j = i;
		while (j > 0 && a[j - 1] > t)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = t;
	}
}


void quick_sort(int* a, int N)
{
	int v, t;
	int i, j;
	if (N > 1) // termination
	{
		v = a[N - 1]; // pivot
		i = -1;
		j = N - 1;
		while (1) {
			while (a[++i] < v); // 두개 값 구하기
			while (a[--j] > v); // 
			if (i >= j) break;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
			t = a[i];
		a[i] = a[N - 1];
		a[N - 1] = t;
		quick_sort(a, i);
		quick_sort(a + i + 1, N - i - 1);
	}
}
void quick_sort1(int* a, int N)
{
	int v, t;
	int i, j;
	int l, r;
	init_stack();
	l = 0;
	r = N - 1;
	push(r);
	push(l);
	while (!is_empty()) {
		l = pop();
		r = pop();
		if (r - l + 1 > 1) // termination
		{
			v = a[r];
			i = l - 1;
			j = r;
			while (1) {
				while (a[++i] < v);
				while (a[--j] > v);
				if (i >= j) break;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			t = a[i];
			a[i] = a[r];
			a[r] = t;
			push(r);
			push(i + 1);
			push(i - 1);
			push(l);
		}
	}
}
int random(int a) {
	return rand() % a;
}
void quick_sort2(int a[], int n)
{
	/* 재귀호출 없앤 퀵 정렬 */
	int v, t;
	int i, j;
	int l, r;
	init_stack();
	l = 0;
	r = n - 1;
	push(r);
	push(l);
	while (!is_empty())
	{
		l = pop();
		r = pop();
		if (r - l + 1 > 1) /* 종료 조건 : r-l+1 */
		{
			t = random(r - l + 1) + l; /* 난수 발생 */
			v = a[t]; /* t 요소와 r 요소 바꿈, v 는 축값 되고 */
			a[t] = a[r];
			a[r] = v;
			i = l - 1;
			j = r;
			while (1) /* 분할 */
			{
				while (a[++i] < v);
				while (a[--j] > v);
				if (i >= j) break;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			t = a[i]; /* 축값 변경 */
			a[i] = a[r];
			a[r] = t;
			push(r);
			push(i + 1);
			push(i - 1);
			push(l);
		}
	}
}

void quick_sort3(int* a, int N)
{
	int v, t;
	int i, j;
	int l, r;
	init_stack();
	l = 0;
	r = N - 1;
	push(r);
	push(l);
	while (!is_empty()) {
		l = pop();
		r = pop();
		if (r - l + 1 > 200) // quick sort
		{
			t = rand() % N;
			v = a[t];
			a[t] = a[r];
			a[r] = v;
			i = l - 1;
			j = r;
			while (1) {
				while (a[++i] < v);
				while (a[j--] > v);
				if (i >= j) break;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			t = a[i];
			a[i] = a[r];
			a[r] = t;
			push(r);
			push(i + 1);
			push(i - 1);
			push(l);
		}
		else
			insert_sort(a + l, r - l + 1);
	}
}

void quick_sort4(int a[], int n)
{
	/* 재귀호출 없앤 퀵 정렬 */
	int v, t;
	int i, j;
	int l, r;
	init_stack();
	l = 0;
	r = n - 1;
	push(r);
	push(l);
	while (!is_empty())
	{
		l = pop();
		r = pop();
		if (r - l + 1 > 200) /* 구간 크기 200 이상일 때만 퀵 */
		{
			t = (r + l) >> 1; /* t 는 중앙  >> 1 이 2로 나눔을 표현 */
			if (a[l] > a[t]) /* 이후 왼쪽, 중앙, 오른쪽 값 정렬 */
			{
				v = a[l];
				a[l] = a[t];
				a[t] = v;
			}
			if (a[l] > a[r])
			{
				v = a[l];
				a[l] = a[r];
				a[r] = v;
			}
			if (a[t] > a[r])
			{
				v = a[t];
				a[t] = a[r];
				a[r] = v;
			}
			v = a[t]; /* 중앙값을 a[r-1]과 교환 */
			a[t] = a[r - 1];
			a[r - 1] = v;
			i = l; /* 분할 구간은 l+1 부터 r-2 */
			j = r - 1;
			while (1) /* 분할 */
			{
				while (a[++i] < v);
				while (a[--j] > v);
				if (i >= j) break;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			t = a[i]; /* 축값 변경 */
			a[i] = a[r];
			a[r] = t;
			push(r);
			push(i + 1);
			push(i - 1);
			push(l);
		}
		else /* 200 보다 작으면 삽입 정렬! */
			insert_sort(a + l, r - l + 1);
	}
}
void gen_quick_sort1(void* base, size_t nelem, size_t width, FCMP fcmp)
{     /* remove recursion & median & small subfile insert*/
	void* v, * u;
	int i, j, t;
	int l, r;
	init_stack();
	v = malloc(width);
	u = malloc(width);
	l = 0;
	r = nelem - 1;
	push(r);
	push(l);
	while (!is_empty())
	{
		l = pop();
		r = pop();
		if (r - l + 1 > 100)    /* terminal condition */
		{
			
			t = (r + l) >> 1;    /* t is middle */
			if (fcmp((char*)base + width * l, (char*)base + width * t) > 0)  /* sort left, middle, right */
			{
				memcpy(v, (char*)base + width * l, width);
				memcpy((char*)base + width * l, (char*)base + width * t, width);
				memcpy(BASE(t), v, width);
			}
			if (fcmp((char*)base + width * l, (char*)base + width * r) > 0)  /* sort left, middle, right */
			{
				memcpy(v, (char*)base + width * l, width);
				memcpy((char*)base + width * l, (char*)base + width * r, width);
				memcpy((char*)base + width * r, v, width);
			}
			if (fcmp((char*)base + width * t, (char*)base + width * r) > 0)  /* sort left, middle, right */
			{
				memcpy(v, (char*)base + width * t, width);
				memcpy((char*)base + width * t, (char*)base + width * r, width);
				memcpy((char*)base + width * r, v, width);
			}
			memcpy(v, (char*)base + width * t, width);    /* exchange middle with a[r-1] */
			memcpy((char*)base + width * t, (char*)base + width * (r - 1), width);
			memcpy((char*)base + width * (r - 1), v, width);
			i = l;     /* partition l+1 to r-2 */
			j = r - 1;
			while (1)      /* partition */
			{
				while (fcmp((char*)base + width * ++i, v) < 0);
				while (fcmp((char*)base + width * --j, v) > 0);
				if (i >= j) break;
				memcpy(u, (char*)base + width * i, width);
				memcpy((char*)base + width * i, (char*)base + width * j, width);
				memcpy((char*)base + width * j, u, width);
			}
			memcpy(u, (char*)base + width * i, width);
			memcpy((char*)base + width * i, (char*)base + width * (r - 1), width);
			memcpy((char*)base + width * (r - 1), u, width);
			push(r);
			push(i + 1);
			push(i - 1);
			push(l);
		}
		else
			insert_sort((char*)base + width * l, r - l + 1, width, fcmp);  /* small sub file */
	}
	free(u);
	free(v);
}
void gen_quick_sort2(void* base, size_t nelem, size_t width, FCMP fcmp)
{     /* remove recursion & random & small subfile insert*/
	void* v, * u;
	int i, j, t;
	int l, r;
	init_stack();
	v = malloc(width);
	u = malloc(width);
	l = 0;
	r = nelem - 1;
	push(r);
	push(l);
	while (!is_empty())
	{
		l = pop();
		r = pop();
		if (r - l + 1 > 100)    /* terminal condition */
		{
			t = random(r - l + 1) + l;    /* t is random */
			memcpy(v, BASE(t), width);    /* exchange random with a[r] */
			memcpy(BASE(t), BASE(r), width);
			memcpy(BASE(r), v, width);
			i = l - 1;     /* partition l to r-1 */
			j = r;
			while (1)      /* partition */
			{
				while (fcmp(BASE(++i), v) < 0);
				while (fcmp(BASE(--j), v) > 0);
				if (i >= j) break;
				memcpy(u, BASE(i), width);
				memcpy(BASE(i), BASE(j), width);
				memcpy(BASE(j), u, width);
			}
			memcpy(u, BASE(i), width);
			memcpy(BASE(i), BASE(r), width);
			memcpy(BASE(r), u, width);
			push(r);
			push(i + 1);
			push(i - 1);
			push(l);
		}
		else
			insert_sort(BASE(l), r - l + 1, width, fcmp);  /* small sub file */
	}
	free(u);
	free(v);
}


void main()
{
	int a[15] = { 9, 4, -80, 1, 172, 13, 9, 39, -99, 2054, 10, -10, 3, 67, -28 };
	quick_sort(a, 15); 
	for (int i = 0; i < 15; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	int b[15] = { 9, 4, -80, 1, 172, 13, 9, 39, -99, 2054, 10, -10, 3, 67, -28 };
	quick_sort1(b, 15);
	for (int i = 0; i < 15; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	int c[15] = { 9, 4, -80, 1, 172, 13, 9, 39, -99, 2054, 10, -10, 3, 67, -28 };
	quick_sort3(c, 15);
	for (int i = 0; i < 15; i++) {
		printf("%d ", c[i]);
	}
	printf("\n");
	int d[15] = { 9, 4, -80, 1, 172, 13, 9, 39, -99, 2054, 10, -10, 3, 67, -28 };
	quick_sort2(d, 15);
	for (int i = 0; i < 15; i++) {
		printf("%d ", d[i]);
	}
	printf("\n");
	int e[15] = { 9, 4, -80, 1, 172, 13, 9, 39, -99, 2054, 10, -10, 3, 67, -28 };
	quick_sort4(e, 15);
	for (int i = 0; i < 15; i++) {
		printf("%d ", e[i]);
	}
	printf("\n");
	int f[15] = { 9, 4, -80, 1, 172, 13, 9, 39, -99, 2054, 10, -10, 3, 67, -28 };
	gen_quick_sort1(f, 15, sizeof(int), intcmp);
	for (int i = 0; i < 15; i++) {
		printf("%d ", f[i]);
	}
	printf("\n");
	int g[15] = { 9, 4, -80, 1, 172, 13, 9, 39, -99, 2054, 10, -10, 3, 67, -28 };
	gen_quick_sort2(g, 15, sizeof(int), intcmp);
	for (int i = 0; i < 15; i++) {
		printf("%d ", g[i]);
	}
}
