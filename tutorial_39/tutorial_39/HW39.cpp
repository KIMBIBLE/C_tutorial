#include <stdio.h>

int main()
{
	int workDay;
	int sumMoney = 0;
	int i;
	int gold = 1;
	
	printf("* ����� �ٹ��ϼ��� �Է��Ͻÿ� : ");
	scanf("%d", &workDay);

	for (i = 1; i <= workDay; i++) {
		if ((gold*(gold + 1) / 2 + 1) == i) {
			gold++;
		}
		sumMoney += gold;
	}
	printf("�ٹ��� : %d�� / �� ��ȭ �� : %d��\n", workDay, sumMoney);
	return 0;
}