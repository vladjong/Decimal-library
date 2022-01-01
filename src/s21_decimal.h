#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdio.h>

typedef enum {
  S21_NORMAL_VALUE = 0,
  S21_INFINITY = 1,
  S21_NEGATIVE_INFINITY = 2,
  S21_NAN = 3
} value_type_t;

typedef struct {
  int bits[4];
  value_type_t value_type;
} s21_decimal;

typedef union {
  unsigned int integerValue;
  float floatValue;
} value;


//  функции для работы с побитовыми операциями
int check_bit(s21_decimal dst, int position);
void set_bit(s21_decimal *dst, int position);
void remove_bit(s21_decimal *dst, int position);
int check_bit_number(unsigned int number, int position);
int set_bit_number(unsigned int number, int position);
int shift_bit(s21_decimal *dst, int position, int side);
// иницилизация структуры
void initialization_struct(s21_decimal *dst);
// функции конвекторы
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
// арифметические операции
s21_decimal s21_add(s21_decimal decimalOne, s21_decimal decimalTwo);
s21_decimal s21_sub(s21_decimal decimalOne, s21_decimal decimalTwo);
s21_decimal s21_div(s21_decimal decimalOne, s21_decimal decimalTwo);
s21_decimal s21_mod(s21_decimal decimalOne, s21_decimal decimalTwo);
s21_decimal s21_mul(s21_decimal decimalOne, s21_decimal decimalTwo);
// операции сравнения
int s21_is_less(s21_decimal decimalOne, s21_decimal decimalTwo);
int s21_is_less_or_equal(s21_decimal decimalOne, s21_decimal decimalTwo);
int s21_is_equal(s21_decimal decimalOne, s21_decimal decimalTwo);
int s21_is_greater(s21_decimal decimalOne, s21_decimal decimalTwo);
int s21_is_greater_or_equal(s21_decimal decimalOne, s21_decimal decimalTwo);
int s21_is_not_equal(s21_decimal decimalOne, s21_decimal decimalTwo);
// дополнительные функции

// возведение двойки в степень
double s21_pow(int degree);
// перевод степени показателя в число (использовать с set accuracy)
int accarucy_bit_to_accuracy_decimal(s21_decimal src);
// перевод decimal в дополнительный код
void transform_additional_code(s21_decimal *dst);
// алгоритм сложения decimal
int algoritm_add_decimal(s21_decimal *decimalOne, s21_decimal *decimalTwo,
                         s21_decimal *decimalResult);
// алгоритм вычитания decimal
void algoritm_sub_decimal(s21_decimal *decimalOne, s21_decimal *decimalTwo,
                          s21_decimal *decimalResult);
//  алгоритм умножения
void algoritm_multiply_decimal(s21_decimal *decimalOne, s21_decimal *decimalTwo,
                               s21_decimal *decimalResult);
// алгоритм деления
void algoritm_div_decimal(s21_decimal *dividend, s21_decimal *divisor,
                          s21_decimal *quotient, s21_decimal *mod);
// выставляет знак в bits[3] при переводе float в decimal
void set_sign_and_accuracy(float src, s21_decimal *dst, int accuracy);
// вычисление порядка при переводе float в decimal
int get_accuracy(float src);
// поставить порядок 10 в decimal
void set_accuracy(s21_decimal *dst, int accuracy);
// приведение decimal к одной степени
void convert_to_like_accuracy(s21_decimal *decimalOne, s21_decimal *decimalTwo);
// переписывание decimal
void rewriteDecimal(s21_decimal *dst, s21_decimal *decimalTemp);
// проверка знака для операций
int checkBitsSign(s21_decimal *decimalOne, s21_decimal *decimalTwo,
                  int *decision, int *signNegative, int operation);
// проверка числа float на nan/+-inf
void check_value_number_float(float src, s21_decimal *decimal);
// проверка значения числа в операции сложения/вычитания
int check_value_add(s21_decimal decimalOne, s21_decimal decimalTwo,
                    s21_decimal *decimalResult, int operation);
// операция сравенение чисел бесконечностей и тд
int comparisonValue(s21_decimal decimalOne, s21_decimal decimalTwo, int equal,
                    int *result);
// проверка умножения
int check_multiply(s21_decimal decimalOne, s21_decimal decimalTwo,
                   s21_decimal *decimalResult);
// целочисленное деление
void div_int_number(s21_decimal *dividend, s21_decimal *divisor,
                    s21_decimal *quotient, s21_decimal *mod);
// деление нецелых чисел
void div_float_number(s21_decimal *mod, s21_decimal *divisor,
                      s21_decimal *quotient);
// умножение на -1
s21_decimal s21_negate(s21_decimal decimal);
// выводит целую часть числа
s21_decimal s21_truncate(s21_decimal decimal);
// округление числа
s21_decimal s21_round(s21_decimal decimal);

// проверка на знаки для доп функций
int check_decimal_negate(s21_decimal decimal, s21_decimal *decimalTemp);
// округление в сторону минус infinity
s21_decimal s21_floor(s21_decimal decimal);

#endif  // SRC_S21_DECIMAL_H_
