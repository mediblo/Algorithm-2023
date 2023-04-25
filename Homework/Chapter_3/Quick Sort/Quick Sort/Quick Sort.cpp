#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void quick(int A[], int left, int right);

#define MAX_SIZE 10

int main() {
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

	quick(A, 0, MAX_SIZE);

	for (int i = 0; i < MAX_SIZE; i++) printf("%d ", A[i]);
	printf("\n");

	return 0;
}

void quick(int A[], int left, int right) {
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

		quick(A, left, j); // 왼쪽
		quick(A, j+1, right); // 오른쪽
	}
}