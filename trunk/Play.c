#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "Global.h"
#include "Board.h"
#include "Play.h"
#include "utilities.h"
#include "IA.h"
#include "Statistics.h"

/**
 * Checks if a player has won. 
 * Takes the coordinates of the last token played and checks if there is alignment.\n
 * +-----------------------> x (j)\n
 * |\n
 * |\n
 * |\n
 * |\n
 * |\n
 * |\n
 * |\n
 * v\n
 * y (k)
 * @param p This is the board.
 * @param j This is the x coordinate.
 * @param k This is the y coordinate.
 * @param paint Selects the color you want to paint the winning move. If 0 is select it does not paint it.
 * @return Returns 1 if it won, 0 otherwise.\
 */
int checkWin(board p, int j, int k, int paint)
{
    int vertical = 1;
    int horizontal = 1;
    int diago1 = 1;/* \ */
    int diago2 = 1;/* / */
    char disc = p[j][k];

    int v;//vertical
    int h;//horizontal
    int i, l; // counters

    //Vertical
    for(v=k+1; v < HEIGHT && p[j][v]==disc; v++, vertical++);
    for(v=k-1; v >= 0 && p[j][v]==disc; v--, vertical++);
    if(vertical>=4)
    {
        if(paint)
        {
            setTextColor(LIGHT_RED);
            for(i=k; i < HEIGHT && p[j][i] == disc; i++)
            {
                setCursorPosition(21 + j * 4, 3 + i * 2);
                putch(disc);
            }
            for(i=k - 1; i >= 0 && p[j][i] == disc; i--)
            {
                setCursorPosition(21 + j * 4, 3 + i * 2);
                putch(disc);
            }
            setTextColor(PURE_WHITE);
        }
        return 1;
    }

    //Horizontal(-)
    for(h=j-1; h>=0 && p[h][k]==disc; h--,horizontal++);
    for(h=j+1; h<WIDTH && p[h][k]==disc; h++,horizontal++);
    if(horizontal>=4)
    {
        if(paint)
        {
            setTextColor(LIGHT_RED);
            for(i=j; i < WIDTH && p[i][k] == disc; i++)
            {
                setCursorPosition(21 + i * 4, 3 + k * 2);
                putch(disc);
            }
            for(i=j - 1; i >= 0 && p[i][k] == disc; i--)
            {
                setCursorPosition(21 + i * 4, 3 + k * 2);
                putch(disc);
            }
            setTextColor(PURE_WHITE);
        }
        return 1;
    }

    //check for diagonal 1
    for(v=j-1, h=k-1; v>=0 && h>=0 && p[v][h]==disc; diago1++,v--,h--);
    for(v=j+1, h=k+1; v<WIDTH && h<HEIGHT && p[v][h]==disc; diago1++, v++, h++);
    if(diago1>=4)
    {
        if(paint)
        {
            setTextColor(LIGHT_RED);
            for(i=j, l = k; i < WIDTH && l < HEIGHT && p[i][l] == disc; i++, l++)
            {
                setCursorPosition(21 + i * 4, 3 + l * 2);
                putch(disc);
            }
            for(i=j - 1, l = k - 1; i >= 0 && j >= 0 && p[i][l] == disc; i--, l--)
            {
                setCursorPosition(21 + i * 4, 3 + l * 2);
                putch(disc);
            }
            setTextColor(PURE_WHITE);
        }
        return 1;
    }

    //check for diagonal 2
    for(v=j-1, h=k+1; v>=0 && h<HEIGHT && p[v][h]==disc; diago2++, v--, h++);
    for(v=j+1, h=k-1; v<WIDTH && h>=0 && p[v][h]==disc; diago2++, v++, h--);
    if(diago2>=4)
    {
        if(paint)
        {
            setTextColor(LIGHT_RED);
            for(i=j, l = k; i >= 0 && l < HEIGHT && p[i][l] == disc; i--, l++)
            {
                setCursorPosition(21 + i * 4, 3 + l * 2);
                putch(disc);
            }
            for(i=j + 1, l = k - 1; i < WIDTH && l >= 0 && p[i][l] == disc; i++, l--)
            {
                setCursorPosition(21 + i * 4, 3 + l * 2);
                putch(disc);
            }
            setTextColor(PURE_WHITE);
        }
        return 1;
    }

    return 0;
    //return winHorizontal(p,j,k) || winVertical(p,j,k) || winDiagDownUp(p,j,k) || winDiagUpDown(p,j,k);
}

