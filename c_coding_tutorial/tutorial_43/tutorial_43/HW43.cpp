#include <stdio.h>

int main()
{
	char upperCaseAlpabet;
	char i, j;

	while (1) {
		printf("* 영문자 대문자 입력('A' ~ 'Z') : ");
		scanf("%c", &upperCaseAlpabet);
		
		//정상 입력 판별
		if (getchar() != '\n') { break; }	//입력 데이터(개행 제외)가 2 이상일 때 종료
		if (upperCaseAlpabet < 'A' || 'Z' < upperCaseAlpabet) { break; }

		//
		for (i = upperCaseAlpabet; i >= 'A'; i--) {
			for (j = upperCaseAlpabet; j >= i; j--) {
				printf("%c", j);
			}
			puts("");
		}
	}


	return 0;
}