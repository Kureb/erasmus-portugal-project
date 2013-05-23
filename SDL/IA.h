#ifndef H_IA
#define H_IA

//First level of IA
int playIA_noob(board p);

int checkOrizontal (board p);
int winning (board p);

/* Second level of IA
 * Doesn't work at all
 * Once the first line filled, the computer can not choose column
 */
int playIA_normal(board p, int k, int col, SDL_Surface *screen);

/* Last level of IA
 * It needs to look carefullyif it
 * can block the other player
 * and allow itself to win
 */
int playIA_hardcore(board p, int numTurns, SDL_Surface *screen);

/* The five following compute in each columns
 * if we put a token, how many tokens are already aligned
 * in all directions
 * The last functions assigns a weight to the columns
 */
int checkDiagonalDownUp(board p, int j, int k);
int checkDiagonalUpDown(board p, int j, int k);
int checkHorizontal(board p, int j, int k);
int checkVertical(board p, int j, int k);
int checkWeight(board p, int j, int k);

#endif
