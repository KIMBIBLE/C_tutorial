#include <stdio.h>
#include <string.h>	// 비교 테스트를 위해 포함

#define BUFFER_SIZE 1000	// 문자열 버퍼 크기 제한

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
		printf("<%s> 문자열 내에서 <%c> 문자의 주소는 %p 입니다.(string1[%d])\n", string1, ch1,position, position-string1);
	}
	else {
		printf("<%s> 문자열 내에서 <%c> 문자는 포함되어있지 않습니다.\n", string1, ch1);
	}

	// test 1-2
	if (position = ustrchr(string1, ch2)) {
		printf("<%s> 문자열 내에서 <%c> 문자의 주소는 %p 입니다.(string1[%d])\n", string1, ch2, position, position - string1);
	}
	else {
		printf("<%s> 문자열 내에서 <%c> 문자는 포함되어있지 않습니다.\n",string1, ch2);
	}

	// test 1-3
	if (position = ustrchr(string2, ch1)) {
		printf("<%s> 문자열 내에서 <%c> 문자의 주소는 %p 입니다.(string2[%d])\n", string2, ch1, position, position - string2);
	}
	else {
		printf("<%s> 문자열 내에서 <%c> 문자는 포함되어있지 않습니다.\n", string2, ch1);
	}

	// test 1-4
	if (position = ustrchr(string2, ch2)) {
		printf("<%s> 문자열 내에서 <%c> 문자의 주소는 %p 입니다.(string2[%d])\n", string2, ch2, position, position - string2);
	}
	else {
		printf("<%s> 문자열 내에서 <%c> 문자는 포함되어있지 않습니다.\n", string2, ch2);
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
		printf("<%s> 문자열 내에서 <%s> 문자열의 시작 주소는 %p 입니다.(string3[%d])\n", string3, string4, position, position - string3);
	}
	else {
		printf("<%s> 문자열 내에서 <%s> 문자열은 포함되어있지 않습니다.\n", string3, string4);
	}
	
	// test 3-2
	if (position = usrstr(string3, string5)) {
		printf("<%s> 문자열 내에서 <%s> 문자열의 시작 주소는 %p 입니다.(string3[%d])\n", string3, string5, position, position - string3);
	}
	else {
		printf("<%s> 문자열 내에서 <%s> 문자열은 포함되어있지 않습니다.\n", string3, string5);
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
	printf("strlen() 결과 : %s => len : %d\n", string6, strlen(string6));
	printf("ustrlen() 결과 : %s => len : %d\n", string6, ustrlen(string6));

	puts("\n");


	/*	<Test Section> ustrcmp()	*/
	puts("------------------------------ustrcmp() Test------------------------------");
	// test 6-1
	res = ustrcmp(string7, string8);
	if (res == 0) {
		printf("<%s> 문자열과 <%s> 문자열은 동일한 문자열입니다.\n", string7, string8);
	}
	else if (res == 1) {
		printf("<%s> 문자열  >>>>>  <%s> 문자열.\n", string7, string8);
	}
	else if (res == -1) {
		printf("<%s> 문자열  <<<<<  <%s> 문자열.\n", string7, string8);
	}
	else { ; }

	// test 6-2
	res = ustrcmp(string8, string7);
	if (res == 0) {
		printf("<%s> 문자열과 <%s> 문자열은 동일한 문자열입니다.\n", string8, string7);
	}
	else if (res == 1) {
		printf("<%s> 문자열  >>>>>  <%s> 문자열.\n", string8, string7);
	}
	else if (res == -1) {
		printf("<%s> 문자열  <<<<<  <%s> 문자열.\n", string8, string7);
	}
	else { ; }

	// test 6-2
	res = ustrcmp(string9, string10);
	if (res == 0) {
		printf("<%s> 문자열과 <%s> 문자열은 동일한 문자열입니다.\n", string9, string10);
	}
	else if (res == 1) {
		printf("<%s> 문자열  >>>>>  <%s> 문자열.\n", string9, string10);
	}
	else if (res == -1) {
		printf("<%s> 문자열  <<<<<  <%s> 문자열.\n", string9, string10);
	}
	else { ; }

	res = ustrcmp(string11, string12);
	if (res == 0) {
		printf("<%s> 문자열과 <%s> 문자열은 동일한 문자열입니다.\n", string11, string12);
	}
	else if (res == 1) {
		printf("<%s> 문자열  >>>>>  <%s> 문자열.\n", string11, string12);
	}
	else if (res == -1) {
		printf("<%s> 문자열  <<<<<  <%s> 문자열.\n", string11, string12);
	}
	else { ; }

	puts("\n");




	return 0;
}


/*
기능 > str 문자열 내에서 문자 ch의 주소 찾기.
parm1 str > 문자를 찾을 문자열의 시작 주소.
parm2 ch > 문자열에서 찾을 int형 문자 ch.
return >	성공 : 문자열 내에서 문자 ch의 주소.
		실패 : NULL pointer
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
기능 > s1 문자열 뒤에 s2 문자열을 덧붙인 후 s1의 시작주소 리턴
parm1 s1 > dest
parm2 s2 > src
return > 합친 문자열의 시작 주소(s1기준) 반환
*/
char* usrcat(char *s1, char *s2) {
	int lenS1;
	int lenS2;
	int i, j;

	lenS1 = 0;
	while (s1[lenS1]) {
		lenS1++;
	}
	
	// s2 복사
	lenS2 = ustrlen(s2);
	for (i = 0; i < lenS2; i++) {
		s1[lenS1 + i] = s2[i];
	}
	s1[lenS1 + i] = NULL;

	return s1;
}


/*
기능 > s1 문자열 내에 s2 문자열이 부분 문자열로 존재하는지 검사
parm s1 > source string
parm s2 > 찾을 부분 문자열
return >	성공 : 부분 문자열의 시작 주소 리턴
		실패 : NULL pointer
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
기능 > s1 주소에 s2 문자열을 복사(s1 주소 기억공간이 부족해서 오류 발생할 수 있음)
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
기능 > str 문자열의 시작 주소부터 Null문자 전까지의 길이 구하기.
parm1 str > 길이를 구할 문자열
return > 문자열의 길이
*/
unsigned int ustrlen(char *str) {
	unsigned int len = 0;

	while (str[len]) { 
		len++;
	}

	return len;
}

/*
기능 > 두 문자열의 문자를 순차적으로 비교
parm s1 > 문자열 1
parm s2 > 문자열 2
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


