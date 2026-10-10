#ifndef UNBAKE_SPAN_1000_CODE_802192C0_H
#define UNBAKE_SPAN_1000_CODE_802192C0_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "gfx.h"
struct func_80219490_S1;
/* unbake published declaration: published_00af4daaab18587b1c2c1217 */
struct func_80219490_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0x90 - 0x8 - sizeof(s32)];
    s32 unk90;
    char pad90[0x94 - 0x90 - sizeof(s32)];
    s32 unk94;
    char pad94[0x98 - 0x94 - sizeof(s32)];
    s32 unk98;
    char pad98[0x9C - 0x98 - sizeof(s32)];
    f32 unk9C;
    char pad9C[0xA0 - 0x9C - sizeof(f32)];
    f32 unkA0;
    char padA0[0xA8 - 0xA0 - sizeof(f32)];
    f32 unkA8;
    char padA8[0xAC - 0xA8 - sizeof(f32)];
    f32 unkAC;
    char padAC[0xB0 - 0xAC - sizeof(f32)];
    f32 unkB0;
    char padB0[0xB4 - 0xB0 - sizeof(f32)];
    s32 unkB4;
};

struct func_8021CBAC_S1;
/* unbake published declaration: published_02b359446a9ee4aa0145ce0d */
struct func_8021CBAC_S1 {
    char pad0[0x2E8];
    char unk2E8;
    char pad2E8[0x5EA - 0x2E8 - sizeof(char)];
    s16 unk5EA;
    char pad5EA[0x62E - 0x5EA - sizeof(s16)];
    s16 unk62E;
};

struct func_80219434_S1;
/* unbake published declaration: published_02f27b63830137baa1e96030 */
typedef struct func_80219434_S1 func_80219434_S1;

struct ObjectState8E;
/* unbake published declaration: published_0d0fe25adae1c88ee7d75a2f */
typedef struct ObjectState8E ObjectState8E;

struct Player_func_8021C698_de;
/* unbake published declaration: published_111ec6f8f399ee7b35acbef1 */
struct Player_func_8021C698_de {
    char pad0[0x1214];
    s32 marker;
    char pad1218[0x147C - 0x1218];
    s32 second;
    char pad1480[0x1500 - 0x1480];
    UnitMtx views[2];
    UnitMtx markers[2];
};

struct func_8021C9B4_Records;
/* unbake published declaration: published_228cc37b8a9cfd2905d19078 */
typedef struct func_8021C9B4_Records func_8021C9B4_Records;

struct func_8021C9B4_S1;
/* unbake published declaration: published_2ee09703b30f7c18d93d8dda */
struct func_8021C9B4_S1 {
    char pad0[0x3];
    u8 unk3;
    char pad3[0x8 - 0x3 - sizeof(u8)];
    Triple unk8;
    char pad8[0x18 - 0x8 - sizeof(Triple)];
    void * unk18;
    char pad18[0x70 - 0x18 - sizeof(void*)];
    f32 unk70;
    char pad70[0x5D8 - 0x70 - sizeof(f32)];
    void * unk5D8;
    char pad5D8[0x86C - 0x5D8 - sizeof(void*)];
    s32 unk86C;
    char pad86C[0x1210 - 0x86C - sizeof(s32)];
    s32 unk1210;
};

struct func_8021C9B4_S1;
/* unbake published declaration: published_31e952a9cb84ef4f636876d5 */
typedef struct func_8021C9B4_S1 func_8021C9B4_S1;

/* unbake published declaration: published_371bc1d87c4668137ff21d1c */
extern float D_800C22FC_de;

struct func_80219408_S1;
/* unbake published declaration: published_3ca0ebecfbb58d16ccd0e66f */
struct func_80219408_S1 {
    char pad0[0x1];
    char unk1;
    char pad1[0x2 - 0x1 - sizeof(char)];
    short unk2;
};

