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

// 입력 조건 : 2 <= cnt <= 1000
// return > 문자입력 시 0(종료코드), 정상 : inputNumber()이 입력받을 숫자의 갯수
int inputCnt() {
	int cnt;

	printf("* 입력할 숫자의 개수 : ");
	scanf("%d", &cnt);
	if (getchar() != '\n') { return 0; }

	return cnt;
}

// 입력 조건 : 1<= N <= 1000
// inputCnt의 cnt만큼 숫자 입력받아 ary배열에 저장
void inputNumber(int *ary, int cnt) {
	int i;

	printf("* 숫자 입력 : ");
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
	printf("서로 다른 수의 개수 : %d\n\n", diffCnt);
}