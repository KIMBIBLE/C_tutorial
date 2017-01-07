#include <stdio.h>

int inputUint(char* message);
double inputDouble(char* message);
int ipow(int num, int n);
double fpow(double dNum, unsigned int n);

int main()
{
	int num;	// ���� ���� ��
	double dNum;	//���� �Ǽ� ��
	
	int n;	// ���� ��

	int res;	// ipow ���
	double dRes;	//fpow ���

	num = inputUint("* ���� ���� ���� �Է��Ͻÿ� : ");
	n = inputUint("* ���� ���� �Է� �Ͻÿ� : ");
	res = ipow(num, n);
	printf("%d�� %d���� %d�Դϴ�.\n", num, n, res);

	puts("\n\n");

	dNum = inputDouble("���� �Ǽ� ���� �Է��Ͻÿ� : ");
	n = inputUint("* ���� ���� �Է� �Ͻÿ� : ");
	dRes = fpow(dNum, n);
	printf("%.2lf�� %d���� %.3lf �Դϴ�.\n", dNum, n, dRes);

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