#include <stdio.h>

int getWonCount(int* remainMoney, int currencyUnit);

int main()
{
	int totalWonMoney = 278970;	//���� :��(Won)
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


	printf("50000���� => %d��\n", wonCnt50000);
	printf("10000���� => %d��\n", wonCnt10000);
	printf("5000���� => %d��\n", wonCnt5000);
	printf("1000���� => %d��\n", wonCnt1000);
	printf("500���� => %d��\n", wonCnt500);
	printf("100���� => %d��\n", wonCnt100);
	printf("50���� => %d��\n", wonCnt50);
	printf("10���� => %d��\n", wonCnt10);

	return 0;
}

///	<summary>
///	�ܾ׿��� Ư�� ȭ������� ���� ȯ�� ������ ȭ�� ���� ��ȯ
///	</summary>
///	<parm name="remainMoney"> �ܾ�
///	<parm name="currencyUnit"> ȭ�� ����
///	<returns wonCnt>ȯ�갡���� ȭ�� ����</returns>
int getWonCount(int* remainMoney, int currencyUnit)
{
	int wonCnt;
	wonCnt = *remainMoney / currencyUnit;
	*remainMoney -= currencyUnit * wonCnt;

	return wonCnt;
}