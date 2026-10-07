#include "b09_types.h"
extern f32 D_800C87B4;

void func_0023E680(B09Range *r, f32 a, s32 id, f32 b, f32 c) {
    f32 hi;
    r->id = id;
    r->a = a;
    r->b = b;
    r->c = c;
    hi = b;
    if (!(a <= hi)) hi = a;
    r->hi = hi + D_800C87B4;
}
