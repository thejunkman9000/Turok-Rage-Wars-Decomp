#ifndef UNBAKE_SPAN_16E000_CODE_804453C4_H
#define UNBAKE_SPAN_16E000_CODE_804453C4_H
#include "../types.h"
#include "common/types_8fd754e1e915.h"
/* unbake published declaration: published_0055ec91f51153da2afe0870 */
extern float D_800E2810;

struct Menu_func_80445964_de;
/* unbake published declaration: published_02d3f7a7f968682d0a09aff9 */
struct Menu_func_80445964_de {
    s16 state;
    char pad2[0x1A];
    s32 id;
    s32 input;
};

struct Actor_func_8044560C_de;
struct Actor_func_8044560C_de {
    char pad0[0x80];
    s32 mask80;
    char pad84[0xA8 - 0x84];
    s32 maskA8;
};
struct Actor_func_8044560C_de;
struct Player_func_8044560C_de;
/* unbake published declaration: published_5f54bed7bad64cf738a42e15 */
struct Player_func_8044560C_de {
    s16 state;
    char pad2[0xA];
    struct Actor_func_8044560C_de *actor;
};

struct Player_func_8044560C_de;
/* unbake published declaration: published_e4a7d03573f0d2ea658df011 */
typedef struct Player_func_8044560C_de Player_func_8044560C_de;

/* unbake published declaration: published_1c446a286f3bae4bc8ae11dc */
extern void func_8044560C_de(Player_func_8044560C_de *player);

struct Spinner;
/* unbake published declaration: published_28c09cc8fa4aefbda9dd9952 */
typedef struct Spinner Spinner;

struct Style_func_80445BC0_de;
/* unbake published declaration: published_3239edbfdd12748e66a266bf */
struct Style_func_80445BC0_de {
    char pad0[0x1C];
    s32 id;
    char pad20[0x10];
    f32 alpha;
    f32 fade;
};

struct State_func_80445EF4_de;
/* unbake published declaration: published_3f4fce3308ce884a8bd2d71a */
typedef struct State_func_80445EF4_de State_func_80445EF4_de;

struct Entry_func_80445AB4_de;
/* unbake published declaration: published_40b2e43fd836c225e8889b2d */
struct Entry_func_80445AB4_de {
    s32 value;
    f32 timer;
    s32 count;
    u8 text[12];
};

struct State_func_80445EF4_de;
/* unbake published declaration: published_426b4ac256731868a6ebedf4 */
struct State_func_80445EF4_de {
    char pad[0x1C];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
};

/* unbake published declaration: published_52343a73ea9637ad324bac36 */
extern s32 func_80445B88_de(u8 *a, u8 *b, s32 count);

struct Entry_func_80445E04_de;
/* unbake published declaration: published_5f327c91b56a4b1206767113 */
struct Entry_func_80445E04_de {
    char pad[0x1C];
    func_80209B64_S4 *unk1C;
};

/* unbake published declaration: published_69683ef00f9880b301104b55 */
extern void func_8044569C_de(void);

/* unbake published declaration: published_766f5397240f49945c3f2d37 */
extern s32 func_80445EF4_de(void);

struct Entry_func_80445AB4_de;
/* unbake published declaration: published_7ca2f59ac48ffda673e12106 */
typedef struct Entry_func_80445AB4_de Entry_func_80445AB4_de;

struct LocalizedInputState;
/* unbake published declaration: published_7ea0772ff8d42c334499f951 */
struct LocalizedInputState {
    u8 reserved[0x1809];
    u8 language;
};

/* unbake published declaration: published_801ac54b0675a647fdd2ee89 */
extern float D_800DE7C8_de;

struct Style_func_80445BC0_de;
/* unbake published declaration: published_8c4a3048c58c378e3362bec5 */
typedef struct Style_func_80445BC0_de Style_func_80445BC0_de;

struct TextEntry_func_80445D6C_de;
/* unbake published declaration: published_91305bc4805b15db0cb8ff24 */
typedef struct TextEntry_func_80445D6C_de TextEntry_func_80445D6C_de;

struct Spinner;
/* unbake published declaration: published_ad25b36bf529b26f6c2f24d3 */
struct Spinner {
    s32 value;
    f32 timer;
    s32 max;
    char padC[0xC];
};

/* unbake published declaration: published_ae0a205aad33e69345d082ae */
extern void func_804456B8_de(void);

struct Menu_func_80445964_de;
/* unbake published declaration: published_b18b2f8abcec14d09979d3fd */
typedef struct Menu_func_80445964_de Menu_func_80445964_de;

struct LocalizedInputState;
/* unbake published declaration: published_c0f20c3f378b4db6f84e2e50 */
typedef struct LocalizedInputState LocalizedInputState;

struct Field_func_80445414_us_rev1;
/* unbake published declaration: published_ca0a00cf2a8f9c4a3be677fa */
struct Field_func_80445414_us_rev1 {
    char pad[0x14];
    char **text;
    s32 pad18;
    s32 value;
};

struct TextEntry_func_80445D6C_de;
/* unbake published declaration: published_cdcd04f23da3c59ffb666398 */
struct TextEntry_func_80445D6C_de {
    s32 length;
    s32 cursor;
    s32 count;
    char text[12];
};

struct Entry_func_80445E04_de;
/* unbake published declaration: published_e2592d32e803440a10ea7eb9 */
typedef struct Entry_func_80445E04_de Entry_func_80445E04_de;

extern int func_80446330_us_rev1(void * arg0);
struct Field;
extern s32 func_80445310_de(struct Field *field);
#endif
