# 알고리즘 설계 구현 결과 5: <가짜 동전 찾기>

## 1. <문제 정의>
- **문제이름**: 독이 든 와인 찾기
- **문제설명**: 와인 저장고 안에 독이 든 와인이 1개가 있다. 신하를 사용하여 찾아라.
- **문제예시** : 다음 그림과 같은 와인 중에서 독이 든 와인을 찾는다.  
![photo](https://1.bp.blogspot.com/-8L7q8Fr131s/Wj4IXawiUoI/AAAAAAABJKg/EkpyKFHSqs0aNdFewso1H5LmjQw6huTWACLcBGAs/s400/drink_wine_cellar.png)



## 2. <해결 아이디어>
- **(해결아이디어1)** : 와인 갯수를 2진수로 변환하여 각각의 비트당 1명의 신하를 배정하여 1일 경우에 그 비트의 신하가 술을 마셔서 확인하자.

## 3. <알고리즘>
- **명칭**: 독이 든 와인 찾기 ( death_wine )
- **입력**: 와인 갯수
- **출력**: 죽어버린 신하의 수 
- **처리순서** :
	1. 와인 갯수를 2진수로 치환한다.
	1. 비트가 1일 때 카운트(죽을 신하)를 증가 시킨다.
	1. 카운트(시체가 된 신하)를 반환한다.

## 4. <코드 설계>
1. **자료 구조 정의**
	- 신하의 수 : max_subject (define int) - 매크로 상수
	- 독이 든 와인 번호 : wine (int []) - 정수 배열

2. **함수 정의**
- **기능** : 독이 든 와인 번호를 받아 죽어버린 신하의 수를 출력한다.
- **프로토타입** : void drink_wine(int wine)

3. **테스트 케이스 설계**  
TC1. 독이 든 와인의 번호를 넣어 위 함수를 호출하여 출력한다.  
TC2. 독이 든 와인의 번호 바꾸어서 TC1과 동일하게 테스트 한다.

## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, stdlib.h, time.h, math.h )
```C
#define max_subject 16 // 신하 수

void drink_wine(int wine);
void TC1();
void TC2();

int main() {
    srand(time(NULL));

    TC1();
    TC2();

    return 0;
}

void drink_wine(int wine) {
    int cnt = 0;
    printf("%d번 : ", wine);
    for (int i = max_subject - 1; i >= 0; i--) {
        if (wine >> i & 1) cnt++;
        printf("%d", wine >> i & 1);
        if (i % 4 == 0) // 4 단위 끊기
            printf(" ");
    }
    printf("\n%d명이 죽었습니다.\n", cnt);
}

//테스트 케이스 1
void TC1() {
    drink_wine(rand() % int(pow(2, max_subject)-1 ) );
}

// 테스트 케이스 2
void TC2() {
    drink_wine(rand() % int(pow(2, max_subject)-1 ) );
}
```

## <코드 저장소 링크>
정용진 : https://github.com/mediblo/Algorithm-2023/tree/master/Homework/1%EC%9E%A5/death_pot  
이동희 : 몰?루