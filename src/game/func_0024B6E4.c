#include "b11_types.h"

void func_0024B64C(Obj *a, s32 b);

s32 func_0024B6E4(Obj *a, s32 b, s32 c) {
    if (b < 0 || (c == 0 && (a->flags & 0x400))) {
        return 0;
    }
    func_0024B64C(a, b);
    return 1;
}
