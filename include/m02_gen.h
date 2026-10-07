#ifndef M02_GEN_H
#define M02_GEN_H
#include "m02_types.h"

typedef struct M2Own M2Own;
typedef struct M2Link M2Link;
typedef struct M2St M2St;
typedef struct M2Act M2Act;
typedef struct M2Cls M2Cls;
typedef struct M2Row18 M2Row18;
typedef struct M2G M2G;
typedef struct M2Sub698 M2Sub698;
typedef struct M2Stats M2Stats;
typedef struct M2Pawn M2Pawn;
typedef struct M2Sub1454 M2Sub1454;
typedef struct M2Row190 M2Row190;
typedef struct M2Cam M2Cam;
typedef struct M2Act2 M2Act2;
typedef struct M2Own2 M2Own2;
typedef struct M2Args M2Args;
typedef struct M2G2 M2G2;
typedef struct M2Cfg M2Cfg;
typedef struct M2P M2P;
typedef struct M2QDef M2QDef;
typedef struct M2Q M2Q;
typedef struct M2Sub80C M2Sub80C;
typedef struct M2P3 M2P3;
typedef struct M2Q3 M2Q3;
typedef struct M2Tgt M2Tgt;
typedef struct M2HDef M2HDef;
typedef struct M2H M2H;

struct M2Own {
    /* 0x0000 */ u8 pad0[0x8];
    /* 0x0008 */ Vec3f pos;
    /* 0x0014 */ u8 pad14[0x580];
    /* 0x0594 */ s32 unk594;
    /* 0x0598 */ u8 pad598[0x3C];
    /* 0x05D4 */ s32 unk5D4;
    /* 0x05D8 */ M2Stats* stats;
    /* 0x05DC */ M2Pawn* pawn;
    /* 0x05E0 */ u8 pad5E0[0x14];
    /* 0x05F4 */ s16 unk5F4;
    /* 0x05F6 */ s16 unk5F6;
    /* 0x05F8 */ s16 unk5F8;
    /* 0x05FA */ u8 pad5FA[0x34];
    /* 0x062E */ s16 unk62E;
    /* 0x0630 */ u8 pad630[0x20];
    /* 0x0650 */ s16 unk650;
    /* 0x0652 */ u8 pad652[0x46];
    /* 0x0698 */ M2Sub698* unk698;
    /* 0x069C */ u8 pad69C[0x10];
    /* 0x06AC */ u32 unk6AC;
    /* 0x06B0 */ u32 unk6B0;
    /* 0x06B4 */ u8 pad6B4[0xBC];
    /* 0x0770 */ s16 unk770;
    /* 0x0772 */ u8 pad772[0x16];
    /* 0x0788 */ s32 unk788;
    /* 0x078C */ s32 unk78C;
    /* 0x0790 */ u8 pad790[0x58];
    /* 0x07E8 */ s32 unk7E8;
    /* 0x07EC */ u8 pad7EC[0x9C8];
    /* 0x11B4 */ s32 unk11B4;
    /* 0x11B8 */ u8 pad11B8[0x20];
    /* 0x11D8 */ f32 unk11D8;
    /* 0x11DC */ u8 pad11DC[0x18];
    /* 0x11F4 */ f32 unk11F4;
    /* 0x11F8 */ s32 unk11F8;
    /* 0x11FC */ s32 unk11FC;
    /* 0x1200 */ u8 pad1200[0x2C];
    /* 0x122C */ u32 unk122C;
    /* 0x1230 */ f32 unk1230;
    /* 0x1234 */ u8 pad1234[0x21C];
    /* 0x1450 */ s32 unk1450;
    /* 0x1454 */ M2Sub1454* unk1454;
    /* 0x1458 */ u8 pad1458[0x8];
};

struct M2Link {
    /* 0x0000 */ u8 pad0[0x8];
    /* 0x0008 */ M2Fn cb8;
    /* 0x000C */ u8 padC[0x4];
};

