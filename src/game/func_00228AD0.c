#include "b06_types.h"

s32 func_00245774();
s32 func_00245788();
void func_002A921C(s32 a, f32 b, f32 c, f32 d, f32 e, s32 f, s32 g, s32 h);
void func_002A94E8();
void func_002A9F18(u8 *a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g, f32 h);
void func_002AA224(u8 a);
extern u8 D_800C7CC8[];
extern f32 D_800C7CCC;
extern f32 D_800C7CD0;
extern f32 D_800C7CD4;
extern f32 D_800C7CD8;
extern f32 D_800C7CDC;
extern f32 D_800C7CE0;
extern f32 D_800C7CE4;
extern f32 D_800C7CE8;
extern f32 D_800C7CEC;
extern f32 D_800C7CF0;
extern f32 D_800C7CF4;
extern f32 D_800C7CF8;
extern f32 D_800C7CFC;
extern f32 D_800C7D00;
extern u32 D_800D2980;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern s32 D_800E28D8;
extern s32 D_801450B8;
extern u8 D_801462DE[];

void func_00228AD0(s32 unused, HudInB6 *b) {
    f32 fs0, fs0f, fs1, fs1f, fs2, ft0;
    if (func_00245774() == 0 && func_00245788() == 0) {
        func_002AA224(D_801462DE[0]);
        if (!(*(f32 *)(D_801462DE + 0x5D6) <= 0.0f) && ((fs2 = *(f32 *)(D_801462DE + 0x5D6) * D_800C7CCC, fs0 = b->unk29C / (f32)D_800E28D0, ft0 = (f32)(s32)(fs2 * D_800C7CD0), fs1f = b->unk2A0 / (f32)D_800E28D4, fs2 = fs2 - ft0 * D_800C7CD4, !(ft0 < D_800C7CD8)) || !(fs2 < D_800C7CDC) || (D_800D2980 % 15 >= 5))) {
            if (D_801450B8 == 1) {
                if (D_800E28D8 == 0) {
                    fs1 = (f32)D_800E28D0 * D_800C7CE0;
                    fs0 = fs0 * D_800C7CE4;
                    fs0f = D_800C7CE8;
                    fs1f = fs1f * D_800C7CE4;
                } else {
                    fs0f = D_800C7CF0;
                    fs1 = (f32)D_800E28D0 * D_800C7CEC;
                }
            } else {
                fs1 = (f32)D_800E28D0 * D_800C7CF4;
                fs0f = (f32)(D_800E28D4 - 10) * D_800C7CF4;
            }
            func_002A921C((s32)ft0, fs1 - fs0 * D_800C7CF8, fs0f, fs0, fs1f, 1, 1, 0);
            func_002A921C((s32)fs2, fs1 + 2.0f * fs0, fs0f, fs0, fs1f, 1, 0, 2);
            func_002A94E8();
            func_002A9F18(D_800C7CC8, (s32)(fs1 - fs0 * D_800C7CFC), (s32)(fs0f - fs1f * D_800C7D00), 0xFF, 0, 0, fs0, fs1f);
        }
    }
}
