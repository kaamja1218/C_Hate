#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

int title_screen();
int introduce_screen();

int title_screen()
{
	printf("######################################\n");
	printf("#                                    #\n");
	printf("#              Dino Run              #\n");
	printf("#               -VO.1-               #\n");
	printf("#                                    #\n");
	printf("#  1.Game Start                      #\n");
	printf("#  2.How to Play                     #\n");
	printf("#  3.Exit(Esc)                       #\n");
	printf("#                                    #\n");
	printf("#                                    #\n");
	printf("######################################\n");
	return 0;
}

int introduce_screen()
{
	printf("######################################\n");
	printf("#                                    #\n");
	printf("#      This is Dinosour run game.    #\n");
	printf("#            Run and jump            #\n");
	printf("#                                    #\n");
	printf("#   Return to menu? (Y.Yes N.No)     #\n");
	printf("#                                    #\n");
	printf("#                                    #\n");
	printf("######################################\n");

	return 0;
}
int main()
{

	int game_state = 0;
	int game_running = 1;
	int screen = 1;
	while (game_running)
	{
		char key_input = 0;
		switch (game_state)
		{
		case 0:
			if (screen == 1)
			{
				title_screen();
				screen = 0;
			}
			key_input = 0;
			key_input = _getch();
			if (key_input == '2')
			{
				game_state = 2;
				screen = 2;
			}
			else if (key_input == '3' || key_input == 27)
				game_running = 0;
			break;

		case 2:
			if (screen == 2)
			{
				introduce_screen();
				screen = 0;
			}
			key_input = 0;
			key_input = _getch();
			if (key_input == 'y')
			{
				game_state = 0;
				screen = 1;
			}
			break;
		default:
			break;
		}
	}
	return 0;
}
