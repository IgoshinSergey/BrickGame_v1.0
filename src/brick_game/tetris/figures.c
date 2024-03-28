#include "inc/figures.h"

Figure_t *randomFigure(void) {
  Figure_t *figure = (Figure_t *)calloc(1, sizeof(Figure_t));
  srand(time(NULL));
  int id = 1 + rand() % 7;
  figure->length = getLength(id);
  figure->coordinates = getFigure(id, figure->length);
  figure->x = 5 - figure->length / 2;
  figure->y = -figure->length;
  return figure;
}

void freeFigure(Figure_t *figure) {
  freeMatrix(figure->coordinates, figure->length);
  free(figure);
}

bool moveLeft(AllInfo_t *info) {
  bool res = true;
  Figure_t *figure = info->current;
  figure->x -= 1;
  if (isCollision(*info)) {
    figure->x += 1;
    res = false;
  }
  return res;
}

bool moveRight(AllInfo_t *info) {
  bool res = true;
  Figure_t *figure = info->current;
  figure->x += 1;
  if (isCollision(*info)) {
    figure->x -= 1;
    res = false;
  }
  return res;
}

bool moveDown(AllInfo_t *info) {
  bool res = true;
  Figure_t *figure = info->current;
  figure->y += 1;
  if (isCollision(*info)) {
    figure->y -= 1;
    res = false;
  }
  return res;
}

void rotation(AllInfo_t *info) {
  Figure_t *figure = info->current;
  int len = figure->length;
  int **cur_m = figure->coordinates;
  int **new_m = initMatrix(len, len);
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      new_m[j][len - i - 1] = cur_m[i][j];
    }
  }
  figure->coordinates = new_m;
  if (isCollision(*info)) {
    figure->coordinates = cur_m;
    freeMatrix(new_m, len);
  } else {
    freeMatrix(cur_m, len);
  }
}

void connectionFigure(AllInfo_t *info) {
  int **field = info->field;
  Figure_t *figure = info->current;
  int x = figure->x;
  int y = figure->y;

  for (int i = 0; i < figure->length; i++) {
    for (int j = 0; j < figure->length; j++) {
      if (figure->coordinates[i][j]) {
        field[y + i][x + j] = 1;
      }
    }
  }
}

void spawnFigure(AllInfo_t *info) {
  if (info->current != NULL) {
    freeFigure(info->current);
  }
  if (info->next == NULL) {
    info->next = randomFigure();
  }
  info->current = info->next;
  info->next = randomFigure();
}

int getLength(int id) {
  int length = 3;
  if (id == 1) {
    length = 5;
  } else if (id == 2) {
    length = 2;
  }
  return length;
}

int **getFigure(int id, int length) {
  int **figure = initMatrix(length, length);
  switch (id) {
    case 1:
      for (int j = 1; j < length; j++) figure[1][j] = 1;
      break;
    case 2:
      for (int i = 0; i < length; i++)
        for (int j = 0; j < length; j++) figure[i][j] = 1;
      break;
    case 3:
      for (int j = 0; j < length; j++) figure[1][j] = 1;
      figure[0][0] = 1;
      break;
    case 4:
      for (int j = 0; j < length; j++) figure[1][j] = 1;
      figure[0][2] = 1;
      break;
    case 5:
      for (int j = 0; j < length - 1; j++) {
        figure[0][j + 1] = 1;
        figure[1][j] = 1;
      }
      break;
    case 6:
      for (int j = 0; j < length - 1; j++) {
        figure[0][j] = 1;
        figure[1][j + 1] = 1;
      }
      break;
    case 7:
      for (int j = 0; j < length; j++) figure[1][j] = 1;
      figure[0][1] = 1;
      break;
  }
  return figure;
}

int **initMatrix(int rows, int cols) {
  int **matrix = (int **)calloc(rows, sizeof(int *));
  if (matrix) {
    for (int i = 0; i < rows; i++) {
      matrix[i] = (int *)calloc(cols, sizeof(int));
      if (!matrix[i]) exit(1);
    }
  } else {
    exit(1);
  }
  return matrix;
}

void freeMatrix(int **matrix, int rows) {
  for (int i = 0; i < rows; i++) free(matrix[i]);
  free(matrix);
}
