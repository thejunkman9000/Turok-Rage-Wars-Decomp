#ifndef S903B_TYPES_H
#define S903B_TYPES_H

/* types of func_0027CCD0 (actor hit / attach handler); names are provisional */
#include "b18_types.h"

typedef struct CcPr {
    s16 a;
    s16 b;
    s32 c;
} CcPr;

typedef struct CcTab {
    CcPr vec[14];
    u16 a70[14];
    u16 a8C[14];
    u16 aA8[14];
} CcTab;

typedef struct CcCfg {
    u32 flags;
    u8 pad4[0x14];
    CcTab *tab;
} CcCfg;

typedef struct CcPar CcPar;
struct CcPar {
    /* 0x000 */ u8 type;
    /* 0x001 */ u8 pad1[0x17];
    /* 0x018 */ s32 *tab18;
    /* 0x01C */ u8 pad1C[0x9C];
    /* 0x0B8 */ u8 *unkB8;
    /* 0x0BC */ u8 padBC[0x44];
    /* 0x100 */ u32 flags100;
    /* 0x104 */ u8 pad104[0x6C];
    /* 0x170 */ u32 unk170;
    /* 0x174 */ u8 pad174[0x114];
    /* 0x288 */ void (*unk288)(CcPar *, void *, void *);
    /* 0x28C */ u8 pad28C[0x1158];
    /* 0x13E4 */ s32 unk13E4;
};

typedef struct CcObj CcObj;
struct CcObj {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ u16 type;
    /* 0x006 */ u8 pad6[2];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ u8 pad18[4];
    /* 0x01C */ Vec3f unk1C;
    /* 0x028 */ u8 pad28[0x28];
    /* 0x050 */ Vec3f unk50;
    /* 0x05C */ u32 flags;
    /* 0x060 */ u8 pad60[0xB8];
    /* 0x118 */ CcCfg *cfg;
    /* 0x11C */ u8 pad11C[0x18];
    /* 0x134 */ void *unk134;
    /* 0x138 */ s32 unk138;
    /* 0x13C */ u8 pad13C[0x44];
    /* 0x180 */ Vec3f unk180;
    /* 0x18C */ u8 pad18C[0x2C];
    /* 0x1B8 */ s8 unk1B8;
    /* 0x1B9 */ s8 unk1B9;
    /* 0x1BA */ u8 pad1BA[0x17];
    /* 0x1D1 */ u8 unk1D1;
    /* 0x1D2 */ u8 pad1D2[7];
    /* 0x1D9 */ u8 unk1D9;
    /* 0x1DA */ u8 pad1DA[6];
    /* 0x1E0 */ f32 unk1E0;
};

typedef struct CcRoot {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 pad1[0x17];
    /* 0x18 */ s32 *tab18;
    /* 0x1C */ u8 pad1C[0xE4];
    /* 0x100 */ u32 flags100;
} CcRoot;

typedef struct CcQ {
    /* 0x00 */ CcRoot *unk0;
    /* 0x04 */ u8 pad4[0xEC];
    /* 0xF0 */ Vec3f unkF0;
} CcQ;

typedef struct CcGs {
    /* 0x00 */ CcPar *unk0;
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ s32 idx;
    /* 0x18 */ u8 pad18[0x65];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 unk7E;
    /* 0x7F */ u8 pad7F[0x59];
    /* 0xD8 */ Vec3f vD8;
} CcGs;

#endif
