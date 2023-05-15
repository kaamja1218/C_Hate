#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Game_Loby() {
    char screen[22][37]; // 게임판 배열

    // 게임판 초기화
    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 36; j++) {
            if (i == 0 || i == 21 || j == 0 || j == 35) {
                screen[i][j] = '*';
            }
            else { // 나머지 칸은 공백으로 초기화
                screen[i][j] = ' ';
            }
        }
        screen[i][35] = '*'; // 각 행의 마지막 열에 별표 삽입
        screen[i][36] = '\0'; // 각 행의 마지막에 널 문자 삽입
    }
    screen[6][2] = 'G';
    screen[6][4] = 'U';
    screen[6][6] = 'E';
    screen[6][8] = 'S';
    screen[6][10] = 'S';
    screen[6][12] = ' ';
    screen[6][14] = 'T';
    screen[6][16] = 'H';
    screen[6][18] = 'E';
    screen[6][20] = ' ';
    screen[6][22] = 'N';
    screen[6][24] = 'U';
    screen[6][26] = 'M';
    screen[6][28] = 'B';
    screen[6][30] = 'E';
    screen[6][32] = 'R';

    screen[10][2] = '1';
    screen[10][4] = '.';
    screen[10][6] = 'G';
    screen[10][8] = 'a';
    screen[10][10] = 'm';
    screen[10][12] = 'e';
    screen[10][14] = ' ';
    screen[10][16] = 'S';
    screen[10][18] = 't';
    screen[10][20] = 'a';
    screen[10][22] = 'r';
    screen[10][24] = 't';

    screen[12][2] = '2';
    screen[12][4] = '.';
    screen[12][6] = 'G';
    screen[12][8] = 'a';
    screen[12][10] = 'm';
    screen[12][12] = 'e';
    screen[12][14] = ' ';
    screen[12][16] = 'D';
    screen[12][18] = 'e';
    screen[12][20] = 's';
    screen[12][22] = 'c';
    screen[12][24] = 'r';
    screen[12][26] = 'i';
    screen[12][28] = 'p';
    screen[12][30] = 't';

    screen[14][2] = '3';
    screen[14][4] = '.';
    screen[14][6] = 'E';
    screen[14][8] = 'x';
    screen[14][10] = 'i';
    screen[14][12] = 't';;

    

    // 게임판 출력
    for (int i = 0; i < 22; i++) {
        printf("%s\n", screen[i]);
    }

    printf("숫자를 입력하세요: ");
}
int Game_Start()
{
    printf("Game start");
}
int Game_Introduce()
{
    printf("Game introduce");
}
int Game_End()
{
    printf("Game end");
}
int main()
{

    int game_state = 0;
    int game_running = 1;
    int screen = 1;
    char key_input = 0;

    while (game_running)
    {
        if (game_state == 0)
        {
            if (screen == 1)
            {
                Game_Loby();
                screen = 0;
            }
            key_input = 0;
            scanf("%c", &key_input);
            if (key_input == '1')
            {
                game_state = 1;
                screen = 1;
            }
            else if (key_input == '2')
            {
                game_state = 2;
                screen = 2;
            }
            else if (key_input == '3')
            {
                game_state = 3;
                screen = 3;
            }
        }
        else if (game_state == 1)
        {
            if (screen == 1)
            {
                system("cls");
                Game_Start();
                screen = 0;
            }
            key_input = 0;

        }
        else if (game_state == 2)
        {
            if (screen == 2)
            {
                system("cls");
                Game_Introduce();
                screen = 0;
            }
        }
        else if (game_state == 3)
        {
            if (screen == 3)
            {
                system("cls");
                Game_End();
                screen = 0;
            }
        }
    }
    return 0;
}