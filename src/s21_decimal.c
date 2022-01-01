#include "s21_decimal.h"

//  проверяет бит в числе на определенной позиции
int check_bit(s21_decimal dst, int position) {
  int indexBits = position / 32;
  int positionToBits = position % 32;
  return ((dst.bits[indexBits] & (1 << positionToBits)) != 0);
}

//  проверить бит в позицию числа
int check_bit_number(unsigned int number, int position) {
  return ((number & (1 << position)) != 0);
}

//  установить бит в позицию числа
int set_bit_number(unsigned int number, int position) {
  return (number | (1 << position));
}

//  устанавливает бит в определенную позицию
void set_bit(s21_decimal *dst, int position) {
  int indexBits = position / 32;
  int positionToBits = position % 32;
  dst->bits[indexBits] = dst->bits[indexBits] | (1 << positionToBits);
}

//  убирает бит из определенной позиции
void remove_bit(s21_decimal *dst, int position) {
  int indexBits = position / 32;
  int positionToBits = position % 32;
  dst->bits[indexBits] = dst->bits[indexBits] & ~(1 << positionToBits);
}

//   сдвинуть бит налево или направо
int shift_bit(s21_decimal *dst, int position, int side) {
  int positionThirtyOne = 0, positionSixtyThree = 0, positionInfinity = 0;
  for (int i = 0; i < position; i++) {
    if (check_bit(*dst, 31) == 1) positionThirtyOne = 1;
    if (check_bit(*dst, 63) == 1) positionSixtyThree = 1;
    if (check_bit(*dst, 95) == 1) positionInfinity = 1;
    for (int j = 0; j < 3; j++) dst->bits[j] = dst->bits[j] << 1;
    if (positionThirtyOne == 1) {
      set_bit(dst, 32);
      positionThirtyOne = 0;
    }
    if (positionSixtyThree == 1) {
      set_bit(dst, 64);
      positionSixtyThree = 0;
    }
  }
  return positionInfinity;
}

//  перевод decimal в дополнительный код
void transform_additional_code(s21_decimal *dst) {
  for (int i = 0; i < 3; i++) dst->bits[i] = ~(dst->bits[i]) + 1;
}

//  иницилизация структуры, заполняем элементы массива нулями
void initialization_struct(s21_decimal *dst) {
  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
}

//  перевод int в decimal
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  initialization_struct(dst);
  int codeError = 0;
  unsigned int srcTemp = src;
  if (dst) {
    if (src < 0) srcTemp *= -1;
    dst->bits[0] = srcTemp;
    if (src < 0) set_bit(dst, 127);
    dst->value_type = S21_NORMAL_VALUE;
  } else {
    codeError = 1;
  }
  return codeError;
}

//  проверка числа float на nan/+-inf
void check_value_number_float(float src, s21_decimal *decimal) {
  int checkSign = check_bit_number((unsigned int)src, 31);
  if (isinf(src) == 1 && checkSign == 0) {
    decimal->value_type = S21_INFINITY;
  } else if (isinf(src) == 1 && checkSign == 1) {
    decimal->value_type = S21_NEGATIVE_INFINITY;
  } else if (isnan(src) == 1) {
    decimal->value_type = S21_NAN;
  } else {
    decimal->value_type = S21_NORMAL_VALUE;
  }
}

// перевод float в decimal
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int codeError = 0;
  value intFloat;
  int binaryAccuracy = 0, decimalAccuracy = 0;
  double srcTemp = (double)src;
  check_value_number_float(srcTemp, dst);
  initialization_struct(dst);
  binaryAccuracy = get_accuracy(srcTemp);
  if (dst->value_type == S21_NORMAL_VALUE && src != 0 && dst) {
    for (; !((int)srcTemp); srcTemp *= 10) decimalAccuracy += 1;
    for (; decimalAccuracy < 28 && (int)srcTemp / 10000000 == 0; srcTemp *= 10)
      decimalAccuracy += 1;
    if (decimalAccuracy <= 28 &&
        (binaryAccuracy > -95 && binaryAccuracy <= 95)) {
      srcTemp = (float)srcTemp;
      for (; fmod(srcTemp, 10) == 0 && decimalAccuracy > 0; decimalAccuracy--)
        srcTemp = srcTemp / 10;
      binaryAccuracy = get_accuracy(srcTemp);
      set_bit(dst, binaryAccuracy);
      intFloat.floatValue = srcTemp;
      for (int i = binaryAccuracy - 1, j = 22; j >= 0; i--, j--)
        if (check_bit_number(intFloat.integerValue, j) == 1) set_bit(dst, i);
      set_sign_and_accuracy(src, dst, decimalAccuracy);
    } else {
      codeError = 1;
    }
  } else if (dst->value_type == S21_NORMAL_VALUE && src == 0 && dst) {
    initialization_struct(dst);
  } else {
    codeError = 1;
  }
  return codeError;
}

//  функция вычисления точности
int get_accuracy(float src) {
  value intFloat;
  intFloat.floatValue = src;
  int accuracy = 0;
  for (int i = 30, position = 7; i >= 23; i--, position--)
    if (check_bit_number(intFloat.integerValue, i) == 1)
      accuracy = set_bit_number(accuracy, position);
  accuracy -= 127;
  return accuracy;
}

