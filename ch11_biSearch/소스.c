#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable : 4996)

void downheap(int* a, int N, int k)	// a는 배열 N은 힙 크기 k는 인덱스
{
	int i, v;
	v = a[k];		// a[k]값 저장
	while (k <= N / 2) {	// k가 N/2(N의 부모 노드)보다 작다면? = k가 index 내에 있다면,
		i = k << 1;	// i는 2*k(k의 자식노드)
		if (i < N && a[i] < a[i + 1]) i++;	// 만약 i가 N 보다 작고 a[i](k자식노드1)가 a[i+1](k자식노드2)보다 작다면 i++
		if (v >= a[i]) break;	// a[k]값이 a[k]자식노드 중 젤 큰노드 보다 크다면 바로 나와서 그대로 나오기
		a[k] = a[i];	// a[k]값에 a[i]값 넣기 
		k = i;	// k 를 i로  = 인덱스 증가 
	}
	a[k] = v;
}
void heap_sort(int* a, int N) {
	int k, t;

	for (k = N / 2; k >= 1; k--) {
		downheap(a, N, k);
	}
	while (N > 1) {
		t = a[1];
		a[1] = a[N];
		a[N] = t;
		downheap(a, --N, 1);
	}
}
int bi_search(int key, int* a, int N)
{
	int mid;
	int left = 0;
	int right = N - 1;
	while (right >= left) {
		mid = (right + left) / 2;
		if (key == a[mid]) return mid;
		if (key < a[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
int bi_insert(int key, int* a, int* N)
{
	int p = 0;
	int i;
	while (key > a[p] && p < *N)
		p++;
	for (i = *N; i > p; i--)
		a[i] = a[i - 1];
	a[p] = key;
	(*N)++;
	return p;
}
int bi_delete(int key, int* a, int* N)
{
	int p;
	int i;
	if (*N > 0) {
		if ((p = bi_search(key, a, *N)) < 0)
			return -1;
		for (i = p + 1; i < *N; i++)
			a[i - 1] = a[i];
		(*N)--;
		return p;
	}
	return -1;
}
int bii_search(int key, int* a, int N)
{
	int mid;
	int left = 0;
	int right = N - 1;
	while (right >= left) {
		mid = left + (float)(key - a[left]) * (right - left) / (a[right] - a[left]);
		if (key == a[mid]) return mid;
		if (key < a[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
void main() {
	int str[20] = {0, 'T','O','S','O','R','T','A','L','G','O','R','I','T','H','M'};
	int size = 15;
	
	heap_sort(str, size);
	// Find a specific character using binary search
	int p = bi_search('S', str, size);
	printf("Find your key at %d(value %c)\n", p, str[p]);
	// Insert and delete a specific character
	p = bi_insert('Z', str, &size); // or p = bi_delete(‘A’, str, &size);
	for (int i = 1; i <= 15; i++)
	{
		printf("%c", str[i]);
	}
	p = bii_search('Z', str, size);

	printf("\n\n%d", p);
}