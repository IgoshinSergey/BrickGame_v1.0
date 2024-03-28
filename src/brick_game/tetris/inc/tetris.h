#ifndef C7_BRICKGAME_V_1_0_TETRIS_H_
#define C7_BRICKGAME_V_1_0_TETRIS_H_

#include <stdio.h>
#include <unistd.h>

#include "figures.h"
#include "fsm.h"
#include "objects.h"

State_t *getState(void);
AllInfo_t *getAllInfo(void);
GameInfo_t *getGameInfo(void);

void initAllInfo(void);
void destroyGame(void);

GameInfo_t makeGameInfo(AllInfo_t *info);
void updateAllInfo(AllInfo_t *info);

bool isEndGame(AllInfo_t *info);
bool isCollision(AllInfo_t info);

void setHighScore(int high_score);
int getHighScore(void);
int getPoints(int **field);
int calculatePoints(int count);
void eraseLine(int **field, int row);
bool checkLine(int **field, int row);

#endif  // C7_BRICKGAME_V_1_0_TETRIS_H_
