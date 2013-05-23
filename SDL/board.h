#ifndef H_BOARD
#define H_BOARD

#include "global.h"


/* We initialize the board (2D)
** Each box is VIDE
*/
void initializeGrid(board p, SDL_Surface* screen);


/* Display of the board,
** with graphic-text boxes
** and we fill boxes
*/
void showBoard(board p, SDL_Surface* screen);

#endif

