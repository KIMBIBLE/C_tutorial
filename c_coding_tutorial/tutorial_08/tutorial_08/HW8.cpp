#include <stdio.h>

int main()
{
	int historyScore = 0;
	int literatureScore = 0;
	int artScore = 0;

	int totalScore = 0;
	double averageScore = 0.0;

	printf("역사, 문학, 예능 점수를 입력하세요 : ");
	scanf("%d %d %d", &historyScore, &literatureScore, &artScore);

	totalScore = historyScore + literatureScore + artScore;
	averageScore = totalScore / 3.0;

	printf("총점은 %d 이고 평균은 %.2lf 입니다.\n", totalScore, averageScore);

	return 0;
}