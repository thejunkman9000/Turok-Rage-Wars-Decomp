#ifndef UNBAKE_SPAN_16E000_CODE_804264F0_H
#define UNBAKE_SPAN_16E000_CODE_804264F0_H
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct State_func_80428214_de;
/* unbake published declaration: published_072e26e1f20f7d5e60584028 */
typedef struct State_func_80428214_de State_func_80428214_de;

struct Resource_func_80419E54_de;
struct State_func_804287F8_de;
/* unbake published declaration: published_0c47250832382dcc614e2d31 */
struct State_func_804287F8_de {
    char pad0[0x988];
    s32 mode;
    char pad98C[0xA50 - 0x98C];
    struct Resource_func_80419E54_de *item;
};

struct ResultsOptionsScreen;
/* unbake published declaration: published_0ebb1ef045868dbc8d83a743 */
struct ResultsOptionsScreen {
    char pad0[0x970];
    union { MenuWidget *root; void *parent; };
};

struct Entry_func_8042840C_de;
/* unbake published declaration: published_0fa998ef337752ec092f14b3 */
struct Entry_func_8042840C_de {
    char pad0[0x11C];
    u8 owned;
};

/* unbake published declaration: published_0fd6df4bc46898eac89f2bd8 */
extern s32 func_80428E78_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct Row_func_80426788_de;
/* unbake published declaration: published_17a13fae87c89176f47e745d */
struct Row_func_80426788_de {
    s32 pad0;
    f32 scale[4];
    f32 distance[4];
    Vec3 position[4];
    s32 light[4];
    char pad64[0x70 - 0x64];
};

struct Slot_func_80428214_de;
/* unbake published declaration: published_8a8d35aace74199c31fb65c1 */
typedef struct Slot_func_80428214_de Slot_func_80428214_de;

struct Slot_func_80428214_de;
/* unbake published declaration: published_92e0e548fa294fdfecd8dc4a */
struct Slot_func_80428214_de {
    u8 flags[0x16];
    u8 unk16[0x16];
    u8 ready;
    u8 pad2D[0x96 - 0x2D];
};

struct State_func_80428214_de;
/* unbake published declaration: published_1f547139deb97af6ebfc4265 */
struct State_func_80428214_de {
    u8 pad0[0x11C];
    Slot_func_80428214_de slots[4];
};

/* unbake published declaration: published_26670d5349bc08716bb597a8 */
extern u8 D_801462D5;

struct Screen_func_80427008_de;
/* unbake published declaration: published_2d1f78b4842425902f29424c */
struct Screen_func_80427008_de {
    char pad0[0xA5C];
    s32 record;
    char padA60[0xA74 - 0xA60];
    u8 shown[5];
    u8 marked[5];
};

/* unbake published declaration: published_2e86daca2a3fcb8b7a5b8469 */
extern void func_8042840C_de();

struct Screen_func_80426788_de;
/* unbake published declaration: published_2ec1ae99f597a251a8f714e4 */
struct Screen_func_80426788_de {
    char pad0[0xA58];
    s32 wordA58;
};

/* unbake published declaration: published_31568b88356f881da5ac55a6 */
extern void func_804279B8_de();

struct Screen_func_80427D70_de;
/* unbake published declaration: published_35fc573869e77734c1bceddf */
struct Screen_func_80427D70_de {
    char pad0[0xA5C];
    s32 player;
    char padA60[0xA74 - 0xA60];
    u8 owned[0xA79 - 0xA74];
    u8 unlocked[1];
};

struct Record_func_80427008_de;
/* unbake published declaration: published_40e40241138eb1d338730e96 */
struct Record_func_80427008_de {
    char pad0[0x7E];
    u8 single[5];
    u8 versus[5];
    u8 three[5];
    u8 four[5];
    char pad92[0x190 - 0x92];
};

struct Screen_func_80428300_de;
/* unbake published declaration: published_45f1c36343888570d9ee5c80 */
struct Screen_func_80428300_de {
    char pad[0xA5C];
    s32 player;
};

/* unbake published declaration: published_54902cfb9f948e029f073e08 */
extern void func_804273D4_de();

struct Menu_func_80428850_de;
struct Resource_func_80419E54_de;
/* unbake published declaration: published_6a16f04acaeebbde53afd119 */
struct Menu_func_80428850_de {
    char pad0[0xA44];
    s32 current;
    struct Resource_func_80419E54_de *window;
    char padA4C[0xA6C - 0xA4C];
    s32 idle;
    char padA70[0xA74 - 0xA70];
    u8 reachable[5];
    u8 visited[5];
};

/* unbake published declaration: published_6a75d709492db21b2f8c58ee */
extern void func_80427B08_de();

/* unbake published declaration: published_6dcd0e583adc394d4812ee53 */
extern int func_8042863C_de(int id);

/* unbake published declaration: published_6f08c560a5609a68a08b061b */
extern void func_80428700_de();

struct Screen_func_804273D4_de;
/* unbake published declaration: published_7f4d871ccb0984114c47a079 */
struct Screen_func_804273D4_de {
    char pad0[0x970];
    s32 context;
};

struct func_80428388_S1;
/* unbake published declaration: published_7fc57eef730e77e313d683e8 */
typedef struct func_80428388_S1 func_80428388_S1;

