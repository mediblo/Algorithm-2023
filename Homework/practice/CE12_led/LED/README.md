# �˰��� ���� ���� ��� : <'LED'>

## 1. <���� ����>
- **�����̸�**: LED ������
- **��������**: LED ������ó�� �Ѵܾ �з� ���δ�.

## 2. <�˰���>
- **��Ī**: LED������ ( LED )
- **�Է�**: ���� ���ڿ�
- **���**: �������� ���ڿ�
- **ó������** :
	1. ���ڿ��� ����Ѵ�.
	2. ���ڿ��� ù ��° �ܾ ���� ���δ�.
	3. 1-2���� �ݺ��Ѵ�.

## 3. <�ڵ� ����>
1. **�ڷ� ���� ����**
	- ���ڿ� : (char msg[]) - ���ڿ�

2. **�Լ� ����**
- **���** : ���ڿ��� �޾� �и鼭 ����Ѵ�.


## <C�ڵ� ���� ���>
��������� ���� ( stdio.h, string.h, windows.h ) 
```c
int main() {
	char msg[80];
	char temp[80];
	int len;
	printf("�����ϰ� ���� �ؽ�Ʈ�� �Է��Ͻÿ� : ");
	gets_s(msg, sizeof(msg));
	
	len = strlen(msg);

	for (int i = 0; i <= len; i++) {
		system("cls");
		printf("%s\n", msg);
		strcpy(temp, msg + 1);
		strncat(temp, msg, 1);
		strcpy(msg, temp);
		Sleep(200);
	}

	return 0;
}
```

## <�ڵ� ����� ��ũ>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/practice/CE12_led/LED