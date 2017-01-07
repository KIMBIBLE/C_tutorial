#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputNumber();
int playOneGame(int num, int key);

int main()
{
	int num;
	int win = 0, draw = 0;
	int key;
	int res;

	srand((unsigned int)time(NULL));
	key = rand() % 3 + 1;

	num = inputNumber();
	while (res = playOneGame(num, key)) {// return > lose : 0, win : 1, draw : 2
		if (res == 1) win++;
		else if (res == 2)	draw++;
		else;

		key = rand() % 3 + 1;
		num = inputNumber();
	}
	printf("���� ��� : %d �� %d ��\n", win, draw);

	return 0;
}


// return> 1: ����, 2 : ����, 3 : ��
int inputNumber() {
	int num;

	printf("������ 1, ������ 2, ���� 3 �߿��� �����ϼ��� : ");
	while (scanf("%d", &num) != 1 || (num < 1 || 3 < num)) {
		while (getchar() != '\n')	NULL;
		printf("������ 1, ������ 2, ���� 3 �߿��� �����ϼ��� : ");
	}

	return num;
}

// parm num > 1: ����, 2 : ����, 3 : ��
// parm key > random value : 1~3
// return > lose : 0, win : 1, draw : 2
int playOneGame(int num,int key) {
	int res;	

	if (num == 1) {
		if (key == 1) {
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
			res = 2;
		}
		else if (key == 2) {
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n");
			res = 1;
		}
		else {
			printf("����� ���� ����, ��ǻ�ʹ� �� ���� : ����� �����ϴ�.\n");
			res = 0;
		}
	}
	else if (num == 2) {
		if (key == 1) {
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : ����� �����ϴ�.");
			res = 0;
		}
		else if (key == 2) {
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
			res = 2;
		}
		else {
			printf("����� ���� ����, ��ǻ�ʹ� �� ���� : �̰���ϴ�.\n");
			res = 1;
		}
	}
	else {//num ==  3
		if (key == 1) {
			printf("����� �� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n");
			res = 1;
		}
		else if (key == 2) {
			printf("����� �� ����, ��ǻ�ʹ� ���� ���� : ����� �����ϴ�.\n");
			res = 0;
		}
		else {
			printf("����� �� ����, ��ǻ�ʹ� �� ���� : �����ϴ�.\n");
			res = 2;
		}
	}

	return res;
}
