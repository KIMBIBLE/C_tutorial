#include <stdio.h>

int main()
{
	double dTotalTime = 365.2422;
	double dTotalTimeTemp = 0;

	int timeDay = 0;
	int timeHour = 0;
	int timeMinuate = 0;
	double timeSecond = 0.0;

	dTotalTimeTemp = dTotalTime;

	timeDay = (int)dTotalTimeTemp;
	dTotalTimeTemp -= timeDay;

	// dTotalTimeTemp : day -> hour 단위 변환
	dTotalTimeTemp *= 24;
	timeHour = (int)dTotalTimeTemp;
	dTotalTimeTemp -= timeHour;

	// dTotalTimeTemp : hour -> Minuate 단위 변환
	dTotalTimeTemp *= 60;
	timeMinuate = (int)dTotalTimeTemp;
	dTotalTimeTemp -= timeMinuate;

	// dTotalTimeTemp : Minuate -> Second 단위 변환
	dTotalTimeTemp *= 60;
	timeSecond = dTotalTimeTemp;

	printf("%.4lf일은 %d일 %d시간 %d분 %.2lf초입니다..\n", 
		dTotalTime, timeDay, timeHour,timeMinuate, timeSecond);

	return 0;
}