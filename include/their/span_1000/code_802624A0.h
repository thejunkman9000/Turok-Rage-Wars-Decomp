#ifndef UNBAKE_SPAN_1000_CODE_802624A0_H
#define UNBAKE_SPAN_1000_CODE_802624A0_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct func_80262CA8_S1;
/* unbake published declaration: published_04ae91f5172862d828227736 */
typedef struct func_80262CA8_S1 func_80262CA8_S1;

struct func_802626BC_S1;
/* unbake published declaration: published_1ac574a73d966e5e2631fc8f */
struct func_802626BC_S1 {
    char pad0[0x4];
    u16 unk4;
    char pad4[0x8 - 0x4 - sizeof(u16)];
    u16 unk8;
    char pad8[0xC - 0x8 - sizeof(u16)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    func_802626BC_S1_U10 unk10;
};

struct func_80262ABC_S1;
/* unbake published declaration: published_1c8db06c7ca6a42673481aa7 */
typedef struct func_80262ABC_S1 func_80262ABC_S1;

struct Effect_func_80262A9C_de;
/* unbake published declaration: published_5a22be9bedf7591b00011ed2 */
typedef struct Effect_func_80262A9C_de Effect_func_80262A9C_de;

struct EffectDesc;
/* unbake published declaration: published_6d439bb47d71b5e03093d9ab */
typedef struct EffectDesc EffectDesc;

struct Effect_func_80262A9C_de;
/* unbake published declaration: published_88616c5df4d92ee039c40388 */
struct Effect_func_80262A9C_de {
    char pad0[0x2F0];
    s32 *ref;
};

struct EffectDesc;
/* unbake published declaration: published_d8c290c233231911887e7687 */
struct EffectDesc {
    u8 id;
    char pad1[7];
    Vec3 position;
    s32 owner;
    s32 count;
    Vec3 direction;
    char pad28[0x28];
    Vec3 color;
    char pad5C[0x10];
    f32 scale;
    char pad70[0x74];
    u16 variant;
};

/* unbake published declaration: published_2657b0315e42d022f822a26b */
extern Effect_func_80262A9C_de *func_80262A9C_de(void *scene, EffectDesc *desc);

/* unbake published declaration: published_29cf9335d3078e7a7f6e7d5d */
extern void *func_80262FF8_de(s32 arg0, s32 *arg1);

struct Record_func_802627A0_de;
/* unbake published declaration: published_439f2aed5e0a7ad66fd59694 */
struct Record_func_802627A0_de {
    char pad0[0x1C];
    u16 count;
    u16 angle;
};

struct SharedPlayer_func_80226A34_de;
/* unbake published declaration: published_4bd2620cecf147ee9595a473 */
extern void func_802631B0_de(char * arg0, struct SharedPlayer_func_80226A34_de * arg1);

struct func_802624A0_S1;
/* unbake published declaration: published_560383e26444757abcf3a256 */
typedef struct func_802624A0_S1 func_802624A0_S1;

struct ResourceEntry;
/* unbake published declaration: published_5c32b168606efb63ae05fd83 */
typedef struct ResourceEntry ResourceEntry;

struct Effect_func_80262E88_de;
/* unbake published declaration: published_619e0e2e134cbe7684a285b1 */
typedef struct Effect_func_80262E88_de Effect_func_80262E88_de;

struct func_802624A0_S1;
/* unbake published declaration: published_6201f6cd8ccffa3133f9e039 */
struct func_802624A0_S1 {
    char pad0[0x4];
    short unk4;
    char pad4[0x6 - 0x4 - sizeof(short)];
    short unk6;
    char pad6[0x8 - 0x6 - sizeof(short)];
    short unk8;
    char pad8[0xA - 0x8 - sizeof(short)];
    unsigned char unkA;
    char padA[0xB - 0xA - sizeof(unsigned char)];
    unsigned char unkB;
    char padB[0x10 - 0xB - sizeof(unsigned char)];
    int unk10;
};

struct Six;
/* unbake published declaration: published_6e76441e9ad61e2366a34aee */
struct Six {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};

struct ObjectLinks5F28;
/* unbake published declaration: published_7f0fd07a104091f0ff03afc2 */
struct ObjectLinks5F28 {
    unsigned char padding_0[24320];
    void *unk_5F00;
    unsigned char padding_5F04[32];
    s32 unk_5F24;
};

union func_80262EA8_S1_U5F14;
/* unbake published declaration: published_e32ef54d6c152ebd0d8a12a3 */
typedef union func_80262EA8_S1_U5F14 func_80262EA8_S1_U5F14;

struct Effect_func_80262E88_de;
/* unbake published declaration: published_d45ac7bc286142b8043f0521 */
struct Effect_func_80262E88_de {
    char pad0[0xE8];
    f32 min[3];
    f32 max[3];
    char pad100[0];
    s32 flags;
    char pad104[0x70];
    s32 busy;
    char pad178[0x2EC - 0x178];
    struct Effect_func_80262E88_de *next;
    s32 *ref;
};

struct Effect_func_80262E88_de;
union func_80262EA8_S1_U5F14;
/* unbake published declaration: published_e440a39d4e3eb52835bc4ad9 */
union func_80262EA8_S1_U5F14 {
    struct Effect_func_80262E88_de * v0;
    char v1;
};

struct func_80262EA8_S1;
/* unbake published declaration: published_80809748cd7e9b5f9ceee72b */
struct func_80262EA8_S1 {
    char pad0[0x5F00];
    char unk5F00;
    char pad5F00[0x5F14 - 0x5F00 - sizeof(char)];
    func_80262EA8_S1_U5F14 unk5F14;
};

struct ObjectLinks5F28;
/* unbake published declaration: published_85461def3235f39761c7c6ae */
typedef struct ObjectLinks5F28 ObjectLinks5F28;

struct Record_func_802627A0_de;
/* unbake published declaration: published_89abfbcce421942c59852c10 */
typedef struct Record_func_802627A0_de Record_func_802627A0_de;

struct func_802626BC_S1;
/* unbake published declaration: published_91f4de581a231bc784b678db */
typedef struct func_802626BC_S1 func_802626BC_S1;

/* unbake published declaration: published_91f992dd3a85d2ca5a30f160 */
extern void func_802624A8_de(void *arg0);

struct func_80262CA8_S1;
/* unbake published declaration: published_95f48bbb559d4696f0255d99 */
struct func_80262CA8_S1 {
    char pad0[0x174];
    s32 unk174;
    char pad174[0x2F0 - 0x174 - sizeof(s32)];
    s32 * unk2F0;
};

struct BitReader;
/* unbake published declaration: published_989ad5e0b3f405ef5cfdfa32 */
typedef struct BitReader BitReader;

/* unbake published declaration: published_ad06b5fa1e9e994b86426ba6 */
extern float D_800C4258_de;

union func_80262ABC_S1_U5F00;
/* unbake published declaration: published_bd0022560d7206aed166fa65 */
typedef union func_80262ABC_S1_U5F00 func_80262ABC_S1_U5F00;

struct Effect_func_80262A9C_de;
union func_80262ABC_S1_U5F00;
/* unbake published declaration: published_ef7870ab938688ed4fda74a6 */
union func_80262ABC_S1_U5F00 {
    struct Effect_func_80262A9C_de * v0;
    char v1;
};

struct func_80262ABC_S1;
/* unbake published declaration: published_c08c3177527ef7bb16aaa56a */
struct func_80262ABC_S1 {
    char pad0[0x5F00];
    func_80262ABC_S1_U5F00 unk5F00;
    char pad5F00[0x5F14 - 0x5F00 - sizeof(func_80262ABC_S1_U5F00)];
    char unk5F14;
    char pad5F14[0x5F24 - 0x5F14 - sizeof(char)];
    s32 unk5F24;
};

struct BitReader;
/* unbake published declaration: published_cf0e9f1d9dc171c45712ceff */
struct BitReader {
    u8 *data;
    s32 bitPos;
};

struct func_80262EA8_S1;
/* unbake published declaration: published_d9c2c26dcbf1bc0dc57baf92 */
typedef struct func_80262EA8_S1 func_80262EA8_S1;

struct ResourceEntry;
/* unbake published declaration: published_dd4a67393f6478a25a913c27 */
struct ResourceEntry {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
};

struct Six;
/* unbake published declaration: published_f82fde6c24a3739c2a841e3f */
typedef struct Six Six;

#endif
