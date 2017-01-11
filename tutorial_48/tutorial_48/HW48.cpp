#include <stdio.h>

void inputDay(int *pYear, int *pMonth, int *pDay);
int yearCheck(int year);
int monthMaxCheck(int year, int month);
int getTotalDay(int year, int month, int day);
void displayDate(int year, int month, int day, int totalDay);

int main()
{
	int year, month, day;
	int totalDay;

	inputDay(&year, &month, &day);
	totalDay = getTotalDay(year, month, day);
	displayDate(year, month, day, totalDay);

	return 0;
}

void inputDay(int *pYear, int *pMonth, int *pDay) {
	while (1) {
		// ���� 3�� �Է� �ݺ�
		while (1) {
			printf("* �� �� ���� �Է��Ͻÿ� : ");
			scanf("%d %d %d", pYear, pMonth, pDay);
			if (getchar() == '\n') { break; }
			while (getchar() != '\n') { ; }
		}

		// ��¥ ������ �Է��� ��ȿ�� �˻�(��,�� -> ��)
		if (*pYear >= 1900 && 1 <= *pMonth && *pMonth <= 12) {
			if (1 <= *pDay && *pDay <= monthMaxCheck(*pYear, *pMonth)) { break; }
		}
	}
}

int getTotalDay(int year, int month, int day) {
	int total = 0;
	int i, j;

	for (i = 1; i < month; i++) {	//�� : �����ޱ��� daycount ����
		total += monthMaxCheck(year, i);
	}

	for (j = 1900; j < year; j++) {
		total += yearCheck(j);
	}

	total += (year - 1900) * 365;	//�� : (1990 ~ �۳�) ���� ���� day count ����

	total += day;	//�� ����

	return total;
}

// ��� : �������ڷ� ���� year, month�� ���� �ش� ��,���� �ִ� ��¥ ���� 
int monthMaxCheck(int year, int month) {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	//2���� ��� ����� �˻�. ���� : 29��, ��� :28��
	else if (month == 2) {
		if (yearCheck(year)) { return 29; }	//����
		else { return 28; }	//���
	}
	else {	//month = 1,3,5,7,8,10,12
		return 31;
	}
}

// ��� : 0, ���� : 1 ����
int yearCheck(int year) {
	if (year % 4 != 0) { 
		return 0; 
	}

	if (year % 100 != 0) { 
		return 1; 
	}

	if (year % 400 == 0) { 
		return 1; 
	}
	else { 
		return 0; 
	}
}

void displayDate(int year, int month, int day, int totalDay) {
	char whatDay[][7] = { "�Ͽ���", "������", "ȭ����", "������", 
		"�����", "�ݿ���", "�����" };

	int dayType = totalDay % 7;

	printf("%d�� %d�� %d���� %s�Դϴ�.\n", year, month, day, whatDay[dayType]);
}