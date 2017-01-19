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
///	주행거리 입력 함수 (단위 :km)
///	</summary>
///	<returns distance>주행거리</returns>
double inputDistance() {
	double distance = 0.0;

	printf("* 거리를 입력하시오(km단위) : ");
	scanf("%lf", &distance);

	return distance;
}

///	<summary>
///	시속 입력 함수 (단위 : km/h)
///	</summary>
///	<returns speed>시속</returns>
double inputSpeed() {
	double speed = 0.0;

	printf("* 시속을 입력하시오(km/h단위) : ");
	scanf("%lf", &speed);

	return speed;
}

///	<summary>
///	주행시간 계산 함수
///	</summary>
///	<parm name="distance"> 주행거리
///	<parm name="speed"> 시속
///	<returns time>주행시간</returns>
double calcTime(double distance, double speed) {
	double time = 0.0;

	time = distance / speed;

	return time;
}

///	<summary>
///	주행시간 출력 함수(시, 분, 초)
///	</summary>
///	<parm name="distance"> 주행거리
///	<parm name="time"> 주행시간
void printTime(double distance, double time) {
	int hour = 0;
	int min = 0;
	double sec = 0.0;

	//전체 시간 => 시, 분, 초 변환 부분
	hour = (int)time;
	time -= hour;

	time *= 60;
	min = (int)time;
	time -= min;

	time *= 60;
	sec = time;

	printf("%.2lf km = >%d시간 %d분 %.3lf 초 소요됨\n",
		distance, hour, min, sec);
}