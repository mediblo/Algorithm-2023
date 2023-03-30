// 랜덤한 임의 숫자 찾기

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int search_K(int A[], int cnt, int K);
void TC1();
void TC2();

int main() {
    srand(time(NULL));

    TC1();
    TC2();

    return 0;
}

// K 찾기
int search_K(int A[], int cnt, int K) {
    int ret = 0;

    for (int i = 1; i < cnt; i++)
        if (A[i] == K) {
            ret = i;
            break;
        }
    return A[ret];
}

// 테스트 케이스 1
void TC1() {
    int A[10] = { 0 };
    for (int i = 0; i < 10; i++) {
        A[i] = rand() % 100 + 1;
        printf("%d ", A[i]);
    }

    printf("\nTest Case No.1 : K is %d\n", search_K(A, 10, A[rand() % 10]));

}

// 테스트 케이스 2
void TC2() {
    int A[20] = { 0 };
    for (int i = 0; i < 20; i++) {
        A[i] = rand() % 100 + 1;
        printf("%d ", A[i]);
    }

    printf("\nTest Case No.2 : K is %d\n", search_K(A, 20, A[rand() % 20]));

}