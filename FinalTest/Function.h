#pragma once
#include "Define.h"
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include <mmsystem.h> 
#pragma comment(lib, "winmm.lib")

void gotoxy(int x, int y, char* s) {
    COORD pos = { 2 * x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s", s);

    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
// Ŀ�� ��ġ�� �����ؼ� �� ��ǥ�� ���ڿ��� ��� �� �� �ְ����ִ� �Լ�
// + Ŀ���� �Ⱥ��̰� ������p

void draw_map(void) { //�� �׵θ� �׸��� �Լ� 
    int i, j;
    for (i = 0; i < MAP_WIDTH; i++) {
        gotoxy(MAP_X + i, MAP_Y, "#");
    }
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) {
        gotoxy(MAP_X, i, "#");
        gotoxy(MAP_X + MAP_WIDTH - 1, i, "#");
    }
    for (i = 0; i < MAP_WIDTH; i++) {
        gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 1, "#");
    }
}

int screen()
{
    int i, j;

    while (_kbhit()) _getch(); //���ۿ� �ִ� Ű���� ���� 

    draw_map();    //�� �׵θ��� �׸� 
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) { // �� �׵θ� ������ ��ĭ���� ä�� 
        for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++) gotoxy(j, i, "  ");
    }
}

void Call()
{
    screen();
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 3, "������ ������~");
    Sleep(1000);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 5, "������ ������~");
    Sleep(2000);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 7, "��ȭ�� �Դ�..������?");
    Sleep(1000);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 9, "���� ��ȭ : I LOVE PYTHON");
    Sleep(1000);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 11, "����.. ������ �������̴�");
    Sleep(1000);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 13, "��ȭ�� �������?");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 14, "��ȭ�� �������� Y, �������� N�� �Է��ϼ���");
    while (1) {
        if (_kbhit()) { // Ű�Է¹��� 
            char key_input = 0;
            key = _getch();
            if (key == YES)
            {
                system("cls");
                SecondCall();

            }
            if (key == NO)
            {
                system("cls");
                CallDie();
            }
            if (key == ESC)
            {
                system("cls");
                exit(0);// ESCŰ�� ���� 
            }
        }
    }
}
void CallDie(void)
{
    screen();
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 8, "����� �������� ��ȭ�� ���� �ʾұ� ������");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 9, "�������� �뿩���� �� F �� �޾ҽ��ϴ�.");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 11, "������ �ٽ� �����Ϸ��� Y�� �Է����ּ���.");

    while (1) {
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 5, "              <BAD ENDING>");
        Sleep(400);
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 5, "                          ");
        Sleep(400);
        if (_kbhit()) { // Ű�Է¹��� 
            char key_input = 0;
            key = _getch();
            
            if (key == YES)
            {
                system("cls");
                Call();

            } 
            if (key == ESC)
            {
                system("cls");
                exit(0);// ESCŰ�� ���� 
            }
        }
    }
}

void SecondCall(void)
{
    screen();
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 3, "�� : ��������?");
    Sleep(1000);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 5, "������ : �� ���� Ȥ�� ��ȭ �����ϴ�?");
    Sleep(2000);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 7, "�� : (�Ҿ��ϴ�)");
    Sleep(1000);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 9, "�� : �� ������ ���� �� �� �����ϴ�.");
    Sleep(1000);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 11, "������ : �� �׷��� ���� �� 10���� �� �����Ƿ� ��Ͷ�");
    Sleep(1000);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 13, "�� : ��..?");
    Sleep(500);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 14, "�� : ���ڱ� ������..?");
    Sleep(2000);
    system("cls");
    screen();
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 3, "������ : �� �׷� ���� �� ����� �̹� �б� �� F��~");
    Sleep(1000);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 5, "�� : (����.. ���� �� ���� ����..)");
    Sleep(1000);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 7, "�� : �� ������ ^^ �ݹ� ���ڽ��ϴ�!");
    Sleep(2000);
    bread_main();
}

