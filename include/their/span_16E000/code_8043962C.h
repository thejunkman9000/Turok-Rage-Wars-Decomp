#ifndef UNBAKE_SPAN_16E000_CODE_8043962C_H
#define UNBAKE_SPAN_16E000_CODE_8043962C_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "gfx.h"
/* unbake published declaration: published_0f7ca3fdb2581e88e019f299 */
extern s32 func_80439E34_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct State_func_80439B5C_de;
/* unbake published declaration: published_13a8a3db303d1b1d10ea1357 */
typedef struct State_func_80439B5C_de State_func_80439B5C_de;

struct Object_func_80439C30_de;
struct Triple;
/* unbake published declaration: published_4996ade56730adb1a6a1786c */
struct Object_func_80439C30_de {
    char pad[0x28];
    struct Triple vector;
};

struct Object_func_80439CDC_de;
struct Triple;
/* unbake published declaration: published_6c99b800d7550aa36d9fc9e1 */
struct Object_func_80439CDC_de {
    char pad[0x10];
    struct Triple vector;
};

struct Object_func_80439CDC_de;
struct Triple;
/* unbake published declaration: published_4e8f038b909795444855e6f8 */
extern void func_80439D00_de(struct Object_func_80439CDC_de *object, struct Triple vector);

struct Shape_func_80299E74_de_2;
struct Shape_func_80299E74_de_2 {
    unsigned char padding_0[16];
    unsigned char field_10;
};
struct Pulse;
struct Shape_func_80299E74_de_2;
/* unbake published declaration: published_617de3b77bc2879f33b6777a */
struct Pulse {
    struct Shape_func_80299E74_de_2 *light;
    s32 phase;
};

struct MenuModelItem;
/* unbake published declaration: published_7337a6537436fd25380d7fb0 */
struct MenuModelItem {
    s32 unused;
    Vec3 scale;
    Vec3 position;
    Vec3 rotation;
    Vec3 speed;
    s32 model;
    char matrices[128];
    s32 flags;
};

struct State_func_80439B5C_de;
/* unbake published declaration: published_7f315f46d6a5836af564438e */
struct State_func_80439B5C_de {
    s32 unk0;
    Triple first;
    Triple second;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
};

struct MenuModelScreen;
/* unbake published declaration: published_8cb532994a7de42e7865bc22 */
struct MenuModelScreen {
    char p0[0x160];
    Matrix camera;
    char p1[0x29C-0x1A0];
    f32 width;
    f32 height;
    char p2[0x380-0x2A4];
    Matrix matrices[2];
};

/* unbake published declaration: published_959958d987d99f4bc64fcbd8 */
extern s32 func_8043944C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct ObjectB8;
/* unbake published declaration: published_b9a738bfde1d7428c6c44ab4 */
struct ObjectB8 {
    char pad[0xB8];
    s32 value;
};

struct Pulse;
/* unbake published declaration: published_cb09c23cf5d1735880662be5 */
typedef struct Pulse Pulse;

struct MenuModelItem;
/* unbake published declaration: published_ce0ce29ff0e9ec04175f88c8 */
typedef struct MenuModelItem MenuModelItem;

struct Shared_Body;
/* unbake published declaration: published_d1650e26e71247717c001d88 */
typedef struct Shared_Body Shared_Body;

struct MenuModelScreen;
/* unbake published declaration: published_dcd57f35854c5a090b248b8b */
typedef struct MenuModelScreen MenuModelScreen;

/* unbake published declaration: published_ea30534b164852ed307703db */
extern s32 func_80439758_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

typedef s32 (*MenuEventHandler)(void *, s32, s32, s32, s32);
extern MenuEventHandler D_800E595C;

#endif
