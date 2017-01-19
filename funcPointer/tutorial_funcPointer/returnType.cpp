#include <stdio.h>

typedef void(*func_t)(void);

void vegetable(), fruit(), grain();
func_t getGroup(int);	//함수 포인터를 리턴하는 함수 선언부
//	void (*)(void) getGroup(int menu)	=> 에러
//	void (*getGroup(int menu))(void)	=> 가능

int main()
{
	int menu;
	void(*fptr)(void) = NULL;

	while (1) {
		printf("1. vegetable / 2. fruit / 3. grain / 4. quit : ");
		scanf("%d", &menu);
		if (menu == 4) { break; }
		fptr = getGroup(menu);	// 함수 포인터 값 리턴 받기
		if (fptr != NULL) { fptr(); }
	}
	return 0;
}

func_t getGroup(int menu) {
	switch (menu) {
	case 1: return vegetable;
	case 2: return fruit;
	case 3: return grain;
	}
	return NULL;
}

void vegetable() {
	char *vegetableName[] = { "celery", "cucumber", "potato" };
	size_t size = sizeof(vegetableName) / sizeof(vegetableName[0]);
	for (size_t i = 0; i < size; i++) {
		printf("[%d] %s\n", i + 1, vegetableName[i]);
	}
}

void fruit() {
	char *fruitName[] = { "grape", "kiwi", "strawberry", "banana",
					"orange" };
	size_t size = sizeof(fruitName) / sizeof(fruitName[0]);
	for (size_t i = 0; i < size; i++) {
		printf("[%d] : %s\n", i + 1, fruitName[i]);
	}
}

void grain() {
	char *grainNmae[] = { "rice", "bean", "oats", "corn" };
	size_t size = sizeof(grainNmae) / sizeof(grainNmae[0]);
	for (size_t i = 0; i < size; i++) {
		printf("[%d] : %s\n", i + 1, grainNmae[i]);
	}
}