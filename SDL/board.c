#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "global.h"
#include "board.h"
#include "utilities.h"




/* We initialize the board (2D)
** Each box is VIDE
*/
void initializeGrid(board p, SDL_Surface* screen)
{

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    int i,j;
    for(i=0; i<WIDTH; i++)
    {
        for(j=0; j<HEIGHT; j++)
        {
            p[i][j] = VIDE;
        }
    }
}

/* Display of the board,
** with graphic-text boxes
** and we fill boxes
*/
void showBoard(board p, SDL_Surface* screen, TTF_Font *font, TTF_Font *bigFont)
{
    int i, j;
    char number[2];
    SDL_Rect position;
    SDL_Surface *vide = NULL, *red = NULL, *yellow = NULL, *redW = NULL, *yellowW = NULL;

    vide = SDL_LoadBMP("empty.bmp");
    red = SDL_LoadBMP("red.bmp");
    yellow = SDL_LoadBMP("yellow.bmp");
    redW = SDL_LoadBMP("redW.bmp");
    yellowW = SDL_LoadBMP("yellowW.bmp");

    position.x = (screen->w - TAILLE_PION)/2;
    position.y= 100;

    for(i=0; i<WIDTH; i++)
    {
        for(j=-1; j<HEIGHT; j++)
        {
            //      positionVide.x = 100 + i * 50 + 10;
            //    positionVide.y = 100 + i * 50 + 10;
            position.x = (i * TAILLE_PION) + (screen->w - (7*TAILLE_PION))/2;
            position.y = j * TAILLE_PION + 100;
            if (j == -1)
            {
                position.y = j * TAILLE_PION + 450;
                sprintf(number,"%d",i+1);
                printWindow(0,0,0,position.x,position.y,screen,number, bigFont);
            }
            else
            {
                switch(p[i][j])
                {
                case VIDE:
                    SDL_BlitSurface(vide, NULL, screen, &position);
                    break;
                case J1:
                    SDL_BlitSurface(red, NULL, screen, &position);
                    break;
                case J2:
                    SDL_BlitSurface(yellow, NULL, screen, &position);
                    break;
                case J1W:
                    SDL_BlitSurface(redW, NULL, screen, &position);
                    break;
                case J2W:
                    SDL_BlitSurface(yellowW, NULL, screen, &position);
                    break;
                }
            }
        }

    }

    /*
        TTF_Init();
        TTF_Font *police = NULL;
        police = TTF_OpenFont("font.ttf", 65);
        SDL_Color couleurNoire = {0, 0, 0};
        texte = TTF_RenderText_Blended(police, "4 In A Line !", couleurNoire);
        TTF_CloseFont(police);
        TTF_Quit();
    */
    SDL_free(red);
    SDL_free(yellow);
    SDL_free(vide);
    SDL_free(redW);
    SDL_free(yellowW);

    SDL_Flip(screen);

}


