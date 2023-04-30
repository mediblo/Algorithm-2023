#include <stdio.h>

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