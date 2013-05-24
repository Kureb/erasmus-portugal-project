#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <conio.h>
#include <SDL/SDL_ttf.h>
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

int pause()
{
    SDL_Event event;
    int continuer = 1;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                return 27;
                break;
            case SDLK_s:
                return -1;
                break;
            case SDLK_q:
                return -2;
                break;
            case SDLK_KP1:
            case SDLK_1:
                return 0;
                break;
            case SDLK_KP2:
            case SDLK_2:
                return 1;
                break;
            case SDLK_KP3:
            case SDLK_3:
                return 2;
                break;
            case SDLK_KP4:
            case SDLK_4:
                return 3;
                break;
            case SDLK_KP5:
            case SDLK_5:
                return 4;
                break;
            case SDLK_KP6:
            case SDLK_6:
                return 5;
                break;
            case SDLK_KP7:
            case SDLK_7:
                return 6;
                break;
            case SDLK_o:
                return 8;
                break;
            case SDLK_RETURN:
            case SDLK_KP_ENTER:
                return 13;
                break;
            default:
                continuer = 1;
                break;

            }
            break;
        }
    }

}
void printWindow(int R,int G,int B, int x, int y, SDL_Surface * screen, char * text, TTF_Font *font)
{

    SDL_Surface *textSurf = NULL;
    SDL_Rect position;
    SDL_Color color = {R,G,B};



    textSurf = TTF_RenderText_Blended(font, text, color);
    if(x == 999)
    {
        position.x = (screen->w-textSurf->w)/2;
        position.y = y;
    }
    else
    {
        position.x = x;
        position.y = y;
    }
    SDL_BlitSurface(textSurf, NULL, screen, &position);
    SDL_Flip(screen);

    SDL_free(textSurf);



    font = NULL;


}