struct Pair;
/* unbake published declaration: published_880c223de27a31dc718e1735 */
struct Pair {
    s32 a;
    s32 b;
    union {
        s32 id;
        struct {
            u16 high;
            u16 low;
        } half;
    } c;
};

/* unbake published declaration: published_889b45b79aec3c8a5973b5e0 */
extern void func_80427008_de();

/* unbake published declaration: published_88a50b4b5a1366c34bf81295 */
extern void func_80428214_de();

struct Entry_func_804279B8_de;
/* unbake published declaration: published_b214a615f165a5861d839834 */
struct Entry_func_804279B8_de {
    char pad[0x80];
    s8 kind;
    char tail[0x15];
};

struct Entry_func_804279B8_de;
struct Globals_func_80427D70_de;
/* unbake published declaration: published_88c574bff3cd3704d1398913 */
struct Globals_func_80427D70_de {
    char pad0[0xD];
    u8 mode;
    char padE[0xD0 - 0xE];
    struct Entry_func_804279B8_de status[8];
};

/* unbake published declaration: published_94a116a3fa18e14a35d21edb */
extern void func_804281A8_de();

struct Resource_func_80419E54_de;
struct func_80428388_S1;
/* unbake published declaration: published_954baaeba49dcd72f0d35739 */
struct func_80428388_S1 {
    char pad0[0xA60];
    struct Resource_func_80419E54_de * unkA60;
    char padA60[0xA64 - 0xA60 - sizeof(struct Resource_func_80419E54_de*)];
    struct Resource_func_80419E54_de * unkA64;
    char padA64[0xA68 - 0xA64 - sizeof(struct Resource_func_80419E54_de*)];
    s32 unkA68;
};

/* unbake published declaration: published_969e9466dcc883511508c0a3 */
extern void func_804274B0_de();

struct Item_func_8042B4D4_de;
struct Screen_func_80426918_de;
/* unbake published declaration: published_a24e7a249bd689e5c3c943cb */
struct Screen_func_80426918_de {
    char pad0[0x978];
    struct Item_func_8042B4D4_de *left;
    char pad97C[2];
    u16 leftSpeed;
    struct Item_func_8042B4D4_de *right;
    char pad984[2];
    u16 rightSpeed;
    s32 state;
    s32 timer;
    void *prompt;
    void *button;
    char pad998[0xA48 - 0x998];
    struct Item_func_8042B4D4_de *pulse;
    char padA4C[4];
    struct Item_func_8042B4D4_de *banner;
    s32 clock;
    s32 requested;
};

struct State_func_804280BC_de;
struct func_8028469C_S2;
/* unbake published declaration: published_a3e92eabcd93a307a2fc2638 */
struct State_func_804280BC_de {
    char pad0[0x998];
    struct func_8028469C_S2 *owner;
    char pad99C[0xA04 - 0x99C];
    char text[0x40];
    s32 name;
};

/* unbake published declaration: published_a799cf7e1bfa751796e3f0a3 */
extern void func_804280BC_de();

struct Entry_func_80428E10_de;
/* unbake published declaration: published_abf9b5f19f703a77400f8a65 */
struct Entry_func_80428E10_de {
    s32 id;
    s32 first;
    s32 second;
    char pad[28 - 12];
};

/* unbake published declaration: published_afc5f8c48156a36d4e964b92 */
extern void func_80428300_de();

struct ResultsDrawScreen;
struct Shape_typemap_21;
/* unbake published declaration: published_b8805f6841e64ec3a52a95cd */
struct ResultsDrawScreen {
    char pad0[0x20];
    char panels[2][0x4A8];
    char pad970[0x988 - 0x970];
    s32 state;
    char pad98C[0xA44 - 0x98C];
    s32 soundBase;
    char padA48[0xA60 - 0xA48];
    struct Shape_typemap_21 *bannerShadow;
    struct Shape_typemap_21 *banner;
    s32 blinking;
    s32 frames;
    s32 blinkDelay;
};

struct Table_func_80427D70_de;
/* unbake published declaration: published_b9ad2d4fa7da4dd9bcda7a22 */
struct Table_func_80427D70_de {
    u8 pad0;
    u8 first;
    u8 items[3];
};

struct State_func_80428E10_de;
/* unbake published declaration: published_bd60bcdfef71f016c058d26d */
struct State_func_80428E10_de {
    char pad[0xA44];
    s32 selection;
};

struct ResultsOptionsScreen;
/* unbake published declaration: published_c509d8d46bb0f8cc1c1f06e9 */
typedef struct ResultsOptionsScreen ResultsOptionsScreen;

struct ResultsDrawScreen;
/* unbake published declaration: published_cabaab17a19b72a26ae0eb61 */
typedef struct ResultsDrawScreen ResultsDrawScreen;

struct Record_func_804284C0_de;
/* unbake published declaration: published_d9b7b6396d66dbe54bef2e4a */
struct Record_func_804284C0_de {
    char pad0[6];
    u16 items[8];
};

struct Entry_func_8042840C_de;
/* unbake published declaration: published_f21454effc3831829e288883 */
typedef struct Entry_func_8042840C_de Entry_func_8042840C_de;

struct Record_func_804284C0_de;
/* unbake published declaration: published_f3baa0147f402ee7063fe9c7 */
typedef struct Record_func_804284C0_de Record_func_804284C0_de;

#endif
