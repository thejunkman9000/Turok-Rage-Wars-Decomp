#include "common.h"

typedef struct B21Obj10 {
    u8 pad0[0x10];
    s32 unk10;
} B21Obj10;

s32 func_00263174(B21Obj10 *o, s32 a);

s32 func_00297578(B21Obj10 *o) {
    return o->unk10 == 2 ? func_00263174(o, 1) != 0 : o->unk10 == 1;
}
