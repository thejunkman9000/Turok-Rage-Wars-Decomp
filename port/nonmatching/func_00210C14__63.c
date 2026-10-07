#include "b02_types.h"

extern f32 D_800C70A0;
extern f32 D_800C70A4;
extern f32 D_800C70A8;
extern f32 D_800C70AC;
extern f32 D_800C70B0;
extern f32 D_800C70B4;
extern f32 D_800C70B8;
extern f32 D_800C70BC;
extern f32 D_800C70C0;
extern f32 D_800C70C4;
extern f32 D_800CDAF8[];
extern f32 D_800CDAF0[];

Vec3f *func_0020993C(B2Ctl *ctl);

void func_00210C14(B2Ctl *ctl) {
    f32 v;
    f32 *p1;
    f32 *p2;
    B2Ctl *c;
    s32 i;
    f32 fa, fb;
    Vec3f A;
    Vec3f B;
    Vec3f *r;

    v = ctl->owner->unk6C;
    v -= D_800C70A0;
    v += D_800C70A4;
    if (D_800C70A8 <= v) {
        do {
            v -= D_800C70A8;
        } while (D_800C70A8 <= v);
    }
    if (v < 0.0f) {
        do {
            v += D_800C70AC;
        } while (v < 0.0f);
    }
    if (D_800C70B0 < v) {
        v = D_800C70B0;
    }
    if (v < D_800C70B4) {
        v = D_800C70B4;
    }
    v = v * D_800C70B8;
    v = v * D_800C70BC;
    if (v < 0.0f) {
        v = 0.0f;
    }
    __asm__ volatile("" : : "f"(v));
    fa = D_800C70C0;
    fb = D_800C70C4;
    p1 = &D_800CDAF8[0];
    p2 = p1 - 2;
    c = ctl;
    for (i = 0; i < 8; i++) {
        r = func_0020993C(ctl);
        A = *r;
        r = func_0020993C(ctl);
        B = *r;
        A.x = A.x + *p2 * ((f32 *)((u8 *)c + 0x1D0))[0];
        A.y = A.y + fa;
        B.y = B.y + fa;
        A.z = A.z + *p1 * ((f32 *)((u8 *)c + 0x1D0))[0];
        r = func_0020993C(ctl);
        A = *r;
        r = func_0020993C(ctl);
        B = *r;
        A.x = A.x + *p2 * ((f32 *)((u8 *)c + 0x1F0))[0];
        A.y = A.y + fb;
        B.y = B.y + fb;
        A.z = A.z + *p1 * ((f32 *)((u8 *)c + 0x1F0))[0];
        p2 += 3;
        p1 += 3;
        c = (B2Ctl *)((u8 *)c + 4);
    }
}
