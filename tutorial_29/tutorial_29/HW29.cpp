#include <stdio.h>\

int transNumber(int num);	//양의정수 num입력받아 각 자리수로 분할 해 곱한 결과 리턴하는 함수
int inputUint(char* message);	//양의 정수만 입력받아 리턴하는 함수(음수와 문자에 대한 입력 예외처리 필수
int display(int num, int n);

int main()
{
	//사용자 입력 값 저장 변수
	int p1, p2;//(100<=p1,p2<=10000)
	int n;	//고집수(1<=N<10)

	//other
	int num;	//p1~p2까지 고집수 계산에서 반복에 사용되는 시드값
	int calcNum;	//각 자리수 곱하기 연산에 사용되는 변수
	int cnt = 0;	//특정 숫자(num)에 대한 고집수계산에 사용되는 카운트 변수
	int sum = 0;	//고집수 총 갯수 	

	//입력
	while (1) {
		p1 = inputUint("시작 값 (P1) : ");
		if (p1 >= 100) { break; }
	}
	while (1) {
		p2 = inputUint("끝 값(P2) : ");
		if (p1 <= p2 && p2 <= 10000) { break; }
	}
	while (1) {
		n = inputUint("고집수(N) : ");
		if (1 <= n && n <= 10) { break; }
	}
	puts("\n");

	printf("고집수가 %d인 숫자 출력\n", n);
	num = p1;	//p1~ p2까지 루프 돌기 위해 초기값 p1으로 설정
	while (num <= p2) {
		//num에 대한 고집수 구하면 루프 탈출
		if (display(num, n)) {
			sum ++;
		}

		num++;
	}
	printf("총 개수 : %d개\n", sum);

	return 0;
}


// 양의정수 num입력받아 각 자리수로 분할 해 곱한 결과 리턴하는 함수
// 자릿수 분할 곱셈 1회 시행
int transNumber(int num)	
{
	int res = 1;	//자릿수 누적 곱에 사용

	if (num / 10000) {	// 자릿수 : 5인 경우
		res = 0;
	}
	else if (num / 1000) {	// 자릿수 : 4
		res *= num / 1000;	//천의자리 곱
		num %= 1000;

		res *= num / 100;	//백의자리 곱
		num %= 100;

		res *= num / 10;	//십의자리 곱

		res *= num % 10;	//일의자리 곱
	}
	else if (num / 100) {	// 자릿수 : 3
		res *= num / 100;	//백의자리 곱
		num %= 100;

		res *= num / 10;	//십의자리 곱

		res *= num % 10;	//일의자리 곱
	}
	else {	// 자릿수 : 2
		res *= num / 10;	//십의자리 곱

		res *= num % 10;	//일의자리 곱
	}

	return res;
}
int inputUint(char* message)	//양의 정수만 입력받아 리턴하는 함수(음수와 문자에 대한 입력 예외처리 필수
{
	int num;

	while (1) {
		printf("%s", message);
		scanf("%d", &num);

		if (getchar() == '\n') {
			if (num > 0) { break; }
		}
		else {
			while (getchar() != '\n') { ; }
		}
	}

	return num;
}
int display(int num, int n) {
	int calcNum;	//각 자리수 곱하기 연산에 사용되는 변수
	int cnt = 0;	//특정 숫자(num)에 대한 고집수계산에 사용되는 카운트 변수

	calcNum = num;	//num 값 보존을 위해 고집수 계산 목적의 변수를 사용
	while (1) {
		cnt++;
		calcNum = transNumber(calcNum);
		if (!(calcNum / 10)) {	//각자리수 곱 결과가 1자리이면
			break;
		}
	}

	if (cnt == n) {	//사용자 입력 고집수와 일치할 경우 '1' 리턴
		printf("%d\n", num);
		return 1;
	}

	return 0;	//사용자 입력 고집수와 일치하지 않을 경우 '0' 리턴
}