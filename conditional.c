#include "conditional.h"

int ternary(int cond, int iftrue,  int elsefalse) {
  int mask = 0 - cond;
  return (iftrue & mask) | (elsefalse & ~mask);
   
}

