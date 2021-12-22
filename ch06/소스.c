#include<stdio.h>
#pragma warning (disable : 4996)
#define MAX 10
int queue[MAX];
int front, rear;

void init_queue() {
	front = 0;
	rear = 0;
}
void clear() {
	front = rear;
}
int put(int k) {
	if ((rear + 1) % MAX == front) {
		printf("Queue overflow!!\n");
		return -1;
	}
	queue[rear] = k;
	rear = ++rear % MAX;
	return k;
}
int get() {
	int j;

	if (front == rear) {
		printf("Queue underflow!!\n");
		return -1;
	}
	j = queue[front];
	front = ++front % MAX;

	return j;
}
void print_queue() {
	int k;
	for (k = front; k != rear; k = ++k % MAX)
	{
		printf("%d\n", queue[k]);
	}
}
void main() {
	int k;
	init_queue();
}