struct ObjectLinks16D8;
/* unbake published declaration: published_440054d13516028d2c414902 */
struct ObjectLinks16D8 {
    char pad0[0x8];
    Vec3 unk_8;
    char pad8[0x18 - 0x8 - sizeof(Vec3)];
    ObjectLinks4_3 unk_18;
    char pad18[0x5D4 - 0x18 - sizeof(ObjectLinks4_3)];
    s32 unk_5D4;
    char pad5D4[0x5D8 - 0x5D4 - sizeof(s32)];
    char * unk_5D8;
    char pad5D8[0x658 - 0x5D8 - sizeof(char*)];
    s32 unk_658;
    char pad658[0x668 - 0x658 - sizeof(s32)];
    s32 unk_668;
    char pad668[0x66C - 0x668 - sizeof(s32)];
    s32 unk_66C;
    char pad66C[0x6C0 - 0x66C - sizeof(s32)];
    s32 unk_6C0;
    char pad6C0[0x6C4 - 0x6C0 - sizeof(s32)];
    s32 unk_6C4;
    char pad6C4[0x6C8 - 0x6C4 - sizeof(s32)];
    s32 unk_6C8;
    char pad6C8[0x6CC - 0x6C8 - sizeof(s32)];
    s32 unk_6CC;
    char pad6CC[0x6D0 - 0x6CC - sizeof(s32)];
    s32 unk_6D0;
    char pad6D0[0x6D4 - 0x6D0 - sizeof(s32)];
    s32 unk_6D4;
    char pad6D4[0x6D8 - 0x6D4 - sizeof(s32)];
    s32 unk_6D8;
    char pad6D8[0x6DC - 0x6D8 - sizeof(s32)];
    s32 unk_6DC;
    char pad6DC[0x6E4 - 0x6DC - sizeof(s32)];
    s32 unk_6E4;
    char pad6E4[0x6E8 - 0x6E4 - sizeof(s32)];
    Vec3 unk_6E8;
    char pad6E8[0x6F4 - 0x6E8 - sizeof(Vec3)];
    func_80203908_S3_U124 unk_6F4;
    char pad6F4[0x6F8 - 0x6F4 - sizeof(func_80203908_S3_U124)];
    Vec3 unk_6F8;
    char pad6F8[0x704 - 0x6F8 - sizeof(Vec3)];
    f32 unk_704;
    char pad704[0x708 - 0x704 - sizeof(f32)];
    s32 unk_708;
    char pad708[0x70C - 0x708 - sizeof(s32)];
    s32 unk_70C;
    char pad70C[0x710 - 0x70C - sizeof(s32)];
    s32 unk_710;
    char pad710[0x714 - 0x710 - sizeof(s32)];
    s32 unk_714;
    char pad714[0x718 - 0x714 - sizeof(s32)];
    s32 unk_718;
    char pad718[0x71C - 0x718 - sizeof(s32)];
    s32 unk_71C;
    char pad71C[0x720 - 0x71C - sizeof(s32)];
    s32 unk_720;
    char pad720[0x724 - 0x720 - sizeof(s32)];
    s32 unk_724;
    char pad724[0x728 - 0x724 - sizeof(s32)];
    s32 unk_728;
    char pad728[0x72C - 0x728 - sizeof(s32)];
    s32 unk_72C;
    char pad72C[0x730 - 0x72C - sizeof(s32)];
    s32 unk_730;
    char pad730[0x734 - 0x730 - sizeof(s32)];
    s32 unk_734;
    char pad734[0x738 - 0x734 - sizeof(s32)];
    s32 unk_738;
    char pad738[0x73C - 0x738 - sizeof(s32)];
    s32 unk_73C;
    char pad73C[0x740 - 0x73C - sizeof(s32)];
    f32 unk_740;
    char pad740[0x744 - 0x740 - sizeof(f32)];
    s32 unk_744;
    char pad744[0x748 - 0x744 - sizeof(s32)];
    Triple unk_748;
    char pad748[0x754 - 0x748 - sizeof(Triple)];
    f32 unk_754;
    char pad754[0x758 - 0x754 - sizeof(f32)];
    s32 unk_758;
    char pad758[0x75C - 0x758 - sizeof(s32)];
    s32 unk_75C;
    char pad75C[0x780 - 0x75C - sizeof(s32)];
    s32 unk_780;
    char pad780[0x784 - 0x780 - sizeof(s32)];
    f32 unk_784;
    char pad784[0x788 - 0x784 - sizeof(f32)];
    s32 unk_788;
    char pad788[0x78C - 0x788 - sizeof(s32)];
    s32 unk_78C;
    char pad78C[0x790 - 0x78C - sizeof(s32)];
    s32 unk_790;
    char pad790[0x794 - 0x790 - sizeof(s32)];
    s32 unk_794;
    char pad794[0x798 - 0x794 - sizeof(s32)];
    s32 unk_798;
    char pad798[0x79C - 0x798 - sizeof(s32)];
    s32 unk_79C;
    char pad79C[0x7A0 - 0x79C - sizeof(s32)];
    s32 unk_7A0;
    char pad7A0[0x7A4 - 0x7A0 - sizeof(s32)];
    s32 unk_7A4;
    char pad7A4[0x7A8 - 0x7A4 - sizeof(s32)];
    s32 unk_7A8;
    char pad7A8[0x7AC - 0x7A8 - sizeof(s32)];
    s32 unk_7AC;
    char pad7AC[0x7B0 - 0x7AC - sizeof(s32)];
    func_8022E280_S1_U744 unk_7B0;
    char pad7B0[0x7B4 - 0x7B0 - sizeof(func_8022E280_S1_U744)];
    s32 unk_7B4;
    char pad7B4[0x7B8 - 0x7B4 - sizeof(s32)];
    s32 unk_7B8;
    char pad7B8[0x7C0 - 0x7B8 - sizeof(s32)];
    f32 unk_7C0;
    char pad7C0[0x7C4 - 0x7C0 - sizeof(f32)];
    f32 unk_7C4;
    char pad7C4[0x7C8 - 0x7C4 - sizeof(f32)];
    f32 unk_7C8;
    char pad7C8[0x7CC - 0x7C8 - sizeof(f32)];
    f32 unk_7CC;
    char pad7CC[0x7D0 - 0x7CC - sizeof(f32)];
    f32 unk_7D0;
    char pad7D0[0x7D4 - 0x7D0 - sizeof(f32)];
    f32 unk_7D4;
    char pad7D4[0x7D8 - 0x7D4 - sizeof(f32)];
    Vec3 unk_7D8;
    char pad7D8[0x7E4 - 0x7D8 - sizeof(Vec3)];
    f32 unk_7E4;
    char pad7E4[0x7E8 - 0x7E4 - sizeof(f32)];
    s32 unk_7E8;
    char pad7E8[0x7EC - 0x7E8 - sizeof(s32)];
    s32 unk_7EC;
    char pad7EC[0x7F0 - 0x7EC - sizeof(s32)];
    s32 unk_7F0;
    char pad7F0[0x80C - 0x7F0 - sizeof(s32)];
    s32 unk_80C;
    char pad80C[0x838 - 0x80C - sizeof(s32)];
    f32 unk_838;
    char pad838[0x83C - 0x838 - sizeof(f32)];
    f32 unk_83C;
    char pad83C[0x840 - 0x83C - sizeof(f32)];
    f32 unk_840;
    char pad840[0x848 - 0x840 - sizeof(f32)];
    s32 unk_848;
    char pad848[0x11B4 - 0x848 - sizeof(s32)];
    s32 unk_11B4;
    char pad11B4[0x11B8 - 0x11B4 - sizeof(s32)];
    s32 unk_11B8;
    char pad11B8[0x1450 - 0x11B8 - sizeof(s32)];
    s32 unk_1450;
    char pad1450[0x16D4 - 0x1450 - sizeof(s32)];
    s32 unk_16D4;
};

