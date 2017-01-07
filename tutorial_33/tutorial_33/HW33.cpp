#include <stdio.h>

int inputUint(char* message);
double inputDouble(char* message);
int ipow(int num, int n);
double fpow(double dNum, unsigned int n);

int main()
{
	int num;	// 양의 정수 밑
	double dNum;	//양의 실수 밑
	
	int n;	// 양의 승

	int res;	// ipow 결과
	double dRes;	//fpow 결과

	num = inputUint("* 양의 정수 밑을 입력하시오 : ");
	n = inputUint("* 양의 승을 입력 하시오 : ");
	res = ipow(num, n);
	printf("%d의 %d승은 %d입니다.\n", num, n, res);

	puts("\n\n");

	dNum = inputDouble("양의 실수 밑을 입력하시오 : ");
	n = inputUint("* 양의 승을 입력 하시오 : ");
	dRes = fpow(dNum, n);
	printf("%.2lf의 %d승은 %.3lf 입니다.\n", dNum, n, dRes);

	return 0;
}

int inputUint(char* message) {
	int num;

	while (1) {
		printf("%s", message);
		scanf("%d", &num);
		if ( num >= 0 && getchar() == '\n') { break; }
		while (getchar() != '\n') { ; }
	}
	return num;
}

double inputDouble(char* message) {
	double dNum;

	while (1) {
		printf("%s", message);
		scanf("%lf", &dNum);
		if (dNum >= 0 && getchar() == '\n') { break; }
		while (getchar() != '\n') { ; }
	}

	return dNum;
}

int ipow(int num, int n) {
	int res = 1;

	if (n == 0 || num == 0)	return 1;
	while (n--) { res *= num; }

	return res;
}

double fpow(double dNum, unsigned int n) {
	double dRes = 1.0;

	if (n == 0 || dNum == 0)	return 1;
	while (n--) { dRes *= dNum; }

	return dRes;
}