//  поставить знак и точность в bits[3]
void set_sign_and_accuracy(float src, s21_decimal *dst, int accuracy) {
  value intFloat;
  intFloat.floatValue = src;
  if (check_bit_number(intFloat.integerValue, 31) == 1) set_bit(dst, 127);
  for (int i = 7, position = 119; i >= 0; i--, position--)
    if (check_bit_number(accuracy, i) == 1) set_bit(dst, position);
}

//  установить точность
void set_accuracy(s21_decimal *dst, int accuracy) {
  for (int i = 7, position = 119; i >= 0; i--, position--)
    remove_bit(dst, position);
  for (int i = 7, position = 119; i >= 0; i--, position--)
    if (check_bit_number(accuracy, i) == 1) set_bit(dst, position);
}

//  перевод из decimal в int
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int codeError = 0;
  if (src.value_type == S21_NORMAL_VALUE) {
    for (int i = 31; i >= 0; i--)
      if (check_bit(src, i) == 1) *dst += (int)s21_pow(i);
    if (check_bit(src, 127) == 1) *dst *= -1;
  } else {
    codeError = 1;
  }
  return codeError;
}

//  перевод из decimal в float
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int codeError = 0;
  if (src.value_type == S21_NORMAL_VALUE || dst) {
    double dstTemp = 0;
    for (int i = 0; i < 96; i++) {
      if (check_bit(src, i))  dstTemp += s21_pow(i);
    }
    int accarucy = accarucy_bit_to_accuracy_decimal(src);
    if (accarucy > 0) {
      for (int i = accarucy; i > 0; i--) dstTemp /= 10.0;
    }
    if (check_bit(src, 127)) dstTemp *= -1;
    *dst = (float)dstTemp;
  } else {
    codeError = 1;
  }
  return codeError;
}

//  перевод степени показателя в число (использовать с set accuracy)
int accarucy_bit_to_accuracy_decimal(s21_decimal src) {
  int decimalAccuracy = 0;
  for (int i = 7, position = 119; i >= 0; i--, position--)
    if (check_bit(src, position) == 1) decimalAccuracy += s21_pow(i);
  return decimalAccuracy;
}

//  возведение 2 в степень
double s21_pow(int degree) {
  double resultPow = 1;
  for (int i = 0; i < degree; i++) {
    resultPow *= 2;
  }
  return resultPow;
}

//  проверка значения числа в операции сложения/вычитания
int check_value_add(s21_decimal decimalOne, s21_decimal decimalTwo,
                    s21_decimal *decimalResult, int operation) {
  int check = 1;
  if (decimalOne.value_type == S21_INFINITY &&
      decimalTwo.value_type == S21_NEGATIVE_INFINITY) {
    if (operation == 1)
      decimalResult->value_type = S21_NAN;
    else
      decimalResult->value_type = S21_INFINITY;
  } else if (decimalOne.value_type == S21_NEGATIVE_INFINITY &&
             decimalTwo.value_type == S21_INFINITY) {
    if (operation == 1)
      decimalResult->value_type = S21_NAN;
    else
      decimalResult->value_type = S21_NEGATIVE_INFINITY;
  } else if (decimalOne.value_type == S21_NAN ||
             decimalTwo.value_type == S21_NAN) {
    decimalResult->value_type = S21_NAN;
  } else if (decimalOne.value_type == S21_NORMAL_VALUE &&
             decimalTwo.value_type == S21_NORMAL_VALUE) {
    decimalResult->value_type = S21_NORMAL_VALUE;
    check = 0;
  } else if ((decimalTwo.value_type == S21_NEGATIVE_INFINITY &&
              decimalOne.value_type == S21_NEGATIVE_INFINITY) ||
             (decimalOne.value_type == S21_NEGATIVE_INFINITY &&
              decimalTwo.value_type == S21_NEGATIVE_INFINITY)) {
    if (operation == 1)
      decimalResult->value_type = S21_NEGATIVE_INFINITY;
    else
      decimalResult->value_type = S21_NAN;
  } else if ((decimalTwo.value_type == S21_INFINITY &&
              decimalOne.value_type == S21_INFINITY) ||
             (decimalOne.value_type == S21_INFINITY &&
              decimalTwo.value_type == S21_INFINITY)) {
    if (operation == 1)
      decimalResult->value_type = S21_INFINITY;
    else
      decimalResult->value_type = S21_NAN;
  } else if (decimalOne.value_type == S21_INFINITY &&
             decimalTwo.value_type == S21_NORMAL_VALUE) {
    decimalResult->value_type = S21_INFINITY;
  } else if (decimalOne.value_type == S21_NEGATIVE_INFINITY &&
             decimalTwo.value_type == S21_NORMAL_VALUE) {
    decimalResult->value_type = S21_NEGATIVE_INFINITY;
  } else if (decimalTwo.value_type == S21_INFINITY &&
             decimalOne.value_type == S21_NORMAL_VALUE) {
    if (operation == 1)
      decimalResult->value_type = S21_INFINITY;
    else
      decimalResult->value_type = S21_NEGATIVE_INFINITY;
  } else if (decimalTwo.value_type == S21_NEGATIVE_INFINITY &&
             decimalOne.value_type == S21_NORMAL_VALUE) {
    if (operation == 1)
      decimalResult->value_type = S21_NEGATIVE_INFINITY;
    else
      decimalResult->value_type = S21_INFINITY;
  }
  return check;
}

