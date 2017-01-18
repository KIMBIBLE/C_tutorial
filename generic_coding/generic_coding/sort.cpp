#include "generic_coding.h"

void genericSort(void *p, int count, size_t size, int(*dataCompare)(void *, void *)){
	int i, j;
	void *tmp;
	tmp = malloc(size);

	for (i = 0; i < count - 1; i++) {
		for (j = i + 1; j < count; j++) {
			/*	�ּ� ����� ����� ������ �ε��� ���꿡 ���� ������ ���� �ʰ�,
				���� �ּҰ����� fix�ϱ� ���� char* type���� casting.
				�� ���, �ּ� ���� �� �����Ϸ��� �ε����� �������� ��� ������ Ÿ����
				ũ�⸦ �ڵ����� ���� �ִ� �κ��� ���� ���� �� �־
				�ּ� ������ �ڷ����� ������ ���� �ʰ� �� �־�� �Ѵ�.
				ex> integer point�� �ּ� ���� �� : p + i =>(�����Ϸ� ��ȯ) p + i*sizeof(int)		*/
			if (dataCompare((char *)p + i*size, (char *)p + j*size) > 0) {
				memcpy(tmp, (char *)p + i*size, size);
				memcpy((char *)p + i*size, (char *)p + j*size, size);
				memcpy((char *)p + j*size, tmp, size);
			}
		}
	}

	free(tmp);
}


int integerCompare(void *p1, void *p2) {
	if (*(int *)p1 > *(int *)p2) { return 1; }
	else if (*(int *)p1 == *(int *)p2) { return 0; }
	else { return -1; }
}


int doubleCompare(void *p1, void *p2) {
	if (*(double *)p1 > *(double *)p2) { return 1; }
	if (*(double *)p1 == *(double *)p2) { return 0; }
	else { return -1; }
}


int stringCompare(void *p1, void *p2) {
	if (strcmp((char *)p1, (char *)p2) > 0) { return 1; }
	else if (strcmp((char *)p1, (char *)p2) == 0) { return 0; }
	else { return -1; }
}

