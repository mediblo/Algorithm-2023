#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "euclid.h"

// 1부터 100억 사이의 랜덤한 값을 주는 테스트 케이스
void TC() {
	srand(time(NULL));
	double start, finish; // 실행시간 체크
	start = clock();

	for (int i = 0; i < 100000; i++) {
		// 1에서 1억 사이의 값과 1에서 1000 사이의 값을 곱한 값을 준다.
		long long int a = (rand() % 100000000 + 1) * (rand() % 1000 + 1);
		long long int b = (rand() % 100000000 + 1) * (rand() % 1000 + 1);

		// 두 방법의 리턴 값이 맞는지 확인
		if (euclidRecursive(a, b) != euclidRepeat(a, b)) {
			printf("Error 두 방법의 값이 다릅니다. %lld %lld,", a, b); // 추후의 확인을 위한 a, b
			exit(1);
		}
	}

	finish = clock();
	printf("%f ms 걸렸습니다.", finish - start);
}
