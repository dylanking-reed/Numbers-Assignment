#ifndef TINYFLOAT_H
#define TINYFLOAT_H
#include <stdint.h>
typedef uint8_t tinyfloat;

tinyfloat add_tf(tinyfloat rhs, tinyfloat lhs);

tinyfloat mul_tf(tinyfloat rhs, tinyfloat lhs);
#endif
