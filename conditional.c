#include "conditional.h"

int ternary(int cond, int iftrue,  int elsefalse) {
  int mask = 0 - (cond && 1);
  return (iftrue & mask) | (elsefalse & ~mask);
   
}

