#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Global.h"
#include "Board.h"
#include "Play.h"
#include "IA.h"
#include "IA_woot.h"

/**
 * This function calculates the play for the computer in hardcore mode (currently bugged).
 * @param p Receives the board.
 * @param numTurns Receives the number of turns in order to predict some plays.
 * @param lastPlay Receives the last play so it can prevent some win situations from the player.
 * @return play Returns the play that computer will do.
 */
int playIA_hardcore_Jorge(board p, int numTurns, int lastPlay) {

    int play = 9, j, k, i = 0;
    char aux[WIDTH][HEIGHT] = {
        {3, 4, 5, 5, 4, 3},
        {4, 6, 8, 8, 6, 4},
        {5, 8, 11, 11, 8, 5},
        {7, 10, 13, 13, 10, 7},
        {5, 8, 11, 11, 8, 5},
        {4, 6, 8, 8, 6, 4},
        {3, 4, 5, 5, 4, 3}
    };

    if (numTurns == 1) {
        play = 3;
    } else if ((numTurns == 2) && ((lastPlay == 2 || lastPlay == 4 || lastPlay == 1 || lastPlay == 5) && p[3][HEIGHT - 1] == J1)) {
        play = (lastPlay == 2 ? 1 :
                (lastPlay == 4 ? 5 :
                (lastPlay == 5 ? 4 : 2)));
    } else {
        for (j = 0; j < WIDTH; j++) {
            for (k = HEIGHT - 1; k > 0; k--) {
                if (p[j][k] == EMPTY) {
                    p[j][k] = J2;
                    if (checkWin(p, j, k, 0)) {
                        play = j;
                    }
                    p[j][k] = EMPTY;
                }

            }
        }
        for (j = 0; j < WIDTH; j++) {
            for (k = HEIGHT - 1; k > 0; k--) {
                if (p[j][k] == EMPTY && play == 9) {
                    p[j][k] = J1;
                    if (checkWin(p, j, k, 0)) {
                        play = j;
                    }
                    p[j][k] = EMPTY;
                }
            }
        }

       if (play == 9) {
             for (j = 0; j < WIDTH; j++) {
              for (k = HEIGHT - 1; k > 0; k--) {
                     if (p[j][k] == EMPTY && aux[j][k] > i){
                         p[j][k-1] = J1;
                         if(!checkWin(p, j, k-1,0)){
                                i = aux[j][k];
                                play = j;
                         }
                         p[j][k-1] = EMPTY;
                    }
                }
            }
        }

    }
    return play;
}