int validate(board p, int col)
{
    int valid = 1;
    if ((col<0) || (col>6))
    {
        valid = 0;
    }
    else if(p[col][0] != EMPTY)
        valid = 0;
    return valid;
}

int findLine(board p, int col)
{
	int line = -1, i;
	for(i = HEIGHT - 1; i >= 0 && line < 0; i--)
		if(p[col][i] == EMPTY)
			line = i;
	return line;
}

void playerVsPlayer(Gamer *g1, Gamer *g2, board p)
{
    // This code belongs to the french team, with some modifications
    /*int nb_token = WIDTH * HEIGHT, win;
    while(nb_token!=0)
    {
    	//showBoard(p, *g1);
        win = play(p, g1);
        nb_token--;
        if(win==1)
            break;

    	//showBoard(p, *g2);
        win = play(p, g2);
        nb_token--;
        if(win==1)
            break;

    }
    if(nb_token==0)
        printf("Noob, equality");
    else
    	showBoard(p, *g2); // Show board at the end again*/
    char ch;
    do
    {
        // This code belongs to the italian team, with some modifications
        Gamer *currentGamer;
        int play, i, win = 0, numTurns = 1, validMove, freePos = WIDTH * HEIGHT, firstNum;
        char mark;
        i = random(2);
        currentGamer = (i == 0 ? g1 : g2); // Choose a random player to play first
        firstNum = currentGamer->num;
        do
        {
            // Print some info
            setCursorPosition(19, 17);
            printf("%s (%c), make your move.\t\t", currentGamer->name, (currentGamer->num == 1 ? J1 : J2));
            setCursorPosition(50, 3);
            printf("Turn number %d\t", numTurns);
            setCursorPosition(50, 5);
            printf("%s moves: %d\t", g1->name, g1->moves);
            setCursorPosition(50, 6);
            printf("%s moves: %d\t", g2->name, g2->moves);

            do
            {
                play = getch() - '0' - 1;
                validMove = validate(p, play);
                if(!validMove)
                {
                    setTextColor(LIGHT_RED);
                    setCursorPosition(50, 8);
                    printf("Invalid move");
                }
                else
                {
                    setTextColor(PURE_WHITE);
                    setCursorPosition(50, 8);
                    printf("\t\t");
                }
            }
            while(!validMove);

            i = findLine(p, play);
            mark = (currentGamer->num == 1 ? J1 : J2);
            p[play][i] = mark;

            // Print the char
            setCursorPosition(21 + play * 4, 3 + i * 2);
            putchar(mark);

            win = checkWin(p, play, i, 1);
            currentGamer->moves++; // Increase number of moves
            freePos--;
            if(!win && freePos > 0)
            {
                currentGamer = (currentGamer->num == 1 ? g2 : g1);
                /*setCursorPosition(19, 17);
                printf("Player %d (%c), make your move.", currentGamer->num, (currentGamer->num == 1 ? J1 : J2));*/
                if(currentGamer->num == firstNum)
                    numTurns++;
            }
        }
        while(win == 0 && freePos > 0);
        // Print final info
        setCursorPosition(50, 3);
        printf("Turn number %d\t", numTurns);
        setCursorPosition(50, 5);
        printf("%s moves: %d\t", g1->name, g1->moves);
        setCursorPosition(50, 6);
        printf("%s moves: %d\t", g2->name, g2->moves);

        setCursorPosition(19, 17);
        if(win)
            printf("%s won! Congratulations!\t", currentGamer->name);
        else // The board was filled
            printf("Draw! Noob equality.\t\t");

        // Store data to files

        // Read data
        GamerStat *stats = NULL;
        int numStats = 0;
        /*FILE *file;
        file = fopen("stats.dat", "rb");
        if(file != NULL)
        {
        	fread(&numStats, sizeof(int), 1, file);
        	stats = (GamerStat *) malloc(numStats * sizeof(GamerStat));
        	fread(stats, sizeof(GamerStat), numStats, file);
        	fclose(file);
        }*/
        stats = readStatisticsFile(&numStats);

        GamerStat newStat;
        Gamer otherGamer = (currentGamer->num == 1 ? *g2 : *g1);
        int foundStatP1 = 0, foundStatP2 = 0;
        if(numStats > 0)
        {
            for(i = 0; i < numStats && (!foundStatP1 || !foundStatP2); i++)
            {
                if(stricmp(currentGamer->name, stats[i].name) == 0)
                {
                    stats[i].numGames++;
                    if(freePos > 0)
                    {
                        stats[i].numWins++;
                        stats[i].totalScore += calculateScore(currentGamer->moves);
                    }
                    stats[i].totalNumMoves += currentGamer->moves;
                    foundStatP1 = 1;
                }
                if(stricmp(otherGamer.name, stats[i].name) == 0)
                {
                    stats[i].numGames++;
                    stats[i].totalNumMoves += otherGamer.moves;
                    foundStatP2 = 1;
                }
            }
        }

        if(!foundStatP1)
        {
            newStat.numGames = 1;
            if(freePos > 0)
            {
                newStat.numWins = 1;
                newStat.totalScore = calculateScore(currentGamer->moves);
            }
            else
            {
                newStat.numWins = 0;
                newStat.totalScore = 0;
            }
            newStat.totalNumMoves = currentGamer->moves;
            strcpy(newStat.name, currentGamer->name);
            stats = realloc(stats, sizeof(GamerStat) * (numStats + 1)); // Create a new position in the array
            stats[numStats] = newStat;
            numStats++;
        }
        if(!foundStatP2)
        {
            newStat.numGames = 1;
            newStat.numWins = 0;
            newStat.totalScore = 0;
            newStat.totalNumMoves = otherGamer.moves;
            strcpy(newStat.name, otherGamer.name);
            stats = realloc(stats, sizeof(GamerStat) * (numStats + 1)); // Create a new position in the array
            stats[numStats] = newStat;
            numStats++;
        }

        // Write stats to file
        writeStatisticsFile(stats, numStats);
        free(stats);

        printStringCenter("Press ENTER to play again", 19);
        printStringCenter("or ESC to return to main menu", 20);
        // Wait until ENTER or ESC is pressed
        do
        {
            fflush(stdin);
            ch = getch();
        }
        while(ch != 13 && ch != 27);

        if(ch == 13)
        {
            g1->moves = 0;
            g2->moves = 0;
            initializeGrid(p);
            showBoard(p);
        }
    }
    while(ch != 27);
}

