#include <stdio.h>

int main()
{
	int fiboCnt;
	int prevNum1 = 1, prevNum2 = 1;	//fibo 시작 값 (1, 1)
	int fiboNum;
	int i ;
	int sum = 0;

	printf("피보나치 수열의 항수를 입력하시오 : ");
	scanf("%d", &fiboCnt);

	for (i = 1; i <= fiboCnt; i++) {
		if (i == 1 || i == 2) {
			printf("1 +");
			sum += 1;
		}
		else {
			fiboNum = prevNum1 + prevNum2;
			sum += fiboNum;
			printf(" %d +", fiboNum);
			prevNum1 = prevNum2;
			prevNum2 = fiboNum;
		}
	}

	printf("\b = %d\n", sum);

	return 0;
}
