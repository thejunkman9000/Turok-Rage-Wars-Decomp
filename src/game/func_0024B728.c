#include "b11_types.h"

void func_002798CC(void *buf);
void func_002798D4(void *buf, s32 a, s32 b);
s32 func_00279918(void *buf);
s32 func_002469F8(Obj *a, s16 b, s32 c);

s16 func_0024B728(Obj *a, s16 *p, s32 c) {
    u8 buf[0x68];
    func_002798CC(buf);
    while (*p != -1) {
        if (func_002469F8(a, *p, c) != -1) {
            func_002798D4(buf, p[0], p[1]);
        }
        p += 2;
    }
    return func_00279918(buf);
}