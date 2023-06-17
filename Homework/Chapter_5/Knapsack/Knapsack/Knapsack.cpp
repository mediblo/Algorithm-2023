// Knapsack 알고리즘
// 202011437 컴퓨터공학과 정용진
// 2023-05-31

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num;
	int kg;
	int price;
} item;

int max(int a, int b) { return a > b ? a : b; }

int* knapsack(item it[], int bag, int count) {
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

void print_knapsack(int* rst, int bag, int count) {
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
}

int main() {
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
}