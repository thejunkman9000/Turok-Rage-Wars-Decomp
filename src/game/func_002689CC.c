#include "b15_types.h"
typedef struct B15A {
    u8 pad0[0x100];
    u32 flags;
    u8 pad104[0x6C];
    u32 unk170;
} B15A;
void func_00217388(B15A *a, void *p);
void func_00262CA8(B15A *a);
void func_002689CC(B15A *a, s32 b, s32 c, Vec3f pos) {
    func_00217388(a, &a->unk170);
    a->unk170 |= 0x20;
    a->flags &= ~0x10000;
    a->flags &= ~0x2000;
    a->flags &= ~0x100;
    if (a->flags & 0x80000) {
        func_00262CA8(a);
    }
}