struct M2St {
    /* 0x0000 */ u8 pad0[0x30];
    /* 0x0030 */ M2Link* link;
    /* 0x0034 */ s8 unk34;
    /* 0x0035 */ s8 unk35;
    /* 0x0036 */ u8 pad36[0x2E];
    /* 0x0064 */ f32 unk64;
    /* 0x0068 */ u8 pad68[0x63];
    /* 0x00CB */ s8 unkCB;
    /* 0x00CC */ u8 padCC[0x58];
    /* 0x0124 */ f32 unk124;
    /* 0x0128 */ f32 unk128;
    /* 0x012C */ u8 pad12C[0x4];
    /* 0x0130 */ f32 unk130;
    /* 0x0134 */ u8 pad134[0x4];
    /* 0x0138 */ s32 unk138;
    /* 0x013C */ s32 unk13C;
    /* 0x0140 */ u8 pad140[0x4];
    /* 0x0144 */ s32 unk144;
    /* 0x0148 */ f32 unk148;
    /* 0x014C */ u8 pad14C[0x4];
};

struct M2Act {
    /* 0x0000 */ u8 pad0[0x1];
    /* 0x0001 */ u8 unk1;
    /* 0x0002 */ u8 pad2[0xFE];
    /* 0x0100 */ u32 flags;
    /* 0x0104 */ u8 pad104[0xD4];
    /* 0x01D8 */ M2Own* owner;
};

struct M2Cls {
    /* 0x0000 */ u8 pad0[0xE];
    /* 0x000E */ u8 unkE;
    /* 0x000F */ u8 padF[0x5];
    /* 0x0014 */ u32 unk14;
    /* 0x0018 */ u8 pad18[0x44];
    /* 0x005C */ M2Fn fn5C;
};

struct M2Row18 {
    /* 0x0000 */ s16 unk0;
    /* 0x0002 */ u8 pad2[0x16];
};

struct M2G {
    /* 0x0000 */ u8 pad0[0x54];
    /* 0x0054 */ s32 unk54;
    /* 0x0058 */ u8 pad58[0x18];
    /* 0x0070 */ s32 unk70;
    /* 0x0074 */ u8 pad74[0xC];
};

struct M2Sub698 {
    /* 0x0000 */ u8 pad0[0x168];
    /* 0x0168 */ f32 unk168;
    /* 0x016C */ u8 pad16C[0x4];
};

struct M2Stats {
    /* 0x0000 */ u8 pad0[0x8F];
    /* 0x008F */ u8 unk8F;
};

struct M2Pawn {
    /* 0x0000 */ u8 pad0[0x128];
    /* 0x0128 */ Vec3f unk128;
    /* 0x0134 */ u8 pad134[0xC];
};

struct M2Sub1454 {
    /* 0x0000 */ u8 pad0[0x23C];
    /* 0x023C */ s32 unk23C;
};

struct M2Row190 {
    /* 0x0000 */ u8 unk0;
    /* 0x0001 */ u8 pad1[0x18F];
};

struct M2Cam {
    /* 0x0000 */ u8 pad0[0x8];
    /* 0x0008 */ f32 px;
    /* 0x000C */ f32 py;
    /* 0x0010 */ f32 pz;
    /* 0x0014 */ u8 pad14[0x48];
    /* 0x005C */ M2Quat q5C;
    /* 0x006C */ f32 f6C;
    /* 0x0070 */ u8 pad70[0x698];
    /* 0x0708 */ f32 f708;
    /* 0x070C */ u8 pad70C[0xC];
    /* 0x0718 */ f32 f718;
    /* 0x071C */ u8 pad71C[0x8];
    /* 0x0724 */ f32 f724;
    /* 0x0728 */ f32 f728;
    /* 0x072C */ f32 f72C;
    /* 0x0730 */ f32 f730;
    /* 0x0734 */ f32 f734;
    /* 0x0738 */ f32 f738;
    /* 0x073C */ f32 f73C;
    /* 0x0740 */ f32 f740;
    /* 0x0744 */ f32 f744;
    /* 0x0748 */ u8 pad748[0x38];
    /* 0x0780 */ f32 f780;
    /* 0x0784 */ u8 pad784[0x7C];
};

