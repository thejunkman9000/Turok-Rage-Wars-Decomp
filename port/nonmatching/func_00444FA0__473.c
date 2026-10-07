#include "o06_types.h"
typedef struct { u8 pad[0x58]; void *unk58; } O06Q;
typedef struct { u8 pad[0x5DC]; O06Q *unk5DC; } O06P;
typedef struct { u8 pad[0x14]; char **unk14; } O06A;
typedef struct { u8 pad[0x1C]; O06P *unk1C; void *unk20; } O06B;
typedef struct { u8 pad[4]; s32 unk4; } O06O;
extern s32 func_0026437C(void *a);
extern s32 func_004424F4(O06A *a, O06B *b, s32 c);
extern u8 *func_0028B2D4();
extern s32 func_0044252C(O06B *a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern s32 func_00442158(O06A *a);
extern s32 sprintf(char *buf, const char *fmt, ...);
extern O06O *func_0028FD94();
extern u8 D_8011FE88[];
extern u8 D_800E27D0[];
extern s32 D_800E63AC;
extern s32 D_8011FEF4;
s32 func_00444FA0(O06A *a, O06B *b, s32 c, s32 type, s32 off, s32 step, s32 max, f32 div) {
    s32 v = 0;
    u8 *p;
    char *s;
    O06O *o;
    s32 k, n;
    void *t;
    u8 *q;
    if (func_0026437C(b->unk20)) return func_004424F4(a, b, c);
    if (b->unk1C != 0 && b->unk1C->unk5DC != 0 && b->unk1C->unk5DC->unk58 != 0) {
    p = func_0028B2D4(D_8011FE88) + off;
    switch (type) {
    case 0: v = *p; v = func_0044252C(b, v, step, 0, max, 1); *p = v; break;
    case 1: v = *(s32 *)p; v = func_0044252C(b, v, step, 0, max, 1); *(s32 *)p = v; break;
    case 2: v = func_0044252C(b, (s32)*(f32 *)p, step, 0, max, 1); *(f32 *)p = (f32)v; break;
    }
    s = *a->unk14;
    sprintf(s - 6 + func_00442158(a), D_800E27D0, (s32)((f32)v / div));
    if (D_800E63AC == 0) return 0;
    o = func_0028FD94(D_8011FEF4, 0);
    n = o->unk4;
    q = (u8 *)o + 8;
    for (k = 0; k < n; k++) {
        p = q + off;
        switch (type) {
        case 1: *(s32 *)p = v; break;
        case 0: *p = v; break;
        case 2: *(f32 *)p = (f32)v; break;
        }
        q += 0x64;
    }
    }
    return 0;
}
