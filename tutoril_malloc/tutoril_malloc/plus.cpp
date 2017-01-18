#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int *** myAlloc(int layer, int row, int col);
void dataInput(int ***ip, int layer, int row, int col);
void dataOutput(int ***ip, int layer, int row, int col);
void myDelete(int ***ip, int layer, int row, int col);
int random(int key);
int userChoice();
int inputNumber(char *message);

int main()
{
	int ***ip;	//동적 Memory 할당받은 3차원 배열의 시작 주소
	int layer, row, col;	//for 3 dimension matrix

	

	// default : layer, row, col (1~10)의 난수로 초기화
	srand((unsigned int)time(NULL));	//난수 시드 값 생성
	layer = random(10) + 1;
	row = random(10) + 1;
	col = random(10) + 1;

	// 유저에게 입력 여부 확인(y : 사용자 임의 입력, n : default 난수값 사용)
	if (userChoice()) {
		layer = inputNumber("면 입력(1~10) : ");
		row = inputNumber("행 입력(1~10) : ");
		col = inputNumber("열 입력(1~10) : ");
	}
	printf("면 : %d, 행 : %d, 열 : %d\n", layer, row, col);

	// 3차원 배열의 동적 Memory 할당
	ip = myAlloc(layer, row, col);

	// 3차원 배열에 데이터 저장
	dataInput(ip, layer, row, col);

	// 3차원 배열에 저장된 데이터 출력
	dataOutput(ip, layer, row, col);

	// 할당받은 메모리 free
	myDelete(ip, layer, row, col);

	return 0;
}


/*
기능 >		0 ~ key-1 까지의 임의의 난수 생성
parm key >	난수 생성 범위
return >		성공적으로 생성된 난수 값
*/
int random(int key) {
	return rand() % key;
}


/*
기능 >		3차원 배열의 동적 메모리 할당
parm layer >	3차원 배열의 면의 갯수
parm row >	3차원 배열의 행의 갯수
parm col >	3차원 배열의 열의 갯수
return >		성공 : 성공적으로 할당받은 3차원 배열의 시작 주소
			실패 : Null pointer
*/
int *** myAlloc(int layer, int row, int col) {
	int ***ip;
	int i, j;

	ip = (int ***)malloc(sizeof(int **) * layer);
	assert(ip != NULL);

	for (i = 0; i < layer; i++) {
		ip[i] = (int **)malloc(sizeof(int *) * row);
		assert(ip != NULL);

		for (j = 0; j < row; j++) {
			ip[i][j] = (int*)malloc(sizeof(int) * col);
			assert(ip != NULL);
		}
	}

	return ip;
}


/*
기능 >		동적 할당 받은 3차원 배열 난수 초기화
parm ip	>	초기화할 메모리의 시작 주소
parm layer >	3차원 배열의 면의 size
parm row >	3차원 배열의 행의 size
parm col >	3차원 배열의 열의 size
return >		None
*/
void dataInput(int ***ip, int layer, int row, int col) {
	int i, j, k;	//3차원 배열의 인덱스

	for (i = 0; i < layer; i++) {
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				ip[i][j][k] = random(100) + 1;
			}
		}
	}
}


/*
기능 >		동적 할당 받은 3차원 배열의 요소 출력
parm ip	>	출력할 메모리의 시작 주소
parm layer >	3차원 배열의 면의 size
parm row >	3차원 배열의 행의 size
parm col >	3차원 배열의 열의 size
return >		None
*/
void dataOutput(int ***ip, int layer, int row, int col) {
	int i, j, k;	//3차원 배열의 인덱스

	for (i = 0; i < layer; i++) {
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				printf("matrix[%d][%d][%d] : ", i, j, k);
				printf("%3d\n", ip[i][j][k]);
			}
			puts("---------------------");
		}
		puts("");
	}

}


/*
기능 >		동적 할당 받은 3차원 배열 free
parm ip	>	free할 메모리의 시작 주소
parm layer >	3차원 배열의 면의 size
parm row >	3차원 배열의 행의 size
parm col >	3차원 배열의 열의 size
return >		None
*/
void myDelete(int ***ip, int layer, int row, int col) {
	int i, j;

	for (i = 0; i < layer; i++) {
		for (j = 0; j < row; j++) {
			free(ip[i][j]);
		}
	}

	for (i = 0; i < layer; i++) {
		free(ip[i]);
	}
}


/*
기능 >		사용자에게 3차원 배열의 면, 행, 열의 입력 여부 확인
return >		성공 : 입력 여부
			return 1 : 'y', 'Y' (사용자 입력)
			return 0 : 'N' (default(1~10) 난수 값으로 초기화)
*/
int userChoice() {
	char isInput;
	
	while (1) {
		printf("3차원 배열 동적 메모리 할당 시 \"면, 행, 열\"을 지정하여 사용하시겠습니까?( y / n )\n");
		printf("(y 선택 시 입력하신 \"면, 행, 열\"의 수로 배열이 초기화 됩니다.)\n");
		printf("(n 선택 시 default로 \"면, 행, 열\"의 수는 1~10 사이의 임의의 난수로 초기화 됩니다.)\n");
		printf("input : ");
		scanf("%c", &isInput);
		puts("-------------------------------------------------------------------------------------------");

		// flush
		if (getchar() != '\n') {
			while (getchar() != '\n') { ; }
		}

		if (isInput == 'y' || isInput == 'Y') { return 1; }
		else if (isInput == 'n' || isInput == 'N') { return 0; }
	}
}



/*
기능 >		1 ~ 10 사이의 정수 입력
parm message >	출력 메시지
return >		사용자 입력 정수
*/
int inputNumber(char* message) {
	int num;

	while (1) {
		printf("%s", message);
		scanf("%d", &num);

		// flush
		if (getchar() != '\n') {
			while (getchar() != '\n') { ; }
		}

		if (1 <= num && num <= 10) { return num; }
	}
}