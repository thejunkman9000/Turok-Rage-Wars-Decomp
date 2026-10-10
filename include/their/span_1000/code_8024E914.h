#ifndef UNBAKE_SPAN_1000_CODE_8024E914_H
#define UNBAKE_SPAN_1000_CODE_8024E914_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "gfx.h"
/* unbake published declaration: published_01d743b79ba7ac1c4e1599d2 */
extern void func_8024F5A0_de(void *arg0);

struct func_8024F490_Inner;
/* unbake published declaration: published_0e5dc0f9ed7bca99e9672fad */
struct func_8024F490_Inner {
    char pad[0x12];
    u8 value;
};

union func_802500A4_S1_UE0;
/* unbake published declaration: published_c30f2269bfae64711e73763c */
typedef union func_802500A4_S1_UE0 func_802500A4_S1_UE0;

union func_802500A4_S1_UE0;
/* unbake published declaration: published_c63e0f3457c19fb115fc9130 */
union func_802500A4_S1_UE0 {
    s8 v0;
    u8 v1;
};

struct func_802500A4_S1;
/* unbake published declaration: published_0edb1fa7d2ad500ed1d1b458 */
struct func_802500A4_S1 {
    char pad0[0x8];
    Vec3 unk8;
    char pad8[0x18 - 0x8 - sizeof(Vec3)];
    void * unk18;
    char pad18[0xD8 - 0x18 - sizeof(void*)];
    u16 unkD8;
    char padD8[0xDC - 0xD8 - sizeof(u16)];
    s32 unkDC;
    char padDC[0xE0 - 0xDC - sizeof(s32)];
    func_802500A4_S1_UE0 unkE0;
};

/* unbake published declaration: published_0f4a3f1a72ea429e15a5873b */
extern float D_800C3DF0_de;

struct func_802500A4_S2;
/* unbake published declaration: published_13ede830ea23240518ccd20a */
struct func_802500A4_S2 {
    char pad0[0xE];
    s8 unkE;
    char padE[0xF - 0xE - sizeof(s8)];
    s8 unkF;
    char padF[0x24 - 0xF - sizeof(s8)];
    s32 unk24;
};

/* unbake published declaration: published_168cd24fafef06418680d72f */
extern float D_800C3E0C_de;

/* unbake published declaration: published_25ff9a737ef22a4d14f8fa4a */
extern void func_8024F108_de(void *arg0);

struct func_8024E914_S1;
/* unbake published declaration: published_284c72757d1842144b943426 */
typedef struct func_8024E914_S1 func_8024E914_S1;

/* unbake published declaration: published_2dabba7382106747c745982a */
extern void func_8024F618_de(void *arg0);

struct func_8024F624_S1;
/* unbake published declaration: published_2f74caa2187c3f729f8e6d61 */
struct func_8024F624_S1 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x18 - 0x10 - sizeof(f32)];
    s32 * unk18;
    char pad18[0x174 - 0x18 - sizeof(s32*)];
    s32 unk174;
    char pad174[0x194 - 0x174 - sizeof(s32)];
    f32 unk194;
    char pad194[0x198 - 0x194 - sizeof(f32)];
    f32 unk198;
};

struct Actor_func_8024ED90_de;
/* unbake published declaration: published_2fa5441ca9994bc57a9367e7 */
typedef struct Actor_func_8024ED90_de Actor_func_8024ED90_de;

struct func_8024F460_S1;
/* unbake published declaration: published_3080b0e41f5a0c6a4ac33309 */
typedef struct func_8024F460_S1 func_8024F460_S1;

struct PropGeometry;
/* unbake published declaration: published_3527b595e7b702a1542946a2 */
typedef struct PropGeometry PropGeometry;

/* unbake published declaration: published_359d132b371b632715fd65b3 */
extern void func_8024F470_de(void *arg0);

struct func_8024F490_S1;
/* unbake published declaration: published_37522aa31c7ac5c3077e1c1a */
typedef struct func_8024F490_S1 func_8024F490_S1;

struct Record_func_8024F960_eu;
/* unbake published declaration: published_3a76a6e98f138308a54f16aa */
struct Record_func_8024F960_eu {
    s32 value;
    f32 scale;
    u16 id;
    u16 segment;
    u16 flags;
    u16 model;
    s16 height;
    s8 extents[6];
    u8 placement;
    u8 cellX;
    u8 cellZ;
};

struct Owner_func_802504B0_de;
/* unbake published declaration: published_3bdcc76af8a00d7de3017c60 */
typedef struct Owner_func_802504B0_de Owner_func_802504B0_de;

struct func_8024F490_Inner;
/* unbake published declaration: published_3bdce5ba768912d8f5f362d2 */
typedef struct func_8024F490_Inner func_8024F490_Inner;

struct PlacedPropRecord;
/* unbake published declaration: published_3c0573cdb8079336232fc715 */
struct PlacedPropRecord {
    s32 value;
    Vec3 position;
    Vec3 scale;
    char pad1C[0];
    u16 extents[6];
    u16 id;
    u16 segment;
    u16 model;
    u8 flags;
    s8 rotation[4];
};

