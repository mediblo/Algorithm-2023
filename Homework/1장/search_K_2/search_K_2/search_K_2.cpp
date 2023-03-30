#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int search_K(int A[], int K, int a, int b);
void TC1();
void TC2();

int main() {
    srand(time(NULL));

    TC1();
    TC2();

    return 0;
}

int search_K(int A[], int K, int a, int b) {
    if (K == A[b - ((b - a) / 2)])
        return K;
    else if (K > A[b - ((b - a) / 2)])
        return search_K(A, K, b - ((b - a) / 2), b);
    else
        return search_K(A, K, a, b - ((b - a) / 2));
}

// 테스트 케이스 1
void TC1() {
    int A[10] = { 0 };
    for (int i = 0; i < 10; i++)
        A[i] = rand() % 100 + 1;

    int dump = 0;
    for (int i = 0; i < 9; i++)
        for (int j = i + 1; j < 10; j++) {
            if (A[i] > A[j]) {
                dump = A[i];
                A[i] = A[j];
                A[j] = dump;
            }
        }
    for(int i=0; i< 10; i++)
        printf("%d ", A[i]);

    printf("\nTest Case No.1 : K is %d\n", search_K(A, A[rand() % 10], 0, 10));

}

// 테스트 케이스 2
void TC2() {
    int A[20] = { 0 };
    for (int i = 0; i < 20; i++)
        A[i] = rand() % 100 + 1;

    int dump = 0;
    for (int i = 0; i < 19; i++)
        for (int j = i + 1; j < 20; j++) {
            if (A[i] > A[j]) {
                dump = A[i];
                A[i] = A[j];
                A[j] = dump;
            }
        }

    for (int i = 0; i < 20; i++)
        printf("%d ", A[i]);

    printf("\nTest Case No.2 : K is %d\n", search_K(A, A[rand() % 20], 0, 20));
}