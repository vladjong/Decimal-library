#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

#include "s21_decimal.h"

START_TEST(convert_less_to_decimal) {
  s21_decimal dst1;
  s21_decimal dst2;
  int result = 0;

  s21_from_float_to_decimal(123.2124, &dst1);
  s21_from_float_to_decimal(123.2, &dst2);
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(123.2, &dst1);
  s21_from_float_to_decimal(123.2124, &dst2);
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(-123.2124, &dst1);
  s21_from_float_to_decimal(-123.2, &dst2);
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(-123.2, &dst1);
  s21_from_float_to_decimal(123.2124, &dst2);
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst2.value_type = 1;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst2.value_type = 2;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;
}
END_TEST

START_TEST(decimal_less_or_equal_to_decimal) {
  s21_decimal dst1;
  s21_decimal dst2;
  int result = 0;

  s21_from_float_to_decimal(123.2124, &dst1);
  s21_from_float_to_decimal(123.2, &dst2);
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(123.2, &dst1);
  s21_from_float_to_decimal(123.2124, &dst2);
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(-123.2124, &dst1);
  s21_from_float_to_decimal(-123.2, &dst2);
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(-123.2, &dst1);
  s21_from_float_to_decimal(123.2124, &dst2);
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst2.value_type = 1;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst2.value_type = 2;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;
}
END_TEST

