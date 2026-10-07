#include "q01_types.h"
typedef struct Q01Pool { s32 unk0; s32 *unk4; s32 *unk8; s32 *unkC[3]; s32 *unk18; s32 *unk1C; } Q01Pool;
extern u32 D_800E28A0;
extern s32 D_800E28A4;
extern s32 D_800E28A8;
extern s32 D_801536B0;
extern s32 D_801536B4;
extern s32 D_801536B8;
extern s32 D_801536BC;
extern s32 D_801536C0;
extern s32 D_801536E8;
extern s32 D_801536EC;
extern s32 D_801536F0;
extern s32 D_801536F4;
extern s32 D_801536F8[];
extern u8 D_800E0D30[];
extern u8 D_800E0D3C[];
extern u8 D_800E0D4C[];
extern u8 D_800E0D6C[];
extern u8 D_800E0D7C[];
extern u8 D_800E0D84[];
s32 *func_002533DC(s32 a, s32 b, s32 c, void *d);
s32 *func_002534D0(s32 a, s32 b, s32 c, void *d);
void func_002537D8(s32 a, s32 *b);
u32 func_00265370();
void *memset(void *p, s32 c, u32 n);

void func_004058B0(Q01Pool *arg0) {
    u32 mb = 0x100000;
    u32 i;
    s32 j;
    s32 n;
    s32 *s0, *s1;
    u32 s2;
    u32 base, top;
    s32 lo;
    if (arg0->unk4 != 0) func_002537D8(0, arg0->unk4);
    if (arg0->unk8 != 0) func_002537D8(0, arg0->unk8);
    if (arg0->unk18 != 0) func_002537D8(0, arg0->unk18);
    if (arg0->unk1C != 0) func_002537D8(0, arg0->unk1C);
    for (n = 0; n < 3; n++) {
        if (arg0->unkC[n] != 0) func_002537D8(0, arg0->unkC[n]);
    }
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    for (j = 2; j >= 0; j--) arg0->unkC[j] = 0;
    if (func_00265370() >= mb * 6) {
        base = func_00265370() | 0x80000000;
        D_800E28A0 = 3;
        s2 = 0x54600;
        s0 = func_002534D0(0, base - mb, s2, D_800E0D30);
        s1 = func_002534D0(0, base - mb * 2, D_800E28A0 * s2, D_800E0D3C);
        memset((void *)*s1, 0, 0xFD200);
        memset((void *)*s0, 0, 0x54600);
        arg0->unk18 = s0;
        arg0->unkC[0] = s1;
        D_801536E8 = *s0;
        i = 0;
        if (D_800E28A0 != 0) {
            u32 a0 = 0;
            do {
                D_801536F8[i] = *s1 + a0;
                i++;
                a0 += s2;
            } while (i < D_800E28A0);
        }
    } else {
        s2 = 0x1ECC0;
        lo = (D_800E28A0 + 1) * s2;
        top = 0x80400000;
        i = 0;
        s1 = func_002534D0(0, top - lo, lo, D_800E0D4C);
        arg0->unkC[0] = s1;
        if (D_800E28A0 != 0) {
            u32 a0 = 0;
            do {
                D_801536F8[i] = *s1 + a0;
                i++;
                a0 += s2;
            } while (i < D_800E28A0);
        }
        D_801536E8 = *s1 + s2 * i;
    }
    i = 0;
    if (D_800E28A0 != 0) {
        do {
            memset((void *)D_801536F8[i], 0, s2);
            i++;
        } while (i < D_800E28A0);
    }
    memset((void *)D_801536E8, 0, s2);
    arg0->unk4 = func_002533DC(0, (D_800E28A4 + D_800E28A8) * 16, 0x23, D_800E0D6C);
    arg0->unk8 = func_002533DC(0, 0x8000, 0x23, D_800E0D7C);
    arg0->unk1C = func_002533DC(0, 0x22000, 0x23, D_800E0D84);
    D_801536B4 = 0x8000;
    D_801536EC = 0x22000;
    D_801536F0 = *arg0->unk4;
    D_801536BC = D_801536F0 + D_800E28A4 * 8;
    D_801536F4 = D_801536BC + D_800E28A8 * 8;
    D_801536C0 = D_801536F4 + D_800E28A4 * 8;
    D_801536B0 = *arg0->unk1C;
    D_801536B8 = *arg0->unk8;
    if (D_800E28A0 != 0) {
        i = 1;
        do { i++; } while (i < D_800E28A0);
    }
    arg0->unk0 = 1;
}
