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

	printf("�칰�� ���̸� �Է��Ͻÿ�(cm����) : ");
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
	printf("%.2lf���� ������ �칰�� Ż���ϱ� ���ؼ��� %d���� �ɸ��ϴ�.\n", depth/100.0, day);
}