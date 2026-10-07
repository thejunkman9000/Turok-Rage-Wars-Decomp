#include "p4_types.h"
typedef struct { u8 pad0[0x4C]; s32 f4C; s32 f50; s32 f54; s32 f58; } P4Cur;
void func_002A2B24(P4Cur *o, s32 idx);
void func_002A2D14(P4Cur *o) {
    if (o->f54 == 0) {
        if (o->f58 > o->f50) {
            func_002A2B24(o, o->f58 - 1);
        }
    } else {
        if (o->f58 == o->f50) {
            o->f58 = o->f4C;
        } else {
            o->f58 = o->f58 - 1;
        }
        func_002A2B24(o, o->f58);
    }
}
