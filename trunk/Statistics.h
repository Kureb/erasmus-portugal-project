#ifndef STATISTICS_H
#define STATISTICS_H

#include "Global.h"

void showStatistics();

void showHighScores(int numStats, GamerStat *stats);
void showGameStatistics(int numStats, GamerStat *stats);
void showPlayersList(int numStats, GamerStat *stats);
void showPlayerData(GamerStat playerState);


#endif // STATISTICS_H
