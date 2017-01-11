#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

int input(char *str, char *pCh);
int strcheck(char *str, char ch, int check);

int main()
{
	char string[BUFFER_SIZE] = { NULL, };
	char ch;
	int idx = 0;

	while (input(string, &ch)) {
		printf("\"%s\" ���ڿ� �ȿ� \'%c\'���ڴ� ", string, ch);
		if (-1 == (idx = strcheck(string, ch, idx))) {
			printf("�������� �ʽ��ϴ�.\n");;
		}
		else {	// �����Ѵٸ� res : string������ ������ ���� �ε���
			printf("%d�� ", idx);
			while (1) {
				idx = strcheck(string, ch, idx);
				if (idx == -1) { break; }
				printf("%d�� ", idx);
			}
			printf("��ġ�� �����մϴ�.\n");
		}
		puts("");
	}

	return 0;
}


int input(char *str, char *pCh) {
	printf("# ���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", str);

	if (!strcmp(str, "end")) {
		return 0;
	}

	while (1) {
		printf("# ���ڸ� �Է��Ͻÿ� : ");
		scanf(" %c", pCh);
		if (getchar() == '\n') { return 1; }
		while (getchar() != '\n') { ; }
	}
}

int strcheck(char *str, char ch, int check) {
	int i;
	int len;

	len = strlen(str);
	for (i = check + 1; i < len; i++) {
		if (str[i] == ch) { 
			return i; 
		}
	}

	return -1;
}
