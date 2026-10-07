#include "b11_types.h"

s32 *func_0024BFC4(Obj *a, s32 b);
B11Node *func_0028FD94(s32 node, s32 idx);
void func_002536F4(s32 a, void *p);

s32 func_0024BE70(Obj *a) {
    s32 r = -1;
    s32 *p = func_0024BFC4(a, a->unk1);
    if (p != 0) {
        r = func_0028FD94(*p, 5)->unk6E;
        func_002536F4(0, p);
    }
    return r;
}
