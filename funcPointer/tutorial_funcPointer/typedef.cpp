/*
typedef를 활용한 function pointer 형명 재지정
(형식) : typedef return type (*함수 포인터의 새 형명) (parameter list)  
(예제) :
void sub(int, int)
typedef void (*FuncPtr)(int, int);
FuncPtr fptr;
fPtr = sub;
fPtr(10, 20)

*/

#include <stdio.h>
void sub1();
void sub2();
void sub3();

int main()
{
	typedef void(*func_t)(void);	// 함수 포인터 변수의 타입 재정의
	/* typedef void (*)(void) func_t; 같은 경우는 에러 발생하는 표현	*/
	/* typedef 키워드로 재정의한 자료형은 관례적으로 _t 접미사를 갖는다. */
	int i;
	func_t *fptr;	/* 함수 포인터 변수를 가리키는 포인터 선언 */
				// void(*fptr)(void)
	func_t funcAry[3] = { sub1, sub2, sub3 };	// void(funcAry[3])(void)
	fptr = funcAry;
	for (i = 0; i < 3; i++) {
		fptr[i]();
		funcAry[i]();
		printf("\n");
	}

	return 0;
}

void sub1() {
	printf("sub1()\n");
}

void sub2() {
	printf("sub2()\n");
}

void sub3() {
	printf("sub3()\n");
}