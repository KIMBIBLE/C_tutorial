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
	printf("몸무게를 입력하세요(kg) : ");
	scanf("%lf", pWeight);

	printf("키를 입력하세요(m) : ");
	scanf("%lf", pHeight);
}


double calcBMI(double weight, double height) {
	return weight / (height * height);
}

void printBMI(double bmi) {
	char buf[BUF_SIZE] = { NULL, };
	char message[] = "당신의 BMI는 %.1lf로 %s입니다.\n";

	if (bmi <= 0)	//정상 BMI 조건 : 양수
		errorHandling("Input error\n");

	if (bmi < 18.5)
		sprintf(buf, message, bmi, "저체중");
	else if (bmi < 20.5)
		sprintf(buf, message, bmi, "정상체중");
	else if (bmi < 30.0)
		sprintf(buf, message, bmi, "과체중");
	else if (bmi < 40.0)
		sprintf(buf, message, bmi, "비만");
	else
		sprintf(buf, message, bmi, "고도비만");

	printf("%s\n", buf);
}

void errorHandling(char *buf) {
	fputs(buf, stdout);
	exit(-1);
}