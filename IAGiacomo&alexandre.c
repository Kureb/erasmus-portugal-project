#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "Global.h"
#include "Board.h"
#include "Play.h"
#include "IA.h"





int checkOrizontal (board p)
{
    srand ((unsigned)time(NULL));
    int j,k,def=-1;
        for (k=0; k<HEIGHT ; k++)
            for (j=0; j<WIDTH ; j++){
                if (p[j][k]==J1){
                    if (p[j+1][k]==J1) {
                        if (k==(HEIGHT-1))    {
                            if ((p[j+2][k]==EMPTY)&&(p[j-1][k]==EMPTY)){
                                if ((rand()%2)==0)
                                    def=(j+2);
                                else
                                    def=(j-1);
                                }
                            if ((p[j+2][k]==J1)&&(p[j-1][k]!=EMPTY)&&(p[j+3][k]==EMPTY)){
                                def=(j+3) ;
                            }
                            if ((p[j+2][k]==J1)&&(p[j+3][k]!=EMPTY)&&(p[j-1][k]==EMPTY)){
                                def=(j-1);
                            }
                        }

                        else {
                        if ((p[j+2][k]==EMPTY)&&(p[j-1][k]==EMPTY)&&(p[j-1][k+1]!=EMPTY)&&(p[j+2][k+1]!=EMPTY)){
                            if ((rand()%2)==0)
                                def=(j+2);
                            else
                                def=(j-1);
                            }
                        if ((p[j+2][k]==J1)&&(p[j-1][k]!=EMPTY)&&(p[j+3][k]==EMPTY)&&(p[j-1][k+1]!=EMPTY)){
                            def=(j+3) ;
                        }
                        if ((p[j+2][k]==J1)&&(p[j+3][k]!=EMPTY)&&(p[j+3][k+1]!=EMPTY)&&(p[j-1][k]==EMPTY)){
                            def=(j-1);
                        }
                    }
                }
            }
        }




    return def;
}

int winning (board p) // if the pc is about to win, return the column in whitch the computer has to play to win, otherwise returns 0
    {


    int j,k,win=0;
    for (k=0; k<HEIGHT ; k++){
        for (j=0; j<WIDTH ; j++){
            if (p[j][k]==J2){
                if ((p[j][k+1]==J2)&&(p[j][k+2]==J2)&& (k>0))
                        win=j;

                if ((p[j+1][k]==J2)&&(p[j+2][k]==J2)){
                        if(((j+3)<=(WIDTH-1))&& p[j+3][k]==EMPTY)
                            win=j+3;
                        if(((j-1)>=0)&& p[j-1][k]==EMPTY)
                            win=j-1;
                        }
                    }

                }
            }
            return win;
    }

int playIA_normal(board p,int k, int col)

{
    int limit = WIDTH-1, limitk = HEIGHT-1;
	int num,j, play=-1;
	int x,y;
	j=col;

    Sleep(1500);
    do
	{
			//WINNING FUNC FIXED
			if (winning(p))
                return winning(p);
            //COLUMN FIXED

                if (k<HEIGHT-1){
                    if ((p[j][k+1]==J1)&&(p[j][k+2]==J1)&&(k>0))
                        return j;
                }

            // ORIZONTAL
            if (checkOrizontal(p)!=-1)
                return checkOrizontal(p);


            if (play == -1)
                if (j>3)
                    play=j-1;
                else
                    play=j+1;





			//}
	} while (play==-1);

    return play;
}





