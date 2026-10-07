#ifndef B06_TYPES_H
#define B06_TYPES_H

#include "common.h"
#include "p1_types.h"

/* Batch 06 types (generated from wip/structs.txt by wip/mkhdr.py; offsets are exact, padding explicit).
   B6F(): accessor for offsets not named yet.  NOTE: accesses through B6F are not seen by gcc as struct
   member accesses (MEM_IN_STRUCT_P), which changes scheduling; prefer real fields when matching. */
#define B6F(p, T, off) (*(T *)((u8 *)(p) + (off)))

typedef struct PlrStats PlrStats;
typedef struct VtxB6 VtxB6;
typedef struct Vec4f Vec4f;
typedef struct PlrList PlrList;
typedef struct PlrRec21 PlrRec21;
typedef struct PlrAux PlrAux;
typedef struct PlrEnt PlrEnt;
typedef struct PlrDef PlrDef;
typedef struct RecB6 RecB6;
typedef struct Pawn Pawn;
typedef struct HudInB6 HudInB6;
typedef struct PlrCls PlrCls;
typedef struct GameB6 GameB6;
typedef struct Game2B6 Game2B6;
typedef struct HudB6 HudB6;
typedef struct HudSubB6 HudSubB6;
typedef struct GStateB6 GStateB6;
typedef struct PlrObj PlrObj;
typedef struct PathB6 PathB6;
typedef struct AimB6 AimB6;
typedef struct OutB6 OutB6;
typedef struct HitB6 HitB6;
typedef struct Plr Plr;
typedef struct PlrGroup PlrGroup;

struct PlrStats {
    /* 0x0000 */ u8 pad0[0x4];
    /* 0x0004 */ s16 unk4;
    /* 0x0006 */ u8 pad6[0x16];
    /* 0x001C */ s16 unk1C[8];
    /* 0x002C */ u8 pad2C[0x10];
    /* 0x003C */ s16 unk3C[8];
    /* 0x004C */ u8 pad4C[0x34];
    /* 0x0080 */ s8 unk80;
    /* 0x0081 */ u8 unk81;
    /* 0x0082 */ u8 pad82[0xC];
    /* 0x008E */ u8 unk8E;
    /* 0x008F */ u8 unk8F;
    /* 0x0090 */ u8 unk90;
    /* 0x0091 */ u8 pad91[0x1];
    /* 0x0092 */ u8 unk92;
    /* 0x0093 */ u8 unk93;
    /* 0x0094 */ u8 unk94;
    /* 0x0095 */ u8 unk95;
};

struct VtxB6 {
    /* 0x0000 */ s16 ob[3];
    /* 0x0006 */ u16 flag;
    /* 0x0008 */ s16 tc[2];
    /* 0x000C */ u8 cn[4];
};

struct Vec4f {
    /* 0x0000 */ f32 x;
    /* 0x0004 */ f32 y;
    /* 0x0008 */ f32 z;
    /* 0x000C */ f32 w;
};

struct PlrList {
    /* 0x0000 */ u8 pad0[0x144];
    /* 0x0144 */ Plr* arrA[0x200];
    /* 0x0944 */ s32 cntA;
    /* 0x0948 */ Plr* arrB[0x80];
    /* 0x0B48 */ s32 cntB;
};

struct PlrRec21 {
    /* 0x0000 */ u8 b[0x15];
};

struct PlrAux {
    /* 0x0000 */ u8 pad0[0x10];
    /* 0x0010 */ s32 unk10;
};

struct PlrEnt {
    /* 0x0000 */ f32 unk0;
    /* 0x0004 */ f32 unk4;
    /* 0x0008 */ s32 unk8;
    /* 0x000C */ f32 unkC;
    /* 0x0010 */ f32 unk10;
    /* 0x0014 */ s32 unk14;
};

