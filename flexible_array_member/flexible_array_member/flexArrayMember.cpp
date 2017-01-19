/*
Flexible Array Member?
구조체가 이름이 있는 한 개 이상의 멤버를 가질 때, 마지막 원소가
불완전한 배열 타입의 멤버를 갖는 경우를 말한다.(첨자 생략)
즉 배열의 크기가 구조체 내에서 명시적으로 지정되지 않은 경우이다.

Flexible Array Member 특징
1) Flexible Array Member는 반드시 구조체의 마지막 원소여야 한다.
2) Flexible Array Member를 원소로 갖는 구조체는 배열로 선언하여
사용할 수 없다.
3) Flexible Array Member를 포함하는 구조체를 다른 구조체의 멤버로
사용할 때에는 마지막 멤버여야만 한다.
4) sizeof 연산자는 Flexible Array Member에 적용할 수 없다.
- 단, 구조체의 크기는 sizeof 연산자로 구할 수 있으며,
Flexible Array Member의 크기는 0으로 계산된다.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC_FLEX(stype, number, etype) \
	((stype *) malloc(sizeof(stype) + (number) * sizeof(etype)))
#define REALLOC_FLEX(stype, number, etype) \
	((stype *) malloc(sizeof(stype) + (number) * sizeof(etype)))
// sizeof(stype) : 0, (number) * sizeof(etype) : 할당할 기억 공간의 크기

typedef struct string
{
	size_t length;
	char text[];	//Flex Array Member는 마지막 멤버 자리에 오직 하나만 사용 가능
}string;

int main()
{
	string *fruit_name;
	fruit_name = MALLOC_FLEX(string, 7, char);
	if (!fruit_name) {
		printf("메모리 할당 에러\n");
		exit(0);
	}

	strcpy(fruit_name->text, "banana");
	fruit_name->length = strlen(fruit_name->text);
	printf("%s : %u Byte\n", fruit_name->text, fruit_name->length + 1);
	
	fruit_name = REALLOC_FLEX(string, 11, char);
	if (!fruit_name) {
		printf("메모리 할당 에러\n");
		exit(0);
	}
	strcpy(fruit_name->text, "pine apple");
	fruit_name->length = strlen(fruit_name->text);
	printf("%s : %u Byte\n", fruit_name->text, fruit_name->length + 1);

	free(fruit_name);

	return 0;
}