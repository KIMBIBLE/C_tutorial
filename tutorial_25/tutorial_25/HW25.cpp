#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputNum();
int guessMessage(int num, int key, int* max, int* min);

int main()
{
	int num;	//1~100 ������ ����
	int cnt = 1;
	int key;
	
	// �� ���� ���� ���� ����
	int min = 0;
	int max = 100;

	srand((unsigned int)time(NULL));
	key = rand() % 100 + 1;
	
	//DELETE COMMENT FOR TEST
	//printf("key : %d\n", key);
	
	num = inputNum();
	while (!guessMessage(num, key, &max, &min)) {
		num = inputNum();
		cnt++;
	}
	printf("���~ �¾Ҵ�~~~ ��ī��ī~~ %d ��° ���� ���߼̽��ϴ�.\n", cnt);

	return 0;
}


int inputNum() {
	int num;

	printf("# ���ڸ� �Է��Ͻÿ� : ");
	while (scanf("%d", &num) != 1) {
		while (getchar() != '\n')	;
		printf("# ���ڸ� �Է��Ͻÿ� : ");
	}
		
	return num;
}

//	return  ���� : 1, ���� : 0
int guessMessage(int num, int key, int* max, int* min) {

	if (num < key)	num < *min ? NULL : *min = num;
	else if(num > key) num > *max ? NULL : *max = num;
	else return 1;

	printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", *min, *max);

	return 0;
}

