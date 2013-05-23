#ifndef H_PLAY
#define H_PLAY

//Checks if a player has won.


//Returns 1 if it's possible to place a mark at column col, 0 otherwise
int validate(board p, int col);

void playerVsPlayer(Gamer *g1, Gamer *g2, board p, SDL_Surface *screen);

void playerVsComputer(Gamer *g1, Gamer *g2, board p, int difficulty, SDL_Surface *screen);

int findLine(board p, int col);

int checkWin(board p, int j, int k, int paint, SDL_Surface *ecran);

int chooseCol(board p);

void loadgame (Gamer* player1, Gamer* player2,board p,int *numTurns,int*freeSpaces,int*Move1,int*Move2,int *WHOSETURNISIT,Gamer*currentgamer, SDL_Surface *screen);

void savegame (Gamer player1, Gamer player2,board p,int numTurns,int freeSpaces,Gamer currentgamer);



#endif
