#include <stdio.h>

int inputInteger(char* message);

int main()
{
	int num;
	unsigned int key = 0x80000000;
	int i;

	num = inputInteger("* 10진수 정수를 입력하시오 : ");
	printf("%d(10) = ", num);
	for (i = 0; i < 32; i++) {
		if ((num & key) == key)
			printf("1");
		else
			printf("0");
		key >>= 1;
	}
	printf("(2)\n");

	return 0;
}

int inputInteger(char* message) {
	int num;

	while (1) {
		printf("%s", message);
		scanf("%d", &num);
		if (getchar() == '\n')	break;
		while (getchar() != '\n') { ; }
	}

	return num;
}