#include <stdio.h>

int menu();
int inputInt(char *message);
void deposit(int* pAmount);
int withdraw(int* pAmount);

int main()
{
	int choice;
	int amount = 0;	//���� �� �ܾ� 0��

	while (1) {
		printf("* ���� �ܾ��� %d�� �Դϴ�.\n", amount);
		choice = menu();
		switch (choice) {
		case 'i': {
			deposit(&amount);
		}; break;
		case 'o': {
			if (!withdraw(&amount)) {
				printf("* �ܾ��� �����մϴ�.\n");
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
		printf("\n\n# �޴��� �����Ͻÿ�(i-�Ա�, o-���, q-����) : ");
		scanf("%c", &choice);
		if (getchar() != '\n') { while (getchar() != '\n') { ; } }
		if (choice == 'i' || choice == 'o' || choice == 'q') { break; }
		printf("* �߸� �Է��ϼ̽��ϴ�.\n");
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

	depositAmount = inputInt("# �Աݾ��� �Է��ϼ��� : ");
	while (depositAmount <= 0) {
		depositAmount = inputInt("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
	}
	*pAmount += depositAmount;
}

int withdraw(int* pAmount) {
	int withdrawAmount;
	withdrawAmount = inputInt("# ��ݾ��� �Է��ϼ��� : ");
	while (withdrawAmount <= 0) {
		withdrawAmount = inputInt("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
	}
	if (withdrawAmount > *pAmount)
		return 0;
	else{
		*pAmount -= withdrawAmount;
		return 1;
	}
		
}