struct Struct802193C8;
/* unbake published declaration: published_4643b57326c8a2337fdf174e */
typedef struct Struct802193C8 Struct802193C8;

struct func_8021CBAC_S3;
/* unbake published declaration: published_49057fa07e76a2cd3d8d52e1 */
typedef struct func_8021CBAC_S3 func_8021CBAC_S3;

struct func_80219460_S1;
/* unbake published declaration: published_4d1cc2765aca081a3caaa9b8 */
struct func_80219460_S1 {
    char pad0[0x4];
    int unk4;
    char pad4[0xC - 0x4 - sizeof(int)];
    short unkC;
    char padC[0xE - 0xC - sizeof(short)];
    char unkE;
    char padE[0x12 - 0xE - sizeof(char)];
    char unk12;
};

/* unbake published declaration: published_511ac70ee31bcbdd6e3e29cd */
extern float D_800C22B0_us;

/* unbake published declaration: published_5bb2382da4f3c659a3a7275f */
extern float D_800C22D0_de;

struct Cursor;
/* unbake published declaration: published_63f62c45ee32cf0d7d0bdac3 */
struct Cursor {
    s8 state;
    u8 clip;
    s16 frame;
    s16 previous;
};

struct func_8021CBAC_S2;
/* unbake published declaration: published_7c6b5c05e40deac51376bfba */
struct func_8021CBAC_S2 {
    char pad0[0x120];
    s32 unk120;
    char pad120[0x29C - 0x120 - sizeof(s32)];
    f32 unk29C;
};

