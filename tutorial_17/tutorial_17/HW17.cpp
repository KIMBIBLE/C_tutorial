#include <stdio.h>
#include <string.h>

int main()
{
	char name[200];
	double height;
	char sex;
	char msg[210];

	printf("���� �Է� : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = NULL;

	printf("Ű �Է�(cm����) : ");
	scanf("%lf", &height);
	while (getchar() != '\n') { ; }

	printf("�����Է�(M/F) : ");
	scanf("%c", &sex);

	if (sex == 'M')
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n",name, height);
	else if (sex == 'F')
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n",name, height);
	else

	return 0;
}