struct PropGeometry;
/* unbake published declaration: published_bce54b9672f163876cd086d1 */
struct PropGeometry {
    char pad0[8];
    f32 radius;
    char padC[0x24 - 0xC];
    u32 radiusSquared;
};

struct PlacedProp;
struct PropGeometry;
/* unbake published declaration: published_3efde3207f260800ec0b8107 */
struct PlacedProp {
    u8 state;
    char pad1[3];
    u16 id;
    char pad6[2];
    Vec3 position;
    void *segment;
    struct PropGeometry *model;
    s32 owner;
    char pad20[8];
    char transform[0x40];
    char matrix[0x40];
    s32 fieldA8;
    s32 fieldAC;
    s32 fieldB0;
    s32 fieldB4;
    Vec3 min;
    Vec3 max;
    s32 key;
    s32 fieldD4;
    u16 flags;
    u8 colorFrame;
    char padDB;
    s32 fieldDC;
    u8 fade;
};

struct PlacedProp;
/* unbake published declaration: published_4ef4918d645c48f803c67486 */
typedef struct PlacedProp PlacedProp;

struct Descriptor_func_80250274_de;
/* unbake published declaration: published_6052a2eb3a42aab31146e483 */
typedef struct Descriptor_func_80250274_de Descriptor_func_80250274_de;

/* unbake published declaration: published_6f286159cffc888fa7ae0503 */
extern void func_8024F634_de(void *arg0);

struct Descriptor_func_80250274_de;
/* unbake published declaration: published_9fb7b1dd9bd39cdd574f6391 */
struct Descriptor_func_80250274_de {
    char pad0[0xE];
    s8 key;
    s8 key2;
    char pad10[2];
    s8 argument;
    char pad13[0x24 - 0x13];
    s32 period;
};

struct Descriptor_func_80250274_de;
struct Owner_func_80250274_de;
/* unbake published declaration: published_7012cafa2e24bb722ddf4d51 */
struct Owner_func_80250274_de {
    char pad0[0x18];
    struct Descriptor_func_80250274_de *descriptor;
    char pad1C[4];
    s32 field20;
    char pad24[4];
    char transform[0xA8];
    s32 flagsD0;
    char padD4[4];
    u16 flagsD8;
    u8 colorFrame;
    char padDB;
    u32 timer;
    s8 fade;
};

struct func_802500A4_S2;
/* unbake published declaration: published_72fae18c5096a2e7e2028755 */
typedef struct func_802500A4_S2 func_802500A4_S2;

struct func_8024F848_S1;
/* unbake published declaration: published_78bcac453c168ceb6ecde530 */
struct func_8024F848_S1 {
    char pad0[0x4];
    u16 unk4;
    char pad4[0x18 - 0x4 - sizeof(u16)];
    void * unk18;
};

struct func_8024E914_S1;
/* unbake published declaration: published_7b12664556394f9907b3209a */
struct func_8024E914_S1 {
    char pad0[0x4];
    u16 unk4;
    char pad4[0xE4 - 0x4 - sizeof(u16)];
    u16 unkE4;
};

/* unbake published declaration: published_7df1eb40b1f87f523f981802 */
extern float D_800C3D98_de;

struct func_8024F608_S1;
/* unbake published declaration: published_815169ed02562e506a0009f8 */
typedef struct func_8024F608_S1 func_8024F608_S1;

struct func_802500A4_S1;
/* unbake published declaration: published_905533f25d3bcf44615bafb3 */
typedef struct func_802500A4_S1 func_802500A4_S1;

struct GlobalState_func_8024F4A0_de;
/* unbake published declaration: published_973b742a593e5ac1fd336900 */
typedef struct GlobalState_func_8024F4A0_de GlobalState_func_8024F4A0_de;

struct GlobalState_func_8024F4A0_de;
/* unbake published declaration: published_9881ed9c74f403606632083c */
struct GlobalState_func_8024F4A0_de {
    s32 field0;
    u8 pad4[0x18];
    s32 field1C;
};

struct func_8024F590_S1;
/* unbake published declaration: published_9960b9899a67dc7e112386fd */
struct func_8024F590_S1 {
    char pad0[0x194];
    f32 unk194;
    char pad194[0x19C - 0x194 - sizeof(f32)];
    u16 unk19C;
    char pad19C[0x1A0 - 0x19C - sizeof(u16)];
    f32 unk1A0;
};

struct func_8024F624_S1;
/* unbake published declaration: published_aa241ea2d14ec8dd60d50b0e */
typedef struct func_8024F624_S1 func_8024F624_S1;

struct Object_func_8024EB90_de;
/* unbake published declaration: published_acde94bf8d79cdd2f6e2b0a9 */
struct Object_func_8024EB90_de {
    char pad0;
    s8 model;
    char pad2;
    s8 material;
    char pad4[4];
    Vec3 position;
    char pad14[4];
    s32 *type;
    char pad1C[0x68 - 0x1C];
    char matrices[4][0x40];
    char pad168[0x174 - 0x168];
    s32 angle;
    char pad178[0x194 - 0x178];
    f32 scale;
    f32 height;
    char pad19C[0x1A8 - 0x19C];
    char lights[0x1C];
    Gfx *cached;
};

