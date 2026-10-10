#include "acmd.h"
#include "audio_callbacks.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "decomp/argb_color.h"
#include "gfx.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_8022A274.h"
#include "span_1000/code_8023B9A0.h"
#include "span_1000/code_80243A80.h"
#include "span_1000/code_80246E34.h"
#include "span_1000/code_802508E0.h"
#include "span_1000/code_80256220.h"
#include "span_1000/code_8025A3EC.h"
#include "span_1000/code_8025C544.h"
#include "span_1000/code_80265370.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_8027302C.h"
#include "span_1000/code_8028308C.h"
#include "span_1000/code_8028CCB8.h"
#include "span_1000/code_8028DF6C.h"
#include "span_1000/code_8028FC98.h"
#include "span_1000/code_802944E8.h"
#include "span_1000/code_80297CD0.h"
#include "span_1000/code_802A6AC0.h"
#include "span_1000/code_802B0388.h"
#include "span_1000/code_802B243C.h"
#include "span_1000/code_802B4730.h"
#include "span_1000/code_802B53FC.h"
#include "span_1000/code_802B8DD0.h"
#include "span_1000/code_802B9ED8.h"
#include "span_1000/code_802BA23C.h"
#include "span_1000/code_802BBC68.h"
#include "span_1000/code_802BE0D0.h"
#include "span_166000/code_80426310.h"
#include "span_16E000/code_80403BCC.h"
#include "span_16E000/code_8040B45C.h"
#include "span_16E000/code_8040F1E0.h"
#include "span_16E000/code_804143D8.h"
#include "span_16E000/code_8041BEA8.h"
#include "span_16E000/code_8041DF04.h"
#include "span_16E000/code_8041F1FC.h"
#include "span_16E000/code_804221A0.h"
#include "span_16E000/code_804251F4.h"
#include "span_16E000/code_804264F0.h"
#include "span_16E000/code_8042BD40.h"
#include "span_16E000/code_8043962C.h"
#include "span_16E000/code_8043E9A8.h"
#include "span_16E000/code_8044ACCC.h"
#include "types.h"
#include "common/draft_fields_func_8026DC24_de.h"
#include "common/draft_fields_func_80283278_de.h"
#include "common/draft_fields_func_8028D474_de.h"
#include "common/draft_fields_func_8028D964_de.h"
#ifndef UNBAKE_SPAN_1000_CODE_8020EAE0_H
#define UNBAKE_SPAN_1000_CODE_8020EAE0_H
#include "../types.h"
#include "common/draft_fields_func_8020F5A4_de.h"
struct func_8020F93C_S1;
/* unbake published declaration: published_05f0862f18f519bde7d3954f */
typedef struct func_8020F93C_S1 func_8020F93C_S1;

struct func_8020F444_S3;
/* unbake published declaration: published_11daeca208a7f90fc85f9e39 */
typedef struct func_8020F444_S3 func_8020F444_S3;

/* unbake published declaration: published_1200409ce4996aa5da883b6c */


/* unbake published declaration: published_120cd997fc60799c06981bec */
extern float D_800C1EE4_de;

struct ObjectLinks1458;
/* unbake published declaration: published_14bf456c163516dbdb4ebe76 */
struct ObjectLinks1458 {
    char pad0[0x1454];
    char * unk_1454;
};

struct func_8020F444_S2;
/* unbake published declaration: published_228f954ef569fe4c3dbb8e1d */
typedef struct func_8020F444_S2 func_8020F444_S2;

struct ObjectLinks1458;
/* unbake published declaration: published_2a667e6a4c62cc6ad9a7cb1c */
typedef struct ObjectLinks1458 ObjectLinks1458;

struct Node_func_8020F150_de;
/* unbake published declaration: published_b22c47375fc66ad1f761f998 */
struct Node_func_8020F150_de {
    s32 id;
    char pad4[0xC];
    struct Node_func_8020F150_de *next;
    char pad14[0x20];
    char *owner;
};

