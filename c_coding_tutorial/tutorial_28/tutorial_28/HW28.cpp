#include <stdio.h>

int main()
{
	int alpabetCnt = 0;
	int numberCnt = 0;
	int whiteSpaceCnt = 0;
	int etcCnt = 0;

	char ch;
	
	printf("# ���� ������ �Է� �Ͻÿ� :\n");

	while ((ch = getchar()) != EOF) {
		if (ch == EOF && ch == '\n')	break;
		else if ('a' <= ch && ch <= 'z')	alpabetCnt++;
		else if ('A' <= ch && ch <= 'Z')	alpabetCnt++;
		else if ('0' <= ch && ch <= '9')	numberCnt++;
		else if (ch == ' ' || ch == '\t' || ch == '\n')
			whiteSpaceCnt++;
		else	etcCnt++;
	}

	printf("* ������ ��ҹ��� ���� : %d��\n", alpabetCnt);
	printf("* ���ڹ��� ���� : %d��\n", numberCnt);
	printf("* ���鹮��(space, tab, enter) ���� : %d��\n", whiteSpaceCnt);
	printf("* �� �� ��Ÿ���� ���� : %d��\n", etcCnt);

	return 0;
}
