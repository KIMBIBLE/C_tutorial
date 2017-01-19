#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "C:/data/hw78_line.txt"
#define BUF_SIZE 1000

FILE *fileOpen(char *fileName, char *mode);
int fileToArray(FILE *fp, int *dataArray);
void errorHandling(char* message);
void swap(int *num1, int *num2);
void insert(int num, int *line, int nowPos);
void display(int *line, int num, int classCnt);

int main()
{
	FILE *fp;
	int readCnt;
	int testCnt;
	int buffer[BUF_SIZE] = { NULL, };
	int i, j, k;
	int totalStudent;
	int line[BUF_SIZE] = { 0, };

	fp = fileOpen(FILE_PATH, "rt");
	fscanf(fp, " %2d", &testCnt);

	for (i = 0; i<testCnt; i++) {
		totalStudent = fileToArray(fp, buffer);
		for (j = 0; j < totalStudent; j++) {
			insert(buffer[j], line, j);
		}
		display(line, totalStudent, i + 1);
	}

	fclose(fp);

	return 0;
}



void insert(int num, int *line, int nowPos) {
	int insertPos;
	int i;

	insertPos = nowPos - num;

	if (num == 0) { ; }
	else {
		for (i = nowPos; i >= insertPos; i--) {
			swap(&line[i + 1], &line[i]);
		}
	}
	line[insertPos] = nowPos + 1;
}


void display(int *line, int num, int classCnt) {
	int i;

	printf("%d반 학생의 순서 출력 : ", classCnt);
	for (i = 0; i < num; i++) {
		printf("%2d", line[i]);
	}
	puts("");
}

FILE *fileOpen(char *fileName, char *mode) {
	FILE *fp;
	if ((fp = fopen(fileName, mode)) == NULL) {
		errorHandling("file open error\n");
	}

	return fp;
}

int fileToArray(FILE *fp, int *dataArray) {
	int totalStudent;
	int i;

	fscanf(fp, "%d", &totalStudent);
	for (i = 0; i < totalStudent; i++) {
		fscanf(fp, "%d", dataArray + i);
	}
	
	return totalStudent;
}

void errorHandling(char* message) {
	fputs(message, stdout);
	exit(-1);
}

void swap(int *num1, int *num2) {
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}