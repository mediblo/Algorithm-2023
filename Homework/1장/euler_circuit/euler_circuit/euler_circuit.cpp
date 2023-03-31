#include <stdio.h>
#include <stdlib.h>

#define max_size 10

int dfs(int test[][max_size], int now);
void TC1();
void TC2();

int move = 0;

int main() {
    TC1();
    printf("\n");
    TC2();

    return 0;
}

int dfs(int test[][max_size], int now) {
    if (move != 0)
        for (int i = 0; i < max_size; i++)
            for (int j = 0; j < max_size; j++)
                if (test[i][j] == 1 && now == 0)
                    return -1;

    printf("%d ", now);
    for (int i = 0; i < max_size; i++) {
        if (test[now][i] == 1) {
            test[now][i] = 0;
            move++;
            if (dfs(test, i) == -1) test[now][i] = 1, move--;
        }
        else if (test[i][now] == 1) {
            test[i][now] = 0;
            move++;
            if (dfs(test, i) == -1) test[now][i] = 1, move--;
        }

    }
    return 0;
}

void TC1() {
    int test[max_size][max_size] = { { 0 } };

    test[0][1] = 1;
    test[0][3] = 1;
    test[1][2] = 1;
    test[1][3] = 1;
    test[1][4] = 1;
    test[2][3] = 1;
    test[3][4] = 1;

    dfs(test, 0);
}

void TC2() {
    int test[max_size][max_size] = { { 0 } };

    test[0][1] = 1;
    test[0][9] = 1;
    test[1][2] = 1;
    test[2][3] = 1;
    test[2][7] = 1;
    test[2][8] = 1;
    test[3][4] = 1;
    test[4][5] = 1;
    test[5][6] = 1;
    test[6][7] = 1;
    test[6][8] = 1;
    test[6][9] = 1;

    move = 0;

    dfs(test, 0);
}