// long long int 이므로 %lld로 출력할 것 / 재귀함수
long long int euclidRecursive(long long int a, long long int b) { // 4, 16
	if (b == 0) return a;
	return euclidRecursive(b, a % b);
}

// long long int 이므로 %lld로 출력할 것 / 반복적 함수
long long int euclidRepeat(long long int a, long long int b) { // 16, 4
	long long int temp = 0;
	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}