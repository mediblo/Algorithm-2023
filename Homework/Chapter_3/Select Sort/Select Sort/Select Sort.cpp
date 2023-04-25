#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int quick(int A[], int left, int right, int find);

#define MAX_SIZE 10


int main() {
	int ret_num = 4;
	int ret = 0;
	int A[MAX_SIZE];
	char num[MAX_SIZE];
	FILE* fp = NULL;

	fp = fopen("test.txt", "r");

	if (fp == NULL) return 0;

	for (int i = 0; i < MAX_SIZE; i++) {
		fgets(num, MAX_SIZE, fp);
		A[i] = atoi(num);
	}
	fclose(fp);

	for (int i = 0; i < MAX_SIZE; i++) printf("%d ", A[i]);
	printf("\n");

	ret = quick(A, 0, MAX_SIZE, ret_num);

	for (int i = 0; i < MAX_SIZE; i++) printf("%d ", A[i]);
	printf("\n");

	printf("%d번째 : %d", ret_num, ret);

	return 0;
}

int quick(int A[], int left, int right, int find) {
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

		if (j + 1 > find) ret = quick(A, left, j, find); // 왼쪽
		else if (j + 1 < find) ret = quick(A, j + 1, right, find); // 오른쪽
		else if (j + 1 == find) return A[find - 1];
	}
	return ret;
}