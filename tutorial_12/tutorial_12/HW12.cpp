#include <stdio.h>

int main()
{
	char name[1000];

	printf("�̸��� �Է��Ͻÿ� : ");
	scanf("%999s", name);

	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\'%-20s\"\n", name);

	return 0;
}