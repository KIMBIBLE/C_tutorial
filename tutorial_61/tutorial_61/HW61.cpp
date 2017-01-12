#include <stdio.h>
#include <string.h>

void set2DArray(char (*ary)[20]);
void strSort(char(*ary)[20]);
void displayResult(char(*ary)[20]);
void strSwap(char *string1, char *string2);

int main()
{
	char ary[5][20];

	set2DArray(ary);
	strSort(ary);
	displayResult(ary);

	return 0;
}

void set2DArray(char(*ary)[20]) {
	int i = 0;

	for (i = 0; i < 5; i++) {
		printf("# %d번 문자열을 입력하시오 : ", i + 1);
		scanf("%s", ary[i]);
	}
}

void strSort(char(*ary)[20]) {
	int i, j;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5 - i; j++) {
			if (strcmp(ary[j], ary[j + 1]) > 0) {
				strSwap(ary[j], ary[j + 1]);
			}
		}
	}
}

void displayResult(char(*ary)[20]) {
	int i;

	for (i = 0; i < 5; i++) {
		printf("str[%d] = %s\n",i, ary[i]);
	}
}

void strSwap(char *string1, char *string2) {
	char temp[20] = { NULL, };

	strcpy(temp, string1);
	strcpy(string1, string2);
	strcpy(string2, temp);
}