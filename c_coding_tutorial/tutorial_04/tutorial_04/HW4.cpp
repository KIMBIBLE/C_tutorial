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

	// dTotalTimeTemp : day -> hour ���� ��ȯ
	dTotalTimeTemp *= 24;
	timeHour = (int)dTotalTimeTemp;
	dTotalTimeTemp -= timeHour;

	// dTotalTimeTemp : hour -> Minuate ���� ��ȯ
	dTotalTimeTemp *= 60;
	timeMinuate = (int)dTotalTimeTemp;
	dTotalTimeTemp -= timeMinuate;

	// dTotalTimeTemp : Minuate -> Second ���� ��ȯ
	dTotalTimeTemp *= 60;
	timeSecond = dTotalTimeTemp;

	printf("%.4lf���� %d�� %d�ð� %d�� %.2lf���Դϴ�..\n", 
		dTotalTime, timeDay, timeHour,timeMinuate, timeSecond);

	return 0;
}