//  сложение чисел decimal
s21_decimal s21_add(s21_decimal decimalOne, s21_decimal decimalTwo) {
  s21_decimal decimalResult, decimalOneTemp, decimalTwoTemp;
  initialization_struct(&decimalResult);
  initialization_struct(&decimalOneTemp);
  initialization_struct(&decimalTwoTemp);
  decimalOneTemp.value_type = S21_NORMAL_VALUE;
  decimalTwoTemp.value_type = S21_NORMAL_VALUE;
  int negativeDecimalOne = 0, negativeDecimalTwo = 0, reverceDecimal = 0,
      signResultDecimal = 0, checkValue = 0;
  if (check_bit(decimalOne, 127) == 1) negativeDecimalOne = 1;
  if (check_bit(decimalTwo, 127) == 1) negativeDecimalTwo = 1;
  int negativeDecimalSum = negativeDecimalOne + negativeDecimalTwo;
  rewriteDecimal(&decimalOne, &decimalOneTemp);
  rewriteDecimal(&decimalTwo, &decimalTwoTemp);
  remove_bit(&decimalOneTemp, 127);
  remove_bit(&decimalTwoTemp, 127);
  if (negativeDecimalSum == 1)
    checkValue = check_value_add(decimalOne, decimalTwo, &decimalResult, 0);
  else
    checkValue = check_value_add(decimalOne, decimalTwo, &decimalResult, 1);
  if (checkValue == 0) {
    convert_to_like_accuracy(&decimalOne, &decimalTwo);
    if (s21_is_less(decimalOneTemp, decimalTwoTemp) == 0) {
      reverceDecimal = 1;
      signResultDecimal = negativeDecimalTwo;
    } else {
      signResultDecimal = negativeDecimalOne;
    }
    if (negativeDecimalSum == 1) {
      if (reverceDecimal == 1) {
        algoritm_sub_decimal(&decimalTwo, &decimalOne, &decimalResult);
        if (signResultDecimal == 1) set_bit(&decimalResult, 127);
      } else if (reverceDecimal != 1) {
        algoritm_sub_decimal(&decimalOne, &decimalTwo, &decimalResult);
        if (signResultDecimal == 1) set_bit(&decimalResult, 127);
      }
    } else if (negativeDecimalSum != 1) {
      if (algoritm_add_decimal(&decimalOne, &decimalTwo, &decimalResult)) {
        if (negativeDecimalSum == 2) set_bit(&decimalResult, 127);
      } else {
        initialization_struct(&decimalResult);
        decimalResult.value_type = S21_INFINITY;
      }
    }
    if ((s21_is_equal(decimalOneTemp, decimalTwoTemp) == 0) &&
        negativeDecimalSum == 1) {
      initialization_struct(&decimalResult);
    } else {
      int accuracyDecimalOne = accarucy_bit_to_accuracy_decimal(decimalOne);
      set_accuracy(&decimalResult, accuracyDecimalOne);
    }
  }
  return decimalResult;
}

// вычитание чисел decimal
s21_decimal s21_sub(s21_decimal decimalOne, s21_decimal decimalTwo) {
  s21_decimal decimalResult;
  decimalResult.value_type = S21_NORMAL_VALUE;
  initialization_struct(&decimalResult);
  if (check_bit(decimalTwo, 127) == 0)
    set_bit(&decimalTwo, 127);
  else
    remove_bit(&decimalTwo, 127);
  decimalResult = s21_add(decimalOne, decimalTwo);
  return decimalResult;
}

//  алгоритм сложения decimal
int algoritm_add_decimal(s21_decimal *decimalOne, s21_decimal *decimalTwo,
                         s21_decimal *decimalResult) {
  int remainder = 0, result = 1;
  for (int i = 0; i < 96; i++) {
    int decimalOneIndex = check_bit(*decimalOne, i);
    int decimalTwoIndex = check_bit(*decimalTwo, i);
    if ((decimalOneIndex == 1) && (decimalTwoIndex == 1)) {
      if (remainder == 1) set_bit(decimalResult, i);
      remainder = 1;
    } else if ((decimalOneIndex || decimalTwoIndex) == 1) {
      if (remainder == 0) set_bit(decimalResult, i);
    } else if ((decimalOneIndex || decimalTwoIndex) == 0) {
      if (remainder == 1) {
        set_bit(decimalResult, i);
        remainder = 0;
      }
    }
    if (remainder == 1 && check_bit(*decimalOne, 95)) {
      result = 0;
    }
  }
  return result;
}

//  алгоритм вычитания decimal
void algoritm_sub_decimal(s21_decimal *decimalOne, s21_decimal *decimalTwo,
                          s21_decimal *decimalResult) {
  transform_additional_code(decimalOne);
  algoritm_add_decimal(decimalOne, decimalTwo, decimalResult);
  transform_additional_code(decimalResult);
}

