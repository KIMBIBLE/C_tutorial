/*
다차원 배열 포인터 typedef
(형식) : typedef type (*new array pointer name)[n]
(예제) :
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

/* int (*)[4] memoryAllocation(int row) => 에러 */
/* int (*memoryAllocation(int row))[4]	=> 가능 */
// 전달인자 row 수 만큼 2차원 배열 메모리를 할당하여 주소를 리턴
intArrayPtr memoryAllocation(int row) {
	intArrayPtr p;	/* 동일 표현 : int (*p)[4] = NULL */
	p = (intArrayPtr)malloc(row * sizeof(int[4]));
	/* 동일 표현 : p = (int (*)[4])malloc(row*sizeof(int [4])); */

	return p;
}