#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int quick(int left, int right, int find);

#define MAX_SIZE 20

int A[MAX_SIZE];

int main() {
	int ret_num = 10;
	int ret = 0;
	srand(time(NULL));

	for (int i = 0; i < MAX_SIZE; i++) A[i] = rand() % 100 + 1;

	for (int i = 0; i < MAX_SIZE; i++) printf("%d ", A[i]);
	printf("\n");

	ret = quick(0, MAX_SIZE, ret_num);

	for (int i = 0; i < MAX_SIZE; i++) printf("%d ", A[i]);
	printf("\n");

	printf("%d번째 : %d", ret_num, ret);

	return 0;
}

int quick(int left, int right, int find) {
	int ret = -1;
	if (left < right) {
		int p = (left + right) / 2;


		int temp = A[right - 1];
		A[right - 1] = A[p];
		A[p] = temp;

		int i, j = left;

		for (i = left; i < right; i++) {
			if (A[i] < A[right - 1]) { // i번째가 피벗 숫자보다 작을 경우
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

		if (j + 1 > find) ret = quick(left, j, find); // 왼쪽
		else if (j + 1 < find) ret = quick(j + 1, right, find); // 오른쪽
		else if (j + 1 == find) return A[find - 1];
	}
	return ret;
}