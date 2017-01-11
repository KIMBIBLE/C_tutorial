#include <stdio.h>

void swap(int *pNum1, int *pNum2);

int main()
{
	int ary[] = { 5, 8, 13, -6, 0 };
	int i, j;
	int arySize;

	arySize = sizeof(ary) / sizeof(int);
	printf("처음 배열에 저장된 값 : ");
	for (i = 0; i < arySize; i++) {
		printf("%  d", ary[i]);
	}
	puts("");
	for (i = 0; i < arySize - 1; i++) {
		for (j = 1; j < arySize - i; j++) {
			if (ary[j - 1] > ary[j]) {
				swap(&ary[j - 1] , &ary[j]);
			}
		}
	}

	printf("바뀐 배열에 저장된 값 : ");
	for (i = 0; i < arySize; i++) {
		printf("%  d", ary[i]);
	}
	puts("");

	return 0;
}

void swap(int *pNum1, int *pNum2) {
	int temp;

	temp = *pNum1;
	*pNum1 = *pNum2;
	*pNum2 = temp;
}