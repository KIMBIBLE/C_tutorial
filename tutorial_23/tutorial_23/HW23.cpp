#include <stdio.h>

int main()
{
	int num1, num2;
	int temp;		//for swap
	FILE* a;
	while (1) {
		printf("# �ΰ��� ������ �Է��ϼ��� : ");
		if (scanf("%d %d", &num1, &num2) != 2) 
			break;
		//num1, num2 ��Һ��Ͽ� ũ�ų� ���� ���� num1 �� ����
		if (num2 > num1) {
			temp = num1;
			num1 = num2;
			num2 = temp;
		}

		printf("%d - %d = %d\n", num1, num2, num1 - num2);
	}

	return 0;
}