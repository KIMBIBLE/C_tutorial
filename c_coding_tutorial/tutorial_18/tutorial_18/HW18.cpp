#include <stdio.h>

void inputInfo(int* age, int* num);
void printPays(int totalPay, int discount, int finalPay);

int main()
{
	int age = 0;	//���� 24���� �̸��� ���� '0'���� ���
	int num = 0;

	int totalPay = 0;
	int discount = 0;
	int finalPay = 0;
	
	int admission = 0;

	inputInfo(&age, &num);

	// ������ �Է� ó��
	if (age < 0 || num < 0)	
		printf("�߸��� �Է��Դϴ�.\n");

	// ���̺� ����� ���
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


	// �ݾ� ���
	totalPay = admission * num;
	
	if (num >= 5)	//���� ����
		discount = totalPay * 0.1;

	finalPay = totalPay - discount;


	printPays(totalPay, discount, finalPay);

	return 0;
}


void inputInfo(int* age, int* num) {
	printf("���尴�� ���̸� �Է��Ͻÿ� : ");
	scanf("%d", age);

	printf("���尴�� ���� �Է��Ͻÿ� : ");
	scanf("%d", num);
}

void printPays(int totalPay, int discount, int finalPay) {
	printf("����� => %d��\n", totalPay);
	printf("���αݾ� => %d��\n", discount);
	printf("�����ݾ� => %d��\n", finalPay);
}