void playerVsComputer(Gamer *g1, Gamer *g2, board p, int difficulty)
{
    Gamer *winner;
    int freeSpaces, i, win, play, validMove, numTurns;
    char ch;
    do
    {
        winner = NULL;
        numTurns = 1;
        freeSpaces = WIDTH * HEIGHT;
        do
        {
            // Print some info
            setCursorPosition(19, 17);
            printf("%s (%c), make your move.", g1->name, (g1->num == 1 ? J1 : J2));
            setCursorPosition(50, 3);
            printf("Turn number %d\t", numTurns);
            setCursorPosition(50, 5);
            printf("%s moves: %d\t", g1->name, g1->moves);
            setCursorPosition(50, 6);
            printf("%s moves: %d\t", g2->name, g2->moves);

            // Player turn
            do
            {
                play = getch() - '0' - 1;
                validMove = validate(p, play);
                if(!validMove)
                {
                    setTextColor(LIGHT_RED);
                    setCursorPosition(50, 8);
                    printf("Invalid move");
                }
                else
                {
                    setTextColor(PURE_WHITE);
                    setCursorPosition(50, 8);
                    printf("\t\t");
                }
            }
            while(!validMove);

            i = findLine(p, play);
            p[play][i] = J1;

            // Print the char
            setCursorPosition(21 + play * 4, 3 + i * 2);
            putchar(J1);

            win = checkWin(p, play, i, 1);
            g1->moves++; // Increase number of moves
            freeSpaces--;

            if(!win) // If player didn't won, the computer will play
            {
                setCursorPosition(50, 10);
                printf("Computer is thinking...\t"); // If the loop takes a lot of time, the player will know the computer is processing
                if (difficulty==1)
                {
                    play = playIA_noob(p);
                }

                if(difficulty==2)
                {
                    play = playIA_normal(p, i, play);
                }

                if(difficulty==3)
                    play = playIA_hardcore(p, numTurns);

                i = findLine(p, play);
                setCursorPosition(21 + play * 4, 3 + i * 2);
                putchar(J2);
                p[play][i] = J2;
                win = checkWin(p, play, i, 1);
                g2->moves++;
                if(win)
                    winner = g2;
                else
                    numTurns++;
                freeSpaces--;
                setCursorPosition(50, 10);
                printf("Computer chose column %d\t", play+1);
            }
            else
                winner = g1;
        }
        while(!win && freeSpaces > 0);
        // Print final info
        setCursorPosition(50, 3);
        printf("Turn number %d\t", numTurns);
        setCursorPosition(50, 5);
        printf("%s moves: %d\t", g1->name, g1->moves);
        setCursorPosition(50, 6);
        printf("%s moves: %d\t", g2->name, g2->moves);

        setCursorPosition(19, 17);
        if(win)
            printf("%s won! %s\t", winner->name, (winner->num == 2 ? "Better luck next time." : "Congratulations!"));
        else // The board was filled
            printf("Draw! Noob equality.\t\t");


        // Read data

        GamerStat *stats = NULL;
        int numStats = 0;
        stats = readStatisticsFile(&numStats);

        GamerStat newStat;
        int foundStatP1 = 0;
        if(numStats > 0)
        {
            for(i = 0; i < numStats && !foundStatP1; i++)
            {
                if(stricmp(g1->name, stats[i].name) == 0)
                {
                    stats[i].numGames++;
                    if(winner->num == g1->num && freeSpaces > 0)
                    {
                        stats[i].numWins++;
                        stats[i].totalScore += calculateScore(g1->moves);
                    }
                    stats[i].totalNumMoves += g1->moves;
                    foundStatP1 = 1;
                }
            }
        }

        if(!foundStatP1)
        {
            newStat.numGames = 1;
            if(winner->num == g1->num && freeSpaces > 0)
            {
                newStat.numWins = 1;
                newStat.totalScore = calculateScore(g1->moves);
            }
            else
            {
                newStat.numWins = 0;
                newStat.totalScore = 0;
            }
            newStat.totalNumMoves = g1->moves;
            strcpy(newStat.name, g1->name);
            stats = realloc(stats, sizeof(GamerStat) * (numStats + 1)); // Create a new position in the array
            stats[numStats] = newStat;
            numStats++;
        }

        writeStatisticsFile(stats, numStats);
        free(stats);

        printStringCenter("Press ENTER to play again", 19);
        printStringCenter("or ESC to return to main menu", 20);
        // Wait until ENTER or ESC is pressed
        do
        {
            fflush(stdin);
            ch = getch();
        }
        while(ch != 13 && ch != 27);

        if(ch == 13)
        {
            g1->moves = 0;
            g2->moves = 0;
            initializeGrid(p);
            showBoard(p);
        }
    }
    while(ch != 27);
}
