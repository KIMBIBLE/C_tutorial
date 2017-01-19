#include <stdio.h>

int main()
{
	int i;
	int num;	//양수 저장
	int sum;	//양수 누계

	sum = 0;
	for (i = 1; i <= 5; ) {
		printf("0 보다 큰수를 입력하시오(%d번째) : ", i);
		scanf("%d", &num);
		if (num > 0) { 
			sum += num;
			i++;
		}
	}
	printf("입력된 값의 총 합 : %d\n", sum);

	return 0;
}