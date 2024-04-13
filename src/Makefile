CC=gcc -std=c11
CFLAGS=-c -Wall -Wextra -Werror
TEST_FLAGS = -lcheck -g

OS := $(shell uname -s)
ifeq ($(OS), Linux)
    D_ENV=__LINUX__
    TEST_FLAGS += -lrt -lpthread -lsubunit -lm
    OPEN_GCOV= xdg-open coverage/src/index.html
else
    D_ENV=__MAC_OS__
    OPEN_GCOV= open coverage/index.html
endif

TARGET = math

C_FILES = math.c other.c
O_FILES = math.o other.o

all: clean $(TARGET).a test gcov_report

math.a:
	@$(CC) $(CFLAGS) $(C_FILES) -D$(D_ENV)
	@ar rc lib$(TARGET).a $(O_FILES)
	@ranlib lib$@
	@cp lib$(TARGET).a $(TARGET).a
	@rm *.o

clean:
	@rm -rf *.out *.o *.gch  log.txt logTest.txt
	@rm -rf coverage *.a *.gcda *gcno *.info Test *.cfg
	@rm -rf report/
	@rm -rf temp/
	@rm -rf Test.dSYM/
	@rm -rf a.out.dSYM/
	@rm -rf test.c

test:
	@checkmk clean_mode=1 test.check > test.c
	@clang-format -i --style=Google test.c
	@$(CC) $(C_FILES) test.c $(TEST_FLAGS) -D$(D_ENV) -o Test
	@./Test

gcov_report:
	@checkmk clean_mode=1 test.check > test.c
	@clang-format -i --style=Google test.c
	@$(CC) $(C_FILES) test.c $(TEST_FLAGS) -D$(D_ENV) --coverage
	@./a.out
	@lcov -c -d . -o coverage.info
	@genhtml coverage.info -o coverage
	@$(OPEN_GCOV)
