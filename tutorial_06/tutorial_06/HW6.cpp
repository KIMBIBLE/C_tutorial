#include <stdio.h>


double inputFahrenheit();
double transferDegreeFToC(double fahrenhei);
void printCentigrade(double centigrade);


int main()
{
	double fahrenhei = 0.0;
	double centigrade = 0.0;

	fahrenhei = inputFahrenheit();
	centigrade = transferDegreeFToC(fahrenhei);
	printCentigrade(centigrade);

	return 0;
}


///	<summary>
///	화씨 온도 입력 함수
///	</summary>
///	<returns wonCnt>double type 화씨 온도</returns>
double inputFahrenheit() {
	double fahrenhei = 0.0;

	printf("화씨 온도를 입력하세요 : ");
	scanf("%lf", &fahrenhei);

	return fahrenhei;
}

///	<summary>
///	화씨 온도 -> 섭씨 온도 변환 함수
///	</summary>
///	<returns wonCnt>double type 화씨 온도</returns>
double transferDegreeFToC(double fahrenhei) {
	double centigrade = 0.0;

	centigrade = 5.0 / 9.0 * (fahrenhei - 32.0);

	return centigrade;
}

///	<summary>
///	변환된 섭씨 온도 출력 함수 (소숫점 이하 첫째자리까지)
///	</summary>
///	<parm name="centigrade"> 변환된 섭씨 온도
void printCentigrade(double centigrade) {
	printf("섭씨 온도는 %.1lf도 입니다.\n", centigrade);
}