# �˰��� ���� ���� ��� : < Knapsack >

## 1. <���� ����>
- **�����̸�**: Knapsack [ �賶���� ]
- **��������**: �ִ� ���԰� ������ �賶�� �Բ� ������ ���Կ� ��ġ�� �־��� �������� ������ �־����� ��, �賶�� ���� �����۵��� ��ġ�� ���� �ִ밡 �ǵ��� �ϴ� �����۵��� �κ������� ã�� ����  
![photo](https://i.namu.wiki/i/D2ECBG4o-4WB-1vczJK_sJZoKhYSuFpEWav7sGkymvug3mJkjOckGvlqPq0Bw3tvnu3S0xgHynl4A6z3aAUfWA_9a_3kG-revgFs0zjmB9ghkfedIgLA6VO98IlIFARPyjqCk-o2LLkn7bIYKGCYjg.webp)

## 2. <�Լ� ����>
- **���** : �ִ� ã�� �Լ�
- **������Ÿ��** : int max(int a, int b)
- **���** : �賶 ���� �˰���
- **������Ÿ��** : int* knapsack(item it[], int bag, int count)
- **���** : �賶 ���� �˰��� ���
- **������Ÿ��** : void print_knapsack(int* rst, int bag, int count)


## <C�ڵ� ���� ���>
���̺귯�� ��� ������ ���� ( stdio.h, stdlib.h )  

item ����ü ����
```C
typedef struct {
	int num;
	int kg;
	int price;
} item;
```

item.txt
```
1 5 7
2 1 6
3 3 9
4 2 5
5 6 8
6 1 9
```

Knapsack �Լ�
```C
	int* rst = (int*)malloc(sizeof(int) * (bag + 1) * (count + 1));

	for (int i = 0; i <= count; i++) *(rst + (i * (bag + 1))) = 0;
	for (int i = 0; i <= bag; i++) *(rst + i) = 0;

	for (int i = 1; i <= count; i++) {
		for (int j = 1; j <= bag; j++) {
			if (it[i].kg > j) *(rst + (i * (bag + 1)) + j) = *(rst + ((i - 1) * (bag + 1)) + j);
			else *(rst + (i * (bag + 1)) + j) = max(*(rst + ((i - 1) * (bag + 1)) + j), *(rst + ((i - 1) * (bag + 1)) + j - it[i].kg) + it[i].price);
		}
	}

	return (int*)rst;
}
```
print_knapsack �Լ�
```C
	printf("No]");
	for (int i = 0; i <= bag; i++) printf("%3d ", i);
	printf("\n");

	for (int i = 0; i <= count; i++) {
		printf("%d] ", i);
		for (int j = 0; j <= bag; j++) {
			printf("%3d ", *(rst + (i * (bag + 1)) + j));
		}
		printf("\n");
	}
```
main �Լ�
```C
	FILE* fp = NULL;
	int* rst;

	int bag = 20;
	int count = 0;
	char temp[10]; // ��� ���� ���ֱ�

	if ((fp = fopen("items.txt", "r")) == 0) return 0;

	while (feof(fp) == NULL) { // ���� ���� ����
		fgets(temp, 10, fp);
		count++;
	}

	fseek(fp, 0, SEEK_SET);

	item* it = (item*)malloc(sizeof(item) * (count + 1));

	for (int i = 1; i <= count; i++)
		temp[0] = fscanf(fp, "%d %d %d", &it[i].num, &it[i].kg, &it[i].price);
	fclose(fp);


	rst = knapsack(it, bag, count);

	print_knapsack(rst, bag, count);

	free(it);
	return 0;
```

## <�ڵ� ����� ��ũ>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/Chapter_5/Knapsack