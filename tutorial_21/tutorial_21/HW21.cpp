#include <stdio.h>

int main()
{
	double height;
	double sum;

	int inputCnt = 5;
	int i;

	sum = 0;
	for (i = 0; i < inputCnt; i++) {
		printf("%d �� �л��� Ű��? ", i+1);
		scanf("%lf", &height);
		sum += height;
	}
	
	printf("�ټ� ���� ��� Ű�� %.1lf cm �Դϴ�\n", sum/inputCnt);

	return 0;
}