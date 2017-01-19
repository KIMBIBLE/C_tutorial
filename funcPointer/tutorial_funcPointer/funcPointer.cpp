#include <stdio.h>

int plus(int num1, int num2);

int main()
{
	int a = 10, b = 20;
	int res;

	// 함수 포인터 선언
	int(*fptr)(int, int);

	// 함수 포인터 사용
	fptr = plus;

	res = fptr(a, b);
	printf("%d + %d = %d\n", a, b, res);

	return 0;
}

int plus(int num1, int num2) {
	return num1 + num2;
}