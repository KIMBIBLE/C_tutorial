#include <stdio.h>

int main()
{
	int num1, num2;
	int temp;		//for swap
	FILE* a;
	while (1) {
		printf("# 두개의 정수를 입력하세요 : ");
		if (scanf("%d %d", &num1, &num2) != 2) 
			break;
		//num1, num2 대소비교하여 크거나 같은 값을 num1 에 저장
		if (num2 > num1) {
			temp = num1;
			num1 = num2;
			num2 = temp;
		}

		printf("%d - %d = %d\n", num1, num2, num1 - num2);
	}

	return 0;
}