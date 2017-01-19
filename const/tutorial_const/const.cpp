/*
const : 변수 선언 시 데이터형 앞에 const 명령어를 붙여서 변수에게 상수(const)의 성격을 부여한다.
이때, const로 선언된 변수는 상수처럼 사용한다. (읽기 전용변수)

(특징)
- const 변수는 반드시 선언문에서만 초기화가 가능하다.
- 초기화 이후에는 실행문에서 그 값을 변경할 수 없다.

(const 예)
1. 변수가 const인 경우
2. 포인터에 const를 사용할 경우
- case 1 : 포인터의 대상의 상수화
- case 2 : 포인터 변수 자체의 상수화
*/

#include <stdio.h>

int main()
{
	/*	const 변수	*/
	{
		double b;
		const double pi = 3.14;
		// double 형 변수 할당 -> 대입 -> 변수의 const화	

		printf("%lf", pi);
		printf("%lf", pi + 1);
		// printf("%lf", pi++); //(X)
		b = pi;
		//pi = 3.141592;	//(X)
	}


	/*	const pointer	*/
	/*	case 1 : 포인터 대상의 상수화	*/
	{
		const int *p;
		int abc = 7;
		p = &abc;
		// *p -= 10;	//(X)
		abc -= 10;
	}

	/*	case 2 : 포인터 변수의 상수화	*/
	{
		int abc[3] = { 10, 20, 30 };
		int * const p = abc;
		// 1) int *p에 해당하는 메모리 할당
		// 2) 대입(초기화)
		// 3) const 화

		printf("%d\n", *p);
		printf("%d\n", ++*p);
		// printf("%d\n", *++p);	//(X)
	}

	// const 활용
	{
		int a = 7;

		const int *p = &a;
		int const *p = &a;
		int *const p = &a;
		const int *const p = &a;
	}

	return 0;
}