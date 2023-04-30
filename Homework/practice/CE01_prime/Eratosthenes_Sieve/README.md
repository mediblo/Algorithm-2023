# 알고리즘 설계 구현 결과 : <에라토스테네스의 체>

## 1. <문제 정의>
- **문제이름**: 에라토스 테네스의 체
- **문제설명**: 체에 거르는 것 처럼 소수의 배는 무시하는 기법
- **문제예시** : 다음 그림은 에라토스 테네스의 체의 예시이다.  
![photo](https://wikidocs.net/images/page/21638/DC-1707V1.png)

## 2. <알고리즘>
- **명칭**: 에라토스테네스 ( eratosthenes )
- **입력**: 정수 n
- **출력**: n까지의 소수
- **처리순서** :
	1. n까지의 수를 반복문으로 반복한다 ( 2부터 시작 )
	2. 만약 수의 값이 1이면 다음 값으로 넘어간다
	3. 0이면 n까지의 수의 배수의 값은 모두 1로 바꾼다.

## 3. <코드 설계>
1. **자료 구조 정의**
	- n까지의 정수 : n (int A[]) - 정수 배열

2. **함수 정의**
- **기능** : 크기 n인 정수타입의 배열 생성하여 에라토스테네스 알고리즘을 실행한다.


## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h ) 
```c
int main() {
	int n = 100;
	int prime[101] = { 0 };
	int j = 0;
	for (int i = 2; i <= n; i++) {
		if (prime[i] == 1) continue;
		for (j = i * 2; j <= n; j += i)
			prime[j] = 1;
	}

	for (int i = 2; i <= n; i++)
		if (prime[i] == 0)
			printf("%d ", i);

	return 0;
}
```

## <코드 저장소 링크>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/practice/CE01_prime/Eratosthenes_Sieve