#include "acmd.h"
#include "audio_callbacks.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
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
#ifndef UNBAKE_SPAN_1000_CODE_80212C90_H
#define UNBAKE_SPAN_1000_CODE_80212C90_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
/* unbake published declaration: published_0c842f1f491f68f4f7a160a3 */
extern float D_800C2100_de;

/* unbake published declaration: published_1390296b47881a6827f9e334 */
extern double D_800C2108_de;

/* unbake published declaration: published_1cd033c8bf4b0bd2db507065 */
extern double D_800C2110_de;

struct func_80213500_S7;
/* unbake published declaration: published_1d9248c43fea440de0bb9c81 */
struct func_80213500_S7 {
    char pad0[0x38];
    s32 unk38;
    char pad38[0x650 - 0x38 - sizeof(s32)];
    s16 unk650;
    char pad650[0x6B0 - 0x650 - sizeof(s16)];
    s32 unk6B0;
};

/* unbake published declaration: published_1e64b0f0fa44ab4e86b351f3 */
extern float D_800C20F0_de;

struct func_8021321C_S3;
/* unbake published declaration: published_2339d525d33a47c2a057182d */
struct func_8021321C_S3 {
    char pad0[0x38];
    u32 unk38;
    char pad38[0x5D8 - 0x38 - sizeof(u32)];
    void * unk5D8;
    char pad5D8[0x650 - 0x5D8 - sizeof(void*)];
    s16 unk650;
    char pad650[0x6B0 - 0x650 - sizeof(s16)];
    u32 unk6B0;
};

struct func_802136EC_S3;
/* unbake published declaration: published_23c5fc4982857d255c2e7ffb */
struct func_802136EC_S3 {
    char pad0[0xC];
    s32 unkC;
    char padC[0x220 - 0xC - sizeof(s32)];
    s32 unk220;
    char pad220[0x22C - 0x220 - sizeof(s32)];
    s32 unk22C;
    char pad22C[0x320 - 0x22C - sizeof(s32)];
    s32 unk320;
};

/* unbake published declaration: published_345dbf641db17ff492770d0b */
extern float D_800C2124_de;

struct func_80213340_S2;
/* unbake published declaration: published_35a57dbd8dadc90fcda3d815 */
struct func_80213340_S2 {
    char pad0[0xC];
    s32 unkC;
    char padC[0x22C - 0xC - sizeof(s32)];
    s32 unk22C;
};

struct func_80213340_S2;
/* unbake published declaration: published_3a71c77b6d0b65860822ede8 */
typedef struct func_80213340_S2 func_80213340_S2;

/* unbake published declaration: published_3be439c7d55671d795af9a5a */
extern void func_80212CC4_de(void *arg0);

/* unbake published declaration: published_4d35eed300317b702d3843cb */
extern void func_802131AC_de(void *arg0);

struct func_802138F0_S2;
/* unbake published declaration: published_50f448f47ff813d13b54a018 */
typedef struct func_802138F0_S2 func_802138F0_S2;

struct func_80212D94_S3;
/* unbake published declaration: published_526bb8052bb74cae35c14c86 */
typedef struct func_80212D94_S3 func_80212D94_S3;

struct func_80213500_S7;
/* unbake published declaration: published_568e8ab57fee7433cfcd8028 */
typedef struct func_80213500_S7 func_80213500_S7;

/* unbake published declaration: published_641ee4f3b9747274417d362c */
extern void func_8021321C_de(void *arg0);

union func_802138F0_S2_U18;
/* unbake published declaration: published_6f36b5972a2de516985ea513 */
typedef union func_802138F0_S2_U18 func_802138F0_S2_U18;

struct func_802138F0_S1;
/* unbake published declaration: published_7ca1809a9ce9d228d6c835b4 */
typedef struct func_802138F0_S1 func_802138F0_S1;

struct func_802138F0_S1;
/* unbake published declaration: published_7f4887e145c6a92f7edc36c3 */
struct func_802138F0_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s8 unk10;
    char pad10[0xCC - 0x10 - sizeof(s8)];
    s8 unkCC;
    char padCC[0x100 - 0xCC - sizeof(s8)];
    u8 unk100;
    char pad100[0x102 - 0x100 - sizeof(u8)];
    s16 unk102;
};

/* unbake published declaration: published_8639febe27fa1548cd51d7fb */
extern void func_802136EC_de(void *arg0);

union func_802138F0_S2_U18;
/* unbake published declaration: published_a2b6755fbc3003782af3fe05 */
union func_802138F0_S2_U18 {
    s32 v0;
    s16 v1;
};

