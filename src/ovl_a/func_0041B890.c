#include "o03_types.h"
typedef struct { s16 pad0[6]; s16 id; } O3ItemS;
typedef struct { u8 pad[0x4C]; O3ItemS *arr[1]; } O3ArrS;
s32 func_0041B890(O3ArrS *o, s32 i) {
    return o->arr[i]->id;
}
