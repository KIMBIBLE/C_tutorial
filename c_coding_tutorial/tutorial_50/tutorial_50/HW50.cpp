#include <stdio.h>

#define BUFFER_SIZE 5

void inputData(double *buffer);
double getMaxValue(double *buffer);
double getMinValue(double *buffer);
void printMaxMin(double max, double min);
void swap(double *pNum1, double *pNum2);

int main()
{
	double buffer[BUFFER_SIZE];
	double maxValue;
	double minValue;

	inputData(buffer);
	maxValue = getMaxValue(buffer);
	minValue = getMinValue(buffer);

	printMaxMin(maxValue, minValue);

	return 0;
}

void inputData(double *buffer) {
	int i;
	for (i = 0; i < BUFFER_SIZE; i++) {
		while (1) {
			printf("%d 번 방 값 : ", i);
			scanf("%lf", &buffer[i]);
			if (getchar() == '\n') { break; }
			while (getchar() != '\n') { ; }
		}
	}
}

void swap(double *pNum1, double *pNum2) {
	double temp;

	temp = *pNum1;
	*pNum1 = *pNum2;
	*pNum2 = temp;
}

double getMaxValue(double *buffer) {
	double maxValue = buffer[0];
	int i;
	for (i = 1; i < BUFFER_SIZE; i++) {
		if (maxValue < buffer[i]) { swap(&maxValue, &buffer[i]); }
	}

	return maxValue;
}
double getMinValue(double *buffer) {
	double minValue = buffer[0];
	int i;
	for (i = 1; i < BUFFER_SIZE; i++) {
		if (buffer[i] < minValue) { swap(&minValue, &buffer[i]); }
	}

	return minValue;
}
void printMaxMin(double max, double min) {
	puts("");
	printf("가장 큰 값 : %.2lf\n", max);
	printf("가장 작은 값 : %.2lf\n", min);
}