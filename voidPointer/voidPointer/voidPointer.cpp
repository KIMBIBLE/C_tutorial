/*
void pointer? : 가리키는 대상체의 type에 제한이 없는 포인터

(선언 형식)
void * 포인터 명;

void pointer는 포인팅 자체는 자유로우나 자신이 포인팅하는 대상을
모르는 상태이기 때문에 void 포인터 자체로 주소 연산을 할 수 없다.
따라서 void pointer는 사용 시 캐스팅이 필요하다.

(void pointer의 사용)
- void pointer 와 함수 포인터 개념은 Generic Coding에 필요한 개념이므로 자유롭게 사용할 수 있어야 한다.
- scanf() 함수의 예 : scanf("%d %lf", &num, &dnum);
위와 같이 함수 호출 시 전달인자로 어떤 데이터 타임이 들어올 지 명확하게 정해지지 않은 함수를
구현할 때 void 포인터의 개념을 사용할 수 있다.
*/

#include <stdio.h>

int main()
{
	void *p;
	int a = 7;
	int intArray[5] = { 1, 2, 3, 4, 5 };
	double doubleArray[2][3] = { {1.5, 2.5, 3.5}, {4.5, 5.5, 6.5} };
	char *charPtrArray[4] = { "apple", "pear", "banana", "pineApple" };
	
	int res1, res2;
	double dres1, dres2;



	/*	void pointer -> integer	*/
	p = &a;
	*(int *)p = 10;
	printf("%d\n", *(int *)p);



	/* void pointer -> integer Array	*/
	p = intArray;

	res1 = *((int *)p + 1);			// 포인터 표현
	printf("res : %d\n", res1);

	res2 = ((int *)p)[2];			// 배열 표현
	printf("res : %d\n", res2);



	/*	void pointer -> 2D double Array	*/
	p = doubleArray;

	dres1 = *(*((double(*)[3])p + 1) + 2);		// 포인터 표현
	printf("res : %lf\n", dres1);

	dres2 = ((double(*)[3])p)[1][2];			// 배열 표현
	printf("res : %lf\n", dres2);

	printf("%lf\n", *(*((double (*)[3])p)+2));	// 포인터 표현
	printf("%lf\n", ((double (*)[3])p)[0][2]);	// 배열 표현
	
	printf("%lf\n", **(double(*)[3])p);
	printf("%lf\n", *(*((double(*)[3])p)+1));
	printf("%lf\n", **((double (*)[3])p+1));

	printf("%lf\n", ((double (*)[3])p)[0][0]);
	printf("%#x\n", (unsigned int)((double(*)[3])p)[1]);



	/*	void pointer -> pointer Array	*/
	p = charPtrArray;

	printf("%s\n", *((char **)p + 2));
	printf("%s\n", ((char **)p)[2]);

	printf("%c\n", ((char **)p)[1][2]);
	printf("%c\n", *(*((char **)p+1)+2));

	return 0;
}