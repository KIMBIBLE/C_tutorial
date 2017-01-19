#include <stdio.h>

int inputUsed();
void printUsageFee(double totalFeeAfterTax);

int main()
{
	double basicRate = 660.0;	//���� : ��
	double kwPerFee = 88.5;	//���� : ��
	double totalFeeBeroreTax = 0.0;	//���� : ��
							//�⺻��� + (��뷮 * kw �� ��� ���)
	double taxRate = 0.09;		//���� : %
							//0.01%
						//��ü����� 9%
	double tax = 0.0;	//���� : ��
	double totalFeeAfterTax = 0.0;	//���� : ��
							//��ü ��� + ����
	int usedAmount;	//���� : kw


	usedAmount = inputUsed();

	totalFeeBeroreTax = basicRate + usedAmount * kwPerFee;
	tax = totalFeeBeroreTax * taxRate;
	totalFeeAfterTax = totalFeeBeroreTax + tax;

	printUsageFee(totalFeeAfterTax);


	return 0;
}


///	<summary>
///	���� ��뷮 �Է� �Լ�(���� : kw)
///	</summary>
///	<returns usedAmount>���� ��뷮(���� : kw)</returns>
int inputUsed() {
	int usedAmount;

	printf("���� ��뷮�� �Է��ϼ���(kw) : ");
	scanf("%d", &usedAmount);

	return usedAmount;
}


///	<summary>
///	��� ��� ��� �Լ�(���� : double type ��)
///	</summary>
///	<parm name="totalFeeAfterTax"> ���� ��뷮(���� : kw)
void printUsageFee(double totalFeeAfterTax) {
	printf("���� ��뷮�� %lf�� �Դϴ�.\n", totalFeeAfterTax);
}
