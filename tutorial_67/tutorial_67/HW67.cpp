#include <stdio.h>

#define ARRAY_SIZE 1000

int inputCnt();
void inputNumber(int *ary, int cnt);
int getDiffNumCnt(int *ary, int cnt);
void displayOutput(int diffCnt);

int main()
{
	int cnt;
	int ary[ARRAY_SIZE] = { NULL, };
	int diffCnt;

	while (cnt = inputCnt() ) {
		inputNumber(ary, cnt);
		diffCnt = getDiffNumCnt(ary, cnt);
		displayOutput(diffCnt);
	}

	return 0;
}

// �Է� ���� : 2 <= cnt <= 1000
// return > �����Է� �� 0(�����ڵ�), ���� : inputNumber()�� �Է¹��� ������ ����
int inputCnt() {
	int cnt;

	printf("* �Է��� ������ ���� : ");
	scanf("%d", &cnt);
	if (getchar() != '\n') { return 0; }

	return cnt;
}

// �Է� ���� : 1<= N <= 1000
// inputCnt�� cnt��ŭ ���� �Է¹޾� ary�迭�� ����
void inputNumber(int *ary, int cnt) {
	int i;

	printf("* ���� �Է� : ");
	for (i = 0; i < cnt; i++) {
		scanf("%d", &ary[i]);
	}

}

int getDiffNumCnt(int *ary, int cnt) {
	int diffCnt = 0;
	int temp[ARRAY_SIZE] = { 0, };
	int i;

	for (i = 0; i < cnt; i++) {
		temp[ary[i]]++;
	}

	for (i = 0; i < ARRAY_SIZE; i++) {
		if (temp[i] >= 1) { diffCnt++; }
	}

	return diffCnt;
}


void displayOutput(int diffCnt) {
	printf("���� �ٸ� ���� ���� : %d\n\n", diffCnt);
}