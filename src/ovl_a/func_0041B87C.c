#include "o03_types.h"
typedef struct { u8 pad[0x4C]; void *arr[1]; } O3Arr;
void *func_0041B87C(O3Arr *o, s32 i) {
    return o->arr[i];
}
