#include <stdio.h>

int main()
{
	int i;
	for (i = 1; i <= 100; i++) {
		if ((i % 3) == 0 && (i % 5) != 0) {
			printf("%3c", '*');
		}
		else if ((i % 3) != 0 && (i % 5) == 0) {
			printf("%3c", '#');
		}
		else {
			printf("%3d", i);
		}

		//10개 단위 개행
		if ((i % 10) == 0) {
			printf("\n");
		}
	}
	return 0;
}