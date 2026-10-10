#ifndef UNBAKE_SPAN_1000_CODE_8027451C_H
#define UNBAKE_SPAN_1000_CODE_8027451C_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct Packed;
/* unbake published declaration: published_170ed5beda84bda23e1c4f59 */
struct Packed {
    unsigned short unk0;
    unsigned short unk2;
    unsigned short first[3];
    unsigned short second[3];
    int unk10;
};

struct Packed;
/* unbake published declaration: published_3408642908f9d4afa24a3ee8 */
typedef struct Packed Packed;

struct Header_func_80275AA4_de;
/* unbake published declaration: published_62ff9755153962a7de2d6350 */
struct Header_func_80275AA4_de {
    short unk0;
    short unk2;
    void *first[3];
    void *second[3];
    int unk1C;
};

struct Header_func_80275AA4_de;
/* unbake published declaration: published_f285e8ff65fbb77c11bc8df4 */
typedef struct Header_func_80275AA4_de Header_func_80275AA4_de;

/* unbake published declaration: published_06f046713e1a4f588da4db0e */
extern void func_80275AA4_de(Header_func_80275AA4_de *dst, Packed *src, char *base, int unused, char *extra);

/* unbake published declaration: published_143c04181ac9212e32025998 */
extern float D_800C4980_de;

/* unbake published declaration: published_1d139982e0b557b187b961ad */
extern void func_802744B4_de(void);

/* unbake published declaration: published_249bccb79a3a422cc383e2e7 */
extern float D_800C9AD8;

/* unbake published declaration: published_2cf6f811fea43f10c90b3487 */
extern void func_802744AC_de(void);

struct func_80274BEC_S2;
/* unbake published declaration: published_31d73e83514f2f11087c61d2 */
typedef struct func_80274BEC_S2 func_80274BEC_S2;

struct func_80274DFC_S1;
/* unbake published declaration: published_3453f51fc6e1ffe9824a5480 */
struct func_80274DFC_S1 {
    f32 unk0;
    char pad0[0x8 - 0x0 - sizeof(f32)];
    f32 unk8;
    char pad8[0x30 - 0x8 - sizeof(f32)];
    Vec3 unk30;
};

struct func_80274BEC_S2;
/* unbake published declaration: published_4143efad78e474d51aa53341 */
struct func_80274BEC_S2 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    f32 unk18;
    char pad18[0x1C - 0x18 - sizeof(f32)];
    f32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(f32)];
    f32 unk20;
    char pad20[0x30 - 0x20 - sizeof(f32)];
    f32 unk30;
    char pad30[0x34 - 0x30 - sizeof(f32)];
    s32 unk34;
    char pad34[0x38 - 0x34 - sizeof(s32)];
    f32 unk38;
};

/* unbake published declaration: published_41f48f5db0c8bbe89e5dfaed */
extern void func_80275A58_de(void *arg0);

/* unbake published declaration: published_4d7f51bda2006f17e928483a */
extern float D_800C4978_de;

/* unbake published declaration: published_5489b7e258d46b2b02cca272 */
extern s32 func_8027451C_de();

/* unbake published declaration: published_559f2731ede558c57a591823 */
extern float D_800C49C0_de;

struct func_80274C64_S1;
/* unbake published declaration: published_5e1488f352ecce1cb617c441 */
struct func_80274C64_S1 {
    char pad0[0x18];
    f32 unk18;
    char pad18[0x1C - 0x18 - sizeof(f32)];
    f32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(f32)];
    f32 unk20;
    char pad20[0x24 - 0x20 - sizeof(f32)];
    f32 unk24;
    char pad24[0x28 - 0x24 - sizeof(f32)];
    f32 unk28;
    char pad28[0x2C - 0x28 - sizeof(f32)];
    f32 unk2C;
};

/* unbake published declaration: published_61ff408a5a3de71401d23a96 */
extern float D_800C9A38;

/* unbake published declaration: published_63bb2f9f9124a75080946f36 */
extern float D_800C49EC_de;

/* unbake published declaration: published_64c4ee46b53ab370c3f91a08 */
extern void func_80274DFC_de(float mf[4][4], float xEye, float yEye, float zEye, float xAt, float yAt, float zAt, float xUp, float yUp, float zUp);

/* unbake published declaration: published_65d7a956cc762391ce7c230b */
extern float D_800C49C4_de;

/* unbake published declaration: published_66945d2b229b9e1e3b9bdc2d */
extern f32 func_802749B4_de(f32 arg0, f32 arg1);

struct Polygon_func_80275410_de;
/* unbake published declaration: published_68de7c3a23e81fa54a5e65ae */
struct Polygon_func_80275410_de {
    char pad0[2];
    u16 flags;
    Vec3 *v0;
    Vec3 *v1;
    Vec3 *v2;
};

/* unbake published declaration: published_6f8be957e5ff1b046212257d */
extern s32 func_80274D8C_de(void *arg0, void *arg1);

struct func_80274DFC_S1;
/* unbake published declaration: published_74ca60431a3d7410403bc4b1 */
typedef struct func_80274DFC_S1 func_80274DFC_S1;

struct Polygon_func_80275410_de;
/* unbake published declaration: published_7551c5fd41dd82869ffab305 */
typedef struct Polygon_func_80275410_de Polygon_func_80275410_de;

/* unbake published declaration: published_7bce46add42cd5c36896659f */
extern void func_80274C7C_de(void *arg0);

struct func_80274BEC_S1;
/* unbake published declaration: published_81d583d6a215cf8f79ad8590 */
typedef struct func_80274BEC_S1 func_80274BEC_S1;

struct func_80274C64_S1;
/* unbake published declaration: published_8254e5999df61dd81d479954 */
typedef struct func_80274C64_S1 func_80274C64_S1;

/* unbake published declaration: published_84c496f7662dc9bf6ece64f1 */
extern void func_80274BF4_de(void *arg0);

/* unbake published declaration: published_9d88b58ce0aca947271dca44 */
extern float D_800C49C8_de;

/* unbake published declaration: published_ac01b765c2f99043f3a74a51 */
extern float D_800C4998_de;

struct func_80274BEC_S1;
/* unbake published declaration: published_aedce3f6bcc6d0675448db2c */
struct func_80274BEC_S1 {
    func_8022E280_S1_U744 unk0;
    char pad0[0x4 - 0x0 - sizeof(func_8022E280_S1_U744)];
    func_8022E280_S1_U744 unk4;
    char pad4[0x8 - 0x4 - sizeof(func_8022E280_S1_U744)];
    func_8022E280_S1_U744 unk8;
};

/* unbake published declaration: published_afc8e98aef644a3e92e02309 */
extern double D_800C4940_de;

/* unbake published declaration: published_b39016c881f36197d6492df9 */
extern void func_80274B7C_de(void *arg0, void *arg1, void *arg2);

/* unbake published declaration: published_b67b836de179dfc1e9272294 */
extern s32 func_802748F4_de(s32 arg0, s32 arg1, s32 arg2);

/* unbake published declaration: published_c3fa82bb79b926750d813438 */
extern float D_800C499C_de;

/* unbake published declaration: published_d4ec57bddc72ab76c9494d1c */
extern float D_800C4990_de;

/* unbake published declaration: published_d4fa9907d41af424032e5df5 */
extern float D_800C49E0_de;

/* unbake published declaration: published_f04a6300faca786abe9477cb */
extern f32 func_80274944_de(f32 arg0);

/* unbake published declaration: published_f85ecd30ea495c145fef2cf8 */
extern float D_800C4988_de;

extern s32 func_80274D10_de(f32 *arg0, f32 *arg1, f32 *arg2);

#endif
