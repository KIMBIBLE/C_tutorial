#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "C:/data/hw56_sortData.txt"
#define BUF_SIZE 16

FILE *fileOpen(char *fileName, char *mode);
int fileToArray(FILE *fp, int *dataArray);
void errorHandling(char* message);
void swap(int *pNum1, int *pNum2);
void sort(int *buffer);

int main()
{
	FILE *fp;
	int readCnt;
	int testCnt;
	int buffer[BUF_SIZE] = { NULL, };
	int i, j, k;

	fp = fileOpen(FILE_PATH, "rt");
	fscanf(fp, " %2d", &testCnt);

	for (i = 0; i<testCnt; i++) {
		readCnt = fileToArray(fp, buffer);
		if (!readCnt) { break; }
		printf("# 소트 전 데이터 : ");
		for (j = 0; j < readCnt; j++) {
			printf(" %2d", buffer[j]);
		}
		puts("");

		sort(buffer);
		printf("# 소트 후 데이터 : ");
		for (j = 0; j < readCnt; j++) {
			printf(" %2d", buffer[j]);
		}
		puts("\n");
	}

	return 0;
}

FILE *fileOpen(char *fileName, char *mode) {
	FILE *fp;
	if ((fp = fopen(fileName, mode)) == NULL) {
		errorHandling("file open error\n");
	}

	return fp;
}

int fileToArray(FILE *fp, int *dataArray) {
	int dataCnt = 0;

	while (1) {
		fscanf(fp, "%d", &dataArray[dataCnt]);
		if (dataArray[dataCnt] == 0) { break; }
		dataCnt++;
	}
	return dataCnt;
}

void errorHandling(char* message) {
	fputs(message, stdout);
	exit(-1);
}

void swap(int *pNum1, int *pNum2) {
	int temp;

	temp = *pNum1;
	*pNum1 = *pNum2;
	*pNum2 = temp;
}

void sort(int* buffer) {
	int i, j;
	int len = 0;

	while (1) {
		if (!buffer[len]) { break; }
		len++;
	}
	
	for (i = 0; i < len - 1; i++) {
		for (j = 1; j < len - i; j++) {
			if (buffer[j - 1] > buffer[j]) {
				swap(&buffer[j - 1], &buffer[j]);
			}
		}
	}
}