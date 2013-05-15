#include <windows.h>
#include <string.h>
#include <stdio.h>
#include "utilities.h"

void setCursorPosition(int x, int y)
{
    HANDLE Screen;
    Screen = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position= {x, y};

    SetConsoleCursorPosition(Screen, Position);
}

void printStringCenter(char *str, int y)
{
    int x;
    x = (int) ((SCREENWIDTH - strlen(str)) / 2);
    setCursorPosition(x, y);
    printf("%s", str);
}

void chomp(char *str)
{
    int pos = strlen(str) - 1;
    if(str[pos] == '\n')
    {
        str[pos] = '\0';
    }
}

void setTextColor(short color)
{
    HANDLE Screen = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Screen, color);
}

void setCursorVisible(BOOL visible)
{
    HANDLE Screen = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
    ConCurInf.bVisible = visible;

    SetConsoleCursorInfo(Screen, &ConCurInf);
}

int random(int n)
{
	FILETIME now;
    GetSystemTimeAsFileTime(&now);
    srand(now.dwLowDateTime);
    return rand() % n;
}

void clrscr()
{
	system(CLEAR);
}
