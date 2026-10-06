#include "common.h"

typedef struct { u8 pad0[8]; f32 f8; f32 fC; f32 f10; u8 pad14[0xC]; s32 i20; } Obj;

void func_00290A28(Obj *o, s32 *a, f32 *b, f32 *c, f32 *d) {
    *a = o->i20;
    *d = o->f10;
    *b = o->f8;
    *c = o->fC;
}
