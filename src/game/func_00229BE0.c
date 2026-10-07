#include "b06_types.h"

extern s32 D_800CE474[];
extern s32 D_80146910;

s32 func_00229BE0(Plr *a, s32 base) {
    s32 off;
    if (a->unkE4 == D_800CE474[2]) {
        switch (D_80146910) {
        case 1: off = 0x5DC; break;
        case 0: off = 0x514; break;
        case 2: off = 0x578; break;
        default: D_80146910 = 0; off = 0x514; break;
        }
    } else if (a->unkE4 == D_800CE474[0]) {
        off = 0x190;
    } else if (a->unkE4 == D_800CE474[1]) {
        off = 0x3E8;
    } else {
        switch (a->stats->unk80) {
        default: a->stats->unk80 = 0;
        case 0: off = 0; break;
        case 1: off = 0x44C; break;
        case 2: off = 0xC8; break;
        case 3: off = 0x12C; break;
        case 4: off = 0x4B0; break;
        case 5: off = 0x64; break;
        case 6: off = 0x258; break;
        case 7: off = 0x384; break;
        case 8: off = 0x320; break;
        case 9: case 15: off = 0x2BC; break;
        case 10: off = 0x1F4; break;
        case 11: off = 0x640; break;
        case 12: off = 0x6A4; break;
        case 13: case 16: off = 0x708; break;
        case 14: off = 0x76C; break;
        }
    }
    return base + off;
}
