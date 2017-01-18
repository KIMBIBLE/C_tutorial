/*
void pointer? : ����Ű�� ���ü�� type�� ������ ���� ������

(���� ����)
void * ������ ��;

void pointer�� ������ ��ü�� �����ο쳪 �ڽ��� �������ϴ� �����
�𸣴� �����̱� ������ void ������ ��ü�� �ּ� ������ �� �� ����.
���� void pointer�� ��� �� ĳ������ �ʿ��ϴ�.

(void pointer�� ���)
- void pointer �� �Լ� ������ ������ Generic Coding�� �ʿ��� �����̹Ƿ� �����Ӱ� ����� �� �־�� �Ѵ�.
- scanf() �Լ��� �� : scanf("%d %lf", &num, &dnum);
���� ���� �Լ� ȣ�� �� �������ڷ� � ������ Ÿ���� ���� �� ��Ȯ�ϰ� �������� ���� �Լ���
������ �� void �������� ������ ����� �� �ִ�.
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

	res1 = *((int *)p + 1);			// ������ ǥ��
	printf("res : %d\n", res1);

	res2 = ((int *)p)[2];			// �迭 ǥ��
	printf("res : %d\n", res2);



	/*	void pointer -> 2D double Array	*/
	p = doubleArray;

	dres1 = *(*((double(*)[3])p + 1) + 2);		// ������ ǥ��
	printf("res : %lf\n", dres1);

	dres2 = ((double(*)[3])p)[1][2];			// �迭 ǥ��
	printf("res : %lf\n", dres2);

	printf("%lf\n", *(*((double (*)[3])p)+2));	// ������ ǥ��
	printf("%lf\n", ((double (*)[3])p)[0][2]);	// �迭 ǥ��
	
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