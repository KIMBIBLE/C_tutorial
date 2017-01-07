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
	printf("게임 결과 : %d 승 %d 무\n", win, draw);

	return 0;
}


// return> 1: 바위, 2 : 가위, 3 : 보
int inputNumber() {
	int num;

	printf("바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");
	while (scanf("%d", &num) != 1 || (num < 1 || 3 < num)) {
		while (getchar() != '\n')	NULL;
		printf("바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");
	}

	return num;
}

// parm num > 1: 바위, 2 : 가위, 3 : 보
// parm key > random value : 1~3
// return > lose : 0, win : 1, draw : 2
int playOneGame(int num,int key) {
	int res;	

	if (num == 1) {
		if (key == 1) {
			printf("당신은 바위 선택, 컴퓨터는 바위 선택 : 비겼습니다.\n");
			res = 2;
		}
		else if (key == 2) {
			printf("당신은 바위 선택, 컴퓨터는 가위 선택 : 이겼습니다.\n");
			res = 1;
		}
		else {
			printf("당신은 바위 선택, 컴퓨터는 보 선택 : 당신이 졌습니다.\n");
			res = 0;
		}
	}
	else if (num == 2) {
		if (key == 1) {
			printf("당신은 가위 선택, 컴퓨터는 바위 선택 : 당신이 졌습니다.");
			res = 0;
		}
		else if (key == 2) {
			printf("당신은 가위 선택, 컴퓨터는 가위 선택 : 비겼습니다.\n");
			res = 2;
		}
		else {
			printf("당신은 가위 선택, 컴퓨터는 보 선택 : 이겼습니다.\n");
			res = 1;
		}
	}
	else {//num ==  3
		if (key == 1) {
			printf("당신은 보 선택, 컴퓨터는 바위 선택 : 이겼습니다.\n");
			res = 1;
		}
		else if (key == 2) {
			printf("당신은 보 선택, 컴퓨터는 가위 선택 : 당신이 졌습니다.\n");
			res = 0;
		}
		else {
			printf("당신은 보 선택, 컴퓨터는 보 선택 : 비겼습니다.\n");
			res = 2;
		}
	}

	return res;
}
