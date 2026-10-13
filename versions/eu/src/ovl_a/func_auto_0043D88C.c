#include "common.h"
typedef struct { u8 pad[0x20]; s32 f20; } Q4O;
typedef struct { s32 cur; f32 timer; s32 len; u8 text[24]; } Q4T;
typedef struct { u8 pad[4]; f32 f4; } Q4E;
typedef struct { u8 pad[0x14]; s32 f14; u8 pad18[8]; s32 f20; } Q4B;
typedef struct { u8 pad[0x30]; f32 f30; f32 f34; } Q4D;
extern Q4T D_auto_800F22C0;
extern s32 D_auto_800EEEF0;
extern s32 D_auto_800F24E0;
extern Q4E *func_auto_00443D14();
extern void func_002AB9E4(void);
extern void func_002A8DD4(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern void func_auto_00442FA4();

void func_auto_0043D88C(void *a0, Q4B *a1, void *a2, Q4D *a3) {
    f32 w;
    f32 t;
    f32 x;
    f32 t2;
    f32 alpha;
    s32 xi;
    f32 pa, pb;
    if (D_auto_800F22C0.timer <= 6.0f) {
        w = func_auto_00443D14(a0, 0)->f4;
        w = w * (f32)D_auto_800EEEF0;
        w = w * 0.0035211267f;
        t = a3->f34 * 128.0f;
        pa = (f32)D_auto_800F22C0.cur; pa = pa * w; pb = (f32)a1->f14; x = pb + pa;
        D_auto_800F24E0 = -1;
        alpha = a3->f30 * t;
        xi = (s32)x;
        func_002AB9E4();
        func_002A8DD4(xi, a1->f20, (s32)((f32)xi + w), a1->f20 + 2, 0, 0, 0xFF, 0xFF, 0xFF, (u32)alpha & 0xFF);
    }
    func_auto_00442FA4(a0, a1, a2, a3);
}
