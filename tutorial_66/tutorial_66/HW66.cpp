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

		// 종료 조건 : 0000 입력
		if (!strcmp(stringNumber, "0000")) { break; }
		
		// string -> integer 변환 후 합 누적
		sum += StringToInteger(stringNumber);

		//문자열 NULL 초기화
		i = 0;
		while (stringNumber[i]) {
			stringNumber[i++] = NULL;
		}
	}

	// 총합을 (,) 추가한 문자열 형으로 변환
	integerToString(stringNumber, sum);

	printf("총합 : %s\n", stringNumber);


	return 0;
}


void inputStringNumber(char* stringNumber) {
	int i;
	int flag = 1;	//flag : 1인동안 반복(비정상 입력)

	while (flag) {
		i = 0;
		printf("금액 입력 : ");
		scanf("%s", stringNumber);

		// 문자열 검사(정상 : 0~9, ',')
		while (stringNumber[i]) {
			if ('0' <= stringNumber[i] && stringNumber[i] <= '9') { ; }
			else if (stringNumber[i] == ',') { ; }
			else {	//문자열 중 정상 이외의 값이 있으면 재입력 요구
				flag = 1;
				break;
			}
			i++;
		}
		flag = 0;	// 문자열 검사 통과하면 flag = 0 으로 반복 stop
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
	int chiper = 1;	//자릿수
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