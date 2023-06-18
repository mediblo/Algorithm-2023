# 알고리즘 설계 구현 결과 : < Knapsack >

## 1. <문제 정의>
- **문제이름**: Knapsack [ 배낭문제 ]
- **문제설명**: 최대 무게가 정해진 배낭과 함께 각각의 무게와 가치가 주어진 아이템의 집합이 주어졌을 때, 배낭에 담은 아이템들의 가치의 합이 최대가 되도록 하는 아이템들의 부분집합을 찾는 문제  
![photo](https://i.namu.wiki/i/D2ECBG4o-4WB-1vczJK_sJZoKhYSuFpEWav7sGkymvug3mJkjOckGvlqPq0Bw3tvnu3S0xgHynl4A6z3aAUfWA_9a_3kG-revgFs0zjmB9ghkfedIgLA6VO98IlIFARPyjqCk-o2LLkn7bIYKGCYjg.webp)

## 2. <함수 정의>
- **기능** : 최댓값 찾는 함수
- **프로토타입** : int max(int a, int b)
- **기능** : 배낭 문제 알고리즘
- **프로토타입** : int* knapsack(item it[], int bag, int count)
- **기능** : 배낭 문제 알고리즘 출력
- **프로토타입** : void print_knapsack(int* rst, int bag, int count)


## <C코드 구현 결과>
라이브러리 헤더 파일은 생략 ( stdio.h, stdlib.h )  

item 구조체 정의
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

Knapsack 함수
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
print_knapsack 함수
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
main 함수
```C
	FILE* fp = NULL;
	int* rst;

	int bag = 20;
	int count = 0;
	char temp[10]; // 경고 문구 없애기

	if ((fp = fopen("items.txt", "r")) == 0) return 0;

	while (feof(fp) == NULL) { // 물건 갯수 세기
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

## <코드 저장소 링크>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/Chapter_5/Knapsack