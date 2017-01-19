#include <stdio.h>

int main()
{
	int asciiCode;

	printf("ASCII code를 입력하시오 : ");
	scanf("%d", &asciiCode);

	printf("%d은 '%c'의 ASCII code 입니다.\n", asciiCode, asciiCode);

	return 0;
}