# 알고리즘 설계 구현 결과 : <사칙연산>

## 1. <문제 정의>
- **문제이름**: 사칙연산
- **문제설명**: 정수 7과 8의 사칙연산

## 2. <알고리즘>
- **명칭**: 사칙연산 (  Elementary arithmetic )
- **입력**: 정수 7과 8
- **출력**: 입력의 사칙연산
- **처리순서** :
	1. 사칙연산 처리 한다.

## 3. <코드 설계>
1. **자료 구조 정의**
	- 7 : (int) - 상수
	- 8 ; (int) - 상수

2. **함수 정의**
- **기능** : 상수 7과 8의 사칙연산처리


## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h ) 
```c
int main() {
	printf("%d+%d=%d\n", 7, 8, 7 + 8);
	printf("%d-%d=%d\n", 7, 8, 7 - 8);
	printf("%d*%d=%d\n", 7, 8, 7 * 8);
	printf("%d/%d=%d\n", 7, 8, 7 / 8);

	return 0;
}
```

## <코드 저장소 링크>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/practice/CE02_P%2CM%2CT%2CD/P%2CM%2CT%2CD