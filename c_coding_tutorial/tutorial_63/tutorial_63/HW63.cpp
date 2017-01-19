#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "C:/data/hw63_histogram.txt"
#define BUF_SIZE 16

FILE *fileOpen(char *fileName, char *mode);
int fileToArray(FILE *fp, int *dataArray);
void errorHandling(char* message);

int main()
{
	FILE *fp;
	int readCnt;
	int testCnt;
	int buffer[BUF_SIZE] = { NULL, };
	int i, j, k;
	int top = 0;

	fp = fileOpen(FILE_PATH, "rt");
	fscanf(fp, " %2d", &testCnt);

	for (i = 0; i<testCnt; i++) {
		readCnt = fileToArray(fp, buffer);
		if (!readCnt) { break; }
		
		// 출력 기준 값 top 구하기
		for (j = 0; j < readCnt; j++) {
			if (buffer[j] > top) {
				top = buffer[j];
			}
		}
		puts("");
		
		// histogram 출력
		while (top) {
			for (j = 0; j < readCnt; j++) {
				if (buffer[j] >= top) {
					printf("  *");
				}
				else {
					printf("   ");
				}
			}
			puts("");
			top--;
		}

		// data 출력
		for (j = 0; j < readCnt; j++) {
			if (buffer[j] > top) {
				top = buffer[j];
			}
			printf(" %2d", buffer[j]);
		}
		puts("");
		puts("-----------------------------------------");

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
