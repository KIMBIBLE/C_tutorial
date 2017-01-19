#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputNum();
int guessMessage(int num, int key, int* max, int* min);

int main()
{
	int num;	//1~100 사이의 정수
	int cnt = 1;
	int key;
	
	// 값 추측 상태 저장 변수
	int min = 0;
	int max = 100;

	srand((unsigned int)time(NULL));
	key = rand() % 100 + 1;
	
	//DELETE COMMENT FOR TEST
	//printf("key : %d\n", key);
	
	num = inputNum();
	while (!guessMessage(num, key, &max, &min)) {
		num = inputNum();
		cnt++;
	}
	printf("우와~ 맞았당~~~ 추카추카~~ %d 번째 만에 맞추셨습니다.\n", cnt);

	return 0;
}


int inputNum() {
	int num;

	printf("# 숫자를 입력하시오 : ");
	while (scanf("%d", &num) != 1) {
		while (getchar() != '\n')	;
		printf("# 숫자를 입력하시오 : ");
	}
		
	return num;
}

//	return  성공 : 1, 실패 : 0
int guessMessage(int num, int key, int* max, int* min) {

	if (num < key)	num < *min ? NULL : *min = num;
	else if(num > key) num > *max ? NULL : *max = num;
	else return 1;

	printf("%d 보다는 크고 %d 보다는 작습니다.\n", *min, *max);

	return 0;
}

