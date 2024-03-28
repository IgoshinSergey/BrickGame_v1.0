#include "brick_game_test.h"

START_TEST(states_normal_test_1) {
  initAllInfo();
  getState();

  userInput(Start, 0);
  updateCurrentState();
  ck_assert_int_eq(*getState(), Spawn);

  updateCurrentState();
  ck_assert_int_eq(*getState(), Moving);

  while (*getState() != Shifting) {
    updateCurrentState();
  }
  ck_assert_int_eq(*getState(), Shifting);

  updateCurrentState();
  userInput(Down, 0);
  userInput(Down, 1);
  ck_assert_int_eq(*getState(), Moving);

  while (*getState() != Shifting) {
    updateCurrentState();
  }
  ck_assert_int_eq(*getState(), Shifting);

  updateCurrentState();
  ck_assert_int_eq(*getState(), Attaching);

  userInput(-1, 0);
  userInput(Terminate, 0);
}

START_TEST(states_normal_test_2) {
  initAllInfo();
  *getState() = StartGame;

  userInput(Start, 0);
  updateCurrentState();
  ck_assert_int_eq(*getState(), Spawn);

  updateCurrentState();
  ck_assert_int_eq(*getState(), Moving);

  for (int i = 0; i < 10; i++) {
    userInput(Left, 0);
  }
  for (int i = 0; i < 10; i++) {
    userInput(Action, 0);
  }
  for (int i = 0; i < 10; i++) {
    userInput(Right, 0);
  }
  for (int i = 0; i < 10; i++) {
    userInput(Up, 0);
  }
  userInput(Down, 1);
  ck_assert_int_eq(*getState(), Moving);

  while (*getState() != Shifting) {
    updateCurrentState();
  }
  ck_assert_int_eq(*getState(), Shifting);

  updateCurrentState();
  ck_assert_int_eq(*getState(), Attaching);

  updateCurrentState();
  ck_assert_int_eq(*getState(), Spawn);

  userInput(Terminate, 0);
}

START_TEST(states_normal_test_3) {
  initAllInfo();
  AllInfo_t* info = getAllInfo();
  if (info->current) freeFigure(info->current);
  if (info->next) freeFigure(info->next);
  info->current = idFigure(1);
  info->next = idFigure(1);
  *getState() = Moving;
  updateCurrentState();

  userInput(Pause, 0);
  GameInfo_t game = updateCurrentState();
  ck_assert_int_eq(game.pause, true);

  userInput(Pause, 0);
  game = updateCurrentState();
  ck_assert_int_eq(game.pause, false);

  for (int i = 0; i < 10; i++) {
    userInput(Left, 0);
  }
  userInput(Action, 0);
  for (int i = 0; i < 10; i++) {
    userInput(Right, 0);
  }
  userInput(Action, 0);
  for (int i = 0; i < 10; i++) {
    userInput(Up, 0);
  }
  userInput(Action, 0);
  userInput(Down, 1);
  ck_assert_int_eq(*getState(), Moving);
}

START_TEST(states_normal_test_4) {
  initAllInfo();
  AllInfo_t* info = getAllInfo();
  if (info->current) freeFigure(info->current);
  if (info->next) freeFigure(info->next);
  info->current = idFigure(2);
  info->next = idFigure(2);
  *getState() = Moving;
  updateCurrentState();

  userInput(Pause, 0);
  GameInfo_t game = updateCurrentState();
  ck_assert_int_eq(game.pause, true);

  userInput(Pause, 0);
  game = updateCurrentState();
  ck_assert_int_eq(game.pause, false);

  for (int i = 0; i < 10; i++) {
    userInput(Left, 0);
  }
  userInput(Action, 0);
  for (int i = 0; i < 10; i++) {
    userInput(Right, 0);
  }
  userInput(Action, 0);
  for (int i = 0; i < 10; i++) {
    userInput(Up, 0);
  }
  userInput(Action, 0);
  userInput(Down, 1);
  ck_assert_int_eq(*getState(), Moving);
}

START_TEST(states_normal_test_5) {
  initAllInfo();
  AllInfo_t* info = getAllInfo();
  if (info->current) freeFigure(info->current);
  if (info->next) freeFigure(info->next);
  info->current = idFigure(3);
  info->next = idFigure(3);
  *getState() = Moving;
  updateCurrentState();

  userInput(Pause, 0);
  GameInfo_t game = updateCurrentState();
  ck_assert_int_eq(game.pause, true);

  userInput(Pause, 0);
  game = updateCurrentState();
  ck_assert_int_eq(game.pause, false);

  for (int i = 0; i < 10; i++) {
    userInput(Left, 0);
  }
  userInput(Action, 0);
  for (int i = 0; i < 10; i++) {
    userInput(Right, 0);
  }
  userInput(Action, 0);
  for (int i = 0; i < 10; i++) {
    userInput(Up, 0);
  }
  userInput(Action, 0);
  userInput(Down, 1);
  ck_assert_int_eq(*getState(), Moving);
}

