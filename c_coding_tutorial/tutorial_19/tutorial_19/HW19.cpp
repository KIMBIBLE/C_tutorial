#include <stdio.h>

int inputYear();
int yearCheck(int year);
void outputCheckResult(int year, int flag);

int main()
{
	int year;
	int flag;

	year = inputYear();
	flag = yearCheck(year);
	outputCheckResult(year, flag);

	return 0;
}

/*
	��� : ����ڷκ��� ������ �Է¹���.
	return : year (�Է¹��� ����)
*/
int inputYear() {
	int year;

	printf("�⵵�� �Է��Ͻÿ� : ");
	scanf("%d", &year);

	return year;
}

/*
	��� : ������ ��, ��� üũ
	parm1 : year
	return : (��� : 0, ���� : 1)
*/
int yearCheck(int year) {
	if (year % 4 != 0)
		return 0;

	if (year % 100 != 0)
		return 1;
	
	if (year % 400)
		return 1;
	else
		return 0;	
}

/*
	��� : ������ ��,��� ��ȯ ��� ���
	parm1 : year (�Է¹��� ����)
	parm2 : flag (��� : 0, ���� : 1)
*/
void outputCheckResult(int year, int flag) {
	if (flag == 0)
		printf("%d���� ���(Common year)�Դϴ�.\n", year);
	else// flag == 0
		printf("%d���� ����(Leap year)�Դϴ�.\n", year);
}