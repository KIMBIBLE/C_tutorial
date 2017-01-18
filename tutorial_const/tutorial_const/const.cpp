/*
const : ���� ���� �� �������� �տ� const ��ɾ �ٿ��� �������� ���(const)�� ������ �ο��Ѵ�.
�̶�, const�� ����� ������ ���ó�� ����Ѵ�. (�б� ���뺯��)

(Ư¡)
- const ������ �ݵ�� ���𹮿����� �ʱ�ȭ�� �����ϴ�.
- �ʱ�ȭ ���Ŀ��� ���๮���� �� ���� ������ �� ����.

(const ��)
1. ������ const�� ���
2. �����Ϳ� const�� ����� ���
- case 1 : �������� ����� ���ȭ
- case 2 : ������ ���� ��ü�� ���ȭ
*/

#include <stdio.h>

int main()
{
	/*	const ����	*/
	{
		double b;
		const double pi = 3.14;
		// double �� ���� �Ҵ� -> ���� -> ������ constȭ	

		printf("%lf", pi);
		printf("%lf", pi + 1);
		// printf("%lf", pi++); //(X)
		b = pi;
		//pi = 3.141592;	//(X)
	}


	/*	const pointer	*/
	/*	case 1 : ������ ����� ���ȭ	*/
	{
		const int *p;
		int abc = 7;
		p = &abc;
		// *p -= 10;	//(X)
		abc -= 10;
	}

	/*	case 2 : ������ ������ ���ȭ	*/
	{
		int abc[3] = { 10, 20, 30 };
		int * const p = abc;
		// 1) int *p�� �ش��ϴ� �޸� �Ҵ�
		// 2) ����(�ʱ�ȭ)
		// 3) const ȭ

		printf("%d\n", *p);
		printf("%d\n", ++*p);
		// printf("%d\n", *++p);	//(X)
	}

	// const Ȱ��
	{
		int a = 7;

		const int *p = &a;
		int const *p = &a;
		int *const p = &a;
		const int *const p = &a;
	}

	return 0;
}