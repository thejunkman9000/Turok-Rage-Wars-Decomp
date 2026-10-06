#include "p4_types.h"
extern s32 D_801450B8[];
extern s32 D_800D297C;
void func_00272908(void *a, void *b, f32 *out);
void func_0027DD1C(void *a, void *b, void *c, f32 d);
void func_0028414C(u8 *o) {
    void *owner;
    f32 v[3];
    f32 y;
    s32 *p = D_801450B8;
    if (p[0] == 1) {
        owner = (void *)p[-4];
        func_00272908((u8 *)owner + 0x220, o + 8, v);
        y = v[2];
        if (y < 0.0f) {
            y = -y;
        }
        func_0027DD1C(o, o + 0x60 + D_800D297C * 0x40, owner, y);
    } else {
        func_0027DD1C(o, o + 0x60 + D_800D297C * 0x40, NULL, 0.0f);
    }
    *(s32 *)(o + 0x5C) |= 0x100000;
}
