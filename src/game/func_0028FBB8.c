#include "common.h"

void osSpTaskYield(void);

typedef struct { u8 pad0[4]; u32 flags; u8 pad8[8]; s32 state; } SpTask;
typedef struct { u8 pad0[0x2F4]; SpTask *task; } Obj;

void func_0028FBB8(Obj *o) {
    SpTask *t = o->task;
    if (t->state == 1) {
        t->flags |= 0x10;
        osSpTaskYield();
    }
}
