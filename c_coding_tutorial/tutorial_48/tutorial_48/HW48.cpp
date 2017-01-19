#include <stdio.h>

void inputDay(int *pYear, int *pMonth, int *pDay);
int yearCheck(int year);
int monthMaxCheck(int year, int month);
int getTotalDay(int year, int month, int day);
void displayDate(int year, int month, int day, int totalDay);

int main()
{
	int year, month, day;
	int totalDay;

	inputDay(&year, &month, &day);
	totalDay = getTotalDay(year, month, day);
	displayDate(year, month, day, totalDay);

	return 0;
}

void inputDay(int *pYear, int *pMonth, int *pDay) {
	while (1) {
		// 정수 3개 입력 반복
		while (1) {
			printf("* 년 월 일을 입력하시오 : ");
			scanf("%d %d %d", pYear, pMonth, pDay);
			if (getchar() == '\n') { break; }
			while (getchar() != '\n') { ; }
		}

		// 날짜 데이터 입력의 유효성 검사(연,월 -> 일)
		if (*pYear >= 1900 && 1 <= *pMonth && *pMonth <= 12) {
			if (1 <= *pDay && *pDay <= monthMaxCheck(*pYear, *pMonth)) { break; }
		}
	}
}

int getTotalDay(int year, int month, int day) {
	int total = 0;
	int i, j;

	for (i = 1; i < month; i++) {	//월 : 지난달까지 daycount 누적
		total += monthMaxCheck(year, i);
	}

	for (j = 1900; j < year; j++) {
		total += yearCheck(j);
	}

	total += (year - 1900) * 365;	//년 : (1990 ~ 작년) 윤년 제외 day count 누적

	total += day;	//일 누적

	return total;
}

// 기능 : 전달인자로 받은 year, month를 통해 해당 년,월의 최대 날짜 리턴 
int monthMaxCheck(int year, int month) {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	//2월의 경우 윤평년 검사. 윤년 : 29일, 평년 :28일
	else if (month == 2) {
		if (yearCheck(year)) { return 29; }	//윤년
		else { return 28; }	//평년
	}
	else {	//month = 1,3,5,7,8,10,12
		return 31;
	}
}

// 평년 : 0, 윤년 : 1 리턴
int yearCheck(int year) {
	if (year % 4 != 0) { 
		return 0; 
	}

	if (year % 100 != 0) { 
		return 1; 
	}

	if (year % 400 == 0) { 
		return 1; 
	}
	else { 
		return 0; 
	}
}

void displayDate(int year, int month, int day, int totalDay) {
	char whatDay[][7] = { "일요일", "월요일", "화요일", "수요일", 
		"목요일", "금요일", "토요일" };

	int dayType = totalDay % 7;

	printf("%d년 %d월 %d일은 %s입니다.\n", year, month, day, whatDay[dayType]);
}