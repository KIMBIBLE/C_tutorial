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
		printf("현재 당신의 소유 금액 입력 : ");
		if (!scanf("%d", &money)) { break; }

		creamMax = money / creamBreadPrice;
		shrimpMax = money / shrimpChipPrice;
		cockMax = money / cockPrice;

		for (creamBreadCnt = 1; creamBreadCnt <= creamMax; creamBreadCnt++) {
			for (shrimpChipCnt = 1; shrimpChipCnt <= shrimpMax; shrimpChipCnt++) {
				for (cockCnt = 1; cockCnt <= cockMax; cockCnt++) {
					if ((creamBreadCnt*creamBreadPrice + shrimpChipCnt*shrimpChipPrice + cockCnt*cockPrice) == money) {
						printf("크림빵(%d 개), 새우깡(%d 봉지), 콜라(%d 병)\n", creamBreadCnt, shrimpChipCnt, cockCnt);
					}
				}
			}
		}

		printf("어떻게 구입하시겠습니까?\n\n\n");
	}
	

	return 0;
}