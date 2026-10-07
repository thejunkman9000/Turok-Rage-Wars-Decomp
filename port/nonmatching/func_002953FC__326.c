#include "common.h"

typedef struct B21Cfg {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} B21Cfg;

extern s32 D_8014AED4;
extern s32 D_8014AED8;
extern B21Cfg *D_8014AED0;
extern s32 D_8014AEC8;
extern u32 D_800D2AE0;

inline s32 func_00295AE0(void) {
    return D_8014AED4;
}

inline s32 func_00295AF0(void) {
    return D_8014AED8;
}

inline s32 func_00295B00(void) {
    return 1 << D_8014AED0->unk2;
}

inline s32 func_00295B18(void) {
    return 1 << D_8014AED0->unk3;
}

inline s32 func_00295B30(void) {
    switch (D_8014AED0->unk0) {
    case 0:
        return 8;
    case 1:
    case 3:
    case 5:
        return 4;
    case 2:
        return 0x20;
    case 4:
        return 0x10;
    default:
        return 0;
    }
}

s32 func_002953FC(s32 id) {
    if (D_800D2AE0 == 0) {
        return 0;
    }
    switch (id) {
    case 0x101:
        return func_00295AE0();
    case 0x102:
        return func_00295AF0();
    case 0x103:
        return func_00295B00();
    case 0x104:
        return func_00295B18();
    case 0x105:
        return func_00295B30();
    case 0x106:
        D_8014AEC8 = 1;
        return 0;
    }
    return 0;
}
