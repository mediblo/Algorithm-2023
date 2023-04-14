#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max_coin 1024 // 최대 동전 갯수

int check_sum(int coin[], int a, int b);
void TC1();
void TC2();

// 반으로 나누기 전에 나머지 값을 빼고 나눈다. ( Ex : 5 % 2 = 1 , ( 5 - 1 ) - / 2 = 2

int main() {
    srand(time(NULL));

    TC1();
    TC2();
    
    return 0;
}

int check_sum(int coin[], int a, int b) {
    if ((b - a) == 1) // 탈출
        if (coin[a])
            return a;
        else
            return b;

    int sum = 0;

    for (int i = a; i < (b - (b - a) / 2); i++) {
        sum += coin[i];
    }

    if (sum == 0)
        return check_sum(coin, b - ((b - a) / 2), b);
    else
        return check_sum(coin, a, b - ((b - a) / 2));

    return -1;
}

// 테스트 케이스 1
void TC1() {
    int coin[max_coin] = { 0 };

    coin[663] = 1;

    printf("%d번이 가짜\n", check_sum(coin, 0, max_coin));
}

// 테스트 케이스 2
void TC2() {
    int coin[max_coin] = { 0 };
    coin[rand() % max_coin] = 1;

    printf("%d번이 가짜\n", check_sum(coin, 0, max_coin));
}