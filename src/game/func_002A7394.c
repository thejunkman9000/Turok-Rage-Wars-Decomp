#include "b24_types.h"

extern f32 D_800CB050;
extern f32 D_800CB054;
void func_00270980(void *, s32);
void func_00272898(void *);
void func_002734EC(void *, f32, f32, f32);
void func_002A35C0(s32, Emit *, void *);

void func_002A7394(s32 a, Emit *e, EmitOwner *own, s32 d) {
    u8 m[0x40];
    f32 s;
    if (e->owner == own && e->unk24 > 0.0f) {
        func_00270980(m, d);
        s = D_800CB050;
        if (own->info->unk14 != 0) {
            s = D_800CB054;
        }
        func_002734EC(m, s, s, s);
        func_00272898(m);
        func_002A35C0(a, e, m);
    }
}
