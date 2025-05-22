CC := gcc
FLAGS := -Wall -Werror -Wextra
CCFLAGS := $(FLAGS) -std=c11

OS := $(shell uname -s)
ifeq ($(OS), Darwin)
	LIBS = -lcheck -lm -lpthread
  OPEN := open
else ifeq ($(OS), Linux)
	LIBS = -lcheck -lm -lsubunit -lpthread -lrt
  OPEN := google-chrome
endif

HEADERS := s21_matrix.h tests/matrix_test.h
PROJ_SRC := *.c
TESTS_SRC := tests/*.c

COVERAGE_FLAGS := -fprofile-arcs -ftest-coverage

all: s21_matrix.a

s21_matrix.a:
	@$(CC) $(CCFLAGS) $(PROJ_SRC) -c
	@ar rcs $@ *.o
	@ranlib $@
	@rm *.o

test:
	$(CC) $(CCFLAGS) -o $@ $(PROJ_SRC) $(TESTS_SRC) $(LIBS)
	./$@

debug_test:
	$(CC) $(CCFLAGS) -g -o debug $(PROJ_SRC) $(TESTS_SRC) $(LIBS)

clean_debug:
	rm debug

valgrind: test
	CK_FORK=no valgrind -s  --track-origins=yes --tool=memcheck --leak-check=full \
	--show-leak-kinds=all --log-file=RESULT_VALGRIND.txt ./$<
	rm $<

miniverter:
	cd ../materials/build && sh run.sh
	# sh ../materials/build/run.sh

gcov_report:
	$(CC) $(CCFLAGS) $(COVERAGE_FLAGS) -o tests_coverage $(PROJ_SRC) $(TESTS_SRC) $(LIBS)
	./tests_coverage
	lcov -t "s21_decimal_tests" -o coverage.info --no-external -c -d .
	genhtml -o report coverage.info
	rm -f *.info *.gcda *.gcno
	rm -f tests_coverage
	$(OPEN) report/index.html

clang_format:
	@clang-format --style=file:"../materials/linters/.clang-format" -i $(PROJ_SRC) $(TESTS_SRC) $(HEADERS)

clang_check:
	@clang-format --style=file:"../materials/linters/.clang-format" -n $(PROJ_SRC) $(TESTS_SRC) $(HEADERS)

clean:
	@rm -rf report
	@rm s21_matrix.a test RESULT_VALGRIND.txt
