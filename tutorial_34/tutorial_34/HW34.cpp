#include <stdio.h>

int menu();
char openFan(char fan);
char offFan(char fan);
char reverseFan(char fan);
void displayFan(char fan);
int inputInt(char* message);

int main()
{
	char fan = 0;	//FAN 상태(초기 OFF)
	int choice;

	while (1) {
		choice = menu();
		//Action
		if (choice == 1) {	fan = openFan(fan);	}
		else if (choice == 2) { fan = offFan(fan); }
		else if (choice == 3) { fan = reverseFan(fan); }
		else if (choice == 4) {	break;	}	//exit : escape loop
		else { ; }
	}

	return 0;
}


int menu() {
	int choice;
	while (1) {
		choice = inputInt("\n1. 환풍구 열기 / 2. 환풍구 닫기 / 3. 환풍구 전체 전환 / 4. 종료 : ");
		if (1 <= choice && choice <= 4) { return choice; }
	}
}

char openFan(char fan){
	int fanNum;
	unsigned char key = 0x1;

	while (1) {
		printf("\n-----------------------------------------------------------------\n");
		printf("\n                     Fan 열기 작업 실행 화면\n");
		printf("\n-----------------------------------------------------------------\n");
		fanNum = inputInt("\nOPEN할 FAN 번호를 입력하시오(1-8) : ");
		if (1 <= fanNum && fanNum <= 8) { break; }
	}
	printf("\n-----------------------------------------------------------------\n");
	
	//FAN OPEN(Bit Masking)
	while (fanNum - 1) {
		key <<= 1;
		fanNum--;
	}
	fan |= key;

	displayFan(fan);
	printf("\n-----------------------------------------------------------------\n");

	return fan;
}

char offFan(char fan) {
	int fanNum;
	unsigned char key = 0x1;

	while (1) {
		printf("\n-----------------------------------------------------------------\n");
		printf("\n                     Fan 닫기 작업 실행 화면\n");
		printf("\n-----------------------------------------------------------------\n");
		fanNum = inputInt("\nCLOSE할 FAN 번호를 입력하시오(1-8) : ");
		if (1 <= fanNum && fanNum <= 8) { break; }
	}
	printf("\n-----------------------------------------------------------------\n");

	//FAN CLOSE(Bit Masking)
	//1로 만들 비트 세팅
	while (fanNum - 1) {
		key <<= 1;
		fanNum--;
	}
	//0으로 만들 위치의 비트를 제외하고 1로 세팅
	key = ~key;

	fan &= key;

	displayFan(fan);
	printf("\n-----------------------------------------------------------------\n");

	return fan;
}

char reverseFan(char fan) {
	int fanNum;
	
	printf("\n-----------------------------------------------------------------\n");
	printf("\n                 Fan 전체 전환 작업 실행 화면\n");
	printf("\n-----------------------------------------------------------------\n");
	//fan 전환
	fan = ~fan;
	printf("\n전체 FAN의 상태가 전환되었습니다.(ON, OFF 상태 뒤바뀜)\n");

	displayFan(fan);
	printf("\n-----------------------------------------------------------------\n");

	return fan;
}

void displayFan(char fan) {
	int fanNum = 8;	//8번 팬부터 순차 출력
	unsigned char key = 0x80;	//8번 팬 비트 1로 세팅

	puts("");
	while (fanNum) {	printf("%d번FAN  ", fanNum--);	}
	puts("\n");

	fanNum = 8;
	while (fanNum--) {
		if ((fan & key) == 0) { printf("OFF     "); }
		else {	printf("ON      "); }
		key >>= 1;
	}
	puts("");
}

int inputInt(char* message) {
	int num;

	while (1) {
		printf("%s", message);
		scanf("%d", &num);
		if (getchar() == '\n') { return num; }
		while (getchar() != '\n') { ; }
	}
}