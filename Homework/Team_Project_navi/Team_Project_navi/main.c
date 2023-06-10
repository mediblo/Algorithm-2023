#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <limits.h>
#include <curses.h>

// PDCurses �غ�
void init_pcr();
// ������ �ҷ�����
void load_data();
// �ΰ� ���
void print_navi();
// ���� �޴� ���
int menu();
// �����, ������
void set_building();
// ����
void change_building();
// ������ ���
void print_change_graph(int start, int finish);
// ���� �� ����
void change_graph(int start, int finish, int new_Value);
// �ִܰ�� �˰��� [ ����, ���� ]
void calculate_distance(int start, int finish);
// ������ ����
void save_data();
// ���� ó��
void error(int code);
// ���� ����
void fast_start();

// void print_map();

#define INFINITY INT_MAX

// �ǹ� ���� ���� ������ �Ÿ� ������ �׷����� ǥ�� [ ���� ]
typedef struct {
    int connected;  // �ǹ� ���� ����
    int distance;   // �Ÿ�
} Graph;

/* �ʱ� ����ġ �� [ ���� ]
Graph buildings[14][14] = {
    {{ 0, 0 }, { 1, 2 }, { 1, 3 }, { 1, 4 }, { 1, 5 }, { 1, 6 }, { 1, 7 }, { 1, 8 }, { 1, 9 }, { 1, 10 }, { 1, 11 }, { 1, 12 }, { 1, 13 }, { 1, 14 }},
    {{ 1, 2 }, { 0, 0 }, { 1, 4 }, { 1, 6 }, { 1, 8 }, { 1, 10 }, { 1, 12 }, { 1, 14 }, { 1, 16 }, { 1, 18 }, { 1, 20 }, { 1, 22 }, { 1, 24 }, { 1, 26 }},
    {{ 1, 3 }, { 1, 4 }, { 0, 0 }, { 1, 5 }, { 1, 10 }, { 1, 15 }, { 1, 20 }, { 1, 25 }, { 1, 30 }, { 1, 35 }, { 1, 40 }, { 1, 45 }, { 1, 50 }, { 1, 55 }},
    {{ 1, 4 }, { 1, 6 }, { 1, 5 }, { 0, 0 }, { 1, 7 }, { 1, 14 }, { 1, 21 }, { 1, 28 }, { 1, 35 }, { 1, 42 }, { 1, 49 }, { 1, 56 }, { 1, 63 }, { 1, 70 }},
    {{ 1, 5 }, { 1, 8 }, { 1, 10 }, { 1, 7 }, { 0, 0 }, { 1, 9 }, { 1, 18 }, { 1, 27 }, { 1, 36 }, { 1, 45 }, { 1, 54 }, { 1, 63 }, { 1, 72 }, { 1, 81 }},
    {{ 1, 6 }, { 1, 10 }, { 1, 15 }, { 1, 14 }, { 1, 9 }, { 0, 0 }, { 1, 11 }, { 1, 22 }, { 1, 33 }, { 1, 44 }, { 1, 55 }, { 1, 66 }, { 1, 77 }, { 1, 88 }},
    {{ 1, 7 }, { 1, 12 }, { 1, 20 }, { 1, 21 }, { 1, 18 }, { 1, 11 }, { 0, 0 }, { 1, 13 }, { 1, 26 }, { 1, 39 }, { 1, 52 }, { 1, 65 }, { 1, 78 }, { 1, 91 }},
    {{ 1, 8 }, { 1, 14 }, { 1, 25 }, { 1, 28 }, { 1, 27 }, { 1, 22 }, { 1, 13 }, { 0, 0 }, { 1, 15 }, { 1, 30 }, { 1, 45 }, { 1, 60 }, { 1, 75 }, { 1, 90 }},
    {{ 1, 9 }, { 1, 16 }, { 1, 30 }, { 1, 35 }, { 1, 36 }, { 1, 33 }, { 1, 26 }, { 1, 15 }, { 0, 0 }, { 1, 17 }, { 1, 34 }, { 1, 51 }, { 1, 68 }, { 1, 85 }},
    {{ 1, 10 }, { 1, 18 }, { 1, 35 }, { 1, 42 }, { 1, 45 }, { 1, 44 }, { 1, 39 }, { 1, 30 }, { 1, 17 }, { 0, 0 }, { 1, 19 }, { 1, 38 }, { 1, 57 }, { 1, 76 }},
    {{ 1, 11 }, { 1, 20 }, { 1, 40 }, { 1, 49 }, { 1, 54 }, { 1, 55 }, { 1, 52 }, { 1, 45 }, { 1, 34 }, { 1, 19 }, { 0, 0 }, { 1, 21 }, { 1, 42 }, { 1, 63 }},
    {{ 1, 12 }, { 1, 22 }, { 1, 45 }, { 1, 56 }, { 1, 63 }, { 1, 66 }, { 1, 65 }, { 1, 60 }, { 1, 51 }, { 1, 38 }, { 1, 21 }, { 0, 0 }, { 1, 23 }, { 1, 46 }},
    {{ 1, 13 }, { 1, 24 }, { 1, 50 }, { 1, 63 }, { 1, 72 }, { 1, 77 }, { 1, 78 }, { 1, 75 }, { 1, 68 }, { 1, 57 }, { 1, 42 }, { 1, 23 }, { 0, 0 }, { 1, 25 }},
    {{ 1, 14 }, { 1, 26 }, { 1, 55 }, { 1, 70 }, { 1, 81 }, { 1, 88 }, { 1, 91 }, { 1, 90 }, { 1, 85 }, { 1, 76 }, { 1, 63 }, { 1, 46 }, { 1, 25 }, { 0, 0 }}
};
*/

