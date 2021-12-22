#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable : 4996)

int main() {

	int dice;
	int tryNum;
	int diceNum[6] = { 0, };

	printf("Input number of dice thrown >>");
	scanf("%d", &tryNum);
	srand((unsigned)time(NULL));
	for (int i = 0; i < tryNum; i++) {
		

		dice = rand() % 6;
		switch (dice) {
		case 0:
			diceNum[0]++;
			break;
		case 1:
			diceNum[1]++;
			break;
		case 2:
			diceNum[2]++;
			break;
		case 3:
			diceNum[3]++;
			break;
		case 4:
			diceNum[4]++;
			break;
		case 5:
			diceNum[5]++;
			break;
		}

		
	}
	printf("Number 1 : %d\n", diceNum[0]);
	printf("Number 2 : %d\n", diceNum[1]);
	printf("Number 3 : %d\n", diceNum[2]);
	printf("Number 4 : %d\n", diceNum[3]);
	printf("Number 5 : %d\n", diceNum[4]);
	printf("Number 6 : %d\n", diceNum[5]);
}