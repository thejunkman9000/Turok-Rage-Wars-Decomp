#include "common.h"

typedef struct { u8 pad0[0x14]; s32 unk14; s32 unk18; } Obj;
void func_002537D8(s32 a, s32 b);

void func_0028DA50(Obj *o) {
    s32 v = o->unk14;
    if (v != 0) {
        func_002537D8(0, v);
        o->unk14 = 0;
        o->unk18 = -1;
    }
}