void title(void) {
    screen();
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 5, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 6, "|        ���� �����       |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 7, "+--------------------------+");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 10, MAP_Y + 9, " < ����Ű �Է½� ������ �����մϴ�. > ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 10, MAP_Y + 10, " < I�� ������ ���� �����Դϴ�.    > ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 10, MAP_Y + 11, " < ESC�� ������ ������ ����˴ϴ�.> ");

    //Ÿ��Ʋ ȭ��

    while (1) {
        if (_kbhit()) { // Ű�Է¹��� 
            char key_input = 0;
            key = _getch();
            if (key == ESC)
            {
                system("cls");
                exit(0);// ESCŰ�� ���� 
            }
            if (key == 'i')
            {
                system("cls");
                Introduce_Screen();
                scanf_s(" %c", &key_input);  // ���� ���ڸ� ����Ͽ� ���� �Է� ���۸� ����ϴ�.

                if (key_input == 'y')
                {
                    system("cls");
                    title();
                }
            }
            else break; //�ƴϸ� �׳� ��� ���� 
        }
    }
    reset(); // ������ �ʱ�ȭ �� ����
}
int Introduce_Screen()
{
    screen();
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|        ���� ����         |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "+--------------------------+");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "    ��,��,��,�� : �̵�     ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "    P : �Ͻ� ����          ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "    ESC : ����             ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 15, "    y �Է½� Ÿ��Ʋ��      ");



    return 0;
}


void reset(void) {
    int i;
    system("cls"); //ȭ���� ���� 
    draw_map(); //�� �׵θ��� �׸� 
    while (_kbhit()) _getch(); //���ۿ� �ִ� Ű���� ���� 

    dir = LEFT; // ���� �ʱ�ȭ  
    speed = 100; // �ӵ� �ʱ�ȭ 
    length = 5; //�� ���� �ʱ�ȭ 
    score = 0; //���� �ʱ�ȭ 
    for (i = 0; i < length; i++) { //�� ���밪 �Է� 
        x[i] = MAP_WIDTH / 2 + i;
        y[i] = MAP_HEIGHT / 2;
        gotoxy(MAP_X + x[i], MAP_Y + y[i], ANSI_COLOR_GREEN"o"ANSI_COLOR_RESET);
    }
    gotoxy(MAP_X + x[0], MAP_Y + y[0], ANSI_COLOR_RED"O"ANSI_COLOR_RESET); //�� �Ӹ� �׸� 
    bbang(); // bbang ����  
}





void bbang(void) {
    int i;

    int bbang_crush_on = 0;//bbang�� �� ������ǥ�� ���� ��� on 
    int r = 0; //���� ������ �絿�Ǵ� ���� 
    gotoxy(MAP_X, MAP_Y + MAP_HEIGHT, " YOUR BREAD: "); //����ǥ�� 
    printf("%3d, LAST BREAD: %3d, BEST BREAD: %3d", score, last_score, best_score);

    while (1) {
        bbang_crush_on = 0;
        srand((unsigned)time(NULL) + r); //����ǥ���� 
        bbang_x = (rand() % (MAP_WIDTH - 2)) + 1;    //������ ��ǥ���� ���� 
        bbang_y = (rand() % (MAP_HEIGHT - 2)) + 1;

        for (i = 0; i < length; i++) { //bbang�� �� ����� ��ġ���� Ȯ��  
            if (bbang_x == x[i] && bbang_y == y[i]) {
                bbang_crush_on = 1; //��ġ�� bbang_crush_on �� on 
                r++;
                break;
            }
        }

        if (bbang_crush_on == 1) continue; //������ ��� while���� �ٽ� ���� 

        gotoxy(MAP_X + bbang_x, MAP_Y + bbang_y, ANSI_COLOR_CYAN"��"ANSI_COLOR_RESET); //�Ȱ����� ��� ��ǥ���� bbang�� ��� 
        speed -= 3; //�ӵ� ���� 
        break;

    }
}

