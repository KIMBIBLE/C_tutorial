#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "c:\\data\\hw49_number_list.txt"
#define BUF_SIZE 16

FILE *fileOpen(char *fileName, char *mode);
int fileToArray(FILE *fp, int *dataArray);
void errorHandling(char* message);

int main()
{
	FILE *fp;
	int readCnt;
	int testCnt;
	int doubleCnt = 0;
	int buffer[BUF_SIZE] = { NULL, };
	int i, j, k;

	fp = fileOpen(FILE_PATH, "rt");
	fscanf(fp, "%d", &testCnt);

	for(i=0;i<testCnt;i++){
		readCnt = fileToArray(fp, buffer);
		if (!readCnt) { break; }
		printf("# 수열 : ");
		for (j = 0; j < readCnt; j++) {
			printf(" %d", buffer[j]);
		}
		puts("");

		for (j = 0; j < readCnt; j++) {
			for (k = 0; k < readCnt; k++) {
				if (buffer[j] == 2 * buffer[k]) { doubleCnt++; }
			}
		}
		printf("2 배 값이 존재하는 원소의 개수는 %d 개 입니다.\n\n", doubleCnt);
		doubleCnt = 0;
	}

	return 0;
}

FILE *fileOpen(char *fileName, char *mode) {
	FILE *fp;
	if ((fp = fopen(fileName, mode)) == NULL) {
		errorHandling("file open error");
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