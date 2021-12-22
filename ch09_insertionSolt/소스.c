#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)

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
void indirect_insert_sort(int* a, int* index, int N)
{
	int i, j, t;
	for (i = 0; i < N; i++)
		index[i] = i;
	for (i = 1; i < N; i++)
	{
		t = index[i];
		j = i;
		while (j > 0 && a[index[j - 1]] > a[t])
		{
			index[j] = index[j - 1];
			j--;
		}
		index[j] = t;
	}
}
int intcmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
void gen_insert_sort(void* base, int nelem, int width, int(*fcmp)(const void*, const void*)) {
	void* t;
	int i, j;
	t = malloc(width);

	for (i = 0; i < nelem; i++) {
		memcpy(t, (char*)base + i * width, width);
		j = i;

		while (fcmp((char*)base + (j - 1) * width, t) > 0 && j > 0) {
			memcpy((char*)base + j * width, (char*)base + (j - 1) * width, width);
			j--;
		}
		memcpy((char*)base + j * width, t, width);
	}
	free(t);
}
void main() {
	int arr[10] = { 0, };
	int idx[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
	insert_sort(arr, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	indirect_insert_sort(arr, idx, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[idx[i]]);
	}
	printf("\n");
	gen_insert_sort(arr, 10, sizeof(int), intcmp);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
} 
 