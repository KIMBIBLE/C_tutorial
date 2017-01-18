#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "C:/data/hw74_jolly.txt"
#define BUF_SIZE 100
#define TIME_SIZE 101

FILE *fileOpen(char *fileName, char *mode);
int fileToArray(FILE *fp, int *buffer);
void errorHandling(char *message);
int checkJolly(int *buffer, int len);
void displayOutput(char *message, int *buffer, int len);

int main()
{
	FILE *fp;
	int testCnt;	//테스트 반복 횟수(.txt file Header)	
	int lineCnt;	//수열의 데이터 수
	int buffer[BUF_SIZE] = { NULL, };
	int i, j;
	
	fp = fileOpen(FILE_PATH, "rt");

	// 테스트 수행 횟수 read
	fscanf(fp, "%d", &testCnt);

	// 테스트 횟수만큼 테스트 data read
	for (i = 0; i < testCnt; i++) {
		lineCnt = fileToArray(fp, buffer);

		if (checkJolly(buffer, lineCnt)) {
			displayOutput("Jolly jumper", buffer, lineCnt);
		}
		else {
			displayOutput("Not Jolly jumper", buffer, lineCnt);
		}
	}

	return 0;
}

void displayOutput(char *message, int *buffer, int len) {
	int i;
	
	printf("검사한 수열 : ");
	for (i = 0; i < len; i++) {
		printf("%d ", buffer[i]);
	}
	printf("(%s)\n", message);
}

FILE *fileOpen(char *fileName, char *mode) {
	FILE* fp;
	if ((fp = fopen(fileName, mode)) == NULL) {
		errorHandling("File open error\n");
		exit(1);
	}

	return fp;
}

int fileToArray(FILE *fp, int *buffer) {
	int lineCnt;	//수열의 데이터 수
	int i;	

	fscanf(fp, "%d", &lineCnt);
	for (i = 0; i < lineCnt; i++) {
		fscanf(fp, "%d", buffer + i);
	}

	return lineCnt;
}

int checkJolly(int* buffer, int len) {
	int *p;
	int i, j;
	int check;

	// int p[len-1] 동적 배열 할당
	p = (int*)malloc(sizeof(int)*(len - 1));

	// 연속한 수열의 차 계산
	for (i = 0; i < len - 1; i++) {
		p[i] = abs(buffer[i] - buffer[i+1]);
	}

	for (i = 1; i < len; i++) {
		check = 0;	//default 0 초기화
		for (j = 0; j < len - 1; j++) {
			if (i == p[j]) { 
				check = 1; 
				p[j] = 0;
			}
		}
		if (check == 0) { return 0; }	//Not jolly
	}

	free(p);
	
	return 1;	//jolly
}

void errorHandling(char* message) {
	fputs(message, stdout);
	exit(-1);
}

