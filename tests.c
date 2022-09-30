#include "conditional.h"
#include "logical-negation.h"
#include <stdio.h>
#include <assert.h>

int dbg(int a) {
  printf("DBG: %d\n", a);
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

int main(void) {
  printf("Testing...\n");
  /* tests */
  conditional_test();
  logical_negation_test();
  printf("Tests passed.\n");
  return 0;
}
