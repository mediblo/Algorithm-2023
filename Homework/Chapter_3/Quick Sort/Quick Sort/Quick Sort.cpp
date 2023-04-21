#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick(int left, int right);

#define MAX_SIZE 20

int A[MAX_SIZE];

int main() {

	srand(time(NULL));

	for (int i = 0; i < MAX_SIZE; i++) A[i] = rand() % 100 + 1;

	for (int i = 0; i < MAX_SIZE; i++) printf("%d ", A[i]);
	printf("\n");

	quick(0, MAX_SIZE);

	for (int i = 0; i < MAX_SIZE; i++) printf("%d ", A[i]);
	printf("\n");

	return 0;
}

void quick(int left, int right) {
	if( left < right ) {
		int p = (left + right) / 2;

		int temp = A[right - 1];
		A[right - 1] = A[p];
		A[p] = temp;

		int i, j = left;

		for (i = left; i < right; i++) {
			if (A[i] < A[right-1]) { // i번째가 피벗 숫자보다 작을 경우
				temp = A[j];
				A[j++] = A[i];
				A[i] = temp;
			}
		}

		if (j <= right - 1) {
			temp = A[j];
			A[j] = A[right - 1];
			A[right - 1] = temp;
		}

		quick(left, j); // 왼쪽
		quick(j+1, right); // 오른쪽
	}
}