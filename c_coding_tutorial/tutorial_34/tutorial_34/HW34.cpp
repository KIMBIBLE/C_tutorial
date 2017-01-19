#include <stdio.h>

int menu();
char openFan(char fan);
char offFan(char fan);
char reverseFan(char fan);
void displayFan(char fan);
int inputInt(char* message);

int main()
{
	char fan = 0;	//FAN ����(�ʱ� OFF)
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
		choice = inputInt("\n1. ȯǳ�� ���� / 2. ȯǳ�� �ݱ� / 3. ȯǳ�� ��ü ��ȯ / 4. ���� : ");
		if (1 <= choice && choice <= 4) { return choice; }
	}
}

char openFan(char fan){
	int fanNum;
	unsigned char key = 0x1;

	while (1) {
		printf("\n-----------------------------------------------------------------\n");
		printf("\n                     Fan ���� �۾� ���� ȭ��\n");
		printf("\n-----------------------------------------------------------------\n");
		fanNum = inputInt("\nOPEN�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
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
		printf("\n                     Fan �ݱ� �۾� ���� ȭ��\n");
		printf("\n-----------------------------------------------------------------\n");
		fanNum = inputInt("\nCLOSE�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
		if (1 <= fanNum && fanNum <= 8) { break; }
	}
	printf("\n-----------------------------------------------------------------\n");

	//FAN CLOSE(Bit Masking)
	//1�� ���� ��Ʈ ����
	while (fanNum - 1) {
		key <<= 1;
		fanNum--;
	}
	//0���� ���� ��ġ�� ��Ʈ�� �����ϰ� 1�� ����
	key = ~key;

	fan &= key;

	displayFan(fan);
	printf("\n-----------------------------------------------------------------\n");

	return fan;
}

char reverseFan(char fan) {
	int fanNum;
	
	printf("\n-----------------------------------------------------------------\n");
	printf("\n                 Fan ��ü ��ȯ �۾� ���� ȭ��\n");
	printf("\n-----------------------------------------------------------------\n");
	//fan ��ȯ
	fan = ~fan;
	printf("\n��ü FAN�� ���°� ��ȯ�Ǿ����ϴ�.(ON, OFF ���� �ڹٲ�)\n");

	displayFan(fan);
	printf("\n-----------------------------------------------------------------\n");

	return fan;
}

void displayFan(char fan) {
	int fanNum = 8;	//8�� �Һ��� ���� ���
	unsigned char key = 0x80;	//8�� �� ��Ʈ 1�� ����

	puts("");
	while (fanNum) {	printf("%d��FAN  ", fanNum--);	}
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