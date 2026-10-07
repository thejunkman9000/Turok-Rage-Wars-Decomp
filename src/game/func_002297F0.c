#include "b06_types.h"

void func_00214178(u8 *a, u8 *b, s32 c);
void func_002227D0(Plr *a, Plr *b, s32 c);
void func_0023919C(Pawn *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
f32 func_002745D4(f32 x);
extern GameB6 D_801468A0[];

void func_002297F0(Plr *a, f32 x) {
    f32 f;
    f32 t;
    u32 v;
    u32 w;
    Pawn *pw;
    if (x != 0.0f && !(75.0f <= a->unk11D8) && !(a->unk670 > 0.0f) && (D_801468A0->unk98 == 0 || a->stats->unk80 != 0xB || D_801468A0->unkA0 <= 0) && !(a->unk122C & 0x8000)) {
        f = a->unk11D8 + x * 15.0f;
        if (75.0f < f) {
            f = 75.0f;
        }
        a->unk11D8 = f;
        func_00214178((u8 *)a + 0x2E8, (u8 *)a + 0x458, 2);
        if (a->unk1210 != 0) {
            if (a->unk5E4 != 0) {
                func_002227D0(a, a, 2);
            }
            a->unk1210 = 0;
            a->unk1214 = 0;
        }
        a->flags100 &= 0xFEFFFFFF;
        if (a->unk5DC != NULL) {
            if (a->unk5DC->unk544 == 0) {
                func_0023919C(a->unk5DC, 0x80, 0, 0, 0xFA, (u8)(u32)func_002745D4(7.5f), 0, (u8)(u32)(((a->unk11D8 * 0.06666667f) - 1.5f) * 15.0f));
                return;
            }
            a->unk5DC->unk544 = 3;
            a->unk5DC->unk54D = (u32)a->unk11D8;
        }
    }
}
