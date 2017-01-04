#include <stdio.h>
#include <string.h>

int main()
{
	char name[200];
	double height;
	char sex;
	char msg[210];

	printf("성명 입력 : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = NULL;

	printf("키 입력(cm단위) : ");
	scanf("%lf", &height);
	while (getchar() != '\n') { ; }

	printf("성별입력(M/F) : ");
	scanf("%c", &sex);

	if (sex == 'M')
		printf("%s씨의 키는 %.2lfcm이고 남성입니다.\n",name, height);
	else if (sex == 'F')
		printf("%s씨의 키는 %.2lfcm이고 여성입니다.\n",name, height);
	else

	return 0;
}