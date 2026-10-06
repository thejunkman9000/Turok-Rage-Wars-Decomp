#include "b10_types.h"

void func_00243804(B10Pair *a, B10Pair *b) {
    B10Pair t = *a;
    *a = *b;
    *b = t;
}
