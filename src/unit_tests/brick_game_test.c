#include "brick_game_test.h"

Figure_t *idFigure(int id) {
  Figure_t *figure = (Figure_t *)calloc(1, sizeof(Figure_t));
  srand(time(NULL));
  figure->length = getLength(id);
  figure->coordinates = getFigure(id, figure->length);
  figure->x = 5 - figure->length / 2;
  figure->y = -figure->length;
  return figure;
}

void run_testcase(Suite *testcase) {
  printf("\n");
  SRunner *suite_runner = srunner_create(testcase);
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  srunner_free(suite_runner);
}

void run_tests(void) {
  printf("\n\033[30;43m -=BRICK_GAME_TESTS=- \033[0m\n");
  Suite *case_list[] = {suite_states(), suite_info(), NULL};
  for (Suite **cur_test_case = case_list; *cur_test_case != NULL;
       cur_test_case++) {
    run_testcase(*cur_test_case);
  }
}

int main() {
  run_tests();
  return 0;
}
