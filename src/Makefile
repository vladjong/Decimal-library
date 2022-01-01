CFLAGS= -Wall -Wextra -Werror
GCOV=-fprofile-arcs -ftest-coverage

all: s21_decimal.a test

s21_decimal.a: s21_decimal.o
	ar rcs s21_decimal.a s21_decimal.o
	ranlib $@
	cp $@ lib$@
	ranlib lib$@

s21_decimal.o: s21_decimal.c
	gcc -c -o s21_decimal.o s21_decimal.c

test: s21_decimal.a
	gcc -c test.c   -o test.o
	gcc test.o s21_decimal.a  -lcheck -o test1.o
	./test1.o

clean:
	rm -rf ./*.o ./*.a ./a.out ./*.gcno ./*.gcda ./report *.info ./*.info report ./Test

check:
	cppcheck *.h *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	CK_FORK=no leaks --atExit -- ./Test

gcov_report: s21_decimal.a
	@gcc $(GCOV) test.c  -lcheck s21_decimal.c -o Test
	@./Test
	@lcov -t "Test" -o Test.info -c -d .
	@genhtml -o report Test.info 
	open ./report/index-sort-f.html
	
rebuild: clean all