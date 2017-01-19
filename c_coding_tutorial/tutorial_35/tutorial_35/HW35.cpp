#include <stdio.h>

int inputInt(char* message);
int calcPay(int code, int use);
void display(int code, int use, int pay);

int main()
{
	int code;
	int use;
	int pay;
	
	//����� �ڵ� �Է�(1~3)
	// 1 : ������ (ton�� 50��)
	// 2 : ����� (ton�� 45��)
	// 3 : ������ (ton�� 30��)
	while (1) {
		code = inputInt("* ����� �ڵ带 �Է��Ͻÿ�(1:������/2:�����/3:������) : ");
		if (1 <= code && code <= 3) { break; }
	}
	
	// ton���� ��뷮 �Է�(0�̻�)
	while (1) {
		use = inputInt("* ��뷮�� �Է��Ͻÿ�(ton����) : ");
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
	case 1: printf("# ����� �ڵ� : 1(������)\n"); break;
	case 2: printf("# ����� �ڵ� : 2(�����)\n"); break;
	case 3: printf("# ����� �ڵ� : 3(������)\n"); break;
	}
	printf("# ��뷮 : %d ton\n", use);
	printf("# �Ѽ������ : %d��\n", pay);
}