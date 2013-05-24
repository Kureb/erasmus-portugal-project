#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utilities.h"
#include "Global.h"
#include "Board.h"
#include "Play.h"
#include "IA.h"

/* First level of IA
** Computer just generate
** a number between 1 and WIDTH
** of the board
*/

int playIA_noob(board p)
{
    int num;
    do
    {
        num = random(WIDTH);
    }
    while (!validate(p, num));
    Sleep(300);

    return num;
}

int checkCol (board p)
{
    int j,k,def=-1;
    for (k=0; k<HEIGHT ; k++)
        for (j=0; j<WIDTH ; j++)
        {
            if ((p[j][k]==J1)&&(p[j][k+1]==J1)&&(p[j][k+2]==J1)&& (k>0))
                def=j;
        }
    if (!validate(p,def))
        def=-1;

    return def;
}


int checkD (board p)
{
    srand ((unsigned)time(NULL));
    int j,k,def=-1;
    for (k=0; k<HEIGHT ; k++)
        for (j=0; j<WIDTH ; j++)
            if (p[j][k]==J1)
                if (p[j+1][k-1]==J1)
                {
                    if ((p[j+2][k-2]==VIDE)&&(p[j-1][k+1]==VIDE)&&(p[j+2][k-1]!=VIDE)&&(p[j-1][k+2]!=VIDE))
                    {
                        if ((rand()%2)==0)
                            def=(j+2);
                        else
                            def=(j-1);
                    }
                    if ((p[j+2][k-2]==VIDE)&&(p[j-1][k+1]==J1)&&(p[j+2][k-1]!=VIDE))
                        def=j+2;
                    if ((p[j+2][k-2]==J1)&&(p[j-1][k+1]==VIDE)&&(p[j-1][k+2]!=VIDE))
                        def=j-1;

                }
    if (p[j-1][k-1]==J1)
    {
        if ((p[j-2][k-2]==VIDE)&&(p[j+1][k+1]==VIDE)&&(p[j-2][k-1]!=VIDE)&&(p[j+1][k+2]!=VIDE))
        {
            if ((rand()%2)==0)
                def=(j-2);
            else
                def=(j+1);
        }
        if ((p[j-2][k-2]==VIDE)&&(p[j+1][k+1]==J1)&&(p[j-2][k-1]!=VIDE))
            def=j-2;
        if ((p[j-2][k-2]==J1)&&(p[j+1][k+1]==VIDE)&&(p[j+1][k+2]!=VIDE))
            def=j+1;
    }
    if (!validate(p,def))
        def=-1;
    return def;
}

int checkOrizontal (board p)
{
    srand ((unsigned)time(NULL));
    int j,k,def=-1;
    for (k=0; k<HEIGHT ; k++)
        for (j=0; j<WIDTH ; j++)
        {
            if (p[j][k]==J1)
            {
                if (p[j+1][k]==J1)
                {
                    if (k==(HEIGHT-1))
                    {
                        if ((p[j+2][k]==VIDE)&&(p[j-1][k]==VIDE))
                        {
                            if ((rand()%2)==0)
                                def=(j+2);
                            else
                                def=(j-1);
                        }
                        if ((p[j+2][k]==J1)&&(p[j-1][k]!=VIDE)&&(p[j+3][k]==VIDE))
                        {
                            def=(j+3) ;
                        }
                        if ((p[j+2][k]==J1)&&(p[j+3][k]!=VIDE)&&(p[j-1][k]==VIDE))
                        {
                            def=(j-1);
                        }
                    }

                    else
                    {
                        if ((p[j+2][k]==VIDE)&&(p[j-1][k]==VIDE)&&(p[j-1][k+1]!=VIDE)&&(p[j+2][k+1]!=VIDE))
                        {
                            if ((rand()%2)==0)
                                def=(j+2);
                            else
                                def=(j-1);
                        }
                        if ((p[j+2][k]==J1)&&(p[j-1][k]!=VIDE)&&(p[j+3][k]==VIDE)&&(p[j-1][k+1]!=VIDE))
                        {
                            def=(j+3) ;
                        }
                        if ((p[j+2][k]==J1)&&(p[j+3][k]!=VIDE)&&(p[j+3][k+1]!=VIDE)&&(p[j-1][k]==VIDE))
                        {
                            def=(j-1);
                        }
                    }
                }
            }
        }


    if (!validate(p,def))
        def=-1;

    return def;
}

