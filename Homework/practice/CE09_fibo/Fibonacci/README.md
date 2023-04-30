# �˰��� ���� ���� ��� : <�Ǻ���ġ�� ��>

## 1. <���� ����>
- **�����̸�**: �Ǻ���ġ�� ��
- **��������**: �Ǻ���ġ�� ���� ����Ѵ�
- **��������** : ���� �׸��� �Ǻ���ġ�� ���� �����̴�.
![photo](http://news.samsungdisplay.com/wp-content/uploads/2020/06/06-1.jpg)

## 2. <�˰���>
- **��Ī**: �Ǻ���ġ ( pibo )
- **�Է�**: �ݺ� Ƚ�� ���� n
- **���**: n������ �Ǻ���ġ ����
- **ó������** :
	1. 0�϶��� 0, 1�϶��� 1�� ����Ѵ�
	2. 2���ʹ� n-2, n-1�� ���� ���Ѵ� ( Ex : 0 + 1 = 1 / 1 + 1 = 2 / 1 + 2 = 3 )
	3. n��°���� 2���� �����Ѵ�.

## 3. <�ڵ� ����>
1. **�ڷ� ���� ����**
	- Ƚ�� : (int n) - ����

2. **�Լ� ����**
- **���** : �Ǻ���ġ���� ����Լ��� ����Ѵ�.
- **������Ÿ��** : void fibo(int a = 0, int b = 0, int cnt = 0)


## <C�ڵ� ���� ���>
��������� ���� ( stdio.h ) 
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

## <�ڵ� ����� ��ũ>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/practice/CE09_fibo/Fibonacci/Fibonacci