#ifndef UNBAKE_SPAN_16E000_CODE_8042E080_H
#define UNBAKE_SPAN_16E000_CODE_8042E080_H
#include "../types.h"
struct Active;
/* unbake published declaration: published_10409a5c52d4f5dc063b9cc7 */
typedef struct Active Active;

struct Settings_func_8042EB10_de;
/* unbake published declaration: published_166d0aa5b1aed53f53be16c1 */
struct Settings_func_8042EB10_de {
    char pad0[0xD];
    u8 trialKind;
    char padE[0x16];
    s8 time;
    s8 limit;
    s8 other;
    s8 score;
};

struct Match_func_8042DEA0_de;
/* unbake published declaration: published_1f5015bd7d287ad107f04fd3 */
struct Match_func_8042DEA0_de {
    char pad0[0x90];
    s32 kills;
    char pad94[4];
    s32 deaths;
};

struct Record_func_8042DEA0_de;
/* unbake published declaration: published_522a4bf11648b0a3e5992950 */
struct Record_func_8042DEA0_de {
    char name[0x189];
    u8 profile[5];
    char pad18E[2];
};

/* unbake published declaration: published_98a5d296569b554477d7421b */
extern void func_8042EBA4_de();

/* unbake published declaration: published_a07fa99a16b6d67b5210e317 */
extern void func_8042E5EC_de();

/* unbake published declaration: published_adc7d0828b38e3a4bdb4a333 */
extern void func_8042EC38_de();

struct Settings_func_8042EB10_de;
/* unbake published declaration: published_c2c6cb5a15b7546af4e958bc */
typedef struct Settings_func_8042EB10_de Settings_func_8042EB10_de;

struct Active;
/* unbake published declaration: published_c8823a0c4abe4a7ee8224153 */
struct Active {
    char pad0[0x21];
    u8 score;
    u8 limit;
    u8 other;
    u8 time;
};

/* unbake published declaration: published_cbc850ba11f40322c5b71a6a */
extern void func_8042EB10_de();

/* unbake published declaration: published_d6e04a01e2547fcd3805d681 */
extern void func_8042ECD8_de();

/* unbake published declaration: published_db3aca8a2e83ae995ec8c3ce */
extern void func_8042E1F0_de();

/* unbake published declaration: published_ea1258d34cb50700092993e1 */
extern s32 func_8042EE94_de();

struct Status_func_8042DEA0_de;
/* unbake published declaration: published_eacc525b1383dd7424edb4b2 */
struct Status_func_8042DEA0_de {
    char pad0[0x78];
    u8 joined;
    u8 unk79;
    u8 unk7A;
    u8 unk7B;
    char pad7C;
    u8 unk7D;
    char pad7E[2];
    s8 kind;
    char pad81;
    u8 unk82;
    char pad83;
    char name[0x91 - 0x84];
    u8 computer;
    u8 team;
    char pad93;
    u8 lives;
    u8 score;
};

#endif
