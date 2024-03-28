PROJECT_NAME=BrickGame_v1.0
CC=gcc
GCOV=--coverage
NCURSES=-lncurses
FRONTEND=gui/cli
BACKEND=brick_game/tetris
TEST_DIR=unit_tests
CFLAGS=-Wall -Werror -Wextra -std=c11
OS=$(shell uname -s)

ifeq ($(OS), Linux)
	LEAK_CHECK=valgrind --tool=memcheck --leak-check=yes
	OPEN_CMD=xdg-open
	ADD_LIB=-lpthread -lcheck_pic -lrt -lm -lsubunit
else ifeq ($(OS), Darwin)
	LEAK_CHECK=leaks -atExit --
	OPEN_CMD=open
	ADD_LIB=-lm -lcheck -lpthread
endif

all: install unistall dvi dist test gcov_report clean

install: clean
	mkdir build
	cd build && $(CC) $(CFLAGS) ../$(BACKEND)/*.c ../$(FRONTEND)/*.c $(NCURSES) -o $(PROJECT_NAME) 
	./build/$(PROJECT_NAME)

unistall:
	rm -rf build

dvi: clean
	cd dvi && latex about.tex
	cd dvi && rm -rf about.log about.aux
	cd dvi && dvipdf about.dvi

dist: clean
	mkdir $(PROJECT_NAME)
	cp -r brick_game $(PROJECT_NAME)
	cp -r dvi $(PROJECT_NAME)
	cp -r gui $(PROJECT_NAME)
	cp Makefile $(PROJECT_NAME)
	tar -cvzf $(PROJECT_NAME).tgz $(PROJECT_NAME)
	rm -rf $(PROJECT_NAME)

test: clean
	$(CC) $(CFLAGS) $(BACKEND)/*.c $(TEST_DIR)/*.c -o tests $(ADD_LIB)
	./tests

gcov_report: clean
	$(CC) $(CFLAGS) $(BACKEND)/*.c $(TEST_DIR)/*.c -o gcov_tests $(ADD_LIB) $(GCOV)
	./gcov_tests
	lcov -c -d . -o gcov_tests.info
	genhtml -o report gcov_tests.info
	chmod 777 report/*
	rm *.gcda *.gcno
	$(OPEN_CMD) ./report/index.html

leaks: clean test
	$(LEAK_CHECK) ./tests

clang:
	cp ../materials/linters/.clang-format .
	clang-format -n \
	$(BACKEND)/*.c \
	$(BACKEND)/inc/*.h \
	$(FRONTEND)/*.* \
	unit_tests/*.*
	rm -rf .clang-format

clean:
	rm -rf \
	*.o \
	build/ high_score.txt \
	report/ \
	dvi/*.aux dvi/*.log dvi/about.pdf dvi/*.dvi \
	$(PROJECT_NAME) $(PROJECT_NAME).tgz \
	gcov_tests gcov_tests.info tests
