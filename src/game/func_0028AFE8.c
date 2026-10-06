#include "common.h"
typedef struct { u8 pad0[0xA0]; s32 *unkA0; } Obj;

void *func_0028AFE8(Obj *o, s32 idx) {
    s32 *p = o->unkA0;
    return (u8 *)p + (idx * p[0] + 8);
}