struct PlrDef {
    /* 0x0000 */ u8 pad0[0x4];
    /* 0x0004 */ u16 unk4;
    /* 0x0006 */ u8 pad6[0x1A];
    /* 0x0020 */ s16* unk20;
    /* 0x0024 */ s16* unk24;
};

struct RecB6 {
    /* 0x0000 */ u8 pad0[0x44];
    /* 0x0044 */ u32 unk44;
};

struct Pawn {
    /* 0x0000 */ u8 pad0[0x24];
    /* 0x0024 */ s32 unk24;
    /* 0x0028 */ u8 pad28[0x100];
    /* 0x0128 */ Vec3f pos128;
    /* 0x0134 */ u8 pad134[0x2C];
    /* 0x0160 */ f32 m160[16];
    /* 0x01A0 */ u8 pad1A0[0x380];
    /* 0x0520 */ u8 unk520[4];
    /* 0x0524 */ u8 pad524[0x20];
    /* 0x0544 */ s32 unk544;
    /* 0x0548 */ u8 pad548[0x5];
    /* 0x054D */ u8 unk54D;
    /* 0x054E */ u8 pad54E[0x16];
    /* 0x0564 */ s32 unk564;
};

struct HudInB6 {
    /* 0x0000 */ u8 pad0[0x29C];
    /* 0x029C */ f32 unk29C;
    /* 0x02A0 */ f32 unk2A0;
};

struct PlrCls {
    /* 0x0000 */ u8 pad0[0xC];
    /* 0x000C */ s16 unkC;
    /* 0x000E */ u8 unkE;
    /* 0x000F */ u8 padF[0x9];
    /* 0x0018 */ s32 unk18;
    /* 0x001C */ u8 pad1C[0xD8];
    /* 0x00F4 */ f32 unkF4;
    /* 0x00F8 */ u8 padF8[0x4];
    /* 0x00FC */ f32 unkFC;
    /* 0x0100 */ f32 unk100;
    /* 0x0104 */ f32 unk104;
    /* 0x0108 */ s32 unk108[1];
};

struct GameB6 {
    /* 0x0000 */ u8 pad0[0x14];
    /* 0x0014 */ f32 unk14;
    /* 0x0018 */ s32 unk18;
    /* 0x001C */ s32 unk1C;
    /* 0x0020 */ s32 unk20;
    /* 0x0024 */ s32 unk24;
    /* 0x0028 */ s32 unk28;
    /* 0x002C */ s32 unk2C[5];
    /* 0x0040 */ s32 unk40[5];
    /* 0x0054 */ s32 unk54;
    /* 0x0058 */ s32 unk58;
    /* 0x005C */ u8 pad5C[0x17];
    /* 0x0073 */ u8 unk73;
    /* 0x0074 */ u8 pad74[0x4];
    /* 0x0078 */ s32 unk78;
    /* 0x007C */ s32 unk7C;
    /* 0x0080 */ u8 pad80[0x4];
    /* 0x0084 */ s32 unk84;
    /* 0x0088 */ u8 pad88[0x10];
    /* 0x0098 */ s32 unk98;
    /* 0x009C */ s32 unk9C;
    /* 0x00A0 */ s32 unkA0;
    /* 0x00A4 */ u8 padA4[0x4];
    /* 0x00A8 */ s32 unkA8;
};

struct Game2B6 {
    /* 0x0000 */ s32 mode;
    /* 0x0004 */ u8 pad4[0x20];
    /* 0x0024 */ GameB6 game;
};

struct HudB6 {
    /* 0x0000 */ u8 pad0[0xCC9];
    /* 0x0CC9 */ u8 unkCC9;
    /* 0x0CCA */ u8 padCCA[0x5AE];
    /* 0x1278 */ s32 unk1278;
};

struct HudSubB6 {
    /* 0x0000 */ u8 pad0[0x1C];
    /* 0x001C */ s32 unk1C;
};

