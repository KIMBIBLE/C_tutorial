#include <stdio.h>

typedef struct {
	unsigned a : 2;
	unsigned b : 3;
	int c : 4;
	int d : 10;
}BitField;

int main()
{
	BitField bx;
	int a, b, c, d;	//��Ʈ�ʵ� ����� �ּҸ� ���� �� ���� ����
	scanf("%u %u", &a, &b);
	scanf("%d %d", &c, &d);

	bx.a = a;
	bx.b = b;
	bx.c = c;
	bx.d = d;

	printf("%u %u %d %d\n", bx.a, bx.b, bx.c, bx.d);

	return 0;
}