#include "screen.h"
#define _CRT_SECURE_NO_WARNINGS

char screenBuf[35 * 12 + 1];  // screenBuf를 전역 변수로 정의합니다.

int width = 34;  // width도 전역 변수로 정의합니다.
int height = 12;

int clearBuffer(char* screenBuf, int width, int height)
{
	int i = 0;	/* 가로 index */
	int j = 0;  /* 세로 index */
	while (j < height)
	{
		while (i < width + 1) /* 개행문자때문에 + 1*/
		{
			if (i == width)
				screenBuf[i + (j * (width + 1))] = '\n';
			else
			{
				if (i == 0 || i == 1 || i == (width - 1) || i == (width - 2) || j == 0 || j == (height - 1))
					screenBuf[i + (j * (width + 1))] = '#';
				else
					screenBuf[i + (j * (width + 1))] = ' ';
			}
			i = i + 1;
		}
		i = 0;
		j = j + 1;
	}
	screenBuf[height * (width + 1) - 1] = '\0';
	return 0;
}

int writeStringToBuffer(const char* string, int x, int y, char* screenBuf, int width)
{
	int i = 0;
	while (string[i] != '\0')
	{
		screenBuf[x + y * (width + 1) + i] = string[i];
		i++;
	}
	return 0;
}

