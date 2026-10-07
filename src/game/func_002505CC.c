#include "b12_types.h"

extern u8 D_800C8F4C[];
extern u8 D_800C8F60[];
s32 **func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, void *h, s32 i);
s32 func_0028FE1C(s32 *a, s32 b, s32 c, s32 *d);
void func_002536F4(s32 a, s32 **n);
void func_00272908(void *a, void *b, P3Vec3 *out);

typedef struct B12Pair { s32 a; s32 b; } B12Pair;

typedef struct B12Rec {
    u8 pad0[2];
    u16 unk2;
    u8 pad4[4];
    u8 unk8[0xC];
    B12Pair tail;
} B12Rec;

void func_00265E30(B12Obj *a, B12Obj *b, s32 c, s32 d, P3Vec3 e, B12Pair f);

void func_002505CC(B12Obj *o, s32 flag) {
    s32 **h;
    s32 **n;
    s32 *base;
    s32 r;
    s32 sp38;
    P3Vec3 v;
    B12Rec *p;
    s32 i;
    s32 cnt;
    h = func_002518DC(0, o->unk1C, o->unk1C, 0x18, 4, 0, 0, D_800C8F4C, 0);
    if (h) {
        r = func_0028FE1C(*h, o->unk1C, 3, &sp38);
        n = func_002518DC(0, r, r, sp38, 0, 0, 0, D_800C8F60, 0);
        if (n) {
            base = *n;
            cnt = base[1];
            p = (B12Rec *)(base + 2);
            for (i = 0; i < cnt; i++) {
                if (flag || p[i].unk2 == 8) {
                    func_00272908((u8 *)o + 0x68, p[i].unk8, &v);
                    func_00265E30(o, o, p[i].unk2, -1, v, p[i].tail);
                }
            }
            func_002536F4(0, n);
        }
        func_002536F4(0, h);
    }
}
