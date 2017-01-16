#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

void initRandomNum(int *keyAry);
void disPlayRandomNum(int *keyAry);
int checkBallCount(int *keyAry, int *ballCount);
int random(int numRange);

int main()
{
	int keyAry[4];
	int ballCount[2];	//[0]: Strike, [1] : Ball, 둘다 0일 때는 No!(Out)
	int i;
	int playCnt = 11;
	
	srand((unsigned int)time(NULL));	//난수 seed 생성

	initRandomNum(keyAry);
	disPlayRandomNum(keyAry);

	// 11차 까지 플레이
	for (i = 1; i <= playCnt; i++) {
		printf("# %d차 : ", i);
		if (checkBallCount(keyAry, ballCount)) {
			if (ballCount[0] == 4) {
				printf("\tOK~~!!\n");
				printf("--------------------\n");
				printf("You Win!!!! 게임 종료!!!\n\n");
				return 1;
			}

			printf("\t%dS %dB\n", ballCount[0], ballCount[1]);
		}
		else {
			printf("\tNo!\n");
		}

		if (i == 11) {
			printf("--------------------\n");
			printf("You Lose~~ 게임 종료!!!\n\n");
		}
	}

	return 0;
}


/*	void initRandomNum(int *keyAry) 
기능 > 0~9 범위의 중복되지 않는 난수 4개를 발생시켜 keyAry 배열에 저장
parm1 > 발생된 난수를 저장할 int형 배열
return > None
*/
void initRandomNum(int *keyAry) {
	int num;	//난수
	int cnt = 0;	//난수 발생 성공 횟수 카운트 변수(4개의 난수 발생)
	int i;
	int temp[10] = { -1};	
	
	for (i = 0; i < 10; i++) {
		temp[i] = -1;
	}
	/* 배열의 각 요소가 0~9 의 수와 중복되지 않도록 임시 배열 생성
	 배열의 각 요소와 random() Ret 값을 매칭하여 사용.
	 발생된 난수에 해당되는 temp 배열의 인덱스의 위치에 난수 값 저장 */
	while (1) {
		// 재반복을 위한 초기화
		cnt = 0;
		for (i = 0; i < 10; i++) {
			temp[i] = -1;
		}

		// 난수 4개 생성
		for (i = 0; i < 4; i++) {
			num = random(10);
			temp[num] = num;
		}

		// 임시 배열에 저장한 난수 값 중복 유무 검사
		for (i = 0; i < 10; i++) {
			/* 배열의 모든 요소를 접근해 temp 배열에 초기 세팅한 값인 
			'-1(난수와 중복되지 않는 값)'과 다른 값을 카운트
			cnt == 난수 발생 후 중복을 제외한 숫자 갯수 */
			if (temp[i] != -1) { cnt++; }	
			
		}
		/* cnt를 통해 반복 횟수 검출( cnt == 4)인 경우
		중복 난수가 없으므로 반복 탈출	*/
		if (cnt == 4) { break; }
		
	}

	// 임시 배열에 저장된 서로 다른 값을 추출해 keyAry에 저장
	for (i = 0; i < 10; i++) {
		if (temp[i] != -1) {
			// index : 3 ~ 0 순으로 저장(4회)
			keyAry[--cnt] = temp[i];
		}
		if (cnt == 0) { break; }
	}

}


/*	void disPlayRandomNum(int *keyAry)
기능 > 컴퓨터가 발생시킨 4자리 난수 출력
parm1 > 출력할 난수가 저장된 keyAry 배열
return > None
*/
void disPlayRandomNum(int *keyAry) {
	int i;

	printf("컴퓨터가 발생한 난수\n");
	printf("--------------------\n   ");
	for (i = 0; i < 4; i++) {
		printf("%3d", keyAry[i]);
	}
	printf("\n--------------------\n");
}



int checkBallCount(int *keyAry, int *ballCount) {
	int inputCnt = 4;
	int i, j;
	int userInput[4];

	for (i = 0; i < 4; i++) {
		userInput[i] = -1;
	}

	// 볼카운트 초기화
	ballCount[0] = 0;	//'0' Strike
	ballCount[1] = 0;	//'0' Ball

	//유저 입력 (4회)
	for (i = 0; i < inputCnt; i++) {
		printf("  ");
		userInput[i] = getche() - '0';
	}

	//Strike 판별
	for (i = 0; i < inputCnt; i++) {
		if (userInput[i] == keyAry[i]) {
			ballCount[0]++;
			userInput[i] = -1;	// 이후 ball 검사에서 중복 Block
		}
	}

	if (ballCount[0] + ballCount[1] == 4) { return 1; }

	//Ball 판별
	for (i = 0; i < inputCnt; i++) {
		for (j = 0; j < inputCnt; j++) {
			if (keyAry[i] == userInput[j]) {
				ballCount[1]++;
			}
		}
	}

	if (ballCount[0] + ballCount[1] == 4) { return 1; }

	//ballCount 결과 판별 (strike나 ball이 있으면 1, 없으면 0 리턴)
	if (ballCount[0] == 0 && ballCount[1] == 0) {
		return 0;
	}

	return 1;
}

int random(int numRange) {
	return rand() % numRange;
}