#ifndef UNBAKE_SPAN_16E000_CODE_80400000_H
#define UNBAKE_SPAN_16E000_CODE_80400000_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
struct Item_func_80403458_de;
/* unbake published declaration: published_05bb5eaae53a8423a02eb7ee */
struct Item_func_80403458_de {
    char pad0[0xE];
    u8 flags;
    char padF[2];
    u8 kind;
    u8 subkind;
    char pad13[1];
};

/* unbake published declaration: published_0ca6f45a4a7e2e51338a3974 */
extern Vec3 func_8040385C_de(void);

/* unbake published declaration: published_0f153b7c3bcdf5e02586e186 */
extern void func_80403458_de();

/* unbake published declaration: published_180f566f619aa726acc58ee0 */
extern Vec3 func_80401564_de(f32 t);

struct Entry_func_80403458_de;
/* unbake published declaration: published_19ddb806a0d0a15ba8f6afca */
struct Entry_func_80403458_de {
    f32 time;
    s32 side;
    s32 index;
};

struct Record_func_80403458_de;
/* unbake published declaration: published_1da6f21703c8de011e39e5b1 */
typedef struct Record_func_80403458_de Record_func_80403458_de;

struct Key_func_80401214_de;
/* unbake published declaration: published_2328bb29474bd73cdd200173 */
struct Key_func_80401214_de {
    char pad0[0x1C];
    f32 time;
    char pad20[4];
};

struct Entry_func_80402FB4_de;
/* unbake published declaration: published_2626effbeb57eba5657e8bd2 */
typedef struct Entry_func_80402FB4_de Entry_func_80402FB4_de;

struct State_func_8040385C_de;
/* unbake published declaration: published_2c11d2e472deb41e3c7d85d8 */
typedef struct State_func_8040385C_de State_func_8040385C_de;

/* unbake published declaration: published_359886d4f6c3b2ac3d895bcd */
extern void func_80402BA0_de();

struct Item_func_8040332C_de;
/* unbake published declaration: published_6d9408f10f73b18f6d29f8d3 */
typedef struct Item_func_8040332C_de Item_func_8040332C_de;

struct Item_func_8040332C_de;
/* unbake published declaration: published_aff01f5342891c41c44be8cf */
struct Item_func_8040332C_de {
    char pad0[0x11];
    u8 kind;
    u8 subkind;
    char pad13[1];
};

struct Tables;
/* unbake published declaration: published_371eef5b9215c86c29af54a6 */
struct Tables {
    char pad0[0x11D0];
    Item_func_8040332C_de *items[2];
};

struct Item_func_80403458_de;
/* unbake published declaration: published_381e99bc30e55692db6612c5 */
typedef struct Item_func_80403458_de Item_func_80403458_de;

struct State_func_8040385C_de;
/* unbake published declaration: published_43a74c837b46fec193d2e581 */
struct State_func_8040385C_de {
    char a[4];
    void *unk4;
    char b[0x30];
    s32 unk38;
};

struct Tables_func_80403458_de;
/* unbake published declaration: published_486b7253bf25320b230160a0 */
struct Tables_func_80403458_de {
    char pad0[0x11D0];
    Item_func_80403458_de *items[2];
};

struct Key_func_80401564_de;
/* unbake published declaration: published_4917df5dfc7d739b326234e2 */
typedef struct Key_func_80401564_de Key_func_80401564_de;

struct Entry_func_80403200_de;
/* unbake published declaration: published_4de850c2a9d08142c187da33 */
struct Entry_func_80403200_de {
    s32 id0;
    s32 id4;
    s32 id8;
    s32 flags;
    char pad10[8];
    char name[0x34];
};

/* unbake published declaration: published_4e0ebf4c4c0c882b353f059f */
extern void func_80403B2C_de(u8 *bits, s32 n, s32 set);

/* unbake published declaration: published_4f7979e98a3900af7f8e83fe */
extern float D_800DCC7C_de;

struct Tables;
/* unbake published declaration: published_5457d04c8adcb5ad114d98be */
typedef struct Tables Tables;

/* unbake published declaration: published_5560336d0382347911987d3b */
extern u32 func_80403B0C_de(u8 *bits, s32 index);

struct Record_func_80402FB4_de;
/* unbake published declaration: published_56e954a8f0dd8a24c7e89c50 */
struct Record_func_80402FB4_de {
    char pad0[0x18];
    s32 owner;
    char pad1C[0x58 - 0x1C];
    s32 pending;
    char pad5C[0xD8 - 0x5C];
    s32 id;
    s32 index;
};

struct Spline;
/* unbake published declaration: published_607f0282da107278868d18b5 */
typedef struct Spline Spline;

