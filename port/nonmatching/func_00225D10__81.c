#include "b06_types.h"

void func_002227D0(Plr *a, Plr *b, s32 c);
void func_002231B0(Plr *a, Plr *b, u8 *c);
void func_00274090(f32 *p);
extern f32 D_800C7BD0;
extern f32 D_800C7BD4;
extern f32 D_800C7BD8;
extern f32 D_800C7BDC;
extern f32 D_800C7BE0;
extern f32 D_800D2988;
extern u8 D_800CE7E4[];

void func_00225D10(Plr *a, Plr *b) {
    Vec3f p;
    f32 s0;
    f32 s1;
    f32 n;
    f32 d1;
    f32 d2;
    f32 r;
    func_002231B0(a, b, D_800CE7E4);
    if (a->unk7FC != NULL) {
        a->unk7F4 = a->unk7F4 + D_800D2988;
        s0 = a->unk6C;
        s1 = a->unk7F8;
        if (s1 != s0) {
            func_00274090(&s0);
            func_00274090(&s1);
            if (s0 > s1) {
                n = s1 + D_800C7BD0;
                d1 = s0 - s1;
                d2 = n - s0;
            } else {
                n = s1 - D_800C7BD4;
                d1 = s1 - s0;
                d2 = s0 - n;
            }
            if (d2 < d1) {
                s1 = n;
            }
            if (s1 > s0) {
                s0 = s0 + (s1 - s0) * D_800C7BD8;
                if (s1 < s0) {
                    s0 = s1;
                }
            } else {
                s0 = s0 - (s0 - s1) * D_800C7BDC;
                if (s0 < s1) {
                    s0 = s1;
                }
            }
            func_00274090(&s0);
        }
        a->unk354 = s0;
        a->unk6C = s0;
        n = (f32)(a->unk7FC->unk5E * 15);
        if (a->unk7F4 < n) {
            r = a->unk7F4 / n;
            p.x = a->unk800 + (a->unk7FC->unk34 - a->unk800) * r;
            p.z = a->unk808 + (a->unk7FC->unk3C - a->unk808) * r;
            p.y = a->unk804 + (a->unk7FC->unk38 - a->unk804) * r + a->unk7FC->unk40 * ((r - r * r) * D_800C7BE0);
            a->unk6E8 = p;
            return;
        }
    }
    func_002227D0(a, b, 2);
}