START_TEST(states_normal_test_6) {
  initAllInfo();
  AllInfo_t* info = getAllInfo();
  if (info->current) freeFigure(info->current);
  if (info->next) freeFigure(info->next);
  info->current = idFigure(4);
  info->next = idFigure(4);
  *getState() = Moving;
  updateCurrentState();

  userInput(Pause, 0);
  GameInfo_t game = updateCurrentState();
  ck_assert_int_eq(game.pause, true);

  userInput(Pause, 0);
  game = updateCurrentState();
  ck_assert_int_eq(game.pause, false);

  for (int i = 0; i < 10; i++) {
    userInput(Left, 0);
  }
  userInput(Action, 0);
  for (int i = 0; i < 10; i++) {
    userInput(Right, 0);
  }
  userInput(Action, 0);
  for (int i = 0; i < 10; i++) {
    userInput(Up, 0);
  }
  userInput(Action, 0);
  userInput(Down, 1);
  ck_assert_int_eq(*getState(), Moving);
}

START_TEST(states_normal_test_7) {
  initAllInfo();
  AllInfo_t* info = getAllInfo();
  if (info->current) freeFigure(info->current);
  if (info->next) freeFigure(info->next);
  info->current = idFigure(5);
  info->next = idFigure(5);
  *getState() = Moving;
  updateCurrentState();

  userInput(Pause, 0);
  GameInfo_t game = updateCurrentState();
  ck_assert_int_eq(game.pause, true);

  userInput(Pause, 0);
  game = updateCurrentState();
  ck_assert_int_eq(game.pause, false);

  for (int i = 0; i < 10; i++) {
    userInput(Left, 0);
  }
  userInput(Action, 0);
  for (int i = 0; i < 10; i++) {
    userInput(Right, 0);
  }
  userInput(Action, 0);
  for (int i = 0; i < 10; i++) {
    userInput(Up, 0);
  }
  userInput(Action, 0);
  userInput(Down, 1);
  ck_assert_int_eq(*getState(), Moving);
}

START_TEST(states_normal_test_8) {
  initAllInfo();
  AllInfo_t* info = getAllInfo();
  if (info->current) freeFigure(info->current);
  if (info->next) freeFigure(info->next);
  info->current = idFigure(6);
  info->next = idFigure(6);
  *getState() = Moving;
  updateCurrentState();

  userInput(Pause, 0);
  GameInfo_t game = updateCurrentState();
  ck_assert_int_eq(game.pause, true);

  userInput(Pause, 0);
  game = updateCurrentState();
  ck_assert_int_eq(game.pause, false);

  for (int i = 0; i < 10; i++) {
    userInput(Left, 0);
  }
  userInput(Action, 0);
  for (int i = 0; i < 10; i++) {
    userInput(Right, 0);
  }
  userInput(Action, 0);
  for (int i = 0; i < 10; i++) {
    userInput(Up, 0);
  }
  userInput(Action, 0);
  userInput(Down, 1);
  ck_assert_int_eq(*getState(), Moving);
}

START_TEST(states_normal_test_9) {
  initAllInfo();
  AllInfo_t* info = getAllInfo();
  if (info->current) freeFigure(info->current);
  if (info->next) freeFigure(info->next);
  info->current = idFigure(7);
  info->next = idFigure(7);
  *getState() = Moving;
  updateCurrentState();

  userInput(Pause, 0);
  GameInfo_t game = updateCurrentState();
  ck_assert_int_eq(game.pause, true);

  userInput(Pause, 0);
  game = updateCurrentState();
  ck_assert_int_eq(game.pause, false);

  for (int i = 0; i < 10; i++) {
    userInput(Left, 0);
  }
  userInput(Action, 0);
  for (int i = 0; i < 10; i++) {
    userInput(Right, 0);
  }
  userInput(Action, 0);
  for (int i = 0; i < 10; i++) {
    userInput(Up, 0);
  }
  userInput(Action, 0);
  userInput(Down, 1);
  ck_assert_int_eq(*getState(), Moving);
}

START_TEST(states_normal_test_10) {
  initAllInfo();
  AllInfo_t* info = getAllInfo();
  if (info->current) freeFigure(info->current);
  if (info->next) freeFigure(info->next);
  info->current = idFigure(1);
  info->next = idFigure(1);
  info->player.start = true;

  for (int j = 0; j < 9; j++) {
    info->field[1][j] = 1;
  }
  *getState() = Moving;

  userInput(Down, 1);
  *getState() = Attaching;

  updateCurrentState();
  ck_assert_int_eq(*getState(), StartGame);
}

