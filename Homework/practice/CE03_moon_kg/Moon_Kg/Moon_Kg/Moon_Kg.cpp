#include <stdio.h>

#pragma warning(disable : 4996)

int main() {
	int kg;

	printf("몸무게를 입력하세요(단위 : kg) : ");
	scanf("%d", &kg);

	printf("달에서의 몸무게는 %.2fkg입니다.", (float)kg * 0.17);
	return 0;
}