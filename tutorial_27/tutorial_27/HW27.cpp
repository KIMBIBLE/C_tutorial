#include <stdio.h>

int inputEggWeight();

int main()
{
	int weight;
	int cnt;

	cnt = 0;
	while ( cnt < 10 ) {
		weight = inputEggWeight();
		if (weight < 150)	printf("*���߸��� ������ �峭���� ���ÿ�~ ^^\n");
		else if (weight > 500)	printf("*Ÿ���� ������ �峭���� ���ÿ�~ ^^\n");
		else printf("* ���� �ް��� �� : %d\n", ++cnt);
	}
	printf("\n*** �ް� ������ �������ϴ�.\n");

	return 0;
}

int inputEggWeight() {
	int weight;

	printf("# ����� ���Ը� �Է��ϼ���(���� :g) : ");
	while (scanf("%d", &weight) != 1) {
		while (getchar() != '\n');
		printf("# ����� ���Ը� �Է��ϼ���(���� :g) : ");
	}

	return weight;
}
