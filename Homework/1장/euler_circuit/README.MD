# 알고리즘 설계 구현 결과 4: <한붓 그리기>

## 1. <문제 정의>
- **문제이름**: 한붓 그리기 ( 오일러 서킷 )
- **문제설명**: 출발지점으로 다시 돌아오는 과정에서 모든 길을 한번씩만 건너라.
- **문제예시** : 다음 그림과 같은 모든 길을 한번씩만 움직여서 출발지점으로 돌아와라.  
![TC1](https://www.techiedelight.com/wp-content/uploads/Eulerian-Cycle.png)  
![TC2](https://i.imgur.com/rqXMEf9.png)



## 2. <해결 아이디어>
- **(해결아이디어1)** : 모든길을 재귀함수를 통하여 하나씩 건너자.

## 3. <알고리즘>
- **명칭**: 한붓 그리기 ( euler_circuit )
- **입력**: 출발지점, 섬 사이의 이어진 길들
- **출력**: 움직이는 경로 
- **처리순서** :
	1. 맨 처음 출발지점에서 보이는 순서대로 걷는다.
	1. 만약 움직일 수 없는데 출발지점이 아니라면 왔던길을 돌아간다.
	1. 1번과 2번을 반복하여 출발지점으로 도착하면 끝낸다.

## 4. <코드 설계>
1. **자료 구조 정의**
	- 최대 꼭짓점 갯수 : max_size (define int) - 매크로 상수
	- 섬 : test (int [][]) - 정수 2차원 배열

2. **함수 정의**
- **기능** : 섬과 섬 사이의 길을 건너는 재귀함수
- **프로토타입** : int dfs(int test[][max_size], int now)

3. **테스트 케이스 설계**  
TC1. 첫 번째 사진을 구현하여 위 함수를 호출하여 경로를 출력한다.  
TC2. 두 번째 사진을 구현하여 TC1과 동일하게 테스트한다.

## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, stdlib.h )
```C
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
```

## <코드 저장소 링크>
정용진 : https://github.com/mediblo/Algorithm-2023/tree/master/Homework/1%EC%9E%A5/euler_circuit  
이동희 : 없음