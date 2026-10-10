#ifndef UNBAKE_SPAN_16E000_CODE_8042BD40_H
#define UNBAKE_SPAN_16E000_CODE_8042BD40_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct Settings_func_8042D060_de;
/* unbake published declaration: published_3594388dc02ba545d62828cf */
struct Settings_func_8042D060_de {
    char pad0[0x24];
    s8 timeSetting;
};

struct Settings_func_8042D060_de;
/* unbake published declaration: published_5f10b9763a00ac40a8103b24 */
typedef struct Settings_func_8042D060_de Settings_func_8042D060_de;

struct Rules_func_8042D060_de;
/* unbake published declaration: published_6b718963e6cc3ebb41a55ca6 */
typedef struct Rules_func_8042D060_de Rules_func_8042D060_de;

struct Rules_func_8042D060_de;
/* unbake published declaration: published_cff28aeb9c0fa5279822cb64 */
struct Rules_func_8042D060_de {
    char pad0[0x14];
    f32 timeLeft;
    char pad18[0x98 - 0x18];
    s32 lastStanding;
};

struct Game_func_8042D060_de;
/* unbake published declaration: published_00c6cbb4bb6861f3cbb01717 */
struct Game_func_8042D060_de {
    char pad0[0xCAC];
    Settings_func_8042D060_de settings;
    char padCD1[0x1284 - 0xCD1];
    Rules_func_8042D060_de rules;
};

/* unbake published declaration: published_00f85ceac038d3e820c5dcf7 */
extern s32 func_8042D958_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* unbake published declaration: published_06df313b85cbb439aa028090 */
extern void func_8042CC74_de();

struct Shared_BigObj;
/* unbake published declaration: published_0ca2894c37922383a60bb33e */
typedef struct Shared_BigObj Shared_BigObj;

/* unbake published declaration: published_1228312e078ac884b63530f1 */
extern void func_8042D1C8_de();

struct Shared_Rec3;
/* unbake published declaration: published_1508e1630ac0c78ce7c4d9a6 */
struct Shared_Rec3 {
    char pad0[0x91];
    u8 flag;
    char pad92[0x4];
};

struct Frame_func_804217D4_de;
struct Menu_func_804241BC_de;
struct State_func_8042DAF8_de;
/* unbake published declaration: published_172c44c2d4430329552598bd */
struct State_func_8042DAF8_de {
    struct Menu_func_804241BC_de *menu;
    char pad4[0x8 - 0x4];
    struct Frame_func_804217D4_de *list;
    s32 delay;
    s32 target;
};

struct Shape_func_802764D4_de_2;
struct Shared_BigObj;
/* unbake published declaration: published_1d2c7e8b135fd0f0905309ea */
struct Shared_BigObj {
    char pad0[0xF0];
    s32 slot[8];
    struct Shape_func_802764D4_de_2 arr2[8];
};

struct Slot_func_8042DC04_de;
/* unbake published declaration: published_1d42f3be6dbd97516828c401 */
typedef struct Slot_func_8042DC04_de Slot_func_8042DC04_de;

/* unbake published declaration: published_1f9a72501d2aa09838a98988 */
extern void func_8042CFDC_de(void);

struct func_8042CE54_S1;
/* unbake published declaration: published_218cf966ebc8640537badcb7 */
typedef struct func_8042CE54_S1 func_8042CE54_S1;

struct IntegerStateF4;
/* unbake published declaration: published_21adbaf98146695ecef85131 */
typedef struct IntegerStateF4 IntegerStateF4;

struct ResourceBank;
/* unbake published declaration: published_98d3111e977dc2639291daaf */
typedef struct ResourceBank ResourceBank;

struct ResourceBank;
/* unbake published declaration: published_b83cb5ac30a1228352d7647b */
struct ResourceBank {
    u16 ids[20];
};

struct Screen_func_8042DC04_de;
/* unbake published declaration: published_30d533969b211e5e8c9a83d5 */
typedef struct Screen_func_8042DC04_de Screen_func_8042DC04_de;

struct func_8042CE54_S1;
/* unbake published declaration: published_329fb87cf87e44cb62976cf9 */
struct func_8042CE54_S1 {
    char pad0[0xE0];
    void * unkE0;
};

struct State_func_8042D908_de;
/* unbake published declaration: published_40ee494564c37fa9016c19cc */
struct State_func_8042D908_de {
    char pad[0xE8];
    s32 position;
    s32 limit;
};

struct IntegerState330;
/* unbake published declaration: published_46ce6ca126aec5f2e0b58431 */
typedef struct IntegerState330 IntegerState330;

struct Item_func_8042D304_de;
/* unbake published declaration: published_5f15dd11c73314705f58590b */
struct Item_func_8042D304_de {
    char pad[0x10];
    u8 alpha;
    char pad11[0x2C - 0x11];
    s32 frame;
};

struct Shared_Rec3;
/* unbake published declaration: published_65204b43f586af8e8aa4d340 */
typedef struct Shared_Rec3 Shared_Rec3;

/* unbake published declaration: published_7b2f4dfd46e252e819e1727b */
extern void func_8042D118_de();

struct Object_func_8042DD00_de;
/* unbake published declaration: published_8048fbb61482e227fc50f151 */
struct Object_func_8042DD00_de {
    char pad[0x14];
    char text[0xC];
    s32 value;
};

struct Screen_func_8042DC04_de;
/* unbake published declaration: published_89943ad5de61d9b17c8bb027 */
struct Screen_func_8042DC04_de {
    int window;
    char pad4[12];
    int state;
    char pad14[12];
    int count;
};

/* unbake published declaration: published_8fb73bc95170d5cb29b40f1e */
extern void func_8042D034_de(void);

struct Screen_func_8042D690_de;
/* unbake published declaration: published_96f1bc5d66cc973b35904beb */
struct Screen_func_8042D690_de {
    char pad0[0xE4];
    void *object;
    char padE8[0x320 - 0xE8];
    s32 open;
    char pad324[0x328 - 0x324];
    s32 choice;
};

struct Game_func_8042D060_de;
/* unbake published declaration: published_98db93c3a9137425d5493ab3 */
typedef struct Game_func_8042D060_de Game_func_8042D060_de;

struct IntegerState330;
/* unbake published declaration: published_99e51e0f963d0b9d6edd1d9f */
struct IntegerState330 {
    char pad0[0x32C];
    s32 unk_32C;
};

/* unbake published declaration: published_b9c50941753f96d7dda5d794 */
extern s32 func_8042DE10_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* unbake published declaration: published_bc23b3c9a4bf598fa700aec6 */
extern void func_8042D418_de(s32 arg0);

struct State_func_8042CFDC_de;
/* unbake published declaration: published_c4caa12f8857169248bae066 */
struct State_func_8042CFDC_de {
    char pad0[0x54];
    s32 first;
    char pad58[0x78 - 0x58];
    s32 second;
};

/* unbake published declaration: published_d0c32e7acbb30464662da5bf */
extern s32 func_8042D060_de();

struct Slot_func_8042DC04_de;
/* unbake published declaration: published_d46a081a32793e979d0afc9a */
struct Slot_func_8042DC04_de {
    char pad0[0x78];
    u8 active;
    char pad79[6];
    u8 index;
    char pad80[0x16];
};

struct IntegerStateF4;
/* unbake published declaration: published_ebed4439639ab4640390fa54 */
struct IntegerStateF4 {
    unsigned char padding_0[240];
    s32 unk_F0;
};

/* unbake published declaration: published_f28294851d68dd6429d140d7 */
extern void func_8042CFB0_de(void);

#endif
