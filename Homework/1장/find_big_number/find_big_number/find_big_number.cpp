#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int searchBig(int A[], int cnt);
void TC1();
void TC2();

int main() {
    srand(time(NULL)); // 랜덤 시드 부여 ( 현재 시간 기준 )
    TC1();
    TC2();
    return 0;
}
int searchBig(int A[], int cnt) {
    int max = 0; // 1. 첫 번째 순서를 변수 max에 저장
    // 2. 두 번째 카드부터 읽어서 변수 max의 카드보다 크면 그 카드 순서를 max에 저장
    // 3. 모든 카드를 읽을 때 까지 2번째 행동 반복
    for (int i = 1; i < 10; i++)
        if (A[max] < A[i])
            max = i;
    return A[max]; // 4. 최댓값을 반환
}
// 테스트 케이스 1
void TC1() {
    int A[10] = { 0 };
    for (int i = 1; i < 10; i++)
        A[i] = rand() % 1000 + 1;
    printf("Test Case No.1 : big number is %d\n", searchBig(A, 10));
}
// 테스트 케이스 2
void TC2() {
    int A[20] = { 0 };
    for (int i = 1; i < 20; i++)
        A[i] = rand() % 1000 + 1;
    printf("Test Case No.2 : big number is %d\n", searchBig(A, 20));
}