#include "b09_types.h"

typedef struct B09Pair { s32 a, b; } B09Pair;

void func_002405EC(B09Pair *x, B09Pair *y) {
    B09Pair t = *x;
    *x = *y;
    *y = t;
}