struct func_802138F0_S2;
/* unbake published declaration: published_8cf5da65cb5fdc3c4b5104e8 */
struct func_802138F0_S2 {
    char pad0[0xE];
    s8 unkE;
    char padE[0x10 - 0xE - sizeof(s8)];
    s8 unk10;
    char pad10[0x12 - 0x10 - sizeof(s8)];
    s8 unk12;
    char pad12[0x18 - 0x12 - sizeof(s8)];
    func_802138F0_S2_U18 unk18;
    char pad18[0x40 - 0x18 - sizeof(func_802138F0_S2_U18)];
    u8 unk40;
    char pad40[0x41 - 0x40 - sizeof(u8)];
    u8 unk41;
};

struct Source;
/* unbake published declaration: published_a93a5780a892c94ec26b36ad */
struct Source {
    u8 pad0[8];
    Vec3 position;
    u8 pad14[4];
    s32 *kind;
    Vec3 velocity;
    u8 pad28[0x10];
    s32 flags38;
    u8 pad3c[0x30];
    f32 height;
};

struct func_80213500_S3;
/* unbake published declaration: published_aa58af66bfb0d8f90146b2d4 */
typedef struct func_80213500_S3 func_80213500_S3;

struct func_80213CF8_S1;
/* unbake published declaration: published_abd2b46754f66758aa68ccae */
typedef struct func_80213CF8_S1 func_80213CF8_S1;

/* unbake published declaration: published_add60784093fc36ceb4207a4 */
extern int D_8013B368;

/* unbake published declaration: published_b81712b8b01a0973dc8883e9 */
extern float D_800C2120_de;

struct IntegerState23C;
/* unbake published declaration: published_c6f2b5eba756c5fdd2665e72 */
struct IntegerState23C {
    unsigned char padding_0[104];
    s32 unk_68;
    unsigned char padding_6C[436];
    s32 unk_220;
    unsigned char padding_224[20];
    s32 unk_238;
};

/* unbake published declaration: published_c78d45fb698d64a9973e7bbf */
extern float D_800C2118_de;

/* unbake published declaration: published_c8824d0d2b1573872175ab6c */
extern void func_80212D94_de(void *arg0);

struct func_80212D94_S3;
/* unbake published declaration: published_d4d531c2205c72a0f7c2c260 */
struct func_80212D94_S3 {
    char pad0[0x10];
    s32 unk10;
    char pad10[0x64 - 0x10 - sizeof(s32)];
    void * unk64;
};

struct func_8021321C_S3;
/* unbake published declaration: published_db0918fcfab7673565545424 */
typedef struct func_8021321C_S3 func_8021321C_S3;

/* unbake published declaration: published_db42690b49295ce425e8ca3a */
extern void func_80213810_de(void *arg0);

struct IntegerState23C;
/* unbake published declaration: published_e05e6a58b4c4295a8570c764 */
typedef struct IntegerState23C IntegerState23C;

struct func_80213500_S3;
/* unbake published declaration: published_e4ac25f6dcc1378c812c529e */
struct func_80213500_S3 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unkC;
    char padC[0x22C - 0xC - sizeof(s32)];
    s32 unk22C;
    char pad22C[0x314 - 0x22C - sizeof(s32)];
    s32 unk314;
    char pad314[0x320 - 0x314 - sizeof(s32)];
    s32 unk320;
};

/* unbake published declaration: published_e631c4c8433ec9f4b44d26db */
extern void func_80212C90_de(void *arg0);

/* unbake published declaration: published_e74ff55ecd2c8316fb2751ac */
extern void func_80213500_de(void *arg0);

struct func_8021321C_S5;
/* unbake published declaration: published_e7790000e8ee9eab8fc6217d */
typedef struct func_8021321C_S5 func_8021321C_S5;

struct Source;
/* unbake published declaration: published_f53842e42c9f8cf13748a485 */
typedef struct Source Source;

struct func_80213CF8_S1;
/* unbake published declaration: published_f858c3eb02915e8602a7c4e2 */
struct func_80213CF8_S1 {
    char pad0[0x8];
    Vec3 unk8;
    char pad8[0x18 - 0x8 - sizeof(Vec3)];
    s32 * unk18;
};

struct func_8021321C_S5;
/* unbake published declaration: published_fc84e030b082f8086d2c677c */
struct func_8021321C_S5 {
    char pad0[0xC];
    s32 unkC;
    char padC[0x320 - 0xC - sizeof(s32)];
    s32 unk320;
};

struct func_802136EC_S3;
/* unbake published declaration: published_ff4fe2c3d15a342a07c7fba3 */
typedef struct func_802136EC_S3 func_802136EC_S3;

extern int func_80212D60_de(void * arg0);
extern int func_80212D80_eu(void * arg0);
extern void func_80212D80_eu_x(struct Actor_func_80212D78_eu_x *arg0);

void func_802131E0_de(Root802131E0 *arg0);
#endif
