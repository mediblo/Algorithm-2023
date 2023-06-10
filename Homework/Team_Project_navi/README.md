# 알고리즘 설계 구현 결과 : <학교 네비게이션>

## 1. <프로젝트 정의>
- **프로젝트 이름**: 학교 네비게이션
- **프로젝트 설명**: 학교에 있는 건물들에 대한 최선의 길을 알려준다.
- **학교 사진**  
![photo](https://i.imgur.com/aCKSImu.png)
## 2. <알고리즘>
- **명칭**: 다익스트라
- **입력**: 건물들 가중치
- **출력**: 최적의 가중치
---
- **명칭** : 순차탐색
- **입력** : 건물들 빈도수
- **출력** : 많이 불린 건물들

## 3. <코드 설계>
1. **자료 구조 정의**
	- 그래프 : (struct[][]) - Graph
      - 연결 여부 : (int) - connected
      - 거리 : (int) - distance
	- 빈도수 : (int[][]) - fast_data

2. **함수 정의**
-  **PDCurses 준비** void init_pcr();
- **데이터 불러오기** void load_data();
- **로고 출력** void print_navi();
- **시작 메뉴 출력** int menu();
- **출발점, 도착점** void set_building();
- **변경** void change_building();
- **변경점 출력** void print_change_graph(int start, int finish);
- **변경 및 저장** void change_graph(int start, int finish, int new_Value);
- **최단경로 알고리즘 [ 무석, 정원 ]** void calculate_distance(int start, int finish);
- **데이터 저장** void save_data();
- **에러 처리** void error(int code);
- **빠른 시작** void fast_start();


## <C코드 구현 결과>
헤더파일은 생략 ( stdio.h, string.h, stdlib.h, limits.h, curses.h [ PDCurses ] ) 
```c
int main() {
    init_pcr();
    load_data();
    // print_map();

    int sel_key = 0;
    while (1) {
        sel_key = menu();

        switch (sel_key)
        {
        case 0:
            set_building();
            break;
        case 1:
            fast_start();
            break;
        case 2:
            change_building();
            break;
        case 3:
            // PDcurses 종료
            save_data();
            endwin();
            return 0;
        default:
            break;
        }
    }

    // PDcurses 종료 && 이례적인 종료
    endwin();
    error(5);
    return 0;
}

void error(int code) {
    switch (code) {
    case 1:
        printf("그래프 데이터 불러오기 에러");
        break;
    case 2:
        printf("빠른 데이터 불러오기 에러");
        break;
    case 3:
        printf("그래프 데이터 저장 에러");
        break;
    case 4:
        printf("빠른 데이터 저장 에러");
        break;
    case 5:
        printf("이례적인 에러!!");
        break;
    default:
        printf("입력 매개변수 값이 이상합니다.");
        break;
    }
    exit(1);
}

void init_pcr() {
    // PDcurses 초기화
    initscr();
    cbreak(); // 입력 스트림 버퍼링 해제
    noecho(); // 사용자 입력 화면에 안뜸
    keypad(stdscr, TRUE); // 특수키 사용 여부 ( 화살표 키 )
}

void load_data() {
    FILE* fp = NULL;
    int temp = 0;

    if ((fp = fopen("graph_text.bin", "rb")) == NULL) { // 가중치 표 이진파일 불러오기
        endwin();
        error(1);
    }
    fread(&buildings, sizeof(buildings), 1, fp);
    fclose(fp);

    if ((fp = fopen("fast.bin", "rb")) == NULL) { // 빈도수 표 이진파일 불러오기
        endwin();
        error(2);
    }
    fread(&fast_data, sizeof(fast_data), 1, fp);
    fclose(fp);
}

// 메인 로고 네비
void print_navi() {
    int x = 30;
    mvprintw(1, x, "@@@         @@@  @@\t\t@@@      @@@  @@");
    mvprintw(2, x, "@@@         @@@  @@\t\t@@@      @@@  @@");
    mvprintw(3, x, "@@@      @@@@@@  @@\t\t@@@@@@@@@@@@  @@");
    mvprintw(4, x, "@@@         @@@  @@\t\t@@@@@@@@@@@@  @@");
    mvprintw(5, x, "@@@@@@@@@   @@@  @@\t\t@@@      @@@  @@");
    mvprintw(6, x, "@@@@@@@@@   @@@  @@\t\t@@@@@@@@@@@@  @@");
}

int menu() {
    int sel = 0;
    const char* menu_bar[] = { "시작", "빠른 시작", "설정", "나가기" };

    while (1) {
        clear();
        print_navi();

        // 4가지 모드 선택
        for (int i = 0; i < 4; i++) {
            if (i == sel) {
                attron(A_REVERSE);
                mvprintw(15, 30 + (i * 15), ">%s<", menu_bar[i]);
                attroff(A_REVERSE);
            }
            else {
                mvprintw(15, 30 + (i * 15), " %s ", menu_bar[i]);
            }
            printw(" ");
        }

        mvprintw(21, 26, "이동 - 화살표 [ w a s d ] / 선택 - Enter or Space / q - 뒤로가기");

        mvprintw(24, 42, "*");
        for (int i = 0; i < 33; i++) mvprintw(24, 43 + i, "-"); mvprintw(24, 76, "*");
        mvprintw(25, 42, "|");
        mvprintw(25, 44, "꼭 나가기를 하셔야 저장됩니다!"); mvprintw(25, 76, "|");
        mvprintw(26, 42, "*");
        for (int i = 0; i < 33; i++) mvprintw(26, 43 + i, "-"); mvprintw(26, 76, "*");

        // 키 입력 이벤트 처리
        int key = getch();
        int k_size = sizeof(menu_bar) / sizeof(menu_bar[0]);
        switch (key) {
        case KEY_LEFT:
        case 'a':
        case 'A':
            sel = (sel - 1 + k_size) % k_size;
            break;
        case KEY_RIGHT:
        case 'd':
        case 'D':
            sel = (sel + 1) % k_size;
            break;
        case 10:  // Enter 키
        case 32:  // Space Bar 키
            // 선택된 메뉴 항목 처리
            return sel;
        case 'q':
            return 3;
        default:
            break;
        }
    }
}

void set_building() {
    const char* building[] = { "목민관", "제2학생회관", "제1자연관", "인문사회관", "예술관", "사범관",
                    "제1학생회관", "바이오융합관", "행정관", "제2자연관", "미래창조관", "글로벌관", "체육관", "비전관" };
    int sel = 0;
    int temp = 0;
    int start = -1, finish = -1;

    bool flag = FALSE; // 시작 버튼 생성 확인

    while (1) {
        clear();

        if (flag == FALSE && (start != -1 && finish != -1)) flag = TRUE;

        // 출발점 출력 [ 0 ~ 13 ]
        for (int i = 0; i < 14; i++) {
            if (i == sel) {
                if (i == start) attron(A_REVERSE);
                mvprintw(i < 7 ? 15 : 16, i < 7 ? 2 + (i * 15) : 2 + ((i - 7) * 15), ">%s<", building[i]);
                if (i == start) attroff(A_REVERSE);
            }
            else {
                if (i == start) attron(A_REVERSE);
                mvprintw(i < 7 ? 15 : 16, i < 7 ? 2 + (i * 15) : 2 + ((i - 7) * 15), " %s ", building[i]);
                if (i == start) attroff(A_REVERSE);
            }
            printw(" ");
        }

        // 구분선 긋기
        mvprintw(18, 1, "*");
        for (int i = 2; i < 110; i++) mvprintw(18, i, "-"); mvprintw(18, 110, "*");

        // 도착점 출력 [ 14 ~ 27 ]
        for (int i = 0; i < 14; i++) {
            if (i + 14 == sel) {
                if (i == finish) attron(A_REVERSE);
                mvprintw(i < 7 ? 20 : 21, i < 7 ? 2 + (i * 15) : 2 + ((i - 7) * 15), ">%s<", building[i]);
                if (i == finish) attroff(A_REVERSE);
            }
            else {
                if (i == finish) attron(A_REVERSE);
                mvprintw(i < 7 ? 20 : 21, i < 7 ? 2 + (i * 15) : 2 + ((i - 7) * 15), " %s ", building[i]);
                if (i == finish) attroff(A_REVERSE);
            }
            printw(" ");
        }

        mvprintw(8, 52, "출발점 : %s", start != -1 ? building[start] : "");
        mvprintw(9, 52, "도착점 : %s", finish != -1 ? building[finish] : "");
        if (start != -1 && start == finish) { // 중첩 확인
            mvprintw(3, 44, "*");
            for (int i = 0; i < 32; i++) mvprintw(3, 45 + i, "-"); mvprintw(3, 77, "*");
            mvprintw(4, 44, "|");
            mvprintw(4, 46, "같은 곳은 확인이 불가능합니다."); mvprintw(4, 77, "|");
            mvprintw(5, 44, "*");
            for (int i = 0; i < 32; i++) mvprintw(5, 45 + i, "-"); mvprintw(5, 77, "*");
        }


        if (flag) { // 시작 버튼 생성
            if (sel == 28) attron(A_REVERSE);
            mvprintw(23, 55, "*");
            for (int i = 0; i < 6; i++) mvprintw(23, 56 + i, "-"); mvprintw(23, 62, "*");
            mvprintw(24, 55, "|");
            mvprintw(24, 56, "-시작-"); mvprintw(24, 62, "|");
            mvprintw(25, 55, "*");
            for (int i = 0; i < 6; i++) mvprintw(25, 56 + i, "-"); mvprintw(25, 62, "*");
            if (sel == 28) attroff(A_REVERSE);
        }

        // 키 입력 이벤트 처리
        int key = getch();
        int k_size = flag ? (sizeof(building) / sizeof(building[0]) * 2) + 1 : sizeof(building) / sizeof(building[0]) * 2; // 전체 크기 저장
        switch (key) {
        case KEY_LEFT:
        case 'a':
        case 'A':
            if (sel == 0 && flag) break; // 시작 활성화 시 왼쪽 끝일시 멈춤
            sel = (sel - 1 + k_size) % k_size;
            break;
        case KEY_RIGHT:
        case 'd':
        case 'D':
            if (sel == 27 && flag) break; // 시작 활성화 시 오른쪽 끝일시 멈춤
            sel = (sel + 1) % k_size;
            break;
        case KEY_UP: // 위
        case 'w':
        case 'W':
            if (sel == 28) sel = temp; // 시작 활성화 시 시작 위치에서 올라갈 때 그 전 위치로
            else sel = (sel - 7 + k_size) % k_size;
            break;
        case KEY_DOWN: // 아래
        case 's':
        case 'S':
            if ((sel + 7) >= 28 && flag) { // 시작 활성화 시 시작으로 내려갈 때 위치 저장
                if (sel != 28)temp = sel;
                sel = 28;
            }
            else sel = (sel + 7) % k_size;
            break;
        case 10:  // Enter 키
        case 32:  // Space Bar 키
            if (sel == 28 && !(start == finish)) // 시작 버튼
                calculate_distance(start, finish);
            else if (sel >= 14)
                finish = sel % 14;
            else
                start = sel;
            break;
        case 'q':
            return;
        default:
            break;
        }
    }
}

void change_building() {
    const char* building[] = { "목민관", "제2학생회관", "제1자연관", "인문사회관", "예술관", "사범관",
                    "제1학생회관", "바이오융합관", "행정관", "제2자연관", "미래창조관", "글로벌관", "체육관", "비전관" };
    int sel = 0;
    int temp = 0;
    int start = -1, finish = -1;

    bool flag = FALSE; // 시작 버튼 생성 확인

    while (1) {
        clear();

        if (flag == FALSE && (start != -1 && finish != -1)) flag = TRUE;

        // 출발점 출력 [ 0 ~ 13 ]
        for (int i = 0; i < 14; i++) {
            if (i == sel) {
                if (i == start) attron(A_REVERSE);
                mvprintw(i < 7 ? 15 : 16, i < 7 ? 2 + (i * 15) : 2 + ((i - 7) * 15), ">%s<", building[i]);
                if (i == start) attroff(A_REVERSE);
            }
            else {
                if (i == start) attron(A_REVERSE);
                mvprintw(i < 7 ? 15 : 16, i < 7 ? 2 + (i * 15) : 2 + ((i - 7) * 15), " %s ", building[i]);
                if (i == start) attroff(A_REVERSE);
            }
            printw(" ");
        }

        // 구분선 긋기
        mvprintw(18, 1, "*");
        for (int i = 2; i < 110; i++) mvprintw(18, i, "-"); mvprintw(18, 110, "*");

        // 도착점 출력 [ 14 ~ 27 ]
        for (int i = 0; i < 14; i++) {
            if (i + 14 == sel) {
                if (i == finish) attron(A_REVERSE);
                mvprintw(i < 7 ? 20 : 21, i < 7 ? 2 + (i * 15) : 2 + ((i - 7) * 15), ">%s<", building[i]);
                if (i == finish) attroff(A_REVERSE);
            }
            else {
                if (i == finish) attron(A_REVERSE);
                mvprintw(i < 7 ? 20 : 21, i < 7 ? 2 + (i * 15) : 2 + ((i - 7) * 15), " %s ", building[i]);
                if (i == finish) attroff(A_REVERSE);
            }
            printw(" ");
        }
        mvprintw(8, 50, "변경 출발점 : %s", start != -1 ? building[start] : "");
        mvprintw(9, 50, "변경 도착점 : %s", finish != -1 ? building[finish] : "");
        if (start != -1 && start == finish) { // 중첩 확인
            mvprintw(3, 44, "*");
            for (int i = 0; i < 32; i++) mvprintw(3, 45 + i, "-"); mvprintw(3, 77, "*");
            mvprintw(4, 44, "|");
            mvprintw(4, 46, "같은 곳 선택은 불가능합니다."); mvprintw(4, 77, "|");
            mvprintw(5, 44, "*");
            for (int i = 0; i < 32; i++) mvprintw(5, 45 + i, "-"); mvprintw(5, 77, "*");
        }


        if (flag) { // 시작 버튼 생성
            if (sel == 28) attron(A_REVERSE);
            mvprintw(23, 55, "*");
            for (int i = 0; i < 6; i++) mvprintw(23, 56 + i, "-"); mvprintw(23, 62, "*");
            mvprintw(24, 55, "|");
            mvprintw(24, 56, "-시작-"); mvprintw(24, 62, "|");
            mvprintw(25, 55, "*");
            for (int i = 0; i < 6; i++) mvprintw(25, 56 + i, "-"); mvprintw(25, 62, "*");
            if (sel == 28) attroff(A_REVERSE);
        }

        // 키 입력 이벤트 처리
        int key = getch();
        int k_size = flag ? (sizeof(building) / sizeof(building[0]) * 2) + 1 : sizeof(building) / sizeof(building[0]) * 2; // 전체 크기 저장
        switch (key) {
        case KEY_LEFT:
        case 'a':
        case 'A':
            if (sel == 0 && flag) break; // 시작 활성화 시 왼쪽 끝일시 멈춤
            sel = (sel - 1 + k_size) % k_size;
            break;
        case KEY_RIGHT:
        case 'd':
        case 'D':
            if (sel == 27 && flag) break; // 시작 활성화 시 오른쪽 끝일시 멈춤
            sel = (sel + 1) % k_size;
            break;
        case KEY_UP: // 위
        case 'w':
        case 'W':
            if (sel == 28) sel = temp; // 시작 활성화 시 시작 위치에서 올라갈 때 그 전 위치로
            else sel = (sel - 7 + k_size) % k_size;
            break;
        case KEY_DOWN: // 아래
        case 's':
        case 'S':
            if ((sel + 7) >= 28 && flag) { // 시작 활성화 시 시작으로 내려갈 때 위치 저장
                if (sel != 28)temp = sel;
                sel = 28;
            }
            else sel = (sel + 7) % k_size;
            break;
        case 10:  // Enter 키
        case 32:  // Space Bar 키
            if (sel == 28 && !(start == finish)) // 시작 버튼
                print_change_graph(start, finish);
            else if (sel >= 14)
                finish = sel % 14;
            else
                start = sel;
            break;
        case 'q':
            return;
        default:
            break;
        }
    }
}

void print_change_graph(int start, int finish) {
    clear();
    char temp[10];
    int sel = 0;
    char* choice[] = { "취소", " 확인" };

    char* building[] = { "목민관", "제2학생회관", "제1자연관", "인문사회관", "예술관", "사범관",
                        "제1학생회관", "바이오융합관", "행정관", "제2자연관", "미래창조관", "글로벌관", "체육관", "비전관" };
    mvprintw(3, 8, "%s", building[start]);
    mvprintw(3, 80, "%s", building[finish]);
    mvprintw(10, 40, "현재 가중치 : %d", buildings[start][finish].distance);
    mvprintw(11, 40, "변경 가중치 : ");
    echo();
    getstr(temp);
    noecho();
    refresh();

    mvprintw(13, 41, "입력 확인 : %s", temp);

    while (1) {
        for (int i = 0; i < 2; i++) {
            if (i == sel)
                mvprintw(15, 40 + (i * 15), ">%s<", choice[i]);
            else
                mvprintw(15, 40 + (i * 15), " %s ", choice[i]);
            printw(" ");
        }
        // 키 입력 이벤트 처리
        int key = getch();
        switch (key) {
        case KEY_LEFT:
        case 'a':
        case 'A':
            sel = (sel - 1 + 2) % 2;
            break;
        case KEY_RIGHT:
        case 'd':
        case 'D':
            sel = (sel + 1) % 2;
            break;
        case 10:  // Enter 키
        case 32:  // Space Bar 키
            // 선택된 메뉴 항목 처리
            if (sel == 1) {
                change_graph(start, finish, atoi(temp));
                return;
            }
            else return;
            break;
        case 'q':
            return;
        default:
            break;
        }
    }
    getch();
}

void change_graph(int start, int finish, int new_Value) {
    clear();

    if (new_Value == 0) { // 숫자가 아닌 값을 받을 때
        mvprintw(3, 44, "*");
        for (int i = 0; i < 29; i++) mvprintw(3, 45 + i, "-"); mvprintw(3, 74, "*");
        mvprintw(4, 44, "|");
        mvprintw(4, 46, "0으로 설정은 불가능 합니다."); mvprintw(4, 74, "|");
        mvprintw(5, 44, "*");
        for (int i = 0; i < 29; i++) mvprintw(5, 45 + i, "-"); mvprintw(5, 74, "*");
        getch();
        return;
    }

    buildings[start][finish].distance = new_Value;


    mvprintw(3, 44, "*");
    for (int i = 0; i < 29; i++) mvprintw(3, 45 + i, "-"); mvprintw(3, 74, "*");
    mvprintw(4, 44, "|");
    mvprintw(4, 46, "성공적으로 변환되었습니다."); mvprintw(4, 74, "|");
    mvprintw(5, 44, "*");
    for (int i = 0; i < 29; i++) mvprintw(5, 45 + i, "-"); mvprintw(5, 74, "*");
    getch();
}

void calculate_distance(int start, int finish) { // 무석 & 정원 [ 다익스트라 알고리즘 사용 ]
    if (start != -1 && finish != -1) {
        char* building[] = { "목민관", "제2학생회관", "제1자연관", "인문사회관", "예술관", "사범관",
                        "제1학생회관", "바이오융합관", "행정관", "제2자연관", "미래창조관", "글로벌관", "체육관", "비전관" };
        int dist[14] = { 0 };       // 출발점에서의 최단 거리
        int visited[14] = { 0 };    // 방문한 건물 체크
        int prev[14] = { 0 };       // 최단 경로 이전 건물 저장
        int via[14] = { 0 };        // 경유지 인덱스 저장 배열

        fast_data[start][finish]++;

        for (int i = 0; i < 14; i++) {
            dist[i] = INFINITY;
            visited[i] = 0;
            prev[i] = -1;
            via[i] = -1;
        }

        dist[start] = 0;

        for (int count = 0; count < 14; count++) {
            int minDist = INFINITY;
            int minIndex = -1;

            for (int i = 0; i < 14; i++) {
                if (!visited[i] && dist[i] <= minDist) {
                    minDist = dist[i];
                    minIndex = i;
                }
            }

            visited[minIndex] = 1;

            for (int i = 0; i < 14; i++) {
                if (!visited[i] && buildings[minIndex][i].connected && dist[minIndex] != INFINITY &&
                    dist[minIndex] + buildings[minIndex][i].distance < dist[i]) {
                    dist[i] = dist[minIndex] + buildings[minIndex][i].distance;
                    prev[i] = minIndex;
                }
            }
        }

        int path[14];
        int pathSize = 0;

        int current = finish;
        while (current != -1) {
            path[pathSize++] = current;
            current = prev[current];
        }

        // 경유지 인덱스 저장
        for (int i = 1; i < pathSize - 1; i++) {
            via[i - 1] = path[i];
        }

        clear();

        mvprintw(2, 2, "출발지: %s", building[start]);
        mvprintw(3, 2, "도착지: %s", building[finish]);
        mvprintw(5, 2, "최단 거리: %d", dist[finish]);
        mvprintw(9, 2, "경유지:");

        int x = 10;
        int y = 9;
        for (int i = pathSize - 1; i >= 0; i--) {
            mvprintw(y, x, "%s", building[path[i]]);
            x += (strlen(building[path[i]]) + 2);
            mvprintw(y, x, "->");
            x += 4;
        }
        x -= 4;
        mvprintw(y, x, "  ");
        getch();
    }
}

void save_data() {
    FILE* fp = NULL;

    if ((fp = fopen("graph_text.bin", "wb")) == NULL) { // 가중치 표 이진파일 저장
        endwin();
        error(3);
    }
    fwrite(&buildings, sizeof(buildings), 1, fp);
    fclose(fp);

    if ((fp = fopen("fast.bin", "wb")) == NULL) { // 빈도수 이진파일 저장
        endwin();
        error(4);
    }
    fwrite(&fast_data, sizeof(fast_data), 1, fp);
    fclose(fp);
}

void fast_start() {
    int start = 0;
    int finish = 0;
    int max_count = 0;

    for (int i = 0; i < 14; i++) { // 순차탐색 알고리즘
        for (int j = 0; j < 14; j++) {
            if (i == j) continue;
            else if (fast_data[i][j] == 0) continue;
            else if (max_count < fast_data[i][j]) {
                max_count = fast_data[i][j];
                start = i;
                finish = j;
            }
        }
    }
    calculate_distance(start, finish);
}
```

## <코드 저장소 링크>
https://github.com/mediblo/Algorithm-2023/tree/master/Homework/Team_Project_navi