Suite* suite_states(void) {
  Suite* suite = suite_create("\033[30;43m STATE_TESTS \033[0m");
  TCase* tc = tcase_create("tcase_states");

  tcase_add_test(tc, states_normal_test_1);
  tcase_add_test(tc, states_normal_test_2);
  tcase_add_test(tc, states_normal_test_3);
  tcase_add_test(tc, states_normal_test_4);
  tcase_add_test(tc, states_normal_test_5);
  tcase_add_test(tc, states_normal_test_6);
  tcase_add_test(tc, states_normal_test_7);
  tcase_add_test(tc, states_normal_test_8);
  tcase_add_test(tc, states_normal_test_9);
  tcase_add_test(tc, states_normal_test_10);

  suite_add_tcase(suite, tc);

  return suite;
}

START_TEST(info_normal_test_1) {
  initAllInfo();
  AllInfo_t* info = getAllInfo();
  if (info->current) freeFigure(info->current);
  if (info->next) freeFigure(info->next);
  info->current = idFigure(1);
  info->next = idFigure(1);
  info->player.start = true;

  for (int j = 0; j < 10; j++) {
    info->field[19][j] = 1;
  }
  *getState() = Moving;
  userInput(Down, 1);
  ck_assert_int_eq(*getState(), Moving);

  *getState() = Attaching;
  ck_assert_int_eq(*getState(), Attaching);

  updateCurrentState();
  ck_assert_int_eq(*getState(), Spawn);

  ck_assert_int_eq(info->player.score, 100);
  ck_assert_int_eq(info->player.high_score, 100);
}

START_TEST(info_normal_test_2) {
  initAllInfo();
  AllInfo_t* info = getAllInfo();
  if (info->current) freeFigure(info->current);
  if (info->next) freeFigure(info->next);
  info->current = idFigure(1);
  info->next = idFigure(1);
  info->player.start = true;
  *getState() = Moving;

  for (int j = 0; j < 10; j++) {
    info->field[19][j] = 1;
    info->field[18][j] = 1;
  }
  userInput(Down, 1);
  updateCurrentState();
  *getState() = Attaching;
  ck_assert_int_eq(*getState(), Attaching);

  updateCurrentState();
  ck_assert_int_eq(*getState(), Spawn);

  ck_assert_int_eq(info->player.score, 300);
  ck_assert_int_eq(info->player.high_score, 300);
}

START_TEST(info_normal_test_3) {
  initAllInfo();
  AllInfo_t* info = getAllInfo();
  if (info->current) freeFigure(info->current);
  if (info->next) freeFigure(info->next);
  info->current = idFigure(1);
  info->next = idFigure(1);
  info->player.start = true;
  *getState() = Moving;

  for (int j = 0; j < 10; j++) {
    info->field[19][j] = 1;
    info->field[18][j] = 1;
    info->field[17][j] = 1;
  }
  userInput(Down, 1);
  updateCurrentState();
  *getState() = Attaching;
  ck_assert_int_eq(*getState(), Attaching);

  updateCurrentState();
  ck_assert_int_eq(*getState(), Spawn);

  ck_assert_int_eq(info->player.score, 700);
  ck_assert_int_eq(info->player.high_score, 700);
  ck_assert_int_eq(info->player.level, 1);
}

START_TEST(info_normal_test_4) {
  initAllInfo();
  AllInfo_t* info = getAllInfo();
  if (info->current) freeFigure(info->current);
  if (info->next) freeFigure(info->next);
  info->current = idFigure(1);
  info->next = idFigure(1);
  info->player.start = true;
  *getState() = Moving;

  for (int j = 0; j < 10; j++) {
    info->field[19][j] = 1;
    info->field[18][j] = 1;
    info->field[17][j] = 1;
    info->field[16][j] = 1;
  }
  userInput(Down, 1);
  updateCurrentState();
  *getState() = Attaching;
  ck_assert_int_eq(*getState(), Attaching);

  updateCurrentState();
  ck_assert_int_eq(*getState(), Spawn);

  ck_assert_int_eq(info->player.score, 1500);
  ck_assert_int_eq(info->player.high_score, 1500);
  ck_assert_int_eq(info->player.level, 2);

  destroyGame();
}

Suite* suite_info(void) {
  Suite* suite = suite_create("\033[30;43m INFO_TESTS \033[0m");
  TCase* tc = tcase_create("tcase_info");

  tcase_add_test(tc, info_normal_test_1);
  tcase_add_test(tc, info_normal_test_2);
  tcase_add_test(tc, info_normal_test_3);
  tcase_add_test(tc, info_normal_test_4);

  suite_add_tcase(suite, tc);

  return suite;
}
