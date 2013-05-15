#ifndef H_GLOBAL
#define H_GLOBAL

#define HEIGHT 6
#define WIDTH 7
#define EMPTY '-'
#define TEST '#'
#define PLAYERNAME 20
#define J1 'X'
#define J2 'O'

typedef struct Gamer
{
    int num;
    int moves;	// We need to keep track of the number of moves made
    char name[PLAYERNAME];
} Gamer;

typedef struct
{
    int numGames; //total played games
    int numWins; // number of games won
    int totalNumMoves; // the total number of moves made by the player
    int totalScore; // the total score achieved by this player through all his games
    char name[PLAYERNAME] ; //the name of the player
} GamerStat;

typedef char board[WIDTH][HEIGHT];

#endif
