#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <conio.h>
#include <SDL/SDL_ttf.h>

#include "global.h"
#include "board.h"
#include "play.h"
#include "TeamPT.h"
#include "utilities.h"
#include "credits.h"




int main(int argc, char *argv[])
{


    /*
    //For DEBUG, it allow us to use the console
    freopen("CON", "w", stdout);
    freopen("CON", "r", stdin);
    freopen("CON", "w", stderr);
    */

    SDL_Surface *screen = NULL;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return 1;

    if(TTF_Init() < 0) return -1;
    TTF_Font *font = NULL;
    font = TTF_OpenFont("verdana.ttf", 18);

    if(font == NULL)
    {
        printf("TTF_OpenFont : %s\n", TTF_GetError());
    }
    TTF_Font *bigFont = NULL;
    bigFont = TTF_OpenFont("verdana.ttf", 72);

    if(bigFont == NULL)
    {
        printf("TTF_OpenFont : %s\n", TTF_GetError());
    }




    if (!(screen = SDL_SetVideoMode(1024, 600, 32, SDL_HWSURFACE)))
    {
        //TTF_Quit();
        SDL_Quit();
        return 1;
    }


    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));



    int option, difficulty = 4;
    char * name;



    do
    {
        SDL_WM_SetCaption("4inALine - ViOpe", NULL);
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        option = welcome(screen, font, bigFont);

        if(option > 0)
        {
            if(option == 3)
            {
                print_credits(screen,font);
            }
            if(option == 1)  // Player vs Player
            {
                board p;
                Gamer g1,g2;
                strcpy(g1.name, "Player 1");
                g1.num = 1;
                g1.moves = 0;
                strcpy(g2.name,"Player 2");
                g2.num = 2;
                g2.moves = 0;
                initializeGrid(p,screen);
                showBoard(p,screen,font,bigFont);
                playerVsPlayer(&g1,&g2,p,screen,font, bigFont);
            }
            else
            {
                if(option == 2)
                {
                    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                    difficulty = chooseDifficulty(screen,font,bigFont);

                    if(difficulty > 0)
                    {
                        board p;
                        Gamer g1,g2;
                        strcpy(g1.name, "Player");
                        g1.num = 1;
                        g1.moves = 0;
                        g2.num = 2;
                        g2.moves = 0;
                        strcpy(g2.name, "Computer");
                        initializeGrid(p, screen);
                        showBoard(p, screen, font, bigFont);
                        playerVsComputer(&g1, &g2, p, difficulty, screen, font,bigFont);
                    }
                }

            }
        }
    }
    while(option != -1);

    TTF_CloseFont(font);
    TTF_CloseFont(bigFont);
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}

