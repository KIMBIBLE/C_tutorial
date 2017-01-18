#include <stdio.h>
#include <malloc.h>	// #include <stdio.h>
#include <assert.h>

int * mallocIntArray1D(int);
void dataInput(int *, int);
void dataOutput(int *, int);
void freeArray1D(int *);

int main()
{
	int *ip;
	int col = 0;
	printf("Input Column Size : ");
	scanf("%d", &col);

	ip = mallocIntArray1D(col);
	dataInput(ip, col);
	dataOutput(ip, col);

	freeArray1D(ip);

	return 0;
}

int *mallocIntArray1D(int col) {
	int *ip;

	ip = (int *)malloc(sizeof(int) * col);
	assert(ip != NULL);

	return ip;
}

void dataInput(int *ip, int col) {
	for (int i = 0; i < col; i++) {
		printf("input Data array[%d] : ", i);
		scanf("%d", ip + i);
	}
}

void dataOutput(int *ip, int col) {
	for (int i = 0; i < col; i++) {
		printf("%d ", ip[i]);
	}
}

void freeArray1D(int *ip) {
	free(ip);
}