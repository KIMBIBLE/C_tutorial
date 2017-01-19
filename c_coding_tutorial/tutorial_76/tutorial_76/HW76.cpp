#include <stdio.h>
#include <string.h>	// �� �׽�Ʈ�� ���� ����

#define BUFFER_SIZE 1000	// ���ڿ� ���� ũ�� ����

char* ustrchr(char *str, int ch);
char* usrcat(char *s1, char *s2);
char* usrstr(char *s1, char *s2);
void ustrcpy(char *s1, char *s2);
unsigned int ustrlen(char *str);
int ustrcmp(char *s1, char *s2);


int main()
{
	// test set for ustrchr()
	char *string1 = "abcdefghijk";
	char *string2 = "1234567890";
	int ch1 = 'f';
	int ch2 = '5';
	char *position;

	// test set for ustrcat()
	char dest[BUFFER_SIZE] = "hello";
	char src[BUFFER_SIZE] = "World!!";

	// test set for ustrstr()
	char *string3 = "banana~~!";
	char *string4 = "na";
	char *string5 = "ab";

	// test set for ustrcpy()
	char cpyDest[BUFFER_SIZE] = "ab";
	char *cpySource = "pineapple";

	// test set for ustrlen()
	char *string6 = "12345";
	unsigned int len;

	// test set for ustrcmp()
	char *string7 = "1234";
	char *string8 = "1234567890";
	char *string9 = "abb";
	char *string10 = "bbb";
	char *string11 = "abc";
	char *string12 = "abd";
	int res;

	/*	<Test Section> ustrchr()	*/
	puts("------------------------------ustrchr() Test------------------------------");
	// test 1-1
	if (position = ustrchr(string1, ch1)) {
		printf("<%s> ���ڿ� ������ <%c> ������ �ּҴ� %p �Դϴ�.(string1[%d])\n", string1, ch1,position, position-string1);
	}
	else {
		printf("<%s> ���ڿ� ������ <%c> ���ڴ� ���ԵǾ����� �ʽ��ϴ�.\n", string1, ch1);
	}

	// test 1-2
	if (position = ustrchr(string1, ch2)) {
		printf("<%s> ���ڿ� ������ <%c> ������ �ּҴ� %p �Դϴ�.(string1[%d])\n", string1, ch2, position, position - string1);
	}
	else {
		printf("<%s> ���ڿ� ������ <%c> ���ڴ� ���ԵǾ����� �ʽ��ϴ�.\n",string1, ch2);
	}

	// test 1-3
	if (position = ustrchr(string2, ch1)) {
		printf("<%s> ���ڿ� ������ <%c> ������ �ּҴ� %p �Դϴ�.(string2[%d])\n", string2, ch1, position, position - string2);
	}
	else {
		printf("<%s> ���ڿ� ������ <%c> ���ڴ� ���ԵǾ����� �ʽ��ϴ�.\n", string2, ch1);
	}

	// test 1-4
	if (position = ustrchr(string2, ch2)) {
		printf("<%s> ���ڿ� ������ <%c> ������ �ּҴ� %p �Դϴ�.(string2[%d])\n", string2, ch2, position, position - string2);
	}
	else {
		printf("<%s> ���ڿ� ������ <%c> ���ڴ� ���ԵǾ����� �ʽ��ϴ�.\n", string2, ch2);
	}
	puts("\n");




	/*	<Test Section> ustrcat()	*/
	puts("------------------------------ustrcat() Test------------------------------");
	// test 2-1
	printf("<%s> + <%s> = <%s>\n",dest,src, usrcat(dest,src));

	puts("\n");




	/*	<Test Section> ustrstr()	*/
	puts("------------------------------ustrstr() Test------------------------------");
	// test 3-1
	if (position = usrstr(string3, string4)) {
		printf("<%s> ���ڿ� ������ <%s> ���ڿ��� ���� �ּҴ� %p �Դϴ�.(string3[%d])\n", string3, string4, position, position - string3);
	}
	else {
		printf("<%s> ���ڿ� ������ <%s> ���ڿ��� ���ԵǾ����� �ʽ��ϴ�.\n", string3, string4);
	}
	
	// test 3-2
	if (position = usrstr(string3, string5)) {
		printf("<%s> ���ڿ� ������ <%s> ���ڿ��� ���� �ּҴ� %p �Դϴ�.(string3[%d])\n", string3, string5, position, position - string3);
	}
	else {
		printf("<%s> ���ڿ� ������ <%s> ���ڿ��� ���ԵǾ����� �ʽ��ϴ�.\n", string3, string5);
	}


	puts("\n");

	/*	<Test Section> ustrcpy()	*/
	puts("------------------------------ustrcpy() Test------------------------------");
	// test 4-1
	printf("<before>\n");
	printf("s1 : %s\n", cpyDest);
	printf("s2 : %s\n", cpySource);

	ustrcpy(cpyDest, cpySource);
	printf("\n(processing)... s1 <- s2\n\n");


	printf("<After>\n");
	printf("s1 : %s\n", cpyDest);
	printf("s2 : %s\n", cpySource);


	puts("\n");

	/*	<Test Section> ustrlen()	*/
	puts("------------------------------ustrlen() Test------------------------------");
	// test 5-1
	printf("strlen() ��� : %s => len : %d\n", string6, strlen(string6));
	printf("ustrlen() ��� : %s => len : %d\n", string6, ustrlen(string6));

	puts("\n");


	/*	<Test Section> ustrcmp()	*/
	puts("------------------------------ustrcmp() Test------------------------------");
	// test 6-1
	res = ustrcmp(string7, string8);
	if (res == 0) {
		printf("<%s> ���ڿ��� <%s> ���ڿ��� ������ ���ڿ��Դϴ�.\n", string7, string8);
	}
	else if (res == 1) {
		printf("<%s> ���ڿ�  >>>>>  <%s> ���ڿ�.\n", string7, string8);
	}
	else if (res == -1) {
		printf("<%s> ���ڿ�  <<<<<  <%s> ���ڿ�.\n", string7, string8);
	}
	else { ; }

	// test 6-2
	res = ustrcmp(string8, string7);
	if (res == 0) {
		printf("<%s> ���ڿ��� <%s> ���ڿ��� ������ ���ڿ��Դϴ�.\n", string8, string7);
	}
	else if (res == 1) {
		printf("<%s> ���ڿ�  >>>>>  <%s> ���ڿ�.\n", string8, string7);
	}
	else if (res == -1) {
		printf("<%s> ���ڿ�  <<<<<  <%s> ���ڿ�.\n", string8, string7);
	}
	else { ; }

	// test 6-2
	res = ustrcmp(string9, string10);
	if (res == 0) {
		printf("<%s> ���ڿ��� <%s> ���ڿ��� ������ ���ڿ��Դϴ�.\n", string9, string10);
	}
	else if (res == 1) {
		printf("<%s> ���ڿ�  >>>>>  <%s> ���ڿ�.\n", string9, string10);
	}
	else if (res == -1) {
		printf("<%s> ���ڿ�  <<<<<  <%s> ���ڿ�.\n", string9, string10);
	}
	else { ; }

	res = ustrcmp(string11, string12);
	if (res == 0) {
		printf("<%s> ���ڿ��� <%s> ���ڿ��� ������ ���ڿ��Դϴ�.\n", string11, string12);
	}
	else if (res == 1) {
		printf("<%s> ���ڿ�  >>>>>  <%s> ���ڿ�.\n", string11, string12);
	}
	else if (res == -1) {
		printf("<%s> ���ڿ�  <<<<<  <%s> ���ڿ�.\n", string11, string12);
	}
	else { ; }

	puts("\n");




	return 0;
}


