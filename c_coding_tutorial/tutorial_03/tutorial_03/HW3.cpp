#include <stdio.h>

int main()
{
	int totalTime = 54321;	//단위 : 초(sec)
	int convertedTime;

	int timeHour;
	int timeMin;
	int timeSec;

	convertedTime = totalTime;

	timeHour = convertedTime / 3600;
	convertedTime -= timeHour * 3600;

	timeMin = convertedTime / 60;
	convertedTime -= timeMin * 60;

	timeSec = convertedTime;

	printf("%d 초는 %d 시간 %d분 %d 초 입니다.\n", totalTime, timeHour, timeMin, timeSec);

	return 0;
}