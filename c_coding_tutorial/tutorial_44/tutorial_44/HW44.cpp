#include <stdio.h>

int main()
{
	int i, j, k;

	//	<2�� for���� �̿��� ���>
	puts("<2�� for���� �̿��� ���>");
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

	//	<3�� for���� �̿��� ���>
	puts("<3�� for���� �̿��� ���>");
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