struct Node_func_8020F150_de;
struct func_8020F150_S1;
/* unbake published declaration: published_33ad3e45a41792dfd2bb4fe7 */
struct func_8020F150_S1 {
    char pad0[0x24];
    struct Node_func_8020F150_de * unk24;
};

struct Actor1DC;
/* unbake published declaration: published_37ddf4ba82244947ea211aeb */
typedef struct Actor1DC Actor1DC;

struct func_8020F93C_S1;
/* unbake published declaration: published_445c22bb552c1ab023612ea8 */
struct func_8020F93C_S1 {
    char pad0[0x38];
    s32 unk38;
    char pad38[0x3C - 0x38 - sizeof(s32)];
    s32 unk3C;
    char pad3C[0x6C - 0x3C - sizeof(s32)];
    s32 unk6C;
};

struct func_8020EAE0_S1;
/* unbake published declaration: published_452b15da74eb12c67001a6f7 */
struct func_8020EAE0_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unkC;
    char padC[0x14 - 0xC - sizeof(s32)];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    s32 unk18;
    char pad18[0x28 - 0x18 - sizeof(s32)];
    s32 unk28;
    char pad28[0x1BC - 0x28 - sizeof(s32)];
    s32 unk1BC;
    char pad1BC[0x1C0 - 0x1BC - sizeof(s32)];
    s32 unk1C0;
    char pad1C0[0x2F4 - 0x1C0 - sizeof(s32)];
    s32 unk2F4;
    char pad2F4[0x2F8 - 0x2F4 - sizeof(s32)];
    s32 unk2F8;
    char pad2F8[0x2FC - 0x2F8 - sizeof(s32)];
    s32 unk2FC;
};

struct func_8020EE50_S1;
/* unbake published declaration: published_48c7119698252a40ba900175 */
typedef struct func_8020EE50_S1 func_8020EE50_S1;

struct ObjectLinks40;
/* unbake published declaration: published_4becbad3d729d038243561a1 */
typedef struct ObjectLinks40 ObjectLinks40;

struct func_8020EEA4_S2;
/* unbake published declaration: published_52db00ee9e16be6ee624cf31 */
struct func_8020EEA4_S2 {
    char pad0[0xC];
    u16 unkC;
    char padC[0xE - 0xC - sizeof(u16)];
    u16 unkE;
};

struct func_8020F444_S3;
/* unbake published declaration: published_5981aa58897157ba4e45074e */
struct func_8020F444_S3 {
    char pad0[0x1A4];
    s8 unk1A4;
};

struct Obj_func_8020F8F0_de;
/* unbake published declaration: published_59a6345e3af94473577a2421 */
struct Obj_func_8020F8F0_de {
    char pad[0x3C];
    int keys[10];
    char pad64[0x6C - 0x64];
    int flags[10];
    char pad94[0x28C - 0x94];
    int current;
};

struct Actor1DC;
/* unbake published declaration: published_64278d94a24014d552de4c45 */
struct Actor1DC {
    char pad0[0x1D8];
    char **info;
};

struct func_8020EAE0_S1;
/* unbake published declaration: published_6f8c0f8190f441514bb10ae8 */
typedef struct func_8020EAE0_S1 func_8020EAE0_S1;

/* unbake published declaration: published_715897414a07df14fc04b063 */
extern s32 func_8020F55C_de(s32 arg0);

/* unbake published declaration: published_71dd46e0dc626560dc6e6495 */
extern s32 func_8020F614_de(void);

struct Node_func_8020F150_de;
/* unbake published declaration: published_730738ddd80344c5f13152bb */
typedef struct Node_func_8020F150_de Node_func_8020F150_de;

struct Func8020ED50Arg;
/* unbake published declaration: published_730e5977d481df46ec060a7c */
struct Func8020ED50Arg {
    char pad0[4];
    s32 field4;
    char pad8[4];
    s32 fieldC;
    s32 field10;
};

/* unbake published declaration: published_7551b5503870154e34987296 */
extern s32 func_8020F57C_de(s32 arg0);

