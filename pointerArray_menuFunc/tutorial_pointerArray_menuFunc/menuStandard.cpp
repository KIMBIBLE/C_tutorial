#include <stdio.h>

void menuDisplay1(char **menuPtr, size_t menuCnt);
void menuDisplay2(char(*menuPtr)[10], size_t menuCnt);

int main()
{
	// ������ �迭�� �̿��� ���ڿ� ����
	char *ptrAryMenu[] = { "insert", "output", "search", "quit" };
	
	// �迭�� ����Ű�� ������(�迭 ������)�� �̿��� ���ڿ� ����
	char aryPtrMenu[][10] = { "insert", "output", "search", "quit" };

	menuDisplay1(ptrAryMenu, sizeof(ptrAryMenu) / sizeof(ptrAryMenu[0]));
	puts("\n");
	menuDisplay2(aryPtrMenu, sizeof(aryPtrMenu) / sizeof(aryPtrMenu[0]));

	return 0;
}

// ������ �迭�� �̿��� ���ڿ� ���
void menuDisplay1(char **menuPtr, size_t menuCnt) {
	for (size_t i = 0; i < menuCnt; i++) {
		printf("%d. %s\n", i + 1, menuPtr[i]);
	}
	return;
}

// �迭�� ����Ű�� ������(�迭 ������)�� �̿��� ���ڿ� ���
void menuDisplay2(char(*menuPtr)[10], size_t menuCnt) {
	for (size_t i = 0; i < menuCnt; i++) {
		printf("%d. %s\n", i + 1, menuPtr[i]);
	}
	return;
}