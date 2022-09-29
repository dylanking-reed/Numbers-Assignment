#include "conditional.h"
#include <stdio.h>
#include <assert.h>

int dbg(int a) {
  printf("%d", a);
  return a;
}

void conditional_test() {
  printf("Running test: conditional_test ... ");
  /* assertions */
  assert(ternary(0, 3, 16) == 16);
  assert(ternary(1, 16, 3) == 16);
  printf("PASSED\n");
}

int main(void) {
  printf("Testing...\n");
  /* tests */
  conditional_test();
  printf("Tests passed.\n");
  return 0;
}
