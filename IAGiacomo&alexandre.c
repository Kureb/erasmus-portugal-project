#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


int playIA_normal(board p, int col)

{
	int num,k,j, play;
    srand((unsigned)time(NULL));
    do
	{
		/*check_if_player_is_about_to_win_first(p);*/
	int k = whatstherow (p, j) ;
	//for (j=0; j<HIGHT ; j++)
		//for (k=0; k<WIDTH ; k++)
		if (!j)
		//check only right

			if (p[k][j]==J1)
				if ((j-2>=0) && (j+2<=6))
					if (p[k][j-1]==J1)
						if ((p[k][j-2]=='-')&&(p[k][j+1]=='-')&&((p[k][j+2]==J1)))
							play=j+1//p[k][j+1]=J2;

				if ((j-3>=0) && (j+1<=6))
					if (p[k][j-1]==J1)
						if ((p[k][j-2]=='-')&&(p[k][j+1]=='-')&&((p[k][j-3]==J1)))
							play=j-2//p[]k[j-2]=J2;

				if ((j-1>=0) && (j+2<=6))
					if (p[k][j+1]==J1)
						if ((p[k][j-1]=='-')&&(p[k][j+2]=='-')&&((p[k][j+3]==J1)))
							play=j+2//p[k][j+2]=J2;
				if ((j-2>=0) && (j+2<=6))

						if ((p[k][j-1]=='-')&&(p[k][j+2]=='-')&&((p[k][j-2]==J1)))
							play=j-1//p[]k[j-1]=J2;

	} while (!validate(p, num));

    return play;
}

int whatstherow (board p,int col)
{
	for (k=WIDTH-1;k>=0;k--)
		if (p[i][col]=='-')
			return k;
}


/*int check_if_player_is_about_to_win_first(board p, int j)

{

	int k = whatstherow (p, j) ;
	//for (j=0; j<HIGHT ; j++)
		//for (k=0; k<WIDTH ; k++)
		if (!j)
		//check only right

			if (p[k][j]==J1)
				if ((j-2>=0) && (j+2<=6))
					if (p[k][j-1]==J1)
						if ((p[k][j-2]=='-')&&(p[k][j+1]=='-')&&((p[k][j+2]==J1)))
							p[k][j+1]=J2;

				if ((j-3>=0) && (j+1<=6))
					if (p[k][j-1]==J1)
						if ((p[k][j-2]=='-')&&(p[k][j+1]=='-')&&((p[k][j-3]==J1)))
							p[]k[j-2]=J2;

				if ((j-1>=0) && (j+2<=6))
					if (p[k][j+1]==J1)
						if ((p[k][j-1]=='-')&&(p[k][j+2]=='-')&&((p[k][j+3]==J1)))
							p[k][j+2]=J2;
				if ((j-2>=0) && (j+2<=6))

						if ((p[k][j-1]=='-')&&(p[k][j+2]=='-')&&((p[k][j-2]==J1)))
							p[]k[j-1]=J2;







	return is_him_about;*/
