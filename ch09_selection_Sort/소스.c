#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#pragma warning (disable : 4996)
#define SIZE 10

int intcmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

void gen_select_sort(void* base, int nelem, int width, int (*fcmp)(const void*, const void*))
{
	void* min;
	int min_idx;
	int i, j;
	int x, y;

	min = malloc(width);
	for (y = 0; y < nelem - 1; y++)
	{
		min_idx = y;
		memcpy(min, (char*)base + y * width, width);
		for (x = y + 1; x < nelem; x++)
		{
			if (fcmp(min, (char*)base + x * width) > 0)
			{
				memcpy(min, (char*)base + x * width, width);
				min_idx = x;
			}
		}
		memcpy((char*)base + min_idx * width, (char*)base + y * width, width);
		memcpy((char*)base + y * width, min, width);
	}
	free(min);
}	
void select_sort(int* a, int N)
{
	int min;
	int min_idx;
	int x, y;
	for (y = 0; y < N - 1; y++) {
		min_idx = y;
		min = a[y];
		for (x = y + 1; x < N; x++) {
			if (min > a[x]) {
				min = a[x];
				min_idx = x;
			}
		}
		a[min_idx] = a[y];
		a[y] = min;
	}
}
void shell_sort(int* a, int N)
{
	int i, j, k, h, v;
	for (h = N / 2; h > 0; h /= 2) {
		for (i = 0; i < h; i++) {
			for (j = i + h; j < N; j += h) {
				v = a[j];
				k = j;
				while (k > h - 1 && a[k - h] > v) {
					a[k] = a[k - h];
					k -= h;
				}
				a[k] = v;
			}
		}
	}
}
void gen_shell_sort(void* base, int nelem, int width, int(*fcmp)(const void*, const void*)) {
	int i, j, k, h;
	void* v;
	v = malloc(width);
	for (h = 1; h < nelem; h = 3 * h + 1);
	for (h /= 3; h > 0; h /= 3) {
		for (i = 0; i < h; i++) {
			for (j = i + h; j < nelem; j += h) {
				memcpy(v, (char*)base + j * width, width);
				k = j;
				while (k > h - 1 && fcmp((char*)base + (k - h) * width, v) > 0) {
					memcpy((char*)base + k * width, (char*)base + (k - h) * width, width);
					k -= h;
				}
				memcpy((char*)base + k * width, v, width);
			}
		}
	}
	
}
void main()
{
	int number[SIZE];
	int number2[SIZE];
	int number3[SIZE];
	int number4[SIZE];
	for (int i = 0; i < SIZE; i++) {
		scanf("%d", &number[i]);
	}
	for (int i = 0; i < SIZE; i++) {
		number2[i] = number[i];
	}
	for (int i = 0; i < SIZE; i++) {
		number3[i] = number[i];
	}
	for (int i = 0; i < SIZE; i++) {
		number4[i] = number[i];
	}
	gen_select_sort(number, SIZE, sizeof(int), intcmp);
	printf("General select sort >> ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", number[i]);

	}
	printf("\n");
	printf("select sort >> ");
	select_sort(number2, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", number2[i]);
	}
	printf("\n");
	printf("shell sort >> ");
	shell_sort(number3, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", number3[i]);
	}
	printf("\n");
	printf("General shell sort >> ");
	gen_shell_sort(number4, SIZE, sizeof(int), intcmp);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", number4[i]);
	}
}
//15 874 64 984 123 4 6545 78 4654 878