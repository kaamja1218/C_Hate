#include "Function.h"
int main()
{
    char c[256] = "";
    PlaySound(NULL, 0, 0);
    Sleep(10);
    PlaySound(TEXT("C:\\Users\\User\\OneDrive\\바탕 화면\\C_Game\\Maple.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    screen();
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 5, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 6, "|  교수님을 도와드리자 ^^  |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 7, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 10, MAP_Y + 10, " < TAB룰 누르면 게임을 시작합니다. > ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 10, MAP_Y + 12, " < ESC룰 누르면 게임을 종료합니다. > ");

    

    while (1) {

        gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 6, "|  교수님을 도와드리자 ^^  |");
        Sleep(400);
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 6, "|                          |");
        Sleep(400);
        if (_kbhit()) { // 키입력받음 
            char key_input = 0;
            key = _getch();
            if (key == ESC)
            {
                system("cls");
                exit(0);// ESC키면 종료 
            }
            if (key == START)
            {
                system("cls");
                Call();

            }
        }
    }

}