void move(int dir) {
    int i;

    if (x[0] == bbang_x && y[0] == bbang_y) { //bbang�ϰ� �浹���� ��� 
        score += 10; //���� ���� 
        bbang(); //���ο� �� �߰� 
        length++; //�������� 
        x[length - 1] = x[length - 2]; //���θ��� ���뿡 �� �Է� 
        y[length - 1] = y[length - 2];
    }
    if (x[0] == 0 || x[0] == MAP_WIDTH - 1 || y[0] == 0 || y[0] == MAP_HEIGHT - 1) { //���� �浹���� ��� 
        game_over();
        return;
        //game_over���� ������ �ٽ� �����ϰ� �Ǹ� ���⼭���� �ݺ��ǹǷ� 
        //return�� ����Ͽ� move�� ������ �κ��� ������� �ʵ��� �մϴ�. 
    }
    for (i = 1; i < length; i++) { //�ڱ���� �浹�ߴ��� �˻� 
        if (x[0] == x[i] && y[0] == y[i]) {
            game_over();
            return;
        }
    }

    gotoxy(MAP_X + x[length - 1], MAP_Y + y[length - 1], "  "); //���� �������� ���� 
    for (i = length - 1; i > 0; i--) { //������ǥ�� ��ĭ�� �ű� 
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }
    gotoxy(MAP_X + x[0], MAP_Y + y[0], ANSI_COLOR_GREEN"o"ANSI_COLOR_RESET); //�Ӹ��� �ִ����� �������� ��ħ 
    if (dir == LEFT) --x[0]; //���⿡ ���� ���ο� �Ӹ���ǥ(x[0],y[0])���� ���� 
    if (dir == RIGHT) ++x[0];
    if (dir == UP) --y[0];
    if (dir == DOWN) ++y[0];
    gotoxy(MAP_X + x[i], MAP_Y + y[i], ANSI_COLOR_RED"O"ANSI_COLOR_RESET); //���ο� �Ӹ���ǥ���� �Ӹ��� �׸� 

    
}

void pause(void) { // pŰ�� ������ ��� ������ �Ͻ� ���� 
    while (1) {
        if (key == PAUSE) {
            gotoxy(MAP_X + (MAP_WIDTH / 2) - 9, MAP_Y, "< ����Ű �Է½� ���� �ٽ� ���� > ");
            Sleep(400);
            gotoxy(MAP_X + (MAP_WIDTH / 2) - 9, MAP_Y, "                                    ");
            Sleep(400);
        }
        else {
            draw_map();
            return;
        }
        if (_kbhit()) {

            do {
                key = _getch();
            } while (key == 224);
        }

    }
}


void game_over(void) { //�������� �Լ�
    system("cls");
    draw_map();
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 5, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 6, "|      GAME OVER..     |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 7, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 8, " YOUR BREAD : ");
    printf("%d", last_score = score);

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, " �ٽ� �����Ϸ��� Ű �Է� ");

    if (score > best_score) {
        best_score = score;
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 4, MAP_Y + 10, "�� �ִ� �� ��");
    }
    Sleep(500);
    while (_kbhit()) _getch();
    key = _getch();
    title();
}

void bread_main() {
    
    title();

    while (score < 30) { // score�� 20 �̸��� ���� �ݺ�
        if (_kbhit()) do { key = _getch(); } while (key == 224); // Ű �Է¹���
        Sleep(speed);

        switch (key) { // �Է¹��� Ű�� �ľ��ϰ� ����  
        case LEFT:
        case RIGHT:
        case UP:
        case DOWN:
            if ((dir == LEFT && key != RIGHT) || (dir == RIGHT && key != LEFT) || (dir == UP && key != DOWN) ||
                (dir == DOWN && key != UP))// 180ȸ�� �̵��� �����ϱ� ���� �ʿ�
                dir = key;
            key = 0; // Ű���� �����ϴ� ������ ���� 
            break;
        case PAUSE: // PŰ�� ������ �Ͻ����� 
            pause();
            break;
        case ESC: // ESCŰ�� ������ ���α׷� ���� 
            exit(0);
        }
        move(dir);
    }

    Clear(); // score�� 30 �̻��� �Ǹ� �ݺ����� Ż���ϰ� Clear() �Լ� ȣ��
}
void Clear(void)
{
    system("cls");
    screen();
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 5, "����� ���� �缭 �����Բ� ��Ƚ��ϴ�.");
    Sleep(1000);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 7, "�������� ���� �԰� �ູ������..");
    Sleep(1000);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 9, "����� A+�� �ް� �Ǿ����ϴ�!");
    Sleep(1000);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 14, "          ������ �������� ESC�� �����ּ���");
    while (1) {
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 3, "                  <HAPPY ENDING>");
        Sleep(400);
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 13, MAP_Y + 3, "                                ");
        Sleep(400);
        if (_kbhit()) { // Ű�Է¹��� 
            char key_input = 0;
            key = _getch();

            if (key == ESC)
            {
                system("cls");
                exit(0);// ESCŰ�� ���� 
            }
        }
    }
}