struct func_8020EE50_S1;
/* unbake published declaration: published_75b5d2b96553d62aef9328e7 */
struct func_8020EE50_S1 {
    char pad0[0x10];
    void * unk10;
    char pad10[0x18 - 0x10 - sizeof(void*)];
    f32 unk18;
    char pad18[0x38 - 0x18 - sizeof(f32)];
    s32 unk38;
};

struct Func8020ED50Arg;
/* unbake published declaration: published_8d2e88097e947fc00b07c818 */
typedef struct Func8020ED50Arg Func8020ED50Arg;

/* unbake published declaration: published_98737a6202b7debdbb223b2d */


struct func_8020F2A8_S1;
/* unbake published declaration: published_98df532cc89fc143b0347ce3 */
struct func_8020F2A8_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unkC;
    char padC[0x14 - 0xC - sizeof(s32)];
    char unk14;
    char pad14[0x68 - 0x14 - sizeof(char)];
    s32 unk68;
    char pad68[0xBC - 0x68 - sizeof(s32)];
    s32 unkBC;
};

struct func_8020F150_S1;
/* unbake published declaration: published_9a0a5f2115fe0969b73262dc */
typedef struct func_8020F150_S1 func_8020F150_S1;

struct func_8020F984_S2;
/* unbake published declaration: published_9e795483c480eecdb91819be */
struct func_8020F984_S2 {
    char pad0[0x38];
    s32 unk38;
    char pad38[0x3C - 0x38 - sizeof(s32)];
    void * unk3C;
    char pad3C[0x6C - 0x3C - sizeof(void*)];
    s32 unk6C;
    char pad6C[0x94 - 0x6C - sizeof(s32)];
    s32 unk94;
};

struct Obj_func_8020F8F0_de;
/* unbake published declaration: published_b0af7916e5660821a7cb04cc */
typedef struct Obj_func_8020F8F0_de Obj_func_8020F8F0_de;

/* unbake published declaration: published_b631cd0063bbe8d1751bcfa2 */
extern float D_800C1EE0_de;

/* unbake published declaration: published_b8340c0ea1af745761b2bf4f */


struct func_8020F984_S2;
/* unbake published declaration: published_b88852b06289f30d08398a2b */
typedef struct func_8020F984_S2 func_8020F984_S2;

struct func_8020EEA4_S3;
/* unbake published declaration: published_cab54bf21082d917067ac26d */
struct func_8020EEA4_S3 {
    char pad0[0x10];
    void * unk10;
    char pad10[0x18 - 0x10 - sizeof(void*)];
    f32 unk18;
};

struct func_8020EEA4_S2;
/* unbake published declaration: published_cb4600820e90837be4547bf1 */
typedef struct func_8020EEA4_S2 func_8020EEA4_S2;

struct func_8020F2A8_S1;
/* unbake published declaration: published_d2947bc71306587832c21328 */
typedef struct func_8020F2A8_S1 func_8020F2A8_S1;

/* unbake published declaration: published_dd6653a164f5941b4d193f74 */
extern float D_800C1EDC_de;

struct ObjectLinks40;
/* unbake published declaration: published_e4ddf34a4e336fcee680f302 */
struct ObjectLinks40 {
    unsigned char padding_0[60];
    Actor1DC *unk_3C;
};

struct func_8020F444_S2;
/* unbake published declaration: published_ef74726fbacc4fa315b61528 */
struct func_8020F444_S2 {
    char pad0[0x10];
    void * unk10;
    char pad10[0x34 - 0x10 - sizeof(void*)];
    void * unk34;
};

struct func_8020EEA4_S3;
/* unbake published declaration: published_fad9ce4788895c865c9ef2f7 */
typedef struct func_8020EEA4_S3 func_8020EEA4_S3;

extern int func_8020EF60_us(void * arg0);
extern int func_8020EF80_eu(void * arg0);
s32 func_8020EF80_eu_x(PickupGoalObj8020EF60 *arg0);
#endif
