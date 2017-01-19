#include <stdio.h>
#include <stdlib.h>

int inputStationNumber();
int calcPay(int num);
void printPay(int pay);

int main()
{
	int num;	//�̵��� ������ ��
	int pay;

	num = inputStationNumber();
	pay = calcPay(num);
	printPay(pay);

	return 0;
}

int inputStationNumber() {
	int num;

	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &num);

	return num;
}

int calcPay(int num) {
	int pay;

	if (num <= 0)
		pay = 0;
	// 1~10 ������ ������ �⺻���.
	if (num <= 5)
		pay = 600;
	else if (num <= 10)
		pay = 800;
	// �߰��ݾ� ����
	else {
		pay = 800;
		pay += (num - 9) / 2 * 100;
	}

	return pay;
}


void printPay(int pay) {
	printf("��� : %d��\n", pay);
}
