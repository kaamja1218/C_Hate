#include<stdio.h>

void draw_game_board(int width, int height)
{
    int i, j;

    for (i = 0; i < width + 2; i++) {
        printf("*");
    }
    printf("\n");

    for (j = 0; j < height; j++) {
        printf("*");
        for (i = 0; i < width; i++) {
            printf(" ");
        }
        printf("*\n");
    }

    for (i = 0; i < width + 2; i++) {
        printf("*");
    }
    printf("\n");
}
void main()
{
    draw_game_board(30, 15);
}
