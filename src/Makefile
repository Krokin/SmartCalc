CC=gcc
CFLAGS= -Wall -Wextra -Werror -pedantic -std=c11
FLAGS_TEST_LIBS = -lcheck -lm -lpthread
#
SRC=Smart_Calc.c			Deposit_Calc.c\
	Credit_Calc.c\


HEADER=Smart_Calc.h
NAME=Smart_Calc.a
OBJ=$(patsubst %.c, %.o, $(SRC))
OS = $(shell uname)

.PHONY: all build static install uninstall rebuild dist test gcov_report clean m

all: build static tests

build:
	$(CC) $(CFLAGS) -c $(SRC)

static:
	ar rc Smart_Calc.a $(OBJ)
	ranlib Smart_Calc.a

tests:
	$(CC) $(CFLAGS) -lcheck  test.c Smart_Calc.a -o test
	./test

gcov_report: all
	$(CC) $(CFLAGS) --coverage test.c $(SRC) $(NAME) $(FLAGS_TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html


install:
	make clean
	mkdir build
	cd CalcQT && qmake && make && make clean && rm Makefile && cd ../ && mv CalcQT/Calculator.app build

uninstall:
	rm -rf build*

dvi:
	open readme.txt



dist:
	rm -rf Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/src
	mv ./build/Calculator.app Archive_SmartCalc_v1.0/src/
	tar cvzf Archive_SmartCalc_v1.0.tgz Archive_SmartCalc_v1.0/
	rm -rf Archive_SmartCalc_v1.0/

clean:
	rm -rf *.{a,o,dSYM,out}
	rm -rf $(EXECUTABLE)
	rm -rf gcov_report
	rm -rf report
	rm -rf CPPLINT.cfg
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf Archive_SmartCalc_v1.0 
	rm -rf *tgz
	rm -rf build
	rm -rf gcov_test

rebuild: clean all

check:
	cp ../materials/linters/CPPLINT.cfg .
	python3 ../materials/linters/cpplint.py --extensions=c *.c
	python3 ../materials/linters/cpplint.py --extensions=c *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	leaks --atExit -- test

m: build static
	@ $(CC) m.c $(NAME)
	@./a.out
