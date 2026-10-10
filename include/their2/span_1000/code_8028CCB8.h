#ifndef UNBAKE_SPAN_1000_CODE_8028CCB8_H
#define UNBAKE_SPAN_1000_CODE_8028CCB8_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
/* unbake published declaration: published_0c18f9831939e1c1ce488a40 */
extern float D_800C52F8_de;

struct func_8028D35C_S1;
/* unbake published declaration: published_0c915cebbee10b7ff2ba76d4 */
struct func_8028D35C_S1 {
    char pad0[0x1C];
    s32 unk1C;
    char pad1C[0x4C - 0x1C - sizeof(s32)];
    s32 * unk4C;
    char pad4C[0x1B40C - 0x4C - sizeof(s32*)];
    s32 unk1B40C;
};

struct State_func_8028D67C_de;
/* unbake published declaration: published_605f6b41661c3b1eb54124d2 */
typedef struct State_func_8028D67C_de State_func_8028D67C_de;

struct State_func_8028D67C_de;
/* unbake published declaration: published_b8689530f8a6c1344b3dd4d2 */
struct State_func_8028D67C_de {
    char pad[0xB4C];
    s32 values[64];
    s32 unkC4C;
    char padc50[0x1A6CC];
    f32 unk1B31C;
};

struct func_8028D658_S1;
/* unbake published declaration: published_12ecc816c1ee1d7f39cc86fb */
struct func_8028D658_S1 {
    char pad0[0x4];
    State_func_8028D67C_de unk4;
};

struct func_8028D7A0_S1;
/* unbake published declaration: published_1588c9c0b2ba7028107a35a5 */
typedef struct func_8028D7A0_S1 func_8028D7A0_S1;

struct ColorEntry;
/* unbake published declaration: published_16add449c9110337b31e01cd */
struct ColorEntry {
    f32 value;
    u8 red;
    u8 green;
    u8 blue;
    u8 pad;
};

struct func_8028D628_S1;
/* unbake published declaration: published_1a98fab3a8a088b4a7950bd0 */
struct func_8028D628_S1 {
    char pad0[0x944];
    int unk944;
    char pad944[0xB48 - 0x944 - sizeof(int)];
    int unkB48;
    char padB48[0xC4C - 0xB48 - sizeof(int)];
    int unkC4C;
    char padC4C[0xE50 - 0xC4C - sizeof(int)];
    int unkE50;
    char padE50[0xF54 - 0xE50 - sizeof(int)];
    int unkF54;
    char padF54[0xFDC - 0xF54 - sizeof(int)];
    int unkFDC;
    char padFDC[0x1020 - 0xFDC - sizeof(int)];
    int unk1020;
    char pad1020[0x10A4 - 0x1020 - sizeof(int)];
    int unk10A4;
    char pad10A4[0x10B8 - 0x10A4 - sizeof(int)];
    int unk10B8;
    char pad10B8[0x10BC - 0x10B8 - sizeof(int)];
    int unk10BC;
    char pad10BC[0x1504 - 0x10BC - sizeof(int)];
    int unk1504;
};

struct func_8028DA90_S1;
/* unbake published declaration: published_272cc065cda814e931c5822b */
typedef struct func_8028DA90_S1 func_8028DA90_S1;

struct Object_func_8028CE94_de;
struct Table_func_8028CE94_de;
/* unbake published declaration: published_3c8e0bd23c00b7b720d95072 */
struct Object_func_8028CE94_de {
    char pad[0xA8];
    struct Table_func_8028CE94_de *unkA8;
    struct Table_func_8028CE94_de *unkAC;
};

struct Object_func_8028CE94_de;
/* unbake published declaration: published_454664fdefb7578755a7da8d */
typedef struct Object_func_8028CE94_de Object_func_8028CE94_de;

struct Container;
/* unbake published declaration: published_6f090f33d2b6404749dc9499 */
typedef struct Container Container;

