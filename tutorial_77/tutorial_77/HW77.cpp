#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "C:/data/hw77_parking_info.txt"
#define BUF_SIZE 100
#define TIME_SIZE 101

FILE *fileOpen(char *fileName, char *mode);
int fileToArray(FILE *fp, int *price, int(*car)[2]);
void initTime(int *time);
void setTime(int *time, int(*car)[2]);
int calcPrice(int *time, int* price);
void display(int *price, int(*car)[2], int pay);
void errorHandling(char* message);

int main()
{
	FILE *fp;
	int readCnt;
	int testCnt;
	int buffer[BUF_SIZE] = { NULL, };
	int i, j;
	int price[3];
	int car[3][2];
	int time[TIME_SIZE] = { 0, };
	int pay;

	fp = fileOpen(FILE_PATH, "rt");
	fscanf(fp, " %d", &testCnt);	//반복 횟수 read

	for (i = 0; i<testCnt; i++) {
		readCnt = fileToArray(fp, price, car);
		if (!readCnt) { break; }
		initTime(time);
		pay = 0;
		setTime(time, car);
		pay = calcPrice(time, price);
		display(price, car, pay);
	}


	fclose(fp);

	return 0;
}

FILE *fileOpen(char *fileName, char *mode) {
	FILE *fp;
	if ((fp = fopen(fileName, mode)) == NULL) {
		errorHandling("file open error\n");
	}

	return fp;
}

int fileToArray(FILE *fp, int *price, int(*car)[2]) {
	int dataCnt = 0;
	int i, j;
	while (1) {
		for (i = 0; i < 3; i++) {
			fscanf(fp, "%d", price + i);
			dataCnt++;
		}
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 2; j++) {
				fscanf(fp, "%d", &car[i][j]);
				dataCnt++;
			}
		}

		return dataCnt;
	}
}


void initTime(int *time) {
	int i;
	
	for (i = 0; i < TIME_SIZE; i++) {
		time[i] = 0;
	}
}

void setTime(int *time, int(*car)[2]) {
	int i;
	
	for (i = 1; i <= 100; i++) {
		if (car[0][0] <= i && i <= car[0][1] -1 ) { time[i]++; }
		if (car[1][0] <= i && i <= car[1][1] -1 ) { time[i]++; }
		if (car[2][0] <= i && i <= car[2][1] -1 ) { time[i]++; }
	}
}


int calcPrice(int *time, int* price) {
	int i;
	int pay = 0;

	for (i = 1; i <= 100; i++) {
		if (time[i] == 0) { ; }
		if (time[i] == 1) { pay += price[0]; }
		else if (time[i] == 2){ pay += price[1] * 2; }
		else if (time[i] == 3) { pay += price[2] * 3; }
		else { ; }
	}

	return pay;
}

void display(int *price, int(*car)[2], int pay) {
	printf("A 요금 : %d / B 요금 : %d / C 요금 : %d\n", price[0], price[1], price[2]);
	printf("총 주차 요금 : %d 원\n", pay);
}

void errorHandling(char* message) {
	fputs(message, stdout);
	exit(-1);
}
