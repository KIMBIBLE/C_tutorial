#include <stdio.h>

int menu();
int inputInt(char *message);
void deposit(int* pAmount);
int withdraw(int* pAmount);

int main()
{
	int choice;
	int amount = 0;	//시작 시 잔액 0원

	while (1) {
		printf("* 현재 잔액은 %d원 입니다.\n", amount);
		choice = menu();
		switch (choice) {
		case 'i': {
			deposit(&amount);
		}; break;
		case 'o': {
			if (!withdraw(&amount)) {
				printf("* 잔액이 부족합니다.\n");
			}
		}; break;
		case 'q':; break;
		default:;
		}
		if (choice == 'q') { break; }
	}

	return 0;
}


int menu() {
	char choice;
	while (1) {
		printf("\n\n# 메뉴를 선택하시오(i-입금, o-출금, q-종료) : ");
		scanf("%c", &choice);
		if (getchar() != '\n') { while (getchar() != '\n') { ; } }
		if (choice == 'i' || choice == 'o' || choice == 'q') { break; }
		printf("* 잘못 입력하셨습니다.\n");
	}
	return choice;
}


int inputInt(char *message) {
	int money;

	while (1) {
		printf("%s", message);
		scanf("%d", &money);
		if (getchar() == '\n') { break; }
		while (getchar() != '\n');
	}
	return money;
}

void deposit(int* pAmount) {
	int depositAmount;

	depositAmount = inputInt("# 입금액을 입력하세요 : ");
	while (depositAmount <= 0) {
		depositAmount = inputInt("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
	}
	*pAmount += depositAmount;
}

int withdraw(int* pAmount) {
	int withdrawAmount;
	withdrawAmount = inputInt("# 출금액을 입력하세요 : ");
	while (withdrawAmount <= 0) {
		withdrawAmount = inputInt("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
	}
	if (withdrawAmount > *pAmount)
		return 0;
	else{
		*pAmount -= withdrawAmount;
		return 1;
	}
		
}
