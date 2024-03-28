#ifndef C7_BRICKGAME_V_1_0_BRICK_GAME_H_
#define C7_BRICKGAME_V_1_0_BRICK_GAME_H_

#include <check.h>

#include "../brick_game/tetris/inc/tetris.h"

Figure_t *idFigure(int id);

Suite *suite_states(void);
Suite *suite_info(void);

#endif  // C7_BRICKGAME_V_1_0_BRICK_GAME_H_
