#ifndef UNBAKE_SPAN_16E000_CODE_8044ACCC_H
#define UNBAKE_SPAN_16E000_CODE_8044ACCC_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct func_8044B388_S1;
/* unbake published declaration: published_03e9c7e3de05cad75660efbd */
typedef struct func_8044B388_S1 func_8044B388_S1;

struct Object_func_8044D220_de;
/* unbake published declaration: published_0715a667da33b1413a7a313c */
struct Object_func_8044D220_de {
    s32 w[4];
    s16 kind;
    s16 pad12;
};

struct func_8044CD58_S2;
/* unbake published declaration: published_0bb211f30fe63a458acee448 */
typedef struct func_8044CD58_S2 func_8044CD58_S2;

struct State_func_8044D5C4_de;
/* unbake published declaration: published_0fb985f91aa95a03bec1931f */
struct State_func_8044D5C4_de {
    char p[0x11C0];
    s32 unk11C0;
    s32 unk11C4;
    char q[8];
    s32 unk11D0;
    s32 unk11D4;
};

struct ObjB;
/* unbake published declaration: published_1a0f621e4ceca3197f0d6100 */
typedef struct ObjB ObjB;

struct Track_func_8044D220_de;
/* unbake published declaration: published_1b5a6c69de844c6abe5cb3cf */
struct Track_func_8044D220_de {
    char pad0[0x90];
    s32 resource;
};

struct LightSettings;
struct LightSettings {
    char pad0[0xA];
    u8 color[3];
    u8 ambient[3];
    char pad10;
    signed char dir[3];
};
struct LightSettings;
struct Scene_func_8044BE04_de;
/* unbake published declaration: published_1ea5d767fee9755fb453c5ad */
struct Scene_func_8044BE04_de {
    char pad0[0x1B2B0];
    struct LightSettings *light;
    s16 dir[3];
};

struct func_8044B27C_S1;
/* unbake published declaration: published_214465e0da8418e64a9b4304 */
struct func_8044B27C_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    IntrusiveList unkC;
    IntrusiveList unk20;
    char pad34[0x38 - 0x34];
    s32 unk38;
    char pad38[0x40 - 0x38 - sizeof(s32)];
    char unk40;
    char pad40[0xF18 - 0x40 - sizeof(char)];
    s32 unkF18;
    char padF18[0xF1C - 0xF18 - sizeof(s32)];
    s32 unkF1C;
    char padF1C[0xF20 - 0xF1C - sizeof(s32)];
    s32 unkF20;
    char padF20[0xF24 - 0xF20 - sizeof(s32)];
    IntrusiveList unkF24;
    char padF24[0x1200 - 0xF24 - sizeof(IntrusiveList)];
    s32 unk1200;
};

struct func_8044CBE0_S1;
/* unbake published declaration: published_2cc73a5be27e6400a95e3e0c */
typedef struct func_8044CBE0_S1 func_8044CBE0_S1;

struct func_8044B27C_S1;
/* unbake published declaration: published_2ef454522ca91f75f3412cd5 */
typedef struct func_8044B27C_S1 func_8044B27C_S1;

struct func_8044ADC0_S1;
/* unbake published declaration: published_313fba72233e3fc5100a149e */
struct func_8044ADC0_S1 {
    char pad0[0x24];
    u8 unk24;
    char pad24[0xA0 - 0x24 - sizeof(u8)];
    u8 unkA0;
    char padA0[0xB8 - 0xA0 - sizeof(u8)];
    u8 unkB8;
    char padB8[0xCC - 0xB8 - sizeof(u8)];
    u8 unkCC;
    char padCC[0xE0 - 0xCC - sizeof(u8)];
    u8 unkE0;
    char padE0[0x140 - 0xE0 - sizeof(u8)];
    u8 unk140;
    char pad140[0x160 - 0x140 - sizeof(u8)];
    u8 unk160;
    char pad160[0x1A0 - 0x160 - sizeof(u8)];
    u8 unk1A0;
    char pad1A0[0x1E0 - 0x1A0 - sizeof(u8)];
    u8 unk1E0;
    char pad1E0[0x554 - 0x1E0 - sizeof(u8)];
    u8 unk554;
    char pad554[0xE40 - 0x554 - sizeof(u8)];
    IntrusiveList unkE40;
    char padE40[0xE54 - 0xE40 - sizeof(IntrusiveList)];
    u8 unkE54;
    char padE54[0xE94 - 0xE54 - sizeof(u8)];
    u8 unkE94;
};

