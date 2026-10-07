#include "b05_types.h"

typedef struct B05P8 {
    u8 pad0[0x29C];
    /* 0x29C */ f32 f29C;
    /* 0x2A0 */ f32 f2A0;
    /* 0x2A4 */ f32 f2A4;
    /* 0x2A8 */ f32 f2A8;
    u8 pad2AC[0x94];
    /* 0x340 */ f32 f340;
    /* 0x344 */ f32 f344;
    /* 0x348 */ f32 f348;
    /* 0x34C */ f32 f34C;
} B05P8;

extern f32 D_800C74C4;
extern f32 D_800C74C8;
extern f32 D_800C74CC;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern u8 D_801462E5;

void func_00239234(B05P8 *, f32 *, f32 *);
void func_002ABC18(s32, s32, s16, s16, f32, f32, s32);

void func_0021E068(B05P8 *p, Vec3f *v, s32 id, f32 a3, f32 a4, f32 a5) {
    f32 sx;
    f32 sy;
    f32 t0;
    f32 t1;
    f32 k;
    f32 d;

    if (id == 0x2DA) goto spec;
    if (id == 0x2E4) goto spec;
    if (id == 0x2BC) goto spec;
    if (id == 0x2EF) goto spec;
    if (id == 0x2F0) goto spec;
    if (id == 0x2F1) goto spec;
    if (id == 0x2F2) {
spec:
        t0 = p->f29C * D_800C74C4;
        t1 = p->f2A0;
        k = D_800C74C4;
        goto join;
    }
    if (p->f340 * v->x + p->f344 * v->y + p->f348 * v->z <= p->f34C) {
        func_00239234(p, &sx, &sy);
        if (!(sx < D_800C74C8) && !((f32)(D_800E28D0 + 0x40) < sx) &&
            !(sy < D_800C74C8) && !((f32)(D_800E28D4 + 0x40) < sy)) {
            if (D_801462E5 != 0) {
                t0 = sx / (f32)D_800E28D0 * p->f29C;
                t1 = sy / (f32)D_800E28D4;
                k = p->f2A0;
join:
                sx = p->f2A4 + t0;
                sy = p->f2A8 + t1 * k;
            }
            d = a4 * a5 - D_800C74CC;
            func_002ABC18(id, (s32)a3, (s16)(s32)(sx - d), (s16)(s32)(sy - d), a5, a5, 1);
        }
    }
}
