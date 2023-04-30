#include <stdio.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

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
		printf("입력 : ");
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
	printf("1. 추가\n");
	printf("2. 출력\n");
	printf("3. 검색\n");
	printf("4. 종료\n");
	printf("====================\n");
}

void append() {
	getchar(); // 버퍼(개행문자) 제거

	printf("제목 :");
	fgets(mp5[length].song, sizeof(mp5[length].song), stdin);
	printf("가수 :");
	fgets(mp5[length].singer, sizeof(mp5[length].singer), stdin);
	printf("위치 :");
	fgets(mp5[length].loc, sizeof(mp5[length].loc), stdin);
	printf("장르(0: 가요, 1: 팝, 2: 클래식, 3: 영화음악) : ");
	scanf("%d", &mp5[length].genre);
	if (!(-1 < mp5[length].genre && mp5[length].genre < 4)) printf("ERRor! 저장 불가!");
	else length++;
}

void all_print() {
	if (length == 0) {
		printf("저장된 노래가 없습니다.\n");
		return;
	}

	for (int i = 0; i < length; i++) {
		printf("\n");
		printf("제목 : %s", mp5[i].song);
		printf("가수 : %s", mp5[i].singer);
		printf("위치 : %s", mp5[i].loc);
		printf("장르 : ");
		ret_genre(mp5[i].genre);
	}
}

void find() {
	if(length == 0) {
		printf("저장된 노래가 없습니다.\n");
		return;
	}

	char fsong[40];
	getchar(); // 버퍼(개행문자) 제거
	printf("찾고 싶은 노래 제목 : ");
	fgets(fsong, sizeof(fsong), stdin);

	for (int i = 0; i < length; i++) {
		if (strcmp(fsong, mp5[i].song) == 0) {
			printf("제목 : %s\n", mp5[i].song);
			printf("가수 : %s\n", mp5[i].singer);
			printf("위치 : %s\n", mp5[i].loc);
			printf("장르 : ");
			ret_genre(mp5[i].genre);
			return;
		}
	}
	printf("찾는 노래가 없습니다.\n");
}

void ret_genre(int a) {
	switch (a) {
	case 0:
		printf("가요\n");
		break;
	case 1:
		printf("팝\n");
		break;
	case 2:
		printf("클래식\n");
		break;
	case 3:
		printf("영화음악\n");
		break;
	}
}