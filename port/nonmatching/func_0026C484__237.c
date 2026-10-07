/* PARTIAL (10 words): only sll/addiu order + 2 regs of the D_80110640 post-increment (ROM: sll first, addiu in place) */
#include "b15_types.h"

typedef struct B15Rec {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} B15Rec;

s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void (*cb)(), void *tab, s32 g);
void func_00253610(s32 a, s32 *p);
void func_002536F4(s32 a, s32 *p);
s32 *func_00254094(s32 a, s32 **out, s32 b, void *tab, s32 c);
void func_0026BC60();
void func_0026D7F4();
s32 func_0028FD94(s32 *p, s32 i);
s32 func_0028FE08(s32 a, s32 b, s32 c);
s32 func_0028FE1C(s32 *a, s32 b, s32 c, s32 *out);
extern u8 D_800C975C[];
extern u8 D_800C9770[];
extern u8 D_800C9784[];
extern s32 D_80110624;
extern s32 D_80110640;
extern s32 *D_8011064C;
extern s32 D_801153D0;
extern s32 *D_801153D8[];
extern B15Rec D_801157D8[];

void func_0026C484(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 *sp28;
    s32 sp2C;
    s32 *t;
    s32 *u;
    s32 *v;
    s32 x;
    s32 y;
    s32 z;
    B15Rec *rec;

    t = func_002518DC(0, a0, a0, 0x18, 0, 0, NULL, D_800C975C, 1);
    if (t != NULL) {
        x = func_0028FE08(*t, a0, 1);
        func_002536F4(0, t);
        u = func_00254094(0, &sp28, x, D_800C9770, 1);
        if (u != NULL) {
            y = func_0028FE1C(sp28, x, a3 % *sp28, &sp2C);
            func_002536F4(0, u);
            v = func_002518DC(0, y, y, sp2C, 0, 0, func_0026D7F4, D_800C9784, a5);
            if (v != NULL) {
                z = func_0028FD94((s32 *)*v, 0);
                if (D_8011064C != v || D_80110624 != a4 || D_80110640 == 0x20) {
                    func_0026BC60();
                    if (D_801153D0 == 0x100) {
                        goto done;
                    }
                    func_00253610(0, v);
                    D_801153D8[D_801153D0] = v;
                    D_801153D0++;
                }
                D_8011064C = v;
                D_80110624 = a4;
                rec = &D_801157D8[D_80110640++];
                rec->a = a1;
                rec->d = 0;
                rec->b = a2;
                rec->c = z;
            done:
                func_002536F4(0, v);
            }
        }
    }
}
