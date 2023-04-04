#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "euclid.h"

// 1���� 100�� ������ ������ ���� �ִ� �׽�Ʈ ���̽�
void TC() {
	srand(time(NULL));
	double start, finish; // ����ð� üũ
	start = clock();

	for (int i = 0; i < 100000; i++) {
		// 1���� 1�� ������ ���� 1���� 1000 ������ ���� ���� ���� �ش�.
		long long int a = (rand() % 100000000 + 1) * (rand() % 1000 + 1);
		long long int b = (rand() % 100000000 + 1) * (rand() % 1000 + 1);

		// �� ����� ���� ���� �´��� Ȯ��
		if (euclidRecursive(a, b) != euclidRepeat(a, b)) {
			printf("Error �� ����� ���� �ٸ��ϴ�. %lld %lld,", a, b); // ������ Ȯ���� ���� a, b
			exit(1);
		}
	}

	finish = clock();
	printf("%f ms �ɷȽ��ϴ�.", finish - start);
}
