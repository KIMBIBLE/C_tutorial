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
///	10진 정수 입력 함수
///	</summary>
///	<returns num>입력받은 10진 정수</returns>
int inputIntNum() {
	int num = 0;

	printf("정수값을 입력하세요 : ");
	scanf("%d", &num);

	return num;
}

///	<summary>
///	10진 정수를 8, 16 진수 형태로 출력
///	</summary>
///	<parm name="num"> 10진 정수
void printNum(int num) {
	printf("입력된 값은 8진수로 %#o 입니다.\n", num);
	printf("입력된 값은 16진수로 %#X 입니다.\n", num);
}