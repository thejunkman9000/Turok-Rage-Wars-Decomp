#include "b11_types.h"

s32 func_002469F8(Obj *a, s32 b, s32 c);
s32 func_0024B6E4(Obj *a, s32 b, s32 c);

s32 func_0024B690(Obj *a, s32 b, s32 c) {
    s32 r = func_002469F8(a, b, -1);
    if (r != -1) {
        return func_0024B6E4(a, r, c);
    }
    return 0;
}
