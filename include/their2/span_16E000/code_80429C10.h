#ifndef UNBAKE_SPAN_16E000_CODE_80429C10_H
#define UNBAKE_SPAN_16E000_CODE_80429C10_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct Menu_func_8042AAD0_de;
/* unbake published declaration: published_10689000d1675d4dd9632335 */
struct Menu_func_8042AAD0_de {
    void *screen;
    char pad4[0x3E8];
    void *widgetA;
    void *widgetB;
    char pad3F4[0x40];
    int mode;
    int selection;
    char pad43C[4];
    void *widgetC;
    void *widgetD;
    void *widgetE;
};

struct Menu_func_8042AAD0_de;
/* unbake published declaration: published_376da950aef692126bdcc731 */
typedef struct Menu_func_8042AAD0_de Menu_func_8042AAD0_de;

struct Control;
/* unbake published declaration: published_3aeaef62cc041b6628333e8c */
struct Control {
    short unk0;
    unsigned short first;
    int second;
    char pad8[8];
};

struct State_func_8042BA54_de;
/* unbake published declaration: published_4aaa57e458b76a6d34cb31b7 */
struct State_func_8042BA54_de {
    char pad[0x3DC];
    s32 mode;
    s32 next;
};

struct Item_func_8042B4D4_de;
struct Screen_func_8042B78C_de;
/* unbake published declaration: published_4bcda58f42d1fbe59678943f */
struct Screen_func_8042B78C_de {
    char pad0[0x308];
    char view[0x434 - 0x308];
    s32 category;
    s32 selection;
    struct Item_func_8042B4D4_de *item;
    char pad440[0x448 - 0x440];
    struct Item_func_8042B4D4_de *marker;
    char pad44C[0x45C - 0x44C];
    s32 word45C;
    char pad460[0x464 - 0x460];
    s32 word464;
};

/* unbake published declaration: published_68892819d8fe7c202539f48f */
extern void func_8042B350_de();

struct Label;
struct Screen_func_8042AFE0_de;
/* unbake published declaration: published_6d46c4e20ad38632f84694a7 */
struct Screen_func_8042AFE0_de {
    char pad0[0x3EC];
    struct Label *widget;
    char pad3F0[0x3F4 - 0x3F0];
    char label[0x40];
    s32 list;
    s32 entry;
};

struct State_func_8042BA98_de;
/* unbake published declaration: published_6ee7ec585a0d8cc081e32360 */
struct State_func_8042BA98_de {
    char pad[0x3DC];
    s32 mode;
};

struct G;
/* unbake published declaration: published_7025aade8e5162b22e326bb8 */
struct G {
    char pad0[0x3DC];
    s32 unk3DC;
    char pad3E0[0x3EC - 0x3E0];
    s32 unk3EC;
    s32 unk3F0;
    char pad3F4[0x440 - 0x3F4];
    s32 unk440;
    s32 unk444;
    s32 unk448;
    Resource_func_80419E54_de *unk44C;
};

struct Resource_func_80419E54_de;
struct VersusResultsScreen;
/* unbake published declaration: published_804027613331530a49bf852f */
struct VersusResultsScreen {
    char pad0[0x8];
    char panels[4][0xC0];
    char tie[0x3DC - 0x308];
    s32 state;
    char pad3E0[0x434 - 0x3E0];
    s32 winnerSlot;
    s32 winner;
    char pad43C[0x450 - 0x43C];
    struct Resource_func_80419E54_de *bannerShadow;
    struct Resource_func_80419E54_de *banner;
    char pad458[0x464 - 0x458];
    s32 frames;
    s32 blinkDelay;
    s32 blinking;
};

struct Resource_func_80419E54_de;
struct func_8042B4C4_S1;
/* unbake published declaration: published_84e7f13e076e753c7b6ffffe */
struct func_8042B4C4_S1 {
    char pad0[0x450];
    struct Resource_func_80419E54_de * unk450;
    char pad450[0x454 - 0x450 - sizeof(struct Resource_func_80419E54_de*)];
    struct Resource_func_80419E54_de * unk454;
    char pad454[0x46C - 0x454 - sizeof(struct Resource_func_80419E54_de*)];
    s32 unk46C;
};

