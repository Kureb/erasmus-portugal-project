#ifndef H_PLAY
#define H_PLAY

//Checks if a player has won.
int checkWin(board p, int j, int k);

// Computes a score based on the number of moves required to win
int calculateScore(int moves);

//Returns 1 if it's possible to place a mark at column col, 0 otherwise
int validate(board p, int col);

// Player vs Player
void playerVsPlayer(Gamer *g1, Gamer *g2, board p);

// Player vs Computer
void playerVsComputer(Gamer *g1, Gamer *g2, board p, int difficulty);

#endif
