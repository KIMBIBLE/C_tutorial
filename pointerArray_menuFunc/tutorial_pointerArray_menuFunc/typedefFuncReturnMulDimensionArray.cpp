/*
������ �迭 ������ typedef
(����) : typedef type (*new array pointer name)[n]
(����) :
char str[3][10];
typedef char (*strPtr_t)[10];
strPtr_t p;
p = str;
p[1][2] = 'b';

*/

#include <stdio.h>
#include <malloc.h>

typedef int(*intArrayPtr)[4];
intArrayPtr memoryAllocation(int);

int main()
{
	int row;
	int(*aryPtr)[4] = NULL;
	//intArrayPtr aryPtr = NULL;

	printf("input row count : ");
	scanf("%d", &row);

	aryPtr = memoryAllocation(row);
	aryPtr[row - 1][3] = 77;
	printf("aryPtr[%d][3] = %d\n", row - 1, aryPtr[row - 1][3]);

	free(aryPtr);

	return 0;
}

/* int (*)[4] memoryAllocation(int row) => ���� */
/* int (*memoryAllocation(int row))[4]	=> ���� */
// �������� row �� ��ŭ 2���� �迭 �޸𸮸� �Ҵ��Ͽ� �ּҸ� ����
intArrayPtr memoryAllocation(int row) {
	intArrayPtr p;	/* ���� ǥ�� : int (*p)[4] = NULL */
	p = (intArrayPtr)malloc(row * sizeof(int[4]));
	/* ���� ǥ�� : p = (int (*)[4])malloc(row*sizeof(int [4])); */

	return p;
}