#include "conditional.h"
#include "logical-negation.h"
#include "tinyfloat.h"
#include <stdio.h>
#include <assert.h>

int dbg(int a) {
  printf("DBG: %d\n", a);
  return a;
}

int xdbg(int a) {
  printf("DBG: 0x%08x\n", a);
  return a;
}

void conditional_test() {
  printf("Running test: conditional_test ... ");
  /* assertions */
  assert(ternary(0, 3, 16) == 16);
  assert(ternary(1, 16, 3) == 16);
  printf("PASSED\n");
}

void logical_negation_test() {
  printf("Running test: logical_negation_test ... ");
  /* assertions */
  assert(lnot(1) == 0);
  assert(lnot(0) == 1);
  assert(lnot(15) == 0);
  printf("PASSED\n");
}

void tinyfloat_test() {
  printf("Running test: tinyfloat_test ... ");
  /* assertions */
  assert(xdbg(add_tf(0b00111000, 0b01000000)) == 0b01000100);
  assert(xdbg(add_tf(0b00111000, 0b01000100)) == 0b01001000);
  printf("PASSED\n");
}

int main(void) {
  printf("Testing...\n");
  /* tests */
  conditional_test();
  logical_negation_test();
  tinyfloat_test();
  printf("Tests passed.\n");
  return 0;
}
