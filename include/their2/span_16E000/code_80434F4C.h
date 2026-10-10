#ifndef UNBAKE_SPAN_16E000_CODE_80434F4C_H
#define UNBAKE_SPAN_16E000_CODE_80434F4C_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
/* unbake published declaration: published_0592af802b89df46dc1828fb */
extern void func_8043577C_de(int arg0);

/* unbake published declaration: published_0616cc2d700edaf4167e107c */
extern s32 func_8043590C_de(s32 arg0);

/* unbake published declaration: published_0b239bb3b6924e306aee6634 */
extern int func_80435184_de(int player);

/* unbake published declaration: published_10ae44068c6f4834efc12130 */
extern void func_80435844_de(s32 index);

struct Entry_func_804350CC_de;
/* unbake published declaration: published_10ea222a1720792aff48506c */
struct Entry_func_804350CC_de {
    char pad0[0x58];
    s32 first;
    char pad5C[0x6C - 0x5C];
    s32 second;
    char pad70[2920 - 0x70];
};

struct Player_func_8043590C_de;
/* unbake published declaration: published_1660029350fa1c9589c65fbd */
struct Player_func_8043590C_de {
    char a[0xB64];
    s32 value;
};

struct ObjectState71;
/* unbake published declaration: published_178f82c92cbc91174ef43d4f */
struct ObjectState71 {
    char pad0[0x70];
    char unk_70;
};

struct Entry_func_80434EF4_de;
/* unbake published declaration: published_1c5144f92586b42d5f2519e5 */
typedef struct Entry_func_80434EF4_de Entry_func_80434EF4_de;

/* unbake published declaration: published_2255f739f41a9b682afe749d */
extern void func_80434FB4_de(s32 value);

struct Block_func_804356BC_de;
struct Player_func_804356BC_de;
struct Triple;
/* unbake published declaration: published_2501e4d5283e71eb57f18f64 */
struct Block_func_804356BC_de {
    char pad0[0x58];
    struct Player_func_804356BC_de players[4];
    struct Triple places[4];
};

struct Player_func_8043590C_de;
/* unbake published declaration: published_9e389906f50c5ffb24db6b2d */
typedef struct Player_func_8043590C_de Player_func_8043590C_de;

struct State_func_8043590C_de;
/* unbake published declaration: published_292b75fab53363d6053faadf */
struct State_func_8043590C_de {
    char a[0x58];
    Player_func_8043590C_de players[1];
};

struct IntegerState346C;
/* unbake published declaration: published_2d2c4a5e7e0f0919a9415c1b */
typedef struct IntegerState346C IntegerState346C;

/* unbake published declaration: published_2e390f7e5c09d301a6456267 */
extern int func_80435270_de(int id, int value);

/* unbake published declaration: published_37beb841539f7b720b6af850 */
extern s32 func_80435A78_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct Record_func_804358C0_de;
/* unbake published declaration: published_3e6868b9b8c8e6327f6dbfba */
struct Record_func_804358C0_de {
    s32 id;
    signed char kind;
    char pad[400 - 5];
};

/* unbake published declaration: published_47c055d1efdfa0253a926300 */
extern int func_80435424_de();

/* unbake published declaration: published_4a04f3a8d415f3f88581df26 */
extern int func_80435224_de(int id, int value);

struct Entry_func_80434FC4_de;
/* unbake published declaration: published_4c93dd04fe947cf36412853e */
struct Entry_func_80434FC4_de {
    char pad0[0x2C];
    s32 phases[1];
    char pad30[0x68 - 0x30];
    void *window;
    char pad6C[2920 - 0x6C];
};

struct Player_func_80435A10_de;
/* unbake published declaration: published_4d3941be502103f7330558c3 */
struct Player_func_80435A10_de {
    char pad[0x58];
    int state;
    char pad5C[0xBA0 - 0x5C];
    int phase;
    int timer;
};

struct Table_func_804352C8_de;
struct Triple;
/* unbake published declaration: published_4f51518cd9af14d57d3140b0 */
struct Table_func_804352C8_de {
    char pad[0x2DF8];
    struct Triple slots[1];
};

struct Game_func_80435128_de;
/* unbake published declaration: published_568f2ffed0a5040c142cb096 */
typedef struct Game_func_80435128_de Game_func_80435128_de;

struct IntegerStateBC0;
/* unbake published declaration: published_5768830b2c88f9e966a223b5 */
typedef struct IntegerStateBC0 IntegerStateBC0;

struct Base;
/* unbake published declaration: published_59fb3e289dddf7e1fbe9eb3b */
typedef struct Base Base;

/* unbake published declaration: published_68aed7aa97ce230176ce7a20 */
extern int func_804351E4_de();

/* unbake published declaration: published_6a53fb60544193764e6487d5 */
extern s32 func_80435574_de(void);

struct Base;
/* unbake published declaration: published_6cd4bd23b0e529d5834dea47 */
struct Base {
    char pad[0x2DF0];
    Triple slots[4];
};

/* unbake published declaration: published_77ee4adf3b5cb8d14905dd9e */
extern void func_80434FC4_de(s32 index);

struct func_80435898_S1;
/* unbake published declaration: published_7935cc78efc670b3ea2f07e6 */
struct func_80435898_S1 {
    char pad0[0xC];
    s8 unkC;
    char padC[0xD - 0xC - sizeof(s8)];
    s8 unkD;
};

/* unbake published declaration: published_7a842c8351efc7762360e956 */
extern int D_800E54A0;

struct Entry_func_80435128_de;
/* unbake published declaration: published_7b556071b5a3a5ac656c4d1a */
typedef struct Entry_func_80435128_de Entry_func_80435128_de;

