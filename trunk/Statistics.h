#ifndef STATISTICS_H
#define STATISTICS_H

#include "Global.h"

#define MAX_HIGH 5

void showStatistics();

GamerStat* readStatisticsFile(int *numStats);
void writeStatisticsFile(GamerStat *stats, int numStats);

// Computes a score based on the number of moves required to win
int calculateScore(int moves);

void showHighScores(int numStats, GamerStat *stats);
void showGameStatistics(int numStats, GamerStat *stats);
void showPlayersList(int numStats, GamerStat *stats);
void showPlayerData(GamerStat playerState);


#endif // STATISTICS_H
