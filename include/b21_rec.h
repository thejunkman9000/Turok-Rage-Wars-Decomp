#ifndef B21_REC_H
#define B21_REC_H

#include "common.h"

/* state block at D_8014AEB0 (size 0x21BC): the globals D_8014AEB1..D_8014D068 are members of this one object.
   D_8014AEBC = unkC, D_8014AEC0 = unk10 (cursor), D_8014AECC = unk1C (loaded script object), D_8014AED0 = unk20, ... */
typedef struct B21Rec {
    /* 0x0000 */ u8 unk0;
    /* 0x0001 */ u8 unk1;
    /* 0x0002 */ u8 pad2[2];
    /* 0x0004 */ s32 unk4;
    /* 0x0008 */ s32 unk8;
    /* 0x000C */ s32 unkC;
    /* 0x0010 */ s32 unk10;
    /* 0x0014 */ s32 unk14;
    /* 0x0018 */ s32 unk18;
    /* 0x001C */ s32 **unk1C;
    /* 0x0020 */ s32 *unk20;
    /* 0x0024 */ s32 *unk24;
    /* 0x0028 */ s32 *unk28;
    /* 0x002C */ u8 buf2C[0x2000];
    /* 0x202C */ u8 buf202C[0x100];
    /* 0x212C */ s32 *unk212C;
    /* 0x2130 */ s32 *unk2130;
    /* 0x2134 */ s32 *unk2134;
    /* 0x2138 */ char buf2138[0x80];
    /* 0x21B8 */ s32 unk21B8;
} B21Rec;

#endif
