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
		printf("\"%s\" 문자열 안에 \'%c\'문자는 ", string, ch);
		if (-1 == (idx = strcheck(string, ch, idx))) {
			printf("존재하지 않습니다.\n");;
		}
		else {	// 존재한다면 res : string에서의 문자의 시작 인덱스
			printf("%d번 ", idx);
			while (1) {
				idx = strcheck(string, ch, idx);
				if (idx == -1) { break; }
				printf("%d번 ", idx);
			}
			printf("위치에 존재합니다.\n");
		}
		puts("");
	}

	return 0;
}


int input(char *str, char *pCh) {
	printf("# 문자열을 입력하시오 : ");
	scanf("%s", str);

	if (!strcmp(str, "end")) {
		return 0;
	}

	while (1) {
		printf("# 문자를 입력하시오 : ");
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
