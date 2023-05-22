#include <stdio.h>
#include "screen.h"
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    /*  width : 30    height : 15    가로 여백 : 2    세로여백 :1 */
    char screenBuf[35 * 17 + 1];
    char input[10];
    int width = 34;
    int height = 15;
    int isGamePlaying = 1;


    int game_state = 0;

    int screen = 1;
    char key_input = 0;

    while (isGamePlaying)
    {
        

        clearBuffer(screenBuf, width, height);

        // setTitleToScreenBuffer(screenBuf, width, height);





        if (input[0] == 'q')	/* q를 누르면 종료 */
            isGamePlaying = 0;

        switch (game_state)
        {
        case 0:
            if (screen == 1)
            {
                writeStringToBuffer("Snake Game", 5, 5, screenBuf, width);
                writeStringToBuffer("1. Game Start", 5, 6, screenBuf, width);
                writeStringToBuffer("2. Game Introduce", 5, 7, screenBuf, width);
                writeStringToBuffer("3. Game Ranking", 5, 8, screenBuf, width);
                writeStringToBuffer("4. Game Exit", 5, 9, screenBuf, width);


                screen = 0;
            }
            //key_input = 0;
            //scanf_s("%c", &key_input);
            switch (key_input)
            {
            case '1':
                game_state = 1;
                screen = 1;
                break;
            case '2':
                game_state = 2;
                screen = 2;
                break;
            case '3':
                game_state = 3;
                screen = 3;
                break;
            case '4':
                game_state = 4;
                screen = 4;
                break;
            }
            break;

        case 1:
            if (screen == 1)
            {
                system("cls");
                writeStringToBuffer("Game Screen", 5, 5, screenBuf, width);
                screen = 0;
            }

            break;


        case 2:
            if (screen == 2)
            {
                system("cls");
                writeStringToBuffer("Game Introduce", 5, 5, screenBuf, width);
                screen = 0;
            }
            key_input = 0;
            break;

        case 3:
            if (screen == 3)
            {
                system("cls");
                writeStringToBuffer("Game Ranking", 5, 5, screenBuf, width);
                screen = 0;
            }
            key_input = 0;
            break;
        case 4:
            if (screen == 4)
            {
                system("cls");
                writeStringToBuffer("Game Exit", 5, 5, screenBuf, width);
                screen = 0;
            }
            key_input = 0;
            break;
        }

        system("cls");
        printf("%s\nEnter Number>", screenBuf);
        //scanf_s("%s", input, sizeof(input));
        scanf_s("%c", &key_input);

    }

    return 0;
}