// �ʱ� ������ ����
Graph buildings[14][14] = { 0 };
int fast_data[14][14] = { 0 };

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
            // PDcurses ����
            save_data();
            endwin();
            return 0;
        default:
            break;
        }
    }

    // PDcurses ���� && �̷����� ����
    endwin();
    error(5);
    return 0;
}

void error(int code) {
    switch (code) {
    case 1:
        printf("�׷��� ������ �ҷ����� ����");
        break;
    case 2:
        printf("���� ������ �ҷ����� ����");
        break;
    case 3:
        printf("�׷��� ������ ���� ����");
        break;
    case 4:
        printf("���� ������ ���� ����");
        break;
    case 5:
        printf("�̷����� ����!!");
        break;
    default:
        printf("�Է� �Ű����� ���� �̻��մϴ�.");
        break;
    }
    exit(1);
}

void init_pcr() {
    // PDcurses �ʱ�ȭ
    initscr();
    cbreak(); // �Է� ��Ʈ�� ���۸� ����
    noecho(); // ����� �Է� ȭ�鿡 �ȶ�
    keypad(stdscr, TRUE); // Ư��Ű ��� ���� ( ȭ��ǥ Ű )
}

void load_data() {
    FILE* fp = NULL;
    int temp = 0;

    if ((fp = fopen("graph_text.bin", "rb")) == NULL) { // ����ġ ǥ �������� �ҷ�����
        endwin();
        error(1);
    }
    fread(&buildings, sizeof(buildings), 1, fp);
    fclose(fp);

    if ((fp = fopen("fast.bin", "rb")) == NULL) { // �󵵼� ǥ �������� �ҷ�����
        endwin();
        error(2);
    }
    fread(&fast_data, sizeof(fast_data), 1, fp);
    fclose(fp);
}

// ���� �ΰ� �׺�
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
    const char* menu_bar[] = { "����", "���� ����", "����", "������" };

    while (1) {
        clear();
        print_navi();

        // 4���� ��� ����
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

        mvprintw(21, 26, "�̵� - ȭ��ǥ [ w a s d ] / ���� - Enter or Space / q - �ڷΰ���");

        mvprintw(24, 42, "*");
        for (int i = 0; i < 33; i++) mvprintw(24, 43 + i, "-"); mvprintw(24, 76, "*");
        mvprintw(25, 42, "|");
        mvprintw(25, 44, "�� �����⸦ �ϼž� ����˴ϴ�!"); mvprintw(25, 76, "|");
        mvprintw(26, 42, "*");
        for (int i = 0; i < 33; i++) mvprintw(26, 43 + i, "-"); mvprintw(26, 76, "*");

        // Ű �Է� �̺�Ʈ ó��
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
        case 10:  // Enter Ű
        case 32:  // Space Bar Ű
            // ���õ� �޴� �׸� ó��
            return sel;
        case 'q':
            return 3;
        default:
            break;
        }
    }
}