struct State_func_8044A170_de;
/* unbake published declaration: published_33d69d29419f50a675dc6095 */
struct State_func_8044A170_de {
    char pad0[12];
    f32 unkC;
    f32 unk10;
    char pad14[104];
    s32 unk7C;
    char pad80[116];
    f32 unkF4;
    f32 unkF8;
    char padFC[36];
    s32 unk120;
    s16 unk124;
    s16 unk126;
    char pad128[24];
    f32 unk140;
    char pad144[8];
    f32 unk14C;
    char pad150[332];
    f32 unk29C;
    f32 unk2A0;
    f32 unk2A4;
    f32 unk2A8;
    char pad2AC[4];
    s16 unk2B0;
    s16 unk2B2;
    s16 unk2B4;
    s16 unk2B6;
    s16 unk2B8;
    s16 unk2BA;
    s16 unk2BC;
    s16 unk2BE;
    char pad2C0[600];
    s32 unk518;
    f32 unk51C;
    u8 unk520;
    u8 unk521;
    u8 unk522;
    u8 unk523;
    u8 unk524;
    u8 unk525;
    u8 unk526;
    u8 unk527;
    f32 unk528;
    f32 unk52C;
    f32 unk530;
    f32 unk534;
    char pad538[4];
    s32 unk53C;
    s32 unk540;
    s32 unk544;
    u8 unk548;
};

struct Bucket;
/* unbake published declaration: published_471abe7b7133cf21ce18265f */
typedef struct Bucket Bucket;

struct Scene_func_8044BE04_de;
/* unbake published declaration: published_48c7b7872d4991bdb0c6fa77 */
typedef struct Scene_func_8044BE04_de Scene_func_8044BE04_de;

struct Level_func_8044CD8C_de;
/* unbake published declaration: published_56bc57263924032593e9862a */
struct Level_func_8044CD8C_de {
    char pad0[0x30];
    s32 key;
    char pad34[0x64 - 0x34];
    s32 file;
    void *grid;
};

struct Record_func_8044B0E0_de;
/* unbake published declaration: published_62b4bfbae9de117fc805f904 */
typedef struct Record_func_8044B0E0_de Record_func_8044B0E0_de;

typedef IntrusiveList List_func_8044D220_de;

struct Bucket;
/* unbake published declaration: published_67dad23f781318bbd3282061 */
struct Bucket {
    char pad0[0x10];
};

struct Floats;
/* unbake published declaration: published_6a829e40a0b390440726b718 */
typedef struct Floats Floats;

struct State_func_8044D528_de;
/* unbake published declaration: published_6be81ebb4d088799734f18a7 */
typedef struct State_func_8044D528_de State_func_8044D528_de;

struct Node_func_8044D220_de;
/* unbake published declaration: published_6cdfb76b51d99806ecd8c592 */
struct Node_func_8044D220_de {
    s32 index;
    s32 link[2];
};

struct ObjA;
/* unbake published declaration: published_6eca4361159d9949f04b4407 */
typedef struct ObjA ObjA;

struct func_8044AD14_S1;
/* unbake published declaration: published_76764fb650f0df8d95430623 */
typedef struct func_8044AD14_S1 func_8044AD14_S1;

struct Face;
/* unbake published declaration: published_80f0f00cf25f576f7f22d299 */
struct Face {
    char pad0[0xE];
    u8 flags;
    u8 hidden;
    char pad10[3];
    u8 group;
};

struct Face;
/* unbake published declaration: published_84a579a7937e3398e6b655b9 */
typedef struct Face Face;

struct func_8044CD58_S2;
/* unbake published declaration: published_7d8422f136aed686ff6b5ca3 */
struct func_8044CD58_S2 {
    char pad0[0x8];
    Face unk8;
};

union func_8044CBE0_S1_U1B500;
/* unbake published declaration: published_faa1761375a00f945a4b4a5d */
union func_8044CBE0_S1_U1B500 {
    void * v0;
    s8 v1;
};

union func_8044CBE0_S1_U1B500;
/* unbake published declaration: published_fadfa2f79e688582e2330cde */
typedef union func_8044CBE0_S1_U1B500 func_8044CBE0_S1_U1B500;

struct func_8044CBE0_S1;
/* unbake published declaration: published_87b278bfae3ccc46b2ee5ebb */
struct func_8044CBE0_S1 {
    char pad0[0xB8];
    void * unkB8;
    void * unkBC;
    void * unkC0;
    void * unkC4;
    void * unkC8;
    void * unkCC;
    void * unkD0;
    void * unkD4;
    char padD4[0x10];
    void * unkE8;
    void * unkEC;
    void * unkF0;
    void * unkF4;
    char padF4[0x4];
    void * unkFC;
    void * unk100;
    char pad100[0x1B3FC];
    IntrusiveList unk1B500;
};

