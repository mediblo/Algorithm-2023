#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int read_file(int** mp);
void merge(int* A, int left, int right, int size);

int main() {

    FILE* fp = NULL;

    int* p = (int*)malloc(sizeof(int));
    int size = read_file(&p);

    for (int i = 0; i < size; i++) printf("%d ", *(p + i)); // 변경 전
    printf("\n");
    merge(p, 0, size - 1, size);

    for (int i = 0; i < size; i++) printf("%d ", *(p + i)); // 변경 후
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

void merge(int* A, int left, int right, int size) {
    if (left < right) {
        int p = (right - left) / 2 + left;
        int t_size = right - left + 1;
        int* temp = (int*)malloc(sizeof(int) * size);
        int a = left, b = p + 1;

        merge(A, left, p, size);
        merge(A, p + 1, right, size);

        for (int i = 0; i < t_size; i++) {

            if (a == p + 1) // 왼쪽 인덱스 다 돌면
            {
                *(temp + i) = A[b++];
                continue;
            }
            if (*(A + a) < *(A + b) || b > right) *(temp + i) = *(A + a++); // 왼쪽 넣기
            else *(temp + i) = *(A + b++); // 오른쪽 넣기
        }

        for (int i = 0, a = left; i < t_size; i++, a++) *(A + a) = *(temp + i); // 임시배열에서 진짜 배열로 데이터 옮기기
        free(temp);
    }
}

int read_file(int** mp) {
    FILE* fp = NULL;
    fp = fopen("test.txt", "r");
    if (fp == NULL) 0;
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


    int* p = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        fscanf(fp, "%d", (p + i));
    fclose(fp);


    free(*mp);
    *mp = p;
    return size;
}