struct M2Act2 {
    /* 0x0000 */ u8 pad0[0x1];
    /* 0x0001 */ u8 unk1;
    /* 0x0002 */ u8 pad2[0x16];
    /* 0x0018 */ M2Cls* unk18;
    /* 0x001C */ u8 pad1C[0x98];
    /* 0x00B4 */ s32 unkB4;
    /* 0x00B8 */ u8 padB8[0x120];
    /* 0x01D8 */ M2Own* owner;
};

struct M2Own2 {
    /* 0x0000 */ u8 pad0[0x5D8];
    /* 0x05D8 */ M2Stats* stats;
    /* 0x05DC */ u8 pad5DC[0xC54];
    /* 0x1230 */ f32 unk1230;
    /* 0x1234 */ u8 pad1234[0x4];
    /* 0x1238 */ s32 unk1238;
    /* 0x123C */ u8 pad123C[0x24];
};

struct M2Args {
    /* 0x0000 */ u8 pad0[0xC];
    /* 0x000C */ s32 unkC;
};

struct M2G2 {
    /* 0x0000 */ u8 pad0[0x54];
    /* 0x0054 */ s32 unk54;
    /* 0x0058 */ u8 pad58[0x1B];
    /* 0x0073 */ u8 unk73;
    /* 0x0074 */ u8 pad74[0xC];
};

struct M2Cfg {
    /* 0x0000 */ u8 pad0[0x8];
    /* 0x0008 */ s32 unk8;
    /* 0x000C */ u8 unkC;
    /* 0x000D */ s8 unkD;
    /* 0x000E */ u8 unkE;
    /* 0x000F */ u8 unkF;
    /* 0x0010 */ u8 pad10[0x7];
    /* 0x0017 */ u8 unk17;
    /* 0x0018 */ u8 pad18[0xD];
    /* 0x0025 */ u8 unk25;
    /* 0x0026 */ u8 pad26[0x46];
    /* 0x006C */ s32 unk6C;
    /* 0x0070 */ s32 unk70;
    /* 0x0074 */ s32 unk74;
    /* 0x0078 */ u8 pad78[0x1C];
    /* 0x0094 */ s32 arr94[36];
    /* 0x0124 */ u8 pad124[0x65];
    /* 0x0189 */ u8 unk189;
    /* 0x018A */ u8 unk18A;
    /* 0x018B */ u8 unk18B;
    /* 0x018C */ u8 unk18C;
    /* 0x018D */ u8 unk18D;
    /* 0x018E */ u8 pad18E[0x2];
};

struct M2P {
    /* 0x0000 */ u8 pad0[0xE4];
    /* 0x00E4 */ u16 unkE4;
    /* 0x00E6 */ u8 padE6[0x28];
    /* 0x010E */ s8 unk10E;
    /* 0x010F */ u8 pad10F[0x541];
    /* 0x0650 */ s16 unk650;
    /* 0x0652 */ u8 pad652[0x6];
    /* 0x0658 */ f32 f658;
    /* 0x065C */ u8 pad65C[0x4C];
    /* 0x06A8 */ f32 f6A8;
    /* 0x06AC */ u8 pad6AC[0x4];
    /* 0x06B0 */ u32 unk6B0;
    /* 0x06B4 */ u8 pad6B4[0xC];
    /* 0x06C0 */ f32 f6C0;
    /* 0x06C4 */ u8 pad6C4[0x4];
    /* 0x06C8 */ f32 f6C8;
    /* 0x06CC */ u8 pad6CC[0x18];
    /* 0x06E4 */ f32 f6E4;
    /* 0x06E8 */ u8 pad6E8[0x4];
    /* 0x06EC */ f32 f6EC;
    /* 0x06F0 */ u8 pad6F0[0x34];
    /* 0x0724 */ f32 f724;
    /* 0x0728 */ u8 pad728[0x4];
    /* 0x072C */ f32 f72C;
    /* 0x0730 */ f32 f730;
    /* 0x0734 */ f32 f734;
    /* 0x0738 */ f32 f738;
    /* 0x073C */ u8 pad73C[0xAC];
    /* 0x07E8 */ s32 unk7E8;
    /* 0x07EC */ u8 pad7EC[0x80];
    /* 0x086C */ s32 unk86C;
    /* 0x0870 */ u8 pad870[0x954];
    /* 0x11C4 */ f32 f11C4;
    /* 0x11C8 */ u8 pad11C8[0x10];
    /* 0x11D8 */ f32 f11D8;
    /* 0x11DC */ u8 pad11DC[0x64];
};

