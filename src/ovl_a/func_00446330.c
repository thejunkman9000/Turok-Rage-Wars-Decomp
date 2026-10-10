/* func_00446330 (real entry 0x446330, one stray word before) inlines func_004467D8; returns void */
#include "o06_types.h"
typedef struct { u8 pad[0x30]; u32 unk30; u8 pad2[0x24]; u32 unk58; u8 pad3[0x24]; u32 unk80; u8 pad4[0x24]; u32 unkA8; } O06B;
typedef struct { u8 pad[0xC]; O06B *unkC; u8 pad2[0xC]; s32 unk1C; } O06A;
typedef struct { s32 unk0; s32 unk4; s32 unk8; u8 unkC[12]; } O06R;
typedef struct { u8 b[8]; u8 pad[0x96 - 8]; } O06N;
static inline s32 func_004467D8(u8 *a, u8 *b, s32 n) {
    u8 c, d;
    do {
        c = *a++; d = *b++;
        n--;
    } while (c == d && c != 0 && n == 0);
    return c == d;
}
extern s32 func_0022A590(void *a, s32 b);
extern u8 D_80145040[];
extern O06R D_800E63C0[];
extern O06N D_8014641C[];
extern u8 *D_800D7C70;
void func_00446330(O06A *a) {
    s32 n = func_0022A590(D_80145040, a->unk1C);
    s32 i, cnt, len;
    u8 *src, *dst, *p;
    switch (n) {
    case 0:
    default:
        a->unkC->unk30 |= 0x1800000;
        a->unkC->unk58 &= ~0x1800000;
        a->unkC->unk80 &= ~0x1800000;
        a->unkC->unkA8 &= ~0x1800000;
        break;
    case 1:
        a->unkC->unk58 |= 0x1800000;
        a->unkC->unk30 &= ~0x1800000;
        a->unkC->unk80 &= ~0x1800000;
        a->unkC->unkA8 &= ~0x1800000;
        break;
    case 2:
        a->unkC->unk80 |= 0x1800000;
        a->unkC->unk30 &= ~0x1800000;
        a->unkC->unk58 &= ~0x1800000;
        a->unkC->unkA8 &= ~0x1800000;
        break;
    case 3:
        a->unkC->unkA8 |= 0x1800000;
        a->unkC->unk30 &= ~0x1800000;
        a->unkC->unk58 &= ~0x1800000;
        a->unkC->unk80 &= ~0x1800000;
        break;
    }
    D_800E63C0[n].unk4 = 0;
    dst = D_800E63C0[n].unkC;
    do { src = D_8014641C[n].b;
    i = 8;
    cnt = 0;
    while (i > 0) { i--; if (src[i] != 0x20) break; cnt++; }
    p = src;
    if (func_004467D8(p, D_800D7C70, 6)) cnt = 8; } while (0);
    for (i = 0; i < 8 - cnt; i++) *dst++ = *src++;
    *dst = 0;
    D_800E63C0[n].unk0 = 8 - cnt;
    D_800E63C0[n].unk8 = 8 - cnt;
}
