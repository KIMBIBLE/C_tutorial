#include <stdio.h>
#include <string.h>

#define STRING_SIZE 50

void inputStringNumber(char* stringNumber);
int StringToInteger(char* stringNumber);
void integerToString(char* stringNumber, int sum);

int main()
{
	int sum = 0;
	char stringNumber[STRING_SIZE] = { NULL, };
	int i = 0;
	int len;

	while (1) {
		inputStringNumber(stringNumber);
		len = strlen(stringNumber);

		// ���� ���� : 0000 �Է�
		if (!strcmp(stringNumber, "0000")) { break; }
		
		// string -> integer ��ȯ �� �� ����
		sum += StringToInteger(stringNumber);

		//���ڿ� NULL �ʱ�ȭ
		i = 0;
		while (stringNumber[i]) {
			stringNumber[i++] = NULL;
		}
	}

	// ������ (,) �߰��� ���ڿ� ������ ��ȯ
	integerToString(stringNumber, sum);

	printf("���� : %s\n", stringNumber);


	return 0;
}


void inputStringNumber(char* stringNumber) {
	int i;
	int flag = 1;	//flag : 1�ε��� �ݺ�(������ �Է�)

	while (flag) {
		i = 0;
		printf("�ݾ� �Է� : ");
		scanf("%s", stringNumber);

		// ���ڿ� �˻�(���� : 0~9, ',')
		while (stringNumber[i]) {
			if ('0' <= stringNumber[i] && stringNumber[i] <= '9') { ; }
			else if (stringNumber[i] == ',') { ; }
			else {	//���ڿ� �� ���� �̿��� ���� ������ ���Է� �䱸
				flag = 1;
				break;
			}
			i++;
		}
		flag = 0;	// ���ڿ� �˻� ����ϸ� flag = 0 ���� �ݺ� stop
	}
}


int StringToInteger(char* stringNumber) {
	int num = 0;
	int len;
	int i = 0;
	int chiper =1;
	
	len = strlen(stringNumber);
	for (i = len; i >= 0; i--) {
		if ('0' <= stringNumber[i] && stringNumber[i] <= '9') {
			num += (stringNumber[i] - '0') * chiper;
			chiper *= 10;
		}
		else if (stringNumber[i] == ',') { ; }
		else { ; }
	}

	return num;
}

void integerToString(char* stringNumber, int num) {
	int temp = num;
	int chiper = 1;	//�ڸ���
	int i;
	int chiperToDiv = 1;

	while (temp /= 10) {
		chiper++;
		chiperToDiv *= 10;
	}

	for (i = 0; i < STRING_SIZE; i++) {
		if (chiper == 0) { break; }
		if (chiper % 3 == 0 && i != 0) {
			stringNumber[i++] = ',';
		}
		stringNumber[i] = (num / chiperToDiv) + '0';
		num %= chiperToDiv;
		chiperToDiv /= 10;
		chiper--;
	}

}