struct Record_func_8028D050_de;
/* unbake published declaration: published_81040570294a963f67c28cb2 */
typedef struct Record_func_8028D050_de Record_func_8028D050_de;

struct Sub18;
struct Sub18 {
    s32 unk0;
    char pad4[8];
    s16 unkC;
};
struct Record_func_8028D050_de;
struct Sub18;
/* unbake published declaration: published_fb54ced59ab681348067ac56 */
struct Record_func_8028D050_de {
    char pad0[0x18];
    struct Sub18 *unk18;
    char pad1C[0xC8];
    u16 unkE4;
    char padE6[0x2E8 - 0xE6];
};

struct Container;
struct Record_func_8028D050_de;
/* unbake published declaration: published_e6f5cda15935faa4a3a38146 */
struct Container {
    char pad0[0x138];
    struct Record_func_8028D050_de *unk138;
    s32 unk13C;
    s32 unk140;
};

/* unbake published declaration: published_4f6f3a1251494db86ef7bdc2 */
extern s32 func_8028D050_de(Container *arg0, s32 key0, s32 key1, s32 key2, Record_func_8028D050_de **out, s32 max);

struct func_8028CD44_S1;
/* unbake published declaration: published_591f5918d8c194f309323781 */
typedef struct func_8028CD44_S1 func_8028CD44_S1;

struct Owner_func_8028D888_de;
/* unbake published declaration: published_5d0347acf97e800eda6af5cf */
typedef struct Owner_func_8028D888_de Owner_func_8028D888_de;

/* unbake published declaration: published_66e9413c3800c2f0cb478000 */
extern void func_8028D644_de(void *object);

/* unbake published declaration: published_6843f5606f4f7bad08f72b4c */
extern s32 func_8028D74C_de(void *arg0, void *arg1);

struct func_8028DA90_S1;
/* unbake published declaration: published_6b33b8a344be8a2d8ed534c9 */
struct func_8028DA90_S1 {
    char pad0[0x80];
    void * unk80;
    char pad80[0x84 - 0x80 - sizeof(void*)];
    void * unk84;
};

struct func_8028D578_S1;
/* unbake published declaration: published_6b4722021e6c4015536e7821 */
struct func_8028D578_S1 {
    char pad0[0x88];
    void * unk88;
    char pad88[0xF8 - 0x88 - sizeof(void*)];
    s32 unkF8;
};

struct ColorEntry;
/* unbake published declaration: published_7060fb4f1dbfb3048d6f6716 */
typedef struct ColorEntry ColorEntry;

struct func_8028CE54_S1;
/* unbake published declaration: published_738aafaea7b06fff2fee741d */
typedef struct func_8028CE54_S1 func_8028CE54_S1;

struct func_8028D628_S1;
/* unbake published declaration: published_8f008880f9ca8b4af586852a */
typedef struct func_8028D628_S1 func_8028D628_S1;

struct func_8028D728_S2;
/* unbake published declaration: published_9868a9e0eb8b05ad9092403c */
struct func_8028D728_S2 {
    char pad0[0x138];
    void * unk138;
    char pad138[0x140 - 0x138 - sizeof(void*)];
    u32 unk140;
};

struct func_8028CF7C_S1;
/* unbake published declaration: published_9bb91d9142c6c1b7c55f5a31 */
struct func_8028CF7C_S1 {
    char pad0[0x78];
    void * unk78;
};

struct func_8028D620_S1;
/* unbake published declaration: published_9c14abaf30d9e4b61d7e17a9 */
typedef struct func_8028D620_S1 func_8028D620_S1;

struct func_8028D620_S1;
/* unbake published declaration: published_a2c0948c1a17452b8e8db167 */
struct func_8028D620_S1 {
    char pad0[0x10BC];
    int unk10BC;
};

struct func_8028CE54_S1;
/* unbake published declaration: published_a373c32d9c4e5a933750e91d */
struct func_8028CE54_S1 {
    char pad0[0xA4];
    char * unkA4;
};

