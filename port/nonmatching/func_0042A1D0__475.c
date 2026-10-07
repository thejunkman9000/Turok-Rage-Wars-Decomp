#include "o04_types.h"
typedef struct { u32 w0; u32 w1; } O04Gfx;
extern O04ModeF60 *D_800E4F60;
extern volatile s32 D_800D15E0;
extern f32 D_800D15E4[];
extern f32 D_800D15F0;
extern O04Gfx *D_80110634;
extern f32 D_800E1ABC;
extern f32 D_800E1AC0;
extern f32 D_800E1AC4;
extern f32 D_800E1AC8;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern s32 D_80154024;
s32 func_0029A958(void);
void func_004399D0(void *p);
void func_004220D8(s32 a);
s32 func_0042B474(s32 a);
s32 func_0042B398(s32 a, s32 b);
void func_0040E958(void *p, s32 a);
s32 func_0042A1D0(s32 a, s32 b, s32 c) {
    s32 i;
    s32 off;
    O04Gfx *dl;
    s32 v;
    if (c == 1) {
        if (D_800E4F60->state == 3 || D_800E4F60->state == 8 || D_800E4F60->state == 9) {
            D_800D15E0 = 0;
            D_800D15E0 = 1;
            D_800D15E4[0] = D_800E1ABC;
            D_800D15E4[1] = D_800E1ABC;
            D_800D15E4[2] = D_800E1ABC;
            D_800D15E4[3] = D_800E1ABC;
            dl = D_80110634++;
            dl->w0 = 0xED000000;
            dl->w1 = (((s32)((f32)(D_800E28D0 - 1) * D_800E1AC0) & 0xFFF) << 12) | ((s32)((f32)(D_800E28D4 - 1) * D_800E1AC0) & 0xFFF);
            D_800D15E4[3] = D_800E1AC4;
            if (func_0029A958() == 0x14 && D_80154024 == 0) {
                for (i = 0, off = 8; i < 4; i++, off += 0xC0) {
                    func_004399D0((u8 *)D_800E4F60 + off);
                }
            }
            if (D_800E4F60->unk438 == 0) {
                func_004399D0(D_800E4F60->unk308);
            }
            D_800D15E0 = 0;
            D_800D15F0 = D_800E1AC8;
        }
    }
    if (c == 0 && func_0029A958() != 0x19) {
        v = D_800E4F60->unk464;
        if (v < 0x14) {
            v++;
            D_800E4F60->unk464 = v;
            if (v == 0x14 && D_800E4F60->unk438 > 0) {
                func_004220D8(func_0042B398(func_0042B474(D_800E4F60->unk434), D_800E4F60->unk438) + 0x259);
                D_800E4F60->unk468 = 0;
            }
        }
        if (D_800E4F60->unk468 != -1) {
            D_800E4F60->unk468 = D_800E4F60->unk468 + 1;
            if (D_800E4F60->unk468 >= 6) {
                D_800E4F60->unk46C = 1;
                D_800E4F60->unk468 = -1;
            }
        }
        if (D_800E4F60->unk46C == 1) {
            v = D_800E4F60->unk454->unk10;
            v -= 0x1E;
            if (v <= 0) {
                D_800E4F60->unk46C = 0;
                func_0040E958(D_800E4F60->unk450, 0);
                func_0040E958(D_800E4F60->unk454, 0);
                v = 0xFF;
            }
            D_800E4F60->unk454->unk10 = v;
            D_800E4F60->unk450->unk10 = v;
        }
    }
    return 0;
}