// алгоритм умножения decimal
void algoritm_multiply_decimal(s21_decimal *decimalOne, s21_decimal *decimalTwo,
                               s21_decimal *decimalResult) {
  s21_decimal decimalTemp, decimalShift;
  int checkInfinity = 0;
  initialization_struct(&decimalTemp);
  decimalTemp.value_type = S21_NORMAL_VALUE;
  decimalShift.value_type = S21_NORMAL_VALUE;
  initialization_struct(&decimalShift);
  initialization_struct(decimalResult);
  for (int i = 95; i >= 0 && checkInfinity == 0; i--) {
    rewriteDecimal(decimalOne, &decimalShift);
    if (check_bit(*decimalTwo, i) == 1) {
      initialization_struct(decimalResult);
      checkInfinity = shift_bit(&decimalShift, i, 0);
      algoritm_add_decimal(&decimalShift, &decimalTemp, decimalResult);
      rewriteDecimal(decimalResult, &decimalTemp);
    }
  }
  if (checkInfinity == 1) decimalResult->value_type = S21_INFINITY;
}

s21_decimal s21_mul(s21_decimal decimalOne, s21_decimal decimalTwo) {
  s21_decimal decimalResult;
  int sign = 0;
  if (check_bit(decimalOne, 127) == 1) sign += 1;
  if (check_bit(decimalTwo, 127) == 1) sign += 1;
  initialization_struct(&decimalResult);
  if (check_multiply(decimalOne, decimalTwo, &decimalResult) == 1) {
    convert_to_like_accuracy(&decimalOne, &decimalTwo);
    algoritm_multiply_decimal(&decimalOne, &decimalTwo, &decimalResult);
    set_accuracy(&decimalResult,
                 accarucy_bit_to_accuracy_decimal(decimalOne) * 2);
    if (sign == 1) set_bit(&decimalResult, 127);
    if (decimalResult.value_type == S21_INFINITY)
      initialization_struct(&decimalResult);
    else
      decimalResult.value_type = S21_NORMAL_VALUE;
  }
  return decimalResult;
}

int check_multiply(s21_decimal decimalOne, s21_decimal decimalTwo,
                   s21_decimal *decimalResult) {
  s21_decimal decimalZero;
  initialization_struct(&decimalZero);
  decimalResult->value_type = S21_NORMAL_VALUE;
  decimalZero.value_type = S21_NORMAL_VALUE;
  int checkZero = 0, checkDoubleInfinity = 0, checkInfOne = 0, checkInfTwo = 0;
  if (decimalOne.value_type == S21_INFINITY ||
      decimalOne.value_type == S21_NEGATIVE_INFINITY)
    checkInfOne = 1;
  if (decimalTwo.value_type == S21_INFINITY ||
      decimalTwo.value_type == S21_NEGATIVE_INFINITY)
    checkInfTwo = 1;
  checkDoubleInfinity = checkInfTwo + checkInfOne;
  if (s21_is_equal(decimalOne, decimalZero) == 0 && checkDoubleInfinity == 1 &&
      checkInfOne == 0) {
    decimalResult->value_type = S21_NAN;
  } else if (s21_is_equal(decimalTwo, decimalZero) == 0 &&
             checkDoubleInfinity == 1 && checkInfTwo == 0) {
    decimalResult->value_type = S21_NAN;
  } else if (decimalOne.value_type == S21_INFINITY ||
             decimalOne.value_type == S21_NORMAL_VALUE) {
    if (decimalTwo.value_type == S21_INFINITY)
      decimalResult->value_type = S21_INFINITY;
    else if (decimalTwo.value_type == S21_NEGATIVE_INFINITY)
      decimalResult->value_type = S21_NEGATIVE_INFINITY;
    else if (decimalTwo.value_type == S21_NORMAL_VALUE)
      decimalResult->value_type = S21_INFINITY;
  } else if (decimalTwo.value_type == S21_INFINITY ||
             decimalTwo.value_type == S21_NORMAL_VALUE) {
    if (decimalOne.value_type == S21_INFINITY)
      decimalResult->value_type = S21_INFINITY;
    else if (decimalOne.value_type == S21_NEGATIVE_INFINITY)
      decimalResult->value_type = S21_NEGATIVE_INFINITY;
    else if (decimalOne.value_type == S21_NORMAL_VALUE)
      decimalResult->value_type = S21_INFINITY;
  } else if ((decimalOne.value_type == S21_NEGATIVE_INFINITY ||
              decimalOne.value_type == S21_NORMAL_VALUE) &&
             decimalTwo.value_type == S21_NEGATIVE_INFINITY) {
    decimalResult->value_type = S21_NEGATIVE_INFINITY;
  } else if ((decimalTwo.value_type == S21_NEGATIVE_INFINITY ||
              decimalTwo.value_type == S21_NORMAL_VALUE) &&
             decimalOne.value_type == S21_NEGATIVE_INFINITY) {
    decimalResult->value_type = S21_NEGATIVE_INFINITY;
  }
  if (decimalOne.value_type == S21_NAN || decimalTwo.value_type == S21_NAN)
    decimalResult->value_type = S21_NAN;

  if (decimalOne.value_type == S21_NORMAL_VALUE &&
      decimalTwo.value_type == S21_NORMAL_VALUE) {
    decimalResult->value_type = S21_NORMAL_VALUE;
    checkZero = 1;
  }
  return checkZero;
}

