/* US v1.0: real entry 0x43DD30 (ROM 0x1A1D30; the word at 0x1A1D2C is pad_1A1D2C) = US v1.1 src/ovl_a/func_0043DD2C.c unchanged, renamed */
#include "o06_types.h"
typedef struct { s32 unk0; u8 pad[0x10]; void *unk14; } O06A;
extern u8 D_801462F5;
extern u8 D_800D7D40[];
extern u8 D_800D7D44[];
extern u8 D_801462F6;
extern u8 D_800D7D48[];
extern u8 D_800D7D4C[];
extern u8 D_801462F7;
extern u8 D_800D7D50[];
extern u8 D_800D7D54[];
extern u8 D_801462F8;
extern u8 D_800D7D58[];
extern u8 D_800D7D5C[];
extern u8 D_801462F9;
extern u8 D_800D7D60[];
extern u8 D_800D7D64[];
extern u8 D_801462FA;
extern u8 D_800D7D68[];
extern u8 D_800D7D6C[];
extern u8 D_801462FB;
extern u8 D_800D7D70[];
extern u8 D_800D7D74[];
extern u8 D_801462FD;
extern u8 D_800D7D78[];
extern u8 D_800D7D7C[];
s32 func_auto_0043DD30(O06A *a) {
    switch (a->unk0) {
    default:
    case 2:
        if (D_801462F5) a->unk14 = D_800D7D40; else a->unk14 = D_800D7D44;
        break;
    case 3:
        if (D_801462F6) a->unk14 = D_800D7D48; else a->unk14 = D_800D7D4C;
        break;
    case 4:
        if (D_801462F7) a->unk14 = D_800D7D50; else a->unk14 = D_800D7D54;
        break;
    case 5:
        if (D_801462F8) a->unk14 = D_800D7D58; else a->unk14 = D_800D7D5C;
        break;
    case 6:
        if (D_801462F9) a->unk14 = D_800D7D60; else a->unk14 = D_800D7D64;
        break;
    case 7:
        if (D_801462FA) a->unk14 = D_800D7D68; else a->unk14 = D_800D7D6C;
        break;
    case 8:
        if (D_801462FB) a->unk14 = D_800D7D70; else a->unk14 = D_800D7D74;
        break;
    case 9:
        if (D_801462FD) a->unk14 = D_800D7D78; else a->unk14 = D_800D7D7C;
        break;
    }
    return 0;
}
