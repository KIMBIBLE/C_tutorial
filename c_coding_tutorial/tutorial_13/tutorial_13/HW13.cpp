#include <stdio.h>
#include <string.h>

int main()
{
	char lastName[1000];
	char firstName[1000];

	int lastNameLen = 0;
	int firstNameLen = 0;


	printf("#성을 입력하시오 : ");
	scanf("%999s", lastName);

	printf("#이름을 입력하시오 : ");
	scanf("%999s", firstName);

	lastNameLen = strlen(lastName);
	firstNameLen = strlen(firstName);

	printf("%*s\t", firstNameLen, firstName);
	printf("%*s\n", lastNameLen, lastName);

	printf("%*d\t", firstNameLen, firstNameLen);
	printf("%*d\n", lastNameLen, lastNameLen);

	return 0;
}