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




int main(int argc, char *argv[])
{


    /*
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



    /*

        TTF_Font *font=NULL;
        font = TTF_OpenFont("BebasNeue.otf", 14);


        SDL_Surface *textSurf = NULL;
        SDL_Rect position;
        SDL_Color color = {0,255,1202};

        position.x = 50;
        position.y = 50;

        textSurf = TTF_RenderText_Blended(font, "test", color);

        SDL_BlitSurface(textSurf, NULL, screen, &position);
        SDL_Flip(screen);

    */



    //TTF_CloseFont(font);
    //SDL_free(textSurf);










    int option, difficulty = 4;
    char * name;



    do
    {
        SDL_WM_SetCaption("4inALine - ViOpe", NULL);
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        option = welcome(screen, font, bigFont);

        if(option > 0)
        {
            if(option == 1)  // Player vs Player
            {
                board p;
                Gamer g1,g2;
                strcpy(g1.name, "Alex");
                g1.num = 1;
                g1.moves = 0;
                strcpy(g2.name,"Jorge");
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
                        strcpy(g1.name, "Alex");
                        g1.num = 1;
                        g1.moves = 0;
                        g2.num = 2;
                        g2.moves = 0;
                        strcpy(g2.name, "Computer");
                        initializeGrid(p, screen);
                        showBoard(p, screen, font, bigFont);
                        // setCursorVisible(FALSE);
                        /*if(option == 1) // Player vs Player
                            playerVsPlayer(&g1,&g2,p,screen,font, bigFont);
                        else // Player vs Computer*/
                        playerVsComputer(&g1, &g2, p, difficulty, screen, font,bigFont);
                    }
                }
            }
        }
    }
    while(option != -1);
    /*option = pause()+1;
    if(option==1){
        board p;
        initializeGrid(p, screen);
        showBoard(p, screen, font, bigFont);
        Gamer g1, g2;
        g1.num = 1;
        strcpy(g1.name, "Alex");
        g2.num = 2;
        strcpy(g2.name, "Test");
        playerVsPlayer(&g1, &g2, p, screen, font, bigFont);
    }else if(option==2){
        board p;
        initializeGrid(p, screen);
        showBoard(p, screen, font, bigFont);
        Gamer g1, g2;
        g1.num = 1;
        strcpy(g1.name, "Alex");
        g2.num = 2;
        strcpy(g2.name, "Computer");
        difficulty = pause()+1;
        playerVsComputer(&g1, &g2, p, difficulty, screen, font,bigFont);

    }

    */



    // }



    TTF_CloseFont(font);
    TTF_CloseFont(bigFont);
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}

