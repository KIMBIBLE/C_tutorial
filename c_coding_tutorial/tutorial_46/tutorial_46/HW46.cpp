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
	//시작 값 입력
	while (1) {
		while (1) {	//정수 입력될 때 까지 반복
			printf("# 시작 값을 입력하시오 : ");
			scanf("%d", startNum);
			if (getchar() == '\n') { break; }
			while (getchar() != '\n') { ; }
		}
		if (*startNum >= 0) { break; }
	}

	//끝 값 입력
	while (1) {
		while (1) {	//정수 입력될 때 까지 반복
			printf("# 끝 값을 입력하시오 : ");
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
			printf("* %d~%d까지의 짝수의 합을 구할까요? 홀수의 합을 구할까요?(짝수:e/홀수:o) : ", startNum, endNum);
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

	//홀수의 합
	if (choice == 'o') {
		printf("%d~%d까지의 홀수(", startNum, endNum);
		for (i = startNum; i <= endNum; i++) {
			if (i % 2) {
				printf("%d ", i);
				sum += i;
			}
		}
	}
	//짝수의 합
	else {
		printf("%d~%d까지의 짝수(", startNum, endNum);
		for (i = startNum; i <= endNum; i++) {
			if ((i+1) % 2) {
				printf("%d ", i);
				sum += i;
			}
		}
	}
	printf("\b)의 합은 %d 입니다.\n", sum);
}