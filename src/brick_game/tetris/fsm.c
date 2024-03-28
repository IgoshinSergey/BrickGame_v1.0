#include "inc/tetris.h"

GameInfo_t updateCurrentState(void) {
  AllInfo_t *info = getAllInfo();
  State_t *state = getState();
  if (!info->player.pause && info->player.start) {
    switch (*state) {
      case StartGame:
        *state = Spawn;
        break;
      case Spawn:
        spawnFigure(info);
        *state = Moving;
        break;
      case Moving:
        struct timeval cur_time = {0};
        gettimeofday(&cur_time, NULL);
        long diff_sec = cur_time.tv_sec - info->last_drop_time.tv_sec;
        long diff_msec = cur_time.tv_usec - info->last_drop_time.tv_usec;
        long diff = diff_sec * 1000000 + diff_msec;
        if (diff >= info->player.speed) {
          gettimeofday(&info->last_drop_time, NULL);
          *state = Shifting;
        }
        break;
      case Shifting:
        bool res = moveDown(info);
        if (res == false) {
          *state = Attaching;
        } else {
          *state = Moving;
        }
        break;
      case Attaching:
        if (isEndGame(info)) {
          initAllInfo();
          *state = StartGame;
        } else {
          connectionFigure(info);
          updateAllInfo(info);
          *state = Spawn;
        }
        break;
      default:
        break;
    }
  }
  GameInfo_t display = makeGameInfo(info);
  return display;
}

void userInput(UserAction_t action, bool hold) {
  AllInfo_t *info = getAllInfo();
  State_t *state = getState();
  bool pause = info->player.pause;
  if (!hold) {
    switch (action) {
      case Start:
        if (*state == StartGame) info->player.start = 1;
        break;
      case Pause:
        if (*state != StartGame) info->player.pause = !info->player.pause;
        break;
      case Terminate:
        setHighScore(info->player.high_score);
        *state = End;
        break;
      case Left:
        if (*state == Moving && !pause) moveLeft(info);
        break;
      case Right:
        if (*state == Moving && !pause) moveRight(info);
        break;
      case Up:
        break;
      case Down:
        break;
      case Action:
        if (*state == Moving && !pause) rotation(info);
        break;
      default:
        break;
    }
  } else {
    if (*state == Moving && !pause) {
      while (moveDown(info)) {
        moveDown(info);
      }
    }
  }
}
