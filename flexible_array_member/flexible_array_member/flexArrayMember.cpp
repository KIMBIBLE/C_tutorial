/*
Flexible Array Member?
����ü�� �̸��� �ִ� �� �� �̻��� ����� ���� ��, ������ ���Ұ�
�ҿ����� �迭 Ÿ���� ����� ���� ��츦 ���Ѵ�.(÷�� ����)
�� �迭�� ũ�Ⱑ ����ü ������ ��������� �������� ���� ����̴�.

Flexible Array Member Ư¡
1) Flexible Array Member�� �ݵ�� ����ü�� ������ ���ҿ��� �Ѵ�.
2) Flexible Array Member�� ���ҷ� ���� ����ü�� �迭�� �����Ͽ�
����� �� ����.
3) Flexible Array Member�� �����ϴ� ����ü�� �ٸ� ����ü�� �����
����� ������ ������ ������߸� �Ѵ�.
4) sizeof �����ڴ� Flexible Array Member�� ������ �� ����.
- ��, ����ü�� ũ��� sizeof �����ڷ� ���� �� ������,
Flexible Array Member�� ũ��� 0���� ���ȴ�.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC_FLEX(stype, number, etype) \
	((stype *) malloc(sizeof(stype) + (number) * sizeof(etype)))
#define REALLOC_FLEX(stype, number, etype) \
	((stype *) malloc(sizeof(stype) + (number) * sizeof(etype)))
// sizeof(stype) : 0, (number) * sizeof(etype) : �Ҵ��� ��� ������ ũ��

typedef struct string
{
	size_t length;
	char text[];	//Flex Array Member�� ������ ��� �ڸ��� ���� �ϳ��� ��� ����
}string;

int main()
{
	string *fruit_name;
	fruit_name = MALLOC_FLEX(string, 7, char);
	if (!fruit_name) {
		printf("�޸� �Ҵ� ����\n");
		exit(0);
	}

	strcpy(fruit_name->text, "banana");
	fruit_name->length = strlen(fruit_name->text);
	printf("%s : %u Byte\n", fruit_name->text, fruit_name->length + 1);
	
	fruit_name = REALLOC_FLEX(string, 11, char);
	if (!fruit_name) {
		printf("�޸� �Ҵ� ����\n");
		exit(0);
	}
	strcpy(fruit_name->text, "pine apple");
	fruit_name->length = strlen(fruit_name->text);
	printf("%s : %u Byte\n", fruit_name->text, fruit_name->length + 1);

	free(fruit_name);

	return 0;
}