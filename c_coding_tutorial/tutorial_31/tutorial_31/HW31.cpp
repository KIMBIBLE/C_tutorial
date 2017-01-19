#include <stdio.h>

int getBit(int num, int i);	//menu select : 1
int setBit(int num, int i);	//menu select : 2

int clearBit(int num, int i);	//menu select : 3
int clearBitsMSBthroughI(int num, int i);	//menu select : 4
int clearBitsIthrough0(int num, int i);	//menu select : 5

int updateBit(int num, int i, int value);	//menu select : 6

void printBit(int num);	//print bit if bit masking action has occured
int inputInteger(char* message);
int inputBit(char* message);
int inputBitValue(char* message);

void menu(int num);


int main()
{
	int num, i;

	num = inputInteger("* 10진수 정수를 입력하시오 : ");
	printBit(num);
	
	menu(num);

	return 0;
}

void menu(int seed) {
	int opt = 1;
	int i;
	int num = seed;
	int value;

	//초기 1번은 무조건 실행
	while (opt) {
		puts("\n===================MENU=======================");
		printf("1. getBit( 특정 bit 값 얻어내기)\n");
		printf("2. setBit(특정 bit 값을 1로 만들기)\n");
		printf("3. clearBit( 2의 i승 비트값을 0으로 지우기)\n");
		printf("4. clearBitsMSBthroughI(MSB ~ 2의 i승 비트까지 모두 0으로 지우기)\n");
		printf("5. clearBitsIthrough0(2의 i승 ~ 0승 비트까지 모두 0으로 지우기)\n");
		printf("6. updateBit(특정 bit를 원하는 값으로 변경하기)\n");
		printf("0. 종료\n");
		puts("=================================================\n");

		while (1) {
			opt = inputInteger("메뉴를 입력하세요(0~6) : ");
			if (0 <= opt && opt <= 6)
				break;
		}

		switch (opt){		
		case 0:; break;
		case 1: {
			i = inputBit("- 비트값을 추출할 비트의 자리수는?(0~31) : ");
			printBit(num);

			if (getBit(num, i))
				printf("2의 %d승 번째 비트는 1입니다.\n", i);
			else
				printf("2의 %d승 번째 비트는 0입니다.\n", i);
		}; break;
		case 2: {
			i = inputBit("- 비트 값을 1로 만들 비트의 자리수는?(0~31) : ");
			printf("%11s", "Before : ");
			printBit(num);	//before bit masking
			
			num = setBit(num, i);
			
			printf("%11s", "After : ");
			printBit(num);	//after bit masking
		}; break;
		case 3: {
			i = inputBit("- 비트 값을 0으로 만들 비트의 자리수는?(0~31) : ");
			printf("%11s", "Before : ");
			printBit(num);	//before bit masking

			num = clearBit(num, i);

			printf("%11s", "After : ");
			printBit(num);	//after bit masking
		}; break;
		case 4: {
			i = inputBit("-(MSB ~ i번 째) 비트 값을 0으로 만들 비트의 자리수는?(0~31) : ");
			printf("%11s", "Before : ");
			printBit(num);	//before bit masking

			num = clearBitsMSBthroughI(num, i);

			printf("%11s", "After : ");
			printBit(num);	//after bit masking
		}; break;
		case 5: {
			i = inputBit("-(i ~ 0번 째) 비트 값을 0으로 만들 비트의 자리수는?(0~31) : ");
			printf("%11s", "Before : ");
			printBit(num);	//before bit masking

			num = clearBitsIthrough0(num, i);

			printf("%11s", "After : ");
			printBit(num);	//after bit masking
		}; break;
		case 6: {
			i = inputBit("-세팅할 비트의 자리수는?(0~31) : ");
			value = inputBitValue("변경할 비트의 값은 ? (0 or 1) : ");
			
			printf("%11s", "Before : ");
			printBit(num);	//before bit masking

			num = updateBit(num, i, value);

			printf("%11s", "After : ");
			printBit(num);	//after bit masking
		}; break;
		default:;

		}
	}
}


/*	기능 : 특정 bit 값 얻어내는 함수
	pram num	>	비트 추출할 변수
	parm i	>	변수에서 추출할 bit의 자리수
	return	>	특정 비트가 1이라면 1, 0이라면 0 리턴
*/
int getBit(int num, int i) {
	unsigned int key = 1;	//2의 0승 자리 1 세팅

	key <<= i;	//2의 i승자리의 비트만 1로 세팅
	if ((key & num) == key)
		return 1;
	else
		return 0;
}


/*	기능 : num변수의 2의 i승 비트 값을 1로 만드는 기능
pram num	>	비트 세팅할 변수
parm i	>	변수에서 1로 세팅할 bit의 자리수
return	>	비트 세팅 완료 된 변수 값 리턴
*/
int setBit(int num, int i) {
	unsigned int key = 0x1;
	key <<= i;

	return num | key;
}


/*	기능 : num변수의 2의 i승 비트 값을 0으로 만드는 기능
pram num	>	비트 세팅할 변수
parm i	>	변수에서 0으로 세팅할 bit의 자리수
return	>	비트 세팅 완료 된 변수 값 리턴
*/
int clearBit(int num, int i) {
	unsigned int key = 1;
	key <<= i;
	key = ~key;

	return num & key;
}


/*	기능 : num변수의 MSB 비트부터 2의 i승 까지의 비트 값을 0으로 만드는 기능
pram num	>	비트 세팅할 변수
parm i	>	MSB ~ i 까지의 범위
return	>	비트 세팅 완료 된 변수 값 리턴
*/
int clearBitsMSBthroughI(int num, int i) {
	unsigned int key = 0xFFFFFFFF;
	while (32 - i++) { key >>= 1; }
	return num & key;
}

/*	기능 : num변수의 2의 i승 비트 부터 0 비트까지의 비트 값을 0으로 만드는 기능
pram num	>	비트 세팅할 변수
parm i	>	i ~ 0 까지의 범위
return	>	비트 세팅 완료 된 변수 값 리턴
*/
int clearBitsIthrough0(int num, int i) {
	unsigned int key = 0xFFFFFFFF;
	while (1 + i--) { key <<= 1; }
	return num & key;
}

/*	기능 : 특정 bit를 원하는 값으로 변경
pram num	>	비트 세팅할 변수
parm i	>	변경할 비트의 인덱스
parm value>	변경할 값
return	>	비트 세팅 완료 된 변수 값 리턴
*/
int updateBit(int num, int i, int value) {
	unsigned int key = 0x1;

	//value = 1 or 0
	if (value) {
		return setBit(num, i);
	}
	else
		return clearBit(num, i);
}

void printBit(int num) {
	unsigned int key = 0x80000000;
	int i;

	for (i = 0; i < 32; i++) {
		if ((num & key) == key)
			printf("1");
		else
			printf("0");
		key >>= 1;
	}
	printf("(2)\n");
}

int inputInteger(char* message) {
	int num;

	while (1) {
		printf("%s", message);
		scanf("%d", &num);
		if (getchar() == '\n')	break;
		while (getchar() != '\n') { ; }
	}

	return num;
}

int inputBit(char* message) {
	int i;

	while (1) {
		i = inputInteger(message);
		if (0 <= i && i < 32)
			break;
	}

	return i;
}

int inputBitValue(char* message) {
	int i;

	while (1) {
		i = inputInteger(message);
		if (i == 1 || i == 0)
			break;
	}

	return i;
}