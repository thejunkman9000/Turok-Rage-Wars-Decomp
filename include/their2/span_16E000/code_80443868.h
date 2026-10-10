#ifndef UNBAKE_SPAN_16E000_CODE_80443868_H
#define UNBAKE_SPAN_16E000_CODE_80443868_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
/* unbake published declaration: published_0eb4b3a62e512f1baf785216 */
extern void func_80443BCC_de(void);

struct Actor_func_80443C14_de;
/* unbake published declaration: published_6269ab063686a952794b7d43 */
typedef struct Actor_func_80443C14_de Actor_func_80443C14_de;

struct Actor_func_80443C14_de;
/* unbake published declaration: published_cc0e06ba6b2e8f2c40e58124 */
struct Actor_func_80443C14_de {
    char pad[0x58];
    int flags58;
    char pad5c[0xC4];
    int flags120;
    char pad124[0x9C];
    int flags1c0;
    char pad1c4[0x4C];
    int flags210;
    char pad214[0x24];
    int flags238;
    char pad23c[0x24];
    int flags260;
};

struct Arg_func_80443CD4_de;
/* unbake published declaration: published_255139fc24583f68943c97c7 */
struct Arg_func_80443CD4_de {
    char pad[12];
    Actor_func_80443C14_de *unkC;
    char pad2[12];
    int unk1C;
};

struct Sync;
/* unbake published declaration: published_39cdb5eff742a0f4f7ec6c2d */
struct Sync {
    char pad[0x54];
    int sync;
    char pad58[0x1C];
    int team;
};

struct Arg_func_80443CD4_de;
/* unbake published declaration: published_bb2770348f407004ab27de77 */
typedef struct Arg_func_80443CD4_de Arg_func_80443CD4_de;

/* unbake published declaration: published_476f9a4be5f13c8672cb38c8 */
extern void func_80443CD4_de(Arg_func_80443CD4_de *arg0);

struct Actor_func_804438BC_de;
/* unbake published declaration: published_fb0049a6a9dd8ab1d8c6f4bb */
struct Actor_func_804438BC_de {
    char pad0[4928];
    s32 unk1340;
    char pad1344[268];
    s32 unk1450;
};

struct Actor_func_804438BC_de;
struct State_func_804438BC_de;
/* unbake published declaration: published_62ef5c02620e31847adf9660 */
struct State_func_804438BC_de {
    char pad0[28];
    struct Actor_func_804438BC_de * unk1C;
};

struct Entry_func_80443734_de;
/* unbake published declaration: published_6f5b7f2b005ca1674717b852 */
typedef struct Entry_func_80443734_de Entry_func_80443734_de;

/* unbake published declaration: published_6fd69d3bce88fe4baf13aa61 */
extern s32 func_80443710_de(void *arg0, MenuRules *arg1);

struct Object_func_80443C14_de;
/* unbake published declaration: published_8726fcf8436cee5692a974ae */
typedef struct Object_func_80443C14_de Object_func_80443C14_de;

struct Leaf;
struct Leaf {
    char pad[0x8E];
    u8 flag;
};
struct Leaf;
struct Middle;
struct Middle {
    char pad[0x5D8];
    struct Leaf *leaf;
};
struct Middle;
struct Root_func_804436F8_de;
/* unbake published declaration: published_90fcbd25cbbb9cba2a00423f */
struct Root_func_804436F8_de {
    char pad[0x1C];
    struct Middle *middle;
};

struct Owner_func_8043E1F8_de;
/* unbake published declaration: published_d6f6bd65e441c985e9c7df55 */
typedef struct Owner_func_8043E1F8_de Owner_func_8043E1F8_de;

struct Actor_func_80443C14_de;
struct Object_func_80443C14_de;
/* unbake published declaration: published_b07fce41a7cb82559049a290 */
struct Object_func_80443C14_de {
    char pad[0xC];
    struct Actor_func_80443C14_de *actor;
    char pad10[0xC];
    Owner_func_8043E1F8_de *parent;
};

/* unbake published declaration: published_a69ccbbd98e9c094b040ec3f */
extern void func_80443C14_de(Object_func_80443C14_de *object);

struct Actor_func_80443844_de;
struct Actor_func_80443844_de {
    char pad[0x5D0];
    int waiting;
    char pad5D4[4];
    func_8020EA10_S3 *info;
};
struct Actor_func_80443844_de;
struct Player_func_80443844_de;
/* unbake published declaration: published_b132cb4099181ba48085adea */
struct Player_func_80443844_de {
    char pad[0x1C];
    struct Actor_func_80443844_de *actor;
};

struct Player_func_80443844_de;
/* unbake published declaration: published_e05aaeb9c1c754946e0b3b53 */
typedef struct Player_func_80443844_de Player_func_80443844_de;

/* unbake published declaration: published_b69cb009339c3b4f2346f57f */
extern int func_80443844_de(int unused, Player_func_80443844_de *player);

struct Record_func_8040AB54_de;
/* unbake published declaration: published_bd6f729d157fb52d13971214 */
extern void func_80443BD4_de(struct Record_func_8040AB54_de *record);

struct Entry_func_80443734_de;
/* unbake published declaration: published_ecb3f1af540e7aa262054265 */
struct Entry_func_80443734_de {
    char pad0[4];
    s32 width;
    char pad8[4];
    f32 scaleX;
    f32 scaleY;
    char pad14[2];
    u16 x;
    char pad18[6];
    u16 y;
};

/* unbake published declaration: published_d12bf1c1e2891e6179f702d2 */
extern void func_80443734_de(func_80239CD0_S1 *arg0, Entry_func_80443734_de *arg1, s32 arg2, Style_func_8043C9AC_de *arg3);

struct Actor_func_804438BC_de;
/* unbake published declaration: published_d6952a069722ad4a8c6f7def */
typedef struct Actor_func_804438BC_de Actor_func_804438BC_de;

struct Root_func_804436F8_de;
/* unbake published declaration: published_d97122025c7e00ac7cccb5d1 */
extern s32 func_804436F8_de(void *unused, struct Root_func_804436F8_de *root);

/* unbake published declaration: published_de272d1171773019d5c0c698 */
extern void func_80443DD0_de(Arg_func_80443CD4_de *arg0);

struct State_func_804438BC_de;
/* unbake published declaration: published_ec110c2991ee533235946d93 */
typedef struct State_func_804438BC_de State_func_804438BC_de;

/* unbake published declaration: published_e374fd2bd3d1fac7729b9c4a */
extern s32 func_804438BC_de(State_func_804438BC_de *arg0);

struct Sync;
/* unbake published declaration: published_f968998661ee29752546c953 */
typedef struct Sync Sync;

struct Item_func_80441FE8_de;
struct MenuRules;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_80443998_de(struct Item_func_80441FE8_de *field, struct MenuRules *holder);
#endif

#endif
