#include "p1_types.h"
void *func_0025C97C(s32 a, s32 b, Vec3f *c, Vec3f *d, void *e);
void func_0025CA44(s32 a, SndHandle *h);
s32 func_0025CC8C();
void func_002172D0(SndSrc *src, SndOwner *owner, s32 id) {
    void *s0 = (void *)-1;
    if (owner->unkFC != NULL) {
        if (owner->unkFC->unkC == id) {
            return;
        }
        func_0025CA44(func_0025CC8C(), owner->unkFC);
    }
    switch (src->type) {
    case 1:
    case 2:
        s0 = src;
        break;
    case 0:
        s0 = src->unkD0;
        break;
    }
    owner->unkFC = func_0025C97C(func_0025CC8C(), id, &src->pos, &src->pos, s0);
}
