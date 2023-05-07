﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick(int* A, int left, int right, int size);
int read_file(int** mp);

int main() {
	FILE* fp = NULL;

	int* p = (int*)malloc(sizeof(int));
	int size = read_file(&p);

	for (int i = 0; i < size; i++) printf("%d ", *(p + i));
	printf("\n");

	quick(p, 0, size, size);

	for (int i = 0; i < size; i++) printf("%d ", *(p + i));
	printf("\n");

	fp = fopen("result.txt", "w");
	if (fp == NULL) return 0;

	for (int i = 0; i < size; i++) {
		fprintf(fp, "%d ", *(p + i));
	}
	fclose(fp);
	free(p);

	return 0;
}

void quick(int* A, int left, int right, int size) {
	if (left < right) {
		int p = (left + right) / 2;

		int temp = *(A + right - 1);
		*(A + right - 1) = *(A + p);
		*(A + p) = temp;

		int i, j = left;

		for (i = left; i < right; i++) {
			if (*(A + i) < *(A + right - 1)) { // i번째가 피벗 숫자보다 작을 경우
				temp = *(A + j);
				*(A + j++) = *(A + i);
				*(A + i) = temp;
			}
		}

		if (j <= right - 1) {
			temp = *(A + j);
			*(A + j) = *(A + right - 1);
			*(A + right - 1) = temp;
		}

		quick(A, left, j, size); // 왼쪽
		quick(A, j + 1, right, size); // 오른쪽
	}
}

int read_file(int** mp) {
	FILE* fp = NULL;
	fp = fopen("test.txt", "r");
	if (fp == NULL) 0;
	int* p = NULL;
	char temp[10];
	char* temp_tok = NULL;
	int size = 0;
	int i = 0;

	while (1) {
		fgets(temp, 10, fp);
		size++;
		if (feof(fp)) break;
	}
	fseek(fp, 0, SEEK_SET); // 갯수 세기

	p = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++)
		fscanf(fp, "%d", (p + i));
	fclose(fp);

	free(*mp);
	*mp = p;
	return size;
}