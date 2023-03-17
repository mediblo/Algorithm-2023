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
int A[10] = { 0 };

int rand_A();
int searchK(int K);

int main() {
    srand(time(NULL));

    int ret = -2;
    int K = rand_A();

    printf("\n%d\n", K);
    
    ret = searchK(K);

    if ( ret == K)
        printf("FOund! it's %d!!", K);
    else if ( ret == -2)
        printf("ErroR!!");
    else
        
    return 0;
}

int rand_A() {
    for (int i = 0; i < 10; i++) {
        A[i] = rand() % 100 + 1;
        printf("%d ", A[i]);
    }

    return A[ rand() % 10 ];
}


// Funtion : find K from array A[]
//  return :
//      -1 : if K is not found
//       K : if K is found
int searchK(int K) {
    int ret = 0;

    // 2. K값 순차적 찾기
    for (int i = 1; i < 10; i++)
        if (A[i] == K){
            ret = i;
            break;
        }
    return A[ret];
}
*/
// 최대 숫자 찾기 ( 해결 )
/*
int searchBig();

int main() {
    printf("\nthe big number is %d", searchBig());

    return 0;
}

int searchBig() {
    srand(time(NULL));

    int A[10] = { 0 };

    for (int i = 0; i < 10; i++){
        A[i] = rand() % 100 + 1;
        printf("%d ", A[i]);
    }

    int ret = 0;

    for (int i = 1; i < 10; i++) {
        if (A[ret] < A[i])
            ret = i;
    }
    return A[ret];
}
*/