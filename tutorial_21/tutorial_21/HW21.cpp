#include <stdio.h>

int main()
{
	double height;
	double sum;

	int inputCnt = 5;
	int i;

	sum = 0;
	for (i = 0; i < inputCnt; i++) {
		printf("%d 번 학생의 키는? ", i+1);
		scanf("%lf", &height);
		sum += height;
	}
	
	printf("다섯 명의 평균 키는 %.1lf cm 입니다\n", sum/inputCnt);

	return 0;
}