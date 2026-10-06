#include "common.h"
typedef struct { u8 pad0[0xAC]; s32 *unkAC; } Obj;

void *func_0028E74C(Obj *o, s32 idx) {
    s32 *p = o->unkAC;
    return (u8 *)p + (idx * p[0] + 8);
}
