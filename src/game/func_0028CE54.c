#include "common.h"
typedef struct { u8 pad0[0xA4]; s32 *unkA4; } Obj;

void *func_0028CE54(Obj *o, s32 idx) {
    s32 *p = o->unkA4;
    return (u8 *)p + (idx * p[0] + 8);
}
