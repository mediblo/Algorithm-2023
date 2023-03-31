#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> // pow() 함수 사용

#define max_subject 16 // 신하 수

void drink_wine(int wine);

void TC1();
void TC2();

int main() {
    srand(time(NULL));

    TC1();
    TC2();

    return 0;
}

void drink_wine(int wine) {
    int cnt = 0;

    printf("%d번 : ", wine);
    for (int i = max_subject - 1; i >= 0; i--) {
        if (wine >> i & 1) cnt++;

        printf("%d", wine >> i & 1);

        if (i % 4 == 0) // 4 단위 끊기
            printf(" ");
    }
    printf("\n%d명이 죽었습니다.\n", cnt);
}

void TC1() {
    drink_wine(rand() % int(pow(2, max_subject)-1 ) );
}
void TC2() {
    drink_wine(rand() % int(pow(2, max_subject)-1 ) );
}