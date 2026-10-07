#include "b04_types.h"
typedef struct { u8 pad0[0x98]; s32 unk98; u8 pad9C[4]; s32 unkA0; } B04GF;
extern B04GF D_801468A0[];
typedef struct { u8 pad0[0x80]; s8 unk80; } B04St80;
typedef struct {
    u8 pad0[0x5D8]; B04St80 *stats; u8 pad5DC[8]; s32 unk5E4; u8 pad5E8[0x88]; f32 unk670; u8 pad674[0xB64];
    s32 unk11D8; u8 pad11DC[8]; s32 unk11E4; u8 pad11E8[0x44]; u32 unk122C; u8 pad1230[0x1A8]; s32 unk13D8;
} B04Pa7;
typedef struct { u8 pad0[4]; u16 unk4; u8 pad6[0x126]; s32 unk12C; } B04Ev7;
s32 func_0022C450(B04Pa7 *);
void func_0022B68C(B04Pa7 *, f32, s32);
void func_0022B540(B04Pa7 *, f32, f32, s32, s32);
void func_0022B5FC(B04Pa7 *, f32, s32);
void func_0022B7E8(B04Pa7 *, s32);
void func_002227D0(B04Pa7 *, B04Pa7 *, s32);
void func_0021C440(B04Pa7 *a, s32 a1, s32 a2, B04Ev7 *e) {
    if (a->unk5E4 != 0 && func_0022C450(a) == 0 && !(a->unk670 > 0.0f)
        && (D_801468A0->unk98 == 0 || a->stats->unk80 != 0xB || D_801468A0->unkA0 <= 0)
        && !(a->unk122C & 0x8000)) {
        switch (e->unk4) {
        case 0x4CD:
        case 0x3FB:
            func_0022B68C(a, 0.1f, e->unk12C);
            return;
        case 0x4CF:
        case 0x3FD:
            func_0022B68C(a, 0.125f, e->unk12C);
            return;
        case 0x4D0:
        case 0x3FE:
            func_0022B68C(a, 0.3f, e->unk12C);
            return;
        case 0x432:
        case 0x4E3:
            func_0022B540(a, 80.0f, 2.0f, e->unk12C, 1);
            return;
        case 0x4E0:
        case 0x408:
            func_0022B5FC(a, 0.25f, e->unk12C);
            return;
        case 0x4D3:
        case 0x419:
            func_0022B7E8(a, e->unk12C);
            return;
        case 0x129:
            a->unk11D8 = 0;
            a->unk11E4 = 0;
            if (!(a->unk122C & 0x8000)) {
                if (a->unk13D8 == 0)
                    a->unk13D8 = e->unk12C;
                func_002227D0(a, a, 0x26);
            }
            break;
        }
    }
}
