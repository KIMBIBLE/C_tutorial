#include <stdio.h>

int main()
{
	char upperCaseAlpabet;
	char i, j;

	while (1) {
		printf("* ������ �빮�� �Է�('A' ~ 'Z') : ");
		scanf("%c", &upperCaseAlpabet);
		
		//���� �Է� �Ǻ�
		if (getchar() != '\n') { break; }	//�Է� ������(���� ����)�� 2 �̻��� �� ����
		if (upperCaseAlpabet < 'A' || 'Z' < upperCaseAlpabet) { break; }

		//
		for (i = upperCaseAlpabet; i >= 'A'; i--) {
			for (j = upperCaseAlpabet; j >= i; j--) {
				printf("%c", j);
			}
			puts("");
		}
	}


	return 0;
}