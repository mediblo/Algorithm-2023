// 230516 - 230527 까지 스스로 제작하려 하였으나 필자의 실력 부족으로 28일 GPT를 사용하여 공동 제작

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable :4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 128

typedef struct _node {
	char ch;
	int count;
	struct _node* left;
	struct _node* right;
} hNode;

hNode* root;

typedef struct _hcode {
	char ch;
	char* code;
} hCode;

hNode* make_tree(hNode* A, hNode* B);

// 이하 GPT 공동제작
hNode* huff(hNode* dict, int size);
void generate_codes(hNode* node, char* code, int depth, hCode* codes);
void compress_text(hCode* codes);
void decompress_text();
void write_bit(FILE* file, int bit);
void write_code(FILE* file, const char* code);
void free_codes(hCode* codes, int size);
void free_tree(hNode* node);
int read_bit(FILE* file);

int main() {
	FILE* fp = NULL;
	int count[MAX_SIZE] = { NULL };
	hNode dict[MAX_SIZE] = { { NULL } };
	int size = 0;

	root = NULL;
	hCode code[MAX_SIZE] = { { NULL } };

	for (int i = 0; i < MAX_SIZE; i++) {
		code[i].ch = '\0';
		code[i].code = NULL;
	}

	if ((fp = fopen("Input.txt", "r")) == NULL) return 0;

	int c;
	while ((c = fgetc(fp)) != EOF) {
		count[c]++;
	} fclose(fp);

	for (int i = 0; i < MAX_SIZE; i++) {
		if (count[i] > 0) {
			dict[size].ch = (char)i;
			dict[size].count = count[i];
			dict[size].left = NULL;
			dict[size++].right = NULL;
		}
	}

	// stats 저장
	if ((fp = fopen("stats.txt", "w")) == NULL) return 0;
	for (int i = 0; i < MAX_SIZE; i++)
		if (dict[i].count >= 1)
			fprintf(fp, "%c\t%d\n", dict[i].ch, dict[i].count);
	fclose(fp);

	root = huff(dict, size);

	char cg[MAX_SIZE] = "";
	generate_codes(root, cg, 0, code);

	compress_text(code);
	decompress_text();

	// Step 5: Free allocated memory
	free_tree(root);
	free_codes(code, size);

	printf("Compression complete.\n");

	return 0;
}

hNode* make_tree(hNode* A, hNode* B) {
	hNode* n = (hNode*)malloc(sizeof(hNode));
	n->ch = '\0';
	n->count = A->count + B->count;
	n->left = A;
	n->right = B;

	return n;
}

hNode* huff(hNode* dict, int size) {
	hNode* temp = NULL;
	hNode* root = NULL;

	while (size > 1) {
		int min1 = 0;
		int min2 = 1;

		// Find two nodes with minimum counts
		if (dict[min2].count < dict[min1].count) {
			int tempIndex = min1;
			min1 = min2;
			min2 = tempIndex;
		}

		for (int i = 2; i < size; i++) {
			if (dict[i].count < dict[min1].count) {
				min2 = min1;
				min1 = i;
			}
			else if (dict[i].count < dict[min2].count) {
				min2 = i;
			}
		}

		// Create new node and update dictionary
		hNode* A = (hNode*)malloc(sizeof(hNode));
		memcpy(A, &dict[min1], sizeof(hNode));
		hNode* B = (hNode*)malloc(sizeof(hNode));
		memcpy(B, &dict[min2], sizeof(hNode));

		temp = make_tree(A, B);

		dict[min1] = *temp;
		dict[min2] = dict[--size];

		root = temp;
	}

	return root;
}

void generate_codes(hNode* node, char* code, int depth, hCode* codes) {
	if (node->left == NULL && node->right == NULL) {
		code[depth] = '\0';
		codes[node->ch].ch = node->ch;
		codes[node->ch].code = strdup(code);
	}
	else {
		code[depth] = '0';
		if (node->left != NULL) generate_codes(node->left, code, depth + 1, codes);

		code[depth] = '1';
		if (node->right != NULL) generate_codes(node->right, code, depth + 1, codes);
	}
}

void compress_text(hCode* codes) {
	FILE* input = fopen("Input.txt", "r");
	if (input == NULL) {
		printf("Error opening input file.\n");
		return;
	}

	FILE* output = fopen("huffman.huf", "wb");
	if (output == NULL) {
		printf("Error opening output file.\n");
		fclose(input);
		return;
	}

	int c;
	while ((c = fgetc(input)) != EOF) {
		write_code(output, codes[c].code);
	}

	fclose(input);
	fclose(output);
}

void decompress_text() {
	FILE* input = fopen("huffman.huf", "rb");
	if (input == NULL) {
		printf("Error opening input file.\n");
		return;
	}

	FILE* output = fopen("output.txt", "w");
	if (output == NULL) {
		printf("Error opening output file.\n");
		fclose(input);
		return;
	}

	hNode* node = root;
	int bit;

	while ((bit = read_bit(input)) != -1) {
		if (bit == 0) {
			node = node->left;
		}
		else {
			node = node->right;
		}

		if (node->left == NULL && node->right == NULL) {
			fputc(node->ch, output);
			node = root;
		}
	}

	fclose(input);
	fclose(output);
}

void write_bit(FILE* file, int bit) {
	static int buffer = 0;
	static int count = 0;

	buffer |= (bit << (7 - count));
	count++;

	if (count == 8) {
		fputc(buffer, file);
		buffer = 0;
		count = 0;
	}
}

void write_code(FILE* file, const char* code) {
	for (int i = 0; code[i] != '\0'; i++) {
		int bit = (code[i] == '0') ? 0 : 1;
		write_bit(file, bit);
	}
}

void free_codes(hCode* codes, int size) {
	for (int i = 0; i < size; i++) {
		free(codes[i].code);
	}
}

void free_tree(hNode* node) {
	if (node == NULL) {
		return;
	}

	free_tree(node->left);
	free_tree(node->right);
	free(node);
}

int read_bit(FILE* file) {
	static int buffer = 0;
	static int count = 0;

	if (count == 0) {
		buffer = fgetc(file);
		if (buffer == EOF) {
			return -1;
		}
		count = 8;
	}

	count--;
	return ((buffer >> count) & 1);
}