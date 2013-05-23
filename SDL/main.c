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

    SDL_Surface *screen = NULL;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return 1;

    if(TTF_Init() ==- 1) return -1;



    if (!(screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE)))
    {
        //TTF_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_WM_SetCaption("4inALine - ViOpe", NULL);
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));


    int option, difficulty;

            //option = welcome();



    option = pause()+1;
    if(option==1){
        board p;
        initializeGrid(p, screen);
        showBoard(p, screen);
        Gamer g1, g2;
        g1.num = 1;
        strcpy(g1.name, "Alex");
        g2.num = 2;
        strcpy(g2.name, "Test");
        playerVsPlayer(&g1, &g2, p, screen);
    }else if(option==2){
        board p;
        initializeGrid(p, screen);
        showBoard(p, screen);
        Gamer g1, g2;
        g1.num = 1;
        strcpy(g1.name, "Alex");
        g2.num = 2;
        strcpy(g2.name, "Computer");
        playerVsComputer(&g1, &g2, p, 3, screen);

    }





   // }


    printf("Debug 1\n");

    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}

