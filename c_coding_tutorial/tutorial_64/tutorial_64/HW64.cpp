#include <stdio.h>

int inputNumber(int *ary);
int getMax(int *ary, int len);
int getMin(int *ary, int len);
void display(int *ary, int maxIdx, int minIdx, int len);

int main()
{
	int ary[100];
	int len;
	int maxIdx, minIdx;

	while (len = inputNumber(ary)) {
		maxIdx = getMax(ary, len);
		minIdx = getMin(ary, len);
		display(ary, maxIdx, minIdx, len);
	}

	return 0;
}

// return > 0 : 문자입력(종료), 정상 : 입력 데이터의 갯수 + 1(0포함)
int inputNumber(int *ary) {
	int i;

	printf("* 정수입력 : ");
	for (i = 0; i < 100; i++) {
		if (!scanf("%d", &ary[i])) { return 0; }
		if (ary[i] == 0) { break; }
	}

	return i + 1;
}

int getMax(int *ary, int len) {
	int i;
	int max = ary[0];
	
	for (i = 1; i < len; i++) {
		if (ary[i] > max) { max = ary[i]; }
	}

	for (i = 0; i < len; i++) {
		if (max == ary[i]) { return i; }
	}
}

int getMin(int *ary, int len) {
	int i;
	int min = ary[0];

	for (i = 1; i < len; i++) {
		if (ary[i] < min) { min = ary[i]; }
	}

	for (i = 0; i < len; i++) {
		if (min == ary[i]) { return i; }
	}
}

void display(int *ary, int maxIdx, int minIdx, int len) {
	int i;

	printf("최대값 : %d(index:%d)   /   최소값 : %d(index:%d)\n",
		ary[maxIdx], maxIdx, ary[minIdx], minIdx);

}
