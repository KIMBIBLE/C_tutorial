#include <stdio.h>

int inputYear();
int yearCheck(int year);
void outputCheckResult(int year, int flag);

int main()
{
	int year;
	int flag;

	year = inputYear();
	flag = yearCheck(year);
	outputCheckResult(year, flag);

	return 0;
}

/*
	기능 : 사용자로부터 연도를 입력받음.
	return : year (입력받은 연도)
*/
int inputYear() {
	int year;

	printf("년도를 입력하시오 : ");
	scanf("%d", &year);

	return year;
}

/*
	기능 : 연도의 윤, 평년 체크
	parm1 : year
	return : (평년 : 0, 윤년 : 1)
*/
int yearCheck(int year) {
	if (year % 4 != 0)
		return 0;

	if (year % 100 != 0)
		return 1;
	
	if (year % 400)
		return 1;
	else
		return 0;	
}

/*
	기능 : 연도의 윤,평년 변환 결과 출력
	parm1 : year (입력받은 연도)
	parm2 : flag (평년 : 0, 윤년 : 1)
*/
void outputCheckResult(int year, int flag) {
	if (flag == 0)
		printf("%d년은 평년(Common year)입니다.\n", year);
	else// flag == 0
		printf("%d년은 윤년(Leap year)입니다.\n", year);
}