#include "generic_coding.h"

void display(void *p, int count, size_t size, void(*dataPrint)(void *)) {
	int i;
	for (i = 0; i < count; i++) {
		printf("%d. ", i + 1);
		dataPrint((char *)p + i*size);
	}
}

void integerPrint(void *p) {
	printf("%d\n", *(int *)p);
}

void doublePrint(void *p) {
	printf("%lf\n", *(double *)p);
}

void stringPrint(void *p) {
	printf("%s\n", (char *)p);
}