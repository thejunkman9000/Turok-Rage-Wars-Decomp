#include "o03_types.h"
typedef struct { u8 pad[0x5C]; s32 arr[1]; } O3Arr;
void func_0041B834(O3Arr *o, s32 i, s32 v) {
    o->arr[i] = v;
}
