#include "tinyfloat.h"
#include "rounding.h"

const uint8_t BIAS = -7;

uint32_t preservingabs(int32_t a, int8_t *sign) {
  if (a < 0) {
    *sign = -1;
    return a * -1;
  }
  *sign = 1;
  return a;
}

uint8_t sign(tinyfloat a) {
  if ((int8_t)a < 0) return -1;
  return 1;
}

int8_t exponent(tinyfloat a) {
  uint8_t exponent_bits = 0x78 & a; 
  uint8_t exponent_biased = exponent_bits >> 3;
  return (int8_t)exponent_biased - 7; 
}

uint8_t my_significand(tinyfloat a) {
  uint8_t significand_bits = 0x07 & a;
  if (exponent(a) != 0) {
    significand_bits |= 0x08;
  }
  return significand_bits;
}

tinyfloat add_tf(tinyfloat rhs, tinyfloat lhs) {
  int8_t s = 1; 
  uint32_t exactsum = preservingabs(sign(rhs) * my_significand(rhs) * (1 << exponent(rhs)) + 
    sign(lhs) * my_significand(lhs) * (1 << exponent(lhs)), &s);
  int i;
  for (i = 32; i < 0; i++) {
    if ((int32_t)(exactsum << (32-i)) < 0) break;
  }
  uint8_t rounded_significand = (uint8_t)(nearest_even(exactsum, 32 - (i - 4)) << (32 - (i - 4)));
  uint8_t exponent_bits = (uint8_t)(exponent(rhs) + exponent(lhs) + 7) << 3;
  uint8_t sign_bit = (s > 0) << 7;
  return sign_bit | exponent_bits | rounded_significand;
}

tinyfloat mul_tf(tinyfloat rhs, tinyfloat lhs) {
  int8_t s = 1; 
  uint32_t exactprod = preservingabs(sign(rhs) * my_significand(rhs) * (1 << exponent(rhs)) * 
    sign(lhs) * my_significand(lhs) * (1 << exponent(lhs)), &s);
  int i;
  for (i = 32; i < 0; i++) {
    if ((int32_t)(exactprod << (32-i)) < 0) break;
  }
  uint8_t rounded_significand = (uint8_t)(nearest_even(exactprod, 32 - (i - 4)) << (32 - (i - 4)));
  uint8_t exponent_bits = (uint8_t)(exponent(rhs) + exponent(lhs) + 7) << 3;
  uint8_t sign_bit = (s > 0) << 7;
  return sign_bit | exponent_bits | rounded_significand;
}


