#include <stdio.h>

int main()
{
	int creamBreadCnt;
	int shrimpChipCnt;
	int cockCnt;

	int creamBreadPrice = 500;
	int shrimpChipPrice = 700;
	int cockPrice = 400;

	int creamMax, shrimpMax, cockMax;

	int money;
	
	while (1) {
		printf("���� ����� ���� �ݾ� �Է� : ");
		if (!scanf("%d", &money)) { break; }

		creamMax = money / creamBreadPrice;
		shrimpMax = money / shrimpChipPrice;
		cockMax = money / cockPrice;

		for (creamBreadCnt = 1; creamBreadCnt <= creamMax; creamBreadCnt++) {
			for (shrimpChipCnt = 1; shrimpChipCnt <= shrimpMax; shrimpChipCnt++) {
				for (cockCnt = 1; cockCnt <= cockMax; cockCnt++) {
					if ((creamBreadCnt*creamBreadPrice + shrimpChipCnt*shrimpChipPrice + cockCnt*cockPrice) == money) {
						printf("ũ����(%d ��), �����(%d ����), �ݶ�(%d ��)\n", creamBreadCnt, shrimpChipCnt, cockCnt);
					}
				}
			}
		}

		printf("��� �����Ͻðڽ��ϱ�?\n\n\n");
	}
	

	return 0;
}