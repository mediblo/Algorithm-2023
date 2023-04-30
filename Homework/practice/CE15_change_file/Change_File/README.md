# �˰��� ���� ���� ��� : <������ Ư�� �ܾ �����ϱ�>

## 1. <���� ����>
- **�����̸�**: ������ Ư�� �ܾ �����ϱ�
- **��������**: ������ Ư�� �ܾ�(ex : Android)�� ����(ex : �ȵ���̵�)�Ѵ�.

## 2. <�˰���>
- **��Ī**: change_file
- **�Է�**: �ؽ�Ʈ ���� ( ���ڿ� )
- **���**: ������ ���ڿ� ( �ؽ�Ʈ ���� )
- **ó������** :
	1. �ؽ�Ʈ������ �о� ���ڿ��� �����Ѵ�.
	2. Ư�� �ܾ �ִ��� Ȯ���Ͽ� ������ �����Ѵ�.
	3. ������ ���ڿ��� �ٽ� ���Ͽ� �����Ѵ�.

## 3. <�ڵ� ����>
1. **�ڷ� ���� ����**
	- ���� : (FILE* fp) - ����
	- ���ڿ� : (char temp[]) - ���ڿ�

2. **�Լ� ����**
- **���** : ������ ���ڿ��� �о� �����Ͽ� �����Ѵ�.


## <C�ڵ� ���� ���>
��������� ���� ( stdio.h, stdlib.h, string.h ) 
```c
// Before : Android 4.1, JellyBean, is the fastest and smoothest version of Android yet.
// After  : �ȵ���̵� 4.1, JellyBean, is the fastest and smoothest version of Android yet.

int main() {
	FILE* fp;
	char temp[200];
	char* ptmp = NULL;
	bool flag = true;

	fp = fopen("test.txt", "r+");
	if (fp == NULL) {
		printf("���ϸ���");
		exit(1);
	}
	fgets(temp, 200, fp);

	printf("%s\n", temp);

	fflush(fp);
	fseek(fp, 0, SEEK_SET);

	ptmp = strtok(temp, " ");
	while (ptmp != NULL) {
		if (flag && strcmp(ptmp, "Android") == 0) {
			flag = false;
			fprintf(fp, "�ȵ���̵� ");
			ptmp = strtok(NULL, " ");
			continue;
		}
		fprintf(fp, "%s ",ptmp);
		ptmp = strtok(NULL, " ");
	}

	fclose(fp);
	return 0;
}
```

## <�ڵ� ����� ��ũ>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/practice/CE15_change_file/Change_File