/*
��� > str ���ڿ� ������ ���� ch�� �ּ� ã��.
parm1 str > ���ڸ� ã�� ���ڿ��� ���� �ּ�.
parm2 ch > ���ڿ����� ã�� int�� ���� ch.
return >	���� : ���ڿ� ������ ���� ch�� �ּ�.
		���� : NULL pointer
*/
char* ustrchr(char *str, int ch) {
	int i;
	int len = ustrlen(str);

	for (i = 0; i < len; i++) {
		if (str[i] == ch) {
			return str + i;
		}
	}

	return NULL;
}


/*
��� > s1 ���ڿ� �ڿ� s2 ���ڿ��� ������ �� s1�� �����ּ� ����
parm1 s1 > dest
parm2 s2 > src
return > ��ģ ���ڿ��� ���� �ּ�(s1����) ��ȯ
*/
char* usrcat(char *s1, char *s2) {
	int lenS1;
	int lenS2;
	int i, j;

	lenS1 = 0;
	while (s1[lenS1]) {
		lenS1++;
	}
	
	// s2 ����
	lenS2 = ustrlen(s2);
	for (i = 0; i < lenS2; i++) {
		s1[lenS1 + i] = s2[i];
	}
	s1[lenS1 + i] = NULL;

	return s1;
}


/*
��� > s1 ���ڿ� ���� s2 ���ڿ��� �κ� ���ڿ��� �����ϴ��� �˻�
parm s1 > source string
parm s2 > ã�� �κ� ���ڿ�
return >	���� : �κ� ���ڿ��� ���� �ּ� ����
		���� : NULL pointer
*/
char* usrstr(char *s1, char *s2) {
	int matchCnt;
	int lenS2;
	int i;
	int idx = 0;

	lenS2 = ustrlen(s2);

	while (s1[idx]) {
		matchCnt = 0;
		for (i = 0; i < lenS2; i++) {
			if (s1[idx + matchCnt] == s2[i]) { matchCnt++; }
			else { break; }

			if (matchCnt == lenS2) { return s1 + idx; }
		}
		idx++;
	}

	return NULL;
}

/*
��� > s1 �ּҿ� s2 ���ڿ��� ����(s1 �ּ� �������� �����ؼ� ���� �߻��� �� ����)
parm s1 > dest
parm s2 > src
return > None
*/
void ustrcpy(char *s1, char *s2) {
	int i;
	int sourceLen;

	sourceLen = ustrlen(s2);

	for (i = 0; i < sourceLen; i++) {
		s1[i] = s2[i];
	}

}


/*
��� > str ���ڿ��� ���� �ּҺ��� Null���� �������� ���� ���ϱ�.
parm1 str > ���̸� ���� ���ڿ�
return > ���ڿ��� ����
*/
unsigned int ustrlen(char *str) {
	unsigned int len = 0;

	while (str[len]) { 
		len++;
	}

	return len;
}

/*
��� > �� ���ڿ��� ���ڸ� ���������� ��
parm s1 > ���ڿ� 1
parm s2 > ���ڿ� 2
return >	0  : s1 == s2
		1  : s1 > s2
		-1 : s1 < s2 
*/
int ustrcmp(char *s1, char *s2) {
	int i = 0;
	
	while (s1[i] == s2[i]) {
		i++;
	}

	if (s1[i] > s2[i]) { return 1; }
	else if (s1[i] < s2[i]) { return -1; }
	else { return 0; }
}


