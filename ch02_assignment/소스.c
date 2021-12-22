#include<stdio.h>
#pragma warning (disable : 4996)

#define ROWS 4
#define COLS 3
int m[ROWS][COLS] = { {1, 3, 5},
					  {9, 7, 3},
					  {3, 3, 9}, 
					  {2, 8, 6} };

float get_row_avg(int m[][COLS], int r) {
	int* start, *end;		// int*���� start, end ����
	float avg = 0;			// float�� ���ϰ�(��հ�)���� ����
	start = m[r];			// start�� �ش� row������ �ּҷ� �ʱ�ȭ	
	end = m[r] + COLS - 1;	// end�� �ش� row ���ּҷ� �ʱ�ȭ 
	while (start <= end) {	// start�� end���� �۰ų� ���ٸ�(�迭 �޸� ����)
		avg += *start;		// avg�� �ش� �ּҾ��� ���� ����
		start++;			// �����ڿ� ���� ���� column�� �ּҷ� �̵�
	}						// ��ӵ� �������� start�� �ּҰ��� end�� �ּҰ��� �����
	avg /= COLS;			// �ݺ����� �������µ� avg�� column�� ������ ������
	return avg;
}

void main() {
	printf("%f\n", get_row_avg(m, 2)); // �Լ� ���ϰ� ���
}