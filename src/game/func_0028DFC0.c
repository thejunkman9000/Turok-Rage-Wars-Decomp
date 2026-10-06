#include "p4_types.h"
typedef struct { s32 a, b; } P4Pair;
void func_0028DFC0(P4Pair *a, P4Pair *b) {
    P4Pair t = *a;
    *a = *b;
    *b = t;
}
