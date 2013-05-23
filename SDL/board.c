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
    //SDL_Surface *vide = NULL;
    //SDL_Rect positionVide;

    int i,j;
    for(i=0;i<WIDTH;i++){
		for(j=0;j<HEIGHT;j++){
      			p[i][j] = VIDE;
			}
    }

   // SDL_BlitSurface(vide, NULL, screen, &positionVide);
}

/* Display of the board,
** with graphic-text boxes
** and we fill boxes
*/
void showBoard(board p, SDL_Surface* screen)
{
	int i, j;
	SDL_Rect position;
	SDL_Surface *vide = NULL, *red = NULL, *yellow = NULL, *redW = NULL, *yellowW = NULL, *num;
	SDL_Surface *texte=NULL;

    vide = SDL_LoadBMP("empty.bmp");
    red = SDL_LoadBMP("red.bmp");
    yellow = SDL_LoadBMP("yellow.bmp");
    redW = SDL_LoadBMP("redW.bmp");
    yellowW = SDL_LoadBMP("yellowW.bmp");
    num = SDL_LoadBMP("number.bmp");


    position.x = 100;
    position.y= 100;


	for(i=0;i<WIDTH;i++){
		for(j=0;j<HEIGHT;j++){
      //      positionVide.x = 100 + i * 50 + 10;
        //    positionVide.y = 100 + i * 50 + 10;
            position.x = i * TAILLE_PION + 100;
            position.y = j * TAILLE_PION + 100;

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

	position.x = 100;
    position.y+= TAILLE_PION;
	SDL_BlitSurface(num, NULL, screen, &position);

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
    SDL_free(num);

    SDL_Flip(screen);

}


