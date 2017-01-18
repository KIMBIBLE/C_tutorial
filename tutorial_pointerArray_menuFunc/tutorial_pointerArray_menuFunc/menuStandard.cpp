#include <stdio.h>

void menuDisplay1(char **menuPtr, size_t menuCnt);
void menuDisplay2(char(*menuPtr)[10], size_t menuCnt);

int main()
{
	// 포인터 배열을 이용한 문자열 전달
	char *ptrAryMenu[] = { "insert", "output", "search", "quit" };
	
	// 배열을 가리키는 포인터(배열 포인터)를 이용한 문자열 전달
	char aryPtrMenu[][10] = { "insert", "output", "search", "quit" };

	menuDisplay1(ptrAryMenu, sizeof(ptrAryMenu) / sizeof(ptrAryMenu[0]));
	puts("\n");
	menuDisplay2(aryPtrMenu, sizeof(aryPtrMenu) / sizeof(aryPtrMenu[0]));

	return 0;
}

// 포인터 배열을 이용한 문자열 출력
void menuDisplay1(char **menuPtr, size_t menuCnt) {
	for (size_t i = 0; i < menuCnt; i++) {
		printf("%d. %s\n", i + 1, menuPtr[i]);
	}
	return;
}

// 배열을 가리키는 포인터(배열 포인터)를 이용한 문자열 출력
void menuDisplay2(char(*menuPtr)[10], size_t menuCnt) {
	for (size_t i = 0; i < menuCnt; i++) {
		printf("%d. %s\n", i + 1, menuPtr[i]);
	}
	return;
}