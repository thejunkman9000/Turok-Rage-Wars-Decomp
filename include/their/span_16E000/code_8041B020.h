#ifndef UNBAKE_SPAN_16E000_CODE_8041B020_H
#define UNBAKE_SPAN_16E000_CODE_8041B020_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
struct Owner_func_8041B6E8_de;
/* unbake published declaration: published_0714bacac8db82f4a213255e */
typedef struct Owner_func_8041B6E8_de Owner_func_8041B6E8_de;

struct Node_func_8041B610_de;
/* unbake published declaration: published_07d83ae67b94ac7e1ee7c52f */
typedef struct Node_func_8041B610_de Node_func_8041B610_de;

/* unbake published declaration: published_09216d2f6f1b8fd2e5a9cac2 */
extern s32 func_8041B970_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct Record_func_8041B22C_de;
/* unbake published declaration: published_0e7e9b1a22e98e1133859c3f */
struct Record_func_8041B22C_de {
    s32 words_00[3];
    s16 field_0C;
    u16 field_0E;
    s32 words_10[2];
    s16 field_18;
    s16 field_1A;
    s32 words_1C[4];
    s32 fields_2C[5];
    s32 field_40;
};

struct Mixer;
/* unbake published declaration: published_126843282e809404d4682828 */
typedef struct Mixer Mixer;

struct Context_func_8041B6E8_de;
/* unbake published declaration: published_201e3036ad0389c77d432267 */
typedef struct Context_func_8041B6E8_de Context_func_8041B6E8_de;

struct Node_func_8041B610_de;
struct Owner_func_8041B610_de;
/* unbake published declaration: published_2c50c48196f00abd786120b1 */
struct Node_func_8041B610_de {
    s32 words_00[3];
    s16 tag;
    s16 kind;
    s16 pad10;
    s16 flags;
    s32 words_14[12];
    struct Owner_func_8041B610_de *owner;
    s32 value;
    s32 words_4C[8];
    s32 field_6C;
};

/* unbake published declaration: published_d79241d7d0a4495e8f49855f */
struct Owner_func_8041B610_de {
    s32 words_00[2];
    struct Node_func_8041B610_de *root;
    s32 words_0C[14];
    struct Node_func_8041B610_de *overlay;
};

struct Slots_func_8041B7C4_de;
/* unbake published declaration: published_312605475efc89a83426a12d */
struct Slots_func_8041B7C4_de {
    char pad0[0x48];
    s32 count;
    char pad4C[0x5C - 0x4C];
    s32 values[1];
};

struct Child_func_8041BC64_de;
/* unbake published declaration: published_74a6d6fcf38814f1b90cb4a9 */
struct Child_func_8041BC64_de {
    char pad[0x12];
    u16 flags;
    char pad14[0x38 - 0x14];
    void *target;
};

struct Child_func_8041BC64_de;
struct Owner_func_8041BC64_de;
/* unbake published declaration: published_3b4a56ce838a1f93c21e1244 */
struct Owner_func_8041BC64_de {
    char pad[0x4C];
    struct Child_func_8041BC64_de *children[4];
    s32 busy[4];
};

/* unbake published declaration: published_4276be9a5f2eedb798a48a55 */
extern void func_8041B110_de(s32 arg0);

struct Slots_func_8041B7B4_de;
/* unbake published declaration: published_436a563ca9548ad2d52ff566 */
struct Slots_func_8041B7B4_de {
    char pad[0x5C];
    s32 values[1];
};

/* unbake published declaration: published_5b59177f20021f05eeae1e87 */
extern void func_8041B0E0_de();

struct Node_func_8041B6E8_de;
/* unbake published declaration: published_5cb03cf93ae37a80eda391b8 */
typedef struct Node_func_8041B6E8_de Node_func_8041B6E8_de;

struct Child;
/* unbake published declaration: published_5fd86df342b7f4c8f96f283f */
struct Child {
    char pad[0x12];
    u16 flags;
    char pad14[0x34 - 0x14];
    void *target;
};

struct Slots_func_8041B7C4_de;
/* unbake published declaration: published_6186d0056db649c692d02fd1 */
extern s32 func_8041B7C4_de(struct Slots_func_8041B7C4_de *object);

struct Owner_func_8041B610_de;
/* unbake published declaration: published_6886aa4bccc269feab8deaa9 */
typedef struct Owner_func_8041B610_de Owner_func_8041B610_de;

