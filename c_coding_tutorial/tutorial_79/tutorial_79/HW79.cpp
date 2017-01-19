#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define BUFFER_SIZE 1000
#define STRING_NUM 5

void inputString(char *p[STRING_NUM]);
void swapString(char **string1, char **string2);
void displayOutput(char *p[STRING_NUM]);
void freeString(char *p[STRING_NUM]);

int main()
{
	char *string[STRING_NUM];
	int i;

	inputString(string);

	for (i = 0; i < STRING_NUM -1; i++) {
		if (strcmp(string[i], string[i + 1]) > 0) {
			swapString(string + i, string + i + 1);
		}
	}

	displayOutput(string);
	freeString(string);

	return 0;
}


void inputString(char *p[STRING_NUM]) {
	char temp[BUFFER_SIZE] = { NULL, };
	int i;
	int len;

	for (i = 0; i < STRING_NUM; i++) {
		// ����� �Է�(temp �ӽ� ����)
		printf("# ���ڿ� %d : ", i + 1);
		scanf("%s", temp);

		// "���ڿ� ���� + 1" ���� Memory �Ҵ�
		len = strlen(temp);
		p[i] = (char*)malloc(sizeof(char) * (len + 1));
		assert(p[i] != NULL);

		// ���ڿ� ���� p[i] <- temp
		strcpy(p[i], temp);
	}
}


void swapString(char **string1, char **string2) {
	char *temp = NULL;

	temp = *string1;
	*string1 = *string2;
	*string2 = temp;

}

void displayOutput(char *p[STRING_NUM]) {
	int i;

	for (i = 0; i < STRING_NUM; i++) {
		printf("%d. %s\n", i + 1, p[i]);
	}
}

void freeString(char *p[STRING_NUM]) {
	int i;

	for (i = 0; i < STRING_NUM; i++) {
		free(p[i]);
	}
}