struct State_func_8044D0F0_de;
/* unbake published declaration: published_8d58e8caf7698d8f4c8bc2dd */
struct State_func_8044D0F0_de {
    char pad[0x3C];
    int resource;
    char pad40[8];
    int bank;
    char pad4c[0x1B3C0];
    int selection;
    char pad1b410[12];
    int changed;
};

struct Track_func_8044D220_de;
/* unbake published declaration: published_8e7a95c9b4a3d45829ece90c */
typedef struct Track_func_8044D220_de Track_func_8044D220_de;

struct Node_func_8044D220_de;
/* unbake published declaration: published_93b184ea0ba838bfa318ace1 */
typedef struct Node_func_8044D220_de Node_func_8044D220_de;

struct State_func_8044D0F0_de;
/* unbake published declaration: published_947c4f0f4169a8d36f755296 */
typedef struct State_func_8044D0F0_de State_func_8044D0F0_de;

struct State_func_8044A170_de;
/* unbake published declaration: published_d5583accc538aa0c239f9794 */
typedef struct State_func_8044A170_de State_func_8044A170_de;

struct func_8044ADC0_S2;
/* unbake published declaration: published_958e83fc183c003efbc03158 */
struct func_8044ADC0_S2 {
    char pad0[0x10];
    State_func_8044A170_de unk10;
};

struct func_8044DE04_S1;
/* unbake published declaration: published_967b3a335a75fad31729a419 */
struct func_8044DE04_S1 {
    char pad0[0x1B410];
    s32 unk1B410;
    char pad1B410[0x1B414 - 0x1B410 - sizeof(s32)];
    s32 unk1B414;
    char pad1B414[0x1B418 - 0x1B414 - sizeof(s32)];
    s32 unk1B418;
    char pad1B418[0x1B41C - 0x1B418 - sizeof(s32)];
    s32 unk1B41C;
    char pad1B41C[0x1B434 - 0x1B41C - sizeof(s32)];
    s32 unk1B434;
    char pad1B434[0x1B438 - 0x1B434 - sizeof(s32)];
    s32 unk1B438;
    char pad1B438[0x1B43C - 0x1B438 - sizeof(s32)];
    s32 unk1B43C;
    char pad1B43C[0x1B440 - 0x1B43C - sizeof(s32)];
    s32 unk1B440;
};

struct Record_func_8044B0E0_de;
/* unbake published declaration: published_99c6af227884454015bdae7a */
struct Record_func_8044B0E0_de {
    char p[8];
    s32 unk8;
    f32 unkC;
    char q[6];
    s16 unk16;
};

struct Pool_func_8044B0E0_de;
/* A list of the pool's eight records and a second, empty list. */
struct Pool_func_8044B0E0_de {
    IntrusiveList empty;
    IntrusiveList records;
    struct Record_func_8044B0E0_de entries[8];
};

/* unbake published declaration: published_a8cd9df325b9249a05caebaa */
extern float D_800CA1F0;

struct ObjA;
/* unbake published declaration: published_a9390afccb50143e4577ceab */
struct ObjA {
    s8 pad0;
    s8 type;
    char pad2[0x20 - 2];
    void **block;
    char pad24[0xE8 - 0x24];
};

struct Level_func_8044CD8C_de;
/* unbake published declaration: published_ab2eebee946e6037911db766 */
typedef struct Level_func_8044CD8C_de Level_func_8044CD8C_de;


struct func_8044AD14_S1;
/* unbake published declaration: published_ad7d00f349fd0aead2ac4135 */
struct func_8044AD14_S1 {
    char pad0[0x3];
    u8 unk3;
    char pad3[0x18 - 0x3 - sizeof(u8)];
    void * unk18;
    char pad18[0x5D8 - 0x18 - sizeof(void*)];
    void * unk5D8;
    char pad5D8[0x5E0 - 0x5D8 - sizeof(void*)];
    s32 unk5E0;
    char pad5E0[0x86C - 0x5E0 - sizeof(s32)];
    s32 unk86C;
};

