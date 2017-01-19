#include <stdio.h>

#define STRING_SIZE 50

int inputNumber();
void integerToString(int num, char *stringNum);

int main()
{
	int num;
	char stringNum[STRING_SIZE] = { NULL, };
	int i = 0;

	while (1) {
		num = inputNumber();
		if (num < 0) { break; }
		integerToString(num, stringNum);
		printf("%d -> %s\n\n",num, stringNum);

		while (stringNum[i]) {
			stringNum[i++] = NULL;
		}
		i = 0;
	}

	return 0;
}

int inputNumber() {
	int num;

	while (1) {
		printf("# 금액 입력 : ");
		scanf("%d", &num);
		if (getchar() == '\n') { return num; }
		while (getchar() != '\n') { ; }
	}
}

void integerToString(int num, char *stringNum) {
	int temp = num;
	int chiper = 1;	//자릿수
	int i;
	int chiperToDiv = 1;

	while (temp /= 10) {
		chiper++;
		chiperToDiv *= 10;
	}

	for (i = 0; i < STRING_SIZE; i++) {
		if (chiper == 0) { break; }
		if (chiper % 3 == 0 && i != 0) {
			stringNum[i++] = ',';
		}
		stringNum[i] = (num / chiperToDiv) + '0';
		num %= chiperToDiv;
		chiperToDiv /= 10;
		chiper--;
	}

}
