#include <stdio.h>

void inputRangeNumber(int *startNum, int *endNum);
char inputEvenOrOdd(int startNum, int endNum);
void printSum(int startNum, int endNum, char choice);
int main()
{
	int startNum, endNum;
	char choice;	//Only : 'e'(even) or 'o'(odd)

	inputRangeNumber(&startNum, &endNum);
	choice = inputEvenOrOdd(startNum, endNum);
	printSum(startNum, endNum, choice);

	return 0;
}

void inputRangeNumber(int *startNum, int *endNum) {
	//���� �� �Է�
	while (1) {
		while (1) {	//���� �Էµ� �� ���� �ݺ�
			printf("# ���� ���� �Է��Ͻÿ� : ");
			scanf("%d", startNum);
			if (getchar() == '\n') { break; }
			while (getchar() != '\n') { ; }
		}
		if (*startNum >= 0) { break; }
	}

	//�� �� �Է�
	while (1) {
		while (1) {	//���� �Էµ� �� ���� �ݺ�
			printf("# �� ���� �Է��Ͻÿ� : ");
			scanf("%d", endNum);
			if (getchar() == '\n') { break; }
			while (getchar() != '\n') { ; }
		}
		if (*endNum > *startNum) { break; }
	}
}

char inputEvenOrOdd(int startNum, int endNum) {
	char choice;

	while (1) {
		while (1) {
			printf("* %d~%d������ ¦���� ���� ���ұ��? Ȧ���� ���� ���ұ��?(¦��:e/Ȧ��:o) : ", startNum, endNum);
			scanf("%c", &choice);
			if (getchar() == '\n') { break; }
			while (getchar() != '\n') { ; }
		}
		if (choice == 'e' || choice == 'o') { break; }
	}	
	
	return choice;
}

void printSum(int startNum, int endNum, char choice) {
	int sum = 0;
	int i;

	//Ȧ���� ��
	if (choice == 'o') {
		printf("%d~%d������ Ȧ��(", startNum, endNum);
		for (i = startNum; i <= endNum; i++) {
			if (i % 2) {
				printf("%d ", i);
				sum += i;
			}
		}
	}
	//¦���� ��
	else {
		printf("%d~%d������ ¦��(", startNum, endNum);
		for (i = startNum; i <= endNum; i++) {
			if ((i+1) % 2) {
				printf("%d ", i);
				sum += i;
			}
		}
	}
	printf("\b)�� ���� %d �Դϴ�.\n", sum);
}