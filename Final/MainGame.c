#include "Function.h"
int main()
{
    char c[256] = "";
    PlaySound(NULL, 0, 0);
    Sleep(10);
    PlaySound(TEXT("C:\\Users\\User\\OneDrive\\���� ȭ��\\C_Game\\Maple.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    screen();
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 5, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 6, "|  �������� ���͵帮�� ^^  |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 7, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 10, MAP_Y + 10, " < TAB�� ������ ������ �����մϴ�. > ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 10, MAP_Y + 12, " < ESC�� ������ ������ �����մϴ�. > ");

    

    while (1) {

        gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 6, "|  �������� ���͵帮�� ^^  |");
        Sleep(400);
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 6, "|                          |");
        Sleep(400);
        if (_kbhit()) { // Ű�Է¹��� 
            char key_input = 0;
            key = _getch();
            if (key == ESC)
            {
                system("cls");
                exit(0);// ESCŰ�� ���� 
            }
            if (key == START)
            {
                system("cls");
                Call();

            }
        }
    }

}
