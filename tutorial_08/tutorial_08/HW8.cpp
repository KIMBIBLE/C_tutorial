#include <stdio.h>

int main()
{
	int historyScore = 0;
	int literatureScore = 0;
	int artScore = 0;

	int totalScore = 0;
	double averageScore = 0.0;

	printf("����, ����, ���� ������ �Է��ϼ��� : ");
	scanf("%d %d %d", &historyScore, &literatureScore, &artScore);

	totalScore = historyScore + literatureScore + artScore;
	averageScore = totalScore / 3.0;

	printf("������ %d �̰� ����� %.2lf �Դϴ�.\n", totalScore, averageScore);

	return 0;
}