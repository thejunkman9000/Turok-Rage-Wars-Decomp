#ifndef UNBAKE_SPAN_1000_CODE_802AB3FC_H
#define UNBAKE_SPAN_1000_CODE_802AB3FC_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
struct LocalizedEffectContext;
/* unbake published declaration: published_0e408923d6da5f495659405f */
typedef struct LocalizedEffectContext LocalizedEffectContext;

struct Entry_func_802AB400_de;
/* unbake published declaration: published_1199e0064f0b5410e99fa700 */
typedef struct Entry_func_802AB400_de Entry_func_802AB400_de;

/* unbake published declaration: published_1b1e61e50251108f62fd4cd8 */
extern void func_802AB1B0_de(u16 *grid, f32 x0, f32 y, f32 sx, f32 sy);

struct Actor_func_802AB6EC_de;
/* unbake published declaration: published_20995f968d6a5066e097c7eb */
struct Actor_func_802AB6EC_de {
    char pad0[0x5E4];
    s32 enabled;
    char pad5E8[0x1224 - 0x5E8];
    s32 lockOn[2];
    char pad122C[0x16E0 - 0x122C];
    struct Actor_func_802AB6EC_de *next;
};

struct func_802ADB08_S2;
/* unbake published declaration: published_28e61d3507651e98a13be380 */
struct func_802ADB08_S2 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x5DC - 0x10 - sizeof(s32)];
    void * unk5DC;
};

struct func_802ADA44_S1;
/* unbake published declaration: published_2f40ed297c4b82e79b646bde */
struct func_802ADA44_S1 {
    char pad0[0x14];
    s32 unk14;
    char pad14[0x19C - 0x14 - sizeof(s32)];
    u16 unk19C;
    char pad19C[0x1D0 - 0x19C - sizeof(u16)];
    s32 unk1D0;
};

/* unbake published declaration: published_2fe923455b1ad2e836073ee9 */


/* unbake published declaration: published_3191936727c880535f53cfff */
extern s32 func_802AD1B4_de(void *arg0);

/* unbake published declaration: published_349dc2c648c197ba8e7ff589 */


struct Actor_func_802AB400_de;
/* unbake published declaration: published_387aebd12f354d95b77fb1b9 */
struct Actor_func_802AB400_de {
    u8 type;
    char pad1[0xE4 - 1];
    u16 team;
    char padE6[0x100 - 0xE6];
    s32 flags;
    char pad104[0x5D8 - 0x104];
    func_8020EA10_S3 *model;
    char pad5DC[0x5E4 - 0x5DC];
    s32 count;
    char pad5E8[0x5F4 - 0x5E8];
    s16 levels[7];
    char pad602[0x602 - 0x602];
    Shared_Slot slots[22];
};

struct func_802ADBF4_S1;
/* unbake published declaration: published_388583d893394b85d09843da */
struct func_802ADBF4_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x174 - 0x10 - sizeof(s32)];
    s32 unk174;
    char pad174[0x5DC - 0x174 - sizeof(s32)];
    void * unk5DC;
    char pad5DC[0x5E4 - 0x5DC - sizeof(void*)];
    s32 unk5E4;
};

struct func_802ADBF4_S2;
/* unbake published declaration: published_49465273d01231dea400f26e */
struct func_802ADBF4_S2 {
    char pad0[0x6];
    s16 unk6;
    char pad6[0x8 - 0x6 - sizeof(s16)];
    s16 unk8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    s32 unkC;
};

struct Actor_func_802AB6EC_de;
/* unbake published declaration: published_5100244f02f2a8b59f794cf8 */
typedef struct Actor_func_802AB6EC_de Actor_func_802AB6EC_de;

struct LocalizedEffectContext;
/* unbake published declaration: published_51fdffb1f3b8ecfa37c093d0 */
struct LocalizedEffectContext {
    u8 reserved[0x17C1];
    u8 language;
};

union func_802ADD18_S1_U5E8;
/* unbake published declaration: published_55cf232f7ef78a10bae8021e */
union func_802ADD18_S1_U5E8 {
    u16 v0;
    s16 v1;
};

/* unbake published declaration: published_5d279f1e58b6cfdeb442c402 */
extern void func_802AB35C_de(int unused, unsigned char *pairs, int count, unsigned char *table);

struct func_802AE1A4_S1;
/* unbake published declaration: published_5e68e0d72f73e5de4d52e896 */
struct func_802AE1A4_S1 {
    char pad0[0x5DC];
    void * unk5DC;
    char pad5DC[0x16D4 - 0x5DC - sizeof(void*)];
    s32 unk16D4;
};

struct func_802ADD18_S1;
/* unbake published declaration: published_64a4ec237cbd450065255330 */
typedef struct func_802ADD18_S1 func_802ADD18_S1;

