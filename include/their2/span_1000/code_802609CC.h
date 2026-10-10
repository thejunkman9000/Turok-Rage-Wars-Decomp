#ifndef UNBAKE_SPAN_1000_CODE_802609CC_H
#define UNBAKE_SPAN_1000_CODE_802609CC_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
/* unbake published declaration: published_0af77100b843ca464eb4c115 */
extern float D_800C41A0_de;

/* unbake published declaration: published_13b53b91c4c9b2a8146ad432 */
extern double D_800C4190_de;

/* unbake published declaration: published_173a4117339dadd87ca9c4fe */
extern f32 func_802615B4_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5);

/* unbake published declaration: published_1a8163948910db56c7932049 */
extern float D_800C4198_de;

/* unbake published declaration: published_2d2956933b903b16919464a2 */
extern float D_8010AC70;

struct LocalDecodeRange;
/* unbake published declaration: published_6efc251518a416900928f4c5 */
struct LocalDecodeRange {
    u32 unused;
    Func802608ECResult range;
};

struct LocalDecodeRange;
/* unbake published declaration: published_e02ffa946504468cbf6d372c */
typedef struct LocalDecodeRange LocalDecodeRange;

/* unbake published declaration: published_3904b4d42b06b7a454c1c4ae */
extern f32 func_80260EF8_de(LocalDecodeRange *arg0);

/* unbake published declaration: published_39d7fa2b63ad88f1deef6034 */
extern double D_800C4170_de;

/* unbake published declaration: published_42fa7b99825a028a8bb7d72a */
extern void func_80260C6C_de(void *arg0, int arg1, Triple t, int arg5);

struct Stream_func_80261418_de;
/* unbake published declaration: published_470fd60e3f006dce5685811e */
struct Stream_func_80261418_de {
    s32 unk0;
    char pad4[8];
    s32 unkC;
    char pad10[16];
    u32 unk20;
    u32 unk24;
    s32 unk28;
};

struct func_80260C8C_S1;
/* unbake published declaration: published_4a16a693ff1daa89e78a2f91 */
typedef struct func_80260C8C_S1 func_80260C8C_S1;

struct Track_func_80261180_de;
/* unbake published declaration: published_50768aa534acbe119e1ecd5c */
struct Track_func_80261180_de {
    s32 keys;
    char pad4[0x2C - 4];
    s32 stride;
};

/* unbake published declaration: published_5592ff8744d5f892e035e9f1 */
extern unsigned int func_8026100C_de(unsigned int *arg0, unsigned int arg1);

struct DecodeArray;
/* unbake published declaration: published_5b94525fa13ae82256da3780 */
struct DecodeArray {
    s32 base;
    Func802608ECResult range;
};

struct BitFieldSource;
/* unbake published declaration: published_dc884619b04e17e85f1d1bc9 */
typedef struct BitFieldSource BitFieldSource;

struct BitFieldSource;
/* unbake published declaration: published_eaa5ed72ad457ecbd13d77db */
struct BitFieldSource {
    int base;
    unsigned int width;
};

/* unbake published declaration: published_5c9237f0f3f0b9bae1a7f7cc */
extern int func_80260E4C_de(BitFieldSource *arg0, int arg1);

struct DecodeArray;
/* unbake published declaration: published_fbf9560b660aad1dfb7e4d9a */
typedef struct DecodeArray DecodeArray;

/* unbake published declaration: published_5dbb13f1848faee073011e72 */
extern f32 func_80260C9C_de(DecodeArray *arg0, s32 arg1);

/* unbake published declaration: published_6240432d622ae5ceb08e0dab */
extern int func_8026140C_de(char *object);

/* unbake published declaration: published_6d89c647be30bb1387c2e940 */
extern void func_80261180_de(char **stream, f32 *out, s32 frames);

/* unbake published declaration: published_6deeab005fb375dd268c17c2 */
extern unsigned int func_8026160C_de(unsigned int value);

