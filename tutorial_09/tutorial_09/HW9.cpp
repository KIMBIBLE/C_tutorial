#include <stdio.h>


int inputIntNum();
void printNum(int num);


int main()
{
	int number = 0;

	number = inputIntNum();
	printNum(number);

	return 0;
}


///	<summary>
///	10�� ���� �Է� �Լ�
///	</summary>
///	<returns num>�Է¹��� 10�� ����</returns>
int inputIntNum() {
	int num = 0;

	printf("�������� �Է��ϼ��� : ");
	scanf("%d", &num);

	return num;
}

///	<summary>
///	10�� ������ 8, 16 ���� ���·� ���
///	</summary>
///	<parm name="num"> 10�� ����
void printNum(int num) {
	printf("�Էµ� ���� 8������ %#o �Դϴ�.\n", num);
	printf("�Էµ� ���� 16������ %#X �Դϴ�.\n", num);
}