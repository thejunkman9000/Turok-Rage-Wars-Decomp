#ifndef UNBAKE_SPAN_16E000_CODE_80412270_H
#define UNBAKE_SPAN_16E000_CODE_80412270_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct Record_func_80412710_de;
/* unbake published declaration: published_025ad358ecf5dd267927bed0 */
typedef struct Record_func_80412710_de Record_func_80412710_de;

/* unbake published declaration: published_0deec24fd83c5f00b7e2f38d */
extern s32 func_804125A4_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* unbake published declaration: published_14a987e525efe0f6be248372 */
extern void func_804129F0_de(s32 identifier, s32 first, s32 second, s32 third);

/* unbake published declaration: published_14cba5b1af9b075c2951de68 */
extern s16 func_80413684_de(s16 *record);

/* unbake published declaration: published_1ad2f82c5caa3bbf6fd5f58d */
extern s16 func_8041366C_de(s16 *record);

struct Layout;
/* unbake published declaration: published_1e1a46bbcc687550b67d1e97 */
typedef struct Layout Layout;

/* unbake published declaration: published_1e8f4b3c893e699a466eff0b */
extern s32 func_80413634_de(u8 *record);

/* unbake published declaration: published_207c1dc5e181f5ed2a6af859 */
extern u8 func_804135FC_de(u8 *record);

struct List_func_80412634_de;
/* unbake published declaration: published_2c3f1610ac1b70cec3abd0a3 */
struct List_func_80412634_de {
    char pad0[0x48];
    u8 columns;
    u8 rows;
};

struct Entry_func_80412898_de;
struct Shape_func_802764D4_de_2;
/* unbake published declaration: published_2e090f098be452df96d87008 */
struct Entry_func_80412898_de {
    char pad_00[0x44];
    struct Shape_func_802764D4_de_2 *cells;
    u8 pad_48[3];
    u8 width;
};

struct Resource_func_80413404_de;
/* unbake published declaration: published_3b1e3372be47f1f9ee6ddc3b */
struct Resource_func_80413404_de {
    unsigned char unk0;
    unsigned char flags;
    char pad2[0xE];
    int size;
    void *data;
    void *handle;
};

/* unbake published declaration: published_407ee139231ec6b2da429b88 */
extern s16 func_80413678_de(s16 *record);

/* unbake published declaration: published_454447d0bacad4ec48c3e43f */
extern void func_80412B18_de(s32 identifier, s32 *first, s32 *second);

struct Object_func_80412CA0_de;
/* unbake published declaration: published_54f631a2e9c5294de10d35eb */
struct Object_func_80412CA0_de {
    char pad[0x44];
    void *child;
};

struct Layout;
/* unbake published declaration: published_54ffb724485b153a9ea4812d */
struct Layout {
    s32 pad0[5];
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    s32 pad1C[4];
};

/* unbake published declaration: published_60b3b5b067cbc06bb1fbf31c */
extern s16 func_80413690_de(s16 *record);

struct Record_func_80412710_de;
/* unbake published declaration: published_6af2dbcf2eb378daf6f2a6eb */
struct Record_func_80412710_de {
    s32 words_00[3];
    s16 field_0C;
    s16 field_0E;
    s32 words_10[13];
    void *field_44;
    u8 field_48;
    u8 field_49;
    u8 field_4A;
    u8 field_4B;
    u8 field_4C;
    u8 field_4D;
    u8 field_4E;
    u8 field_4F;
    u8 field_50;
    u8 field_51;
    u8 pad_52[0xE];
};

struct Image_func_80413480_de;
/* unbake published declaration: published_861892ae604a35d475387dd0 */
struct Image_func_80413480_de {
    u8 unk0;
    u8 flags;
    char pad2[0xE];
    s32 paletteCount;
    void *palette;
    void *pixels;
    s32 unk1C;
};

struct Resource_func_80413404_de;
/* unbake published declaration: published_90e6eb54ba6e0aa6e5e9b80c */
typedef struct Resource_func_80413404_de Resource_func_80413404_de;

struct Cell_func_804122CC_de;
/* unbake published declaration: published_99845aaed7d25ff804476645 */
typedef struct Cell_func_804122CC_de Cell_func_804122CC_de;

struct Cell_func_804122CC_de;
/* unbake published declaration: published_af0b57d854ee10f1f66c1f91 */
struct Cell_func_804122CC_de {
    Layout layout;
    u8 fg;
    u8 bg;
    u8 selectedFg;
    u8 selectedBg;
    s32 pad30[2];
    s32 content;
};

/* unbake published declaration: published_b6285a54ad6c14c6183197bb */
extern u32 func_80412D94_de(u32 value, s32 from, s32 to);

struct List_func_80412634_de;
/* unbake published declaration: published_b9d20bde1da0d4f67d7e8b0a */
typedef struct List_func_80412634_de List_func_80412634_de;

struct Entry_func_80412AC0_de;
/* unbake published declaration: published_b9ebb009aa70f3ee5828c6e6 */
struct Entry_func_80412AC0_de {
    char pad[0x58];
    s32 first;
    s32 second;
};

/* unbake published declaration: published_bc7fe448883cff7c66d315e0 */
extern void func_80412A58_de(s32 identifier, s32 first, s32 second, s32 third);

struct Entry_func_80412898_de;
/* unbake published declaration: published_bce21e60ffe0122484ad7be6 */
typedef struct Entry_func_80412898_de Entry_func_80412898_de;

/* unbake published declaration: published_c24664665f74e1260b5830a7 */
extern void func_80412AC0_de(s32 identifier, s32 first, s32 second);

/* unbake published declaration: published_c4d40fec5ca7668ec9087a07 */
extern void func_80412940_de(s32 identifier, s32 row, s32 column, s32 *first, s32 *second);

struct Table_func_804122CC_de;
/* unbake published declaration: published_c9bf87e1f4707aed60374998 */
struct Table_func_804122CC_de {
    Layout layout;
    s32 pad2C[6];
    s32 *contents;
    char pad48[3];
    u8 columns;
    u8 selectedRow;
    u8 selectedCol;
    u8 rowScroll;
    u8 colScroll;
    u8 headerRows;
    u8 headerCols;
    u8 headerFg;
    u8 headerBg;
    u8 fg;
    u8 bg;
    u8 selectedFg;
    u8 selectedBg;
    s32 *widths;
    s32 *heights;
};

/* unbake published declaration: published_ce9ab10312fd186f1d4c5d28 */
extern s16 func_80413660_de(s16 *record);

struct Image_func_80413480_de;
/* unbake published declaration: published_d5fa8e21ad7ba610875d1381 */
typedef struct Image_func_80413480_de Image_func_80413480_de;

struct Entry_func_80412B18_de;
/* unbake published declaration: published_ecd4470f65c8f38260764b4e */
struct Entry_func_80412B18_de {
    char pad[0x4C];
    u8 first;
    u8 second;
};

/* unbake published declaration: published_f572bbaeed70070112262e2e */
extern void func_80412898_de(s32 identifier, s32 row, s32 column, s32 first, s32 second);

struct Table_func_804122CC_de;
/* unbake published declaration: published_f6818811194aa097f16bec90 */
typedef struct Table_func_804122CC_de Table_func_804122CC_de;

/* unbake published declaration: published_f7990f4385d30f2460f01e1a */
extern s32 func_80412710_de(s32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6);

#endif
