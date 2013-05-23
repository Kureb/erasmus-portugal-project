#ifndef TEAMPT_H
#define TEAMPT_H

//*****************************************
//Welcome screen
//It should give an welcome message to the user
//Should also write say the name of each player on the screen
//
//input parameters:
//		none
//output value:
//		1 if the chosen game mode was player vs player
//		2 if the chosen game mode was player vs computer
//		3 if the user wants to check the high scores
//		0 if the user wants to exit
//*****************************************
int welcome();

//*****************************************
//The choose difficulty screen
//It asks the user the level in which of intelligence of
//the computer
//
//input parameters:
//		none
//output value:
//		1 if the chosen difficulty is easy
//		2 if the chosen difficulty is normal
//		3 if the chosen difficulty is hard
//*****************************************
int chooseDifficulty();

#endif // TEAMPT_H

