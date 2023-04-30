#include <stdio.h>

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