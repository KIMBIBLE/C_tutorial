#include <stdio.h>

void printAge(int age);
void printHeight(double height);

int main()
{
	char name[20] = "ȫ�浿";
	int age = 500;
	double height = 170.8;

	printf("���� :  %s\n", name);
	printAge(age);
	printHeight(height);
}

void printAge(int age) {
	printf("���� : %d\n", age);
}

void printHeight(double height) {
	printf("���� : %lf\n", height);
}