#include "generic_coding.h"

void genericSort(void *p, int count, size_t size, int(*dataCompare)(void *, void *)){
	int i, j;
	void *tmp;
	tmp = malloc(size);

	for (i = 0; i < count - 1; i++) {
		for (j = i + 1; j < count; j++) {
			/*	주소 계산의 결과가 포인터 인덱스 연산에 따른 영향을 받지 않고,
				실제 주소값으로 fix하기 위해 char* type으로 casting.
				이 경우, 주소 연산 시 컴파일러가 인덱스에 포인터의 대상 데이터 타입의
				크기를 자동으로 곱해 주는 부분을 직접 구현 해 주어서
				주소 연산이 자료형의 영향을 받지 않게 해 주어야 한다.
				ex> integer point형 주소 연산 시 : p + i =>(컴파일러 변환) p + i*sizeof(int)		*/
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

