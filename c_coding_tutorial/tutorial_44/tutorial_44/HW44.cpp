#include <stdio.h>

int main()
{
	int i, j, k;

	//	<2중 for문을 이용한 출력>
	puts("<2중 for문을 이용한 출력>");
	for (i = 1; i <= 9; i++) {
		for (j = 2; j <= 5; j++) {
			printf("%d*%d=%2d\t\t", j, i, j*i);
		}
		puts("");
	}
	puts("");
	for (i = 1; i <= 9; i++) {
		for (j = 6; j <= 9; j++) {
			printf("%d*%d=%2d\t\t", j, i, j*i);
		}
		puts("");
	}
	puts("-------------------------------------------------------\n");

	//	<3중 for문을 이용한 출력>
	puts("<3중 for문을 이용한 출력>");
	for (i = 0; i <= 4; i += 4) {
		for (j = 1; j <= 9; j++) {
			for (k = 2 + i; k <= 5 + i; k++) {
				printf("%d*%d=%2d\t\t", k, j, k*j);
				if (k==5 || k==9) { puts(""); }
			}
		}
		puts("");
	}

	return 0;
}