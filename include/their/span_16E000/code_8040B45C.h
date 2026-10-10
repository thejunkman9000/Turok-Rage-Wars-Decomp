#ifndef UNBAKE_SPAN_16E000_CODE_8040B45C_H
#define UNBAKE_SPAN_16E000_CODE_8040B45C_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
/* unbake published declaration: published_0fd6c13740119d2f331992f8 */
extern void func_8040B7E0_de(void);

/* unbake published declaration: published_36b2602f052521f6a900f8aa */
extern int D_800CC37C;

/* unbake published declaration: published_417b0347bd629d38221a578b */
extern int D_800DE898;

struct Record_func_8040B58C_de;
/* unbake published declaration: published_484eec677197f48e78a2306d */
typedef struct Record_func_8040B58C_de Record_func_8040B58C_de;

/* unbake published declaration: published_4efdc635807d7ade832bbd9b */
extern void func_8040C09C_de();

struct Action_func_8040B4E0_de;
/* unbake published declaration: published_56a0647ac8eac4f9c4ff70a4 */
struct Action_func_8040B4E0_de {
    char pad0[0x1C];
    void *unk1C;
    func_80242278_S1 *unk20;
    void *unk24;
};

/* unbake published declaration: published_5d8faeab57ef644fd8ec3c40 */
extern void func_8040B830_de(void);

struct Node_func_8040C484_de;
/* unbake published declaration: published_672532a2127822782f4bd37b */
typedef struct Node_func_8040C484_de Node_func_8040C484_de;

struct Action_func_8040B648_de;
/* unbake published declaration: published_6c5671d0119add7a691670e3 */
typedef struct Action_func_8040B648_de Action_func_8040B648_de;

struct Shape_func_8024A5A8_de_2;
/* unbake published declaration: published_6e22507428ee6c1f70af332c */
struct Shape_func_8024A5A8_de_2 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
};

/* unbake published declaration: published_8a1eed7c2111c34ccf585db4 */
extern int D_800DE8A0[];

/* unbake published declaration: published_97cea080e6f4f1b20afbd17f */
extern void func_8040B814_de(void);

struct Mode_func_8040C09C_de;
/* unbake published declaration: published_97d67fb47e68e767e08e680c */
struct Mode_func_8040C09C_de {
    int width;
    int height;
    int rest[5];
};

/* unbake published declaration: published_993a567c362c7f18c8130005 */
extern int D_800CC378;

struct Record_func_8040B58C_de;
/* unbake published declaration: published_9bbeaefc707ad0212cc3fee5 */
struct Record_func_8040B58C_de {
    char pad0[0x1C];
    func_8024795C_S2 *player;
    func_80242278_S1 *inner;
    void *unk24;
};

struct Node_func_8040C484_de;
/* unbake published declaration: published_a358d219d76e4a78fd61d73b */
struct Node_func_8040C484_de {
    int unused;
    struct Node_func_8040C484_de *next;
    char pad[0x294];
    float width;
    float height;
    int x;
    int y;
};

struct Action_func_8040B648_de;
/* unbake published declaration: published_bb1ea53b76c65661ed1e332a */
struct Action_func_8040B648_de {
    char a[0x1C];
    func_8024795C_S2 *unk1C;
    s32 unk20;
    s32 unk24;
};

/* unbake published declaration: published_ab64f2ab4497c864ba495199 */
extern s32 func_8040B648_de(s32 arg0, Action_func_8040B648_de *arg1);

/* unbake published declaration: published_adfddc2ee934d5a1214ca5a7 */
extern int D_80141000;

struct Action_func_8040B4E0_de;
/* unbake published declaration: published_b45c3010f11aa6ba99b13a99 */
typedef struct Action_func_8040B4E0_de Action_func_8040B4E0_de;

/* unbake published declaration: published_b6b5b540cfb166224f246e47 */
extern void func_8040C2F8_de();

struct Mode_func_8040C09C_de;
/* unbake published declaration: published_c7a4e4b8ed8d3d4d03efc295 */
typedef struct Mode_func_8040C09C_de Mode_func_8040C09C_de;

/* unbake published declaration: published_c9b5ee039e127e490b5b0c84 */
extern void func_8040C318_de();

/* unbake published declaration: published_df7f86cf180558c034c8d9be */
extern void func_8040B7F8_de(void);

/* unbake published declaration: published_f28cab0cb2695e2fb41fdf5c */
extern void func_8040BBB0_de();

/* unbake published declaration: published_fb2e4f255263da1164b8dacf */
extern void func_8040B84C_de(void);

struct Item_func_80441FE8_de;
struct Record_func_80409BDC_de;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_8040B444_de(struct Item_func_80441FE8_de *field, struct Record_func_80409BDC_de *holder);
#endif

#endif
