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

	num = inputInteger("* 10���� ������ �Է��Ͻÿ� : ");
	printBit(num);
	
	menu(num);

	return 0;
}

void menu(int seed) {
	int opt = 1;
	int i;
	int num = seed;
	int value;

	//�ʱ� 1���� ������ ����
	while (opt) {
		puts("\n===================MENU=======================");
		printf("1. getBit( Ư�� bit �� ����)\n");
		printf("2. setBit(Ư�� bit ���� 1�� �����)\n");
		printf("3. clearBit( 2�� i�� ��Ʈ���� 0���� �����)\n");
		printf("4. clearBitsMSBthroughI(MSB ~ 2�� i�� ��Ʈ���� ��� 0���� �����)\n");
		printf("5. clearBitsIthrough0(2�� i�� ~ 0�� ��Ʈ���� ��� 0���� �����)\n");
		printf("6. updateBit(Ư�� bit�� ���ϴ� ������ �����ϱ�)\n");
		printf("0. ����\n");
		puts("=================================================\n");

		while (1) {
			opt = inputInteger("�޴��� �Է��ϼ���(0~6) : ");
			if (0 <= opt && opt <= 6)
				break;
		}

		switch (opt){		
		case 0:; break;
		case 1: {
			i = inputBit("- ��Ʈ���� ������ ��Ʈ�� �ڸ�����?(0~31) : ");
			printBit(num);

			if (getBit(num, i))
				printf("2�� %d�� ��° ��Ʈ�� 1�Դϴ�.\n", i);
			else
				printf("2�� %d�� ��° ��Ʈ�� 0�Դϴ�.\n", i);
		}; break;
		case 2: {
			i = inputBit("- ��Ʈ ���� 1�� ���� ��Ʈ�� �ڸ�����?(0~31) : ");
			printf("%11s", "Before : ");
			printBit(num);	//before bit masking
			
			num = setBit(num, i);
			
			printf("%11s", "After : ");
			printBit(num);	//after bit masking
		}; break;
		case 3: {
			i = inputBit("- ��Ʈ ���� 0���� ���� ��Ʈ�� �ڸ�����?(0~31) : ");
			printf("%11s", "Before : ");
			printBit(num);	//before bit masking

			num = clearBit(num, i);

			printf("%11s", "After : ");
			printBit(num);	//after bit masking
		}; break;
		case 4: {
			i = inputBit("-(MSB ~ i�� °) ��Ʈ ���� 0���� ���� ��Ʈ�� �ڸ�����?(0~31) : ");
			printf("%11s", "Before : ");
			printBit(num);	//before bit masking

			num = clearBitsMSBthroughI(num, i);

			printf("%11s", "After : ");
			printBit(num);	//after bit masking
		}; break;
		case 5: {
			i = inputBit("-(i ~ 0�� °) ��Ʈ ���� 0���� ���� ��Ʈ�� �ڸ�����?(0~31) : ");
			printf("%11s", "Before : ");
			printBit(num);	//before bit masking

			num = clearBitsIthrough0(num, i);

			printf("%11s", "After : ");
			printBit(num);	//after bit masking
		}; break;
		case 6: {
			i = inputBit("-������ ��Ʈ�� �ڸ�����?(0~31) : ");
			value = inputBitValue("������ ��Ʈ�� ���� ? (0 or 1) : ");
			
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


/*	��� : Ư�� bit �� ���� �Լ�
	pram num	>	��Ʈ ������ ����
	parm i	>	�������� ������ bit�� �ڸ���
	return	>	Ư�� ��Ʈ�� 1�̶�� 1, 0�̶�� 0 ����
*/
int getBit(int num, int i) {
	unsigned int key = 1;	//2�� 0�� �ڸ� 1 ����

	key <<= i;	//2�� i���ڸ��� ��Ʈ�� 1�� ����
	if ((key & num) == key)
		return 1;
	else
		return 0;
}


/*	��� : num������ 2�� i�� ��Ʈ ���� 1�� ����� ���
pram num	>	��Ʈ ������ ����
parm i	>	�������� 1�� ������ bit�� �ڸ���
return	>	��Ʈ ���� �Ϸ� �� ���� �� ����
*/
int setBit(int num, int i) {
	unsigned int key = 0x1;
	key <<= i;

	return num | key;
}


/*	��� : num������ 2�� i�� ��Ʈ ���� 0���� ����� ���
pram num	>	��Ʈ ������ ����
parm i	>	�������� 0���� ������ bit�� �ڸ���
return	>	��Ʈ ���� �Ϸ� �� ���� �� ����
*/
int clearBit(int num, int i) {
	unsigned int key = 1;
	key <<= i;
	key = ~key;

	return num & key;
}


/*	��� : num������ MSB ��Ʈ���� 2�� i�� ������ ��Ʈ ���� 0���� ����� ���
pram num	>	��Ʈ ������ ����
parm i	>	MSB ~ i ������ ����
return	>	��Ʈ ���� �Ϸ� �� ���� �� ����
*/
int clearBitsMSBthroughI(int num, int i) {
	unsigned int key = 0xFFFFFFFF;
	while (32 - i++) { key >>= 1; }
	return num & key;
}

/*	��� : num������ 2�� i�� ��Ʈ ���� 0 ��Ʈ������ ��Ʈ ���� 0���� ����� ���
pram num	>	��Ʈ ������ ����
parm i	>	i ~ 0 ������ ����
return	>	��Ʈ ���� �Ϸ� �� ���� �� ����
*/
int clearBitsIthrough0(int num, int i) {
	unsigned int key = 0xFFFFFFFF;
	while (1 + i--) { key <<= 1; }
	return num & key;
}

/*	��� : Ư�� bit�� ���ϴ� ������ ����
pram num	>	��Ʈ ������ ����
parm i	>	������ ��Ʈ�� �ε���
parm value>	������ ��
return	>	��Ʈ ���� �Ϸ� �� ���� �� ����
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