struct GStateB6 {
    /* 0x0000 */ u8 pad0[0xD];
    /* 0x000D */ u8 unkD;
    /* 0x000E */ u8 padE[0xF];
    /* 0x001D */ u8 unk1D;
    /* 0x001E */ u8 pad1E[0x12A];
    /* 0x0148 */ u8 unk148;
    /* 0x0149 */ u8 pad149[0x19];
    /* 0x0162 */ u8 unk162;
    /* 0x0163 */ u8 pad163[0x475];
    /* 0x05D8 */ GameB6 sub;
};

struct PlrObj {
    /* 0x0000 */ u8 pad0[0x8];
    /* 0x0008 */ Vec3f pos;
    /* 0x0014 */ u8 pad14[0xB0];
    /* 0x00C4 */ s32 unkC4;
    /* 0x00C8 */ u8 padC8[0x8];
    /* 0x00D0 */ s32 unkD0;
    /* 0x00D4 */ u8 padD4[0x2C];
    /* 0x0100 */ u32 flags100;
    /* 0x0104 */ u8 pad104[0xD4];
    /* 0x01D8 */ Plr* unk1D8;
    /* 0x01DC */ u8 pad1DC[0x104];
    /* 0x02E0 */ s32 unk2E0;
};

struct PathB6 {
    /* 0x0000 */ u8 pad0[0x34];
    /* 0x0034 */ f32 unk34;
    /* 0x0038 */ f32 unk38;
    /* 0x003C */ f32 unk3C;
    /* 0x0040 */ f32 unk40;
    /* 0x0044 */ u8 pad44[0x1A];
    /* 0x005E */ u8 unk5E;
};

struct AimB6 {
    /* 0x0000 */ u8 pad0[0x8];
    /* 0x0008 */ Vec3f pos;
    /* 0x0014 */ u8 pad14[0x8];
    /* 0x001C */ Vec3f aim;
    /* 0x0028 */ u8 pad28[0x14C];
    /* 0x0174 */ Vec3f out;
};

struct OutB6 {
    /* 0x0000 */ u8 pad0[0x1C];
    /* 0x001C */ s32 unk1C;
    /* 0x0020 */ s32 unk20;
    /* 0x0024 */ s32 unk24;
};

struct HitB6 {
    /* 0x0000 */ Plr* unk0;
    /* 0x0004 */ s32 unk4;
};