struct Face;
struct World_func_8044C108_de;
/* unbake published declaration: published_b14efc97a06d9009324be95e */
struct World_func_8044C108_de {
    char pad0[0x80];
    void *tree;
    char pad84[0x11C0 - 0x84];
    s32 nfaces;
    s32 nedges;
    void *verts;
    void *edgeData;
    struct Face *faces;
    struct Face *edges;
    IntrusiveList listA;
    IntrusiveList listB;
    Bucket buckets[0x30];
    char pad1500[0x1B40C - 0x1500];
    s32 group;
};

struct func_8044DC48_S1;
/* unbake published declaration: published_bcd8c5d65e5346023eb35e54 */
struct func_8044DC48_S1 {
    char pad0[0x1B444];
    s32 unk1B444;
    char pad1B444[0x1B448 - 0x1B444 - sizeof(s32)];
    s32 unk1B448;
    char pad1B448[0x1B44C - 0x1B448 - sizeof(s32)];
    s32 unk1B44C;
};

struct func_8044ADC0_S1;
/* unbake published declaration: published_c284947750ad8fd02c12a019 */
typedef struct func_8044ADC0_S1 func_8044ADC0_S1;

struct Object_func_8044D220_de;
/* unbake published declaration: published_ca85549dbf05a794bd997b96 */
typedef struct Object_func_8044D220_de Object_func_8044D220_de;

/* unbake published declaration: published_cc47fe67a6f2024256f55403 */
extern short D_8010F320;

struct State_func_8044D528_de;
/* unbake published declaration: published_cd6af7fbd41b171e29f57d14 */
struct State_func_8044D528_de {
    char pad[0x1B2B0];
    Resource_func_80419E54_de *input;
    char pad1b2b4[0x15C];
    int mode;
    int active;
    char pad1b418[0x20];
    int selection;
};

struct func_8044D9DC_S1;
/* unbake published declaration: published_debcf34518aece203f8d24f9 */
typedef struct func_8044D9DC_S1 func_8044D9DC_S1;

struct func_8044DE04_S1;
/* unbake published declaration: published_dfa64f0f9e4b63873270bf69 */
typedef struct func_8044DE04_S1 func_8044DE04_S1;

struct func_8044B420_S1;
/* unbake published declaration: published_e11f3c33d8e73aa79a16e6e0 */
struct Entry_func_8044A7D0_de {
    char pad0[0x228];
};

struct func_8044B420_S1 {
    struct Entry_func_8044A7D0_de entries[4];
    IntrusiveList free;
    IntrusiveList active;
    s16 unk8C8;
};

struct func_8044B388_S1;
/* unbake published declaration: published_e1476b404f133e421e0f2871 */
struct func_8044B388_S1 {
    char pad0[0xC];
    char unkC;
    char padC[0x20 - 0xC - sizeof(char)];
    IntrusiveList unk20;
};

struct func_8044ADC0_S2;
/* unbake published declaration: published_e1a1fc83c1e471b78aa089bb */
typedef struct func_8044ADC0_S2 func_8044ADC0_S2;

struct State_func_8044D5C4_de;
/* unbake published declaration: published_e1f64bd196785a44f72a94eb */
typedef struct State_func_8044D5C4_de State_func_8044D5C4_de;

struct func_8044B420_S1;
/* unbake published declaration: published_e22b85f0ce79b7c4622e43cd */
typedef struct func_8044B420_S1 func_8044B420_S1;

/* unbake published declaration: published_e6d3488b06462f7d3306f6e0 */
extern s16 func_8044AE70_de();

struct Floats;
/* unbake published declaration: published_eb7e1aedf4fe20ba41e44888 */
struct Floats {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};

struct func_8044DC48_S1;
/* unbake published declaration: published_ec65ebd705eaee7ed9d3a1b0 */
typedef struct func_8044DC48_S1 func_8044DC48_S1;

struct func_8044D9DC_S1;
/* unbake published declaration: published_f85fc8254c3c5703ab026de5 */
struct func_8044D9DC_S1 {
    char pad0[0x8];
    func_8022BC04_S3 unk8;
};

struct Object_func_8044A07C_de;
/* unbake published declaration: published_fe86c82f8ad35cecf64a81a5 */
struct Object_func_8044A07C_de {
    char pad[0x11BC];
    s32 first;
    s32 second;
};

struct World_func_8044C108_de;
/* unbake published declaration: published_ff33d1624dc36a7a729a3f00 */
typedef struct World_func_8044C108_de World_func_8044C108_de;

struct ObjB;
/* unbake published declaration: published_ffc8a37c2286ca66a3ebb2fa */
struct ObjB {
    s8 pad0;
    s8 type;
    char pad2[0x60 - 2];
    void **block;
    char pad64[0x1C8 - 0x64];
};

#endif
