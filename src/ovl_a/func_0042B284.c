#include "o04_types.h"
typedef struct { u8 pad0[2]; u16 unk2; union { s32 w; struct { u16 h0; u16 h1; } h; } u4; u8 pad8[8]; } O04Ent16;
extern O04ModeF60 *D_800E4F60;
extern O04Ent16 D_800E4F64[];
s32 func_0040ECB0(void *a, s32 b);
void func_0040E958(s32 a, s32 b);
void func_0042B284(void) {
    s32 i;
    for (i = 0; i < 0x28; i++) {
        func_0040E958(func_0040ECB0(D_800E4F60->unk0, D_800E4F64[i].unk2), 0);
        if (D_800E4F64[i].u4.w != -1) {
            func_0040E958(func_0040ECB0(D_800E4F60->unk0, D_800E4F64[i].u4.h.h1), 0);
        }
    }
}
