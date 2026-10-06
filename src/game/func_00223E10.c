#include "b05_types.h"

typedef struct B05P9 {
    u8 pad0[0x18];
    /* 0x018 */ void* def;
    u8 pad1C[0x63C];
    /* 0x658 */ f32 f658;
    u8 pad65C[0xCC];
    /* 0x728 */ f32 f728;
    /* 0x72C */ f32 f72C;
    /* 0x730 */ f32 f730;
    /* 0x734 */ f32 f734;
    /* 0x738 */ f32 f738;
    /* 0x73C */ f32 f73C;
    /* 0x740 */ f32 f740;
    /* 0x744 */ f32 f744;
    u8 pad748[0x10];
    /* 0x758 */ f32 f758;
    /* 0x75C */ f32 f75C;
    u8 pad760[0xA78];
    /* 0x11D8 */ f32 f11D8;
} B05P9;

typedef struct B05Def9 { u8 pad0[0xF4]; f32 unkF4; } B05Def9;
typedef struct B05S9 { u8 pad0[0x6C]; f32 ang; } B05S9;

extern const f32 D_800C7A04;
extern f32 D_800C7A08;
extern f32 D_800C7A0C;
extern f32 D_800C7A10;
extern f32 D_800C7A14;
extern f32 D_800C7A18;
extern f32 D_800C7A1C;
extern f32 D_800C7A20;
extern f32 D_800C7A24;
extern f32 D_800C7A28;
extern const f32 D_800C7A2C;
extern f32 D_800C7A30;
extern const f32 D_800C7A34;

f32 sinf(f32);
f32 cosf(f32);
f32 func_00274810(f32, f32);
void func_002748E0(void *, f32, f32);

void func_00223E10(B05P9 *p, B05S9 *s) {
    f32 ang;
    f32 base;
    f32 r;

    if (!(p->f11D8 > 0.0f)) {
        func_002748E0(&p->f72C, 0.0f, 0.25f);
        func_002748E0(&p->f728, 0.0f, 0.5f);
        p->f730 = func_00274810(p->f730, D_800C7A04);
        p->f734 = func_00274810(p->f734, D_800C7A04);
        p->f738 = func_00274810(p->f738, D_800C7A04);
        if (p->f75C > D_800C7A08) {
            p->f75C = D_800C7A08;
        }
        if (p->f758 > D_800C7A0C) {
            p->f758 = D_800C7A0C;
        }
        p->f75C = func_00274810(p->f75C, D_800C7A10);
        p->f758 = func_00274810(p->f758, D_800C7A14);
        if (p->f758 < D_800C7A18) {
            p->f758 = 0.0f;
            p->f75C = 0.0f;
        }
        ang = p->f658 * p->f75C * D_800C7A1C;
        if (p->def != NULL) {
            base = ((B05Def9 *)p->def)->unkF4 * D_800C7A20;
        } else {
            base = D_800C7A24;
        }
        func_002748E0(&p->f740, base + p->f758 * (sinf(ang) * D_800C7A28), D_800C7A2C);
        r = p->f758 * (cosf(ang) * D_800C7A30);
        func_002748E0(&p->f73C, -sinf(s->ang + D_800C7A34) * r, D_800C7A2C);
        func_002748E0(&p->f744, -cosf(s->ang + D_800C7A34) * r, D_800C7A2C);
    }
}
