#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

int A[MAX_SIZE];

void merge(int left, int right);

int main() {
	srand(time(NULL));

	for (int i = 0; i < MAX_SIZE; i++) A[i] = rand()%100 + 1;

	for (int i = 0; i < MAX_SIZE; i++) printf("%d ", A[i]);
	printf("\n");

	merge(0, MAX_SIZE-1);


	printf("\n");
	for (int i = 0; i < MAX_SIZE; i++) printf("%d ", A[i]);
	printf("\n");

	return 0;
}

void merge(int left, int right) {
	if (left < right) {
		int p = (right - left) / 2 + left;
		int t_size = right - left + 1;
		int temp[MAX_SIZE+1];
		int a = left, b = p+1;
		
		merge(left, p);
		merge(p + 1, right);

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

void swap(int a, int b) {

}