#include <stdio.h>

int plus(int num1, int num2);

int main()
{
	int a = 10, b = 20;
	int res;

	// �Լ� ������ ����
	int(*fptr)(int, int);

	// �Լ� ������ ���
	fptr = plus;

	res = fptr(a, b);
	printf("%d + %d = %d\n", a, b, res);

	return 0;
}

int plus(int num1, int num2) {
	return num1 + num2;
}