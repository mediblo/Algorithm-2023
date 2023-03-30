# 알고리즘 설계 구현 결과 : <임의 숫자 찾기>

## 1. <문제 정의>
- **문제이름**: 랜덤한 임의 숫자 찾기
- **문제설명**: 주어진 숫자 (정수) 목록 중 선택한 숫자를 찾는다.
- **문제예시** : 다음 그림과 같은 숫자 목록 중 선택한 숫자는 7이다.
![photo](https://1.bp.blogspot.com/-5ZKfHE46N_w/U9zsZKNSJwI/AAAAAAAAkdI/EgZ4lm7z3UE/s1600/number_7.png)



## 2. <해결 아이디어 1>
- **(해결아이디어 1-1)** :  주어진 숫자가 랜덤할 때 첫 번째 숫자부터 마지막 숫자까지 비교하면서 찾는다.
- **(해결아이디어 1-2)** : 주어진 숫자가 정렬되어 있을 때 가운데 숫자를 큰지 작은지를 비교하여 절반씩 나누면서 찾는다.

## 3-1. <알고리즘>
- **명칭**: 임의숫자찾기 (search_K)
- **입력**: 숫자 카드 목록 ( 랜덤 )
- **출력**: 원하는 숫자( K )
- **처리순서** :
	1. 첫 번째 숫자랑 원하는 숫자 K랑 비교
	1. 만약 숫자가 K랑 같으면 K를 반환, 아닐 시 1번을 반복

## 4-1. <코드 설계>
1. **자료 구조 정의**
	- 선택한 숫자 : K (int) - 정수
	- 숫자 목록 : A (int []) - 정수 배열

2. **함수 정의**
- **기능** : 정수 배열과 크기, 선택한 숫자를 입력받아 찾으면 K, 아닐시 -1을 반환
- **프로토타입** : int search_K(int A[], int cnt, int K)

3. **테스트 케이스 설계**
TC1. 임의의 숫자로 구성된 정수 배열을 선언하고, 위 함수를 호출하여 K값을 반환 받아 출력한다.
TC2. 임의의 개수로 된 정수 배열을 선언하고 TC1과 동일하게 테스트한다.

## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, stdlib.h, time.h )
```C
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

```

## 3-2. <알고리즘>
- **명칭**: 임의숫자찾기 (search_K)
- **입력**: 숫자 카드 목록 ( 오름차순 )
- **출력**: 원하는 숫자( K )
- **처리순서** :
	1. 숫자 갯수의 절반을 찾아서 나눈 다음, 가운데 숫자를 숫자 K와 비교
	1. 같으면 K 반환, 크면 위쪽, 작으면 아래쪽으로 향하여 1번을 반복

## 4-2. <코드 설계>
1. **자료 구조 정의**
	- 선택한 숫자 : K (int) - 정수
	- 숫자 목록 : A (int []) - 정수 배열
	- 최솟값, 최댓값 : a, b (int) - 정수

2. **함수 정의**
- **기능** : 정수 배열과 크기, 선택한 숫자를 입력받아 찾으면 K, 아닐시 -1을 반환
- **프로토타입** : int search_K(int A[], int a, int b, int K)

3. **테스트 케이스 설계**
TC1. 임의의 숫자로 구성된 정수 배열을 선언하고, 위 함수를 호출하여 K값을 반환 받아 출력한다.
TC2. 임의의 개수로 된 정수 배열을 선언하고 TC1과 동일하게 테스트한다.

## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, stdlib.h, time.h )
```C
int search_K(int A[], int K, int a, int b);
void TC1();
void TC2();

int main() {
    srand(time(NULL));
    TC1();
    TC2();
    return 0;
}
int search_K(int A[], int K, int a, int b) {
    if (K == A[ b - ((b - a) / 2)])
        return K;
    else if (K > A[ b - ((b - a) / 2) ])
        return search_K(A, K, b - ((b - a) / 2), b);
    else
        return search_K(A, K, a, b - ((b - a) / 2));
}
// 테스트 케이스 2
void TC1() {
    int A[10] = { 0 };
    for (int i = 0; i < 10; i++) {
        A[i] = rand() % 100 + 1;
        printf("%d ", A[i]);
    }
    int dump = 0;
    for(int i=0; i< 9; i++)
        for(int j=i+1; j<10; j++) {
            if( A[i] > A[j]){
                dump = A[i];
                A[i] = A[j];
                A[j] = dump;
            }
        }
    printf("\nTest Case No.1 : K is %d\n", search_K(A, A[rand() % 10], 0, 10));
}
// 테스트 케이스 2
void TC2() {
    int A[20] = { 0 };
    for (int i = 0; i < 20; i++) {
        A[i] = rand() % 100 + 1;
        printf("%d ", A[i]);
    }
    int dump = 0;
    for(int i=0; i< 19; i++)
        for(int j=i+1; j<20; j++) {
            if( A[i] > A[j]){
                dump = A[i];
                A[i] = A[j];
                A[j] = dump;
            }
        }
    printf("\nTest Case No.2 : K is %d\n", search_K(A, A[rand() % 20], 0, 20));
}

```

## <코드 저장소 링크>
정용진 : https://github.com/mediblo/Algorithm-2023/tree/master/Homework/1%EC%9E%A5/find_big_number  
이동희 : 몰?루
