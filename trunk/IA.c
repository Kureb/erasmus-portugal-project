#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
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
    srand(time(NULL));
    Sleep(1000);
    do
	{
		num = (rand() % (WIDTH));
	} while (!validate(p, num));
    //printf("The computer chose column %d \n", num);
    /*int number = num-1;
    int i=0;
    for(i=HEIGHT-1; i>=0; i--)
    {
        //From top to bottom, it stops at the first blank
        if(p[number][i] == EMPTY)
        {
            //The Computer is the player 2
            p[(number)][i] = J2;
            break;
        }
    }*/
    //showBoard(p, g);
    /*int a = (checkWin(p, number, i));
    if(a==1)
    {
        //printf("%s won ! Congratulation \n", g.name);
        play=1;
    }*/

    return num;
}

//NE MARCHE PAS
//UNE FOIS QUE LA PREMIERE LIGNE
//EST REMPLIE

int playIA_normal(board p)
{
    int i,j,w,a,number = 0;
    int ok=0;

    for(j=WIDTH-1; j>=0; j--)
    {
        for(i=HEIGHT-1; i>=0; i--)
        {

            if(p[j][i]==EMPTY)
            {
                //a = checkWeight(p,j,i);
                p[j][i] = J2;//Obligé de placer un jeton pour comparer
                a = checkWeight(p,j,i);
                w=4;
                while(ok!=1)
                {


                    if(a==w)
                    {
                        p[j][i] = J2;
                        ok=1;//pour sortir de toutes ces imbrications de boucle
                        number = j+1;//on récupère la colonne
                        i=-1;//idem
                        j=-1;//sortir des imbrications

                    }
                    else
                    {
                        p[j][i] = EMPTY;
                    }
                    w--;


                }//fin while
                //break;
            }//Fin if EMPTY
            break;
        }

    }

    //printf("The computer chose column %d \n", number);
    /*showBoard(p, g);
    int b = (checkWin(p, number+1, i));
    if(b==1)
    {
        //printf("%s won ! Congratulation \n", g.name);
        play=1;
    }*/

    return number + 1;
}

int playIA_hardcore(board p)
{
    return 0;
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
