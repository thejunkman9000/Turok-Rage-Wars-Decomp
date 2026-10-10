#ifndef UNBAKE_SPAN_1000_CODE_8024D018_H
#define UNBAKE_SPAN_1000_CODE_8024D018_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
struct func_8024DEF8_S1;
/* unbake published declaration: published_09be9b328381970f7dffdc1a */
struct func_8024DEF8_S1 {
    char pad0[0x18];
    void * unk18;
    char pad18[0x174 - 0x18 - sizeof(void*)];
    s32 unk174;
};

struct func_8024D860_S1;
/* unbake published declaration: published_38346eb6664dd3e679dda576 */
struct func_8024D860_S1 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    f32 unk10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    s32 unk14;
    char pad14[0x38 - 0x14 - sizeof(s32)];
    s32 unk38;
    char pad38[0x100 - 0x38 - sizeof(s32)];
    s32 unk100;
};

struct func_8024DD48_S1;
/* unbake published declaration: published_429f2858f3a366284375672a */
struct func_8024DD48_S1 {
    s32 unk0;
    char pad0[0x14 - 0x0 - sizeof(s32)];
    char unk14;
};

/* unbake published declaration: published_4325933db3f2662678f885df */
extern float D_800C3C98_de;

/* unbake published declaration: published_49c7838ab884262dd1f98d36 */
extern float D_800C3CA0_de;

struct func_8024D0F8_S1;
/* unbake published declaration: published_541b0faea088c8e994360c59 */
typedef struct func_8024D0F8_S1 func_8024D0F8_S1;

struct func_8024E090_S2;
/* unbake published declaration: published_5822dfceb87c77ec5df9ec60 */
typedef struct func_8024E090_S2 func_8024E090_S2;

struct func_8024D860_S2;
/* unbake published declaration: published_5c3c6c1f8cacfd1b3c0546a6 */
typedef struct func_8024D860_S2 func_8024D860_S2;

struct func_8024DD48_S1;
/* unbake published declaration: published_6b26e3738ae239fa359716c5 */
typedef struct func_8024DD48_S1 func_8024DD48_S1;

/* unbake published declaration: published_825516c39e2d609ef8336e49 */
extern float D_800C8CA0;

struct func_8024DEF8_S1;
/* unbake published declaration: published_8f04c81cb273b94b6e9ad999 */
typedef struct func_8024DEF8_S1 func_8024DEF8_S1;

struct Probe;
/* unbake published declaration: published_a4579d2827eff21380cc4dde */
typedef struct Probe Probe;

struct SoundRequest;
/* unbake published declaration: published_aff44145335a5c1ef0f9fc65 */
struct SoundRequest {
    s32 kind;
    Triple position;
    char pad[0x148];
    s32 owner;
    s32 flags;
};

/* unbake published declaration: published_b80ca5add27dc2415c0b761d */
extern float D_800C3C9C_de;

struct func_8024D860_S1;
/* unbake published declaration: published_c3a197c9e187ed5a47b4a6b8 */
typedef struct func_8024D860_S1 func_8024D860_S1;

struct func_8024D49C_S1;
/* unbake published declaration: published_c6ae1177f903b04a743a4b90 */
typedef struct func_8024D49C_S1 func_8024D49C_S1;

struct func_8024E090_S2;
/* unbake published declaration: published_d3ceb06530263df04b7cb3c8 */
struct func_8024E090_S2 {
    s32 unk0;
    char pad0[0x4C - 0x0 - sizeof(s32)];
    s32 unk4C;
};

/* unbake published declaration: published_d8ef4769d10d9ef4d0e64ffb */
extern void func_8024D028_de(f32 *m, f32 *q, f32 *t);

struct func_8024D49C_S1;
/* unbake published declaration: published_e8d03ac60272bd03644e88d2 */
struct func_8024D49C_S1 {
    char pad0[0x1F0];
    char * unk1F0;
};

struct func_8024D0F8_S1;
/* unbake published declaration: published_ec985e2e0a1da41a8f44b8ff */
struct func_8024D0F8_S1 {
    char pad0[0xB4];
    int unkB4;
    char padB4[0xE8 - 0xB4 - sizeof(int)];
    char unkE8;
};

struct Input_func_8024D728_de;
/* unbake published declaration: published_edb9b159c2ad648f106569e7 */
typedef struct Input_func_8024D728_de Input_func_8024D728_de;

struct Input_func_8024D728_de;
/* unbake published declaration: published_f7c65a991fffd76acb61e859 */
struct Input_func_8024D728_de {
    u8 state;
    u8 pad[0x43];
    Vec3 direction;
};

struct func_8024D860_S2;
/* unbake published declaration: published_f7f9559a9888823e6a89f6ab */
struct func_8024D860_S2 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    f32 unk10;
    char pad10[0x40 - 0x10 - sizeof(f32)];
    f32 unk40;
    char pad40[0x44 - 0x40 - sizeof(f32)];
    Vec3 unk44;
    char pad44[0x6C - 0x44 - sizeof(Vec3)];
    f32 unk6C;
};

struct Probe;
/* unbake published declaration: published_fe3304afdfae11a9ae8eb616 */
struct Probe {
    char pad0[0x18];
    Vec3 start;
    char pad24[0x24];
    Vec3 dir;
    char pad54[0x8C];
};

struct SoundRequest;
/* unbake published declaration: published_ffca7d8196fbea3125ec83a2 */
typedef struct SoundRequest SoundRequest;

extern int func_8024D264_de(void * arg0);
#endif
