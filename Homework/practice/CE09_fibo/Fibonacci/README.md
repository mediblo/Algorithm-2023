# 알고리즘 설계 구현 결과 : <피보나치의 수>

## 1. <문제 정의>
- **문제이름**: 피보나치의 수
- **문제설명**: 피보나치의 수를 계산한다
- **문제예시** : 다음 그림은 피보나치의 수의 예시이다.  
![photo](http://news.samsungdisplay.com/wp-content/uploads/2020/06/06-1.jpg)

## 2. <알고리즘>
- **명칭**: 피보나치 ( pibo )
- **입력**: 반복 횟수 정수 n
- **출력**: n까지의 피보나치 수열
- **처리순서** :
	1. 0일때는 0, 1일때는 1을 출력한다
	2. 2부터는 n-2, n-1의 값을 더한다 ( Ex : 0 + 1 = 1 / 1 + 1 = 2 / 1 + 2 = 3 )
	3. n번째까지 2번을 실행한다.

## 3. <코드 설계>
1. **자료 구조 정의**
	- 횟수 : (int n) - 정수

2. **함수 정의**
- **기능** : 피보나치수를 재귀함수로 계산한다.
- **프로토타입** : void fibo(int a = 0, int b = 0, int cnt = 0)


## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h ) 
```c
#define N 15

void fibo(int a = 0, int b = 0, int cnt = 0);

int main() {
	fibo();
}

void fibo(int a, int b, int cnt) {
	if (cnt == N) return;
	if (cnt == 0) {
		printf("fib(%d) = %d\n", cnt, 0);
		fibo(0, 1, ++cnt);
	}
	else if (cnt == 1) {
		printf("fib(%d) = %d\n", cnt, 1);
		fibo(0, 1, ++cnt);
	}
	else {
		printf("fib(%d) = %d\n", cnt, a+b);
		fibo(b, a+b, ++cnt);
	}
}
```

## <코드 저장소 링크>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/practice/CE09_fibo/Fibonacci/Fibonacci