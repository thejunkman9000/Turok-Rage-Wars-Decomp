#include "o04_types.h"
typedef struct { u32 w0; u32 w1; } O04Gfx;
extern O04ModeS4690 *D_800E4690;
extern s32 D_800D15E0;
extern f32 D_800D15E4[];
extern f32 D_800E19E4;
extern f32 D_800E19E8[];
typedef struct { s32 a; s32 b; s32 c; s32 d; } O04Quad;
extern O04Quad D_800E41C0[];
extern u8 D_801462D5[];
extern O04Gfx *D_80110634;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
void func_0041C864(void *p);
s32 func_0029A958(void);
void func_004220D8(s32 a);
void func_0040E958(void *p, s32 a);
s32 func_00426EC4(s32 a, s32 b, s32 c) {
    s32 s3;
    s32 s2;
    s32 k;
    s32 s0;
    f32 fs0;
    O04Gfx *dl;
    s32 v;
    if (c == 1) {
        if (D_800E4690->unk988 == 3 || D_800E4690->unk988 == 8 || D_800E4690->unk988 == 9) {
            D_800D15E0 = 0;
            D_800D15E4[0] = D_800E19E4;
            D_800D15E4[1] = D_800E19E4;
            D_800D15E4[2] = D_800E19E4;
            D_800D15E4[3] = D_800E19E4;
            s3 = 1;
            if (D_801462D5[0] == 2) {
                s3 = 2;
            }
            s2 = 0;
            k = 0;
            if (s3 != 0) {
                fs0 = D_800E19E8[0];
                s0 = 0x20;
                do {
                    s2++;
                    dl = D_80110634++;
                    dl->w0 = (((s32)((f32)D_800E41C0[k].a * fs0) & 0xFFF) << 12) | (((s32)((f32)D_800E41C0[k].b * fs0) & 0xFFF) | 0xED000000);
                    dl->w1 = (((s32)((f32)D_800E41C0[k].c * fs0) & 0xFFF) << 12) | ((s32)((f32)D_800E41C0[k].d * fs0) & 0xFFF);
                    func_0041C864((u8 *)D_800E4690 + s0);
                    s0 += 0x4A8;
                    k = 2;
                    dl = D_80110634++;
                    dl->w0 = 0xED000000;
                    dl->w1 = (((s32)((f32)(D_800E28D0 - 1) * fs0) & 0xFFF) << 12) | ((s32)((f32)(D_800E28D4 - 1) * fs0) & 0xFFF);
                } while (s2 < s3);
            }
            if (D_801462D5[0] != 2 && func_0029A958() != 0x19) {
                v = D_800E4690->unkA6C;
                if (v < 0x14) {
                    D_800E4690->unkA6C = v + 1;
                    if (v + 1 == 0x14) {
                        func_004220D8(D_800E4690->unkA44 + 0x259);
                        D_800E4690->unkA70 = 0;
                    }
                }
                if (D_800E4690->unkA70 != -1) {
                    D_800E4690->unkA70 = D_800E4690->unkA70 + 1;
                    if (D_800E4690->unkA70 >= 6) {
                        D_800E4690->unkA68 = 1;
                        D_800E4690->unkA70 = -1;
                    }
                }
                if (D_800E4690->unkA68 == 1) {
                    v = D_800E4690->unkA64->unk10;
                    v -= 0x1E;
                    if (v <= 0) {
                        D_800E4690->unkA68 = 0;
                        func_0040E958(D_800E4690->unkA60, 0);
                        func_0040E958(D_800E4690->unkA64, 0);
                        v = 0xFF;
                    }
                    D_800E4690->unkA64->unk10 = v;
                    D_800E4690->unkA60->unk10 = v;
                }
            }
        }
    }
    return 0;
}
