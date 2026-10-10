#ifndef UNBAKE_SPAN_16E000_CODE_8043E9A8_H
#define UNBAKE_SPAN_16E000_CODE_8043E9A8_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
/* unbake published declaration: published_0f77a8bdcf23f065bd015732 */
extern s32 func_8043EA4C_de(void *arg0, Outer8043E56C *arg1);

/* unbake published declaration: published_102dcef60e8226c4bd7759a4 */
extern signed char D_801422C1;

struct Player_func_8043F048_de;
/* unbake published declaration: published_2447bc2edfaaf6e428d8cda8 */
struct Player_func_8043F048_de {
    char pad[0x644];
    u8 flags[9];
    u8 count64D;
    u8 count64E;
};

struct Holder_func_8043F048_de;
struct Player_func_8043F048_de;
/* unbake published declaration: published_1046fa18b08cf6f0f59046a4 */
struct Holder_func_8043F048_de {
    char pad[0x1C];
    struct Player_func_8043F048_de *player;
};

struct Flagged;
struct Flagged {
    u8 pad0[0x58];
    u32 unk58;
};
struct Flagged;
struct Obj8043ECE8;
/* unbake published declaration: published_1e7b37ec2e0dcba71a84d49b */
struct Obj8043ECE8 {
    s16 unk0;
    u8 pad2[10];
    struct Flagged *unkC;
};

/* unbake published declaration: published_1ee829bfdcc1afadd97499bc */
extern s32 func_8043ED48_de(void);

struct ItemDef;
/* unbake published declaration: published_fe768b0fe06c12d49f6cfc2d */
struct ItemDef {
    char pad[0x20];
    s16 type;
    s16 index;
};

struct ItemDef;
struct Item_func_8043F048_de;
/* unbake published declaration: published_2cc1add42aadc0df688d8a6f */
struct Item_func_8043F048_de {
    char pad[0x18];
    struct ItemDef *def;
};

/* unbake published declaration: published_2e3dd0990f78bda081471af6 */
extern s32 func_8043EA00_de(void *arg0, Arg1Struct *arg1);

struct Obj8043EB20;
/* unbake published declaration: published_45c5fd2426df4266bc9b8dce */
typedef struct Obj8043EB20 Obj8043EB20;

struct func_802285C4_S1;
/* unbake published declaration: published_6756adee7a7b2544bcb9e0a6 */
extern void func_8043EA98_de(void *arg0, struct func_802285C4_S1 *menu);

struct Globals_func_8043EA98_de;
struct Player_func_8041EAC4_de;
/* unbake published declaration: published_798ce30f91ac5fd452a972f5 */
struct Globals_func_8043EA98_de {
    char pad0[0x1D];
    u8 flag1D;
    u8 flag1E;
    char pad1F[0xD0 - 0x1F];
    struct Player_func_8041EAC4_de status[8];
};

struct Inner8043E56C;
/* unbake published declaration: published_d5445d7b998f84f28e27c037 */
typedef struct Inner8043E56C Inner8043E56C;

struct Obj8043EB20;
/* unbake published declaration: published_7e3993f033d70b7242b3070b */
struct Obj8043EB20 {
    u8 pad0[0x1C];
    s32 unk1C;
    Inner8043E56C *unk20;
};

struct Obj8043ECE8;
/* unbake published declaration: published_7eaeca5f528f81e0afaf2b94 */
typedef struct Obj8043ECE8 Obj8043ECE8;

/* unbake published declaration: published_aeffd3f622e48de087f82d2a */
extern void func_8043F040_de(void);

struct Player_func_8043EBE4_de;
/* unbake published declaration: published_b81e44dd17d238d72f050b7f */
struct Player_func_8043EBE4_de {
    u8 flag;
    u8 data[149];
};

struct Options_func_8043EBE4_de;
struct Player_func_8043EBE4_de;
/* unbake published declaration: published_b0fa77a7c5668eed9ad81500 */
struct Options_func_8043EBE4_de {
    char pad0[0x1D];
    u8 first;
    u8 second;
    char pad1F[0x148 - 0x1F];
    struct Player_func_8043EBE4_de players[8];
};

struct Record_func_80409BDC_de;
/* unbake published declaration: published_ba77be7b4b1d25eac63299d1 */
extern void func_8043E948_de(struct Record_func_80409BDC_de *arg0);

/* unbake published declaration: published_c4e341e79b171acfe1b586b6 */
extern s32 func_8043E9A8_de(void *arg0, Obj8043EB20 *arg1);

/* unbake published declaration: published_e00e6bd38fcd6fb5270242f0 */
extern s32 func_8043EDDC_de(void);

/* unbake published declaration: published_f9752afaaea7942ced279af4 */
extern s32 func_8043ED50_de(void);

extern void func_8043E97C_de(void *arg0);
#endif