/* unbake published declaration: published_7142a23515d7f4c7f2843c99 */
extern double D_800C4188_de;

/* unbake published declaration: published_75b1f1fa2e4cf3c3336dd7fa */
extern int func_80260DA8_de(BitFieldSource *arg0, int arg1);

/* unbake published declaration: published_784672d9c94db8ee9f6c633a */
extern u32 func_80261614_de(s32 arg0);

struct func_80260EEC_S1;
/* unbake published declaration: published_8617670d36ac35c83eb73b64 */
typedef struct func_80260EEC_S1 func_80260EEC_S1;

struct Pack;
/* unbake published declaration: published_8ad5b5da1097af113cd2c9e0 */
struct Pack {
    s32 count;
    s32 offsets[1];
};

/* unbake published declaration: published_9174a9ae1e25b4d14d6133ce */
extern double D_800C4180_de;

struct Anim;
/* unbake published declaration: published_96ea68b27701568d4ec9d41a */
struct Anim {
    s32 time;
    s16 current;
    s16 next;
    u16 frames;
    u8 blending;
    u8 active;
    s32 length;
    void *resource;
};

/* unbake published declaration: published_a2de2972013f89f1e85f75b7 */
extern void func_80260FF0_de(unsigned int *record, int index);

/* unbake published declaration: published_a43648a2ef632ff9e36da9a1 */
extern void func_80260A5C_de(s32 arg0, Func802608ECResult range, f32 arg4);

/* unbake published declaration: published_ab7fc8b33c2a3c323ef5a6fb */
extern void func_80260E1C_de(void *arg0, int arg1, Triple t, int arg5);

struct Entry802612C8;
/* unbake published declaration: published_b9fedd92a141a058fd218795 */
struct Entry802612C8 {
    s32 x;
    s32 pad4;
    s32 z;
    f32 f0C;
    s32 n10;
    s32 n14;
};

struct Anim;
/* unbake published declaration: published_c68e0bcf0c7c88c16e6a803a */
typedef struct Anim Anim;

struct Pack;
/* unbake published declaration: published_cbc6f6843de17e8eea01c783 */
typedef struct Pack Pack;

/* unbake published declaration: published_cd4e4eaf3a448afaa1dc3f3a */
extern void func_80260ECC_de(void *arg0, int arg1, Triple t);

struct Entry802612C8;
/* unbake published declaration: published_ce1c79542ad73002edad19b2 */
typedef struct Entry802612C8 Entry802612C8;

/* unbake published declaration: published_d1e430076dd5755fc70d22d8 */
extern float D_800C41A4_de;

struct Track_func_80261180_de;
/* unbake published declaration: published_d94324924f957dae9b12ab92 */
typedef struct Track_func_80261180_de Track_func_80261180_de;

/* unbake published declaration: published_e2ac276c0e0e9c8387696dcc */
extern f32 func_802609AC_de(s32 bitAddress, Func802608ECResult range);

/* unbake published declaration: published_f2c1870800b92097f3302b73 */
extern void func_80260D78_de(void *arg0, int arg1, Triple t, int arg5);

struct func_80260C8C_S1;
/* unbake published declaration: published_f37f4d76c8e0273e260f33d6 */
struct func_80260C8C_S1 {
    int unk0;
    char pad0[0x4 - 0x0 - sizeof(int)];
    Triple unk4;
    char pad4[0x10 - 0x4 - sizeof(Triple)];
    int unk10;
};

struct Stream_func_80261418_de;
/* unbake published declaration: published_f9282694b9218a0dc7a7ed23 */
typedef struct Stream_func_80261418_de Stream_func_80261418_de;

struct func_80260EEC_S1;
/* unbake published declaration: published_fec4983253e7c798ac201cb6 */
struct func_80260EEC_S1 {
    int unk0;
    char pad0[0x4 - 0x0 - sizeof(int)];
    Triple unk4;
};

/* unbake published declaration: published_ff3535174168b355dce20d9a */
extern void func_8026107C_de(int *arg0, int arg1);

#endif