START_TEST(decimal_greater_to_decimal) {
  s21_decimal dst1;
  s21_decimal dst2;
  int result = 0;

  s21_from_float_to_decimal(123.2124, &dst1);
  s21_from_float_to_decimal(123.2, &dst2);
  result = s21_is_greater(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(123.2, &dst1);
  s21_from_float_to_decimal(123.2124, &dst2);
  result = s21_is_greater(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(-123.2124, &dst1);
  s21_from_float_to_decimal(-123.2, &dst2);
  result = s21_is_greater(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(-123.2, &dst1);
  s21_from_float_to_decimal(123.2124, &dst2);
  result = s21_is_greater(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  result = s21_is_greater(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  result = s21_is_greater(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst2.value_type = 1;
  result = s21_is_greater(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  result = s21_is_greater(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst2.value_type = 2;
  result = s21_is_greater(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;
}
END_TEST

START_TEST(decimal_greater_or_equal_to_decimal) {
  s21_decimal dst1;
  s21_decimal dst2;
  int result = 0;

  s21_from_float_to_decimal(123.2124, &dst1);
  s21_from_float_to_decimal(123.2, &dst2);
  result = s21_is_greater_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(123.2, &dst1);
  s21_from_float_to_decimal(123.2124, &dst2);
  result = s21_is_greater_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(-123.2124, &dst1);
  s21_from_float_to_decimal(-123.2, &dst2);
  result = s21_is_greater_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(-123.2, &dst1);
  s21_from_float_to_decimal(123.2124, &dst2);
  result = s21_is_greater_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  result = s21_is_greater_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  result = s21_is_greater_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst2.value_type = 1;
  result = s21_is_greater_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  result = s21_is_greater_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst2.value_type = 2;
  result = s21_is_greater_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;
}
END_TEST

START_TEST(decimal_equal) {
  s21_decimal dst1;
  s21_decimal dst2;
  int result = 0;

  s21_from_float_to_decimal(123.2124, &dst1);
  s21_from_float_to_decimal(123.2, &dst2);
  result = s21_is_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(123.2, &dst1);
  s21_from_float_to_decimal(123.2124, &dst2);
  result = s21_is_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(-123.2124, &dst1);
  s21_from_float_to_decimal(-123.2, &dst2);
  result = s21_is_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(-123.2, &dst1);
  s21_from_float_to_decimal(123.2124, &dst2);
  result = s21_is_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  result = s21_is_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  result = s21_is_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst2.value_type = 1;
  result = s21_is_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  result = s21_is_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst2.value_type = 2;
  result = s21_is_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;
}
END_TEST

START_TEST(convert_int_to_decimal) {
  int testBits[4];
  for (int i = 0; i < 4; i++) testBits[i] = 0;
  s21_decimal dst;

  s21_from_int_to_decimal(0, &dst);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(dst.bits[i], testBits[i]);
  for (int i = 0; i < 4; i++) testBits[i] = 0;
  initialization_struct(&dst);

  s21_from_int_to_decimal(INT_MAX, &dst);
  testBits[0] = INT_MAX;
  for (int i = 0; i < 4; i++) ck_assert_int_eq(dst.bits[i], testBits[i]);
  for (int i = 0; i < 4; i++) testBits[i] = 0;
  initialization_struct(&dst);

  s21_from_int_to_decimal(INT_MIN, &dst);
  int sign = 0;
  char str[] = {"10000000000000000000000000000000"};
  char strTest[95] = "";
  for (int i = 0; i <= 32; i++) {
    if (check_bit(dst, i))
      strTest[31 - i] = '1';
    else
      strTest[31 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  initialization_struct(&dst);
}
END_TEST

START_TEST(convert_float_to_decimal) {
  int testBits[4];
  for (int i = 0; i < 4; i++) testBits[i] = 0;
  s21_decimal dst;

  s21_from_float_to_decimal(0.0, &dst);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(dst.bits[i], testBits[i]);
  for (int i = 0; i < 4; i++) testBits[i] = 0;
  initialization_struct(&dst);

  s21_from_float_to_decimal(0.001234, &dst);
  int sign = 0;
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000000000000000010011010010"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  initialization_struct(&dst);

  s21_from_float_to_decimal(-0.001234, &dst);
  sign = 0;
  char strTest1[100] = "";
  char str1[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000000000000000010011010010"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst, i))
      strTest1[95 - i] = '1';
    else
      strTest1[95 - i] = '0';
  }
  ck_assert_str_eq(strTest1, str1);
  if (check_bit(dst, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  initialization_struct(&dst);

  int check = 0;
  check = s21_from_float_to_decimal(8E28, &dst);
  ck_assert_int_eq(check, 1);
  initialization_struct(&dst);

  s21_from_float_to_decimal(INFINITY, &dst);
  ck_assert_int_eq(dst.value_type, 1);
  initialization_struct(&dst);

  s21_from_float_to_decimal(NAN, &dst);
  ck_assert_int_eq(dst.value_type, 3);
  initialization_struct(&dst);
}
END_TEST

START_TEST(less_to_decimal) {
  s21_decimal dst1;
  s21_decimal dst2;
  int result = 0;

  s21_from_float_to_decimal(123.2124, &dst1);
  s21_from_float_to_decimal(123.2, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.00002, &dst1);
  s21_from_float_to_decimal(0.00122, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(12312.2, &dst1);
  s21_from_float_to_decimal(12312.2, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(12312.2, &dst1);
  s21_from_float_to_decimal(12312.19, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(12312.2, &dst1);
  s21_from_float_to_decimal(12312.21, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 0;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  dst2.value_type = 0;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 3;
  dst2.value_type = 0;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 2;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  dst2.value_type = 1;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  dst2.value_type = 2;
  result = s21_is_less(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;
}
END_TEST

START_TEST(less_eq_to_decimal) {
  s21_decimal dst1;
  s21_decimal dst2;
  int result = 0;

  s21_from_float_to_decimal(123.2124, &dst1);
  s21_from_float_to_decimal(123.2, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.00002, &dst1);
  s21_from_float_to_decimal(0.00122, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(12312.2, &dst1);
  s21_from_float_to_decimal(12312.2, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(12312.2, &dst1);
  s21_from_float_to_decimal(12312.19, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(12312.2, &dst1);
  s21_from_float_to_decimal(12312.21, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 0;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  dst2.value_type = 0;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 3;
  dst2.value_type = 0;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 2;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  dst2.value_type = 1;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 1;
  result = s21_is_less_or_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;
}
END_TEST

START_TEST(eq_to_decimal) {
  s21_decimal dst1;
  s21_decimal dst2;
  int result = 0, sign = 0;

  s21_from_float_to_decimal(123.2124, &dst1);
  s21_from_float_to_decimal(123.2, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(1E8, &dst1);
  s21_from_float_to_decimal(1E8, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(-124.12, &dst1);
  s21_from_float_to_decimal(-124.12, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_equal(dst1, dst2);
  ck_assert_int_eq(result, 0);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(124.12, &dst1);
  s21_from_float_to_decimal(-124.12, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  result = s21_is_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 0;
  result = s21_is_equal(dst1, dst2);
  ck_assert_int_eq(result, 1);
  initialization_struct(&dst1);
  initialization_struct(&dst2);
  result = 0;
}
END_TEST

START_TEST(add_decimal_1) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_add(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(add_decimal_2) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(12.3132, &dst1);
  s21_from_float_to_decimal(32.23, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_add(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000000001101100101111111000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(add_decimal_3) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-12.3132, &dst1);
  s21_from_float_to_decimal(-32.23, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_add(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000000001101100101111111000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(add_decimal_4) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-1.23132, &dst1);
  s21_from_float_to_decimal(32.23, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_add(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000001011110100110011011100"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(add_decimal_5) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-65331.32, &dst1);
  s21_from_float_to_decimal(322.23, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_add(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000110000011"
      "011110111111111111000110"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(add_decimal_6) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 1;
  dst3 = s21_add(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 1);
}
END_TEST

START_TEST(add_decimal_7) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  dst2.value_type = 2;
  dst3 = s21_add(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 2);
}
END_TEST

START_TEST(add_decimal_8) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  dst2.value_type = 0;
  dst3 = s21_add(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 2);
}
END_TEST

START_TEST(add_decimal_9) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 0;
  dst3 = s21_add(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 1);
}
END_TEST

START_TEST(add_decimal_10) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 1;
  dst3 = s21_add(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 1);
}
END_TEST

START_TEST(add_decimal_11) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 2;
  dst3 = s21_add(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 2);
}
END_TEST

START_TEST(add_decimal_12) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 2;
  dst3 = s21_add(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(add_decimal_13) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  dst2.value_type = 1;
  dst3 = s21_add(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(add_decimal_14) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(53634643.12, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 3;
  dst3 = s21_add(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(add_decimal_15) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(1E12, &dst1);
  s21_from_float_to_decimal(2E15, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_add(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000111000110111110011000011100"
      "101001010000000000000000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(add_decimal_16) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0;
  s21_from_float_to_decimal(7E28, &dst1);
  s21_from_float_to_decimal(7E28, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_add(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 1);
}
END_TEST

START_TEST(sub_decimal_1) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_sub(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(sub_decimal_2) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(431.123, &dst1);
  s21_from_float_to_decimal(42.23, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_sub(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000000001011110111100011101"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(sub_decimal_3) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(12321.213, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_sub(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "101111000000000110111101"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(sub_decimal_4) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(123.123, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 0;
  dst3 = s21_sub(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 1);
}
END_TEST

START_TEST(sub_decimal_5) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(123.123, &dst2);
  dst1.value_type = 2;
  dst2.value_type = 0;
  dst3 = s21_sub(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 2);
}
END_TEST

START_TEST(sub_decimal_6) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 1;
  dst3 = s21_sub(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 2);
}
END_TEST

START_TEST(sub_decimal_7) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 2;
  dst3 = s21_sub(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 1);
}
END_TEST

START_TEST(sub_decimal_8) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 1;
  dst3 = s21_sub(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(sub_decimal_9) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  dst2.value_type = 2;
  dst3 = s21_sub(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(sub_decimal_10) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 3;
  dst2.value_type = 2;
  dst3 = s21_sub(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(sub_decimal_11) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(3E24, &dst1);
  s21_from_float_to_decimal(4E20, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_sub(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000001001111011001100001010010011100010100000000000000000000000"
      "000000000000000000000000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(sub_decimal_12) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0;
  s21_from_float_to_decimal(-7E28, &dst1);
  s21_from_float_to_decimal(-7E28, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_sub(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(mul_decimal_1) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_mul(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(mul_decimal_2) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(25E25, &dst1);
  s21_from_float_to_decimal(123123213213.1231, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_mul(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 1);
}
END_TEST

START_TEST(mul_decimal_3) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(1234.2, &dst1);
  s21_from_float_to_decimal(0.00023, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_mul(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000010101001001100101000001110100000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(mul_decimal_4) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(5E12, &dst1);
  s21_from_float_to_decimal(-12.2, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_mul(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000010101101010111110101011100110111000000000000000000000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(mul_decimal_5) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-45312.1221, &dst1);
  s21_from_float_to_decimal(12.222, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_mul(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000001000000011110001010101011001000100010000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(mul_decimal_6) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-0.00023, &dst1);
  s21_from_float_to_decimal(-0.0189, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_mul(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000000000001010100111001110"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(mul_decimal_19) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 0;
  dst3 = s21_mul(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(mul_decimal_7) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 1;
  dst3 = s21_mul(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(mul_decimal_8) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 2;
  dst3 = s21_mul(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(mul_decimal_16) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  dst2.value_type = 0;
  dst3 = s21_mul(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(mul_decimal_17) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 1;
  dst3 = s21_mul(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 1);
}
END_TEST

START_TEST(mul_decimal_9) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  dst2.value_type = 2;
  dst3 = s21_mul(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 2);
}
END_TEST

START_TEST(mul_decimal_10) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 2;
  dst2.value_type = 1;
  dst3 = s21_mul(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 2);
}
END_TEST

START_TEST(mul_decimal_11) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 2;
  dst3 = s21_mul(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 2);
}
END_TEST

START_TEST(mul_decimal_18) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(123.213, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 2;
  dst3 = s21_mul(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 2);
}
END_TEST

START_TEST(mul_decimal_12) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(123.21, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 0;
  dst3 = s21_mul(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 1);
}
END_TEST

START_TEST(mul_decimal_13) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(123.21, &dst2);
  dst1.value_type = 2;
  dst2.value_type = 0;
  dst3 = s21_mul(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 2);
}
END_TEST

START_TEST(mul_decimal_14) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(123.213, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 1;
  dst3 = s21_mul(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 1);
}
END_TEST

START_TEST(mul_decimal_15) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 3;
  dst2.value_type = 3;
  dst3 = s21_mul(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(mod_decimal_1) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_mod(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(mod_decimal_2) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(124.123, &dst1);
  s21_from_float_to_decimal(12.213, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_mod(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000000000000000011111001001"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(mod_decimal_3) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(1232.12, &dst1);
  s21_from_float_to_decimal(-24.12, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_mod(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011001000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(mod_decimal_4) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-7E12, &dst1);
  s21_from_float_to_decimal(3E10, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_mod(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000001001010100"
      "000001001101000000000000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(mod_decimal_5) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(7E5, &dst1);
  s21_from_float_to_decimal(10E10, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_mod(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000000010101010111001100000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(mod_decimal_6) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(12312.12, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_mod(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(mod_decimal_7) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 1;
  dst3 = s21_mod(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(mod_decimal_8) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 2;
  dst3 = s21_mod(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(mod_decimal_9) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 1;
  dst2.value_type = 0;
  dst3 = s21_mod(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(mod_decimal_10) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 1;
  dst3 = s21_mod(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(div_decimal_1) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_div(dst1, dst2);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(div_decimal_2) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(124.123, &dst1);
  s21_from_float_to_decimal(12.213, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_div(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "100110110001001111110011"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(div_decimal_3) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(1232.12, &dst1);
  s21_from_float_to_decimal(-24.12, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_div(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000011"
      "000010110111011010100111"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(div_decimal_4) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-100000, &dst1);
  s21_from_float_to_decimal(0.2345678, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_div(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000110001101000010"
      "011010011000001101010111"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(div_decimal_5) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(2.0, &dst1);
  s21_from_float_to_decimal(5.0, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_div(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000001100001101010000000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 0;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(div_decimal_6) {
  s21_decimal dst1;
  s21_decimal dst2;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(12312.12, &dst2);
  dst1.value_type = 0;
  dst2.value_type = 0;
  dst3 = s21_div(dst1, dst2);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 0;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(truncate_1) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  dst1.value_type = 0;
  dst3 = s21_truncate(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 0;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(truncate_2) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(124.123213, &dst1);
  dst1.value_type = 0;
  dst3 = s21_truncate(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000001111100"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 0;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(truncate_3) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(4345.8, &dst1);
  dst1.value_type = 0;
  dst3 = s21_truncate(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000001000011111001"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 0;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(truncate_4) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-123.23, &dst1);
  dst1.value_type = 0;
  dst3 = s21_truncate(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000001111011"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(truncate_5) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  dst1.value_type = 1;
  dst3 = s21_truncate(dst1);
  ck_assert_int_eq(dst3.value_type, 1);
}
END_TEST

START_TEST(truncate_6) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  dst1.value_type = 2;
  dst3 = s21_truncate(dst1);
  ck_assert_int_eq(dst3.value_type, 2);
}
END_TEST

START_TEST(truncate_7) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  dst1.value_type = 3;
  dst3 = s21_truncate(dst1);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(negate_1) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-123.23, &dst1);
  dst1.value_type = 0;
  dst3 = s21_negate(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000000000000011000000100011"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(negate_2) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(123.23, &dst1);
  dst1.value_type = 0;
  dst3 = s21_negate(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000000000000011000000100011"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(negate_3) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-0.000012, &dst1);
  dst1.value_type = 0;
  dst3 = s21_negate(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001100"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 0;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(negate_4) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  dst1.value_type = 1;
  dst3 = s21_truncate(dst1);
  ck_assert_int_eq(dst3.value_type, 1);
}
END_TEST

START_TEST(negate_5) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  dst1.value_type = 2;
  dst3 = s21_truncate(dst1);
  ck_assert_int_eq(dst3.value_type, 2);
}
END_TEST

START_TEST(negate_6) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  dst1.value_type = 3;
  dst3 = s21_truncate(dst1);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(round_1) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  dst1.value_type = 0;
  dst3 = s21_round(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 0;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(round_2) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(1243.49, &dst1);
  dst1.value_type = 0;
  dst3 = s21_round(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000010011011011"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 0;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(round_3) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(31.5, &dst1);
  dst1.value_type = 0;
  dst3 = s21_round(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000100000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 0;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(round_4) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(234325.75, &dst1);
  dst1.value_type = 0;
  dst3 = s21_round(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000111001001101010110"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 0;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(round_5) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-2.653, &dst1);
  dst1.value_type = 0;
  dst3 = s21_round(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000011"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(round_6) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-123.49, &dst1);
  dst1.value_type = 0;
  dst3 = s21_round(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000001111011"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(round_7) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-190.5, &dst1);
  dst1.value_type = 0;
  dst3 = s21_round(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000010111111"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(floor_1) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  dst1.value_type = 0;
  dst3 = s21_floor(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(floor_2) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(1243.49, &dst1);
  dst1.value_type = 0;
  dst3 = s21_floor(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000010011011011"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 0;
  ck_assert_int_eq(sign, 0);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(floor_3) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-2.653, &dst1);
  dst1.value_type = 0;
  dst3 = s21_floor(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000011"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(floor_4) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-123.49, &dst1);
  dst1.value_type = 0;
  dst3 = s21_floor(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000001111100"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(floor_5) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(-1901232.5, &dst1);
  dst1.value_type = 0;
  dst3 = s21_floor(dst1);
  char strTest[100] = "";
  char str[] = {
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000111010000001010110001"};
  for (int i = 0; i <= 95; i++) {
    if (check_bit(dst3, i))
      strTest[95 - i] = '1';
    else
      strTest[95 - i] = '0';
  }
  ck_assert_str_eq(strTest, str);
  if (check_bit(dst3, 127)) sign = 1;
  ck_assert_int_eq(sign, 1);
  ck_assert_int_eq(dst3.value_type, 0);
}
END_TEST

START_TEST(floor_6) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  dst1.value_type = 1;
  dst3 = s21_floor(dst1);
  ck_assert_int_eq(dst3.value_type, 1);
}
END_TEST

START_TEST(floor_7) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  dst1.value_type = 2;
  dst3 = s21_floor(dst1);
  ck_assert_int_eq(dst3.value_type, 2);
}
END_TEST

START_TEST(floor_8) {
  s21_decimal dst1;
  s21_decimal dst3;
  int result = 0, sign = 0;
  s21_from_float_to_decimal(0.0, &dst1);
  dst1.value_type = 3;
  dst3 = s21_floor(dst1);
  ck_assert_int_eq(dst3.value_type, 3);
}
END_TEST

START_TEST(convert_decimal_to_float_1) {
  s21_decimal dst1;
  int result = 0;
  float number = 0;
  dst1.value_type = 0;
  dst1.bits[3] = 163840;
  dst1.bits[2] = 0;
  dst1.bits[1] = 0;
  dst1.bits[0] = 12323000;
  result = s21_from_decimal_to_float(dst1, &number);
  ck_assert_float_eq(number, 123230);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(convert_decimal_to_float_2) {
  s21_decimal dst1;
  int result = 0;
  float number = 0;
  dst1.value_type = 0;
  dst1.bits[3] = 2147811328;
  dst1.bits[2] = 0;
  dst1.bits[1] = 0;
  dst1.bits[0] = 24023000;
  result = s21_from_decimal_to_float(dst1, &number);
  ck_assert_float_eq(number, -240.23);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(convert_decimal_to_float_3) {
  s21_decimal dst1;
  int result = 0;
  float number = 0;
  dst1.value_type = 0;
  dst1.bits[3] = 0;
  dst1.bits[2] = 0;
  dst1.bits[1] = 1396;
  dst1.bits[0] = 4225761280;
  result = s21_from_decimal_to_float(dst1, &number);
  ck_assert_float_eq(number, 6000000106496.000000);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(convert_decimal_to_float_4) {
  s21_decimal dst1;
  int result = 0;
  float number = 0;
  dst1.value_type = 0;
  dst1.bits[3] = 0;
  dst1.bits[2] = 0;
  dst1.bits[1] = 0;
  dst1.bits[0] = 0;
  result = s21_from_decimal_to_float(dst1, &number);
  ck_assert_float_eq(number, 0.000000);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(convert_decimal_to_int_1) {
  s21_decimal dst1;
  int result = 0, number = 0;
  dst1.value_type = 0;
  dst1.bits[3] = 0;
  dst1.bits[2] = 0;
  dst1.bits[1] = 0;
  dst1.bits[0] = 133141;
  result = s21_from_decimal_to_int(dst1, &number);
  ck_assert_float_eq(number, 133141);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(convert_decimal_to_int_2) {
  s21_decimal dst1;
  int result = 0, number = 0;
  dst1.value_type = 0;
  dst1.bits[3] = 0;
  dst1.bits[2] = 0;
  dst1.bits[1] = 0;
  dst1.bits[0] = 0;
  result = s21_from_decimal_to_int(dst1, &number);
  ck_assert_float_eq(number, 0);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(convert_decimal_to_int_3) {
  s21_decimal dst1;
  int result = 0, number = 0;
  dst1.value_type = 0;
  dst1.bits[3] = 2147483648;
  dst1.bits[2] = 0;
  dst1.bits[1] = 0;
  dst1.bits[0] = INT_MAX;
  result = s21_from_decimal_to_int(dst1, &number);
  ck_assert_float_eq(number, -2147483648);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(convert_decimal_to_int_4) {
  s21_decimal dst1;
  int result = 0, number = 0;
  dst1.value_type = 0;
  dst1.bits[3] = 0;
  dst1.bits[2] = 0;
  dst1.bits[1] = 0;
  dst1.bits[0] = INT_MAX;
  result = s21_from_decimal_to_int(dst1, &number);
  ck_assert_float_eq(number, 2147483647);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(convert_decimal_to_int_5) {
  s21_decimal dst1;
  int result = 0, number = 0;
  dst1.value_type = 3;
  dst1.bits[3] = 0;
  dst1.bits[2] = 0;
  dst1.bits[1] = 0;
  dst1.bits[0] = 0;
  result = s21_from_decimal_to_int(dst1, &number);
  ck_assert_float_eq(number, 0);
  ck_assert_int_eq(result, 1);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("fpeEGg");
  SRunner *sr = srunner_create(s1);
  int nf;

  TCase *tc1_1 = tcase_create("fpeEGg");
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, convert_int_to_decimal);
  tcase_add_test(tc1_1, convert_float_to_decimal);

  tcase_add_test(tc1_1, convert_less_to_decimal);
  tcase_add_test(tc1_1, decimal_less_or_equal_to_decimal);
  tcase_add_test(tc1_1, decimal_greater_to_decimal);
  tcase_add_test(tc1_1, decimal_greater_or_equal_to_decimal);
  tcase_add_test(tc1_1, decimal_equal);

  tcase_add_test(tc1_1, less_to_decimal);
  tcase_add_test(tc1_1, less_eq_to_decimal);
  tcase_add_test(tc1_1, eq_to_decimal);
  tcase_add_test(tc1_1, add_decimal_1);
  tcase_add_test(tc1_1, add_decimal_2);
  tcase_add_test(tc1_1, add_decimal_3);
  tcase_add_test(tc1_1, add_decimal_4);
  tcase_add_test(tc1_1, add_decimal_5);
  tcase_add_test(tc1_1, add_decimal_6);
  tcase_add_test(tc1_1, add_decimal_7);
  tcase_add_test(tc1_1, add_decimal_8);
  tcase_add_test(tc1_1, add_decimal_9);
  tcase_add_test(tc1_1, add_decimal_10);
  tcase_add_test(tc1_1, add_decimal_11);
  tcase_add_test(tc1_1, add_decimal_12);
  tcase_add_test(tc1_1, add_decimal_13);
  tcase_add_test(tc1_1, add_decimal_14);
  tcase_add_test(tc1_1, add_decimal_15);
  tcase_add_test(tc1_1, add_decimal_16);
  tcase_add_test(tc1_1, sub_decimal_1);
  tcase_add_test(tc1_1, sub_decimal_2);
  tcase_add_test(tc1_1, sub_decimal_3);
  tcase_add_test(tc1_1, sub_decimal_4);
  tcase_add_test(tc1_1, sub_decimal_5);
  tcase_add_test(tc1_1, sub_decimal_6);
  tcase_add_test(tc1_1, sub_decimal_7);
  tcase_add_test(tc1_1, sub_decimal_8);
  tcase_add_test(tc1_1, sub_decimal_9);
  tcase_add_test(tc1_1, sub_decimal_10);
  tcase_add_test(tc1_1, sub_decimal_11);
  tcase_add_test(tc1_1, sub_decimal_12);
  tcase_add_test(tc1_1, mul_decimal_1);
  tcase_add_test(tc1_1, mul_decimal_2);
  tcase_add_test(tc1_1, mul_decimal_3);
  tcase_add_test(tc1_1, mul_decimal_4);
  tcase_add_test(tc1_1, mul_decimal_5);
  tcase_add_test(tc1_1, mul_decimal_6);
  tcase_add_test(tc1_1, mul_decimal_7);
  tcase_add_test(tc1_1, mul_decimal_8);
  tcase_add_test(tc1_1, mul_decimal_9);
  tcase_add_test(tc1_1, mul_decimal_10);
  tcase_add_test(tc1_1, mul_decimal_11);
  tcase_add_test(tc1_1, mul_decimal_12);
  tcase_add_test(tc1_1, mul_decimal_13);
  tcase_add_test(tc1_1, mul_decimal_14);
  tcase_add_test(tc1_1, mul_decimal_15);
  tcase_add_test(tc1_1, mul_decimal_16);
  tcase_add_test(tc1_1, mul_decimal_17);
  tcase_add_test(tc1_1, mul_decimal_18);
  tcase_add_test(tc1_1, mul_decimal_19);
  tcase_add_test(tc1_1, mod_decimal_1);
  tcase_add_test(tc1_1, mod_decimal_2);
  tcase_add_test(tc1_1, mod_decimal_3);
  tcase_add_test(tc1_1, mod_decimal_4);
  tcase_add_test(tc1_1, mod_decimal_5);
  tcase_add_test(tc1_1, mod_decimal_6);
  tcase_add_test(tc1_1, mod_decimal_7);
  tcase_add_test(tc1_1, mod_decimal_8);
  tcase_add_test(tc1_1, mod_decimal_9);
  tcase_add_test(tc1_1, mod_decimal_10);
  tcase_add_test(tc1_1, div_decimal_1);
  tcase_add_test(tc1_1, div_decimal_2);
  tcase_add_test(tc1_1, div_decimal_3);
  tcase_add_test(tc1_1, div_decimal_4);
  tcase_add_test(tc1_1, div_decimal_5);
  tcase_add_test(tc1_1, div_decimal_6);
  tcase_add_test(tc1_1, truncate_1);
  tcase_add_test(tc1_1, truncate_2);
  tcase_add_test(tc1_1, truncate_3);
  tcase_add_test(tc1_1, truncate_4);
  tcase_add_test(tc1_1, truncate_5);
  tcase_add_test(tc1_1, truncate_6);
  tcase_add_test(tc1_1, truncate_7);
  tcase_add_test(tc1_1, negate_1);
  tcase_add_test(tc1_1, negate_2);
  tcase_add_test(tc1_1, negate_3);
  tcase_add_test(tc1_1, negate_4);
  tcase_add_test(tc1_1, negate_5);
  tcase_add_test(tc1_1, negate_6);
  tcase_add_test(tc1_1, round_1);
  tcase_add_test(tc1_1, round_2);
  tcase_add_test(tc1_1, round_3);
  tcase_add_test(tc1_1, round_4);
  tcase_add_test(tc1_1, round_5);
  tcase_add_test(tc1_1, round_6);
  tcase_add_test(tc1_1, round_7);
  tcase_add_test(tc1_1, floor_1);
  tcase_add_test(tc1_1, floor_2);
  tcase_add_test(tc1_1, floor_3);
  tcase_add_test(tc1_1, floor_4);
  tcase_add_test(tc1_1, floor_5);
  tcase_add_test(tc1_1, floor_6);
  tcase_add_test(tc1_1, floor_7);
  tcase_add_test(tc1_1, floor_7);
  tcase_add_test(tc1_1, floor_8);
  tcase_add_test(tc1_1, convert_decimal_to_float_1);
  tcase_add_test(tc1_1, convert_decimal_to_float_2);
  tcase_add_test(tc1_1, convert_decimal_to_float_3);
  tcase_add_test(tc1_1, convert_decimal_to_float_4);
  tcase_add_test(tc1_1, convert_decimal_to_int_1);
  tcase_add_test(tc1_1, convert_decimal_to_int_2);
  tcase_add_test(tc1_1, convert_decimal_to_int_3);
  tcase_add_test(tc1_1, convert_decimal_to_int_4);
  tcase_add_test(tc1_1, convert_decimal_to_int_5);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