// приведение к одной степени
void convert_to_like_accuracy(s21_decimal *decimalOne,
                              s21_decimal *decimalTwo) {
  int sign = 0;
  s21_decimal decimalTen;
  s21_decimal decimalTemp;
  decimalOne->value_type = S21_NORMAL_VALUE;
  decimalTwo->value_type = S21_NORMAL_VALUE;
  decimalTen.value_type = S21_NORMAL_VALUE;
  decimalTemp.value_type = S21_NORMAL_VALUE;
  initialization_struct(&decimalTen);
  initialization_struct(&decimalTemp);
  s21_from_int_to_decimal(10, &decimalTen);
  int accuracyDecimalOne = accarucy_bit_to_accuracy_decimal(*decimalOne);
  int accuracyDecimalTwo = accarucy_bit_to_accuracy_decimal(*decimalTwo);
  if (accuracyDecimalOne > accuracyDecimalTwo && accuracyDecimalOne <= 28) {
    if (check_bit(*decimalTwo, 127) == 1) sign = 1;
    for (int i = accuracyDecimalTwo; i < accuracyDecimalOne; i++) {
      algoritm_multiply_decimal(decimalTwo, &decimalTen, &decimalTemp);
      rewriteDecimal(&decimalTemp, decimalTwo);
    }
    set_accuracy(decimalTwo, accuracyDecimalOne);
    if (sign == 1) set_bit(decimalTwo, 127);
  } else if (accuracyDecimalOne < accuracyDecimalTwo &&
             accuracyDecimalTwo <= 28) {
    if (check_bit(*decimalOne, 127) == 1) sign = 1;
    for (int i = accuracyDecimalOne; i < accuracyDecimalTwo; i++) {
      algoritm_multiply_decimal(decimalOne, &decimalTen, &decimalTemp);
      rewriteDecimal(&decimalTemp, decimalOne);
    }
    set_accuracy(decimalOne, accuracyDecimalTwo);
    if (sign == 1) set_bit(decimalOne, 127);
  }
}

//  перезапись decimal
void rewriteDecimal(s21_decimal *dst, s21_decimal *decimalTemp) {
  initialization_struct(decimalTemp);
  for (int i = 127; i >= 0; i--)
    if (check_bit(*dst, i) == 1) set_bit(decimalTemp, i);
}

//  сравенение чисел бесконечностей и тд
int comparisonValue(s21_decimal decimalOne, s21_decimal decimalTwo, int equal,
                    int *result) {
  int flagInfinity = 1;
  if (decimalOne.value_type == S21_NEGATIVE_INFINITY &&
      decimalTwo.value_type == S21_INFINITY) {
    *result = 0;
  } else if (decimalOne.value_type == S21_NEGATIVE_INFINITY &&
             decimalTwo.value_type == S21_NORMAL_VALUE) {
    *result = 0;
  } else if (decimalOne.value_type == S21_INFINITY &&
             decimalTwo.value_type == S21_NEGATIVE_INFINITY) {
    *result = 1;
  } else if (decimalOne.value_type == S21_NORMAL_VALUE &&
             decimalTwo.value_type == S21_NEGATIVE_INFINITY) {
    *result = 1;
  } else if (decimalOne.value_type == S21_NEGATIVE_INFINITY &&
             decimalTwo.value_type == S21_NEGATIVE_INFINITY) {
    if (equal == 1)
      *result = 0;
    else
      *result = 1;
  } else if (decimalOne.value_type == S21_INFINITY &&
             decimalTwo.value_type == S21_INFINITY) {
    if (equal == 1)
      *result = 0;
    else
      *result = 1;
  } else if (decimalOne.value_type == S21_NAN ||
             decimalTwo.value_type == S21_NAN) {
    *result = 1;
  } else if (decimalOne.value_type == S21_INFINITY &&
             decimalTwo.value_type == S21_NORMAL_VALUE) {
    *result = 1;
  } else if (decimalOne.value_type == S21_NORMAL_VALUE &&
             decimalTwo.value_type == S21_INFINITY) {
    *result = 0;
  } else if (decimalOne.value_type == S21_NORMAL_VALUE &&
             decimalTwo.value_type == S21_NORMAL_VALUE) {
    flagInfinity = 0;
  }
  return flagInfinity;
}

//  меньше из decimal
int s21_is_less(s21_decimal decimalOne, s21_decimal decimalTwo) {
  int decision = 1, maxPositionOne = -1, maxPositionTwo = -1, count = 0;
  int signNegativeDecimal = 0, tempSign = 0, flagInfinity = 0;
  tempSign = checkBitsSign(&decimalOne, &decimalTwo, &decision,
                           &signNegativeDecimal, 0);
  flagInfinity = comparisonValue(decimalOne, decimalTwo, 0, &decision);
  if (tempSign == 1 && flagInfinity == 0) {
    convert_to_like_accuracy(&decimalOne, &decimalTwo);
    for (int i = 95; i >= 0; i--) {
      if ((check_bit(decimalOne, i) == 1)) maxPositionOne = i;
      if ((check_bit(decimalTwo, i) == 1)) maxPositionTwo = i;
      if (maxPositionOne < maxPositionTwo) {
        decision = 0;
        break;
      } else if (maxPositionOne == maxPositionTwo) {
        maxPositionOne = -1;
        maxPositionTwo = -1;
        count++;
      } else {
        break;
      }
    }
  }
  if (signNegativeDecimal == 1 && decision == 1 && flagInfinity == 0)
    decision = 0;
  else if (signNegativeDecimal == 1 && decision == 0 && flagInfinity == 0)
    decision = 1;
  if (count == 96 && flagInfinity == 0) decision = 1;
  return decision;
}

