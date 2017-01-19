#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

int input(char *str, char *pCh);
int strcheck(char *str, char ch);

int main()
{
	char string[BUFFER_SIZE] = { NULL, };
	char ch;
	int res;

	while (input(string, &ch)) {
		if (-1 != (res = strcheck(string, ch))) {
			printf("\"%s\" ���ڿ� �ȿ� \'%c\'���ڴ� %d�� ��ġ�� �����մϴ�.\n",
				string, ch, res);
		}
		else {
			printf("\"%s\" ���ڿ� �ȿ� \'%c\'���ڴ� �������� �ʽ��ϴ�.\n",
				string, ch);
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
int strcheck(char *str, char ch) {
	int i;
	int len;

	len = strlen(str);
	for (i = 0; i < len; i++) {
		if (str[i] == ch) { return i; }
	}

	return -1;
}
