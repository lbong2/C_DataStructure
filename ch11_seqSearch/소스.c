#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int data[SIZE];
int nitem;

int seq_search(int key, int* a, int* num)
{
	int i = 0;
	while (a[i] != key && i < *num) i++;
	return (i < *num ? i : -1);
}
int seq_insert(int key, int* a, int* num)
{
	a[(*num)++] = key;
	return (*num) - 1;
}
int seq_delete(int key, int* a, int* num)
{
	int p, i;
	if (*num > 0)
	{
		if ((p = seq_search(key, a, num)) < 0) return -1;
		for (i = p + 1; i < *num; i++)
			a[i - 1] = a[i];
		(*num)--;
		return p;
	}
	return -1;
}
int seq_f_search(int key, int* a, int* num)
{
	int p, i;
	if ((p = seq_search(key, a, num)) < 0)
		return -1;
	for (i = p - 1; i >= 0; i--)
		a[i + 1] = a[i];
	a[0] = key;
	return 0;
}