struct func_8021CBAC_S3;
/* unbake published declaration: published_7e34e12db0dc0e85449c8739 */
struct func_8021CBAC_S3 {
    char pad0[0x44];
    f32 unk44;
    char pad44[0x48 - 0x44 - sizeof(f32)];
    f32 unk48;
    char pad48[0x4C - 0x48 - sizeof(f32)];
    f32 unk4C;
    char pad4C[0x50 - 0x4C - sizeof(f32)];
    f32 unk50;
};

struct func_80219460_S1;
/* unbake published declaration: published_802f7fca018276e4378e3919 */
typedef struct func_80219460_S1 func_80219460_S1;

/* unbake published declaration: published_8b06ef28bb9421cd1dfe15f2 */
extern float D_800C22F8_de;

struct func_80219408_S1;
/* unbake published declaration: published_9447a27efae135fdd1ac5479 */
typedef struct func_80219408_S1 func_80219408_S1;

struct ObjectState8E;
/* unbake published declaration: published_b256f126519a56329635e551 */
struct ObjectState8E {
    unsigned char padding[141];
    s8 state;
};

struct Cursor;
/* unbake published declaration: published_c22d44ff83f8162733fe7093 */
typedef struct Cursor Cursor;

struct Struct802193C8;
/* unbake published declaration: published_cb683ed4cf261441b6f2b330 */
struct Struct802193C8 {
    s8 field0;
    s8 field1;
    s16 field2;
    s16 field4;
};

struct func_8021C9B4_Records;
/* unbake published declaration: published_cbb724e495896d42ab761051 */
struct func_8021C9B4_Records {
    char pad[0x140];
    Slot records[16];
};

struct func_8021CBAC_S2;
/* unbake published declaration: published_d55435d307220429a8286dc8 */
typedef struct func_8021CBAC_S2 func_8021CBAC_S2;

struct func_8021CBAC_S1;
/* unbake published declaration: published_da0607871a816e7de4fb558c */
typedef struct func_8021CBAC_S1 func_8021CBAC_S1;

struct func_80219490_S1;
/* unbake published declaration: published_e3df4ee3d8ed8b29604bdd66 */
typedef struct func_80219490_S1 func_80219490_S1;

struct Player_func_8021C698_de;
/* unbake published declaration: published_e9e3fb1434b4570dde546b96 */
typedef struct Player_func_8021C698_de Player_func_8021C698_de;

struct ObjectLinks16D8;
/* unbake published declaration: published_f36ae8aea2abcccb56c6d98b */
typedef struct ObjectLinks16D8 ObjectLinks16D8;

struct func_80219434_S1;
/* unbake published declaration: published_f6d60c481db216d17af88659 */
struct func_80219434_S1 {
    char pad0[0x1];
    char unk1;
    char pad1[0x4 - 0x1 - sizeof(char)];
    short unk4;
};

#endif
