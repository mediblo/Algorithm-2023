# 알고리즘 설계 구현 결과 : <'MP3'>

## 1. <문제 정의>
- **문제이름**: MP3
- **문제설명**: 음악의 제목, 가수, 위치, 장르를 추가,검색, 출력하는 프로그램을 제작

## 2. <알고리즘>
- **명칭**: MP3
- **입력**: 원하는 행동 / 음악의 제목, 가수, 위치, 장르
- **출력**: 추가, 검색, 출력
- **처리순서-추가** :
	1. 음악의 제목, 가수, 위치, 장르를 입력받아 저장한다.
- **처리순서-검색** :
	1. 원하는 음악의 제목을 입력받는다.
	2. 처음부터 검색하여 원하는 음악의 제목이 일치하면 그 음악의 정보를 출력한다.
- **처리순서-출력** :
	1. 순서대로 음악의 정보를 출력한다.

## 3. <코드 설계>
1. **자료 구조 정의**
	- 음악의 정보 : (struct) - 구조체
		- 제목 : (char song[]) - 문자열
		- 가수 : (char singer[]) - 문자열
		- 위치 : (char loc[]) - 문자열
		- 장르 : (int genre) - 정수

2. **함수 정의**
- **기능** : 음악의 정보를 추가, 검색, 출력한다.


## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, string.h ) 
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
```

## <코드 저장소 링크>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/practice/CE13_mp3/MP3