//  проверка знака для функций сравнения
int checkBitsSign(s21_decimal *decimalOne, s21_decimal *decimalTwo,
                  int *decision, int *signNegative, int operation) {
  int tempSign = 0;
  if (operation == 0) {
    if ((check_bit(*decimalOne, 127) == 0) &&
        (check_bit(*decimalTwo, 127) == 1)) {
      *decision = 1;
    } else if ((check_bit(*decimalOne, 127) == 1) &&
               (check_bit(*decimalTwo, 127) == 0)) {
      *decision = 0;
    } else if ((check_bit(*decimalOne, 127) == 1) &&
               (check_bit(*decimalTwo, 127) == 1)) {
      *signNegative = 1;
      tempSign = 1;
    } else {
      tempSign = 1;
    }
  } else {
    if ((check_bit(*decimalOne, 127) == 0) &&
        (check_bit(*decimalTwo, 127) == 1)) {
      *decision = 0;
    } else if ((check_bit(*decimalOne, 127) == 1) &&
               (check_bit(*decimalTwo, 127) == 0)) {
      *decision = 1;
    } else if ((check_bit(*decimalOne, 127) == 1) &&
               (check_bit(*decimalTwo, 127) == 1)) {
      *signNegative = 1;
      tempSign = 1;
    } else {
      tempSign = 1;
    }
  }
  return tempSign;
}

int s21_is_less_or_equal(s21_decimal decimalOne, s21_decimal decimalTwo) {
  int decision = s21_is_less(decimalOne, decimalTwo);
  int decisionTemp = s21_is_equal(decimalOne, decimalTwo);
  if (decisionTemp == 0) decision = 0;
  return decision;
}

int s21_is_equal(s21_decimal decimalOne, s21_decimal decimalTwo) {
  int decision = 1, maxPositionOne = -1, maxPositionTwo = -1, count = 0;
  int flagInfinity = 0;
  flagInfinity = comparisonValue(decimalOne, decimalTwo, 1, &decision);
  for (int i = 127; i >= 0 && flagInfinity == 0; i--) {
    convert_to_like_accuracy(&decimalOne, &decimalTwo);
    if ((check_bit(decimalOne, i) == 1)) maxPositionOne = i;
    if ((check_bit(decimalTwo, i) == 1)) maxPositionTwo = i;
    if (maxPositionOne == maxPositionTwo) {
      maxPositionOne = -1;
      maxPositionTwo = -1;
      count++;
    } else {
      break;
    }
  }
  if (count == 128 && flagInfinity == 0) decision = 0;
  if (decimalTwo.value_type != decimalOne.value_type) decision = 1;
  return decision;
}

int s21_is_greater(s21_decimal decimalOne, s21_decimal decimalTwo) {
  int decision_less = s21_is_less(decimalOne, decimalTwo);
  int decision = 0;
  int decisionTemp = s21_is_equal(decimalOne, decimalTwo);
  if (decision_less == 1 && decisionTemp != 0)
    decision = 0;
  else if (decision_less == 0 && (decisionTemp != 0 || decisionTemp == 0))
    decision = 1;
  else if (decision_less == 1 && decisionTemp == 0)
    decision = 1;
  return decision;
}

int s21_is_greater_or_equal(s21_decimal decimalOne, s21_decimal decimalTwo) {
  int decision = s21_is_greater(decimalOne, decimalTwo);
  int decisionTemp = s21_is_equal(decimalOne, decimalTwo);
  if (decisionTemp == 0) decision = 0;
  return decision;
}

int s21_is_not_equal(s21_decimal decimalOne, s21_decimal decimalTwo) {
  int decision = 0;
  int decision_equal = s21_is_equal(decimalOne, decimalTwo);
  if (decision_equal == 0)
    decision = 1;
  else if (decision_equal == 1)
    decision = 0;
  return decision;
}