struct Descriptor_func_802504B0_de;
struct Descriptor_func_802504B0_de {
    char pad0[0xE];
    s8 key;
    char padF[3];
    s8 argument;
};
struct Descriptor_func_802504B0_de;
struct Owner_func_802504B0_de;
/* unbake published declaration: published_b783bd94cd28ec7690c6afae */
struct Owner_func_802504B0_de {
    char pad0[0x18];
    struct Descriptor_func_802504B0_de *descriptor;
    char pad1C[4];
    s32 field20;
    char pad24[4];
    char transform[0xA8];
    s32 flagsD0;
    char padD4[4];
    u16 flagsD8;
    u8 colorFrame;
};

struct func_8024F590_S1;
/* unbake published declaration: published_bcc5684bc7d9a6ddd1ac1391 */
typedef struct func_8024F590_S1 func_8024F590_S1;

struct Object_func_8024EB90_de;
/* unbake published declaration: published_bec2bcfdb49229dd6eb71c04 */
typedef struct Object_func_8024EB90_de Object_func_8024EB90_de;

/* unbake published declaration: published_bf4e4ae864cc3955fc2dee74 */
extern int D_8013B190;

struct Actor_func_8024ED90_de;
/* unbake published declaration: published_c24a53b99f47bfcd8eab2be1 */
struct Actor_func_8024ED90_de {
    u32 pad0[2];
    Vec3 position0;
    u32 pad14[2];
    Vec3 position1;
};

struct PlacedPropRecord;
/* unbake published declaration: published_c5acf4158c8383daa6199c34 */
typedef struct PlacedPropRecord PlacedPropRecord;

/* unbake published declaration: published_cc068291fe7890f736f5fd89 */
extern float D_800C3E08_de;

struct func_8024F460_S1;
/* unbake published declaration: published_cddc262d94229621c0ba98c4 */
struct func_8024F460_S1 {
    char pad0[0x1C4];
    int unk1C4;
};

struct func_8024F848_S1;
/* unbake published declaration: published_d04a4ff49c4d6bae916bb1f0 */
typedef struct func_8024F848_S1 func_8024F848_S1;

struct func_8024F608_S1;
/* unbake published declaration: published_e0dda1d87a36dfd3973640aa */
struct func_8024F608_S1 {
    char pad0[0x18];
    void * unk18;
    char pad18[0x1A4 - 0x18 - sizeof(void*)];
    float unk1A4;
};

struct Record_func_8024F960_eu;
/* unbake published declaration: published_e80ed24ab542c2021221d26e */
typedef struct Record_func_8024F960_eu Record_func_8024F960_eu;

/* unbake published declaration: published_ef2491d38f4c54850d282feb */
extern float D_800C3E00_de;

struct func_8024F8CC_S1;
/* unbake published declaration: published_f010084d0a67405196f6deea */
typedef struct func_8024F8CC_S1 func_8024F8CC_S1;

struct Owner_func_80250274_de;
/* unbake published declaration: published_f10bdf529c7858782f53f33e */
typedef struct Owner_func_80250274_de Owner_func_80250274_de;

struct func_8024EF18_S1;
/* unbake published declaration: published_f237a1d33fffda30aaee53c4 */
struct func_8024EF18_S1 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x40 - 0x10 - sizeof(f32)];
    f32 unk40;
};

struct func_8024F490_S1;
/* unbake published declaration: published_f9133870b9fca5f73aa33c80 */
struct func_8024F490_S1 {
    char pad0[0x1];
    u8 unk1;
    char pad1[0x3 - 0x1 - sizeof(u8)];
    u8 unk3;
    char pad3[0x14 - 0x3 - sizeof(u8)];
    void * unk14;
    char pad14[0x18 - 0x14 - sizeof(void*)];
    char * unk18;
    char pad18[0x194 - 0x18 - sizeof(char*)];
    f32 unk194;
    char pad194[0x19C - 0x194 - sizeof(f32)];
    u16 unk19C;
    char pad19C[0x1A0 - 0x19C - sizeof(u16)];
    f32 unk1A0;
    char pad1A0[0x1A4 - 0x1A0 - sizeof(f32)];
    f32 unk1A4;
    char pad1A4[0x1C0 - 0x1A4 - sizeof(f32)];
    s32 unk1C0;
};

struct func_8024F8CC_S1;
/* unbake published declaration: published_fced6c2994eebc2de5cbecba */
struct func_8024F8CC_S1 {
    char pad0[0x60];
    s32 * unk60;
    char pad60[0x17C - 0x60 - sizeof(s32*)];
    char unk17C;
};

struct func_8024EF18_S1;
/* unbake published declaration: published_ff9f91b47a0303c8b6df357b */
typedef struct func_8024EF18_S1 func_8024EF18_S1;

#endif
