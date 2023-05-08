#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} point;

// 데이터 읽기 ( 동적 배열 )
int read_file(point** mp);
// 직선거리 반환
double distance(point a, point b) { return sqrt(pow((a.x - b.x), 2.0) + pow((a.y - b.y), 2.0)); }
// 분할 후 최근접 쌍 찾기
void merge(point* A, int left, int right, int size, bool loop);
// x좌표 기준으로 정렬 ( x좌표 같을 시 y좌표 기준 )
void quick(point* A, int left, int right);
// 최솟값 및 최솟값 좌표
void who_min(point temp[], int size);

// 최솟값 저장하는 전역변수
double min = -1.0;
// 최솟값 좌표
point min_p[2];

// (10, 15), (5, 15), (20, 3), (6, 1), (9, 7), (15,9), (8, 15), (20, 14)
// (17, 13), (16, 11), (7, 12), (10, 10), (1, 19), (8, 8),(30, 9), (22, 4)
int main() {

    point* p = (point*)malloc(sizeof(point));

    int size = read_file(&p);

    for (int i = 0; i < size; i++) {
        if (i == 8) printf("\n");
        printf("[%d %d] ", (p + i)->x, (p + i)->y);
    }
    printf("\n\n");

    quick(p, 0, size);

    for (int i = 0; i < size; i++) {
        if (i == 8) printf("\n");
        printf("[%d %d] ", (p + i)->x, (p + i)->y);
    }
    printf("\n\n");

    merge(p, 0, size - 1, size, false);
    free(p);
    printf("%.2f의 거리로 [%d %d]와 [%d %d]의 거리가 제일 적다.", min, min_p[0].x, min_p[0].y, min_p[1].x, min_p[1].y);

    FILE* fp = fopen("result.txt", "w");
    if (fp == NULL) return 0;
    fprintf(fp, "%.2f의 거리로 [%d %d]와 [%d %d]의 거리가 제일 적다.", min, min_p[0].x, min_p[0].y, min_p[1].x, min_p[1].y);
    fclose(fp);

    return 0;
}

int read_file(point** mp) {
    FILE* fp = NULL;
    fp = fopen("test.txt", "r");
    if (fp == NULL) 0;
    point* p = NULL;
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


    p = (point*)malloc(size * 2 * sizeof(point));

    while (1) {
        fgets(temp, 10, fp);
        temp_tok = strtok(temp, " ");
        (p + i)->x = atoi(temp_tok);
        temp_tok = strtok(NULL, " ");
        (p + i++)->y = atoi(temp_tok);

        if (feof(fp)) break;
    }
    fclose(fp);


    free(*mp);
    *mp = p;
    return size;
}

void quick(point* A, int left, int right) {
    if (left < right) {
        int p = (left + right) / 2;


        point temp = *(A + right - 1);
        *(A + right - 1) = *(A + p);
        *(A + p) = temp;

        int i, j = left;

        for (i = left; i < right; i++) {
            if ((A + i)->x < (A + right - 1)->x) { // i번째 x좌표가 피벗의 x좌표보다 작을 경우
                temp = *(A + j);
                *(A + j++) = *(A + i);
                *(A + i) = temp;
            }
            else if ((A + i)->x == (A + right - 1)->x && (A + i)->y < (A + right - 1)->y) { // x좌표는 같으나 y좌표가 다를 경우
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

        quick(A, left, j); // 왼쪽
        quick(A, j + 1, right); // 오른쪽
    }
}

void merge(point* A, int left, int right, int size, bool loop) {
    int p_size = right - left + 1;
    point temp[3];
    if (2 == p_size) {
        temp[0] = *(A + left);
        temp[1] = *(A + left + 1);
        who_min(temp, 2);
        return;
    }
    else if (3 == p_size) {
        for (int i = 0; i < 3; i++) temp[i] = *(A + left + i);
        who_min(temp, 3);
        return;
    }
    else if (3 < p_size) {
        int p = (right - left) / 2 + left;
        point* temp = (point*)malloc(size * sizeof(point));
        int j = 0;
        bool count = false;

        merge(A, left, p, size, false);
        merge(A, p, right, size, false);

        int check_l = (A + p)->x - (int)min;
        int check_r = (A + p)->x + (int)min;

        // 최솟값 기준으로 중간 영역 확인
        for (int i = left; i <= (right == size ? right - 1 : right); i++) if (check_l <= (A + i)->x && (A + i)->x <= check_r) *(temp + j++) = *(A + i);


        if (j > 0 && loop == false) {
            for (int i = 0; i < j; i++) // 최소점 첫 번째 중복 확인
                if ((temp + i)->x == min_p[0].x && (temp + i)->y == min_p[0].y) continue;
                else count++;
            if (j == count) *(temp + j++) = min_p[0];

            count = 0;
            for (int i = 0; i < j; i++) // 최소점 두 번째 중복 확인
                if ((temp + i)->x == min_p[1].x && (temp + i)->y == min_p[1].y) continue;
                else count++;
            if (j == count) *(temp + j++) = min_p[1];

            merge(temp, 0, j - 1, j, true);
        }
        free(temp);
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
    else if (size == 3) {
        double dis[3] = { 0 }; // 3개의 직선거리 저장

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