// алгоритм деления decimal
void algoritm_div_decimal(s21_decimal *dividend, s21_decimal *divisor,
                          s21_decimal *quotient, s21_decimal *mod) {
  s21_decimal decimalZero;
  decimalZero.value_type = S21_NORMAL_VALUE;
  initialization_struct(&decimalZero);
  remove_bit(divisor, 127);
  remove_bit(dividend, 127);
  initialization_struct(quotient);
  quotient->value_type = 0;
  initialization_struct(mod);
  int equal = s21_is_equal(*divisor, decimalZero);
  quotient->value_type = S21_NORMAL_VALUE;
  mod->value_type = S21_NORMAL_VALUE;
  int d = divisor->value_type;
  if (equal == 1) {
    if (divisor->value_type == S21_NEGATIVE_INFINITY) {  //  делитель минус беск
      if (dividend->value_type == S21_NEGATIVE_INFINITY ||
          dividend->value_type == S21_INFINITY) {
        quotient->value_type = S21_NAN;
        mod->value_type = S21_NAN;
      } else if (dividend->value_type == S21_NORMAL_VALUE) {
        *quotient = s21_negate(*quotient);
        rewriteDecimal(dividend, mod);
        mod->value_type = S21_NORMAL_VALUE;
      }
    } else if (divisor->value_type == 1) {  //  делитель беск
      if (dividend->value_type == S21_NEGATIVE_INFINITY ||
          dividend->value_type == S21_INFINITY) {
        quotient->value_type = S21_NAN;
        mod->value_type = S21_NAN;
      } else if (dividend->value_type == S21_NORMAL_VALUE) {
        rewriteDecimal(dividend, mod);
        mod->value_type = S21_NORMAL_VALUE;
        initialization_struct(quotient);
      }
    } else {
      convert_to_like_accuracy(dividend, divisor);
      div_int_number(dividend, divisor, quotient, mod);
    }
  } else {
    //  делитель 0
    if (dividend->value_type == S21_NEGATIVE_INFINITY)
      quotient->value_type = S21_NEGATIVE_INFINITY;
    else if (dividend->value_type == S21_INFINITY)
      quotient->value_type = S21_INFINITY;
    else
      quotient->value_type = S21_NAN;
    mod->value_type = S21_NAN;
  }
}

// целочислнное деление decimal
void div_int_number(s21_decimal *dividend, s21_decimal *divisor,
                    s21_decimal *quotient, s21_decimal *mod) {
  s21_decimal decimalTemp, decimalZero, sub;
  int flag = 0;
  remove_bit(divisor, 127);
  remove_bit(dividend, 127);
  decimalTemp.value_type = S21_NORMAL_VALUE;
  sub.value_type = S21_NORMAL_VALUE;
  decimalZero.value_type = S21_NORMAL_VALUE;
  initialization_struct(&decimalTemp);  //  изменяемое делимое
  initialization_struct(&sub);          //  изменяемое делимое
  initialization_struct(quotient);      //  результат
  initialization_struct(mod);
  initialization_struct(&decimalZero);
  convert_to_like_accuracy(dividend, divisor);
  int a = s21_is_equal(*divisor, decimalZero);
  int b = s21_is_less(*dividend, *divisor);
  if (a == 1 && b != 0) {
    for (int i = 95; i >= 0; i--) {
      shift_bit(&decimalTemp, 1, 0);
      if (check_bit(*dividend, i)) set_bit(&decimalTemp, 0);
      int sizeSub1 = accarucy_bit_to_accuracy_decimal(*divisor);
      set_accuracy(&decimalTemp, sizeSub1);
      sub = s21_sub(decimalTemp, *divisor);
      if (s21_is_less_or_equal(*divisor, decimalTemp) == 0) {
        flag = 1;
        rewriteDecimal(&sub, &decimalTemp);
        int sizeSub = accarucy_bit_to_accuracy_decimal(sub);
        set_accuracy(&decimalTemp, sizeSub);
        shift_bit(quotient, 1, 0);
        set_bit(quotient, 0);

      } else {
        if (flag == 1) shift_bit(quotient, 1, 0);
      }
      if (i == 0) rewriteDecimal(&decimalTemp, mod);
    }
  } else if (a == 1 && b == 0) {
    initialization_struct(quotient);
    rewriteDecimal(dividend, mod);
  } else {
    initialization_struct(quotient);
  }
}

//  деление остатка от деления
void div_second_number(s21_decimal *mod, s21_decimal *divisor,
                       s21_decimal *quotient) {
  s21_decimal decimalTemp, decimalTemp2, decMil;
  decimalTemp.value_type = S21_NORMAL_VALUE;
  decimalTemp2.value_type = S21_NORMAL_VALUE;
  decMil.value_type = S21_NORMAL_VALUE;
  initialization_struct(&decimalTemp);
  initialization_struct(&decimalTemp2);
  initialization_struct(&decMil);
  s21_from_float_to_decimal(1000000, &decMil);
  *mod = s21_mul(*mod, decMil);
  div_int_number(mod, divisor, &decimalTemp, &decimalTemp2);
  shift_bit(&decimalTemp2, 1, 0);
  if (s21_is_less_or_equal(*divisor, decimalTemp2) == 0) {
    set_bit(&decimalTemp, 0);
  }
  int aac = accarucy_bit_to_accuracy_decimal(decimalTemp);
  int aa = aac + 6;
  set_accuracy(&decimalTemp, aa);
  *quotient = s21_add(decimalTemp, *quotient);
}

