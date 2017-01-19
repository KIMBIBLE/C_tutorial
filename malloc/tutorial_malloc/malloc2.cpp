#include <stdio.h>
#include <malloc.h>
#include <assert.h>

int **mallocIntArray2D(int row, int col);
void dataInput(int **ip, int row, int col);
void dataOutput(int **ip, int row, int col);
void freeArray2D(int **ip, int row);

int main()
{
	int **ip;
	int row, col;

	printf("Input row size : ");
	scanf("%d", &row);

	printf("Input col size : ");
	scanf("%d", &col);

	ip = mallocIntArray2D(row, col);
	
	dataInput(ip, row, col);
	dataOutput(ip, row, col);

	freeArray2D(ip, row);

	return 0;
}


int **mallocIntArray2D(int row, int col) {
	int **ip;
	int i;

	ip = (int **)malloc(sizeof(int *) * row);
	assert(ip != NULL);

	for (i = 0; i < row; i++) {
		ip[i] = (int *)malloc(sizeof(int) * col);
		assert(ip[i] != NULL);
	}

	return ip;
}

void dataInput(int **ip, int row, int col) {
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("data input (array[%d][%d]) : ", i, j);
			scanf("%d", *(ip + i) + j);
		}
	}
}

void dataOutput(int **ip, int row, int col) {
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("ary[%d][%d] : %d\n", i, j, ip[i][j]);
		}
	}
}

void freeArray2D(int **ip, int row) {
	int i;

	for (i = 0; i < row; i++) {
		free(ip[i]);
	}

	free(ip);
}