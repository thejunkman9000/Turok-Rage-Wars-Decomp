#include "b12_types.h"

extern u8 D_800C8F4C[];
extern u8 D_800C8F70[];
extern u8 D_800C8F84[];
s32 **func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *g, void *h, s32 i);
void func_00253610(s32 a, s32 b);
void func_002537D8(s32 a, s32 **n);
s32 **func_00254094(s32 unused, s32 **out, s32 id, void *arg3, s32 arg4);
s32 func_0028FE08(s32 a, s32 b, s32 c);
s32 func_0028FE1C(s32 *a, s32 b, s32 c, void *d);
void func_0026D7D4(void);

s32 **func_00250754(B12Obj *o, s32 key) {
    s32 **h;
    s32 **n;
    s32 *out;
    s32 s2;
    if (o->unkB4) {
        func_00253610(0, o->unkB4);
        return (s32 **)o->unkB4;
    }
    if (key != o->unkA8) {
        h = func_002518DC(0, o->unk1C, o->unk1C, 0x18, 0, 0, 0, D_800C8F4C, 1);
        if (h) {
            s2 = func_0028FE08((s32)*h, o->unk1C, 1);
            func_002537D8(0, h);
            n = func_00254094(0, &out, s2, D_800C8F70, 1);
            if (n) {
                o->unkAC = func_0028FE1C(out, s2, key % *out, &o->unkB0);
                o->unkA8 = key;
                func_002537D8(0, n);
            }
        }
    }
    if (o->unkAC != 0) {
        return func_002518DC(0, o->unkAC, o->unkAC, o->unkB0, 0, 0, (void *)func_0026D7D4, D_800C8F84, 0);
    }
    return 0;
}