/* unbake published declaration: published_83d4858534bc1a354cc698cb */
extern void func_8043542C_de(s32 index);

struct Entry_func_80434EF4_de;
/* unbake published declaration: published_83f6866bd6cf41c8027227df */
struct Entry_func_80434EF4_de {
    u8 pad0[0xB4C];
    InventorySlot name[8];
    s32 cursor;
    u8 padB60[0x8];
};

/* unbake published declaration: published_8686d79955683ec7315fe366 */
extern s32 func_804352C8_de(s32 first, s32 second);

/* unbake published declaration: published_893c2fed2d2a0d338dabc824 */
extern int func_80435340_de(void);

struct Player_func_80435128_de;
/* unbake published declaration: published_8af263649ae8ac589dc1f97c */
typedef struct Player_func_80435128_de Player_func_80435128_de;

struct Entry_func_80435128_de;
/* unbake published declaration: published_f7c4b928d5df9e9fb6d4ed47 */
struct Entry_func_80435128_de {
    char pad[0x7D];
    signed char state;
    char pad7E[0x190 - 0x7E];
};

struct Player_func_80435128_de;
/* unbake published declaration: published_f6e795f80028fcad860e6d1d */
struct Player_func_80435128_de {
    Entry_func_80435128_de entries[4];
    char pad[0xB68 - 0x640];
};

struct Game_func_80435128_de;
/* unbake published declaration: published_993806fb8af5ca0d51af797a */
struct Game_func_80435128_de {
    Player_func_80435128_de players[4];
};

/* unbake published declaration: published_9bdd2b869004c516aa9b2273 */
extern void func_804354C0_de(s32 index);

struct IntegerState346C;
/* unbake published declaration: published_9cd48c1b3e8c08cbc74160af */
struct IntegerState346C {
    char pad0[0x3468];
    s32 unk_3468;
};

struct State_func_8043590C_de;
/* unbake published declaration: published_9fc4168ace0baed64ea55dd6 */
typedef struct State_func_8043590C_de State_func_8043590C_de;

/* unbake published declaration: published_a0eea1a666561d3eaf5f091d */
extern void func_804356BC_de(s32 arg0);

struct IntegerStateBC0;
/* unbake published declaration: published_aa62f72e723b83e6ac06c2f9 */
struct IntegerStateBC0 {
    unsigned char padding_0[3004];
    s32 unk_BBC;
};

/* unbake published declaration: published_b659f51bcfade9cb5c321dd4 */
extern float D_800DDED0;

struct Table_func_804351E4_de;
struct Triple;
/* unbake published declaration: published_b798e0d097174509bf803e00 */
struct Table_func_804351E4_de {
    char pad[0x2DF8];
    struct Triple slots[4];
};

/* unbake published declaration: published_b8bd514819b062305af18cc7 */
extern void func_8043599C_de(s32 first, s32 second, s32 index);

/* unbake published declaration: published_c1ecad02408c3c39623f2a28 */
extern int func_804355B4_de();

struct State_func_80434D70_de;
/* unbake published declaration: published_c6312206c2d5d671d1ee81e9 */
struct State_func_80434D70_de {
    char pad0[4];
    s32 window;
    char pad8[0x50];
    s32 state;
    s32 step;
    s32 next;
    char pad64[8];
    s32 display;
    char pad70[0xB18];
    s32 reset;
    char padb8c[0x226C];
    s32 selected;
};

struct IntegerState3470;
/* unbake published declaration: published_da3edef88408ade6d3d8fb37 */
struct IntegerState3470 {
    char pad0[0x3468];
    s32 unk_3468;
    char pad3468[0x346C - 0x3468 - sizeof(s32)];
    s32 unk_346C;
};

struct func_80435898_S1;
/* unbake published declaration: published_df3d52b4921c5001f1798e92 */
typedef struct func_80435898_S1 func_80435898_S1;

/* unbake published declaration: published_e04c760d8757021e8e609310 */
extern float D_800E1EF8;

struct Player_func_80435A10_de;
/* unbake published declaration: published_ea41211f0cba38f9c2589052 */
typedef struct Player_func_80435A10_de Player_func_80435A10_de;

struct State_func_80434D70_de;
/* unbake published declaration: published_ead390c1a864b6cb3430c40e */
typedef struct State_func_80434D70_de State_func_80434D70_de;

/* unbake published declaration: published_f0950651d8331147324005f9 */
extern int func_80435128_de(int player);

/* unbake published declaration: published_f389090bbe0a070efae4e76e */
extern void func_8043583C_de(void);

struct Menu_func_80434EF4_de;
/* unbake published declaration: published_f699118f7851af613c95338f */
struct Menu_func_80434EF4_de {
    s32 unk0;
    s32 unk4;
    u8 pad8[0x24];
    s32 flags[5];
    Entry_func_80434EF4_de entries[1];
};

struct ObjectState71;
/* unbake published declaration: published_f7617f9e3fe364b20b0f6189 */
typedef struct ObjectState71 ObjectState71;

struct Menu_func_80434EF4_de;
/* unbake published declaration: published_f7c0203b80d3519904224d3d */
typedef struct Menu_func_80434EF4_de Menu_func_80434EF4_de;

/* unbake published declaration: published_fb15522e4dcd95c55dda779a */
extern s32 func_80435528_de(void);

/* unbake published declaration: published_fb2e3792eb859af2db4ceaf7 */
extern void func_804350CC_de(s32 index);

struct IntegerState3470;
/* unbake published declaration: published_fcc1c72f3765286bde4cefcf */
typedef struct IntegerState3470 IntegerState3470;

/* unbake published declaration: published_fe1e6acc1e7ba13bfb6e6557 */
extern void func_80434D70_de(s32 player);

extern int func_804355E8_de(void);
#endif
