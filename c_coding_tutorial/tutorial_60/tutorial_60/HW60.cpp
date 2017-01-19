#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setRandomArray(int(*pNum)[5]);
void getPartialArraySum(int(*pNum)[5], int *sumSet);
void printArray(int(*pNum)[5], int *sumSet);

int main()
{
	int num[5][5];
	int sumSet[3] = { 0, };

	srand((unsigned int)time(NULL));

	setRandomArray(num);
	getPartialArraySum(num, sumSet);
	printArray(num, sumSet);

	return 0;
}


void setRandomArray(int(*pNum)[5]) {
	int i, j;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			pNum[i][j] = 1 + rand() % 20;	// 1~20 까지 난수 발생
		}
	}
}

void getPartialArraySum(int(*pNum)[5], int *sumSet) {
	int i, j;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (i == j) {
				sumSet[0] += pNum[i][j];
			}
			else if (i < j) {
				sumSet[1] += pNum[i][j];
			}
			else {
				sumSet[2] += pNum[i][j];
			}
		}
	}

}

void printArray(int(*pNum)[5], int *sumSet) {
	int i, j;

	for (i = 0; i < 5; i++) {
		printf("%d번 행 : ", i);
		for (j = 0; j < 5; j++) {
			printf("%3d", pNum[i][j]);
		}
		puts("");
	}
	puts("\n");

	for (i = 0; i < 3; i++) {
		printf("sum%d = %d\n", i + 1, sumSet[i]);
	}
	puts("\n");
}