struct func_802ADBF4_S2;
/* unbake published declaration: published_66cb15e23a62ca43f6192f51 */
typedef struct func_802ADBF4_S2 func_802ADBF4_S2;

struct func_802ADFA0_S1;
/* unbake published declaration: published_6c6f3d4c1e96a3df9df114db */
struct func_802ADFA0_S1 {
    char pad0[0x6];
    s16 unk6;
    char pad6[0x8 - 0x6 - sizeof(s16)];
    s16 unk8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    s16 unkC;
    char padC[0xE - 0xC - sizeof(s16)];
    s16 unkE;
    char padE[0x10 - 0xE - sizeof(s16)];
    s16 unk10;
};

union func_802ADD18_S1_U5E8;
/* unbake published declaration: published_8d0e916ff5dea49c93715947 */
typedef union func_802ADD18_S1_U5E8 func_802ADD18_S1_U5E8;

struct func_802ADD18_S1;
/* unbake published declaration: published_72d6ff802e4948ba1199c9e1 */
struct func_802ADD18_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x5DC - 0x10 - sizeof(s32)];
    void * unk5DC;
    char pad5DC[0x5E8 - 0x5DC - sizeof(void*)];
    func_802ADD18_S1_U5E8 unk5E8;
    char pad5E8[0x5EA - 0x5E8 - sizeof(func_802ADD18_S1_U5E8)];
    func_8022FD9C_S2_U770 unk5EA;
};

struct func_802ADFA0_S1;
/* unbake published declaration: published_797ba9b23e1525d946c3660f */
typedef struct func_802ADFA0_S1 func_802ADFA0_S1;

struct func_802AE1A4_S2;
/* unbake published declaration: published_a251a27ec1ea246a2b39e958 */
typedef struct func_802AE1A4_S2 func_802AE1A4_S2;

/* unbake published declaration: published_a582f609e04d6f0786e3d054 */


/* unbake published declaration: published_acfad39b96ec0caedaff4ee8 */
extern void func_802AB3A8_de(void);

struct func_802ADBF4_S1;
/* unbake published declaration: published_b3a5f1989b95d4d0d070fc8a */
typedef struct func_802ADBF4_S1 func_802ADBF4_S1;

/* unbake published declaration: published_bed7a71b3b69343407bdc868 */
extern void func_802AB0B0_de(u16 *grid, s16 x0, s32 y);

struct Entry_func_802AB400_de;
/* unbake published declaration: published_c17e9ee01d7deb44ae0af1d6 */
struct Entry_func_802AB400_de {
    char pad0[4];
    s16 id;
    char pad6[6];
    s16 index;
};

struct func_802ADD18_S2;
/* unbake published declaration: published_c7e558c95b0f33d1765de986 */
typedef struct func_802ADD18_S2 func_802ADD18_S2;

struct func_802ADA44_S1;
/* unbake published declaration: published_d35c1ad68ad50f0bd0b8c8ab */
typedef struct func_802ADA44_S1 func_802ADA44_S1;

struct func_802ADB08_S1;
/* unbake published declaration: published_d50110d60f932194f55bb571 */
struct func_802ADB08_S1 {
    char pad0[0x6];
    s16 unk6;
    char pad6[0x8 - 0x6 - sizeof(s16)];
    s16 unk8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    s16 unkC;
    char padC[0xE - 0xC - sizeof(s16)];
    s16 unkE;
};

struct Actor_func_802AB400_de;
/* unbake published declaration: published_df6049f613ecbaa25229a8fe */
typedef struct Actor_func_802AB400_de Actor_func_802AB400_de;

struct func_802ADD18_S2;
/* unbake published declaration: published_e679887f163701f03f96d957 */
struct func_802ADD18_S2 {
    char pad0[0x6];
    s16 unk6;
    char pad6[0x8 - 0x6 - sizeof(s16)];
    s16 unk8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    u16 unkC;
};

struct func_802ADB08_S2;
/* unbake published declaration: published_eefe1d5543c7610180cb25cf */
typedef struct func_802ADB08_S2 func_802ADB08_S2;

struct func_802ADB08_S1;
/* unbake published declaration: published_f07cd4f20c2183f26edff62e */
typedef struct func_802ADB08_S1 func_802ADB08_S1;

struct func_802AE1A4_S1;
/* unbake published declaration: published_f0abd5f2525d48d0092cbbc7 */
typedef struct func_802AE1A4_S1 func_802AE1A4_S1;

struct func_802AE1A4_S2;
/* unbake published declaration: published_f5456b607366e847ef5ba73e */
struct func_802AE1A4_S2 {
    char pad0[0x124];
    s16 unk124;
};

/* unbake published declaration: published_f7cac5039a72467c8f6e1eeb */
extern void func_802AADCC_de(u16 *grid, s16 x0, s32 y);

/* unbake published declaration: published_fb2a6d0b7026cd3e9934b469 */
extern float D_800C62E0;

#endif
