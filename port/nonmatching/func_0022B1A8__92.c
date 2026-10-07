#include "b06_types.h"

void func_0025DF54(s32 a);
void func_00237E70(u8 *a, Pawn *p, char *s);
void func_00273208(f32 *m, Vec3f *v);
void func_0027200C(f32 *out, Vec3f *v, f32 s);
void func_00271FA4(f32 *out, f32 *a, Vec3f *b);
void func_002734B8(f32 *m, f32 x, f32 y, f32 z);
void func_00273DDC(f32 *m);
void func_002702EC(f32 *m, u8 *dst);
extern f32 D_800C7DFC;
extern char *D_800D7148;
extern char *D_800D714C;
extern char *D_800D7150;
extern u8 D_80145088[];

void func_0022B1A8(Plr *a, s32 b) {
    f32 m[16];
    f32 t[3];
    char *s;
    if (a->unk147C != 0) {
        if (a->unk11FC > 0.0f) {
            a->unk11FC = 0.0f;
            func_0025DF54(0x578);
            if (a->unk5DC != NULL) {
                func_00237E70(D_80145088, a->unk5DC, D_800D7148);
            }
        } else {
            a->unk11FC = D_800C7DFC;
            a->unk1200 = a->unk1458;
            a->unk120C = b;
            func_00273208(m, &a->unk1470);
            func_0027200C(t, &a->unk1470, 5.12f);
            func_00271FA4(t, t, &a->unk1200);
            func_002734B8(m, t[0], t[1], t[2]);
            func_00273DDC(m);
            func_002702EC(m, (u8 *)a + 0x1600);
            func_0025DF54(0x578);
            if (a->unk5DC != NULL) {
                if (b != 0) {
                    s = D_800D714C;
                } else {
                    s = D_800D7150;
                }
                func_00237E70(D_80145088, a->unk5DC, s);
            }
        }
    }
}