struct Slots_func_8041B810_de;
struct func_8021C9B4_S3;
/* unbake published declaration: published_6a07a9f023031b8fea545416 */
struct Slots_func_8041B810_de {
    char pad[0x4C];
    struct func_8021C9B4_S3 *entries[1];
};

struct Child_func_8041BBD0_de;
/* unbake published declaration: published_6b475c076d870847f57dd334 */
struct Child_func_8041BBD0_de {
    char pad[0x12];
    u16 flags;
    char pad14[0x2C - 0x14];
    void *target;
};

struct Node_func_8041B6E8_de;
/* unbake published declaration: published_c21c4d5090d76b04e0259f1c */
struct Node_func_8041B6E8_de {
    s32 words_00[3];
    s16 id;
};

struct Context_func_8041B6E8_de;
/* unbake published declaration: published_dffcea01a15bdf640cafdf89 */
struct Context_func_8041B6E8_de {
    s32 words_00[17];
    void *root;
    s32 words_48;
    Node_func_8041B6E8_de *shown[4];
    s32 locked[4];
    s32 shared;
};

struct Context_func_8041B6E8_de;
struct Owner_func_8041B6E8_de;
/* unbake published declaration: published_6fd6e1cf1b72b98d06675a13 */
struct Owner_func_8041B6E8_de {
    s32 words_00[2];
    struct Context_func_8041B6E8_de *context;
};

struct Record_func_8041B110_de;
/* unbake published declaration: published_823082453215d853594305f0 */
struct Record_func_8041B110_de {
    s32 words_00[3];
    s16 field_0C;
    s16 field_0E;
    s32 words_10[2];
    s16 field_18;
    s16 field_1A;
    s32 words_1C[4];
    s32 fields_2C[5];
    s32 field_40;
};

/* unbake published declaration: published_8ec6e299ef372440efd340bf */
extern s32 func_8041B340_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct Child_func_8041BBD0_de;
struct Owner_func_8041BBD0_de;
/* unbake published declaration: published_9c31d932cad743356a9a7dad */
struct Owner_func_8041BBD0_de {
    char pad[0x4C];
    struct Child_func_8041BBD0_de *children[4];
    s32 busy[4];
};

struct Record_func_8041B110_de;
/* unbake published declaration: published_9cc895f7a90a7e25ce2ff960 */
typedef struct Record_func_8041B110_de Record_func_8041B110_de;

/* unbake published declaration: published_a21b02f7546dbb6780917164 */
extern void func_8041B5E0_de();

struct Mixer;
/* unbake published declaration: published_a6f60188f99251145c84f8e6 */
struct Mixer {
    char pad[0x4C];
    func_8021C9B4_S3 *handlers[4];
    int muted[4];
};

/* unbake published declaration: published_a98bac6c2965f533f293f1aa */
extern void func_8041B828_de(Context_func_8041B6E8_de *context, s32 index, s32 id);

struct Record_func_8041B22C_de;
/* unbake published declaration: published_ae0000ab21457d0dbcea6677 */
typedef struct Record_func_8041B22C_de Record_func_8041B22C_de;

struct Key;
struct Menu_func_8041AFF8_de;
struct Owner_func_8041AD10_de;
/* unbake published declaration: published_bb1ec0968853c9b7a657f68b */
struct Menu_func_8041AFF8_de {
    char pad0[0x44];
    struct Owner_func_8041AD10_de *owner;
    struct Key entries[(0x110 - 0x48) / 20];
    s32 index;
    s32 count;
};

struct Child_func_8041BCF8_de;
/* unbake published declaration: published_bf31e7413e6659ab24ef7b44 */
struct Child_func_8041BCF8_de {
    char pad[0x12];
    u16 flags;
    char pad14[0x30 - 0x14];
    void *target;
};

struct Child_func_8041BCF8_de;
struct Owner_func_8041BCF8_de;
/* unbake published declaration: published_d7152d5d3a6854e59e7d51cc */
struct Owner_func_8041BCF8_de {
    char pad[0x4C];
    struct Child_func_8041BCF8_de *children[4];
    s32 busy[4];
};

struct Child;
struct Owner_func_8041BB3C_de;
/* unbake published declaration: published_f7b1950242631ed79751b1e5 */
struct Owner_func_8041BB3C_de {
    char pad[0x4C];
    struct Child *children[4];
    s32 busy[4];
};

#endif
