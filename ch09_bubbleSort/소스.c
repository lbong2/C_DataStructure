#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)
#define SIZE 10
void bubble_sort(int* a, int n) {
	int i, j, t;
	for (i = 0; i < n - 1; i++) {
		for (j = 1; j < n - i; j++) {
			if (a[j - 1] > a[j]) {
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
		}
	}
}
void gen_bubble_sort(void* base, int nelem, int width, int(*fcmp)(const void*, const void*)) {
	int i, j, s;
	void* t;
	t = malloc(width);
	for (i = 0; i < nelem; i++) {
		s = 1;
		for (j = 1; j < nelem - i; j++) {
			if (fcmp((char*)base + (j - 1) * width, (char*)base + j * width) > 0) {
				memcpy(t, (char*)base + (j - 1) * width, width);
				memcpy((char*)base + (j - 1) * width, (char*)base + j * width, width);
				memcpy((char*)base + j * width, t, width);
				s = 0;
			}
		}
		if (s == 1) break;
	}
}
int intcmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
void main() {
	int number[SIZE];
	int number2[SIZE];
	for (int i = 0; i < SIZE; i++) {
		scanf("%d", &number[i]);
	}
	for (int i = 0; i < SIZE; i++) {
		number2[i] = number[i];
	}
	gen_bubble_sort(number, SIZE, sizeof(int), intcmp);
	printf("General bubble_sort >> ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", number[i]);

	}
	printf("\n");
	printf("bubble_sort >> ");
	bubble_sort(number2, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", number2[i]);
	}
}//15 874 64 984 123 4 6545 78 4654 878