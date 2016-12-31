#include <stdio.h>


double inputFahrenheit();
double transferDegreeFToC(double fahrenhei);
void printCentigrade(double centigrade);


int main()
{
	double fahrenhei = 0.0;
	double centigrade = 0.0;

	fahrenhei = inputFahrenheit();
	centigrade = transferDegreeFToC(fahrenhei);
	printCentigrade(centigrade);

	return 0;
}


///	<summary>
///	ȭ�� �µ� �Է� �Լ�
///	</summary>
///	<returns wonCnt>double type ȭ�� �µ�</returns>
double inputFahrenheit() {
	double fahrenhei = 0.0;

	printf("ȭ�� �µ��� �Է��ϼ��� : ");
	scanf("%lf", &fahrenhei);

	return fahrenhei;
}

///	<summary>
///	ȭ�� �µ� -> ���� �µ� ��ȯ �Լ�
///	</summary>
///	<returns wonCnt>double type ȭ�� �µ�</returns>
double transferDegreeFToC(double fahrenhei) {
	double centigrade = 0.0;

	centigrade = 5.0 / 9.0 * (fahrenhei - 32.0);

	return centigrade;
}

///	<summary>
///	��ȯ�� ���� �µ� ��� �Լ� (�Ҽ��� ���� ù°�ڸ�����)
///	</summary>
///	<parm name="centigrade"> ��ȯ�� ���� �µ�
void printCentigrade(double centigrade) {
	printf("���� �µ��� %.1lf�� �Դϴ�.\n", centigrade);
}