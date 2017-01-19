#include <stdio.h>

void printAge(int age);
void printHeight(double height);

int main()
{
	char name[20] = "홍길동";
	int age = 500;
	double height = 170.8;

	printf("성명 :  %s\n", name);
	printAge(age);
	printHeight(height);
}

void printAge(int age) {
	printf("나이 : %d\n", age);
}

void printHeight(double height) {
	printf("신장 : %lf\n", height);
}