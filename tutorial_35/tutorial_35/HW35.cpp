#include <stdio.h>

int inputInt(char* message);
int calcPay(int code, int use);
void display(int code, int use, int pay);

int main()
{
	int code;
	int use;
	int pay;
	
	//사용자 코드 입력(1~3)
	// 1 : 가정용 (ton당 50원)
	// 2 : 상업용 (ton당 45원)
	// 3 : 공업용 (ton당 30원)
	while (1) {
		code = inputInt("* 사용자 코드를 입력하시오(1:가정용/2:상업용/3:공업용) : ");
		if (1 <= code && code <= 3) { break; }
	}
	
	// ton단위 사용량 입력(0이상)
	while (1) {
		use = inputInt("* 사용량을 입력하시오(ton단위) : ");
		if (use >= 0) { break; }
	}

	pay = calcPay(code, use);
	display(code, use, pay);

	return 0;
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

int calcPay(int code, int use) {
	int pay;

	int homePrice = 50;
	int industrialPrice = 45;
	int commercialPrice = 30;

	switch (code) {
	case 1: pay = homePrice * use; break;
	case 2: pay = industrialPrice * use; break;
	case 3: pay = commercialPrice * use; break;
	}

	pay *= 1.05;

	return pay;
}

void display(int code, int use, int pay) {
	puts("\n\n");
	switch (code) {
	case 1: printf("# 사용자 코드 : 1(가정용)\n"); break;
	case 2: printf("# 사용자 코드 : 2(상업용)\n"); break;
	case 3: printf("# 사용자 코드 : 3(공업용)\n"); break;
	}
	printf("# 사용량 : %d ton\n", use);
	printf("# 총수도요금 : %d원\n", pay);
}