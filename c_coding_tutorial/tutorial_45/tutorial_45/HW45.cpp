#include <stdio.h>
#include <math.h>

int inputInteger(char* message);
int primeNumber(int number);

int main()
{
	int num;
	int i;
	int cnt = 0;

	num = inputInteger("*정수값 하나를 입력하시오 : ");
	for (i = 2; i <= num; i++) {
		if (primeNumber(i)) {
			printf("%5d", i);
			if (!(++cnt % 5)) { puts(""); }
		}
	}
	puts("");
	printf("1~%d까지의 총 소수는 %d개 입니다.\n", num, cnt);

	return 0;
}

int primeNumber(int number) {
	int i;
	int SqrtedNumber;

	SqrtedNumber = sqrt(number);
	for (i = 2; i <= SqrtedNumber; i++) {
		if (!(number%i)) {
			return 0;
		}
	}
	
	return 1;
}

int inputInteger(char* message) {
	int num;

	while (1) {
		printf("%s", message);
		scanf("%d", &num);
		if (getchar() == '\n') {
			return num;
		}
		while (getchar() != '\n') { ; }
	}
}