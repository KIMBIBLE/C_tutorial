#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 100

void inputElementBMI(double* pWeight, double* pHeight);
double calcBMI(double weight, double height);
void printBMI(double bmi);
void errorHandling(char *);

int main()
{
	double weight, height;
	double bmi;

	inputElementBMI(&weight, &height);
	bmi = calcBMI(weight, height);
	printBMI(bmi);

	return 0;
}

void inputElementBMI(double* pWeight, double* pHeight) {
	printf("�����Ը� �Է��ϼ���(kg) : ");
	scanf("%lf", pWeight);

	printf("Ű�� �Է��ϼ���(m) : ");
	scanf("%lf", pHeight);
}


double calcBMI(double weight, double height) {
	return weight / (height * height);
}

void printBMI(double bmi) {
	char buf[BUF_SIZE] = { NULL, };
	char message[] = "����� BMI�� %.1lf�� %s�Դϴ�.\n";

	if (bmi <= 0)	//���� BMI ���� : ���
		errorHandling("Input error\n");

	if (bmi < 18.5)
		sprintf(buf, message, bmi, "��ü��");
	else if (bmi < 20.5)
		sprintf(buf, message, bmi, "����ü��");
	else if (bmi < 30.0)
		sprintf(buf, message, bmi, "��ü��");
	else if (bmi < 40.0)
		sprintf(buf, message, bmi, "��");
	else
		sprintf(buf, message, bmi, "����");

	printf("%s\n", buf);
}

void errorHandling(char *buf) {
	fputs(buf, stdout);
	exit(-1);
}