int winning (board p) // if the pc is about to win, return the column in whitch the computer has to play to win, otherwise returns 0
{


    int j,k,win=-1;
    for (k=0; k<HEIGHT ; k++)
    {
        for (j=0; j<WIDTH ; j++)
        {
            if (p[j][k]==J2)
            {
                if ((p[j][k+1]==J2)&&(p[j][k+2]==J2)&& (k>0))
                    win=j;

                if ((p[j+1][k]==J2)&&(p[j+2][k]==J2))
                {
                    if(((j+3)<=(WIDTH-1))&& p[j+3][k]==VIDE)
                        win=j+3;
                    if(((j-1)>=0)&& p[j-1][k]==VIDE)
                        win=j-1;
                }
            }

        }
    }

    if (!validate(p,win))
        win=-1;

    return win;
}

int playIA_normal(board p,int k, int col, SDL_Surface *screen)

{
    srand ((unsigned)time(NULL));
    int j=col, play=-1;

    Sleep(500);

    //WINNING FUNC FIXED
    if (winning(p)!=-1)
        return winning(p);
    // VERTICAL
    if (checkCol(p)!=-1)
        return checkCol(p);
    // ORIZONTAL
    if (checkOrizontal(p)!=-1)
        return checkOrizontal(p);
    // DIAGONALS
    if (checkD(p)!=-1)
        return checkD(p);


    if (play == -1)
    {
        if ((j>3)&&(validate(p,(j-1))))
            play=j-1;
        else if ((j<=3)&&(validate(p,(j+1))))
            play=j+1;
        else
            do
                play= rand()%7;
            while(!validate(p,play));
    }







    return play;
}

