#include <stdio.h>

int inputPrintCnt();

int main()
{
	int cnt;
	int i;

	cnt = inputPrintCnt();

	i = 0;
	while (i++ != cnt) {
		printf("*");
		if (i % 5 == 0)
			printf("\n");
	}
	puts("");

	return 0;
}

int inputPrintCnt() {
	int cnt = 0;

	while (1) {
		printf("# �������� �Է��ϼ��� : ");
		if (scanf("%d", &cnt) == 1) 
			break;
	}
	
	return cnt;
}