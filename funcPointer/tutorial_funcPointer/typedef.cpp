/*
typedef�� Ȱ���� function pointer ���� ������
(����) : typedef return type (*�Լ� �������� �� ����) (parameter list)  
(����) :
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
	typedef void(*func_t)(void);	// �Լ� ������ ������ Ÿ�� ������
	/* typedef void (*)(void) func_t; ���� ���� ���� �߻��ϴ� ǥ��	*/
	/* typedef Ű����� �������� �ڷ����� ���������� _t ���̻縦 ���´�. */
	int i;
	func_t *fptr;	/* �Լ� ������ ������ ����Ű�� ������ ���� */
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