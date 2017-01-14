#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH  13 /* 주민등록번호 길이*/

int availabilityCheck(char *resident_number);
int checkLengthCharacter(char *resident_number);
int checkDate(char *resident_number);
int checkIdentification(char *resident_number);
int checkGender(char *resident_number);
int checkYear(int year);
int getMonthMax(int year, int month);
int parseYear(char* resident_number);
int parseMonth(char* resident_number);
int parseDay(char* resident_number);

int main()
{
	/* 테스트할 주민등록번호 저장 배열*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
		"0003154194917", "801203#201122", "7804155328845", "7804150328840",
		"9612241068382", "9902292194322", "0230174326176", "8811391042219",
		"8100122042213", "8112002042213", "9210101069415", "0802294012345",
		"8806311069417","8807311069418" };
	int i, count;
	/* 검사할 주민등록번호의 개수 계산*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);
	for (i = 0; i<count; i++) /* 주민등록번호 유효성 검사를 반복적으로 수행 함*/
	{
		if (availabilityCheck(resident_number[i]) == TRUE)
		{
			printf("(+) 주민번호%s는(은) 유효한 번호입니다.\n", resident_number[i]);
		}
		else
		{
			printf("(-) 주민번호%s는(은) 유효하지 않은 번호입니다.\n", resident_number[i]);
		}
	}
	return 0;
}


/*----------------------------------------------------------------
availabilityCheck()함수: 주민등록번호 유효성 검사 함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 유효하면TRUE, 유효하지 않으면FALSE 리턴
------------------------------------------------------------------*/
int availabilityCheck(char *resident_number) {
	if (!checkLengthCharacter(resident_number)) { return FALSE; }
	if (!checkDate(resident_number)) { return FALSE; }
	if (!checkGender(resident_number)) { return FALSE; }
	if (!checkIdentification(resident_number)) { return FALSE; }

	return TRUE;
}

/*-------------------------------------------------------------------------
checkLengthCharacter()함수: 주민등록번호 길이 및 문자 유효성검사 함수
전달인자: 검사할 주민등록번호(문자열)
리턴값: 주민등록번호의 길이가 맞고 숫자문자로만 구성되어 있으면TRUE,
길이가 짧거나 길고, 숫자 문자가 아닌 문자가 섞여 있으면FALSE 리턴
--------------------------------------------------------------------------*/
int checkLengthCharacter(char *resident_number) {
	int i;
	int len;
	len = strlen(resident_number);

	if (len != 13) { return FALSE; }
	for (i = 0; i < len; i++) {
		if (resident_number[i] <'0' || resident_number[i] > '9') {
			return FALSE;
		}
	}

	return TRUE;
}

/*----------------------------------------------------------------
checkDate()함수: 첫6자리(연,월,일)의 유효성 검사 함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 유효한 날짜이면TRUE, 유효하지 않은 날짜이면FALSE 리턴
------------------------------------------------------------------*/
int checkDate(char *resident_number) {
	int year;
	int month;
	int day;

	// 주민등록번호에서 연,월,일 추출
	year = parseYear(resident_number);
	month = parseMonth(resident_number);
	day = parseDay(resident_number);

	// 날짜 데이터 입력의 유효성 검사(연,월 -> 일)
	if (1 <= month && month <= 12) {
		if (1 <= day && day <= getMonthMax(year, month)) { return TRUE; }
	}

	return FALSE;
}


/*----------------------------------------------------------------------
checkGender()함수: 7번째 자리의 성별식별번호 유효성 검사함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 성별식별번호가'1'~'4'이면TRUE, 그 외 숫자 문자이면FALSE 리턴
-----------------------------------------------------------------------*/
int checkGender(char *resident_number) {
	if ('1' <= resident_number[6] && resident_number[6] <= '4') {
		return TRUE;
	}

	return FALSE;
}


/*------------------------------------------------------------------------
checkIdentification()함수: 주민등록번호 끝자리(인식자) 유효성 검사 함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 유효한 인식자이면TRUE, 유효하지 않은 인식자이면 FALSE 리턴
-------------------------------------------------------------------------*/
int checkIdentification(char *resident_number) {
	int i;
	int check = 0; 
	int len;

	len = strlen(resident_number);
	for (i = 0; i < len - 1; i++) {
		check += resident_number[i] - '0';
	}
	check %= 10;

	if (check == resident_number[i] - '0') {
		return TRUE;
	}
	
	return FALSE;
}


/*----------------------------------------------------------------
checkYear ()함수: 년도의 윤,평년 여부 검사
전달인자: 윤,평년 검사할 년도
리턴값: 윤년이면 TRUE, 평년이면FALSE 리턴
------------------------------------------------------------------*/
int checkYear(int year) {
	if (year % 4 != 0) {
		return FALSE;
	}

	if (year % 100 != 0) {
		return TRUE;
	}

	if (year % 400 == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}

}


// 기능 : 전달인자로 받은 year, month를 통해 해당 년,월의 최대 날짜 리턴 
int getMonthMax(int year, int month) {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	//2월의 경우 윤평년 검사. 윤년 : 29일, 평년 :28일
	else if (month == 2) {
		if (checkYear(year)) { return 29; }	//윤년
		else { return 28; }	//평년
	}
	else {	//month = 1,3,5,7,8,10,12
		return 31;
	}
}


/*----------------------------------------------------------------
parseYear ()함수: 주민등록번호에서 연도 추출
전달인자: 주민등록번호 배열
리턴값: 추출한 연도
------------------------------------------------------------------*/
int parseYear(char* resident_number) {
	int year = 0;

	if (resident_number[0] == '0') {
		year += 2000;
	}
	else {
		year += 1900;
	}

	year += (resident_number[0] - '0') * 10;
	year += (resident_number[1] - '0');

	return year;
}


/*----------------------------------------------------------------
parseMonth ()함수: 주민등록번호에서 월 추출
전달인자: 주민등록번호 배열
리턴값: 추출한 연도
------------------------------------------------------------------*/
int parseMonth(char* resident_number) {
	int month = 0;

	month += (resident_number[2] - '0') * 10;
	month += resident_number[3] - '0';

	return month;
}


/*----------------------------------------------------------------
parseMonth ()함수: 주민등록번호에서 일 추출
전달인자: 주민등록번호 배열
리턴값: 추출한 연도
------------------------------------------------------------------*/
int parseDay(char* resident_number) {
	int day = 0;

	day += (resident_number[4] - '0') * 10;
	day += resident_number[5] - '0';

	return day;
}

