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
	int ***ip;	//���� Memory �Ҵ���� 3���� �迭�� ���� �ּ�
	int layer, row, col;	//for 3 dimension matrix

	

	// default : layer, row, col (1~10)�� ������ �ʱ�ȭ
	srand((unsigned int)time(NULL));	//���� �õ� �� ����
	layer = random(10) + 1;
	row = random(10) + 1;
	col = random(10) + 1;

	// �������� �Է� ���� Ȯ��(y : ����� ���� �Է�, n : default ������ ���)
	if (userChoice()) {
		layer = inputNumber("�� �Է�(1~10) : ");
		row = inputNumber("�� �Է�(1~10) : ");
		col = inputNumber("�� �Է�(1~10) : ");
	}
	printf("�� : %d, �� : %d, �� : %d\n", layer, row, col);

	// 3���� �迭�� ���� Memory �Ҵ�
	ip = myAlloc(layer, row, col);

	// 3���� �迭�� ������ ����
	dataInput(ip, layer, row, col);

	// 3���� �迭�� ����� ������ ���
	dataOutput(ip, layer, row, col);

	// �Ҵ���� �޸� free
	myDelete(ip, layer, row, col);

	return 0;
}


/*
��� >		0 ~ key-1 ������ ������ ���� ����
parm key >	���� ���� ����
return >		���������� ������ ���� ��
*/
int random(int key) {
	return rand() % key;
}


/*
��� >		3���� �迭�� ���� �޸� �Ҵ�
parm layer >	3���� �迭�� ���� ����
parm row >	3���� �迭�� ���� ����
parm col >	3���� �迭�� ���� ����
return >		���� : ���������� �Ҵ���� 3���� �迭�� ���� �ּ�
			���� : Null pointer
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
��� >		���� �Ҵ� ���� 3���� �迭 ���� �ʱ�ȭ
parm ip	>	�ʱ�ȭ�� �޸��� ���� �ּ�
parm layer >	3���� �迭�� ���� size
parm row >	3���� �迭�� ���� size
parm col >	3���� �迭�� ���� size
return >		None
*/
void dataInput(int ***ip, int layer, int row, int col) {
	int i, j, k;	//3���� �迭�� �ε���

	for (i = 0; i < layer; i++) {
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				ip[i][j][k] = random(100) + 1;
			}
		}
	}
}


/*
��� >		���� �Ҵ� ���� 3���� �迭�� ��� ���
parm ip	>	����� �޸��� ���� �ּ�
parm layer >	3���� �迭�� ���� size
parm row >	3���� �迭�� ���� size
parm col >	3���� �迭�� ���� size
return >		None
*/
void dataOutput(int ***ip, int layer, int row, int col) {
	int i, j, k;	//3���� �迭�� �ε���

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
��� >		���� �Ҵ� ���� 3���� �迭 free
parm ip	>	free�� �޸��� ���� �ּ�
parm layer >	3���� �迭�� ���� size
parm row >	3���� �迭�� ���� size
parm col >	3���� �迭�� ���� size
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
��� >		����ڿ��� 3���� �迭�� ��, ��, ���� �Է� ���� Ȯ��
return >		���� : �Է� ����
			return 1 : 'y', 'Y' (����� �Է�)
			return 0 : 'N' (default(1~10) ���� ������ �ʱ�ȭ)
*/
int userChoice() {
	char isInput;
	
	while (1) {
		printf("3���� �迭 ���� �޸� �Ҵ� �� \"��, ��, ��\"�� �����Ͽ� ����Ͻðڽ��ϱ�?( y / n )\n");
		printf("(y ���� �� �Է��Ͻ� \"��, ��, ��\"�� ���� �迭�� �ʱ�ȭ �˴ϴ�.)\n");
		printf("(n ���� �� default�� \"��, ��, ��\"�� ���� 1~10 ������ ������ ������ �ʱ�ȭ �˴ϴ�.)\n");
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
��� >		1 ~ 10 ������ ���� �Է�
parm message >	��� �޽���
return >		����� �Է� ����
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