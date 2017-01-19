#include <stdio.h>

int inputUsed();
void printUsageFee(double totalFeeAfterTax);

int main()
{
	double basicRate = 660.0;	//단위 : 원
	double kwPerFee = 88.5;	//단위 : 원
	double totalFeeBeroreTax = 0.0;	//단위 : 원
							//기본요금 + (사용량 * kw 당 사용 요금)
	double taxRate = 0.09;		//단위 : %
							//0.01%
						//전체요금의 9%
	double tax = 0.0;	//단위 : 원
	double totalFeeAfterTax = 0.0;	//단위 : 원
							//전체 요금 + 세금
	int usedAmount;	//단위 : kw


	usedAmount = inputUsed();

	totalFeeBeroreTax = basicRate + usedAmount * kwPerFee;
	tax = totalFeeBeroreTax * taxRate;
	totalFeeAfterTax = totalFeeBeroreTax + tax;

	printUsageFee(totalFeeAfterTax);


	return 0;
}


///	<summary>
///	전기 사용량 입력 함수(단위 : kw)
///	</summary>
///	<returns usedAmount>전기 사용량(단위 : kw)</returns>
int inputUsed() {
	int usedAmount;

	printf("전기 사용량을 입력하세요(kw) : ");
	scanf("%d", &usedAmount);

	return usedAmount;
}


///	<summary>
///	사용 요금 출력 함수(단위 : double type 원)
///	</summary>
///	<parm name="totalFeeAfterTax"> 전기 사용량(단위 : kw)
void printUsageFee(double totalFeeAfterTax) {
	printf("전기 사용량을 %lf원 입니다.\n", totalFeeAfterTax);
}
