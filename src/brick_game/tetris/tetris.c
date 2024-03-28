#include "inc/tetris.h"

State_t *getState(void) {
  static State_t state = 0;
  return &state;
}

AllInfo_t *getAllInfo(void) {
  static AllInfo_t all_info = {NULL, NULL, NULL, {0}, {0}, 0};
  return &all_info;
}

GameInfo_t *getGameInfo(void) {
  static GameInfo_t game_info = {NULL, NULL, 0, 0, 0, 0, 0};
  return &game_info;
}

GameInfo_t makeGameInfo(AllInfo_t *info) {
  GameInfo_t *display = getGameInfo();
  State_t *state = getState();
  if (display->field != NULL) freeMatrix(display->field, 20);
  display->field = initMatrix(20, 10);
  int **disp = display->field;
  int **g = info->field;
  Figure_t *figure = info->current;
  if (figure && *state != StartGame && *state != Spawn) {
    int **f = figure->coordinates;
    int x_f = figure->x;
    int y_f = figure->y;
    for (int i = 0; i < 20; i++) {
      int len_f = figure->length;
      for (int j = 0; j < 10; j++) {
        bool flag = 0;
        if (i >= y_f && j >= x_f && (i - y_f < len_f) && (j - x_f < len_f)) {
          if (f[i - y_f][j - x_f]) {
            flag = 1;
          } else {
            flag = (g[i][j]) ? 1 : 0;
          }
        } else {
          flag = (g[i][j]) ? 1 : 0;
        }
        if (flag) {
          disp[i][j] = 1;
        }
      }
    }
  } else if (g) {
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 10; j++) {
        if (g[i][j]) {
          disp[i][j] = 1;
        }
      }
    }
  }
  if (info->next)
    display->next = info->next->coordinates;
  else
    display->next = NULL;
  display->field = disp;
  display->high_score = info->player.high_score;
  display->level = info->player.level;
  display->pause = info->player.pause;
  display->score = info->player.score;
  display->speed = info->player.speed;
  return *display;
}

int getHighScore(void) {
  int high_score = 0;
  FILE *f = fopen("./high_score.txt", "r");
  if (f != NULL) {
    fscanf(f, "%d", &high_score);
    fclose(f);
  }
  return high_score;
}

void setHighScore(int high_score) {
  FILE *f = fopen("./high_score.txt", "w");
  if (f != NULL) {
    fprintf(f, "%d", high_score);
    fclose(f);
  }
}

int getPoints(int **field) {
  int num_row = 19;
  int count_full_lines = 0;
  while (num_row > 0) {
    if (checkLine(field, num_row)) {
      eraseLine(field, num_row);
      count_full_lines++;
    } else {
      num_row--;
    }
  }
  int points = calculatePoints(count_full_lines);
  return points;
}

int calculatePoints(int count) {
  int points = 0;
  switch (count) {
    case 1:
      points = 100;
      break;
    case 2:
      points = 300;
      break;
    case 3:
      points = 700;
      break;
    case 4:
      points = 1500;
      break;
    default:
      break;
  }
  return points;
}

bool isEndGame(AllInfo_t *info) {
  bool res = false;
  Figure_t *cur = info->current;
  int **coordinates = cur->coordinates;
  int len = cur->length;
  int y = cur->y;
  if (y <= 0) {
    for (int i = 0; i < len; i++) {
      if (coordinates[-y][i]) {
        res = true;
        break;
      }
    }
  }
  return res;
}

void eraseLine(int **field, int row) {
  for (int i = row; i > 0; i--) {
    for (int j = 0; j < 10; j++) {
      field[i][j] = field[i - 1][j];
    }
  }
}

bool checkLine(int **field, int row) {
  bool flag = true;
  for (int j = 0; j < 10; j++) {
    if (!field[row][j]) {
      flag = false;
      break;
    }
  }
  return flag;
}

void initAllInfo(void) {
  AllInfo_t *info = getAllInfo();
  if (info->field) freeMatrix(info->field, 20);
  info->field = initMatrix(20, 10);
  gettimeofday(&info->last_drop_time, NULL);
  info->player.high_score = getHighScore();
  info->player.level = 0;
  info->player.pause = 0;
  info->player.score = 0;
  info->player.start = 0;
  info->player.speed = 900000 - 60000 * info->player.level;
}

void updateAllInfo(AllInfo_t *info) {
  info->player.score += getPoints(info->field);
  if (info->player.high_score < info->player.score) {
    info->player.high_score = info->player.score;
  }
  if (info->player.level < 10) {
    info->player.level = info->player.score / 600;
    if (info->player.level > 10) {
      info->player.level = 10;
    }
  }
  info->player.speed = 900000 - 60000 * info->player.level;
}

void destroyGame(void) {
  AllInfo_t *info = getAllInfo();
  GameInfo_t *display = getGameInfo();
  if (display->field) freeMatrix(display->field, 20);
  if (info->field) freeMatrix(info->field, 20);
  if (info->current) freeFigure(info->current);
  if (info->next) freeFigure(info->next);
}

bool isCollision(AllInfo_t info) {
  int **field = info.field;
  int **figure = info.current->coordinates;
  int x = info.current->x;
  int y = info.current->y;
  int len = info.current->length;
  bool flag = false;
  for (int i = 0; i < len && !flag; i++) {
    for (int j = 0; j < len && !flag; j++) {
      int val_figure = figure[i][j];
      if (y + i >= 0) {
        if (x + j >= 0 && x + j < 10 && y + i < 20) {
          int val_field = field[i + y][j + x];
          flag = (val_field == 1 && val_figure == 1) ? true : false;
        } else {
          flag = (val_figure == 1) ? true : false;
        }
      } else if (x + j < 0 || x + j >= 10) {
        flag = true;
      }
    }
  }
  return flag;
}
