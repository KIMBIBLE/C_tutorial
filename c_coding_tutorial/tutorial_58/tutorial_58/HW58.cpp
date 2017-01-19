#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

int inputString(char* string);
int calcSumInString(char* string);
void displayResult(char* string, int sum);
int stringAsciiToInteger(char* string, int numCiper);

int main()
{
	char string[BUFFER_SIZE];
	int sum;

	while (inputString(string)) {
		sum = calcSumInString(string);
		displayResult(string, sum);
		
		puts("");
	}

	return 0;
}

// return > ���� : 1, ����(end) : 0
int inputString(char* string) {
	printf("# ������ �Է��Ͻÿ� : ");
	scanf("%s", string);
	if (strcmp(string, "end") == 0) {
		return 0;
	}

	return 1;
}


int calcSumInString(char* string) {
	int sum = 0;
	int numCiper = 0;	//�ڸ��� ���� ����
	int numStart, numEnd;
	int i = 0;

	while (string[i]) {
		// ���ڿ� �� ���� ����(0����) �κ� ����
		if ('0' <= string[i] && string[i] <= '9') {	
			numCiper++; //�ڸ��� ī��Ʈ ����

			//���ڿ��� ���� ��ġ�� NULL�̳� ���ڰ� �ƴ� ������ ��� ��� �� ����
			if (string[i + 1] == NULL || '0' > string[i + 1] || string[i + 1] > '9') {
				//���� ���ڿ��� �����ּ�, ���� ���ڿ��� �ڸ����� ���� ���� ����
				sum += stringAsciiToInteger(&string[i+1-numCiper], numCiper);
				numCiper = 0;	//�ڸ��� �ʱ�ȭ
			}
		}
		i++;
	}

	return sum;
}


int stringAsciiToInteger(char* string, int numCiper) {
	int nowCiper = 1;
	int i;
	int resultNum = 0;

	for (i = 0; i < numCiper - 1; i++) {
		nowCiper *= 10;
	}

	for (i = 0; i < numCiper; i++) {
		resultNum += (string[i] - '0') * nowCiper;
		nowCiper /= 10;
	}

	return resultNum;
}


void displayResult(char* string, int sum) {
	printf("\"%s\" ���� �� ���ڴ� [%d]�Դϴ�.\n", string, sum);
}
