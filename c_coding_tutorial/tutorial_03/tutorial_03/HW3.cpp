#include <stdio.h>

int main()
{
	int totalTime = 54321;	//���� : ��(sec)
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

	printf("%d �ʴ� %d �ð� %d�� %d �� �Դϴ�.\n", totalTime, timeHour, timeMin, timeSec);

	return 0;
}