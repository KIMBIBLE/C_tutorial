#include <stdio.h>

void inputInfo(int* age, int* num);
void printPays(int totalPay, int discount, int finalPay);

int main()
{
	int age = 0;	//생후 24개월 미만은 나이 '0'으로 계산
	int num = 0;

	int totalPay = 0;
	int discount = 0;
	int finalPay = 0;
	
	int admission = 0;

	inputInfo(&age, &num);

	// 비정상 입력 처리
	if (age < 0 || num < 0)	
		printf("잘못된 입력입니다.\n");

	// 나이별 입장료 계산
	if (age <= 7)
		admission = 500;
	else if (age <= 13)
		admission = 700;
	else if (age <= 19)
		admission = 1000;
	else if (age <= 55)
		admission = 1500;
	else
		admission = 500;


	// 금액 계산
	totalPay = admission * num;
	
	if (num >= 5)	//할인 적용
		discount = totalPay * 0.1;

	finalPay = totalPay - discount;


	printPays(totalPay, discount, finalPay);

	return 0;
}


void inputInfo(int* age, int* num) {
	printf("입장객의 나이를 입력하시오 : ");
	scanf("%d", age);

	printf("입장객의 수를 입력하시오 : ");
	scanf("%d", num);
}

void printPays(int totalPay, int discount, int finalPay) {
	printf("입장료 => %d원\n", totalPay);
	printf("할인금액 => %d원\n", discount);
	printf("결제금액 => %d원\n", finalPay);
}