struct Item_func_8042B4D4_de;
struct Screen_func_8042B4D4_de;
/* unbake published declaration: published_8c43883ad04a6378bb423f3d */
struct Screen_func_8042B4D4_de {
    char pad0[0x308];
    char view[0x434 - 0x308];
    s32 category;
    s32 selection;
    struct Item_func_8042B4D4_de *item;
    struct Item_func_8042B4D4_de *left;
    struct Item_func_8042B4D4_de *right;
    struct Item_func_8042B4D4_de *marker;
    char pad44C[0x45C - 0x44C];
    s32 word45C;
    char pad460[0x464 - 0x460];
    s32 word464;
};

struct Cup;
/* unbake published declaration: published_92718e628febf3d018c4fb56 */
struct Cup {
    s32 index;
    s32 stages;
    u8 played[4];
};

/* The cup being played. */
extern struct Cup D_80154010;

/* unbake published declaration: published_952da37508f57003830cec05 */
extern void func_8042AFE0_de();

/* unbake published declaration: published_9f418af3341e39b99c5c2111 */
extern void func_8042AAD0_de();

struct G;
/* unbake published declaration: published_ab7b6e11b261f76832abe682 */
typedef struct G G;

struct Resource_func_80419E54_de;
struct Screen_func_8042B644_de;
/* unbake published declaration: published_bbd8e9737bbe054659873be0 */
struct Screen_func_8042B644_de {
    char pad0[0x434];
    s32 category;
    s32 selection;
    struct Resource_func_80419E54_de *item;
    struct Resource_func_80419E54_de *left;
    struct Resource_func_80419E54_de *right;
    struct Resource_func_80419E54_de *marker;
    char pad44C[0x45C - 0x44C];
    s32 word45C;
    char pad460[0x464 - 0x460];
    s32 word464;
};

/* unbake published declaration: published_bdb52a82b46eff38ab4760d6 */
extern void func_8042B0A4_de();

struct Control;
/* unbake published declaration: published_c5631a097f9f8ff6925e8dfd */
typedef struct Control Control;

struct Record_func_8042B1B8_de;
/* unbake published declaration: published_cf1d14bc84d9e30476921b7a */
struct Record_func_8042B1B8_de {
    s32 key;
    char pad4[0x8];
    s32 value;
};

struct Label;
struct Screen_func_8042A990_de;
/* unbake published declaration: published_cfb738a5eb1c43a2561d8857 */
struct Screen_func_8042A990_de {
    void *window;
    char pad4[0x3EC - 0x4];
    struct Label *label;
    char pad3F0[0x3F4 - 0x3F0];
    char text[0x434 - 0x3F4];
    s32 category;
    s32 selection;
    void *item;
};

/* unbake published declaration: published_d0fc65f9358ff2f93147d1c6 */
extern void func_8042B2E4_de();

struct MenuRenderFill;
/* unbake published declaration: published_e865b97541e4ae458300d1f5 */
struct MenuRenderFill {
    s32 mode;
    f32 color[4];
};

struct func_8042B4C4_S1;
/* unbake published declaration: published_effbc6f7ea6d0793ea2b12f0 */
typedef struct func_8042B4C4_S1 func_8042B4C4_S1;

/* unbake published declaration: published_f183a877ef172f4921837ecb */
extern s32 func_8042BAD0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* unbake published declaration: published_f2f23b322d5e781d2fcf9db8 */
extern void func_8042B080_de();

struct Icon;
/* unbake published declaration: published_f3d2e9053f1681a2e14691d9 */
struct Icon {
    s32 key;
    s32 other;
    char pad8[0x10 - 0x8];
};

/* unbake published declaration: published_f7449e3976ac16fe31f10b78 */
extern void func_8042A990_de();

/* unbake published declaration: published_fdb826a3eca22e93edda793b */
extern s32 func_8042AFB8_de();

struct Record_func_8042B1B8_de;
/* unbake published declaration: published_fedb4a67f75043bba66b4a34 */
typedef struct Record_func_8042B1B8_de Record_func_8042B1B8_de;

#endif
