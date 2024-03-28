#ifndef C7_BRICKGAME_V_1_0_FSM_H_
#define C7_BRICKGAME_V_1_0_FSM_H_

#include "objects.h"

GameInfo_t updateCurrentState(void);
void userInput(UserAction_t action, bool hold);

#endif  // C7_BRICKGAME_V_1_0_FSM_H_
