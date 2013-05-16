#ifndef H_PLAY
#define H_PLAY

//Checks if a player has won.
int checkWin(board p, int j, int k, int paint);

//Returns 1 if it's possible to place a mark at column col, 0 otherwise
int validate(board p, int col, Gamer *g1, Gamer *g2,int *numTurns,int*freeSpaces,int*num,int*TOTmoves,int*WHOSETURNISIT,Gamer*currentgamer);
int validateIA(board p,int col); // TESTING FUNCTION

// Returns the first position with a free space in column col
int findLine(board p, int col);

// Player vs Player
void playerVsPlayer(Gamer *g1, Gamer *g2, board p);

// Player vs Computer
void playerVsComputer(Gamer *g1, Gamer *g2, board p, int difficulty);

#endif
