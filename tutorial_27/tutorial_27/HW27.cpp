#include <stdio.h>

int inputEggWeight();

int main()
{
	int weight;
	int cnt;

	cnt = 0;
	while ( cnt < 10 ) {
		weight = inputEggWeight();
		if (weight < 150)	printf("*메추리알 가지고 장난하지 마시오~ ^^\n");
		else if (weight > 500)	printf("*타조알 가지고 장난하지 마시오~ ^^\n");
		else printf("* 현재 달걀의 수 : %d\n", ++cnt);
	}
	printf("\n*** 달걀 포장이 끝났습니다.\n");

	return 0;
}

int inputEggWeight() {
	int weight;

	printf("# 계란의 무게를 입력하세요(단위 :g) : ");
	while (scanf("%d", &weight) != 1) {
		while (getchar() != '\n');
		printf("# 계란의 무게를 입력하세요(단위 :g) : ");
	}

	return weight;
}
