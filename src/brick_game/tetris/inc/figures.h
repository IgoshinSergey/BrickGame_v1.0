#ifndef C7_BRICKGAME_V_1_0_FIGURES_H_
#define C7_BRICKGAME_V_1_0_FIGURES_H_

#include <stdlib.h>
#include <time.h>

#include "objects.h"
#include "tetris.h"

Figure_t *randomFigure(void);
void freeFigure(Figure_t *figure);
int getLength(int id);
int **getFigure(int id, int length);

bool moveLeft(AllInfo_t *info);
bool moveRight(AllInfo_t *info);
bool moveDown(AllInfo_t *info);
void rotation(AllInfo_t *info);

void connectionFigure(AllInfo_t *info);
void spawnFigure(AllInfo_t *info);

int **initMatrix(int rows, int cols);
void freeMatrix(int **matrix, int length);

#endif  // C7_BRICKGAME_V_1_0_FIGURES_H_
