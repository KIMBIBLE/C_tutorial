#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

void initRandomNum(int *keyAry);
void disPlayRandomNum(int *keyAry);
int checkBallCount(int *keyAry, int *ballCount);
int random(int numRange);

int main()
{
	int keyAry[4];
	int ballCount[2];	//[0]: Strike, [1] : Ball, �Ѵ� 0�� ���� No!(Out)
	int i;
	int playCnt = 11;
	
	srand((unsigned int)time(NULL));	//���� seed ����

	initRandomNum(keyAry);
	disPlayRandomNum(keyAry);

	// 11�� ���� �÷���
	for (i = 1; i <= playCnt; i++) {
		printf("# %d�� : ", i);
		if (checkBallCount(keyAry, ballCount)) {
			if (ballCount[0] == 4) {
				printf("\tOK~~!!\n");
				printf("--------------------\n");
				printf("You Win!!!! ���� ����!!!\n\n");
				return 1;
			}

			printf("\t%dS %dB\n", ballCount[0], ballCount[1]);
		}
		else {
			printf("\tNo!\n");
		}

		if (i == 11) {
			printf("--------------------\n");
			printf("You Lose~~ ���� ����!!!\n\n");
		}
	}

	return 0;
}


/*	void initRandomNum(int *keyAry) 
��� > 0~9 ������ �ߺ����� �ʴ� ���� 4���� �߻����� keyAry �迭�� ����
parm1 > �߻��� ������ ������ int�� �迭
return > None
*/
void initRandomNum(int *keyAry) {
	int num;	//����
	int cnt = 0;	//���� �߻� ���� Ƚ�� ī��Ʈ ����(4���� ���� �߻�)
	int i;
	int temp[10] = { -1};	
	
	for (i = 0; i < 10; i++) {
		temp[i] = -1;
	}
	/* �迭�� �� ��Ұ� 0~9 �� ���� �ߺ����� �ʵ��� �ӽ� �迭 ����
	 �迭�� �� ��ҿ� random() Ret ���� ��Ī�Ͽ� ���.
	 �߻��� ������ �ش�Ǵ� temp �迭�� �ε����� ��ġ�� ���� �� ���� */
	while (1) {
		// ��ݺ��� ���� �ʱ�ȭ
		cnt = 0;
		for (i = 0; i < 10; i++) {
			temp[i] = -1;
		}

		// ���� 4�� ����
		for (i = 0; i < 4; i++) {
			num = random(10);
			temp[num] = num;
		}

		// �ӽ� �迭�� ������ ���� �� �ߺ� ���� �˻�
		for (i = 0; i < 10; i++) {
			/* �迭�� ��� ��Ҹ� ������ temp �迭�� �ʱ� ������ ���� 
			'-1(������ �ߺ����� �ʴ� ��)'�� �ٸ� ���� ī��Ʈ
			cnt == ���� �߻� �� �ߺ��� ������ ���� ���� */
			if (temp[i] != -1) { cnt++; }	
			
		}
		/* cnt�� ���� �ݺ� Ƚ�� ����( cnt == 4)�� ���
		�ߺ� ������ �����Ƿ� �ݺ� Ż��	*/
		if (cnt == 4) { break; }
		
	}

	// �ӽ� �迭�� ����� ���� �ٸ� ���� ������ keyAry�� ����
	for (i = 0; i < 10; i++) {
		if (temp[i] != -1) {
			// index : 3 ~ 0 ������ ����(4ȸ)
			keyAry[--cnt] = temp[i];
		}
		if (cnt == 0) { break; }
	}

}


/*	void disPlayRandomNum(int *keyAry)
��� > ��ǻ�Ͱ� �߻���Ų 4�ڸ� ���� ���
parm1 > ����� ������ ����� keyAry �迭
return > None
*/
void disPlayRandomNum(int *keyAry) {
	int i;

	printf("��ǻ�Ͱ� �߻��� ����\n");
	printf("--------------------\n   ");
	for (i = 0; i < 4; i++) {
		printf("%3d", keyAry[i]);
	}
	printf("\n--------------------\n");
}



int checkBallCount(int *keyAry, int *ballCount) {
	int inputCnt = 4;
	int i, j;
	int userInput[4];

	for (i = 0; i < 4; i++) {
		userInput[i] = -1;
	}

	// ��ī��Ʈ �ʱ�ȭ
	ballCount[0] = 0;	//'0' Strike
	ballCount[1] = 0;	//'0' Ball

	//���� �Է� (4ȸ)
	for (i = 0; i < inputCnt; i++) {
		printf("  ");
		userInput[i] = getche() - '0';
	}

	//Strike �Ǻ�
	for (i = 0; i < inputCnt; i++) {
		if (userInput[i] == keyAry[i]) {
			ballCount[0]++;
			userInput[i] = -1;	// ���� ball �˻翡�� �ߺ� Block
		}
	}

	if (ballCount[0] + ballCount[1] == 4) { return 1; }

	//Ball �Ǻ�
	for (i = 0; i < inputCnt; i++) {
		for (j = 0; j < inputCnt; j++) {
			if (keyAry[i] == userInput[j]) {
				ballCount[1]++;
			}
		}
	}

	if (ballCount[0] + ballCount[1] == 4) { return 1; }

	//ballCount ��� �Ǻ� (strike�� ball�� ������ 1, ������ 0 ����)
	if (ballCount[0] == 0 && ballCount[1] == 0) {
		return 0;
	}

	return 1;
}

int random(int numRange) {
	return rand() % numRange;
}