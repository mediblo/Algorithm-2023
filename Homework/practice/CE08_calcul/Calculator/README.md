# 알고리즘 설계 구현 결과 : <계산기>

## 1. <문제 정의>
- **문제이름**: 계산기
- **문제설명**: 정수 2개를 입력받아 원하는 사칙연산을 실행한다.
- **문제예시** : 다음 그림은 계산기이다.  
![photo](https://i.namu.wiki/i/_i4dszQjFT8YnXRFtyEVUcgXAwmZM5GnhK_y6P2MZKm6s46tky3xLazJ3xB2Q8_33_u5DsBE3yBzlnzpWbyRy8xbA3qb7_rwhKQKJdZLgU1mQTtIeeTsf5gDxv-R01tnqHBAoPbAN6L9DgeVvZcFpA.webp)

## 2. <알고리즘>
- **명칭**: 계산기 ( calculator )
- **입력**: 정수 2개
- **출력**: 원하는 사칙연산
- **처리순서** :
	1. 정수 2개를 입력받는다
	2. 원하는 사칙연산을 고른다
	3. 계산 값을 도출한다

## 3. <코드 설계>
1. **자료 구조 정의**
	- 정수 2개 : (int a, b) - 정수

2. **함수 정의**
- **기능** : 정수 2개를 입력받아 원하는 사칙연산을 행한다.


## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h ) 
```c
void printMenu();
int choose();
void calcul(int c);
// 더하기
void plus();
// 뺄셈
void minus();
// 곱셈
void triple();
// 나눗셈
void quotient();
// 나머지
void remainder();

int main() {
	int choice;
	printMenu();
	choice = choose();
	calcul(choice);
	return 0;
}

void printMenu() {
	printf("====================\n");
	printf("        MENU\n");
	printf("====================\n");
	printf("1. 덧셈\n");
	printf("2. 뺄셈\n");
	printf("3. 곱셈\n");
	printf("4. 나눗셈\n");
	printf("5. 나머지\n");
}

int choose() {
	int a;
	printf("원하는 메뉴를 선택하시오(1-5): ");
	scanf("%d", &a);
	return a;
}

void calcul(int c) {
	switch (c) {
	case 1:
		plus();
		break;
	case 2:
		minus();
		break;
	case 3:
		triple();
		break;
	case 4:
		quotient();
		break;
	case 5:
		remainder();
		break;
	default:
		printf("Error!!");
	}
}

void plus() {
	int A, B;
	printf("숫자 2개를 입력하시오 : ");
	scanf("%d %d", &A, &B);

	printf("연산결과 : %d", A + B);
}

void minus() {
	int A, B;
	printf("숫자 2개를 입력하시오 : ");
	scanf("%d %d", &A, &B);

	printf("연산결과 : %d", A - B);
}
void triple() {
	int A, B;
	printf("숫자 2개를 입력하시오 : ");
	scanf("%d %d", &A, &B);

	printf("연산결과 : %.2f", (float)A * B);
}
void quotient() {
	int A, B;
	printf("숫자 2개를 입력하시오 : ");
	scanf("%d %d", &A, &B);

	printf("연산결과 : %d", A / B);
}
void remainder() {
	int A, B;
	printf("숫자 2개를 입력하시오 : ");
	scanf("%d %d", &A, &B);

	printf("연산결과 : %d", A % B);
}
```

## <코드 저장소 링크>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/practice/CE08_calcul/Calculator