int playIA_hardcore(board p, int numTurns, SDL_Surface *screen)
{
    int i, j, k, l, num = -1;
    if(numTurns == 1) // This is the first turn
    {
        if(p[3][HEIGHT - 1] == J1)
            num = 2 + (random(2) * 2); // 2 or 4
        else
            num = 3;
    }
    else
    {
        int plays[WIDTH] = {0}, pos[WIDTH], max, maxPos, winFlag, marksHorizontal, marksVertical, marksDiag1, marksDiag2, moveValidated;
        setCursorPosition(0, 10);
        for(i = 0; i < WIDTH; i++)
            pos[i] = findLine(p, i);

        for(i = 0; i < WIDTH; i++)
        {
            if(pos[i] >= 0)
            {
                p[i][pos[i]] = J2;
                winFlag = checkWin(p, i, pos[i], 0, screen); // Check if if the computer playes here, it will win
                p[i][pos[i]] = VIDE; // Clear the position
                if(winFlag)
                {
                    num = i;
                    break;
                }
            }
        }

        if(num < 0)
        {
            for(i = 0; i < WIDTH; i++)
            {
                if(pos[i] >= 0)
                {
                    p[i][pos[i]] = J1;
                    winFlag = checkWin(p, i, pos[i], 0, screen); // If checkWin returns true here, the player would win if he played in this position. So, the computer will play here to prevent that
                    p[i][pos[i]] = VIDE; // Clear the position
                    if(winFlag)
                    {
                        num = i;
                        break;
                    }
                    else
                    {
                        marksHorizontal = marksVertical = marksDiag1 = marksDiag2 = 0;
                        for(k = i - 1; k >= 0 && p[k][pos[i]] == J2; k--, marksHorizontal++);
                        for(k = i + 1; k < WIDTH && p[k][pos[i]] == J2; k++, marksHorizontal++);

                        for(k = pos[i] + 1; k < HEIGHT && p[i][k] == J2; k++, marksVertical++);

                        for(k = i - 1, l = pos[i] - 1; i >= 0 && l >= 0 && p[k][l] == J2; k--, l--, marksDiag1++);
                        for(k = i + 1, l = pos[i] + 1; i < WIDTH && l < HEIGHT && p[k][l] == J2; k++, l++, marksDiag1++);

                        for(k = i + 1, l = pos[i] - 1; i < WIDTH && l >= 0 && p[k][l] == J2; k++, l--, marksDiag2++);
                        for(k = i - 1, l = pos[i] + 1; i >= 0 && l < HEIGHT && p[k][l] == J2; k--, l++, marksDiag2++);

                        /*if(pos[i] <= 1)
                        {
                            if(marksVertical < 3)
                                marksVertical = 0; // Playing here is not useful if we can't win with it
                            if(marksDiag1 < 3)
                                marksDiag1 = 0;
                            if(marksDiag2 < 3)
                                marksDiag2 = 0;
                        }*/
                        if(i < 3 && p[i + 1][pos[i]] == J1 && p[i + 2][pos[i]] == J1 && p[i + 3][pos[i]] == VIDE)
                        {
                            marksHorizontal = 10; // High priority move! - - i x x - -
                        }

                        max = marksHorizontal;
                        if(marksVertical > max)
                            max = marksVertical;
                        if(marksDiag1 > max)
                            max = marksDiag1;
                        if(marksDiag2 > max)
                            max = marksDiag2;
                        plays[i] = max;
                    }
                }
            }
        }

        if(num == -1)
        {
            moveValidated = 1;
            int maxPlays[WIDTH] = {-1};
            int numMaxP;
            int playFlags[WIDTH];
            for(i = 0; i < WIDTH; i++)
            {
                if(pos[i] < 0)
                    playFlags[i] = -1;
                else
                    playFlags[i] = 1;
            }

            max = -1;
            maxPos = 0;
            numMaxP = 0;
            for(j = 0; j < WIDTH; j++)
            {
                if(pos[j] >= 0)
                {
                    winFlag = 0;
                    if(pos[j] > 0)
                    {
                        p[j][pos[j] - 1] = J1;
                        winFlag = checkWin(p, j, pos[j] - 1, 0, screen);
                        p[j][pos[j] - 1] = VIDE;
                    }
                    if(!winFlag)
                    {
                        if(plays[j] > max)
                        {
                            maxPos = j;
                            max = plays[j];
                            maxPlays[0] = j;
                            numMaxP = 1;
                        }
                        else if(plays[j] == max)
                        {
                            maxPlays[numMaxP] = j;
                            numMaxP++;
                        }
                    }
                    else
                        playFlags[j] = 0;
                }
            }
            j = 0; // Just a temporary flag
            for(i = 0; i < WIDTH; i++)
            {
                if(playFlags[i] == 1)
                {
                    j = 1;
                    break;
                }
            }
            if(j == 0) // Didn't found any positions that wouln't make the player a winner
            {
                for(i = 0; i < WIDTH; i++)
                {
                    if(playFlags[i] == 0) // Pick the first free column it finds
                        num = i;
                }
            }
            else
            {
                num = maxPlays[random(numMaxP)];
                moveValidated = validate(p, num);
            }
        }
    }
    Sleep(500);
    return num;
}
/*
* Returns the number of tokens
** which are in a line
** Returns a number between 1 and 4
**  +-----------------------> x (j)
**  |
**  |
**  |
**  |
**  |
**  |
**  |
**  v
**  y (k)
*/
int checkVertical(board p, int j, int k)
{
    //Vertical
    //It's a stack, so there is only one way to fill it
    //Up to down
    int vertical=1;
    if(p[j][k]==p[j][k+1])
    {
        vertical++;//=2
        if(p[j][k]==p[j][k+2])
        {
            vertical++;//=3
            if(p[j][k]==p[j][k+3])
            {
                vertical++;//=4
            }
        }
    }

    return vertical;
}

