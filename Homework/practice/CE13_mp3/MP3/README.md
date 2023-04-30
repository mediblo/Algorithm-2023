# �˰��� ���� ���� ��� : <'MP3'>

## 1. <���� ����>
- **�����̸�**: MP3
- **��������**: ������ ����, ����, ��ġ, �帣�� �߰�,�˻�, ����ϴ� ���α׷��� ����

## 2. <�˰���>
- **��Ī**: MP3
- **�Է�**: ���ϴ� �ൿ / ������ ����, ����, ��ġ, �帣
- **���**: �߰�, �˻�, ���
- **ó������-�߰�** :
	1. ������ ����, ����, ��ġ, �帣�� �Է¹޾� �����Ѵ�.
- **ó������-�˻�** :
	1. ���ϴ� ������ ������ �Է¹޴´�.
	2. ó������ �˻��Ͽ� ���ϴ� ������ ������ ��ġ�ϸ� �� ������ ������ ����Ѵ�.
- **ó������-���** :
	1. ������� ������ ������ ����Ѵ�.

## 3. <�ڵ� ����>
1. **�ڷ� ���� ����**
	- ������ ���� : (struct) - ����ü
		- ���� : (char song[]) - ���ڿ�
		- ���� : (char singer[]) - ���ڿ�
		- ��ġ : (char loc[]) - ���ڿ�
		- �帣 : (int genre) - ����

2. **�Լ� ����**
- **���** : ������ ������ �߰�, �˻�, ����Ѵ�.


## <C�ڵ� ���� ���>
��������� ���� ( stdio.h, string.h ) 
```c
typedef struct {
	char song[40];
	char singer[30];
	char loc[40];
	int genre;
}MP3;

MP3 mp5[30];
int length = 0;

void print_menu();
void append();
void all_print();
void find();
void del();
void ret_genre(int a);

int main() {
	int choice;

	do {
		print_menu();
		printf("�Է� : ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				append();
				break;
			case 2:
				all_print();
				break;
			case 3:
				find();
				break;
			case 4:
				break;
			default:
				printf("ERRor");
		}
	} while (choice != 4);

	return 0;
}

void print_menu() {
	printf("====================\n");
	printf("1. �߰�\n");
	printf("2. ���\n");
	printf("3. �˻�\n");
	printf("4. ����\n");
	printf("====================\n");
}

void append() {
	getchar(); // ����(���๮��) ����

	printf("���� :");
	fgets(mp5[length].song, sizeof(mp5[length].song), stdin);
	printf("���� :");
	fgets(mp5[length].singer, sizeof(mp5[length].singer), stdin);
	printf("��ġ :");
	fgets(mp5[length].loc, sizeof(mp5[length].loc), stdin);
	printf("�帣(0: ����, 1: ��, 2: Ŭ����, 3: ��ȭ����) : ");
	scanf("%d", &mp5[length].genre);
	if (!(-1 < mp5[length].genre && mp5[length].genre < 4)) printf("ERRor! ���� �Ұ�!");
	else length++;
}

void all_print() {
	if (length == 0) {
		printf("����� �뷡�� �����ϴ�.\n");
		return;
	}

	for (int i = 0; i < length; i++) {
		printf("\n");
		printf("���� : %s", mp5[i].song);
		printf("���� : %s", mp5[i].singer);
		printf("��ġ : %s", mp5[i].loc);
		printf("�帣 : ");
		ret_genre(mp5[i].genre);
	}
}

void find() {
	if(length == 0) {
		printf("����� �뷡�� �����ϴ�.\n");
		return;
	}

	char fsong[40];
	getchar(); // ����(���๮��) ����
	printf("ã�� ���� �뷡 ���� : ");
	fgets(fsong, sizeof(fsong), stdin);

	for (int i = 0; i < length; i++) {
		if (strcmp(fsong, mp5[i].song) == 0) {
			printf("���� : %s\n", mp5[i].song);
			printf("���� : %s\n", mp5[i].singer);
			printf("��ġ : %s\n", mp5[i].loc);
			printf("�帣 : ");
			ret_genre(mp5[i].genre);
			return;
		}
	}
	printf("ã�� �뷡�� �����ϴ�.\n");
}

void ret_genre(int a) {
	switch (a) {
	case 0:
		printf("����\n");
		break;
	case 1:
		printf("��\n");
		break;
	case 2:
		printf("Ŭ����\n");
		break;
	case 3:
		printf("��ȭ����\n");
		break;
	}
}
```

## <�ڵ� ����� ��ũ>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/practice/CE13_mp3/MP3