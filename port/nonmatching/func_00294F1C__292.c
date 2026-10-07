#include "common.h"

extern s32 D_800D2AE0;
extern s32 D_800D2AE4;
extern s32 D_800D2AE8;
extern s32 D_800D2AEC;
extern s32 D_800D2AF0;
extern s32 D_800D2AF4;
extern s32 D_800D2AF8;
extern s32 D_800D2AFC;
extern s32 D_8010F3D8;
extern u8 D_80145088[];
extern u8 D_800CA60C[];
extern u8 D_800CA620[];
extern f32 D_800CA634;
extern s32 D_800E28D4;
extern s32 D_8014AEB8;
extern s32 D_8014AEBC;
extern s32 D_8014AEC0;
extern s32 D_8014AEC4;
extern u8 D_8014AEB0_u8 __asm__("D_8014AEB0");
extern s32 D_8014AEB0_14 __asm__("D_8014AEB0");
extern s32 D_8014D068[];

void func_00237E70(void *, void *, void *);
void func_00294CA0(s32);
void func_002A94E8();
void func_002A9700();
void func_002A9F18(void *, s32, s32, s32, s32, s32, f32, f32);
void func_002ABB2C(s32, s32, s32, s32, s32, s32);
void func_002ABB58(f32, f32);

typedef struct Cfg4F { u8 on; u8 pad[0x13]; s32 f14; } Cfg4F;
extern Cfg4F D_8014AEB0;

void func_00294F1C(s32 arg) {
    s32 t, a0, v1;
    f32 k;
    s32 *p;

    if (D_800D2AE0 != 0) {
        if (D_8010F3D8 & 0x10) {
            if (D_800D2AFC == 0) {
                if (D_8014AEB0.on == 0) {
                    func_00237E70(D_80145088, D_80145088 + 0x40, D_800CA60C);
                    D_8014AEB0.f14 = 1;
                } else {
                    func_00237E70(D_80145088, D_80145088 + 0x40, D_800CA620);
                }
                D_800D2AFC = 1;
                D_8014AEB0.on = D_8014AEB0.on < 1;
            }
        } else {
            D_800D2AFC = 0;
        }
        if (D_8010F3D8 & 0x2000) {
            if (D_8010F3D8 & 0x200) {
                if (D_800D2AEC++ >= 3) {
                    t = D_8014AEC0;
                    D_8014AEC4 = 1;
                    D_800D2AEC = 0;
                    D_8014AEC0 = t - 1;
                }
            }
            if (D_8010F3D8 & 0x100) {
                if (D_800D2AF0++ >= 3) {
                    t = D_8014AEC0;
                    D_8014AEC4 = 1;
                    D_800D2AF0 = 0;
                    D_8014AEC0 = t + 1;
                }
            }
        } else {
            if (D_8010F3D8 & 0x200) {
                if (D_800D2AE4++ >= 3) {
                    a0 = D_8014AEBC - 1;
                    v1 = (a0 + D_8014AEB8) % D_8014AEB8;
                    D_8014AEC4 = 1;
                    D_8014AEBC = a0;
                    D_8014AEBC = v1;
                    if ((f32)v1 < 0.0f) {
                        v1 = -v1;
                    }
                    *(s32 *)((u8 *)&D_8014AEC4 - 8) = v1;
                    D_800D2AE4 = 0;
                }
            }
            if (D_8010F3D8 & 0x100) {
                if (D_800D2AE8++ >= 3) {
                    t = D_8014AEBC + 1;
                    a0 = t % D_8014AEB8;
                    D_800D2AE8 = 0;
                    D_8014AEC4 = 1;
                    D_8014AEBC = t;
                    D_8014AEBC = a0;
                }
            }
            if (D_8010F3D8 & 0x400) {
                if (D_800D2AF4++ >= 3) {
                    a0 = D_8014AEBC - 5;
                    v1 = (a0 + D_8014AEB8) % D_8014AEB8;
                    D_8014AEBC = a0;
                    p = &D_8014AEBC;
                    D_8014AEBC = v1;
                    if ((f32)v1 < 0.0f) {
                        v1 = -v1;
                    }
                    p[0] = v1;
                    p[2] = 1;
                    D_800D2AF4 = 0;
                }
            }
            if (D_8010F3D8 & 0x800) {
                if (D_800D2AF8++ >= 3) {
                    t = D_8014AEBC + 5;
                    a0 = t % D_8014AEB8;
                    D_800D2AF8 = 0;
                    D_8014AEC4 = 1;
                    D_8014AEBC = t;
                    D_8014AEBC = a0;
                }
            }
        }
        D_8014D068[0] = D_8014D068[0] + 1;
        if (D_8014D068[-0x21A4 / 4] != 0) {
            func_00294CA0(arg);
            D_8014D068[-0x21A4 / 4] = 0;
        }
        func_002A94E8();
        k = D_800CA634;
        func_002A9700();
        func_002ABB58(k, k);
        func_002ABB2C(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
        func_002A9F18((u8 *)D_8014D068 - 0x80, 0x10, D_800E28D4 - 0x30, 0xFF, 0, 0, k, k);
    }
}
