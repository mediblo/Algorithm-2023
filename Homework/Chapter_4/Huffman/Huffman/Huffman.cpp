// 230516 - 230527 까지 스스로 제작하려 하였으나 필자의 실력 부족으로 28일 GPT를 사용하여 공동 제작

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable :4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 128

// 문자의 데이터를 저장하여 허프만 트리로 구성할 구조체
typedef struct _node {
	char ch;
	int count;
	struct _node* left;
	struct _node* right;
} hNode;

hNode* root;

// 허프만 파일로 작성하기 전 문자의 데이터를 이진 데이터와 함께 묶기 위한 구조체
typedef struct _hcode {
	char ch;
	char* code;
} hCode;

// 허프만 트리 제작하기 위해 빈도수가 적은 A, B를 합쳐 반환
hNode* make_tree(hNode* A, hNode* B);
// 이하 GPT 공동제작

// 허프만 트리 제작 함수 ( make_tree사용해서 반복적으로 합친 최종 트리를 반환 )
hNode* huff(hNode* dict, int size);
// 처음부터 시작하여 L은 0, R은 1로 가서 마지막으로 갈 경우 이진 데이터를 codes에 삽입
void generate_codes(hNode* node, char* code, int depth, hCode* codes);
// Input.txt 를 압축하여 huffman.huf으로 내보내는 함수, write_bit, write_code 함수를 사용한다.
void compress_text(hCode* codes);
// huffman.huf를 해제하여 Output.txt으로 내보내는 함수, read_bit 함수를 사용한다.
void decompress_text();
// 매개변수 bit으로 판단하여 비트를 file에 쓰는 함수
void write_bit(FILE* file, int bit);
// 문자를 읽어 그에 맞는 code를 통해 이진 데이터로 쓰는 함수, write_bit를 사용한다.
void write_code(FILE* file, const char* code);
// 코드 구조체 메모리 할당 해제
void free_codes(hCode* codes, int size);
// 노드 구조체 메모리 할당 해제
void free_tree(hNode* node);
// 비트를 읽어서 문자로 치환하는 함수
int read_bit(FILE* file);

int main() {
	FILE* fp = NULL;
	int count[MAX_SIZE] = { NULL };
	hNode dict[MAX_SIZE] = { { NULL } };
	int size = 0;

	root = NULL;
	hCode code[MAX_SIZE] = { { NULL } };

	// code 구조체 초기화
	for (int i = 0; i < MAX_SIZE; i++) {
		code[i].ch = '\0';
		code[i].code = NULL;
	}

	// Input.txt 파일 열기
	if ((fp = fopen("Input.txt", "r")) == NULL) return 0;

	// 문자 빈도수 카운트
	int c;
	while ((c = fgetc(fp)) != EOF) {
		count[c]++;
	} fclose(fp);

	// 문자 데이터를 노드 구조체 데이터로 치환
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

	// 허프만 제작
	root = huff(dict, size);

	// 허프만 트리를 사용해서 문자에 코드 데이터 삽입
	char cg[MAX_SIZE] = "";
	generate_codes(root, cg, 0, code);

	// 압축 및 해제
	compress_text(code);
	decompress_text();

	// 동적 메모리 할당 전부 해제
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

		// 최솟값 2개 찾기
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

		// 약한 복사를 위해 노드 2개 생성
		hNode* A = (hNode*)malloc(sizeof(hNode));
		memcpy(A, &dict[min1], sizeof(hNode));
		hNode* B = (hNode*)malloc(sizeof(hNode));
		memcpy(B, &dict[min2], sizeof(hNode));

		temp = make_tree(A, B);

		// 강한 복사를 하면 아래 2줄로 인하여 트리가 꼬이게 됨
		dict[min1] = *temp;
		dict[min2] = dict[--size];

		root = temp;
	}

	return root;
}

void generate_codes(hNode* node, char* code, int depth, hCode* codes) {
	if (node->left == NULL && node->right == NULL) { // 리프 노드일 경우 코드 저장
		code[depth] = '\0';
		codes[node->ch].ch = node->ch;
		codes[node->ch].code = strdup(code);
	}
	else {
		code[depth] = '0'; // 왼쪽
		if (node->left != NULL) generate_codes(node->left, code, depth + 1, codes);

		code[depth] = '1'; // 오른쪽
		if (node->right != NULL) generate_codes(node->right, code, depth + 1, codes);
	}
}

void compress_text(hCode* codes) {
	FILE* input, * output;
	// 파일 열기
	if ((input = fopen("Input.txt", "r")) == NULL) {
		printf("Error opening input file.\n");
		return;
	}
	if ((output = fopen("huffman.huf", "wb")) == NULL) {
		printf("Error opening output file.\n");
		fclose(input);
		return;
	}

	// 문자마다 write_code() 호출
	int c;
	while ((c = fgetc(input)) != EOF) {
		write_code(output, codes[c].code);
	}

	fclose(input);
	fclose(output);
}

void decompress_text() {
	FILE* input, * output;
	// 파일 열기
	if ((input = fopen("huffman.huf", "rb")) == NULL) {
		printf("Error opening input file.\n");
		return;
	}
	if ((output = fopen("output.txt", "w")) == NULL) {
		printf("Error opening output file.\n");
		fclose(input);
		return;
	}

	hNode* node = root;
	int bit;

	while ((bit = read_bit(input)) != -1) {
		// bit 읽으면서 내려가기
		if (bit == 0) node = node->left;
		else node = node->right;

		// 리프 노드 일 때 문자 출력
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

	// 버퍼에 비트 데이터를 저장
	buffer |= (bit << (7 - count));
	count++;

	// 다 읽었으면 출력 후 버퍼 초기화
	if (count == 8) {
		fputc(buffer, file);
		buffer = 0;
		count = 0;
	}
}

void write_code(FILE* file, const char* code) {
	// 비트 데이터 읽기
	for (int i = 0; code[i] != '\0'; i++) {
		int bit = (code[i] == '0') ? 0 : 1;
		write_bit(file, bit);
	}
}

void free_codes(hCode* codes, int size) {
	// 메모리 할당 해제
	for (int i = 0; i < size; i++) {
		free(codes[i].code);
	}
}

void free_tree(hNode* node) {
	// 메모리 할당 해제
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
	// 비트 읽고 파일의 끝이 되면 -1 출력
	// decompress_text() 함수와 같이 해석하기 바람
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