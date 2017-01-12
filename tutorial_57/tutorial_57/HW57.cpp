#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 100

int inputString(char *string);
int checkCircularString(char *string);
void printResult(char *string, char* message);

int main()
{
	char string[BUFFER_SIZE] = { NULL, };
	int res;

	while (inputString(string)) {
		if (checkCircularString(string)) {
			printResult(string, "회문입니다!\n");
		}
		else {
			printResult(string, "회문이 아닙니다!\n");
		}
	}

	return 0;
}

// return> end : 0, 이외 : 1
int inputString(char *string) {
	printf("# 단어 입력 : ");
	scanf("%s", string);
	if (!strcmp(string, "end")) {
		return 0;
	}

	return 1;
}

// return> 회문 : 1, 회문X : 0
int checkCircularString(char *string) {
	int i = 0;
	int len;
	char temp[BUFFER_SIZE] = { NULL, };

	strcpy(temp, string);
	while (temp[i]) {
		temp[i] = toupper(temp[i]);
		i++;
	}

	len = strlen(temp) -1;
	for (i = 0; i < len/2 ; i++) {
		if (temp[i] != temp[len - i]) {
			return 0;
		}
	}

	return 1;
}


void printResult(char *string, char* message) {
	printf("\"%s\" : ", string);
	printf("%s\n", message);
}