# �˰��� ���� ���� ��� : <����>

## 1. <���� ����>
- **�����̸�**: ����
- **��������**: ���� 2���� �Է¹޾� ���ϴ� ��Ģ������ �����Ѵ�.
- **��������** : ���� �׸��� �����̴�.  
![photo](https://i.namu.wiki/i/_i4dszQjFT8YnXRFtyEVUcgXAwmZM5GnhK_y6P2MZKm6s46tky3xLazJ3xB2Q8_33_u5DsBE3yBzlnzpWbyRy8xbA3qb7_rwhKQKJdZLgU1mQTtIeeTsf5gDxv-R01tnqHBAoPbAN6L9DgeVvZcFpA.webp)

## 2. <�˰���>
- **��Ī**: ���� ( calculator )
- **�Է�**: ���� 2��
- **���**: ���ϴ� ��Ģ����
- **ó������** :
	1. ���� 2���� �Է¹޴´�
	2. ���ϴ� ��Ģ������ ����
	3. ��� ���� �����Ѵ�

## 3. <�ڵ� ����>
1. **�ڷ� ���� ����**
	- ���� 2�� : (int a, b) - ����

2. **�Լ� ����**
- **���** : ���� 2���� �Է¹޾� ���ϴ� ��Ģ������ ���Ѵ�.


## <C�ڵ� ���� ���>
��������� ���� ( stdio.h ) 
```c
void printMenu();
int choose();
void calcul(int c);
// ���ϱ�
void plus();
// ����
void minus();
// ����
void triple();
// ������
void quotient();
// ������
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
	printf("1. ����\n");
	printf("2. ����\n");
	printf("3. ����\n");
	printf("4. ������\n");
	printf("5. ������\n");
}

int choose() {
	int a;
	printf("���ϴ� �޴��� �����Ͻÿ�(1-5): ");
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
	printf("���� 2���� �Է��Ͻÿ� : ");
	scanf("%d %d", &A, &B);

	printf("������ : %d", A + B);
}

void minus() {
	int A, B;
	printf("���� 2���� �Է��Ͻÿ� : ");
	scanf("%d %d", &A, &B);

	printf("������ : %d", A - B);
}
void triple() {
	int A, B;
	printf("���� 2���� �Է��Ͻÿ� : ");
	scanf("%d %d", &A, &B);

	printf("������ : %.2f", (float)A * B);
}
void quotient() {
	int A, B;
	printf("���� 2���� �Է��Ͻÿ� : ");
	scanf("%d %d", &A, &B);

	printf("������ : %d", A / B);
}
void remainder() {
	int A, B;
	printf("���� 2���� �Է��Ͻÿ� : ");
	scanf("%d %d", &A, &B);

	printf("������ : %d", A % B);
}
```

## <�ڵ� ����� ��ũ>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/practice/CE08_calcul/Calculator