#include <stdio.h>
#include <string.h>

int main()
{
	char buf[1000];
	int bufLen = 0;

	printf("* ���ڿ� �Է� : ");
	scanf("%999s", buf);

	bufLen = strlen(buf);

	printf("[%*.*s...]\n", bufLen, bufLen / 2, buf);

	return 0;
}