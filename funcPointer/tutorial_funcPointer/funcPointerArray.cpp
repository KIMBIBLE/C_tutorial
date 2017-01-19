#include <stdio.h>

int plus(int x, int y);
int minus(int x, int y);
int multi(int x, int y);

int main()
{
	int res;
	size_t i, j;
	size_t len;

	int(*fpAry[4])(int, int) = { plus, minus, multi, plus };
	
	len = sizeof(fpAry) / sizeof(fpAry[0]);
	for (i = 0; i < len; i++) {
		res = fpAry[i](10, 6);
		printf("res = %d\n", res);
	}

	return 0;
}

int plus(int x, int y) {
	return x + y;
}
int minus(int x, int y) {
	return x - y;
}
int multi(int x, int y) {
	return x * y;
}