struct func_8028D35C_S1;
/* unbake published declaration: published_a6bc3611cf1dcfb76b0a6866 */
typedef struct func_8028D35C_S1 func_8028D35C_S1;

struct func_8028D268_S3;
/* unbake published declaration: published_ab2b057a11105277a82cc6a8 */
typedef struct func_8028D268_S3 func_8028D268_S3;

struct func_8028D578_S1;
/* unbake published declaration: published_b8f028cf622ab0549d38f366 */
typedef struct func_8028D578_S1 func_8028D578_S1;

struct func_8028CD44_S1;
/* unbake published declaration: published_bed3ac8f211d8ee1da2bfa57 */
struct func_8028CD44_S1 {
    char pad0[0x138];
    s32 unk138;
    char pad138[0x140 - 0x138 - sizeof(s32)];
    s32 unk140;
};

struct func_8028D220_S1;
/* unbake published declaration: published_d03df9ecd165ae3987f32653 */
struct func_8028D220_S1 {
    char pad0[0x7C];
    void * unk7C;
};

struct func_8028D7A0_S1;
/* unbake published declaration: published_d2415001b20851c235de7758 */
struct func_8028D7A0_S1 {
    char pad0[0x11C0];
    s32 unk11C0;
    char pad11C0[0x11C4 - 0x11C0 - sizeof(s32)];
    s32 unk11C4;
    char pad11C4[0x11C8 - 0x11C4 - sizeof(s32)];
    s32 unk11C8;
    char pad11C8[0x11CC - 0x11C8 - sizeof(s32)];
    s32 unk11CC;
    char pad11CC[0x11D0 - 0x11CC - sizeof(s32)];
    s32 unk11D0;
    char pad11D0[0x11D4 - 0x11D0 - sizeof(s32)];
    s32 unk11D4;
};

struct func_8028CF7C_S1;
/* unbake published declaration: published_d8a45bba7ecf58528a6bacb4 */
typedef struct func_8028CF7C_S1 func_8028CF7C_S1;

struct func_8028D0E4_S1;
/* unbake published declaration: published_e1f35556a23fc2b7d434bcb9 */
struct func_8028D0E4_S1 {
    char pad0[0x1B410];
    s32 unk1B410;
    char pad1B410[0x1B414 - 0x1B410 - sizeof(s32)];
    s32 unk1B414;
    char pad1B414[0x1B418 - 0x1B414 - sizeof(s32)];
    f32 unk1B418;
};

struct func_8028D268_S3;
/* unbake published declaration: published_e260c1f8c139a3d7a2a98733 */
struct func_8028D268_S3 {
    char pad0[0x38];
    char unk38;
};

/* unbake published declaration: published_ece095288fd8dc2d93d440eb */
extern float D_800C5300_de;

struct Owner_func_8028D888_de;
/* unbake published declaration: published_f10b04b0e34e3585b8cac937 */
struct Owner_func_8028D888_de {
    char pad0[0x944];
    s32 unk944;
    char pad948[0xC4C - 0x948];
    s32 unkC4C;
    char padC50[0x10BC - 0xC50];
    s32 unk10BC;
    char pad10C0[0x1500 - 0x10C0];
    s32 prevCount;
    s32 count;
    Triple entries[1];
};

struct func_8028D728_S2;
/* unbake published declaration: published_f6289473bff1d89734715878 */
typedef struct func_8028D728_S2 func_8028D728_S2;

struct func_8028D0E4_S1;
/* unbake published declaration: published_f704a50583d44392f33757ed */
typedef struct func_8028D0E4_S1 func_8028D0E4_S1;

struct func_8028D220_S1;
/* unbake published declaration: published_fa3a995aa8bb5c42f8b6a0bf */
typedef struct func_8028D220_S1 func_8028D220_S1;

struct func_8028D658_S1;
/* unbake published declaration: published_fabd06f0f0817187a2880065 */
typedef struct func_8028D658_S1 func_8028D658_S1;

#endif
