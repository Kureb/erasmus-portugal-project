#ifndef H_GLOBAL
#define H_GLOBAL


#define TAILLE_PION 52 //The real size is 50
#define LARGEUR_FENETRE 220
#define HAUTEUR_FENETRE 180
#define PLAYERNAME 20
#define HEIGHT 6
#define WIDTH 7

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



enum {RIGHT, LEFT};
enum {VIDE, J1, J2, J1W, J2W};

typedef struct
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


