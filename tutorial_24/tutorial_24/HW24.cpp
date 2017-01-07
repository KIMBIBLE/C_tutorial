#include <stdio.h>

int inputDepth();
int calcEscapeDay(int depth);
void printOutput(int depth, int day);

int main()
{
	int depth, day;

	depth = inputDepth();
	day = calcEscapeDay(depth);
	printOutput(depth, day);

	return 0;
}

int inputDepth() {
	int depth;

	printf("우물의 깊이를 입력하시오(cm단위) : ");
	scanf("%d", &depth);

	return depth;
}
int calcEscapeDay(int depth) {
	int day = 0;

	if (depth == 0)	
		return day;

	while (1) {
		depth -= 50;
		day++;
		if (depth <= 0) 
			break;
			
		depth += 20;
	}
	
	return day;
}
void printOutput(int depth, int day) {
	printf("%.2lf미터 깊이의 우물을 탈출하기 위해서는 %d일이 걸립니다.\n", depth/100.0, day);
}