struct M2QDef {
    /* 0x0000 */ u8 pad0[0x14];
    /* 0x0014 */ u32 unk14;
    /* 0x0018 */ u8 pad18[0x8];
};

struct M2Q {
    /* 0x0000 */ u8 pad0[0x8];
    /* 0x0008 */ Vec3f pos;
    /* 0x0014 */ u8 pad14[0x4];
    /* 0x0018 */ M2QDef* def;
    /* 0x001C */ u8 pad1C[0x1C];
    /* 0x0038 */ u32 flags38;
    /* 0x003C */ u8 pad3C[0x4];
};

struct M2Sub80C {
    /* 0x0000 */ u8 pad0[0x1A4];
    /* 0x01A4 */ s8 unk1A4;
    /* 0x01A5 */ u8 pad1A5[0xB];
};

struct M2P3 {
    /* 0x0000 */ u8 pad0[0x5DC];
    /* 0x05DC */ M2Pawn* pawn;
    /* 0x05E0 */ u8 pad5E0[0xBC];
    /* 0x069C */ f32 f69C;
    /* 0x06A0 */ u8 pad6A0[0x18];
    /* 0x06B8 */ u32 unk6B8;
    /* 0x06BC */ u8 pad6BC[0x4];
    /* 0x06C0 */ f32 f6C0;
    /* 0x06C4 */ f32 f6C4;
    /* 0x06C8 */ u8 pad6C8[0x3C];
    /* 0x0704 */ f32 f704;
    /* 0x0708 */ u8 pad708[0x24];
    /* 0x072C */ f32 f72C;
    /* 0x0730 */ u8 pad730[0xC];
    /* 0x073C */ Vec3f v73C;
    /* 0x0748 */ u8 pad748[0xC4];
    /* 0x080C */ M2Sub80C* unk80C;
    /* 0x0810 */ s32 unk810;
    /* 0x0814 */ Vec3f v814;
    /* 0x0820 */ u8 pad820[0x18];
    /* 0x0838 */ f32 f838;
    /* 0x083C */ f32 f83C;
    /* 0x0840 */ u8 pad840[0x10];
};

struct M2Q3 {
    /* 0x0000 */ u8 pad0[0x8];
    /* 0x0008 */ Vec3f pos;
    /* 0x0014 */ u8 pad14[0x58];
    /* 0x006C */ f32 f6C;
    /* 0x0070 */ u8 pad70[0x10];
};

struct M2Tgt {
    /* 0x0000 */ u8 pad0[0x8];
    /* 0x0008 */ Vec3f pos;
    /* 0x0014 */ u8 pad14[0x5C];
    /* 0x0070 */ f32 unk70;
    /* 0x0074 */ u8 pad74[0x1D4];
    /* 0x0248 */ Vec3f v248;
    /* 0x0254 */ u8 pad254[0x3DA];
    /* 0x062E */ s16 unk62E;
    /* 0x0630 */ u8 pad630[0x10B0];
    /* 0x16E0 */ M2Tgt* next;
    /* 0x16E4 */ u8 pad16E4[0x1C];
};

struct M2HDef {
    /* 0x0000 */ u8 pad0[0x24];
    /* 0x0024 */ f32 unk24;
    /* 0x0028 */ u8 pad28[0x8];
};

struct M2H {
    /* 0x0000 */ u8 pad0[0x18];
    /* 0x0018 */ M2HDef* unk18;
    /* 0x001C */ u8 pad1C[0x158];
    /* 0x0174 */ s32 unk174;
    /* 0x0178 */ u8 pad178[0x2E4];
    /* 0x045C */ s32 unk45C;
    /* 0x0460 */ u8 pad460[0x178];
    /* 0x05D8 */ M2Stats* stats;
    /* 0x05DC */ u8 pad5DC[0x8];
    /* 0x05E4 */ s32 unk5E4;
    /* 0x05E8 */ u8 pad5E8[0xC44];
    /* 0x122C */ u32 unk122C;
    /* 0x1230 */ u8 pad1230[0x10];
};

#endif
