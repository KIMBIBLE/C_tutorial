#include <stdio.h>

int getWonCount(int* remainMoney, int currencyUnit);

int main()
{
	int totalWonMoney = 278970;	//단위 :원(Won)
	int remainMoney = 0;

	int wonCnt50000 = 0;
	int wonCnt10000 = 0;
	int wonCnt5000 = 0;
	int wonCnt1000 = 0;
	int wonCnt500 = 0;
	int wonCnt100 = 0;
	int wonCnt50 = 0;
	int wonCnt10 = 0;

	remainMoney = totalWonMoney;
	wonCnt50000 = getWonCount(&remainMoney, 50000);
	wonCnt10000 = getWonCount(&remainMoney, 10000);
	wonCnt5000 = getWonCount(&remainMoney, 5000);
	wonCnt1000 = getWonCount(&remainMoney, 1000);
	wonCnt500 = getWonCount(&remainMoney, 500);
	wonCnt100 = getWonCount(&remainMoney, 100);
	wonCnt50 = getWonCount(&remainMoney, 50);
	wonCnt10 = getWonCount(&remainMoney, 10);


	printf("50000원권 => %d개\n", wonCnt50000);
	printf("10000원권 => %d개\n", wonCnt10000);
	printf("5000원권 => %d개\n", wonCnt5000);
	printf("1000원권 => %d개\n", wonCnt1000);
	printf("500원권 => %d개\n", wonCnt500);
	printf("100원권 => %d개\n", wonCnt100);
	printf("50원권 => %d개\n", wonCnt50);
	printf("10원권 => %d개\n", wonCnt10);

	return 0;
}

///	<summary>
///	잔액에서 특정 화폐단위에 의해 환산 가능한 화폐 갯수 반환
///	</summary>
///	<parm name="remainMoney"> 잔액
///	<parm name="currencyUnit"> 화폐 단위
///	<returns wonCnt>환산가능한 화폐 갯수</returns>
int getWonCount(int* remainMoney, int currencyUnit)
{
	int wonCnt;
	wonCnt = *remainMoney / currencyUnit;
	*remainMoney -= currencyUnit * wonCnt;

	return wonCnt;
}