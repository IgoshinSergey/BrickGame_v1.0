#ifndef C7_BRICKGAME_V_1_0_FRONTEND_H_
#define C7_BRICKGAME_V_1_0_FRONTEND_H_

#include <ncurses.h>

#include "../../brick_game/tetris/inc/tetris.h"

void game_tetris(void);
UserAction_t getAction(int user_input);
void showGame(WINDOW *field, WINDOW *player, GameInfo_t game);

#endif  // C7_BRICKGAME_V_1_0_FRONTEND_H_
