#ifndef C7_BRICKGAME_V_1_0_OBJECTS_H_
#define C7_BRICKGAME_V_1_0_OBJECTS_H_

#include <stdbool.h>
#include <sys/time.h>

typedef enum State_t {
  StartGame,
  Spawn,
  Moving,
  Shifting,
  Attaching,
  End
} State_t;

typedef enum UserAction_t {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

typedef struct Figure_t {
  int **coordinates;
  int length;
  int x, y;
} Figure_t;

typedef struct PlayerInfo_t {
  int score;
  int high_score;
  int level;
  int speed;
  bool pause;
  bool start;
} PlayerInfo_t;

typedef struct AllInfo_t {
  int **field;
  Figure_t *current;
  Figure_t *next;
  PlayerInfo_t player;
  struct timeval last_drop_time;
  int tacts;
} AllInfo_t;

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

#endif  // C7_BRICKGAME_V_1_0_FSM_H_
