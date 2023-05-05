#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 16

typedef struct {
	int x;
	int y;
} point;

// 직선거리 반환
double distance(point a, point b) { return sqrt(pow((a.x - b.x), 2.0) + pow((a.y - b.y), 2.0)); }
// 분할 후 최근접 쌍 찾기
void merge(point A[], int left, int right);
// x좌표 기준으로 정렬 ( x좌표 같을 시 y좌표 기준 )
void quick(point A[], int left, int right);
// 최솟값 및 최솟값 좌표
void who_min(point temp[], int size);

// 최솟값 저장하는 전역변수
double min = -1.0;
// 최솟값 좌표
point min_p[2];

// (10, 15), (5, 15), (20, 3), (6, 1), (9, 7), (15,9), (8, 15), (20, 14)
// (17, 13), (16, 11), (7, 12), (10, 10), (1, 19), (8, 8),(30, 9), (22, 4)
int main() {

	point A[16] = { {10, 15},{5, 15},{20, 3},{6, 1},{9, 7},{15, 9},{8, 15},{20, 14}, 
					{17, 13}, {16, 11}, {7, 12}, {10, 10}, {1, 19}, {8, 8}, {30, 9}, {22, 4} };

	for (int i = 0; i < MAX_SIZE; i++) {
		if (i == 8) printf("\n");
		printf("[%d %d] ", A[i].x, A[i].y);
	}
	printf("\n\n");

	quick(A, 0, MAX_SIZE);

	for (int i = 0; i < MAX_SIZE; i++) {
		if (i == 8) printf("\n");
		printf("[%d %d] ", A[i].x, A[i].y);
	}
	printf("\n\n");

	merge(A, 0, MAX_SIZE - 1);

	printf("%.2f의 거리로 [%d %d]와 [%d %d]의 거리가 제일 적다.", min, min_p[0].x, min_p[0].y, min_p[1].x, min_p[1].y);

	return 0;
}

void quick(point A[], int left, int right) {
	if (left < right) {
		int p = (left + right) / 2;


		point temp = A[right - 1];
		A[right - 1] = A[p];
		A[p] = temp;

		int i, j = left;

		for (i = left; i < right; i++) {
			if (A[i].x < A[right - 1].x) { // i번째 x좌표가 피벗의 x좌표보다 작을 경우
				temp = A[j];
				A[j++] = A[i];
				A[i] = temp;
			}
			else if(A[i].x == A[right - 1].x && A[i].y < A[right - 1].y) { // x좌표는 같으나 y좌표가 다를 경우
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
		quick(A, j + 1, right); // 오른쪽
	}
}

void merge(point A[], int left, int right) {
	int p_size = right - left + 1;
	point temp[3];
	if ( 2 == p_size) {
		temp[0] = A[left];
		temp[1] = A[left + 1];
		who_min(temp, 2);
		return;
	}
	else if (3 == p_size) {
		for (int i = 0; i < 3; i++) temp[i] = A[left + i];
		who_min(temp, 3);
		return;
	}
	else if (3 < p_size) {
		int p = (right - left) / 2 + left;
		point temp[MAX_SIZE];
		int j = 0;
		int check_l = A[p].x - (int)min;
		int check_r = A[p].x + (int)min;

		merge(A, left, p);
		merge(A, p + 1, right);

		// 최솟값 기준으로 중간 영역 확인
		for (int i = left; i < p; i++) if (check_l <= A[i].x) temp[j++] = A[i];
		for (int i = p; i < right; i++) if (check_l >= A[i].x) temp[j++] = A[i];

		if (j > 0) { 
			temp[j++] = min_p[0];
			temp[j] = min_p[1];

			merge(temp, 0, j-1);
		}
	}
}

void who_min(point temp[], int size) {
	double check;
	if (size == 2) {
		check = distance(temp[0], temp[1]); // 제일 작은 경우
		if (min < check && min != -1.0) return;
		min = check;
		min_p[0] = temp[0];
		min_p[1] = temp[1];
	}
	else {
		double dis[3]; // 3개의 직선거리 저장

		for (int i = 0; i < size; i++) { // 3개의 직선거리 구하기
			if (i == 2) dis[i] = distance(temp[i], temp[0]);
			else dis[i] = distance(temp[i], temp[i + 1]);
		}

		// 젤 작은 거리 저장
		check = dis[0] < dis[1] ? dis[0] : dis[1];
		check = check < dis[2] ? check : dis[2];

		if (min != -1.0 && min < check) return;
		min = check;

		// 젤 작은 거리 점들 저장
		for (int i = 0; i < 3; i++) { // 3개의 직선거리 구하기
			if (min == dis[i]) {
				if (i == 2) min_p[0] = temp[i], min_p[1] = temp[0];
				else min_p[0] = temp[i], min_p[1] = temp[i + 1];
			}
		}
	}
}