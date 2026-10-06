#include "common.h"

typedef struct B21Blk {
    /* 0x0000 */ u8 unk0;
    /* 0x0001 */ u8 unk1;
    /* 0x0002 */ u8 pad2[2];
    /* 0x0004 */ s32 unk4;
    /* 0x0008 */ s32 unk8;
    /* 0x000C */ s32 unkC;
    /* 0x0010 */ s32 unk10;
    /* 0x0014 */ s32 unk14;
    /* 0x0018 */ u8 pad18[4];
    /* 0x001C */ s32 unk1C;
    /* 0x0020 */ s32 unk20;
    /* 0x0024 */ s32 unk24;
    /* 0x0028 */ s32 unk28;
    /* 0x002C */ u8 pad2C[0x212C - 0x2C];
    /* 0x212C */ s32 unk212C;
    /* 0x2130 */ s32 unk2130;
    /* 0x2134 */ s32 unk2134;
    /* 0x2138 */ u8 pad2138[0x21B8 - 0x2138];
    /* 0x21B8 */ s32 unk21B8;
} B21Blk;

extern B21Blk D_8014AEB0;

void func_002958D8(void) {
    D_8014AEB0.unk0 = 0;
    D_8014AEB0.unk1 = 0;
    D_8014AEB0.unkC = 0;
    D_8014AEB0.unk10 = 0;
    D_8014AEB0.unk8 = 1;
    D_8014AEB0.unk4 = 0;
    D_8014AEB0.unk14 = 0;
    D_8014AEB0.unk1C = 0;
    D_8014AEB0.unk24 = 0;
    D_8014AEB0.unk28 = 0;
    D_8014AEB0.unk20 = 0;
    D_8014AEB0.unk212C = 0;
    D_8014AEB0.unk2130 = 0;
    D_8014AEB0.unk2134 = 0;
    D_8014AEB0.unk21B8 = 0;
}