void set_building() {
    const char* building[] = { "��ΰ�", "��2�л�ȸ��", "��1�ڿ���", "�ι���ȸ��", "������", "�����",
                    "��1�л�ȸ��", "���̿����հ�", "������", "��2�ڿ���", "�̷�â����", "�۷ι���", "ü����", "������" };
    int sel = 0;
    int temp = 0;
    int start = -1, finish = -1;

    bool flag = FALSE; // ���� ��ư ���� Ȯ��

    while (1) {
        clear();

        if (flag == FALSE && (start != -1 && finish != -1)) flag = TRUE;

        // ����� ��� [ 0 ~ 13 ]
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

        // ���м� �߱�
        mvprintw(18, 1, "*");
        for (int i = 2; i < 110; i++) mvprintw(18, i, "-"); mvprintw(18, 110, "*");

        // ������ ��� [ 14 ~ 27 ]
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

        mvprintw(8, 52, "����� : %s", start != -1 ? building[start] : "");
        mvprintw(9, 52, "������ : %s", finish != -1 ? building[finish] : "");
        if (start != -1 && start == finish) { // ��ø Ȯ��
            mvprintw(3, 44, "*");
            for (int i = 0; i < 32; i++) mvprintw(3, 45 + i, "-"); mvprintw(3, 77, "*");
            mvprintw(4, 44, "|");
            mvprintw(4, 46, "���� ���� Ȯ���� �Ұ����մϴ�."); mvprintw(4, 77, "|");
            mvprintw(5, 44, "*");
            for (int i = 0; i < 32; i++) mvprintw(5, 45 + i, "-"); mvprintw(5, 77, "*");
        }


        if (flag) { // ���� ��ư ����
            if (sel == 28) attron(A_REVERSE);
            mvprintw(23, 55, "*");
            for (int i = 0; i < 6; i++) mvprintw(23, 56 + i, "-"); mvprintw(23, 62, "*");
            mvprintw(24, 55, "|");
            mvprintw(24, 56, "-����-"); mvprintw(24, 62, "|");
            mvprintw(25, 55, "*");
            for (int i = 0; i < 6; i++) mvprintw(25, 56 + i, "-"); mvprintw(25, 62, "*");
            if (sel == 28) attroff(A_REVERSE);
        }

        // Ű �Է� �̺�Ʈ ó��
        int key = getch();
        int k_size = flag ? (sizeof(building) / sizeof(building[0]) * 2) + 1 : sizeof(building) / sizeof(building[0]) * 2; // ��ü ũ�� ����
        switch (key) {
        case KEY_LEFT:
        case 'a':
        case 'A':
            if (sel == 0 && flag) break; // ���� Ȱ��ȭ �� ���� ���Ͻ� ����
            sel = (sel - 1 + k_size) % k_size;
            break;
        case KEY_RIGHT:
        case 'd':
        case 'D':
            if (sel == 27 && flag) break; // ���� Ȱ��ȭ �� ������ ���Ͻ� ����
            sel = (sel + 1) % k_size;
            break;
        case KEY_UP: // ��
        case 'w':
        case 'W':
            if (sel == 28) sel = temp; // ���� Ȱ��ȭ �� ���� ��ġ���� �ö� �� �� �� ��ġ��
            else sel = (sel - 7 + k_size) % k_size;
            break;
        case KEY_DOWN: // �Ʒ�
        case 's':
        case 'S':
            if ((sel + 7) >= 28 && flag) { // ���� Ȱ��ȭ �� �������� ������ �� ��ġ ����
                if (sel != 28)temp = sel;
                sel = 28;
            }
            else sel = (sel + 7) % k_size;
            break;
        case 10:  // Enter Ű
        case 32:  // Space Bar Ű
            if (sel == 28 && !(start == finish)) // ���� ��ư
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
    const char* building[] = { "��ΰ�", "��2�л�ȸ��", "��1�ڿ���", "�ι���ȸ��", "������", "�����",
                    "��1�л�ȸ��", "���̿����հ�", "������", "��2�ڿ���", "�̷�â����", "�۷ι���", "ü����", "������" };
    int sel = 0;
    int temp = 0;
    int start = -1, finish = -1;

    bool flag = FALSE; // ���� ��ư ���� Ȯ��

    while (1) {
        clear();

        if (flag == FALSE && (start != -1 && finish != -1)) flag = TRUE;

        // ����� ��� [ 0 ~ 13 ]
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

        // ���м� �߱�
        mvprintw(18, 1, "*");
        for (int i = 2; i < 110; i++) mvprintw(18, i, "-"); mvprintw(18, 110, "*");

        // ������ ��� [ 14 ~ 27 ]
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
        mvprintw(8, 50, "���� ����� : %s", start != -1 ? building[start] : "");
        mvprintw(9, 50, "���� ������ : %s", finish != -1 ? building[finish] : "");
        if (start != -1 && start == finish) { // ��ø Ȯ��
            mvprintw(3, 44, "*");
            for (int i = 0; i < 32; i++) mvprintw(3, 45 + i, "-"); mvprintw(3, 77, "*");
            mvprintw(4, 44, "|");
            mvprintw(4, 46, "���� �� ������ �Ұ����մϴ�."); mvprintw(4, 77, "|");
            mvprintw(5, 44, "*");
            for (int i = 0; i < 32; i++) mvprintw(5, 45 + i, "-"); mvprintw(5, 77, "*");
        }


        if (flag) { // ���� ��ư ����
            if (sel == 28) attron(A_REVERSE);
            mvprintw(23, 55, "*");
            for (int i = 0; i < 6; i++) mvprintw(23, 56 + i, "-"); mvprintw(23, 62, "*");
            mvprintw(24, 55, "|");
            mvprintw(24, 56, "-����-"); mvprintw(24, 62, "|");
            mvprintw(25, 55, "*");
            for (int i = 0; i < 6; i++) mvprintw(25, 56 + i, "-"); mvprintw(25, 62, "*");
            if (sel == 28) attroff(A_REVERSE);
        }

        // Ű �Է� �̺�Ʈ ó��
        int key = getch();
        int k_size = flag ? (sizeof(building) / sizeof(building[0]) * 2) + 1 : sizeof(building) / sizeof(building[0]) * 2; // ��ü ũ�� ����
        switch (key) {
        case KEY_LEFT:
        case 'a':
        case 'A':
            if (sel == 0 && flag) break; // ���� Ȱ��ȭ �� ���� ���Ͻ� ����
            sel = (sel - 1 + k_size) % k_size;
            break;
        case KEY_RIGHT:
        case 'd':
        case 'D':
            if (sel == 27 && flag) break; // ���� Ȱ��ȭ �� ������ ���Ͻ� ����
            sel = (sel + 1) % k_size;
            break;
        case KEY_UP: // ��
        case 'w':
        case 'W':
            if (sel == 28) sel = temp; // ���� Ȱ��ȭ �� ���� ��ġ���� �ö� �� �� �� ��ġ��
            else sel = (sel - 7 + k_size) % k_size;
            break;
        case KEY_DOWN: // �Ʒ�
        case 's':
        case 'S':
            if ((sel + 7) >= 28 && flag) { // ���� Ȱ��ȭ �� �������� ������ �� ��ġ ����
                if (sel != 28)temp = sel;
                sel = 28;
            }
            else sel = (sel + 7) % k_size;
            break;
        case 10:  // Enter Ű
        case 32:  // Space Bar Ű
            if (sel == 28 && !(start == finish)) // ���� ��ư
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
    char* choice[] = { "���", " Ȯ��" };

    char* building[] = { "��ΰ�", "��2�л�ȸ��", "��1�ڿ���", "�ι���ȸ��", "������", "�����",
                        "��1�л�ȸ��", "���̿����հ�", "������", "��2�ڿ���", "�̷�â����", "�۷ι���", "ü����", "������" };
    mvprintw(3, 8, "%s", building[start]);
    mvprintw(3, 80, "%s", building[finish]);
    mvprintw(10, 40, "���� ����ġ : %d", buildings[start][finish].distance);
    mvprintw(11, 40, "���� ����ġ : ");
    echo();
    getstr(temp);
    noecho();
    refresh();

    mvprintw(13, 41, "�Է� Ȯ�� : %s", temp);

    while (1) {
        for (int i = 0; i < 2; i++) {
            if (i == sel)
                mvprintw(15, 40 + (i * 15), ">%s<", choice[i]);
            else
                mvprintw(15, 40 + (i * 15), " %s ", choice[i]);
            printw(" ");
        }
        // Ű �Է� �̺�Ʈ ó��
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
        case 10:  // Enter Ű
        case 32:  // Space Bar Ű
            // ���õ� �޴� �׸� ó��
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

    if (new_Value == 0) { // ���ڰ� �ƴ� ���� ���� ��
        mvprintw(3, 44, "*");
        for (int i = 0; i < 29; i++) mvprintw(3, 45 + i, "-"); mvprintw(3, 74, "*");
        mvprintw(4, 44, "|");
        mvprintw(4, 46, "0���� ������ �Ұ��� �մϴ�."); mvprintw(4, 74, "|");
        mvprintw(5, 44, "*");
        for (int i = 0; i < 29; i++) mvprintw(5, 45 + i, "-"); mvprintw(5, 74, "*");
        getch();
        return;
    }

    buildings[start][finish].distance = new_Value;


    mvprintw(3, 44, "*");
    for (int i = 0; i < 29; i++) mvprintw(3, 45 + i, "-"); mvprintw(3, 74, "*");
    mvprintw(4, 44, "|");
    mvprintw(4, 46, "���������� ��ȯ�Ǿ����ϴ�."); mvprintw(4, 74, "|");
    mvprintw(5, 44, "*");
    for (int i = 0; i < 29; i++) mvprintw(5, 45 + i, "-"); mvprintw(5, 74, "*");
    getch();
}

void calculate_distance(int start, int finish) { // ���� & ���� [ ���ͽ�Ʈ�� �˰��� ��� ]
    if (start != -1 && finish != -1) {
        char* building[] = { "��ΰ�", "��2�л�ȸ��", "��1�ڿ���", "�ι���ȸ��", "������", "�����",
                        "��1�л�ȸ��", "���̿����հ�", "������", "��2�ڿ���", "�̷�â����", "�۷ι���", "ü����", "������" };
        int dist[14] = { 0 };       // ����������� �ִ� �Ÿ�
        int visited[14] = { 0 };    // �湮�� �ǹ� üũ
        int prev[14] = { 0 };       // �ִ� ��� ���� �ǹ� ����
        int via[14] = { 0 };        // ������ �ε��� ���� �迭

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

        // ������ �ε��� ����
        for (int i = 1; i < pathSize - 1; i++) {
            via[i - 1] = path[i];
        }

        clear();

        mvprintw(2, 2, "�����: %s", building[start]);
        mvprintw(3, 2, "������: %s", building[finish]);
        mvprintw(5, 2, "�ִ� �Ÿ�: %d", dist[finish]);
        mvprintw(9, 2, "������:");

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

    if ((fp = fopen("graph_text.bin", "wb")) == NULL) { // ����ġ ǥ �������� ����
        endwin();
        error(3);
    }
    fwrite(&buildings, sizeof(buildings), 1, fp);
    fclose(fp);

    if ((fp = fopen("fast.bin", "wb")) == NULL) { // �󵵼� �������� ����
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

    for (int i = 0; i < 14; i++) { // ����Ž�� �˰���
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

/* �̱��� �Լ�
void print_map() {
    int x = 10;
    int y = 11;

    // 0 = Stop, 1 = Up, 2 = Down, 3 = Left, 4 = Right
    int sToF[14][14][14] = {{0}, {4,4,4,1,0}};

    mvprintw(y, x + 0, "*");
    mvprintw(y, x + 59, "*");
    mvprintw(y + 16, x + 59, "*");
    mvprintw(y + 16, x, "*");

    for (int i = 1; i < 59; i++) mvprintw(y + 0, x + i, "-"); // ��
    for (int i = 1; i < 16; i++) mvprintw(y + i, x, "|"); // ��
    for (int i = 1; i < 59; i++) mvprintw(y + 16, x + i, "-"); // �Ʒ�
    for (int i = 1; i < 16; i++) mvprintw(y + i, x + 59, "|"); // ����

    mvprintw(y + 14, x + 18, "@"); // ��ΰ�
    mvprintw(y + 12, x + 22, "@"); // ��1��
    mvprintw(y + 11, x + 14, "@"); // �ι���ȸ
    mvprintw(y + 10, x + 19, "@"); // ��1��
    mvprintw(y + 12, x + 16, "@"); // ��2��
    mvprintw(y + 10, x + 12, "@"); // ������
    mvprintw(y + 8, x + 14, "@"); // �����
    mvprintw(y + 9, x + 26, "@"); // ���̿�
    mvprintw(y + 6, x + 30, "@"); // ��2��
    mvprintw(y + 7, x + 22, "@"); // ����
    mvprintw(y + 5, x + 18, "@"); // ��â��
    mvprintw(y + 3, x + 18, "@"); // ü����
    mvprintw(y + 4, x + 23, "@"); // �۷ι���
    mvprintw(y + 1, x + 20, "@"); // ������


    x += 18;
    y += 14;
    for (int i = 0; sToF[0][1][i] == 0; i++) {
        switch (sToF[0][1][i]) {
            case 1:
                y -= 1;
                break;
            case 2:
                y += 1;
            case 3:
                x -= 1;
            case 4:
                x += 1;
        }

        mvprintw(y, x, "@");
        refresh();
        getch();
    }

    refresh();
    getch();
}
*/
