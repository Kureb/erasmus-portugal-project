#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "Global.h"
#include "Statistics.h"
#include "utilities.h"

void showStatistics()
{
    GamerStat *stats = NULL;
    int option, numStats = 0, i;
    char player[PLAYERNAME];

    system("cls");
    stats = readStatisticsFile(stats, &numStats);
    if(stats == NULL)
    {
        printf("Error opening file. Press ENTER to return.");
        do
        {
            fflush(stdin);
        }
        while(getch() != 13);
    }
    else
    {
        if(numStats <= 0)
        {
            printf("There are no statistics yet. Press ENTER to return.");
            do
            {
                fflush(stdin);
            }
            while(getch() != 13);
        }
        else
        {
            do
            {
                system("cls");
                printStringCenter("Global Statistics", 1);
                printStringCenter("Please choose an option", 4);
                printStringCenter("1 - Check High-Scores", 6);
                printStringCenter("2 - Check Game Statistics", 7);
                printStringCenter("3 - Check player list", 8);
                printStringCenter("4 - Search Data About Player", 9);
                printStringCenter("0 - Return", 10);
                do
                {
                    option = getch() - '0';
                }
                while(option < 0 || option > 4);

                switch(option)
                {
                case 1:
                    showHighScores(numStats, stats);
                    break;
                case 2:
                    showGameStatistics(numStats, stats);
                    break;
				case 3:
					showPlayersList(numStats, stats);
					break;
				case 4:
					do
					{
						system("cls");
						printf("Enter the name of the player: ");
						fgets(player, PLAYERNAME, stdin);
						chomp(player);
					} while(strcmp(player, "") == 0);
					for(i = 0; i < numStats; i++)
					{
						if(stricmp(stats[i].name, player) == 0)
							break;
					}
					if(i == numStats)
					{
						system("cls");
						printf("There is no player with such name. Press ENTER to return.");
						do
						{
							fflush(stdin);
						}
						while(getch() != 13);
					}
					else
						showPlayerData(stats[i]);
                }
            }
            while(option != 0);
        }
    }
    free(stats);

}

void writeStatisticsFile(GamerStat *stats, int numStats)
{
	FILE *file;
	file = fopen("stats.dat", "wb");
	if(file != NULL)
	{
		fwrite(&numStats, sizeof(int), 1, file);
		fwrite(stats, sizeof(GamerStat), numStats, file);
		fclose(file);
	}
}

GamerStat* readStatisticsFile(GamerStat *stats, int *numStats)
{
	FILE *file;
	file = fopen("stats.dat", "rb");
	if(file != NULL)
	{
		fread(numStats, sizeof(int), 1, file);
		stats = (GamerStat *) malloc((*numStats) * sizeof(GamerStat));
		fread(stats, sizeof(GamerStat), *numStats, file);
		fclose(file);
	}
	return stats;
}

void showHighScores(int numStats, GamerStat *stats)
{
    system("cls");
    printStringCenter("High-Scores", 3);
    GamerStat bestStats[5];
    int numBestStats = (numStats > 5 ? 5 : numStats), i, j, k;

    for(i = 0; i < 5; i++)
    {
        bestStats[i].totalScore = -1;
    }
    for(i = 0; i < numStats; i++)
    {
        if(stats[i].totalScore > bestStats[4].totalScore) // If the stat being checked is better than the last, we will find its position
        {
            for(j = 0; j < 5; j++)
            {
                if(stats[i].totalScore > bestStats[j].totalScore)
                {
                    for(k = j; k < 4; k++)
                    {
                        bestStats[k + 1] = bestStats[k]; // Move all positions by one
                    }
                    bestStats[j] = stats[i]; // Add the new stat
                    break;
                }
            }
        }
    }
    for(i = 0; i < numBestStats; i++)
    {
        setCursorPosition(25, 6 + i);
        printf("%d%s\t%s - %d", i + 1, (i == 0 ? "st" : (i == 1 ? "nd" : (i == 2 ? "rd" : "th"))), bestStats[i].name, bestStats[i].totalScore);
    }
    printStringCenter("Press ENTER to return", 8 + i);
    do
    {
        fflush(stdin);
    }
    while(getch() != 13);
}

void showGameStatistics(int numStats, GamerStat *stats)
{
    int totalNumMoves = 0, totalGamesPlayed = 0, totalNumWins = 0, i;
    float averageMovesPerPlayer = 0, averageWinsPerPlayer = 0;
    for(i = 0; i < numStats; i++)
    {
        totalNumMoves += stats[i].totalNumMoves;
        totalGamesPlayed += stats[i].numGames;
        totalNumWins += stats[i].numWins;
    }
    if(totalNumMoves > 0)
    {
        averageMovesPerPlayer = (float) (totalNumMoves / numStats);
    }
    if(totalNumWins > 0)
	{
		averageWinsPerPlayer = (float) (totalNumWins / numStats);
	}
    system("cls");
    printStringCenter("Global Game Statistics", 3);
    setCursorPosition(20, 6);
    printf("Total number of games played: %d", totalGamesPlayed);
    setCursorPosition(20, 7);
    printf("Total number of moves made by players: %d", totalNumMoves);
    if(totalNumMoves > 0)
    {
        setCursorPosition(20, 8);
        printf("Average number of moves per player: %.1f", averageMovesPerPlayer);
    }
    if(totalNumWins > 0)
	{
		setCursorPosition(20, 10);
        printf("Average number of games won per player: %.1f", averageWinsPerPlayer);
	}


    printStringCenter("Press ENTER to return", 13);
    do
    {
        fflush(stdin);
    }
    while(getch() != 13);
}

void showPlayersList(int numStats, GamerStat *stats)
{
	int i;

	system("cls");
	printStringCenter("Players List", 3);
	for(i = 0; i < numStats; i++)
	{
		printStringCenter(stats[i].name, i + 6);
	}
	printStringCenter("Press ENTER to return", numStats + 7);
	do
    {
        fflush(stdin);
    }
    while(getch() != 13);
}

void showPlayerData(GamerStat playerStat)
{
	system("cls");
	printStringCenter("Player Data", 3);
	setCursorPosition(20, 6);
	printf("Player name: %s", playerStat.name);
	setCursorPosition(20, 7);
	printf("Total number of games played: %d", playerStat.numGames);
	setCursorPosition(20, 8);
	printf("Total number of games won: %d", playerStat.numWins);
	setCursorPosition(20, 9);
	printf("Total score: %d", playerStat.totalScore);
	setCursorPosition(20, 10);
	printf("Total number of moves made: %d", playerStat.totalNumMoves);
	if(playerStat.numGames > 0)
	{
		setCursorPosition(20, 11);
		printf("Percentage of games won: %.1f", (float) playerStat.numWins / (float) playerStat.numGames * 100.0);
		setCursorPosition(20, 12);
		printf("Average moves per game: %.1f", (float) playerStat.totalNumMoves / (float) playerStat.numGames);
	}
	printStringCenter("Press ENTER to return", 14);
    do
    {
        fflush(stdin);
    }
    while(getch() != 13);
}
