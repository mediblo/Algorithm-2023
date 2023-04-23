# 알고리즘 설계 구현 결과 : <유클리드 호제법>

## 1. <문제 정의>
- **문제이름**: 유클리드 호제법 ( 재귀 함수, 반복문 )
- **문제설명**: 재귀함수와 반복문을 동시에 사용하여 유클리드 호제법을 사용하라
- **문제예시** : 다음 그림은 유클리드 호제법의 예시이다.  
![photo](https://velog.velcdn.com/images%2Fgjtang%2Fpost%2F397c8edb-8eb0-4367-8c26-a3c640e3e127%2Fimage.png)

## 2. <알고리즘>
- **명칭**: 유클리드 호제법 ( Euclid )
- **입력**: 두개의 정수 값
- **출력**: 입력된 두 값의 GCD 
- **처리순서** :
	1. a와 b를 나눈 나머지가 0인지 확인한다.
	1. 0이면 a를 반환 아닐 시 b값과 나머지 값으로 1번을 반복한다.

## 3. <코드 설계>
1. **자료 구조 정의**
	- 두 정수 값 : a, b (long long int) - 정수

2-1. **함수 정의**
- **기능** : 두 정수 값 a와 b를 받아 재귀함수 호출방법으로 GCD를 출력한다.
- **프로토타입** : long long int euclidRecursive(long long int a, long long int b)

2-2. **함수 정의**
- **기능** : 두 정수 값 a와 b를 받아 반복문 사용으로 GCD를 출력한다.
- **프로토타입** : long long int euclidRepeat(long long int a, long long int b)  

3. **테스트 케이스 설계**  
TC. 두 함수를 호출하여 값이 같은지 확인하는 것을 여러번 반복한다.

## 4. <의사 코드>
1-1. **재귀함수 호출법**
```
정수 재귀함수( 정수 a, 정수 b )
  만약 b가 0이랑 같다면? a를 반환한다.
  아니면? 재귀함수의 매개변수의 a부분에는 b를, b 부분에는 a mod b를 하여 호출한다.
  ```

1-2. **반복문 사용**
```
정수 반복문( 정수 a, 정수 b )
  정수 변수 C를 생성한다.
  B가 0이 될 때 까지
    C = b
    b = a mod b
    a = C
  a를 반환한다.
  ```

## 5. <순서도>
![photo](https://i.imgur.com/5JWokih.png)

## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, stdlib.h, time.h )  
Euclid
```C
// long long int 이므로 %lld로 출력할 것 / 재귀함수
long long int euclidRecursive(long long int a, long long int b) {
	if (b == 0) return a;
	return euclidRecursive(b, a % b);
}

// long long int 이므로 %lld로 출력할 것 / 반복적 함수
long long int euclidRepeat(long long int a, long long int b) {
	long long int temp = 0;
	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
```

test_case
```C
// 1부터 100억 사이의 랜덤한 값을 주는 테스트 케이스
void TC() {
	srand(time(NULL));
	double start, finish; // 실행시간 체크
	start = clock();
	
	for(int i=0; i<100000; i++){
		// 1에서 1억 사이의 값과 1에서 1000 사이의 값을 곱한 값을 준다.
		long long int a = (rand() % 100000000 + 1) * ( rand() % 1000 + 1 );
		long long int b = (rand() % 100000000 + 1) * ( rand() % 1000 + 1 );

		// 두 방법의 리턴 값이 맞는지 확인
		if ( euclidRecursive(a, b) != euclidRepeat(a, b) ) { 
			printf("Error 두 방법의 값이 다릅니다. %lld %lld,", a, b); // 추후의 확인을 위한 a, b
			exit(1);
		}
	}

	finish = clock();
	printf("%f ms 걸렸습니다.", finish - start);
}
```

main
```C
int main() {
	TC();
	return 0;
}
```

## <코드 저장소 링크>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/2%EC%9E%A5/Euclid