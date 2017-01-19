#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH  13 /* �ֹε�Ϲ�ȣ ����*/

int availabilityCheck(char *resident_number);
int checkLengthCharacter(char *resident_number);
int checkDate(char *resident_number);
int checkIdentification(char *resident_number);
int checkGender(char *resident_number);
int checkYear(int year);
int getMonthMax(int year, int month);
int parseYear(char* resident_number);
int parseMonth(char* resident_number);
int parseDay(char* resident_number);

int main()
{
	/* �׽�Ʈ�� �ֹε�Ϲ�ȣ ���� �迭*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
		"0003154194917", "801203#201122", "7804155328845", "7804150328840",
		"9612241068382", "9902292194322", "0230174326176", "8811391042219",
		"8100122042213", "8112002042213", "9210101069415", "0802294012345",
		"8806311069417","8807311069418" };
	int i, count;
	/* �˻��� �ֹε�Ϲ�ȣ�� ���� ���*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);
	for (i = 0; i<count; i++) /* �ֹε�Ϲ�ȣ ��ȿ�� �˻縦 �ݺ������� ���� ��*/
	{
		if (availabilityCheck(resident_number[i]) == TRUE)
		{
			printf("(+) �ֹι�ȣ%s��(��) ��ȿ�� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
		else
		{
			printf("(-) �ֹι�ȣ%s��(��) ��ȿ���� ���� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
	}
	return 0;
}


/*----------------------------------------------------------------
availabilityCheck()�Լ�: �ֹε�Ϲ�ȣ ��ȿ�� �˻� �Լ�
��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
���ϰ�: ��ȿ�ϸ�TRUE, ��ȿ���� ������FALSE ����
------------------------------------------------------------------*/
int availabilityCheck(char *resident_number) {
	if (!checkLengthCharacter(resident_number)) { return FALSE; }
	if (!checkDate(resident_number)) { return FALSE; }
	if (!checkGender(resident_number)) { return FALSE; }
	if (!checkIdentification(resident_number)) { return FALSE; }

	return TRUE;
}

/*-------------------------------------------------------------------------
checkLengthCharacter()�Լ�: �ֹε�Ϲ�ȣ ���� �� ���� ��ȿ���˻� �Լ�
��������: �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
���ϰ�: �ֹε�Ϲ�ȣ�� ���̰� �°� ���ڹ��ڷθ� �����Ǿ� ������TRUE,
���̰� ª�ų� ���, ���� ���ڰ� �ƴ� ���ڰ� ���� ������FALSE ����
--------------------------------------------------------------------------*/
int checkLengthCharacter(char *resident_number) {
	int i;
	int len;
	len = strlen(resident_number);

	if (len != 13) { return FALSE; }
	for (i = 0; i < len; i++) {
		if (resident_number[i] <'0' || resident_number[i] > '9') {
			return FALSE;
		}
	}

	return TRUE;
}

/*----------------------------------------------------------------
checkDate()�Լ�: ù6�ڸ�(��,��,��)�� ��ȿ�� �˻� �Լ�
��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
���ϰ�: ��ȿ�� ��¥�̸�TRUE, ��ȿ���� ���� ��¥�̸�FALSE ����
------------------------------------------------------------------*/
int checkDate(char *resident_number) {
	int year;
	int month;
	int day;

	// �ֹε�Ϲ�ȣ���� ��,��,�� ����
	year = parseYear(resident_number);
	month = parseMonth(resident_number);
	day = parseDay(resident_number);

	// ��¥ ������ �Է��� ��ȿ�� �˻�(��,�� -> ��)
	if (1 <= month && month <= 12) {
		if (1 <= day && day <= getMonthMax(year, month)) { return TRUE; }
	}

	return FALSE;
}


/*----------------------------------------------------------------------
checkGender()�Լ�: 7��° �ڸ��� �����ĺ���ȣ ��ȿ�� �˻��Լ�
��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
���ϰ�: �����ĺ���ȣ��'1'~'4'�̸�TRUE, �� �� ���� �����̸�FALSE ����
-----------------------------------------------------------------------*/
int checkGender(char *resident_number) {
	if ('1' <= resident_number[6] && resident_number[6] <= '4') {
		return TRUE;
	}

	return FALSE;
}


/*------------------------------------------------------------------------
checkIdentification()�Լ�: �ֹε�Ϲ�ȣ ���ڸ�(�ν���) ��ȿ�� �˻� �Լ�
��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
���ϰ�: ��ȿ�� �ν����̸�TRUE, ��ȿ���� ���� �ν����̸� FALSE ����
-------------------------------------------------------------------------*/
int checkIdentification(char *resident_number) {
	int i;
	int check = 0; 
	int len;

	len = strlen(resident_number);
	for (i = 0; i < len - 1; i++) {
		check += resident_number[i] - '0';
	}
	check %= 10;

	if (check == resident_number[i] - '0') {
		return TRUE;
	}
	
	return FALSE;
}


/*----------------------------------------------------------------
checkYear ()�Լ�: �⵵�� ��,��� ���� �˻�
��������: ��,��� �˻��� �⵵
���ϰ�: �����̸� TRUE, ����̸�FALSE ����
------------------------------------------------------------------*/
int checkYear(int year) {
	if (year % 4 != 0) {
		return FALSE;
	}

	if (year % 100 != 0) {
		return TRUE;
	}

	if (year % 400 == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}

}


// ��� : �������ڷ� ���� year, month�� ���� �ش� ��,���� �ִ� ��¥ ���� 
int getMonthMax(int year, int month) {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	//2���� ��� ����� �˻�. ���� : 29��, ��� :28��
	else if (month == 2) {
		if (checkYear(year)) { return 29; }	//����
		else { return 28; }	//���
	}
	else {	//month = 1,3,5,7,8,10,12
		return 31;
	}
}


/*----------------------------------------------------------------
parseYear ()�Լ�: �ֹε�Ϲ�ȣ���� ���� ����
��������: �ֹε�Ϲ�ȣ �迭
���ϰ�: ������ ����
------------------------------------------------------------------*/
int parseYear(char* resident_number) {
	int year = 0;

	if (resident_number[0] == '0') {
		year += 2000;
	}
	else {
		year += 1900;
	}

	year += (resident_number[0] - '0') * 10;
	year += (resident_number[1] - '0');

	return year;
}


/*----------------------------------------------------------------
parseMonth ()�Լ�: �ֹε�Ϲ�ȣ���� �� ����
��������: �ֹε�Ϲ�ȣ �迭
���ϰ�: ������ ����
------------------------------------------------------------------*/
int parseMonth(char* resident_number) {
	int month = 0;

	month += (resident_number[2] - '0') * 10;
	month += resident_number[3] - '0';

	return month;
}


/*----------------------------------------------------------------
parseMonth ()�Լ�: �ֹε�Ϲ�ȣ���� �� ����
��������: �ֹε�Ϲ�ȣ �迭
���ϰ�: ������ ����
------------------------------------------------------------------*/
int parseDay(char* resident_number) {
	int day = 0;

	day += (resident_number[4] - '0') * 10;
	day += resident_number[5] - '0';

	return day;
}

