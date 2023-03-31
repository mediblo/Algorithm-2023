# 알고리즘 설계 구현 결과 5: <가짜 동전 찾기>

## 1. <문제 정의>
- **문제이름**: 가짜 동전 찾기
- **문제설명**: 주어진 동전 더미 속 가벼운 가짜 동전 1개가 들어 있다. 양팔 저울을 통해 찾아라
- **문제예시** : 다음 그림과 같은 동전들 속에 가짜 동전이 1개 들어가 있다.  
![photo](https://3.bp.blogspot.com/-B-GJEFmOm-I/Wmf8Qbh9psI/AAAAAAABJyk/JHD7pAQqxxw6Gc9e80kEQ63qoyHgM9q2wCLcBGAs/s400/money_kasoutsuuka_kusa_shibafu.png)



## 2. <해결 아이디어>
- **(해결아이디어1)** : 동희  
동전 더미를 반으로 나눈 다음, 양팔 저울을 통해 조금 더 가벼운 쪽을 다시 반으로 나누어서 가짜 동전을 찾을 때 까지 반복한다. O(log2n)
- **(해결아이디어2)** : 용진  
동전 더미를 3개의 더미(A, B, C)로 나눈 다음, 2개(A, B)를 저울에 달고 저울이 기울어지면 A, B중에 하나를 다시 3 분할 하여 저울에 달고, 기울어지지 않으면 C를 3 분할 하여 저울에 달아서 가짜 동전을 찾을 때 까지 반복한다. O(log3n)

- **아이디어 채택** : 의논한 결과 아이디어 2를 채택하려 했으나 코드 제작 과정에서 정확한 3분할이 안되어 아이디어 1을 채택.

## 3. <알고리즘>
- **명칭**: 가짜 동전 찾기 ( fake_coin )
- **입력**: 동전 더미
- **출력**: 가짜 동전 
- **처리순서** :
	1. 동전 더미를 2개로 나누어 저울을 통해 비교한다.
	1. 저울이 기울어진 쪽의 더미를 선택해 1번을 반복한다.
	1. 가짜 동전을 찾아 반환한다.

## 4. <코드 설계>
1. **자료 구조 정의**
	- 동전 크기 : max_coin (define int) - 매크로 상수
	- 동전 더미 : coin (int []) - 정수 배열

2. **함수 정의**
- **기능** : 동전 더미와 동전 더미의 처음과 끝을 받아, 재귀함수로 호출하여 가짜 동전을 반환.
- **프로토타입** : int check_sum(int coin[], int a, int b)

3. **테스트 케이스 설계**  
TC1. 동전 더미를 선언하고 그 안에 가짜 동전을 넣어 위 함수를 호출하여 출력한다.  
TC2. 가짜 동전을 바꾸어서 넣어 TC1과 동일하게 테스트 한다.

## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, stdlib.h, time.h )
```C
#define max_coin 1024 // 최대 동전 갯수

int check_sum(int coin[], int a, int b);
void TC1();
void TC2();

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

    coin[666] = 1;

    printf("%d번이 가짜\n", check_sum(coin, 0, max_coin));
}

// 테스트 케이스 2
void TC2() {
    int coin[max_coin] = { 0 };
    coin[rand() % max_coin] = 1;

    printf("%d번이 가짜\n", check_sum(coin, 0, max_coin));
}
```

## <코드 저장소 링크>
정용진 : https://github.com/mediblo/Algorithm-2023/tree/master/Homework/1%EC%9E%A5/fake_coin_1  
이동희 : 몰?루