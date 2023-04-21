#include <stdio.h>

#define max_size 12

int A[max_size] = { 6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14};

void merge(int p, int q);

int main() {

	for (int i = 0; i < max_size; i++) printf("%d ", A[i]);
	printf("\n");
	printf("==========================\n");
	merge(0, max_size);

	printf("==========================\n");
	for (int i = 0; i < max_size; i++) printf("%d ", A[i]);
	printf("\n");
	return 0;
}

void merge(int p, int q) {
	if (p < q) {
		int k = (p + q) / 2;

		merge(p, k);
		merge(k + 1, q);
		printf("[%d %d %d]\t", p, q, k);

		int ci = 0;
		int ai = p;
		int bi = k + 1;		
		int C[max_size + 1]{};

		while (ci+1 <= q - p + 1)
		{
			if (bi > q) bi = p;
			else if (ci + 1 < q - p + 1 && ai == bi) bi++, printf("[LV] ");
			if (A[ai] < A[bi]) C[ci++] = A[ai++], printf("[%d %d] ", A[ai - 1], A[bi]);
			else C[ci++] = A[bi++], printf("(%d %d) ", A[ai], A[bi - 1]);
		}

		for(int i=0, j=p; i < q - p + 1; i++, j++) A[j] = C[i];
		for (int i = 0; i < max_size; i++) printf("%d ", A[i]);
		printf("\n");
	}
}