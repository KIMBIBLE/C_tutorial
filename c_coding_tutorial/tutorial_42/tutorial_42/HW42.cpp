#include <stdio.h>

int main()
{
	int i, j;
	int line;

	while (1) {
		printf("# ��� ���� ���� �Է��Ͻÿ� : ");
		if (!scanf("%d", &line)) { break; }
		//����� �Է� line ���� ���

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