/* Returns the number of tokens
** which are in a line
** Returns a number between 1 and 4
*/
int checkHorizontal(board p, int j, int k)
{
    //Horizontal
    int horizontal=1;
    if(p[j][k]==p[j+1][k])
    {
        horizontal++;//=2
        if(p[j][k]==p[j+2][k])
        {
            horizontal++;//=3
            if(p[j][k]==p[j+3][k])
            {
                horizontal++;//=4
            }
        }
        else if(p[j][k]==p[j-1][k])
        {
            horizontal++;//=3
            if(p[j][k]==p[j-2][k])
            {
                horizontal++;//=4
            }
        }
    }
    else if(p[j][k]==p[j-1][k])
    {
        horizontal++;//=2
        if(p[j][k]==p[j+1][k])
        {
            horizontal++;//=3
            if(p[j][k]==p[j+2][k])
            {
                horizontal++;//=4
            }
        }
        else if(p[j][k]==p[j-2][k])
        {
            horizontal++;//=3
            if(p[j][k]==p[j-3][k])
            {
                horizontal++;//=4
            }
        }
    }

    return horizontal;
}

/* Returns the number of tokens
** which are in a line
** Returns a number between 1 and 4
**  +-----------------------> x (j)
**  |
**  |
**  |
**  |
**  |
**  |
**  |
**  v
**  y (k)
*/
int checkDiagonalUpDown(board p, int j, int k)
{
    //Diagonal Up-Down
    int diagoUD=1;
    if(p[j][k]==p[j+1][k-1])
    {
        diagoUD++;
        if(p[j][k]==p[j+2][k-2])
        {
            diagoUD++;
            if(p[j][k]==p[j+3][k-3])
            {
                diagoUD++;//=4
            }
        }
        else if(p[j][k]==p[j-1][k+1])
        {
            diagoUD++;//=3
            if(p[j][k]==p[j+2][k-2])
            {
                diagoUD++;//=4
            }
            else if(p[j][k]==p[j-2][k+2])
            {
                diagoUD++;
            }
        }
    }
    else if(p[j][k]==p[j-1][k+1])
    {
        diagoUD++;
        if(p[j][k]==p[j-2][k+2])
        {
            diagoUD++;
            if(p[j][k]==p[j-3][k+3])
            {
                diagoUD++;
            }
        }
    }

    return diagoUD;
}

/* Returns the number of tokens
** which are in a line
** Returns a number between 1 and 4
**  +-----------------------> x (j)
**  |
**  |
**  |
**  |
**  |
**  |
**  |
**  v
**  y (k)
*/
int checkDiagonalDownUp(board p, int j, int k)
{
    //Diagonal DownUp
    int diagoDU=1;
    if(p[j][k]==p[j+1][k+1])
    {
        diagoDU++;
        if(p[j][k]==p[j+2][k+2])
        {
            diagoDU++;
            if(p[j][k]==p[j+3][k+3])
            {
                diagoDU++;//=4
            }
        }
        else if(p[j][k]==p[j-1][k-1])
        {
            diagoDU++;//=3
            if(p[j][k]==p[j+2][k+2])
            {
                diagoDU++;//=4
            }
            else if(p[j][k]==p[j-2][k-2])
            {
                diagoDU++;
            }
        }
    }
    else if(p[j][k]==p[j-1][k-1])
    {
        diagoDU++;
        if(p[j][k]==p[j-2][k-2])
        {
            diagoDU++;
            if(p[j][k]==p[j-3][k-3])
            {
                diagoDU++;
            }
        }
    }

    return diagoDU;
}

/* assigning weights to each column
** Then playing in the one with the biggest weight
** We verify the possible alignments
** If res = 4, Weight = 4
** If res = 3, weight = 3
** If res = 2, weight = 2
** If res = 1, weight 0, we avoid playing there
** because our token is lonely
** The first shot (by the IA) will be played in
** boxes in the middle: more chance of winning (NEED TO BE IMPLEMENTED)
** Check all the alignements and return the biggest number
** We need to apply this fonction on each column
** Each columns will have a weight and we will play
** in the columns with the biggest weight
*/
int checkWeight(board p, int j, int k)
{
    int a = checkDiagonalDownUp(p, j, k);
    int b = checkDiagonalUpDown(p, j, k);
    int c = checkVertical(p, j, k);
    int d = checkHorizontal(p, j, k);

    int res[4];
    res[0]=a;
    res[1]=b;
    res[2]=c;
    res[3]=d;

    int i = 0;
    int maxi = res[0];

    while(i < 4)
    {
        if(res[i] > maxi)
        {
            maxi = res[i];
        }
        i++;
    }


    return maxi;

}

