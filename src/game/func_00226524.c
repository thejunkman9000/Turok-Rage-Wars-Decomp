#include "b06_types.h"

void func_002231B0(Plr *a, Plr *b, u8 *c);
void func_0021CF04(u8 *a, Plr *p, Plr **out, u8 *b);
f32 func_00272768(Vec3f *a, Vec3f *b);
s32 func_00244494(Plr *a, Vec3f from, Vec3f to, u8 *p);
void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
f32 func_00271B18(Vec3f *v);
void func_00274090(f32 *p);
void func_002748E0(f32 *p, f32 v, s32 s);
extern u8 D_800CE7E4[];
extern f32 D_800C7C3C;
extern f32 D_800C7C40;
extern f32 D_800C7C44;
extern f32 D_800C7C48;
extern f32 D_800C7C4C;
extern f32 D_800C7C50;
extern f32 D_800C7C54;
extern s32 D_800CF230;
extern Plr **D_80103FCC;
extern u8 D_80103FD0[];

void func_00226524(Plr *a, Plr *b) {
    u8 buf20[0x10];
    u8 buf30[0x10];
    Vec3f v40;
    Plr *t;
    f32 ang;
    f32 d;
    func_002231B0(a, b, D_800CE7E4);
    if (a->unk1210 != 0) {
        func_0021CF04(buf20, a, &t, buf30);
        if (t != NULL) {
            d = func_00272768(&a->pos, &t->pos);
            if (!(D_800C7C3C < d)) {
                if (func_00244494(a, a->pos, t->pos, D_80103FD0) == 0 || *D_80103FCC == t) {
                    func_00271FD8(&v40, &t->pos, &a->pos);
                    ang = func_00271B18(&v40);
                    func_00274090(&ang);
                    func_00274090(&b->unk6C);
                    if (b->unk6C > D_800C7C40 && ang < D_800C7C44) {
                        ang += D_800C7C48;
                    } else if (ang > D_800C7C4C && b->unk6C < D_800C7C50) {
                        b->unk6C += D_800C7C54;
                    }
                    func_002748E0(&b->unk6C, ang, D_800CF230);
                }
            }
        }
    }
}