struct Entry_func_80403200_de;
/* unbake published declaration: published_686290573cec4b1ab1ed67bd */
typedef struct Entry_func_80403200_de Entry_func_80403200_de;

/* unbake published declaration: published_70512f8c0de35230f8e0f393 */
extern Vec3 func_8040390C_de(void);

struct SplineNode;
/* unbake published declaration: published_806bfef09edcba0f7103ea83 */
struct SplineNode {
    Vec3 p;
    Vec3 d2p;
    f32 s;
    f32 w;
    f32 d2s;
};

struct SplineNode;
/* unbake published declaration: published_c16b6625e4325412e6954127 */
typedef struct SplineNode SplineNode;

struct Spline;
/* unbake published declaration: published_734e51eda5c2dd49290f8eee */
struct Spline {
    s32 nodeSize;
    s32 count;
    SplineNode nodes[1];
};

/* unbake published declaration: published_7490616b96743b204c52e1eb */
extern f32 func_804039C4_de(void);

struct Entry_func_80403458_de;
/* unbake published declaration: published_7e3a77ffc15fe53353103966 */
typedef struct Entry_func_80403458_de Entry_func_80403458_de;

struct Entry_func_80402FB4_de;
/* unbake published declaration: published_80a98bbc7dccf5de936b334d */
struct Entry_func_80402FB4_de {
    s32 id0;
    s32 id4;
    char pad8[0x44];
};

struct Key_func_80401214_de;
/* unbake published declaration: published_96cee384cd7efa66139cedd0 */
typedef struct Key_func_80401214_de Key_func_80401214_de;

struct Key_func_80401564_de;
/* unbake published declaration: published_9f09061c19b0bca99a2be8ec */
struct Key_func_80401564_de {
    f32 x;
    f32 y;
    f32 z;
    f32 pad;
    f32 time;
};

/* unbake published declaration: published_a5e3e437fdc42bf32ad4b819 */
extern void *func_80403B04_de(void *value);

/* unbake published declaration: published_a70aa306b6ae67ca1d99ad17 */
extern void func_80401980_de();

struct State_func_804039C4_de;
/* unbake published declaration: published_b1f446e7b5b278c72ded2e68 */
typedef struct State_func_804039C4_de State_func_804039C4_de;

struct Entry_func_804030E0_de;
/* unbake published declaration: published_b20f0b3a80d77614d6cfe392 */
typedef struct Entry_func_804030E0_de Entry_func_804030E0_de;

/* unbake published declaration: published_b266832af6e3add593c892bf */
extern void func_804009F4_de(int resource);

struct Record_func_804030E0_de;
/* unbake published declaration: published_b43769e2f59bec282d08fcd0 */
typedef struct Record_func_804030E0_de Record_func_804030E0_de;

struct Entry_func_804030E0_de;
/* unbake published declaration: published_ba4cf85a963272b3877b7157 */
struct Entry_func_804030E0_de {
    s32 id0;
    s32 id4;
    s32 id8;
    s32 flags;
    char pad10[0x3C];
};

/* unbake published declaration: published_baa76d8aabe56fbb6c5da009 */
extern void func_80403ADC_de();

struct Record_func_80403458_de;
/* unbake published declaration: published_bf495ec84ca3b6b7c61574ee */
struct Record_func_80403458_de {
    char pad0[4];
    s32 resource;
    char pad8[0x14];
    f32 time;
    char pad20[0x14];
    f32 endTime;
    char pad38[0x18];
    s32 active;
    char pad54[4];
    s32 pending;
};

/* unbake published declaration: published_c5461fca20a63c81a9063801 */
extern s32 func_80403A64_de();

struct Record_func_804030E0_de;
/* unbake published declaration: published_d45bbae20ac7f43d0b9dab31 */
struct Record_func_804030E0_de {
    char pad0[0x18];
    s32 owner;
    char pad1C[0x58 - 0x1C];
    s32 pending;
    char pad5C[0xD8 - 0x5C];
    s32 id;
    s32 index;
    s32 key;
};

struct Tables_func_80403458_de;
/* unbake published declaration: published_d538b79d8b4f87c05990c89f */
typedef struct Tables_func_80403458_de Tables_func_80403458_de;

struct State_func_804039C4_de;
/* unbake published declaration: published_d7a93cedce99d88ca3bc0dec */
struct State_func_804039C4_de {
    s32 a;
    s32 *unk4;
};

/* unbake published declaration: published_dc5c82153b2a70f58d98ad3c */
extern f32 D_800E0B60[];

struct Record_func_80402FB4_de;
/* unbake published declaration: published_fb09ffa8961d4097a8da2716 */
typedef struct Record_func_80402FB4_de Record_func_80402FB4_de;

#endif
