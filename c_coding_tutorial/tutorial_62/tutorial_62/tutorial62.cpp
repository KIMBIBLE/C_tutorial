#include <stdio.h>

void getMatrixMultiple(int(*a)[4], int(*b)[4], int(*c)[4]);
void displayMatrix(int(*a)[4], int(*b)[4], int(*c)[4]);

int main()
{
	int matrixA[4][4] = { {0,1,2,3},{1,-2,1,2},{2,5,-3,2},{0,-3,1,4} };
	int matrixB[4][4] = { {1,-1,2,0},{1,-1,1,2},{-1,0,3,1},{2,-1,2,8} };
	int matrixC[4][4] = {0,};

	getMatrixMultiple(matrixA, matrixB, matrixC);
	displayMatrix(matrixA, matrixB, matrixC);

	return 0;
}


void getMatrixMultiple(int(*a)[4], int(*b)[4], int(*c)[4]) {
	int i, j, k;
	int sum = 0;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	
}

void displayMatrix(int(*a)[4], int(*b)[4], int(*c)[4]) {
	int i, j;

	printf("  [Matrix A]\t\t");
	printf("  [Matrix B]\t\t");
	printf("  [C = A * B]\n");

	for (i = 0; i < 4; i++) {
		//Matrix A i행 출력
		for (j = 0; j < 4; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\t\t");

		//Matrix B i행 출력
		for (j = 0; j < 4; j++) {
			printf("%3d", b[i][j]);
		}
		printf("\t\t");

		//Matrix C i행 출력
		for (j = 0; j < 4; j++) {
			printf("%3d", c[i][j]);
		}
		puts("");
	}
}