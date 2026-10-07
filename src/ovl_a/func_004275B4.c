#include "o04_types.h"
typedef struct { u8 pad0[2]; u16 unk2; u8 pad4[2]; u16 unk6; union { s32 w; struct { u16 h0; u16 h1; } h; } u8_; } O04Ent12;
extern O04ModeS4690 *D_800E4690;
extern O04Ent12 D_800E4A84[];
s32 func_0040ECB0(s32 a, s32 b);
void func_0040E958(s32 a, s32 b);
void func_004275B4(void) {
    s32 i;
    for (i = 0; i < 0x40; i++) {
        func_0040E958(func_0040ECB0(D_800E4690->unk970, D_800E4A84[i].unk2), 0);
        func_0040E958(func_0040ECB0(D_800E4690->unk970, D_800E4A84[i].unk6), 0);
        if (D_800E4A84[i].u8_.w != -1) {
            func_0040E958(func_0040ECB0(D_800E4690->unk970, D_800E4A84[i].u8_.h.h1), 0);
        }
    }
}