struct Plr {
    /* 0x0000 */ u8 unk0;
    /* 0x0001 */ u8 unk1;
    /* 0x0002 */ u8 pad2[0x1];
    /* 0x0003 */ u8 unk3;
    /* 0x0004 */ u8 pad4[0x4];
    /* 0x0008 */ Vec3f pos;
    /* 0x0014 */ s32 unk14;
    /* 0x0018 */ PlrCls* unk18;
    /* 0x001C */ u8 pad1C[0x4];
    /* 0x0020 */ s32 unk20;
    /* 0x0024 */ u8 pad24[0x14];
    /* 0x0038 */ u32 flags38;
    /* 0x003C */ u8 pad3C[0x14];
    /* 0x0050 */ f32 unk50;
    /* 0x0054 */ f32 unk54;
    /* 0x0058 */ f32 unk58;
    /* 0x005C */ Vec4f unk5C;
    /* 0x006C */ f32 unk6C;
    /* 0x0070 */ s32 unk70;
    /* 0x0074 */ u8 pad74[0x40];
    /* 0x00B4 */ s32 unkB4;
    /* 0x00B8 */ u8 padB8[0xC];
    /* 0x00C4 */ s32 unkC4;
    /* 0x00C8 */ u8 padC8[0x8];
    /* 0x00D0 */ s32 unkD0;
    /* 0x00D4 */ u8 padD4[0x10];
    /* 0x00E4 */ u16 unkE4;
    /* 0x00E6 */ u8 padE6[0x1A];
    /* 0x0100 */ u32 flags100;
    /* 0x0104 */ u8 pad104[0xA];
    /* 0x010E */ s8 unk10E;
    /* 0x010F */ u8 pad10F[0x1D];
    /* 0x012C */ Plr* unk12C;
    /* 0x0130 */ u8 pad130[0x44];
    /* 0x0174 */ s32 unk174;
    /* 0x0178 */ u8 pad178[0x5C];
    /* 0x01D4 */ f32 unk1D4;
    /* 0x01D8 */ Plr* unk1D8;
    /* 0x01DC */ u8 pad1DC[0x114];
    /* 0x02F0 */ Vec3f unk2F0;
    /* 0x02FC */ s32 unk2FC;
    /* 0x0300 */ u8 pad300[0x44];
    /* 0x0344 */ Vec4f unk344;
    /* 0x0354 */ f32 unk354;
    /* 0x0358 */ s32 unk358;
    /* 0x035C */ u8 pad35C[0x8C];
    /* 0x03E8 */ u32 flags3E8;
    /* 0x03EC */ u8 pad3EC[0x98];
    /* 0x0484 */ PlrAux* unk484;
    /* 0x0488 */ u8 pad488[0x10C];
    /* 0x0594 */ s32 unk594;
    /* 0x0598 */ u8 pad598[0xC];
    /* 0x05A4 */ s32 unk5A4;
    /* 0x05A8 */ s32 unk5A8;
    /* 0x05AC */ u8 pad5AC[0x24];
    /* 0x05D0 */ s32 unk5D0;
    /* 0x05D4 */ s32 unk5D4;
    /* 0x05D8 */ PlrStats* stats;
    /* 0x05DC */ Pawn* unk5DC;
    /* 0x05E0 */ s32 unk5E0;
    /* 0x05E4 */ s32 unk5E4;
    /* 0x05E8 */ u8 pad5E8[0x2];
    /* 0x05EA */ s16 unk5EA;
    /* 0x05EC */ u8 pad5EC[0x8];
    /* 0x05F4 */ s16 unk5F4[8];
    /* 0x0604 */ s8 unk604;
    /* 0x0605 */ u8 pad605[0x29];
    /* 0x062E */ s16 unk62E;
    /* 0x0630 */ u8 pad630[0x20];
    /* 0x0650 */ s16 unk650;
    /* 0x0652 */ u8 pad652[0x6];
    /* 0x0658 */ f32 unk658;
    /* 0x065C */ u8 pad65C[0x8];
    /* 0x0664 */ s32 flags664;
    /* 0x0668 */ u8 pad668[0x8];
    /* 0x0670 */ f32 unk670;
    /* 0x0674 */ u8 pad674[0x14];
    /* 0x0688 */ u8 unk688[8];
    /* 0x0690 */ u8 pad690[0x8];
    /* 0x0698 */ u8* unk698;
    /* 0x069C */ u8 pad69C[0x14];
    /* 0x06B0 */ u32 unk6B0;
    /* 0x06B4 */ u8 pad6B4[0xC];
    /* 0x06C0 */ f32 unk6C0;
    /* 0x06C4 */ u8 pad6C4[0x4];
    /* 0x06C8 */ f32 unk6C8;
    /* 0x06CC */ u8 pad6CC[0x1C];
    /* 0x06E8 */ Vec3f unk6E8;
    /* 0x06F4 */ u8 pad6F4[0x14];
    /* 0x0708 */ f32 unk708;
    /* 0x070C */ u8 pad70C[0xC];
    /* 0x0718 */ f32 unk718;
    /* 0x071C */ u8 pad71C[0x8];
    /* 0x0724 */ f32 unk724;
    /* 0x0728 */ f32 unk728;
    /* 0x072C */ f32 unk72C;
    /* 0x0730 */ f32 unk730;
    /* 0x0734 */ f32 unk734;
    /* 0x0738 */ f32 unk738;
    /* 0x073C */ f32 unk73C;
    /* 0x0740 */ f32 unk740;
    /* 0x0744 */ f32 unk744;
    /* 0x0748 */ u8 pad748[0x38];
    /* 0x0780 */ f32 unk780;
    /* 0x0784 */ u8 pad784[0x70];
    /* 0x07F4 */ f32 unk7F4;
    /* 0x07F8 */ f32 unk7F8;
    /* 0x07FC */ PathB6* unk7FC;
    /* 0x0800 */ f32 unk800;
    /* 0x0804 */ f32 unk804;
    /* 0x0808 */ f32 unk808;
    /* 0x080C */ u8 pad80C[0x34];
    /* 0x0840 */ s32 unk840;
    /* 0x0844 */ u8 pad844[0xC];
    /* 0x0850 */ s32 unk850;
    /* 0x0854 */ u8 pad854[0x18];
    /* 0x086C */ s32 unk86C;
    /* 0x0870 */ u8 pad870[0xC8];
    /* 0x0938 */ u8 unk938[4];
    /* 0x093C */ u8 pad93C[0x618];
    /* 0x0F54 */ s32 unkF54;
    /* 0x0F58 */ u8 padF58[0x38];
    /* 0x0F90 */ s32 unkF90;
    /* 0x0F94 */ u8 padF94[0x228];
    /* 0x11BC */ s32 unk11BC;
    /* 0x11C0 */ s32 unk11C0;
    /* 0x11C4 */ f32 unk11C4;
    /* 0x11C8 */ u8 pad11C8[0x10];
    /* 0x11D8 */ f32 unk11D8;
    /* 0x11DC */ u8 pad11DC[0x8];
    /* 0x11E4 */ f32 unk11E4;
    /* 0x11E8 */ u8 pad11E8[0x14];
    /* 0x11FC */ f32 unk11FC;
    /* 0x1200 */ Vec3f unk1200;
    /* 0x120C */ s32 unk120C;
    /* 0x1210 */ s32 unk1210;
    /* 0x1214 */ s32 unk1214;
    /* 0x1218 */ u8 pad1218[0x14];
    /* 0x122C */ s32 unk122C;
    /* 0x1230 */ f32 unk1230;
    /* 0x1234 */ u8 pad1234[0x4];
    /* 0x1238 */ s32 unk1238;
    /* 0x123C */ u8 pad123C[0xC];
    /* 0x1248 */ PlrEnt ent[5];
    /* 0x12C0 */ f32 unk12C0;
    /* 0x12C4 */ u8 pad12C4[0x80];
    /* 0x1344 */ PlrRec21 rec[5];
    /* 0x13AD */ u8 pad13AD[0x3];
    /* 0x13B0 */ s32 unk13B0;
    /* 0x13B4 */ u8 pad13B4[0x24];
    /* 0x13D8 */ Plr* unk13D8;
    /* 0x13DC */ u8 pad13DC[0x4];
    /* 0x13E0 */ s32 unk13E0;
    /* 0x13E4 */ u8 pad13E4[0x8];
    /* 0x13EC */ u8 unk13EC[0x20];
    /* 0x140C */ u8 pad140C[0x44];
    /* 0x1450 */ s32 unk1450;
    /* 0x1454 */ u8* brain;
    /* 0x1458 */ Vec3f unk1458;
    /* 0x1464 */ u8 pad1464[0xC];
    /* 0x1470 */ Vec3f unk1470;
    /* 0x147C */ s32 unk147C;
    /* 0x1480 */ u8 pad1480[0x260];
    /* 0x16E0 */ Plr* next;
    /* 0x16E4 */ u32 unk16E4;
};

struct PlrGroup {
    /* 0x0000 */ s32* unk0;
    /* 0x0004 */ Plr* unk4;
    /* 0x0008 */ s32 unk8;
    /* 0x000C */ u8 padC[0x14];
    /* 0x0020 */ Plr* head;
    /* 0x0024 */ u8 pad24[0x1C];
    /* 0x0040 */ s32 unk40;
};

#endif
