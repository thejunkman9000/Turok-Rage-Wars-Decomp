#include "b03_types.h"
extern EntList D_8013B364[];
extern f32 D_800C7030;
Vec3f *func_0020993C(BrainB *b);
s32 func_002099B4(BrainB *b, ActorB *t);
EntRec *func_0020C994(EntList *list, s32 key);
void func_0020DC10(BrainB *b);
f32 func_00272768(Vec3f *a, EntRec *b);
s32 func_00210178(BrainB *b) {
    Vec3f *from;
    if (b->unk64 == NULL) {
        return 1;
    }
    if (func_002099B4(b, b->unk64) != 0) {
        func_0020DC10(b);
    }
    if (b->unkC == -1) {
        return 1;
    }
    from = func_0020993C(b);
    if (func_00272768(from, func_0020C994(D_8013B364, b->unkC)) < D_800C7030) {
        func_0020DC10(b);
    }
    return 1;
}
