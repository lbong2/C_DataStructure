#include<stdio.h>
#pragma warning (disable : 4996)

#define ROWS 4
#define COLS 3
int m[ROWS][COLS] = { {1, 3, 5},
					  {9, 7, 3},
					  {3, 3, 9}, 
					  {2, 8, 6} };

float get_row_avg(int m[][COLS], int r) {
	int* start, *end;		// int*형의 start, end 선언
	float avg = 0;			// float형 리턴값(평균값)변수 선언
	start = m[r];			// start에 해당 row시작점 주소로 초기화	
	end = m[r] + COLS - 1;	// end에 해당 row 끝주소로 초기화 
	while (start <= end) {	// start가 end보다 작거나 같다면(배열 메모리 내부)
		avg += *start;		// avg에 해당 주소안의 값을 더함
		start++;			// 연산자에 의해 다음 column의 주소로 이동
	}						// 계속된 연산으로 start의 주소값이 end의 주소값을 벗어나면
	avg /= COLS;			// 반복문을 빠져나온뒤 avg는 column의 개수로 나눠짐
	return avg;
}

void main() {
	printf("%f\n", get_row_avg(m, 2)); // 함수 리턴값 출력
}