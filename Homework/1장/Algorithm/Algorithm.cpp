#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//test push

// 독 단지 찾기 / 임의의 독이 든 독 단지 ( 1개만 독 ) / 독이든 단지의 번호

// 가짜 동전 / 가짜 동전이 포함된 동전 더미 ( 1개만 가짜 ) / 가짜 동전의 번호 ( 해결 )
/*
#define max_coin 1024 // 최대 동전 갯수
int cnt = 0;

int check_sum(int coin[], int a, int b);

int main() {
    int coin[max_coin] = { 0 };
    int i = 0;
    srand(time(NULL));

    // coin[rand() % max_coin] = 1;

    coin[524] = 1;

    printf("%d번이 가짜 :  %d번의 확인 끝의 탈출", check_sum(coin, 0, max_coin), cnt);
    return 0;
}

int check_sum(int coin[], int a, int b) {
    if ((b - a) == 1) // 탈출
        if (coin[a])
            return a;
        else
            return b;

    int sum = 0;
    cnt++;

    for (int i = a; i < ( b - (b-a) / 2 ); i++) {
        sum += coin[i];
    }

    printf("%d\n", sum);
    if (sum == 0)
        return check_sum(coin, b - ((b - a) / 2), b);
    else
        return check_sum(coin, a, b - ((b - a) / 2));

    return -1;
}
*/

// 미로 구현 / 어떻게 빠져 나올 것 인가 ( 우수의 법칙 / 마크 법칙 )
/*
int make_maze();

int main() {
    int maze[6][6] = { 0 };

    return 0;
}
*/

// 한붓그리기 ( 재귀함수 사용 할 예정 ) / 아직 이상함 좀더 만져볼 것
/*
int dfs(int test[][5], int now);

int cnt = 0;

int main() {
    
    int node[5] = {1, 2, 3, 4, 5};
    int edge[5][5] = { { 1, 3 }, { 2, 3, 4 }, { 3 }, { 4 } };

    int test[5][5] = { { 0 } };
    
    test[0][1] = 1;
    test[0][3] = 1;
    test[1][2] = 1;
    test[1][3] = 1;
    test[1][4] = 1;
    test[2][3] = 1;
    test[3][4] = 1;

    dfs(test, 0);
    
    printf("\n%d", cnt);

    return 0;
}

int dfs(int test[][5], int now) {
    printf("%d ", now);
    for (int i = 0; i < 5; i++) {
        if (test[now][i] == 1) {
            printf("[%d %d] ", now, i);
            test[now][i] = 0;
            cnt++;
            dfs(test, i);
        }
        else if (test[i][now] == 1) {
            printf("[%d %d] ", i, now);
            test[i][now] = 0;
            cnt++;
            dfs(test, i);
        }
    }
    return 0;
}
*/

// 동전 거스름돈 ( 해결 )
/*
int change(int money, struct change_coin *cc);

struct change_coin {
    int n_coin[4] = { 0 };
};

int main() {
    int money = 8240;
    
    struct change_coin cc = { 0 };


    printf("%d원\n", money);
    change(money, &cc);

    for (int i = 0; i < 4; i++)
        printf("%d ", cc.n_coin[i]);

    return 0;
}

int change(int money, struct change_coin *cc) {
    int coin[] = { 500, 100, 50, 10 };

    for (int i = 0; i < 4; i++) {
        cc->n_coin[i] = money / coin[i]; // 구조체를 통한 출력
        printf("%d원 : %d\n", coin[i], money / coin[i]); // printf를 통한 출력
        money %= coin[i];
    }

    return 0;
}
*/
// 임의 숫자 찾기 ( 해결 )
/*
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
        if (A[i] == K){
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
*/
// 최대 숫자 찾기 ( 해결 )
/*
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
    for (int i = 1; i < cnt; i++)
        if (A[max] < A[i]) 
            max = i;

    return A[max]; // 4. 최댓값을 반환
}

// 테스트 케이스 1
void TC1() {
    int A[10] = { 0 };
    for (int i = 1; i < 10; i++)
        A[i] = rand() % 100 + 1;

    printf("Test Case No.1 : big number is %d\n", searchBig(A, 10));

}

// 테스트 케이스 2
void TC2() {
    int A[20] = { 0 };
    for (int i = 1; i < 20; i++)
        A[i] = rand() % 100 + 1;

    printf("Test Case No.2 : big number is %d\n", searchBig(A, 20));

}
*/