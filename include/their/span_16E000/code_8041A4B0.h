#ifndef UNBAKE_SPAN_16E000_CODE_8041A4B0_H
#define UNBAKE_SPAN_16E000_CODE_8041A4B0_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct func_8041AA30_S1;
/* unbake published declaration: published_0cadf267a46757814d80c32b */
struct func_8041AA30_S1 {
    char pad0[0x8];
    void * unk8;
    char pad8[0x54 - 0x8 - sizeof(void*)];
    s32 unk54;
};

/* unbake published declaration: published_1c7c00c1bc3dc5c235997cf9 */
extern void func_8041A520_de(void *target, const char *format, ...);

struct Key;
struct Menu_func_8041AD10_de;
struct Owner_func_8041AD10_de;
/* unbake published declaration: published_1d65ca388169b544fbaf2798 */
struct Menu_func_8041AD10_de {
    char pad0[0x44];
    struct Owner_func_8041AD10_de *owner;
    struct Key entries[(0x110 - 0x48) / 20];
    s32 index;
};

/* unbake published declaration: published_2030796def4cc2503e12d561 */
extern s32 func_8041A724_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct func_8041AA30_S1;
/* unbake published declaration: published_54f67a269fe45055356bdccb */
typedef struct func_8041AA30_S1 func_8041AA30_S1;

struct Key;
struct Menu_func_8041AD34_de;
/* unbake published declaration: published_577f7334044d2fb165ca0c94 */
struct Menu_func_8041AD34_de {
    char pad0[0x48];
    struct Key entries[(0x110 - 0x48) / 20];
    s32 index;
    s32 count;
};

struct Record_func_8041ABC0_de;
/* unbake published declaration: published_5f7cb29b890c47dbec218b20 */
struct Record_func_8041ABC0_de {
    s32 words_00[3];
    s16 field_0C;
    s16 field_0E;
    s32 words_10[2];
    s16 field_18;
    s16 field_1A;
    s32 words_1C[4];
    s32 fields_2C[5];
    s32 field_40;
    struct Record_func_8041ABC0_de *field_44;
    s32 words_48[(0x110 - 0x48) / 4];
    s32 field_110;
    s32 field_114;
};

/* unbake published declaration: published_6090a2949cc2883b69e80071 */
extern void func_8041AB90_de();

/* unbake published declaration: published_717148457e1c6a1c7cd1055b */
extern s32 func_8041AD7C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct Obj_func_802B20D4_de;
struct Scroll;
/* unbake published declaration: published_957889d3395d2f0bd41e73ed */
struct Scroll {
    char pad[0x44];
    struct Obj_func_802B20D4_de *bar;
    s32 length;
    s32 count;
    s32 item;
};

struct Record_func_8041A580_de;
/* unbake published declaration: published_9c65f6ce29e0e1680876a13f */
struct Record_func_8041A580_de {
    s32 words_00[3];
    s16 field_0C;
    s16 field_0E;
    s32 words_10[2];
    s16 field_18;
    s16 field_1A;
    s32 words_1C[4];
    s32 fields_2C[5];
    s32 field_40;
    struct Record_func_8041A580_de *field_44;
    s32 field_48;
    s32 field_4C;
    s32 field_50;
    s32 field_54;
};

struct Record_func_8041ABC0_de;
/* unbake published declaration: published_a5972a620f7bf029a23a5def */
typedef struct Record_func_8041ABC0_de Record_func_8041ABC0_de;

/* unbake published declaration: published_c27548190d8f85d9102a281a */
extern void func_8041A550_de();

struct Scroll_func_8041A8E8_de;
/* unbake published declaration: published_f8d9c57a0bc19ec6c35bc1bf */
struct Scroll_func_8041A8E8_de {
    char pad[0x48];
    s32 length;
    s32 count;
    s32 item;
};

struct Record_func_8041A580_de;
/* unbake published declaration: published_fc181e36b165338619ecd112 */
typedef struct Record_func_8041A580_de Record_func_8041A580_de;

/* unbake published declaration: published_fe200c52d36bbf1718fe7a44 */
extern s32 func_8041A490_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

#endif
