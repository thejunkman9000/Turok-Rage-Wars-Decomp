#include "b24_types.h"

typedef struct Obj24 {
    u8 pad0[0x14];
    s32 unk14;
    u8 pad18[0x184];
    u16 unk19C;
    u8 pad19E[0x32];
    u32 unk1D0;
} Obj24;

extern u8 D_8011FE88[];
s32 func_0024E914(Obj24 *);
void func_00278E74(s32, s32, void *);
void func_0028B874(u8 *, Obj24 *, s32);
void func_00290528(Obj24 *, Obj24 *);
s32 func_002AC6DC(void *, Obj24 *, s32);

void func_002ADA44(void *a, Obj24 *o) {
    u16 v;
    if (o->unk19C & 8) {
        if (!(o->unk1D0 & 1)) {
            return;
        }
    } else {
        if (o->unk19C & 1) {
            return;
        }
    }
    if (func_002AC6DC(a, o, func_0024E914(o)) != 0) {
        v = o->unk19C | 1;
        o->unk19C = v;
        if (v & 8) {
            func_00290528(o, o);
            return;
        }
        func_0028B874(D_8011FE88, o, 1);
        func_00278E74(o->unk14, 0x400, a);
    }
}


