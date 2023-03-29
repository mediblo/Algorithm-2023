# 알고리즘 설계 구현 결과 1: <가장 큰 수 찾기>

## 1. <문제 정의>
- **문제이름**: 가장 큰 숫자 찾기
- **문제설명**: 주어진 숫자 (정수) 카드 목록 중 가장 큰 숫자 카드를 찾는다.
- **문제예시** : 다음 그림과 같은 카드 목록 중 가장 큰 숫자는 90이다.  
![photo](https://1.bp.blogspot.com/-QMiAZRjHwvs/WWcOoEyVZ-I/AAAAAAABFig/0CCtYP2FD6kMVOYzksciAvQJedKKpn-dQCLcBGAs/s800/cardgame_card_dasu.png)



## 2. <해결 아이디어>
- **(해결아이디어1)** : 모두  
 임의의 카드를 선택하고 적힌 숫자를 가장 큰 숫자로 기억. 나머지 선택되지 않은 카드목록에서 하나를 선택하여 비교. 기억된 숫자와 선택 카드 숫자 비교하여 가장 큰 숫자 갱신. 모든 카드를 다 방문할 때까지 반복.

- **아이디어 채택** : 의논한 결과 아이디어 1을 채택.

## 3. <알고리즘>
- **명칭**: 가장큰수찾기 (findMaxNumber)
- **입력**: 숫자 카드 목록 
- **출력**: 가장 큰 숫자  
- **처리순서** :
	1. 첫 번째 순서를 변수 max에 저장  
	1. 두 번째 카드부터 읽어서 변수 max의 카드보다 크면 그 카드 순서를 max에 저장
	1. 모든 카드를 읽을 때 까지 2번째 행동 반복
	1. 최댓값을 반환

## 4. <코드 설계>
1. **자료 구조 정의**
	- 가장 큰 숫자 : max (int) - 정수
	- 숫자 목록 : A (int []) - 정수 배열

2. **함수 정의**
- 기능:정수 배열과 배열의 크기(count) 입력받아 최대 정수 출력
- 프로토타입: int searchBig(int A[], int cnt) 

3. **테스트 케이스 설계**
TC1. 임의의 숫자로 구성된 정수 배열을 선언하고, 위 함수를 호출하여 최대값을 반환 받아 출력한다.  
TC2. 임의의 개수로 된 정수 배열을 선언하고 TC1과 동일하게 테스트한다.

## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, stdlib.h, time.h )
```C
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
```

## <코드 저장소 링크>
정용진 : https://github.com/mediblo/Algorithm-2023/tree/master/Homework/1%EC%9E%A5/find_big_number
이동희 : 몰?루