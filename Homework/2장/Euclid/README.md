# �˰��� ���� ���� ��� : <��Ŭ���� ȣ����>

## 1. <���� ����>
- **�����̸�**: ��Ŭ���� ȣ���� ( ��� �Լ�, �ݺ��� )
- **��������**: ����Լ��� �ݺ����� ���ÿ� ����Ͽ� ��Ŭ���� ȣ������ ����϶�
- **��������** : ���� �׸��� ��Ŭ���� ȣ������ �����̴�.  
![photo](https://velog.velcdn.com/images%2Fgjtang%2Fpost%2F397c8edb-8eb0-4367-8c26-a3c640e3e127%2Fimage.png)

## 2. <�˰���>
- **��Ī**: ��Ŭ���� ȣ���� ( Euclid )
- **�Է�**: �ΰ��� ���� ��
- **���**: �Էµ� �� ���� GCD 
- **ó������** :
	1. a�� b�� ���� �������� 0���� Ȯ���Ѵ�.
	1. 0�̸� a�� ��ȯ �ƴ� �� b���� ������ ������ 1���� �ݺ��Ѵ�.

## 3. <�ڵ� ����>
1. **�ڷ� ���� ����**
	- �� ���� �� : a, b (long long int) - ����

2-1. **�Լ� ����**
- **���** : �� ���� �� a�� b�� �޾� ����Լ� ȣ�������� GCD�� ����Ѵ�.
- **������Ÿ��** : long long int euclidRecursive(long long int a, long long int b)

2-2. **�Լ� ����**
- **���** : �� ���� �� a�� b�� �޾� �ݺ��� ������� GCD�� ����Ѵ�.
- **������Ÿ��** : long long int euclidRepeat(long long int a, long long int b)  

3. **�׽�Ʈ ���̽� ����**  
TC. �� �Լ��� ȣ���Ͽ� ���� ������ Ȯ���ϴ� ���� ������ �ݺ��Ѵ�.

## 4. <�ǻ� �ڵ�>
1-1. **����Լ� ȣ���**
```
���� ����Լ�( ���� a, ���� b )
  ���� b�� 0�̶� ���ٸ�? a�� ��ȯ�Ѵ�.
  �ƴϸ�? ����Լ��� �Ű������� a�κп��� b��, b �κп��� a mod b�� �Ͽ� ȣ���Ѵ�.
  ```

1-2. **�ݺ��� ���**
```
���� �ݺ���( ���� a, ���� b )
  ���� ���� C�� �����Ѵ�.
  B�� 0�� �� �� ����
    C = b
    b = a mod b
    a = C
  a�� ��ȯ�Ѵ�.
  ```

## 5. <������>
![photo](https://i.imgur.com/5JWokih.png)

## <C�ڵ� ���� ���>
��������� ���� ( stdio.h, stdlib.h, time.h )  
Euclid
```C
// long long int �̹Ƿ� %lld�� ����� �� / ����Լ�
long long int euclidRecursive(long long int a, long long int b) {
	if (b == 0) return a;
	return euclidRecursive(b, a % b);
}

// long long int �̹Ƿ� %lld�� ����� �� / �ݺ��� �Լ�
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
// 1���� 100�� ������ ������ ���� �ִ� �׽�Ʈ ���̽�
void TC() {
	srand(time(NULL));
	double start, finish; // ����ð� üũ
	start = clock();
	
	for(int i=0; i<100000; i++){
		// 1���� 1�� ������ ���� 1���� 1000 ������ ���� ���� ���� �ش�.
		long long int a = (rand() % 100000000 + 1) * ( rand() % 1000 + 1 );
		long long int b = (rand() % 100000000 + 1) * ( rand() % 1000 + 1 );

		// �� ����� ���� ���� �´��� Ȯ��
		if ( euclidRecursive(a, b) != euclidRepeat(a, b) ) { 
			printf("Error �� ����� ���� �ٸ��ϴ�. %lld %lld,", a, b); // ������ Ȯ���� ���� a, b
			exit(1);
		}
	}

	finish = clock();
	printf("%f ms �ɷȽ��ϴ�.", finish - start);
}
```

main
```C
int main() {
	TC();
	return 0;
}
```

## <�ڵ� ����� ��ũ>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/2%EC%9E%A5/Euclid