// деление decimal
s21_decimal s21_div(s21_decimal decimalOne, s21_decimal decimalTwo) {
  s21_decimal quotient, mod;
  quotient.value_type = S21_NORMAL_VALUE;
  mod.value_type = S21_NORMAL_VALUE;
  int negativeDecimalOne = 0, negativeDecimalTwo = 0;
  if (check_bit(decimalOne, 127) == 1) negativeDecimalOne = 1;
  if (check_bit(decimalTwo, 127) == 1) negativeDecimalTwo = 1;
  algoritm_div_decimal(&decimalOne, &decimalTwo, &quotient, &mod);
  div_second_number(&mod, &decimalTwo, &quotient);
  if (negativeDecimalOne + negativeDecimalTwo == 1)
    set_bit(&quotient, 127);
  else
    remove_bit(&quotient, 127);
  return quotient;
}

// деление decimal
s21_decimal s21_mod(s21_decimal decimalOne, s21_decimal decimalTwo) {
  s21_decimal quotient, mod;
  int negativeDecimalOne = 0;
  if (check_bit(decimalOne, 127) == 1) negativeDecimalOne = 1;
  algoritm_div_decimal(&decimalOne, &decimalTwo, &quotient, &mod);
  if (negativeDecimalOne == 1)
    set_bit(&mod, 127);
  else
    remove_bit(&mod, 127);
  return mod;
}

//  проверка значений enum для доп функций
int check_decimal_negate(s21_decimal decimal, s21_decimal *decimalTemp) {
  int result = 0;
  if (decimal.value_type == S21_INFINITY)
    decimalTemp->value_type = S21_INFINITY;
  else if (decimal.value_type == S21_NEGATIVE_INFINITY)
    decimalTemp->value_type = S21_NEGATIVE_INFINITY;
  else if (decimal.value_type == S21_NAN)
    decimalTemp->value_type = S21_NAN;
  if (decimal.value_type == S21_NORMAL_VALUE) {
    decimalTemp->value_type = S21_NORMAL_VALUE;
    result = 1;
  }
  return result;
}

//  умножение decimal на -1
s21_decimal s21_negate(s21_decimal decimal) {
  s21_decimal decimalResult, decimalZero;
  decimalZero.value_type = S21_NORMAL_VALUE;
  initialization_struct(&decimalResult);
  initialization_struct(&decimalZero);
  if (check_decimal_negate(decimal, &decimalResult) == 1) {
    rewriteDecimal(&decimal, &decimalResult);
    if (s21_is_equal(decimal, decimalZero) == 1) {
      if (check_bit(decimal, 127))
        remove_bit(&decimalResult, 127);
      else
        set_bit(&decimalResult, 127);
    }
  }
  return decimalResult;
}

//  возвращает целые цифры указанного decimal числа
s21_decimal s21_truncate(s21_decimal decimal) {
  s21_decimal decimalResult, decimalAccuracy, decimalMod;
  int sign = 0;
  if (check_bit(decimal, 127)) sign = 1;
  initialization_struct(&decimalAccuracy);
  initialization_struct(&decimalResult);
  initialization_struct(&decimalMod);
  decimalAccuracy.value_type = S21_NORMAL_VALUE;
  decimalMod.value_type = S21_NORMAL_VALUE;
  if (check_decimal_negate(decimal, &decimalResult) == 1) {
    s21_from_float_to_decimal(1.0, &decimalAccuracy);
    div_int_number(&decimal, &decimalAccuracy, &decimalResult, &decimalMod);
    if (sign) set_bit(&decimalResult, 127);
  }
  return decimalResult;
}
//  округление до ближайшего целого числа
s21_decimal s21_round(s21_decimal decimal) {
  s21_decimal decimalResult, decimalAccuracyOne, decimalMod;
  s21_decimal decimalModTemp;
  initialization_struct(&decimalResult);
  initialization_struct(&decimalMod);
  decimalMod.value_type = S21_NORMAL_VALUE;
  decimalAccuracyOne.value_type = S21_NORMAL_VALUE;
  decimalModTemp.value_type = S21_NORMAL_VALUE;
  if (check_decimal_negate(decimal, &decimalResult) == 1) {
    s21_from_int_to_decimal(1, &decimalAccuracyOne);
    s21_from_float_to_decimal(0.5, &decimalModTemp);
    decimalResult = s21_truncate(decimal);
    decimalMod = s21_mod(decimal, decimalAccuracyOne);
    convert_to_like_accuracy(&decimalModTemp, &decimalMod);
    if (check_bit(decimal, 127) == 1) remove_bit(&decimalMod, 127);
    if (s21_is_greater_or_equal(decimalMod, decimalModTemp) == 0) {
      if (check_bit(decimalResult, 127) == 0)
        decimalResult = s21_add(decimalResult, decimalAccuracyOne);
      else
        decimalResult = s21_sub(decimalResult, decimalAccuracyOne);
    }
  }
  return decimalResult;
}

s21_decimal s21_floor(s21_decimal decimal) {
  s21_decimal decimalResult, decimalAccuracy;
  initialization_struct(&decimalResult);
  initialization_struct(&decimalAccuracy);
  decimalAccuracy.value_type = S21_NORMAL_VALUE;
  if (check_decimal_negate(decimal, &decimalResult) == 1) {
    s21_from_int_to_decimal(1, &decimalAccuracy);
    decimalResult = s21_truncate(decimal);
    if (check_bit(decimalResult, 127) == 1)
      decimalResult = s21_sub(decimalResult, decimalAccuracy);
  }
  return decimalResult;
}
