#include <stdio.h>

int main()
{
	int i, j;
	int line;

	while (1) {
		printf("# 출력 라인 수를 입력하시오 : ");
		if (!scanf("%d", &line)) { break; }
		//사용자 입력 line 단위 출력

		for (i = 1; i <= line; i++) {
			for (j = 1; j <= i; j++) {
				printf("*");
			}
			for (j = line-i; j >= 0; j--) {
				printf("  ");	//double space
			}
			for (j = 1; j <= i; j++) {
				printf("*");
			}
			puts("");
		}
	}

	return 0;
}