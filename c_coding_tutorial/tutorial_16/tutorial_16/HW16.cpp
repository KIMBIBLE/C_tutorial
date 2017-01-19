#include <stdio.h>
#include <stdlib.h>

int inputStationNumber();
int calcPay(int num);
void printPay(int pay);

int main()
{
	int num;	//이동할 정거장 수
	int pay;

	num = inputStationNumber();
	pay = calcPay(num);
	printPay(pay);

	return 0;
}

int inputStationNumber() {
	int num;

	printf("역수를 입력하시오 : ");
	scanf("%d", &num);

	return num;
}

int calcPay(int num) {
	int pay;

	if (num <= 0)
		pay = 0;
	// 1~10 정거장 까지의 기본요금.
	if (num <= 5)
		pay = 600;
	else if (num <= 10)
		pay = 800;
	// 추가금액 누적
	else {
		pay = 800;
		pay += (num - 9) / 2 * 100;
	}

	return pay;
}


void printPay(int pay) {
	printf("요금 : %d원\n", pay);
}
