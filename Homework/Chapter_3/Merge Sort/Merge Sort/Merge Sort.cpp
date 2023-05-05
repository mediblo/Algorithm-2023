#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void merge(int A[], int left, int right);

int main() {

	FILE* fp = NULL;
	char num[MAX_SIZE];
	int A[MAX_SIZE];

	fp = fopen("test.txt", "r"); // 파일 불러오기
	if (fp == NULL) return 0;

	for (int i = 0; i < MAX_SIZE; i++) { // 문자열 -> 정수 변환
		fgets(num, MAX_SIZE, fp);
		A[i] = atoi(num);
	}
	fclose(fp);

	for (int i = 0; i < MAX_SIZE; i++) printf("%d ", A[i]); // 변경 전
	printf("\n");
	merge(A, 0, MAX_SIZE-1);


	printf("\n");
	for (int i = 0; i < MAX_SIZE; i++) printf("%d ", A[i]); // 변경 후
	printf("\n");

	

	return 0;
}

void merge(int A[], int left, int right) {
	if (left < right) {
		int p = (right - left) / 2 + left;
		int t_size = right - left + 1;
		int temp[MAX_SIZE+1];
		int a = left, b = p+1;

		merge(A, left, p);
		merge(A, p + 1, right);

		for (int i = 0; i < t_size; i++) {
			
			if (a == p + 1) // 왼쪽 인덱스 다 돌면
			{
				temp[i] = A[b++];
				continue;
			}
			if (A[a] < A[b] || b > right) temp[i] = A[a++]; // 왼쪽 넣기
			else temp[i] = A[b++]; // 오른쪽 넣기
		}

		for (int i = 0, a=left; i < t_size; i++, a++) A[a] = temp[i]; // 임시배열에서 진짜 배열로 데이터 옮기기
	}
}