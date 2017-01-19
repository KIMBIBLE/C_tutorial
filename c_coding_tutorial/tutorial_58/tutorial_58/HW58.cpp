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

// return > 성공 : 1, 종료(end) : 0
int inputString(char* string) {
	printf("# 문장을 입력하시오 : ");
	scanf("%s", string);
	if (strcmp(string, "end") == 0) {
		return 0;
	}

	return 1;
}


int calcSumInString(char* string) {
	int sum = 0;
	int numCiper = 0;	//자릿수 저장 변수
	int numStart, numEnd;
	int i = 0;

	while (string[i]) {
		// 문자열 중 양의 정수(0포함) 부분 시작
		if ('0' <= string[i] && string[i] <= '9') {	
			numCiper++; //자리수 카운트 증가

			//문자열의 다음 위치가 NULL이나 숫자가 아닌 문자일 경우 양수 합 누적
			if (string[i + 1] == NULL || '0' > string[i + 1] || string[i + 1] > '9') {
				//정수 문자열의 시작주소, 정수 문자열의 자릿수를 통해 숫자 추출
				sum += stringAsciiToInteger(&string[i+1-numCiper], numCiper);
				numCiper = 0;	//자릿수 초기화
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
	printf("\"%s\" 내의 총 숫자는 [%d]입니다.\n", string, sum);
}
