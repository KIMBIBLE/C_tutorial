#include <stdio.h>

int main()
{
	int alpabetCnt = 0;
	int numberCnt = 0;
	int whiteSpaceCnt = 0;
	int etcCnt = 0;

	char ch;
	
	printf("# 영문 문장을 입력 하시오 :\n");

	while ((ch = getchar()) != EOF) {
		if (ch == EOF && ch == '\n')	break;
		else if ('a' <= ch && ch <= 'z')	alpabetCnt++;
		else if ('A' <= ch && ch <= 'Z')	alpabetCnt++;
		else if ('0' <= ch && ch <= '9')	numberCnt++;
		else if (ch == ' ' || ch == '\t' || ch == '\n')
			whiteSpaceCnt++;
		else	etcCnt++;
	}

	printf("* 영문자 대소문자 개수 : %d개\n", alpabetCnt);
	printf("* 숫자문자 개수 : %d개\n", numberCnt);
	printf("* 여백문자(space, tab, enter) 개수 : %d개\n", whiteSpaceCnt);
	printf("* 그 외 기타문자 개수 : %d개\n", etcCnt);

	return 0;
}
