#include <stdio.h>
#pragma warning(disable:4996)

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