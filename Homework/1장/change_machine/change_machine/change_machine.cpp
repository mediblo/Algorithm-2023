#include <stdio.h>
#include <stdlib.h>

int change(int money, struct change_coin *cc, int flag);
void TC1();
void TC2();

int coin[] = { 500, 100, 50, 10 };

struct change_coin {
    int n_coin[4] = { 0 };
};

int main() {
    TC1();
    printf("\n");
    TC2();

    return 0;
}
int change(int money, struct change_coin *cc, int flag) {
    printf("돈 : %d\n", money);
    for (int i = 0; i < 4; i++) {
        if (flag == 1) printf("%d원 : %d\n", coin[i], money / coin[i]); // printf를 통한 출력
        else if (flag == 2) cc->n_coin[i] = money / coin[i]; // 구조체를 통한 출력
        
        money %= coin[i];
    }
    return 0;
}

// 테스트 케이스 1
void TC1() {
    int money = 8240;
    struct change_coin cc = { 0 }; // 사용안함
    
    change(money, &cc, 1);
}
// 테스트 케이스 2
void TC2() {
    struct change_coin cc = { 0 };
    int money = 8240;

    change(money, &cc, 2);
    for (int i = 0; i < 4; i++)
        printf("%d원 : %d\n", coin[i], cc.n_coin[i]);
}