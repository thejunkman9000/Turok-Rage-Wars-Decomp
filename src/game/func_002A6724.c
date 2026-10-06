#include "b23_types.h"

typedef struct Big6A90 {
    u8 pad0[0x6A90];
    s32 unk6A90;
} Big6A90;

void func_002795C0(s32 *p, s32 v);
void func_00279578(u8 *p, s32 v);

s32 func_002A6724(Big6A90 *o, u8 *p) {
    s32 v = o->unk6A90;

    if (v != 0) {
        func_002795C0(&o->unk6A90, v);
        func_00279578(p + 0x40, v);
    }
    return v;
}
