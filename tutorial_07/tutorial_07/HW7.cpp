#include <stdio.h>


double inputDistance();
double inputSpeed();
double calcTime(double distance, double speed);
void printTime(double distance, double time);


int main()
{
	double distance = 0.0;
	double speed = 0.0;
	double time = 0.0;

	distance = inputDistance();
	speed = inputSpeed();
	time = calcTime(distance, speed);
	printTime(distance, time);

	return 0;
}


///	<summary>
///	����Ÿ� �Է� �Լ� (���� :km)
///	</summary>
///	<returns distance>����Ÿ�</returns>
double inputDistance() {
	double distance = 0.0;

	printf("* �Ÿ��� �Է��Ͻÿ�(km����) : ");
	scanf("%lf", &distance);

	return distance;
}

///	<summary>
///	�ü� �Է� �Լ� (���� : km/h)
///	</summary>
///	<returns speed>�ü�</returns>
double inputSpeed() {
	double speed = 0.0;

	printf("* �ü��� �Է��Ͻÿ�(km/h����) : ");
	scanf("%lf", &speed);

	return speed;
}

///	<summary>
///	����ð� ��� �Լ�
///	</summary>
///	<parm name="distance"> ����Ÿ�
///	<parm name="speed"> �ü�
///	<returns time>����ð�</returns>
double calcTime(double distance, double speed) {
	double time = 0.0;

	time = distance / speed;

	return time;
}

///	<summary>
///	����ð� ��� �Լ�(��, ��, ��)
///	</summary>
///	<parm name="distance"> ����Ÿ�
///	<parm name="time"> ����ð�
void printTime(double distance, double time) {
	int hour = 0;
	int min = 0;
	double sec = 0.0;

	//��ü �ð� => ��, ��, �� ��ȯ �κ�
	hour = (int)time;
	time -= hour;

	time *= 60;
	min = (int)time;
	time -= min;

	time *= 60;
	sec = time;

	printf("%.2lf km = >%d�ð� %d�� %.3lf �� �ҿ��\n",
		distance, hour, min, sec);
}