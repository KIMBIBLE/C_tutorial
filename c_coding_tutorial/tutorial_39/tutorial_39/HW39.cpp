#include <stdio.h>

int main()
{
	int workDay;
	int sumMoney = 0;
	int i;
	int gold = 1;
	
	printf("* 기사의 근무일수를 입력하시오 : ");
	scanf("%d", &workDay);

	for (i = 1; i <= workDay; i++) {
		if ((gold*(gold + 1) / 2 + 1) == i) {
			gold++;
		}
		sumMoney += gold;
	}
	printf("근무일 : %d일 / 총 금화 수 : %d개\n", workDay, sumMoney);
	return 0;
}