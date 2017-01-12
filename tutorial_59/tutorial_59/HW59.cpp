#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setRandomArray(int(*pNum)[4]);
void printArray(int(*pNum)[4]);

int main()
{
	int num[3][4];
	int sum = 0;

	srand((unsigned int)time(NULL));

	setRandomArray(num);
	printArray(num);

	return 0;
}


void setRandomArray(int(*pNum)[4]) {
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			pNum[i][j] = 1 + rand() % 9;	// 1~9 ���� ���� �߻�
		}
	}
}

void printArray(int(*pNum)[4]) {
	int i, j;
	int sum = 0;

	puts("\n");	//�̰��� ����
	for (i = 0; i < 3; i++) {
		sum = 0;
		printf("%d��\t : ", i);
		for (j = 0; j < 4; j++) {
			printf("%3d", pNum[i][j]);
			sum += pNum[i][j];
		}
		printf("%10d���� �� : %3d\n", i, sum);
	}


	printf("���� ��\t : ");
	for (i = 0; i < 4; i++) {
		sum = 0;
		for (j = 0; j < 3; j++) {
			sum += pNum[j][i];
		}
		printf("%3d", sum);
	}
	puts("\n");

}