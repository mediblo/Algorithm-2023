# 알고리즘 설계 구현 결과 3 : <동전 거스름돈>

## 1. <문제 정의>
- **문제이름**: 동전 거스름돈
- **문제설명**: 거스름돈을 최소한의 갯수로 줄 때 각 동전의 갯수를 찾는다.
- **문제예시** : 다음 그림과 같은 동전을 최소한으로 하여 상대방에게 준다.
![photo](https://2.bp.blogspot.com/-_D5eRKkVsN4/VD3RiiHw15I/AAAAAAAAoEI/emmL8Zph45s/s800/gaika_coin.png)



## 2. <해결 아이디어>
- **(해결아이디어 1)** :  받은 돈을 각 동전의 크기만큼 나누고 차감하여 준다.

## 3. <알고리즘>
- **명칭**: 동전 거스름돈 ( change_machine )
- **입력**: 거스름돈 ( 돈 )
- **출력**: 각 동전 갯수
- **처리순서** :
	1. 거스름돈을 최댓값의 동전부터 나눠서 갯수를 얻는다.
	1. 그 다음 돈을 동전의 크기만큼 나눈 나머지 값을 마지막 동전까지 1번을 반복한다.

## 4. <코드 설계>
1. **자료 구조 정의**
	- 거스름돈 : money (int) - 정수
	- 동전 크기 : coin (int []) - 정수 배열
	- 동전 갯수 : cc (int []) - 정수 배열

2. **함수 정의**
- **기능** : 돈과 동전 갯수, 테스트케이스의 플래그를 받아서 동전 갯수를 출력한다. 
- **프로토타입** : int change(int money, struct change_coin *cc, int flag)

3. **테스트 케이스 설계**  
TC1. 동전의 값을 선언하고, 위 함수를 호출하여 출력한다.  
TC2. 동전의 값을 선언하고, 위 함수를 호출하여 구조체를 통하여 출력한다.

## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, stdlib.h, time.h )
```C
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
```

## <코드 저장소 링크>
정용진 : https://github.com/mediblo/Algorithm-2023/tree/master/Homework/1%EC%9E%A5/change_machine  
이동희 : https://github.com/20LDH/algorithm_report/tree/master/%EA%B1%B0%EC%8A%A4%EB%A6%84%EB%8F%88%20%EB%8F%99%EC%A0%84%20%EA%B0%9C
